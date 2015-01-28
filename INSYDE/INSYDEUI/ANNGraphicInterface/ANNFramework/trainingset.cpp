#include "trainingset.h"

TrainingSet::TrainingSet() :
	QAbstractTableModel()
{
	vector<vector<double> > single_cell = vector<vector<double> >(1, vector<double> (1, 0));

	init(single_cell, 1, single_cell, 1);
}

TrainingSet::TrainingSet(int inputsize, int targetsize, int n) :
	QAbstractTableModel()
{
	vector<vector<double> >
			inputs = vector<vector<double> >(n, vector<double> (inputsize, 0)),
			targets = vector<vector<double> >(n, vector<double> (targetsize, 0));

	init(inputs, inputsize, targets, targetsize);
}

TrainingSet::TrainingSet(const vector<vector<double> > &inputs, int is, const vector<vector<double> > &targets, int ts) :
	QAbstractTableModel()
{
	init(inputs, is, targets, ts);
}

TrainingSet::TrainingSet(double **inputs,
						 unsigned int sinputs,
						 double **targets,
						 unsigned int stargets,
						 unsigned int spatterns) :
	QAbstractTableModel()
{
	vector<vector<double> >
			tinputs(spatterns),
			ttargets(spatterns);

	for(unsigned int i = 0; i < spatterns; i++){
		tinputs[i] = vector<double>(inputs[i], inputs[i] + sinputs);
		ttargets[i] = vector<double>(targets[i], targets[i] + stargets);
	}
	init(tinputs, sinputs, ttargets, stargets);
}

TrainingSet::TrainingSet(MultilayerPerceptron *mlp) :
	QAbstractTableModel()
{
	init(vector<vector<double> >(1, vector<double>(mlp->getInputSize(), 0)), mlp->getInputSize(), vector<vector<double> >(1, vector<double>(mlp->getOutputSize(), 0)), mlp->getOutputSize());
}

TrainingSet::TrainingSet(TrainingSetFile &file) :
	QAbstractTableModel()
{
	QPair<TrainingSet*, TrainingSetFile::Error> tsf = TrainingSetFile::fromFile(file);

	if(tsf.second.errnum == 0){
		*this = *(tsf.first);
	}
}

TrainingSet::TrainingSet(const QString &path) :
	QAbstractTableModel()
{
	QPair<TrainingSet*, TrainingSetFile::Error> tsf = TrainingSetFile::fromFile(path);

	if(tsf.second.errnum == 0){
		*this = *(tsf.first);
	}
}

TrainingSet::TrainingSet(const TrainingSetFile &file) :
	QAbstractTableModel()
{
	*this = *file.getTrainingSet();
}

TrainingSet::TrainingSet(const TrainingSet &ts) :
	QAbstractTableModel()
{
	*this = ts;
}

TrainingSet::~TrainingSet()
{
}

void TrainingSet::setInputSize(int is, double fill)
{
	int ls = getInputsSize();

	//Si realmente hubo un cambio en el tamaño de las entradas
	if(is != ls){
		inputsSize = is;
		resizeVectorSet(inputs, inputsSize, fill);
		resizeVectorSet(normalizedInputs, inputsSize, 0);
		normalizeInputs(getInputsNormalization());

		emit inputsSizeChanged(is);
		emit inputsSizeChanged(ls, is);

		//NOTE: se debe probar si es necesario emitir dataChanged
	}
}

int TrainingSet::getInputsSize() const
{
	return inputsSize;
}

void TrainingSet::setTargetSize(int ts, double fill)
{
	int ls = getTargetsSize();

	//Si realmente cambio el tamaño del patron de salidas
	if(ls != ts){
		targetsSize = ts;
		resizeVectorSet(targets, targetsSize, fill);
		resizeVectorSet(normalizedTargets, targetsSize, fill);
		normalizeTargets(getTargetsNormalization());

		emit targetsSizeChanged(ts);
		emit targetsSizeChanged(ls, ts);

		//NOTE: se debe probar si es necesario emitir dataChanged
	}
}

int TrainingSet::getTargetsSize() const
{
	return targetsSize;
}

void TrainingSet::insertPattern(const vector<double> &inputs, const vector<double> &targets, int i)
{
	vector<vector<double> >::iterator it;

	vector<double>
			cinputs = inputs,
			ctargets = targets;

	if(cinputs.size() != (size_t)inputsSize){
		cinputs.resize(inputsSize, 0);
	}
	if(ctargets.size() != (size_t)targetsSize){
		ctargets.resize(targetsSize, 0);
	}

	it = this->inputs.begin();
	this->inputs.insert(it + i, cinputs);
	this->normalizedInputs.insert(it + i, normalizedVector(cinputs, getInputsNormalization()));

	it = this->targets.begin();
	this->targets.insert(it + i, ctargets);
	this->normalizedTargets.insert(it + i, normalizedVector(ctargets, getTargetsNormalization()));

	//NOTE: esta en evaluacion la llamada a este metodo despues de hacer la insercion
	insertRow(i);

	emit patternInserted(inputs, targets, i);
}

void TrainingSet::insertPattern(const vector<int> &inputs, const vector<int> &targets, int i)
{
	vector<double>
			newInputs = vector<double>(inputs.begin(), inputs.end()),
			newTargets = vector<double>(targets.begin(), targets.end());
	insertPattern(newInputs, newTargets, i);
}

void TrainingSet::removePattern(int i)
{
	if(i >= 0 && i < patternCount){
		vector<vector<double> >::iterator it;
		vector<vector<double> >::iterator inputPattern, targetPattern;

		it = inputs.begin();
		inputPattern = inputs.erase(it + i);
		normalizedInputs.erase(it + i);

		it = targets.begin();
		targetPattern = targets.erase(it + i);
		normalizedTargets.erase(it + i);

		patternCount--;

		//NOTE: se deve evaluar si es necesario llamar a este metodo heredado
		removeRow(i);

		emit patternDeleted(*inputPattern, *targetPattern, i);
	}
}

