#include "trainingsetfile.h"

const QString TrainingSetFile::STR_TAG_TRAINING_SET = "trainingset";
const QString TrainingSetFile::STR_TAG_PROPERTIES = "properties";
const QString TrainingSetFile::STR_TAG_INPUTS_DATA_REPRESENTATION = "inputsdatarepresentation";
const QString TrainingSetFile::STR_TAG_TARGETS_DATA_REPRESENTATION = "targetsdatarepresentation";
const QString TrainingSetFile::STR_TAG_VERSION = "version";
const QString TrainingSetFile::STR_TAG_INPUTS_NORMALIZATION = "inputsnormalization";
const QString TrainingSetFile::STR_TAG_TARGETS_NORMALIZATION = "targetsnormalization";
const QString TrainingSetFile::STR_TAG_PATTERN = "pattern";
const QString TrainingSetFile::STR_TAG_INPUTS = "inputs";
const QString TrainingSetFile::STR_TAG_TARGETS = "targets";
const QString TrainingSetFile::STR_ATTR_NAME = "name";
const QString TrainingSetFile::STR_ATTR_WIDTH = "width";
const QString TrainingSetFile::STR_ATTR_HEIGHT = "height";
const QString TrainingSetFile::STR_ATTR_INPUTS_SIZE = "inputssize";
const QString TrainingSetFile::STR_ATTR_TARGETS_SIZE = "targetssize";
const QString TrainingSetFile::STR_ATTR_PATTERN_SIZE = "patternsize";
const QString TrainingSetFile::STR_ATTR_VERSION = "version";
const QString TrainingSetFile::STR_ATTR_TYPE = "type";
const QString TrainingSetFile::STR_ATTR_MAX_VALUE = "maxvalue";
const QString TrainingSetFile::STR_ATTR_MIN_VALUE = "minvalue";
const QString TrainingSetFile::STR_ATTR_THRESHOLD = "threshold";
const QString TrainingSetFile::STR_ATTR_AMPLITUDE = "amplitude";
const QString TrainingSetFile::STR_ATTR_ELONGATION = "elongation";
const QString TrainingSetFile::STR_ATTR_INDEX = "index";
const QString TrainingSetFile::STR_SEPARATOR = ",";

TrainingSetFile::TrainingSetFile() :
	QFile()
{
	init(new TrainingSet());
}

TrainingSetFile::TrainingSetFile(const QString &path) :
	QFile(path)
{
	//TODO: verificar esto
	init(new TrainingSet());
}

TrainingSetFile::TrainingSetFile(TrainingSet *ts, const QString &path) :
	QFile(path)
{
	//TODO: validar esto
	init(ts);
}

TrainingSetFile::TrainingSetFile(const TrainingSetFile &tsf):
	QFile(tsf.fileName())
{

}

