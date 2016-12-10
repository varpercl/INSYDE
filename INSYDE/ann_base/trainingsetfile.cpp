#include "trainingsetfile.h"
using namespace ann_base;

const QString TrainingSetFile::STR_TRAININGSET = "trainingset";
const QString TrainingSetFile::STR_PROPERTIES = "properties";
const QString TrainingSetFile::STR_INPUTSDATAREPRESENTATION = "inputsdatarepresentation";
const QString TrainingSetFile::STR_TARGETSDATAREPRESENTATION = "targetsdatarepresentation";
const QString TrainingSetFile::STR_VERSION = "version";
const QString TrainingSetFile::STR_INPUTSNORMALIZATION = "inputsnormalization";
const QString TrainingSetFile::STR_TARGETSNORMALIZATION = "targetsnormalization";
const QString TrainingSetFile::STR_PATTERN = "pattern";
const QString TrainingSetFile::STR_INPUTS = "inputs";
const QString TrainingSetFile::STR_TARGETS = "targets";
const QString TrainingSetFile::STR_NAME = "name";
const QString TrainingSetFile::STR_FORMAT = "format";
const QString TrainingSetFile::STR_WIDTH = "width";
const QString TrainingSetFile::STR_HEIGHT = "height";
const QString TrainingSetFile::STR_INPUTSSIZE = "inputssize";
const QString TrainingSetFile::STR_TARGETSSIZE = "targetssize";
const QString TrainingSetFile::STR_PATTERNSIZE = "patternsize";
const QString TrainingSetFile::STR_TYPE = "type";
const QString TrainingSetFile::STR_MAXVALUE = "maxvalue";
const QString TrainingSetFile::STR_MINVALUE = "minvalue";
const QString TrainingSetFile::STR_THRESHOLD = "threshold";
const QString TrainingSetFile::STR_AMPLITUDE = "amplitude";
const QString TrainingSetFile::STR_ELONGATION = "elongation";
const QString TrainingSetFile::STR_INDEX = "index";
const QString TrainingSetFile::STR_SEPARATOR = ",";

TrainingSetFile::TrainingSetFile() :
	QFile()
{
	init(new TrainingSet());
}

TrainingSetFile::TrainingSetFile(const QString &path) :
	QFile(path)
{
	init(new TrainingSet());
}

TrainingSetFile::TrainingSetFile(TrainingSet *ts, const QString &path) :
	QFile(path)
{
	init(ts);
}

TrainingSetFile::TrainingSetFile(const TrainingSetFile &tsf):
	QFile(tsf.fileName())
{

}