void TrainingSet::setInputs(const vector<vector<double> > &inputs, int size)
{

	//TODO: validar el correcto funcionamiento

	if(size <= 0) return;

	vector<vector<double> >
			li = this->inputs;

	this->inputs = inputs;

	if(this->inputs.size() != (size_t)patternCount){
		this->inputs.resize(patternCount);
		normalizedInputs.resize(patternCount);
	}

	if(inputsSize != size){

		for(size_t i = 0; i < this->inputs.size(); i++){
			this->inputs[i].resize(size);
		}

		inputsSize = size;
		resizeVectorSet(normalizedInputs, inputsSize, 0);

		emit inputsSizeChanged(inputsSize);
		emit inputsSizeChanged(li.size(), inputsSize);
	}
	normalizeInputs(getInputsNormalization());

	if(li != inputs){
		emit inputsChanged(inputs);
		emit inputsChanged(li, inputs);
	}
}

void TrainingSet::setInputs(const vector<vector<int> > &inputs, int size)
{
	setInputs(ANN::toDouble(inputs), size);
}

void TrainingSet::setTargets(const vector<vector<double> > &targets, int size)
{
	//FIXME: validar el correcto funcionamiento

	if(size <= 0) return;

	vector<vector<double> >
			lt = this->targets;

	this->targets = targets;

	if(this->targets.size() != (size_t)patternCount){
		this->targets.resize(patternCount);
		normalizedTargets.resize(patternCount);
	}

	if(targetsSize != size){

		for(size_t i = 0; i < this->targets.size(); i++){
			this->targets[i].resize(size);
		}

		targetsSize = size;
		resizeVectorSet(normalizedTargets, targetsSize, 0);

		emit targetsSizeChanged(targetsSize);
		emit targetsSizeChanged(lt.size(), targetsSize);
	}
	normalizeTargets(getTargetsNormalization());

	if(lt != targets){
		emit targetsChanged(targets);
		emit targetsChanged(lt, targets);
	}
}

void TrainingSet::setTargets(const vector<vector<int> > &targets, int size)
{
	setTargets(ANN::toDouble(targets), size);
}

vector<vector<double> > TrainingSet::getInputs() const
{
	return inputs;
}

vector<vector<double> > TrainingSet::getTargets() const
{
	return targets;
}