bool TrainingSetFile::flush()
{
	int
			nPatterns = ts->getPatternCount(),
			nInputs = ts->getInputsSize(),
			nTargets = ts->getTargetsSize();

	QString strInputs,
			strTargets;

	vector<vector<double> >
			inputs = ts->getInputs(),
			targets = ts->getTargets(),
			normalizedInputs = ts->getNormalizedInputs(),
			normalizedTargets = ts->getNormalizedTargets();

	Normalization
			inputsNorm = ts->getInputsNormalization(),
			targetsNorm = ts->getTargetsNormalization();

	QString
			strInputsNorm = inputsNorm.getNormalizationName(),
			strTargetsNorm = targetsNorm.getNormalizationName();

	tsWriteXML.writeStartDocument();

	tsWriteXML.writeStartElement("trainingset");
	//Indica el numero de patrones a almacenar
	tsWriteXML.writeAttribute("patternsize", QString::number(nPatterns));

	//Indica el tamaño de las entradas
	tsWriteXML.writeAttribute("inputsize", QString::number(nInputs));

	//Indica el tamaño de las salidas
	tsWriteXML.writeAttribute("targetsize", QString::number(nTargets));

	//Indica propiedades particulares del archivo
	tsWriteXML.writeStartElement("properties");
	tsWriteXML.writeAttribute("version", "1.0.0");
	tsWriteXML.writeEndElement();

	//Este parametro indica que representacion grafica se usara para visualizar entradas
	tsWriteXML.writeStartElement("inputsdatarepresentation");
	tsWriteXML.writeAttribute("name", inputsdatarepresentation);
	tsWriteXML.writeAttribute("width", QString::number(inputswidth));
	tsWriteXML.writeAttribute("height", QString::number(inputsheight));
	tsWriteXML.writeEndElement();

	//Este parametro indica que representacion grafica se usara para visualizar las salidas
	tsWriteXML.writeStartElement("targetsdatarepresentation");
	tsWriteXML.writeAttribute("name", targetsdatarepresentation);
	tsWriteXML.writeAttribute("width", QString::number(targetswidth));
	tsWriteXML.writeAttribute("height", QString::number(targetsheight));
	tsWriteXML.writeEndElement();

	tsWriteXML.writeStartElement("inputsnormalization");
	tsWriteXML.writeAttribute("type", strInputsNorm);
	tsWriteXML.writeAttribute("maxvalue", QString::number(inputsNorm.getMaxValue(), decimalformat, decimals));
	tsWriteXML.writeAttribute("minvalue", QString::number(inputsNorm.getMinValue(), decimalformat, decimals));
	tsWriteXML.writeAttribute("threshold", QString::number(inputsNorm.getThreshold(), decimalformat, decimals));
	tsWriteXML.writeAttribute("amplitude", QString::number(inputsNorm.getAmplitude(), decimalformat, decimals));
	tsWriteXML.writeAttribute("elongation", QString::number(inputsNorm.getElongation(), decimalformat, decimals));
	tsWriteXML.writeEndElement();

	tsWriteXML.writeStartElement("targetsnormalization");
	tsWriteXML.writeAttribute("type", strTargetsNorm);
	tsWriteXML.writeAttribute("maxvalue", QString::number(targetsNorm.getMaxValue(), decimalformat, decimals));
	tsWriteXML.writeAttribute("minvalue", QString::number(targetsNorm.getMinValue(), decimalformat, decimals));
	tsWriteXML.writeAttribute("threshold", QString::number(targetsNorm.getThreshold(), decimalformat, decimals));
	tsWriteXML.writeAttribute("amplitude", QString::number(targetsNorm.getAmplitude(), decimalformat, decimals));
	tsWriteXML.writeAttribute("elongation", QString::number(targetsNorm.getElongation(), decimalformat, decimals));
	tsWriteXML.writeEndElement();

	for(int p = 0; p < nPatterns; p++){
		tsWriteXML.writeStartElement("pattern");
		tsWriteXML.writeAttribute("index", QString::number(p));
		//Se escriben las entradas
		tsWriteXML.writeStartElement("inputs");
		strInputs = "";
		for(int i = 0; i < nInputs; i++){
			strInputs += QString::number(inputs[p][i], decimalformat, decimals);
			if(i != nInputs - 1){
				strInputs += ",";
			}
		}
		tsWriteXML.writeCharacters(strInputs);
		tsWriteXML.writeEndElement();//inputs

		//Se escriben las salidas
		tsWriteXML.writeStartElement("targets");
		strTargets = "";
		for(int t = 0; t < nTargets; t++){
			strTargets += QString::number(targets[p][t], decimalformat, decimals);
			if(t != nTargets - 1){
				strTargets += ",";
			}
		}
		//		tsXML.writeTextElement("targets", strTargets);
		tsWriteXML.writeCharacters(strTargets);
		tsWriteXML.writeEndElement();//targets
		tsWriteXML.writeEndElement();//pattern
	}
	tsWriteXML.writeEndElement();//trainingset
	tsWriteXML.writeEndDocument();

	return true;
}

void TrainingSetFile::setTrainingSet(TrainingSet *ts)
{
	this->ts = ts;
}

TrainingSet *TrainingSetFile::getTrainingSet() const
{
	return ts;
}

void TrainingSetFile::setFormat(char f)
{
	decimalformat = f;
}

char TrainingSetFile::getFormat() const
{
	return decimalformat;
}

void TrainingSetFile::setDecimals(int d)
{
	decimals = d;
}

int TrainingSetFile::getDecimals() const
{
	return decimals;
}