bool TrainingSetFile::flush()
{
	QXmlStreamWriter tsWriteXML;

	int
			nPatterns = ts->getPatternCount(),
			nInputs = ts->getInputsSize(),
			nTargets = ts->getTargetsSize();

	QString strInputs,
			strTargets;

	vector<vector<double> >
			inputs = ts->getInputs(),
			targets = ts->getTargets();

	Normalization
			*inputsNorm = ts->getInputsNormalization(),
			*targetsNorm = ts->getTargetsNormalization();

	QString
			strInputsNorm = inputsNorm->getName(),
			strTargetsNorm = targetsNorm->getName();

	DataRepresentation
			*idr = ts->getInputsDataRepresentation(),
			*tdr = ts->getTargetsDataRepresentation();

	tsWriteXML.setDevice(this);
	tsWriteXML.setAutoFormatting(true);
	tsWriteXML.setAutoFormattingIndent(3);

	tsWriteXML.writeStartDocument();

	tsWriteXML.writeStartElement(STR_TRAININGSET);
	//Indica el numero de patrones a almacenar
	tsWriteXML.writeAttribute(STR_PATTERNSIZE, QString::number(nPatterns));

	//Indica el tamaño de las entradas
	tsWriteXML.writeAttribute(STR_INPUTSSIZE, QString::number(nInputs));

	//Indica el tamaño de las salidas
	tsWriteXML.writeAttribute(STR_TARGETSSIZE, QString::number(nTargets));

	//Indica propiedades particulares del archivo
	tsWriteXML.writeStartElement(STR_PROPERTIES);
	tsWriteXML.writeAttribute(STR_VERSION, "1.0.0");
	tsWriteXML.writeEndElement();

	//Este parametro indica que representacion grafica se usara para visualizar entradas
	tsWriteXML.writeStartElement(STR_INPUTSDATAREPRESENTATION);
	tsWriteXML.writeAttribute(STR_NAME, idr->getName());
	tsWriteXML.writeAttribute(STR_FORMAT, idr->getImageFormatName());
	tsWriteXML.writeAttribute(STR_WIDTH, QString::number(idr->getWidth()));
	tsWriteXML.writeAttribute(STR_HEIGHT, QString::number(idr->getHeight()));
	tsWriteXML.writeEndElement();

	//Este parametro indica que representacion grafica se usara para visualizar las salidas
	tsWriteXML.writeStartElement(STR_TARGETSDATAREPRESENTATION);
	tsWriteXML.writeAttribute(STR_NAME, tdr->getName());
	tsWriteXML.writeAttribute(STR_FORMAT, tdr->getImageFormatName());
	tsWriteXML.writeAttribute(STR_WIDTH, QString::number(tdr->getWidth()));
	tsWriteXML.writeAttribute(STR_HEIGHT, QString::number(tdr->getHeight()));
	tsWriteXML.writeEndElement();

	//Normalizacion de entradas
	tsWriteXML.writeStartElement(STR_INPUTSNORMALIZATION);
	tsWriteXML.writeAttribute(STR_TYPE, strInputsNorm);
	tsWriteXML.writeAttribute(STR_MAXVALUE, QString::number(inputsNorm->getMaxValue(), decimalformat, decimals));
	tsWriteXML.writeAttribute(STR_MINVALUE, QString::number(inputsNorm->getMinValue(), decimalformat, decimals));
	tsWriteXML.writeAttribute(STR_THRESHOLD, QString::number(inputsNorm->getThreshold(), decimalformat, decimals));
	tsWriteXML.writeAttribute(STR_AMPLITUDE, QString::number(inputsNorm->getAmplitude(), decimalformat, decimals));
	tsWriteXML.writeAttribute(STR_ELONGATION, QString::number(inputsNorm->getElongation(), decimalformat, decimals));
	tsWriteXML.writeEndElement();

	//Normalizacion de salidas
	tsWriteXML.writeStartElement(STR_TARGETSNORMALIZATION);
	tsWriteXML.writeAttribute(STR_TYPE, strTargetsNorm);
	tsWriteXML.writeAttribute(STR_MAXVALUE, QString::number(targetsNorm->getMaxValue(), decimalformat, decimals));
	tsWriteXML.writeAttribute(STR_MINVALUE, QString::number(targetsNorm->getMinValue(), decimalformat, decimals));
	tsWriteXML.writeAttribute(STR_THRESHOLD, QString::number(targetsNorm->getThreshold(), decimalformat, decimals));
	tsWriteXML.writeAttribute(STR_AMPLITUDE, QString::number(targetsNorm->getAmplitude(), decimalformat, decimals));
	tsWriteXML.writeAttribute(STR_ELONGATION, QString::number(targetsNorm->getElongation(), decimalformat, decimals));
	tsWriteXML.writeEndElement();

	for(int p = 0; p < nPatterns; p++){
		tsWriteXML.writeStartElement(STR_PATTERN);
		tsWriteXML.writeAttribute(STR_INDEX, QString::number(p));
		//Se escriben las entradas
		tsWriteXML.writeStartElement(STR_INPUTS);
		strInputs = "";
		for(int i = 0; i < nInputs; i++){
			strInputs += QString::number(inputs[p][i], decimalformat, decimals);
			if(i != nInputs - 1){
				strInputs += STR_SEPARATOR;
			}
		}
		tsWriteXML.writeCharacters(strInputs);
		tsWriteXML.writeEndElement();//inputs

		//Se escriben las salidas
		tsWriteXML.writeStartElement(STR_TARGETS);
		strTargets = "";
		for(int t = 0; t < nTargets; t++){
			strTargets += QString::number(targets[p][t], decimalformat, decimals);
			if(t != nTargets - 1){
				strTargets += STR_SEPARATOR;
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

void TrainingSetFile::setVersion(const QString &ver)
{
	version = ver;
}

QString TrainingSetFile::getVersion() const
{
	return version;
}

TrainingSetFile::TSFResult TrainingSetFile::load()
{
	TrainingSetFile::TSFResult result = fromFile(*this);
	ts = result.file->getTrainingSet();
	return result;
}

TrainingSetFile::TSFResult TrainingSetFile::fromFile(const QString &path)
{
	QFile file(path);

	return fromFile(file);
}

TrainingSetFile::TSFResult TrainingSetFile::fromFile(QFile &file)
{
	QString
			version,
			text;

	QStringRef name;

	QXmlStreamReader tsReadXML;

	QXmlStreamReader::TokenType tt;
	QStringList textElements;
	QXmlStreamAttributes attributes;

	TrainingSetFile *retTSF = new TrainingSetFile();
	TSFResult res = {retTSF, true, NoError, "", 0};

	TrainingSet *ts = retTSF->getTrainingSet();

	int
			lastPatternIndex = 0,
			sTextElements,
			pSize = 0,
			iSize = 0,
			tSize = 0;

	Normalization
			*inor = new Normalization(),
			*tnor = new Normalization();

	vector<vector<double> >
			inputs,
			targets;

	DataRepresentation
			*idr = ts->getInputsDataRepresentation(),
			*tdr = ts->getTargetsDataRepresentation();

	if(file.open(QIODevice::ReadOnly)){
		tsReadXML.setDevice(&file);
		while (!tsReadXML.atEnd()) {
			tt = tsReadXML.readNext();

			if(tsReadXML.hasError()){
				file.close();
				return {retTSF, false, toTSFError(tsReadXML.error()), tsReadXML.errorString(), tsReadXML.lineNumber()};
			}

			if(tt == QXmlStreamReader::StartDocument){
				continue;
			}else if(tt == QXmlStreamReader::StartElement){
				name = tsReadXML.name();
				if(name == STR_TRAININGSET){
					attributes = tsReadXML.attributes();
					if(attributes.hasAttribute(STR_PATTERNSIZE) &&
					   attributes.hasAttribute(STR_INPUTSSIZE) &&
					   attributes.hasAttribute(STR_TARGETSSIZE))
					{
						pSize = attributes.value(STR_PATTERNSIZE).toInt();
						iSize = attributes.value(STR_INPUTSSIZE).toInt();
						tSize = attributes.value(STR_TARGETSSIZE).toInt();

						inputs = vector<vector<double> >(pSize, vector<double>(iSize, 0));
						targets = vector<vector<double> >(pSize, vector<double>(tSize, 0));
					}else{
						file.close();
						return {
							retTSF, false, NotWellFormedError, "NotWellFormedError: Missing attributes (" + STR_PATTERNSIZE + ", " + STR_INPUTSSIZE + ", " + STR_TARGETSSIZE + ") on tag " + STR_TRAININGSET, tsReadXML.lineNumber()
						};
					}
				}else if(name == STR_PROPERTIES){
					attributes = tsReadXML.attributes();
					if(attributes.hasAttribute(STR_VERSION)){
						version = attributes.value(STR_VERSION).toString();
					}else{
						file.close();
						return
						{
							retTSF, false, NotWellFormedError, "NotWellFormedError: Missing attributes (" + STR_VERSION + ") on tag " + STR_PROPERTIES, tsReadXML.lineNumber()
						};
					}
				}else if(name == STR_INPUTSDATAREPRESENTATION){
					attributes = tsReadXML.attributes();
					if(attributes.hasAttribute(STR_NAME) &&
					   attributes.hasAttribute(STR_WIDTH) &&
					   attributes.hasAttribute(STR_HEIGHT) &&
					   attributes.hasAttribute(STR_FORMAT))
					{
						idr->setType(drFromStrToInt(attributes.value(STR_NAME).toString()));
						idr->setWidth(attributes.value(STR_WIDTH).toInt());
						idr->setHeight(attributes.value(STR_HEIGHT).toInt());
						idr->setImageFormat(fromStrToImgFormat(attributes.value(STR_FORMAT).toString()));
					}else{
						file.close();
						return
						{
							retTSF, false, NotWellFormedError, "NotWellFormedError: Missing attributes (" + STR_NAME + ", " + STR_WIDTH + ", " + STR_HEIGHT + ", " + STR_FORMAT + ") on tag " + STR_INPUTSDATAREPRESENTATION, tsReadXML.lineNumber()
						};
					}
				}else if(name == STR_TARGETSDATAREPRESENTATION){
					attributes = tsReadXML.attributes();
					if(attributes.hasAttribute(STR_NAME) &&
					   attributes.hasAttribute(STR_WIDTH) &&
					   attributes.hasAttribute(STR_HEIGHT) &&
					   attributes.hasAttribute(STR_FORMAT))
					{
						tdr->setType(drFromStrToInt(attributes.value(STR_NAME).toString()));
						tdr->setWidth(attributes.value(STR_WIDTH).toInt());
						tdr->setHeight(attributes.value(STR_HEIGHT).toInt());
						tdr->setImageFormat(fromStrToImgFormat(attributes.value(STR_FORMAT).toString()));
					}else{
						file.close();
						return
						{
							retTSF, false, NotWellFormedError, "NotWellFormedError: Missing attributes (" + STR_NAME + ", " + STR_WIDTH + ", " + STR_HEIGHT + ", " + STR_FORMAT + ") on tag " + STR_TARGETSDATAREPRESENTATION, tsReadXML.lineNumber()
						};
					}
				}else if(name == STR_INPUTSNORMALIZATION){
					attributes = tsReadXML.attributes();
					if(attributes.hasAttribute(STR_TYPE) &&
					   attributes.hasAttribute(STR_MAXVALUE) &&
					   attributes.hasAttribute(STR_MINVALUE) &&
					   attributes.hasAttribute(STR_THRESHOLD) &&
					   attributes.hasAttribute(STR_AMPLITUDE) &&
					   attributes.hasAttribute(STR_ELONGATION))
					{
						inor->setType(normFromStrToInt(attributes.value(STR_TYPE).toString()));
						inor->setMaxValue(attributes.value(STR_MAXVALUE).toDouble());
						inor->setMinValue(attributes.value(STR_MINVALUE).toDouble());
						inor->setThreshold(attributes.value(STR_THRESHOLD).toDouble());
						inor->setAmplitude(attributes.value(STR_AMPLITUDE).toDouble());
						inor->setElongation(attributes.value(STR_ELONGATION).toDouble());
					}else{
						file.close();
						return
						{
							retTSF, false, NotWellFormedError, "NotWellFormedError: Missing attributes (" + STR_TYPE + ", " + STR_MAXVALUE + ", " + STR_MINVALUE + ", " + STR_THRESHOLD + ", " + STR_ELONGATION + ") on tag " + STR_INPUTSNORMALIZATION, tsReadXML.lineNumber()
						};
					}
				}else if(name == STR_TARGETSNORMALIZATION){
					attributes = tsReadXML.attributes();
					if(attributes.hasAttribute(STR_TYPE) &&
					   attributes.hasAttribute(STR_MAXVALUE) &&
					   attributes.hasAttribute(STR_MINVALUE) &&
					   attributes.hasAttribute(STR_THRESHOLD) &&
					   attributes.hasAttribute(STR_AMPLITUDE) &&
					   attributes.hasAttribute(STR_ELONGATION))
					{
						tnor->setType(normFromStrToInt(attributes.value(STR_TYPE).toString()));
						tnor->setMaxValue(attributes.value(STR_MAXVALUE).toDouble());
						tnor->setMinValue(attributes.value(STR_MINVALUE).toDouble());
						tnor->setThreshold(attributes.value(STR_THRESHOLD).toDouble());
						tnor->setAmplitude(attributes.value(STR_AMPLITUDE).toDouble());
						tnor->setElongation(attributes.value(STR_ELONGATION).toDouble());
					}else{
						file.close();
						return
						{
							retTSF, false, NotWellFormedError, "NotWellFormedError: Missing attributes (" + STR_TYPE + ", " + STR_MAXVALUE + ", " + STR_MINVALUE + ", " + STR_THRESHOLD + ", " + STR_ELONGATION + ") on tag " + STR_TARGETSNORMALIZATION, tsReadXML.lineNumber()
						};
					}
				}else if(name == STR_PATTERN){
					attributes = tsReadXML.attributes();
					if(attributes.hasAttribute(STR_INDEX))
					{
						lastPatternIndex = attributes.value(STR_INDEX).toInt();
					}else{
						file.close();
						return
						{
							retTSF, false, NotWellFormedError, "NotWellFormedError: Missing attributes (" + STR_INDEX + ") on tag " + STR_PATTERN, tsReadXML.lineNumber()
						};
					}
				}else if(name == STR_INPUTS){
					text = tsReadXML.readElementText(QXmlStreamReader::SkipChildElements);
					textElements = text.split(STR_SEPARATOR, QString::KeepEmptyParts, Qt::CaseInsensitive);
					sTextElements = textElements.size();
					if(sTextElements == iSize){
						for(int i = 0; i < sTextElements; i++){
							inputs[lastPatternIndex][i] = textElements[i].toDouble();
						}
					}else{
						file.close();
						return
						{
							retTSF, false, NotWellFormedError, "NotWellFormedError: Incongruence between reported input size with found inputs elements", tsReadXML.lineNumber()
						};
					}
				}else if(name == STR_TARGETS){
					text = tsReadXML.readElementText(QXmlStreamReader::SkipChildElements);
					textElements = text.split(STR_SEPARATOR, QString::KeepEmptyParts, Qt::CaseInsensitive);
					sTextElements = textElements.size();
					if(sTextElements == tSize){
						for(int t = 0; t < sTextElements; t++){
							targets[lastPatternIndex][t] = textElements[t].toDouble();
						}
					}else{
						file.close();
						return
						{
							retTSF, false, NotWellFormedError, "NotWellFormedError: Incongruence between reported target size with found target elements", tsReadXML.lineNumber()
						};
					}
				}
			}
		}

		retTSF->setFileName(file.fileName());
		res.file = retTSF;

		ts->setPatternCount(pSize);
		ts->setInputs(inputs, iSize);
		ts->setTargets(targets, tSize);
		ts->setInputsNormalization(inor);
		ts->setTargetsNormalization(tnor);
		ts->setInputsDataRepresentation(idr);
		ts->setTargetsDataRepresentation(tdr);

		res.sucess = true;
		res.errnum = toTSFError(QXmlStreamReader::NoError);
		res.errormsg = "";
		res.line = -1;

		file.close();
		return res;
	}else{
		file.close();
		return
		{
			retTSF, false, toTSFError(file.error()), file.errorString(), -1
		};
	}
}

TrainingSetFile::TSFError TrainingSetFile::toTSFError(const QFileDevice::FileError &tsferr)
{
	switch(tsferr){
		case QFileDevice::NoError:
			return NoError;
		case QFileDevice::ReadError:
			return ReadError;
		case QFileDevice::WriteError:
			return WriteError;
		case QFileDevice::FatalError:
			return FatalError;
		case QFileDevice::ResourceError:
			return ResourceError;
		case QFileDevice::OpenError:
			return OpenError;
		case QFileDevice::AbortError:
			return AbortError;
		case QFileDevice::TimeOutError:
			return TimeOutError;
		case QFileDevice::UnspecifiedError:
			return UnspecifiedError;
		case QFileDevice::RemoveError:
			return RemoveError;
		case QFileDevice::RenameError:
			return RenameError;
		case QFileDevice::PositionError:
			return PositionError;
		case QFileDevice::ResizeError:
			return ResizeError;
		case QFileDevice::PermissionsError:
			return PermissionsError;
		case QFileDevice::CopyError:
			return CopyError;
		default:
			return UnspecifiedError;
	}
}

TrainingSetFile::TSFError TrainingSetFile::toTSFError(const QXmlStreamReader::Error &tsferr)
{
	switch(tsferr){
		case QXmlStreamReader::NoError:
			return NoError;
		case QXmlStreamReader::UnexpectedElementError:
			return UnexpectedElementError;
		case QXmlStreamReader::CustomError:
			return CustomError;
		case QXmlStreamReader::NotWellFormedError:
			return NotWellFormedError;
		case QXmlStreamReader::PrematureEndOfDocumentError:
			return PrematureEndOfDocumentError;
		default:
			return UnspecifiedError;
	}
}

void TrainingSetFile::init(TrainingSet *ts)
{
	setFormat('f');
	setDecimals(10);
	setTrainingSet(ts);
}

Normalization::Type TrainingSetFile::normFromStrToInt(const QString &str)
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

DataRepresentation::Type TrainingSetFile::drFromStrToInt(const QString &str)
{
	if(str == "Raw"){
		return DataRepresentation::Raw;
	}else if(str == "Image"){
		return DataRepresentation::Image;
	}else if(str == "DotMatrix"){
		return DataRepresentation::DotMatrix;
	}else if(str == "Sound"){
		return DataRepresentation::Sound;
	}else if(str == "Text"){
		return DataRepresentation::Text;
	}else if(str == "Chart"){
		return DataRepresentation::Chart;
	}else{
		return DataRepresentation::Raw;
	}
}

QImage::Format TrainingSetFile::fromStrToImgFormat(const QString &str)
{
	if(str == "Format_Invalid"){
		return QImage::Format_Invalid;
	}else if(str == "Format_Mono"){
		return QImage::Format_Mono;
	}else if(str == "Format_MonoLSB"){
		return QImage::Format_MonoLSB;
	}else if(str == "Format_Indexed8"){
		return QImage::Format_Indexed8;
	}else if(str == "Format_RGB32"){
		return QImage::Format_RGB32;
	}else if(str == "Format_ARGB32"){
		return QImage::Format_ARGB32;
	}else if(str == "Format_ARGB32_Premultiplied"){
		return QImage::Format_ARGB32_Premultiplied;
	}else if(str == "Format_RGB16"){
		return QImage::Format_RGB16;
	}else if(str == "Format_ARGB8565_Premultiplied"){
		return QImage::Format_ARGB8565_Premultiplied;
	}else if(str == "Format_RGB666"){
		return QImage::Format_RGB666;
	}else if(str == "Format_ARGB6666_Premultiplied"){
		return QImage::Format_ARGB6666_Premultiplied;
	}else if(str == "Format_RGB555"){
		return QImage::Format_RGB555;
	}else if(str == "Format_ARGB8555_Premultiplied"){
		return QImage::Format_ARGB8555_Premultiplied;
	}else if(str == "Format_RGB888"){
		return QImage::Format_RGB888;
	}else if(str == "Format_RGB444"){
		return QImage::Format_RGB444;
	}else if(str == "Format_ARGB4444_Premultiplied"){
		return QImage::Format_ARGB4444_Premultiplied;
	}else if(str == "Format_RGBX8888"){
		return QImage::Format_RGBX8888;
	}else if(str == "Format_RGBA8888"){
		return QImage::Format_RGBA8888;
	}else if(str == "Format_RGBA8888_Premultiplied"){
		return QImage::Format_RGBA8888_Premultiplied;
	}else if(str == "Format_BGR30"){
		return QImage::Format_BGR30;
	}else if(str == "Format_A2BGR30_Premultiplied"){
		return QImage::Format_A2BGR30_Premultiplied;
	}else if(str == "Format_RGB30"){
		return QImage::Format_RGB30;
	}else if(str == "Format_A2RGB30_Premultiplied"){
		return QImage::Format_A2RGB30_Premultiplied;
	}else if(str == "NImageFormats"){
		return QImage::NImageFormats;
	}else{
		return QImage::Format_Invalid;
	}
}