void TrainingSet::normalizeNothing()
{
	normalizedInputs = inputs;
	normalizedTargets = targets;

	setInputsNormalization(Normalization(Normalization::Nothing));
	setTargetsNormalization(Normalization(Normalization::Nothing));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeInputsNothing()
{
	normalizedInputs = inputs;
	setInputsNormalization(Normalization(Normalization::Nothing));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeTargetsNothing()
{
	normalizedTargets = targets;
	setTargetsNormalization(Normalization(Normalization::Nothing));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeLinearFixedRange(Normalization in, Normalization tn)
{
	normalizedInputs = ANN::normalizeLinearFixedRange(inputs, in.getMinValue(), in.getMaxValue());
	normalizedTargets = ANN::normalizeLinearFixedRange(targets, tn.getMinValue(), tn.getMaxValue());

	setInputsNormalization(in);

	setTargetsNormalization(tn);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeLinearFixedRange(double minInputs, double maxInputs, double minTargets, double maxTargets)
{
	normalizedInputs = ANN::normalizeLinearFixedRange(inputs, minInputs, maxInputs);
	normalizedTargets = ANN::normalizeLinearFixedRange(targets, minTargets, maxTargets);

	setInputsNormalization(Normalization(Normalization::LinearFixedRange, minInputs, maxInputs));

	setTargetsNormalization(Normalization(Normalization::LinearFixedRange, minTargets, maxTargets));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeInputsLinearFixedRange(Normalization in)
{
	normalizedInputs = ANN::normalizeLinearFixedRange(inputs, in.getMinValue(), in.getMaxValue());

	setInputsNormalization(in);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeInputsLinearFixedRange(double min, double max)
{
	normalizedInputs = ANN::normalizeLinearFixedRange(inputs, min, max);

	setInputsNormalization(Normalization(Normalization::LinearFixedRange, min, max));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeTargetsLinearFixedRange(Normalization tn)
{
	normalizedTargets = ANN::normalizeLinearFixedRange(targets, tn.getMinValue(), tn.getMaxValue());

	setTargetsNormalization(tn);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeTargetsLinearFixedRange(double min, double max)
{
	normalizedTargets = ANN::normalizeLinearFixedRange(targets, min, max);

	setTargetsNormalization(Normalization(Normalization::LinearFixedRange, min, max));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeLinearAutoRange(Normalization *in, Normalization *tn)
{
	double
			inMin = in->getMinValue(),
			inMax = in->getMaxValue(),
			tnMin = tn->getMinValue(),
			tnMax = tn->getMaxValue();
	normalizedInputs = ANN::normalizeLinearAutoRange(inputs, &inMin, &inMax);
	normalizedTargets = ANN::normalizeLinearAutoRange(targets, &tnMin, &tnMax);

	in->setMinValue(inMin);
	in->setMaxValue(inMax);
	setInputsNormalization(*in);

	tn->setMinValue(tnMin);
	tn->setMaxValue(tnMax);
	setTargetsNormalization(*tn);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeLinearAutoRange(double *minInputs, double *maxInputs, double *minTargets, double *maxTargets)
{
	normalizedInputs = ANN::normalizeLinearAutoRange(inputs, minInputs, maxInputs);
	normalizedTargets = ANN::normalizeLinearAutoRange(targets, minTargets, maxTargets);

	setInputsNormalization(Normalization(Normalization::LinearAutoRange, *minInputs, *maxInputs));

	setTargetsNormalization(Normalization(Normalization::LinearAutoRange, *minTargets, *maxTargets));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeInputsLinearAutoRange(Normalization *in)
{
	double
			min = in->getMinValue(),
			max = in->getMaxValue();
	normalizedInputs = ANN::normalizeLinearAutoRange(inputs, &min, &max);

	in->setMinValue(min);
	in->setMaxValue(max);
	setInputsNormalization(*in);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeInputsLinearAutoRange(double *min, double *max)
{
	normalizedInputs = ANN::normalizeLinearAutoRange(inputs, min, max);

	setInputsNormalization(Normalization(Normalization::LinearAutoRange, *min, *max));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeTargetsLinearAutoRange(Normalization *tn)
{
	double
			min = tn->getMinValue(),
			max = tn->getMaxValue();
	normalizedTargets = ANN::normalizeLinearAutoRange(targets, &min, &max);

	tn->setMinValue(min);
	tn->setMaxValue(max);
	setTargetsNormalization(*tn);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeTargetsLinearAutoRange(double *min, double *max)
{
	normalizedTargets = ANN::normalizeLinearAutoRange(targets, min, max);

	setTargetsNormalization(Normalization(Normalization::LinearAutoRange, *min, *max));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeUnipolarFixedThreshold(Normalization in, Normalization tn)
{
	normalizedInputs = ANN::normalizeUnipolarFixedThreshold(inputs, in.getThreshold());
	normalizedTargets = ANN::normalizeUnipolarFixedThreshold(targets, tn.getThreshold());

	setInputsNormalization(in);

	setTargetsNormalization(tn);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeUnipolarFixedThreshold(double inThreshold, double tarThreshold)
{
	normalizedInputs = ANN::normalizeUnipolarFixedThreshold(inputs, inThreshold);
	normalizedTargets = ANN::normalizeUnipolarFixedThreshold(targets, tarThreshold);

	setInputsNormalization(Normalization(Normalization::UnipolarFixedThreshold, 999999999, -999999999, inThreshold));

	setTargetsNormalization(Normalization(Normalization::UnipolarFixedThreshold, 999999999, -999999999, tarThreshold));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeInputsUnipolarFixedThreshold(Normalization in)
{
	normalizedInputs = ANN::normalizeUnipolarFixedThreshold(inputs, in.getThreshold());

	setInputsNormalization(in);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeInputsUnipolarFixedThreshold(double threshold)
{
	normalizedInputs = ANN::normalizeUnipolarFixedThreshold(inputs, threshold);

	setInputsNormalization(Normalization(Normalization::UnipolarFixedThreshold, 999999999, -999999999, threshold));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeTargetsUnipolarFixedThreshold(Normalization tn)
{
	normalizedTargets = ANN::normalizeUnipolarFixedThreshold(targets, tn.getThreshold());

	setTargetsNormalization(tn);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeTargetsUnipolarFixedThreshold(double threshold)
{
	normalizedTargets = ANN::normalizeUnipolarFixedThreshold(targets, threshold);

	setTargetsNormalization(Normalization(Normalization::UnipolarFixedThreshold, 999999999, -999999999, threshold));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeUnipolarAutoThreshold(Normalization *in, Normalization *tn)
{
	double
			inThre = in->getThreshold(),
			tnThre = tn->getThreshold();
	normalizedInputs = ANN::normalizeUnipolarAutoThreshold(inputs, &inThre);
	normalizedTargets = ANN::normalizeUnipolarAutoThreshold(targets, &tnThre);

	in->setThreshold(inThre);
	setInputsNormalization(*in);

	tn->setThreshold(tnThre);
	setTargetsNormalization(*tn);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeUnipolarAutoThreshold(double *inThreshold, double *tarThreshold)
{
	normalizedInputs = ANN::normalizeUnipolarAutoThreshold(inputs, inThreshold);
	normalizedTargets = ANN::normalizeUnipolarAutoThreshold(targets, tarThreshold);

	setInputsNormalization(Normalization(Normalization::UnipolarAutoThreshold, 999999999, -999999999, *inThreshold));

	setTargetsNormalization(Normalization(Normalization::UnipolarAutoThreshold, 999999999, -999999999, *tarThreshold));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeInputsUnipolarAutoThreshold(Normalization *in)
{
	double
			thre = in->getThreshold();
	normalizedInputs = ANN::normalizeUnipolarAutoThreshold(inputs, &thre);

	in->setThreshold(thre);
	setInputsNormalization(*in);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeInputsUnipolarAutoThreshold(double *threshold)
{
	normalizedInputs = ANN::normalizeUnipolarAutoThreshold(inputs, threshold);

	setInputsNormalization(Normalization(Normalization::UnipolarAutoThreshold, 999999999, -999999999, *threshold));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeTargetsUnipolarAutoThreshold(Normalization *tn)
{
	double
			thre = tn->getThreshold();
	normalizedTargets = ANN::normalizeUnipolarAutoThreshold(targets, &thre);

	tn->setThreshold(thre);
	setTargetsNormalization(*tn);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeTargetsUnipolarAutoThreshold(double *threshold)
{
	normalizedTargets = ANN::normalizeUnipolarAutoThreshold(targets, threshold);

	setTargetsNormalization(Normalization(Normalization::UnipolarAutoThreshold, 999999999, -999999999, *threshold));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeBipolarFixedThreshold(Normalization in, Normalization tn)
{
	normalizedInputs = ANN::normalizeBipolarFixedThreshold(inputs, tn.getThreshold());
	normalizedTargets = ANN::normalizeBipolarFixedThreshold(targets, tn.getThreshold());

	setInputsNormalization(in);

	setTargetsNormalization(tn);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeBipolarFixedThreshold(double inThreshold, double tarThreshold)
{
	normalizedInputs = ANN::normalizeBipolarFixedThreshold(inputs, inThreshold);
	normalizedTargets = ANN::normalizeBipolarFixedThreshold(targets, tarThreshold);

	setInputsNormalization(Normalization(Normalization::BipolarFixedThreshold, 999999999, -999999999, inThreshold));

	setTargetsNormalization(Normalization(Normalization::BipolarFixedThreshold, 999999999, -999999999, tarThreshold));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeInputsBipolarFixedThreshold(Normalization in)
{
	normalizedInputs = ANN::normalizeBipolarFixedThreshold(inputs, in.getThreshold());

	setInputsNormalization(in);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeInputsBipolarFixedThreshold(double threshold)
{
	normalizedInputs = ANN::normalizeBipolarFixedThreshold(inputs, threshold);

	setInputsNormalization(Normalization(Normalization::BipolarFixedThreshold, 999999999, -999999999, threshold));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeTargetsBipolarFixedThreshold(Normalization tn)
{
	normalizedTargets = ANN::normalizeBipolarFixedThreshold(targets, tn.getThreshold());

	setTargetsNormalization(tn);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeTargetsBipolarFixedThreshold(double threshold)
{
	normalizedTargets = ANN::normalizeBipolarFixedThreshold(targets, threshold);

	setTargetsNormalization(Normalization(Normalization::BipolarFixedThreshold, 999999999, -999999999, threshold));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeBipolarAutoThreshold(Normalization *in, Normalization *tn)
{
	double
			inThre = in->getThreshold(),
			tnThre = tn->getThreshold();
	normalizedInputs = ANN::normalizeBipolarAutoThreshold(inputs, &inThre);
	normalizedTargets = ANN::normalizeBipolarAutoThreshold(targets, &tnThre);

	in->setThreshold(inThre);
	setInputsNormalization(*in);

	tn->setThreshold(tnThre);
	setTargetsNormalization(*tn);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeBipolarAutoThreshold(double *inThreshold, double *tarThreshold)
{
	normalizedInputs = ANN::normalizeBipolarAutoThreshold(inputs, inThreshold);
	normalizedTargets = ANN::normalizeBipolarAutoThreshold(targets, tarThreshold);

	setInputsNormalization(Normalization(Normalization::BipolarAutoThreshold, 999999999, -999999999, *inThreshold));

	setTargetsNormalization(Normalization(Normalization::BipolarAutoThreshold, 999999999, -999999999, *tarThreshold));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeInputsBipolarAutoThreshold(Normalization *in)
{
	double
			thre = in->getThreshold();
	normalizedInputs = ANN::normalizeBipolarAutoThreshold(inputs, &thre);

	in->setThreshold(thre);
	setInputsNormalization(*in);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeInputsBipolarAutoThreshold(double *threshold)
{
	normalizedInputs = ANN::normalizeBipolarAutoThreshold(inputs, threshold);

	setInputsNormalization(Normalization(Normalization::BipolarAutoThreshold, 999999999, -999999999, *threshold));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeTargetsBipolarAutoThreshold(Normalization *tn)
{
	double
			thre = tn->getThreshold();
	normalizedTargets = ANN::normalizeBipolarAutoThreshold(targets, &thre);

	tn->setThreshold(thre);
	setTargetsNormalization(*tn);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeTargetsBipolarAutoThreshold(double *threshold)
{
	normalizedTargets = ANN::normalizeBipolarAutoThreshold(targets, threshold);

	setTargetsNormalization(Normalization(Normalization::BipolarAutoThreshold, 999999999, -999999999, *threshold));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeTanh(Normalization in, Normalization tn)
{
	normalizedInputs = ANN::normalizeTanh(inputs, in.getAmplitude(), in.getElongation());
	normalizedTargets = ANN::normalizeTanh(targets, tn.getElongation(), tn.getElongation());

	setInputsNormalization(in);

	setTargetsNormalization(tn);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeTanh(double inAmp, double inElong, double tarAmp, double tarElong)
{
	normalizedInputs = ANN::normalizeTanh(inputs, inAmp, inElong);
	normalizedTargets = ANN::normalizeTanh(targets, tarAmp, tarElong);

	setInputsNormalization(Normalization(Normalization::Tanh, 999999999, -999999999, 0, inAmp, inElong));

	setTargetsNormalization(Normalization(Normalization::Tanh, 999999999, -999999999, 0, tarAmp, tarElong));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeInputsTanh(Normalization in)
{
	normalizedInputs = ANN::normalizeTanh(inputs, in.getAmplitude(), in.getElongation());

	setInputsNormalization(in);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeInputsTanh(double amp, double elong)
{
	normalizedInputs = ANN::normalizeTanh(inputs, amp, elong);

	setInputsNormalization(Normalization(Normalization::Tanh, 999999999, -999999999, 0, amp, elong));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeTargetsTanh(Normalization tn)
{
	normalizedTargets = ANN::normalizeTanh(targets, tn.getAmplitude(), tn.getElongation());

	setTargetsNormalization(tn);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeTargetsTanh(double amp, double elong)
{
	normalizedTargets = ANN::normalizeTanh(targets, amp, elong);

	setTargetsNormalization(Normalization(Normalization::Tanh, 999999999, -999999999, 0, amp, elong));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeSigmoid(Normalization in, Normalization tn)
{
	normalizedInputs = ANN::normalizeSigmoid(inputs, in.getAmplitude(), in.getElongation());
	normalizedTargets = ANN::normalizeSigmoid(targets, tn.getAmplitude(), tn.getElongation());

	setInputsNormalization(in);

	setTargetsNormalization(tn);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeSigmoid(double inAmp, double inElong, double tarAmp, double tarElong)
{
	normalizedInputs = ANN::normalizeSigmoid(inputs, inAmp, inElong);
	normalizedTargets = ANN::normalizeSigmoid(targets, tarAmp, tarElong);

	setInputsNormalization(Normalization(Normalization::Sigmoid, 999999999, -999999999, 0, inAmp, inElong));

	setTargetsNormalization(Normalization(Normalization::Sigmoid, 999999999, -999999999, 0, tarAmp, tarElong));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeInputsSigmoid(Normalization in)
{
	normalizedInputs = ANN::normalizeSigmoid(inputs, in.getAmplitude(), in.getElongation());

	setInputsNormalization(in);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeInputsSigmoid(double amp, double elong)
{
	normalizedInputs = ANN::normalizeSigmoid(inputs, amp, elong);

	setInputsNormalization(Normalization(Normalization::Sigmoid, 999999999, -999999999, 0, amp, elong));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeTargetsSigmoid(Normalization tn)
{
	normalizedTargets = ANN::normalizeSigmoid(targets, tn.getAmplitude(), tn.getElongation());

	setTargetsNormalization(tn);
}

void TrainingSet::normalizeTargetsSigmoid(double amp, double elong)
{
	normalizedTargets = ANN::normalizeSigmoid(targets, amp, elong);

	setTargetsNormalization(Normalization(Normalization::Sigmoid, 999999999, -999999999, 0, amp, elong));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeMeanDistance()
{
	normalizedInputs = ANN::normalizeMeanDistance(inputs);
	normalizedTargets = ANN::normalizeMeanDistance(targets);

	setInputsNormalization(Normalization(Normalization::MeanDistance));

	setTargetsNormalization(Normalization(Normalization::MeanDistance));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeInputsMeanDistance()
{
	normalizedInputs = ANN::normalizeMeanDistance(inputs);

	setInputsNormalization(Normalization(Normalization::MeanDistance));

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::normalizeTargetsMeanDistance()
{
	normalizedTargets = ANN::normalizeMeanDistance(targets);

	setTargetsNormalization(Normalization(Normalization::MeanDistance));

	emit dataChanged(QModelIndex(), QModelIndex());
}

TrainingSet TrainingSet::getNormalizedLinearAutoRange(double *minInputs, double *maxInputs, double *minTargets, double *maxTargets) const
{
	TrainingSet ts(*this);
	ts.normalizeLinearAutoRange(minInputs, maxInputs, minTargets, maxTargets);
	return ts;
}

TrainingSet TrainingSet::getNormalizedLinearFixedRange(double minInputs, double maxInputs, double minTargets, double maxTargets) const
{
	TrainingSet ts(*this);
	ts.normalizeLinearFixedRange(minInputs, maxInputs, minTargets, maxTargets);
	return ts;
}

vector<vector<double> > TrainingSet::getNormalizedInputsLinearFixedRange(double min, double max)
{
	TrainingSet ts(*this);
	ts.normalizeInputsLinearFixedRange(min, max);
	return ts.getInputs();
}

vector<vector<double> > TrainingSet::getNormalizedTargetsLinearFixedRange(double min, double max)
{
	TrainingSet ts(*this);
	ts.normalizeTargetsLinearFixedRange(min, max);
	return ts.getTargets();
}

vector<vector<double> > TrainingSet::getNormalizedInputsLinearAutoRange(double *min, double *max)
{
	TrainingSet ts(*this);
	ts.normalizeInputsLinearAutoRange(min, max);
	return ts.getInputs();
}

vector<vector<double> > TrainingSet::getNormalizedTargetsLinearAutoRange(double *min, double *max)
{
	TrainingSet ts(*this);
	ts.normalizeTargetsLinearAutoRange(min, max);
	return ts.getTargets();
}

void TrainingSet::normalizeInputs(Normalization in)
{
	inputsNormalization = in;
	switch(in.getType()){
		case Normalization::Nothing:
			normalizeInputsNothing();
			break;
		case Normalization::BipolarFixedThreshold:
			normalizeInputsBipolarFixedThreshold(in);
			break;
		case Normalization::BipolarAutoThreshold:
			normalizeInputsBipolarAutoThreshold(&in);
			break;
		case Normalization::UnipolarFixedThreshold:
			normalizeInputsUnipolarFixedThreshold(in);
			break;
		case Normalization::UnipolarAutoThreshold:
			normalizeInputsUnipolarAutoThreshold(&in);
			break;
		case Normalization::LinearFixedRange:
			normalizeInputsLinearFixedRange(in);
			break;
		case Normalization::LinearAutoRange:
			normalizeInputsLinearAutoRange(&in);
			break;
		case Normalization::Tanh:
			normalizeInputsTanh(in);
			break;
		case Normalization::Sigmoid:
			normalizeInputsSigmoid(in);
			break;
		case Normalization::MeanDistance:
			normalizeInputsMeanDistance();
			break;
	}
}

void TrainingSet::normalizeTargets(Normalization tn)
{
	targetsNormalization = tn;
	switch (tn.getType()) {
		case Normalization::Tanh:
			normalizeTargetsTanh(tn);
			break;
		case Normalization::Sigmoid:
			normalizedTargets = ANN::normalizeSigmoid(targets, tn.getAmplitude(), tn.getElongation());
			break;
		case Normalization::Nothing:
		case Normalization::BipolarFixedThreshold:
		case Normalization::BipolarAutoThreshold:
		case Normalization::UnipolarFixedThreshold:
		case Normalization::UnipolarAutoThreshold:
		case Normalization::LinearFixedRange:
		case Normalization::LinearAutoRange:
		case Normalization::MeanDistance:
		default:
			normalizeTargetsNothing();
			break;
	}
}

void TrainingSet::normalize(Normalization in, Normalization tn)
{
	normalizeInputs(in);
	normalizeTargets(tn);
}

TrainingSet TrainingSet::getNormalized(Normalization in, Normalization tn) const
{
	TrainingSet ts(*this);
	ts.normalize(in, tn);
	return ts;
}

vector<vector<double> > TrainingSet::getNormalizedInputs() const
{
	return normalizedInputs;
}

vector<vector<double> > TrainingSet::getNormalizedTargets() const
{
	return normalizedTargets;
}

TrainingSet TrainingSet::getNormalizedUnipolarFixedThreshold(double inThreshold, double tarThreshold) const
{
	TrainingSet ts(*this);
	ts.normalizeUnipolarFixedThreshold(inThreshold, tarThreshold);
	return ts;
}

vector<vector<double> > TrainingSet::getNormalizedInputsUnipolarFixedThreshold(double threshold) const
{
	TrainingSet ts(*this);
	ts.normalizeInputsUnipolarFixedThreshold(threshold);
	return ts.getInputs();
}

vector<vector<double> > TrainingSet::getNormalizedTargetsUnipolarFixedThreshold(double threshold) const
{
	TrainingSet ts(*this);
	ts.normalizeTargetsUnipolarFixedThreshold(threshold);
	return ts.getTargets();
}

TrainingSet TrainingSet::getNormalizedUnipolarAutoThreshold(double *inThreshold, double *tarThreshold) const
{
	TrainingSet ts(*this);
	ts.normalizeUnipolarAutoThreshold(inThreshold, tarThreshold);
	return ts;
}

vector<vector<double> > TrainingSet::getNormalizedInputsUnipolarAutoThreshold(double *threshold) const
{
	TrainingSet ts(*this);
	ts.normalizeInputsUnipolarAutoThreshold(threshold);
	return ts.getInputs();
}

vector<vector<double> > TrainingSet::getNormalizedTargetsUnipolarAutoThreshold(double *threshold) const
{
	TrainingSet ts(*this);
	ts.normalizeTargetsUnipolarAutoThreshold(threshold);
	return ts.getTargets();
}

TrainingSet TrainingSet::getNormalizedBipolarFixedThreshold(double inThreshold, double tarThreshold) const
{
	TrainingSet ts(*this);
	ts.normalizeBipolarFixedThreshold(inThreshold, tarThreshold);
	return ts;
}

vector<vector<double> > TrainingSet::getNormalizedInputsBipolarFixedThreshold(double threshold) const
{
	TrainingSet ts(*this);
	ts.normalizeInputsBipolarFixedThreshold(threshold);
	return ts.getInputs();
}

vector<vector<double> > TrainingSet::getNormalizedTargetsBipolarFixedThreshold(double threshold) const
{
	TrainingSet ts(*this);
	ts.normalizeTargetsBipolarFixedThreshold(threshold);
	return ts.getTargets();
}

TrainingSet TrainingSet::getNormalizedBipolarAutoThreshold(double *inThreshold, double *tarThreshold) const
{
	TrainingSet ts(*this);
	ts.normalizeBipolarAutoThreshold(inThreshold, tarThreshold);
	return ts;
}

vector<vector<double> > TrainingSet::getNormalizedInputsBipolarAutoThreshold(double *threshold) const
{
	TrainingSet ts(*this);
	ts.normalizeInputsBipolarAutoThreshold(threshold);
	return ts.getInputs();
}

vector<vector<double> > TrainingSet::getNormalizedTargetsBipolarAutoThreshold(double *threshold) const
{
	TrainingSet ts(*this);
	ts.normalizeTargetsBipolarAutoThreshold(threshold);
	return ts.getTargets();
}

void TrainingSet::addNoiseToInputs(double min, double max)
{
	size_t sPatterns = getPatternCount();
	vector<vector<double> > li = inputs;

	for(size_t i = 0; i < sPatterns; i++){
		inputs[i] = ANN::addNoise(inputs[i], min, max);
	}

	if(li != inputs){
		emit inputsChanged(inputs);
		emit inputsChanged(li, inputs);
	}
}

void TrainingSet::addNoiseToInputs(double a)
{
	vector<vector<double> > li = inputs;
	addNoiseToInputs(-a, a);

	if(li != inputs){
		emit inputsChanged(inputs);
		emit inputsChanged(li, inputs);
	}
}

void TrainingSet::addNoiseToTargets(double min, double max)
{
	size_t sPatterns = getPatternCount();
	vector<vector<double> > lt = targets;

	for(size_t i = 0; i < sPatterns; i++){
		targets[i] = ANN::addNoise(targets[i], min, max);
	}

	if(lt != targets){
		emit targetsChanged(targets);
		emit targetsChanged(lt, targets);
	}
}

void TrainingSet::addNoiseToTargets(double a)
{
	vector<vector<double> > lt = targets;

	addNoiseToTargets(-a, a);

	if(lt != targets){
		emit targetsChanged(targets);
		emit targetsChanged(lt, targets);
	}
}

void TrainingSet::addNoiseToAll(double min, double max)
{
	size_t sPatterns = getPatternCount();
	vector<vector<double> >
			li = inputs,
			lt = targets;

	for(size_t i = 0; i < sPatterns; i++){
		inputs[i] = ANN::addNoise(inputs[i], min, max);
		targets[i] = ANN::addNoise(targets[i], min, max);
	}

	if(li != inputs){
		emit inputsChanged(inputs);
		emit inputsChanged(li, inputs);
	}

	if(lt != targets){
		emit targetsChanged(targets);
		emit targetsChanged(lt, targets);
	}
}

void TrainingSet::addNoiseToAll(double a)
{
	vector<vector<double> >
			li = inputs,
			lt = targets;

	addNoiseToAll(-a, a);

	if(li != inputs){
		emit inputsChanged(inputs);
		emit inputsChanged(li, inputs);
	}

	if(lt != targets){
		emit targetsChanged(targets);
		emit targetsChanged(lt, targets);
	}
}

void TrainingSet::setPatternCount(int s)
{
	inputs.resize(s);
	targets.resize(s);
	patternCount = s;
}

int TrainingSet::getPatternCount() const
{
	return patternCount;
}

TrainingSet &TrainingSet::operator=(const TrainingSet &trset)
{
	//FIXME: asignar la normalizacion
	setInputs(trset.getInputs(), trset.getInputsSize());
	setTargets(trset.getTargets(), trset.getTargetsSize());

	return *this;
}

bool TrainingSet::operator==(const TrainingSet &trset)
{
	//FIXME: comparar la normalizacion
	if(trset.getInputs() == inputs && trset.getTargets() == targets){
		return true;
	}
	return false;
}

bool TrainingSet::operator!=(const TrainingSet &trset)
{
	//FIXME: comparar la normalizacion
	if(trset.getInputs() == inputs && trset.getTargets() == targets){
		return false;
	}
	return true;
}

void TrainingSet::init(const vector<vector<double> > &inputs, int is, const vector<vector<double> > &targets, int ts)
{
	vector<vector<double> >
			cinputs = inputs,
			ctargets = targets;
	if(cinputs.size() >= ctargets.size()){
		ctargets.resize(cinputs.size());
	}else{
		cinputs.resize(ctargets.size());
	}

	inputsSize = is;
	targetsSize = ts;
	patternCount = cinputs.size();

//	setRowCount(cinputs.size());
//	setColumnCount(is + ts);

	setInputs(cinputs, is);
	setTargets(ctargets, ts);

	//Establece por defecto ninguna normalizacion inicialmente
	//Se debe llamar para que se inicialice las variables normalizedInputs y normalizedTargets
	normalizeNothing();
}

void TrainingSet::resizeVectorSet(vector<vector<double> > &vec, int s, double fill)
{
	size_t sInputs = vec.size();

	for(size_t i = 0; i < sInputs; i++){
		vec[i].resize(s, fill);
	}
}

void TrainingSet::appendPattern()
{
	appendPattern(vector<double>(getInputsSize(), 0), vector<double>(getTargetsSize(), 0));
}

void TrainingSet::appendPattern(const vector<double> &inputs, const vector<double> &targets)
{
	vector<double>
			cinputs = inputs,
			ctargets = targets;

	if((int)cinputs.size() != getInputsSize()){
		cinputs.resize(getInputsSize(), 0);
	}

	this->inputs.push_back(cinputs);
	normalizedInputs.push_back(normalizedVector(cinputs, getInputsNormalization()));

	if((int)ctargets.size() != getTargetsSize()){
		ctargets.resize(getTargetsSize(), 0);
	}
	this->targets.push_back(ctargets);
	normalizedTargets.push_back(normalizedVector(ctargets, getTargetsNormalization()));

	//TODO: validar si no es necesario llamar a insertRow

	emit patternAdded(cinputs, ctargets);
}

void TrainingSet::setInputsNormalization(const Normalization &in)
{
	Normalization ln = in;
	if(inputsNormalization != in){
		inputsNormalization = in;

		emit inputsNormalizationChanged(in);
		emit inputsNormalizationChanged(ln, in);
	}
}

void TrainingSet::setTargetsNormalization(const Normalization &tn)
{
	Normalization ln = tn;
	if(targetsNormalization != tn){
		targetsNormalization = tn;

		emit inputsNormalizationChanged(tn);
		emit inputsNormalizationChanged(ln, tn);
	}
}

int TrainingSet::rowCount(const QModelIndex &parent) const
{
	(void)parent;
	return patternCount;
}

int TrainingSet::columnCount(const QModelIndex &parent) const
{
	(void)parent;
	return inputsSize + targetsSize;
}

bool TrainingSet::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if(!index.isValid() || role != Qt::EditRole){
		return false;
	}

	int
			row = index.row(),
			col = index.column();

	bool ok;

	double dblValue = value.toDouble(&ok);

	if(ok){
		if(row < rowCount() && row >= 0 && col >= 0 && col < columnCount()){
			if(col < inputsSize){
				if(inputsNormalization.getType() == Normalization::Nothing){
					inputs[row][col] = dblValue;
				}
			}else{
				if(targetsNormalization.getType() == Normalization::Nothing){
					targets[row][col - inputsSize] = dblValue;
				}
			}
		}
		return true;

		emit dataChanged(index, index);
	}
	return false;
}

QVariant TrainingSet::data(const QModelIndex &index, int role) const
{
	//Rechaza en caso de que el indice no sea valido o el rol no sea para mostrar o editar
	if(!index.isValid() || !(role == Qt::DisplayRole || role == Qt::EditRole)){
		return QVariant();
	}

	int
			row = index.row(),
			col = index.column();

	if(row < rowCount() && row >= 0 && col >= 0 && col < columnCount()){
		if(col < inputsSize){
			if(inputsNormalization.getType() != Normalization::Nothing){
				return normalizedInputs[row][col];
			}else{
				return inputs[row][col];
			}
		}else{
			if(targetsNormalization.getType() != Normalization::Nothing){
				return normalizedTargets[row][col - inputsSize];
			}else{
				return targets[row][col - inputsSize];
			}
		}
	}
	return QVariant();
}

QVariant TrainingSet::headerData(int section, Qt::Orientation orientation, int role) const
{
	if(role != Qt::DisplayRole){
		return QVariant();
	}

	if(orientation == Qt::Horizontal){
		if(section >= 0 && section < inputsSize + targetsSize){
			if(section < inputsSize){
				return "in[" + QString::number(section) + "]";
			}else{
				return "out[" + QString::number(section - inputsSize) + "]";
			}
		}
	}else{
		if(section >= 0 && section < patternCount){
			return "p[" + QString::number(section) + "]";
		}
	}
	return QVariant();
}

Qt::ItemFlags TrainingSet::flags(const QModelIndex &index) const
{
	//Rechaza en caso de que el indice no sea valido o el rol no sea para mostrar o editar
	if(!index.isValid()){
		return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
	}

	int
			row = index.row(),
			col = index.column();

	if(row < rowCount() && row >= 0 && col >= 0 && col < columnCount()){
		if(col < inputsSize){
			if(inputsNormalization.getType() == Normalization::Nothing){
				return Qt::ItemIsEnabled |Qt::ItemIsSelectable | Qt::ItemIsEditable;
			}else{
				return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
			}
		}else{
			if(targetsNormalization.getType() == Normalization::Nothing){
				return Qt::ItemIsEnabled |Qt::ItemIsSelectable | Qt::ItemIsEditable;
			}else{
				return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
			}
		}
	}
	return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

void TrainingSet::setTarget(int pattern, int index, double value)
{
	double prevVal = targets[pattern][index];
	if(prevVal != value){
		targets[pattern][index] = value;

		emit targetChanged(pattern, index, value);
		emit targetChanged(pattern, index, prevVal, value);
	}
}

double TrainingSet::getInput(int pat, int index) const
{
	//TODO: validar pat e index
	return inputs[pat][index];
}

double TrainingSet::getTarget(int pat, int index) const
{
	//TODO: validar pat e index
	return targets[pat][index];
}

void TrainingSet::setPattern(int index, const vector<double> &inputs, const vector<double> &targets)
{
	vector<double>
			prevInputs = this->inputs[index],
			prevTargets = this->targets[index];
	if(prevInputs != inputs || prevTargets != targets){
		this->inputs[index] = inputs;
		this->targets[index] = targets;

		emit patternChanged(index, inputs, targets);
		emit patternChanged(index, prevInputs, inputs, prevTargets, targets);
	}
}

pair<vector<double>, vector<double> > TrainingSet::getPattern(int index) const
{
	return pair<vector<double>, vector<double> >(inputs[index], targets[index]);
}

void TrainingSet::setInput(int pat, int index, double value)
{
	double prevVal = inputs[pat][index];
	if(prevVal != value){
		inputs[pat][index] = value;

		emit inputChanged(pat, index, value);
		emit inputChanged(pat, index, prevVal, value);
	}
}

TrainingSet TrainingSet::getNormalizedTanh(double inAmp, double inElong, double tarAmp, double tarElong)
{
	TrainingSet ts(*this);
	ts.normalizeTanh(inAmp, inElong, tarAmp, tarElong);
	return ts;
}

vector<vector<double> > TrainingSet::getNormalizedInputsTanh(double amp, double elong)
{
	TrainingSet ts(*this);
	ts.normalizeInputsTanh(amp, elong);
	return ts.getInputs();
}

vector<vector<double> > TrainingSet::getNormalizedTargetsTanh(double amp, double elong)
{
	TrainingSet ts(*this);
	ts.normalizeTargetsTanh(amp, elong);
	return ts.getTargets();
}

TrainingSet TrainingSet::getNormalizedSigmoid(double inAmp, double inElong, double tarAmp, double tarElong)
{
	TrainingSet ts(*this);
	ts.normalizeSigmoid(inAmp, inElong, tarAmp, tarElong);
	return ts;
}

vector<vector<double> > TrainingSet::getNormalizedInputsSigmoid(double amp, double elong)
{
	TrainingSet ts(*this);
	ts.normalizeSigmoid(amp, elong);
	return ts.getInputs();
}

vector<vector<double> > TrainingSet::getNormalizedTargetsSigmoid(double amp, double elong)
{
	TrainingSet ts(*this);
	ts.normalizeSigmoid(amp, elong);
	return ts.getTargets();
}

TrainingSet TrainingSet::getNormalizedMeanDistance()
{
	TrainingSet ts(*this);
	ts.normalizeMeanDistance();
	return ts;
}

vector<vector<double> > TrainingSet::getNormalizedInputsMeanDistance()
{
	TrainingSet ts(*this);
	ts.normalizeMeanDistance();
	return ts.getInputs();
}

vector<vector<double> > TrainingSet::getNormalizedTargetsMeanDistance()
{
	TrainingSet ts(*this);
	ts.normalizeMeanDistance();
	return ts.getTargets();
}

vector<double> TrainingSet::normalizedVector(const vector<double> &vec, const Normalization &nor)
{
	double tmp1, tmp2;
	switch(nor.getType()){
		case Normalization::BipolarFixedThreshold:
			return ANN::normalizeBipolarFixedThreshold(vec, nor.getThreshold());
		case Normalization::BipolarAutoThreshold:
			return ANN::normalizeBipolarAutoThreshold(vec, &tmp1);
		case Normalization::UnipolarFixedThreshold:
			return ANN::normalizeUnipolarFixedThreshold(vec, nor.getThreshold());
		case Normalization::UnipolarAutoThreshold:
			return ANN::normalizeUnipolarAutoThreshold(vec, &tmp1);
		case Normalization::LinearFixedRange:
			return ANN::normalizeLinearFixedRange(vec, nor.getMinValue(), nor.getMaxValue());
		case Normalization::LinearAutoRange:
			return ANN::normalizeLinearAutoRange(vec, &tmp1, &tmp2);
		case Normalization::Tanh:
			return ANN::normalizeTanh(vec);
		case Normalization::Sigmoid:
			return ANN::normalizeSigmoid(vec);
		case Normalization::MeanDistance:
			return ANN::normalizeMeanDistance(vec);
		case Normalization::Nothing:
		default:
			return vec;
	}
}