TrainingSetFile::Error TrainingSetFile::load()
{
	QXmlStreamReader::TokenType tt;
	QStringRef name;
	QString text;
	QStringList textElements;
	QXmlStreamAttributes attributes;
	Error err;

	int
			lastPatternIndex = 0,
			sTextElements,
			pSize,
			iSize = 0,
			tSize = 0;

	*ts = TrainingSet();
	Normalization
			inor,
			tnor;

	vector<vector<double> >
			inputs,
			targets;

	while (!tsReadXML.atEnd()) {
		tt = tsReadXML.readNext();
		if(tt == QXmlStreamReader::StartDocument){
			continue;
		}else if(tt == QXmlStreamReader::StartElement){
			name = tsReadXML.name();
			if(name == STR_TAG_TRAINING_SET){
				attributes = tsReadXML.attributes();
				pSize = attributes.value(STR_ATTR_PATTERN_SIZE).toInt();
				iSize = attributes.value(STR_ATTR_INPUTS_SIZE).toInt();
				tSize = attributes.value(STR_ATTR_TARGETS_SIZE).toInt();

				inputs = vector<vector<double> >(pSize, vector<double>(iSize, 0));
				targets = vector<vector<double> >(pSize, vector<double>(tSize, 0));
			}else if(name == STR_TAG_PROPERTIES){
				version = tsReadXML.attributes().value(STR_ATTR_VERSION).toString();
			}else if(name == STR_TAG_INPUTS_NORMALIZATION){
				attributes = tsReadXML.attributes();
				inor.setType(fromStringToInt(attributes.value(STR_ATTR_TYPE).toString()));
				inor.setMaxValue(attributes.value(STR_ATTR_MAX_VALUE).toDouble());
				inor.setMinValue(attributes.value(STR_ATTR_MIN_VALUE).toDouble());
				inor.setThreshold(attributes.value(STR_ATTR_THRESHOLD).toDouble());
				inor.setAmplitude(attributes.value(STR_ATTR_AMPLITUDE).toDouble());
				inor.setElongation(attributes.value(STR_ATTR_ELONGATION).toDouble());
				ts->setInputsNormalization(inor);
			}else if(name == STR_TAG_TARGETS_NORMALIZATION){
				attributes = tsReadXML.attributes();
				tnor.setType(fromStringToInt(attributes.value(STR_ATTR_TYPE).toString()));
				tnor.setMaxValue(attributes.value(STR_ATTR_MAX_VALUE).toDouble());
				tnor.setMinValue(attributes.value(STR_ATTR_MIN_VALUE).toDouble());
				tnor.setThreshold(attributes.value(STR_ATTR_THRESHOLD).toDouble());
				tnor.setAmplitude(attributes.value(STR_ATTR_AMPLITUDE).toDouble());
				tnor.setElongation(attributes.value(STR_ATTR_ELONGATION).toDouble());
				ts->setTargetsNormalization(tnor);
			}else if(name == STR_TAG_PATTERN){
				attributes = tsReadXML.attributes();
				lastPatternIndex = attributes.value(STR_ATTR_INDEX).toInt();
			}else if(name == STR_TAG_INPUTS){
				text = tsReadXML.readElementText(QXmlStreamReader::SkipChildElements);
				textElements = text.split(STR_SEPARATOR, QString::KeepEmptyParts, Qt::CaseInsensitive);
				sTextElements = textElements.size();
				for(int i = 0; i < sTextElements; i++){
					inputs[lastPatternIndex][i] = textElements[i].toDouble();
				}
			}else if(name == STR_TAG_TARGETS){
				text = tsReadXML.readElementText(QXmlStreamReader::SkipChildElements);
				textElements = text.split(STR_SEPARATOR, QString::KeepEmptyParts, Qt::CaseInsensitive);
				sTextElements = textElements.size();
				for(int t = 0; t < sTextElements; t++){
					targets[lastPatternIndex][t] = textElements[t].toDouble();
				}
			}
		}
	}
	if (tsReadXML.hasError()) {
		err.sucess = false;
		err.errnum = tsReadXML.error();
		err.errormsg = tsReadXML.errorString();
		err.line = tsReadXML.lineNumber();
	}else{
		ts->setInputs(inputs, iSize);
		ts->setTargets(targets, tSize);

		err.sucess = true;
		err.errnum = QXmlStreamReader::NoError;
		err.errormsg = "";
		err.line = -1;

	}

	return err;
}

Normalization::Type TrainingSetFile::fromStringToInt(const QString &str)
{
	if(str == "Nothing"){
		return Normalization::Nothing;
	}else if(str == "BipolarFixedThreshold"){
		return Normalization::BipolarFixedThreshold;
	}else if(str == "BipolarAutoThreshold"){
		return Normalization::BipolarAutoThreshold;
	}else if(str == "UnipolarFixedThreshold"){
		return Normalization::UnipolarFixedThreshold;
	}else if(str == "UnipolarAutoThreshold"){
		return Normalization::UnipolarAutoThreshold;
	}else if(str == "LinearFixedRange"){
		return Normalization::LinearFixedRange;
	}else if(str == "LinearAutoRange"){
		return Normalization::LinearAutoRange;
	}else if(str == "Tanh"){
		return Normalization::Tanh;
	}else if(str == "Sigmoid"){
		return Normalization::Sigmoid;
	}else if(str == "MeanDistance"){
		return Normalization::MeanDistance;
	}else{
		return Normalization::Nothing;
	}
}

void TrainingSetFile::setVersion(const QString &ver)
{
	version = ver;
}

QString TrainingSetFile::getVersion() const
{		//NOTE: 06/12/14: se implemento de este modo ya que del otro que parece mas sencillo resulta en un error
	//				inputs.resize(pSize);
	//				targets.resize(pSize);
	//				for(int i = 0; i < pSize; i++){
	//					inputs[i].resize(iSize, 0);
	//					targets[i].resize(iSize, 0);
	//				}
	return version;
}

QPair<TrainingSet *, TrainingSetFile::Error> TrainingSetFile::fromFile(const QString &path)
{
	QFile file(path);

	return fromFile(file);
}

QPair<TrainingSet *, TrainingSetFile::Error> TrainingSetFile::fromFile(QFile &file)
{
	QString
			version,
			text;

	QStringRef
			name,
			idrName, //Inputs Data Representation Name
			tdrName; //Targets Data Representation Name;

	TrainingSet *ts = new TrainingSet();
	QXmlStreamReader tsReadXML;

	QStringList textElements;
	QXmlStreamAttributes attributes;
	Error err = {true, QXmlStreamReader::NoError, "", 0};
//	QPair<TrainingSet*, TrainingSetFile::Error> finalOutput;

	int
			lastPatternIndex = 0,
			sTextElements,
			pSize,
			iSize = 0,
			tSize = 0,
			idrWidth = 0, //Inputs Data Representation Width
			idrHeight = 0, //Inputs Data Representation Height
			tdrWidth = 0, //Targets Data Representation Width
			tdrHeight = 0; //Targets Data Representation Height

	Normalization
			inor,
			tnor;

	vector<vector<double> >
			inputs,
			targets;

	if(file.open(QIODevice::ReadOnly)){
		tsReadXML.setDevice(&file);
		bool hasError;
		while (!tsReadXML.atEnd() && !(hasError = tsReadXML.hasError())) {

			QXmlStreamReader::TokenType tt;
			try{
				tt = tsReadXML.readNext();
			}catch(QException exc){
				qWarning() << exc.what();
			}

			if(tt == QXmlStreamReader::StartDocument){
				continue;
			}else if(tt == QXmlStreamReader::StartElement){
				name = tsReadXML.name();
				if(name == STR_TAG_TRAINING_SET){
					attributes = tsReadXML.attributes();
					pSize = attributes.value(STR_ATTR_PATTERN_SIZE).toInt();
					iSize = attributes.value(STR_ATTR_INPUTS_SIZE).toInt();
					tSize = attributes.value(STR_ATTR_TARGETS_SIZE).toInt();

					inputs = vector<vector<double> >(pSize, vector<double>(iSize, 0));
					targets = vector<vector<double> >(pSize, vector<double>(tSize, 0));
				}else if(name == STR_TAG_PROPERTIES){
					version = tsReadXML.attributes().value(STR_ATTR_VERSION).toString();
				}else if(name == STR_TAG_INPUTS_DATA_REPRESENTATION){
					attributes = tsReadXML.attributes();
					idrName = attributes.value(STR_ATTR_NAME);
					idrWidth = attributes.value(STR_ATTR_WIDTH).toInt();
					idrHeight = attributes.value(STR_ATTR_HEIGHT).toInt();
				}else if(name == STR_TAG_TARGETS_DATA_REPRESENTATION){
					attributes = tsReadXML.attributes();
					tdrName = attributes.value(STR_ATTR_NAME);
					tdrWidth = attributes.value(STR_ATTR_WIDTH).toInt();
					tdrHeight = attributes.value(STR_ATTR_HEIGHT).toInt();
				}else if(name == STR_TAG_INPUTS_NORMALIZATION){
					attributes = tsReadXML.attributes();
					inor.setType(fromStringToInt(attributes.value(STR_ATTR_TYPE).toString()));
					inor.setMaxValue(attributes.value(STR_ATTR_MAX_VALUE).toDouble());
					inor.setMinValue(attributes.value(STR_ATTR_MIN_VALUE).toDouble());
					inor.setThreshold(attributes.value(STR_ATTR_THRESHOLD).toDouble());
					inor.setAmplitude(attributes.value(STR_ATTR_AMPLITUDE).toDouble());
					inor.setElongation(attributes.value(STR_ATTR_ELONGATION).toDouble());
					ts->setInputsNormalization(inor);
				}else if(name == STR_TAG_TARGETS_NORMALIZATION){
					attributes = tsReadXML.attributes();
					tnor.setType(fromStringToInt(attributes.value(STR_ATTR_TYPE).toString()));
					tnor.setMaxValue(attributes.value(STR_ATTR_MAX_VALUE).toDouble());
					tnor.setMinValue(attributes.value(STR_ATTR_MIN_VALUE).toDouble());
					tnor.setThreshold(attributes.value(STR_ATTR_THRESHOLD).toDouble());
					tnor.setAmplitude(attributes.value(STR_ATTR_AMPLITUDE).toDouble());
					tnor.setElongation(attributes.value(STR_ATTR_ELONGATION).toDouble());
					ts->setTargetsNormalization(tnor);
				}else if(name == STR_TAG_PATTERN){
					attributes = tsReadXML.attributes();
					lastPatternIndex = attributes.value(STR_ATTR_INDEX).toInt();
				}else if(name == STR_TAG_INPUTS){
					text = tsReadXML.readElementText(QXmlStreamReader::SkipChildElements);
					textElements = text.split(STR_SEPARATOR, QString::KeepEmptyParts, Qt::CaseInsensitive);
					sTextElements = textElements.size();
					for(int i = 0; i < sTextElements; i++){
						inputs[lastPatternIndex][i] = textElements[i].toDouble();
					}
				}else if(name == STR_TAG_TARGETS){
					text = tsReadXML.readElementText(QXmlStreamReader::SkipChildElements);
					textElements = text.split(STR_SEPARATOR, QString::KeepEmptyParts, Qt::CaseInsensitive);
					sTextElements = textElements.size();
					for(int t = 0; t < sTextElements; t++){
						targets[lastPatternIndex][t] = textElements[t].toDouble();
					}
				}
			}
		}
		if (tsReadXML.hasError()) {
			err = {false, tsReadXML.error(), tsReadXML.errorString(), tsReadXML.lineNumber()};

			ts = NULL;
		}else{
			ts->setPatternCount(pSize);
			ts->setInputs(inputs, iSize);
			ts->setTargets(targets, tSize);

			err = {true, QXmlStreamReader::NoError, "", -1};
		}
		return QPair<TrainingSet*, TrainingSetFile::Error>(ts, err);

		tsReadXML.clear();
		file.close();
	}
	err = {false, QXmlStreamReader::CustomError, "", -1};

	ts = NULL;
	return QPair<TrainingSet*, TrainingSetFile::Error>(ts, err);
}

void TrainingSetFile::setInputsWidth(int width)
{
	this->inputswidth = width;
}

int TrainingSetFile::getInputsWidth() const
{
	return inputswidth;
}

void TrainingSetFile::setInputsHeight(int height)
{
	this->inputsheight = height;
}

int TrainingSetFile::getInputsHeight() const
{
	return inputsheight;
}

void TrainingSetFile::setTargetsWidth(int width)
{
	targetswidth = width;
}

int TrainingSetFile::getTargetsWidth() const
{
	return targetswidth;
}

void TrainingSetFile::setTargetsHeight(int height)
{
	targetsheight = height;
}

int TrainingSetFile::getTargetsHeight() const
{
	return targetsheight;
}

void TrainingSetFile::setTargetsDataRepresentation(const QString &rep)
{
	targetsdatarepresentation = rep;
}

QString TrainingSetFile::getTargetsDataRepresentation() const
{
	return targetsdatarepresentation;
}

void TrainingSetFile::setInputsDataRepresentation(const QString &rep)
{
	inputsdatarepresentation = rep;
}

QString TrainingSetFile::getInputsDataRepresentation() const
{
	return inputsdatarepresentation;
}

void TrainingSetFile::init(TrainingSet *ts)
{
	setFormat('f');
	setDecimals(10);
	setTrainingSet(ts);
	//	tsXML = QXmlStreamWriter(this);
	tsWriteXML.setDevice(this);
	tsWriteXML.setAutoFormatting(true);

	tsReadXML.setDevice(this);
}
