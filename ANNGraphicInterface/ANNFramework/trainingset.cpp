#include "trainingset.h"

TrainingSet::TrainingSet(QObject *parent) :
	QObject(parent)
{
	initTS(vector<vector<double> > (1, vector<double>(1, 0)), vector<vector<double> >(1, vector<double>(1, 0)));
}

TrainingSet::TrainingSet(int inputsize, double targetsize, int n, QObject *parent) :
	QObject(parent)
{
	initTS(vector<vector<double> > (n, vector<double>(inputsize, 0)), vector<vector<double> >(n, vector<double>(targetsize, 0)));
}

TrainingSet::TrainingSet(const vector<vector<double> > &inputs, const vector<vector<double> > &targets, QObject *parent) :
	QObject(parent)
{
	initTS(inputs, targets);
}

TrainingSet::TrainingSet(double **inputs,
						 unsigned int sinputs,
						 double **targets,
						 unsigned int stargets,
						 unsigned int spatterns, QObject *parent) :
	QObject(parent)
{
	vector<vector<double> >
			tinputs(spatterns),
			ttargets(spatterns);

	for(unsigned int i = 0; i < spatterns; i++){
		tinputs[i] = vector<double>(inputs[i], inputs[i] + sinputs);
		ttargets[i] = vector<double>(targets[i], targets[i] + stargets);
	}
	initTS(tinputs, ttargets);
}

TrainingSet::TrainingSet(const TrainingSet &ts, QObject *parent) :
	QObject(parent)
{
	initTS(ts.getInputs(), ts.getTargets());
}

TrainingSet::~TrainingSet()
{
	inputs.clear();
	targets.clear();
}

void TrainingSet::setInputSize(int is, double fill)
{
	int ls = getInputSize();
	resizeVectorSet(inputs, is, fill);
//	inputSize = is;

	//Si realmente hubo un cambio en el tamaño de las entradas
	if(is != ls){
		emit inputSizeChanged(is);
		emit inputSizeChanged(ls, is);
	}
}

int TrainingSet::getInputSize() const
{
	return inputs[0].size();
}

void TrainingSet::setTargetSize(int ts, double fill)
{
	int ls = getTargetSize();
	resizeVectorSet(targets, ts, fill);
//	targetSize = ts;

	//Si realmente cambio el tamaño del patron de salidas
	if(ls != ts){
		emit targetSizeChanged(ts);
		emit targetSizeChanged(ls, ts);
	}
}

int TrainingSet::getTargetSize() const
{
	return targets[0].size();
}

void TrainingSet::insertPattern(const vector<double> &inputs, const vector<double> &targets, int i)
{
	vector<vector<double> >::iterator it;

	it = this->inputs.begin();
	this->inputs.insert(it + i, inputs);

	it = this->targets.begin();
	this->targets.insert(it + i, targets);

	emit patternInserted(inputs, targets, i);
}

void TrainingSet::insertPattern(const vector<int> &inputs, const vector<int> &targets, int i)
{
	vector<vector<double> >::iterator it;

	it = this->inputs.begin();
	this->inputs.insert(it + i, vector<double>(inputs.begin(), inputs.end()));

	it = this->targets.begin();
	this->targets.insert(it + i, vector<double>(targets.begin(), targets.end()));

	emit patternInserted(inputs, targets, i);
}

void TrainingSet::deletePattern(int i)
{
	if(i >= 0){
		vector<vector<double> >::iterator it;
		vector<vector<double> >::iterator inputPattern, targetPattern;

		it = inputs.begin();
		inputPattern = inputs.erase(it + i);

		it = targets.begin();
		targetPattern = targets.erase(it + i);

		emit patternDeleted(*inputPattern, *targetPattern, i);
	}
}

void TrainingSet::setInputs(const vector<vector<double> > &inputs)
{
	vector<vector<double> > li = this->inputs;
//	const vector<double> *dInput = inputs.data();
//	inputSize = dInput->size();
	this->inputs = inputs;

	if(li != inputs){
		emit inputsChanged(li, inputs);
	}
}

void TrainingSet::setInputs(const vector<vector<int> > &inputs)
{
	vector<vector<int> > li = ANNFrameworkFunctions::toInt(this->inputs);
//	const vector<int> *dInput = inputs.data();
//	inputSize = dInput->size();
	this->inputs = ANNFrameworkFunctions::toDouble(inputs);

	if(li != inputs){
		emit inputsChanged(inputs);
		emit inputsChanged(li, inputs);
	}
}

void TrainingSet::setTargets(const vector<vector<double> > &targets)
{
	vector<vector<double> > lt = this->targets;
//	const vector<double> *dTarget = targets.data();
//	targetSize = dTarget->size();
	this->targets = targets;

	if(lt != targets){
		emit targetsChanged(targets);
		emit targetsChanged(lt, targets);
	}
}

void TrainingSet::setTargets(const vector<vector<int> > &targets)
{
	vector<vector<int> > lt = ANNFrameworkFunctions::toInt(this->targets);
//	const vector<int> *dTarget = targets.data();
//	targetSize = dTarget->size();
	this->targets = ANNFrameworkFunctions::toDouble(targets);

	if(lt != targets){
		emit targetsChanged(targets);
		emit targetsChanged(lt, targets);
	}
}

vector<vector<double> > TrainingSet::getInputs() const
{
	return inputs;
}

vector<vector<double> > TrainingSet::getTargets() const
{
	return targets;
}

void TrainingSet::normalizeLinearFixedRange(double minInputs, double maxInputs, double minTargets, double maxTargets)
{
	inputs = ANNFrameworkFunctions::normalizeLinearFixedRange(inputs, minInputs, maxInputs);
	targets = ANNFrameworkFunctions::normalizeLinearFixedRange(targets, minTargets, maxTargets);

	inputsNorm.setNormalization(Normalization::LinearFixedRange);
	inputsNorm.setMinValue(minInputs);
	inputsNorm.setMaxValue(maxInputs);
	inputsNorType = LinearFixedRange;

	targetsNorm.setNormalization(Normalization::LinearFixedRange);
	targetsNorm.setMinValue(minTargets);
	targetsNorm.setMaxValue(maxTargets);
	targetsNorType = LinearFixedRange;
}

void TrainingSet::normalizeInputsLinearFixedRange(double min, double max)
{
	inputs = ANNFrameworkFunctions::normalizeLinearFixedRange(inputs, min, max);

	inputsNorm.setNormalization(Normalization::LinearFixedRange);
	inputsNorm.setMinValue(min);
	inputsNorm.setMaxValue(max);
	inputsNorType = LinearFixedRange;
}

void TrainingSet::normalizeTargetsLinearFixedRange(double min, double max)
{
	targets = ANNFrameworkFunctions::normalizeLinearFixedRange(targets, min, max);

	targetsNorm.setNormalization(Normalization::LinearFixedRange);
	targetsNorm.setMinValue(min);
	targetsNorm.setMaxValue(max);
	targetsNorType = LinearFixedRange;
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

void TrainingSet::normalizeLinearAutoRange(double *minInputs, double *maxInputs, double *minTargets, double *maxTargets)
{
	inputs = ANNFrameworkFunctions::normalizeLinearAutoRange(inputs, minInputs, maxInputs);
	targets = ANNFrameworkFunctions::normalizeLinearAutoRange(targets, minTargets, maxTargets);

	inputsNorm.setNormalization(Normalization::LinearAutoRange);
	inputsNorm.setMinValue(*minInputs);
	inputsNorm.setMaxValue(*maxInputs);
	inputsNorType = LinearAutoRange;

	targetsNorm.setNormalization(Normalization::LinearAutoRange);
	targetsNorm.setMinValue(*minTargets);
	targetsNorm.setMaxValue(*maxTargets);
	targetsNorType = LinearAutoRange;
}

void TrainingSet::normalizeInputsLinearAutoRange(double *min, double *max)
{
	inputs = ANNFrameworkFunctions::normalizeLinearAutoRange(inputs, min, max);

	inputsNorm.setNormalization(Normalization::LinearAutoRange);
	inputsNorm.setMinValue(*min);
	inputsNorm.setMaxValue(*max);
	inputsNorType = LinearAutoRange;
}

void TrainingSet::normalizeTargetsLinearAutoRange(double *min, double *max)
{
	targets = ANNFrameworkFunctions::normalizeLinearAutoRange(targets, min, max);

	targetsNorm.setNormalization(Normalization::LinearAutoRange);
	targetsNorm.setMinValue(*min);
	targetsNorm.setMaxValue(*max);
	targetsNorType = LinearAutoRange;
}

TrainingSet TrainingSet::getNormalizedLinearAutoRange(double *minInputs, double *maxInputs, double *minTargets, double *maxTargets) const
{
	TrainingSet ts(*this);
	ts.normalizeLinearAutoRange(minInputs, maxInputs, minTargets, maxTargets);
	return ts;
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

void TrainingSet::normalize(NormalizationType no)
{
	size_t sPatterns = getPatternCount();
	size_t sInputs = getInputSize();
	size_t sTargets = getTargetSize();
	double mean;
	double stddv;
	double nor;
	vector<vector<double> >
			li = inputs,
			lt = targets;

	for(size_t p = 0; p < sPatterns; p++){
		mean = ANNFrameworkFunctions::getMean(inputs[p]);
		stddv = ANNFrameworkFunctions::getStandardDeviation(inputs[p]);
		for(size_t i = 0; i < sInputs; i++){
			nor = (inputs[p][i] - mean)/stddv;
			switch(no){
				case ITrainingSet::BipolarAutoThreshold:
					break;
				case ITrainingSet::UnipolarAutoThreshold:
					break;
				case ITrainingSet::Nothing:
					break;
				case ITrainingSet::BipolarFixedThreshold:
					break;
				case ITrainingSet::UnipolarFixedThreshold:
					break;
				case ITrainingSet::LinearFixedRange:
					break;
				case ITrainingSet::LinearAutoRange:
					break;
				case ITrainingSet::Sigmoid:
					//NOTE: no estoy seguro de que esto sea asi
					inputs[p][i] = 1/(1 + exp(-nor));
					break;
				case ITrainingSet::Tanh:
					inputs[p][i] = (1 - exp(-nor))/(1 + exp(-nor));
					break;
				case ITrainingSet::MeanDistance:
					break;
			}

		}
		mean = ANNFrameworkFunctions::getMean(targets[p]);
		stddv = ANNFrameworkFunctions::getStandardDeviation(targets[p]);
		for(size_t t = 0; t < sTargets; t++){
			nor = (targets[p][t] - mean)/stddv;
			switch(no){
				case ITrainingSet::BipolarAutoThreshold:
					break;
				case ITrainingSet::UnipolarAutoThreshold:
					break;
				case ITrainingSet::Nothing:
					break;
				case ITrainingSet::BipolarFixedThreshold:
					break;
				case ITrainingSet::UnipolarFixedThreshold:
					break;
				case ITrainingSet::LinearFixedRange:
					break;
				case ITrainingSet::LinearAutoRange:
					break;
				case ITrainingSet::Sigmoid:
					//NOTE: no estoy seguro de que esto sea asi
					targets[p][t] = 1/(1 + exp(-nor));
					break;
				case ITrainingSet::Tanh:
					targets[p][t] = (1 - exp(-nor))/(1 + exp(-nor));
					break;
				case ITrainingSet::MeanDistance:
					break;
			}
		}
	}
	inputsNorType = no;
	targetsNorType = no;

	if(li != inputs){
		emit inputsChanged(inputs);
		emit inputsChanged(li, inputs);
	}

	if(lt != targets){
		emit targetsChanged(targets);
		emit targetsChanged(lt, targets);
	}
}

TrainingSet TrainingSet::getNormalized(NormalizationType nt) const
{
	TrainingSet ts(*this);
	ts.normalize(nt);
	return ts;
}

void TrainingSet::normalizeUnipolarFixedThreshold(double inThreshold, double tarThreshold)
{
	inputs = ANNFrameworkFunctions::normalizeUnipolarFixedThreshold(inputs, inThreshold);
	targets = ANNFrameworkFunctions::normalizeUnipolarFixedThreshold(targets, tarThreshold);

	inputsNorm.setNormalization(Normalization::UnipolarFixedThreshold);
	inputsNorm.setThreshold(inThreshold);
	inputsNorType = UnipolarFixedThreshold;

	targetsNorm.setNormalization(Normalization::UnipolarFixedThreshold);
	targetsNorm.setThreshold(tarThreshold);
	targetsNorType = UnipolarFixedThreshold;
}

void TrainingSet::normalizeInputsUnipolarFixedThreshold(double threshold)
{
	inputs = ANNFrameworkFunctions::normalizeUnipolarFixedThreshold(inputs, threshold);

	inputsNorm.setNormalization(Normalization::UnipolarFixedThreshold);
	inputsNorm.setThreshold(threshold);
	inputsNorType = UnipolarFixedThreshold;
}

void TrainingSet::normalizeTargetsUnipolarFixedThreshold(double threshold)
{
	targets = ANNFrameworkFunctions::normalizeUnipolarFixedThreshold(targets, threshold);

	targetsNorm.setNormalization(Normalization::UnipolarFixedThreshold);
	targetsNorm.setThreshold(threshold);
	targetsNorType = UnipolarFixedThreshold;
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

void TrainingSet::normalizeUnipolarAutoThreshold(double *inThreshold, double *tarThreshold)
{
	inputs = ANNFrameworkFunctions::normalizeUnipolarAutoThreshold(inputs, inThreshold);
	targets = ANNFrameworkFunctions::normalizeUnipolarAutoThreshold(targets, tarThreshold);

	inputsNorm.setNormalization(Normalization::UnipolarAutoThreshold);
	inputsNorm.setThreshold(*inThreshold);
	inputsNorType = UnipolarAutoThreshold;

	targetsNorm.setNormalization(Normalization::UnipolarAutoThreshold);
	targetsNorm.setThreshold(*tarThreshold);
	targetsNorType = UnipolarAutoThreshold;
}

void TrainingSet::normalizeInputsUnipolarAutoThreshold(double *threshold)
{
	inputs = ANNFrameworkFunctions::normalizeUnipolarAutoThreshold(inputs, threshold);

	inputsNorm.setNormalization(Normalization::UnipolarAutoThreshold);
	inputsNorm.setThreshold(*threshold);
	inputsNorType = UnipolarAutoThreshold;
}

void TrainingSet::normalizeTargetsUnipolarAutoThreshold(double *threshold)
{
	targets = ANNFrameworkFunctions::normalizeUnipolarAutoThreshold(targets, threshold);

	targetsNorm.setNormalization(Normalization::UnipolarAutoThreshold);
	targetsNorm.setThreshold(*threshold);
	targetsNorType = UnipolarAutoThreshold;
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

void TrainingSet::normalizeBipolarFixedThreshold(double inThreshold, double tarThreshold)
{
	inputs = ANNFrameworkFunctions::normalizeBipolarFixedThreshold(inputs, inThreshold);
	targets = ANNFrameworkFunctions::normalizeBipolarFixedThreshold(targets, tarThreshold);

	inputsNorm.setNormalization(Normalization::BipolarFixedThreshold);
	inputsNorm.setThreshold(inThreshold);
	inputsNorType = BipolarFixedThreshold;

	targetsNorm.setNormalization(Normalization::BipolarFixedThreshold);
	targetsNorm.setThreshold(tarThreshold);
	targetsNorType = BipolarFixedThreshold;
}

void TrainingSet::normalizeInputsBipolarFixedThreshold(double threshold)
{
	inputs = ANNFrameworkFunctions::normalizeBipolarFixedThreshold(inputs, threshold);

	inputsNorm.setNormalization(Normalization::BipolarFixedThreshold);
	inputsNorm.setThreshold(threshold);
	inputsNorType = BipolarFixedThreshold;
}

void TrainingSet::normalizeTargetsBipolarFixedThreshold(double threshold)
{
	targets = ANNFrameworkFunctions::normalizeBipolarFixedThreshold(targets, threshold);
	targetsNorm.setNormalization(Normalization::BipolarFixedThreshold);
	targetsNorm.setThreshold(threshold);
	targetsNorType = BipolarFixedThreshold;
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

void TrainingSet::normalizeBipolarAutoThreshold(double *inThreshold, double *tarThreshold)
{
	inputs = ANNFrameworkFunctions::normalizeBipolarAutoThreshold(inputs, inThreshold);
	targets = ANNFrameworkFunctions::normalizeBipolarAutoThreshold(targets, tarThreshold);
	inputsNorType = BipolarAutoThreshold;
	targetsNorType = BipolarAutoThreshold;
	inputsNorm.setNormalization(Normalization::BipolarAutoThreshold);
	inputsNorm.setThreshold(*inThreshold);
	targetsNorm.setNormalization(Normalization::BipolarAutoThreshold);
	targetsNorm.setThreshold(*tarThreshold);
}

void TrainingSet::normalizeInputsBipolarAutoThreshold(double *threshold)
{
	inputs = ANNFrameworkFunctions::normalizeBipolarAutoThreshold(inputs, threshold);
	inputsNorType = BipolarAutoThreshold;
	inputsNorm.setNormalization(Normalization::BipolarAutoThreshold);
	inputsNorm.setThreshold(*threshold);
}

void TrainingSet::normalizeTargetsBipolarAutoThreshold(double *threshold)
{
	targets = ANNFrameworkFunctions::normalizeBipolarAutoThreshold(targets, threshold);
	targetsNorType = BipolarAutoThreshold;
	targetsNorm.setNormalization(Normalization::BipolarAutoThreshold);
	targetsNorm.setThreshold(*threshold);
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
		inputs[i] = ANNFrameworkFunctions::addNoise(inputs[i], min, max);
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
		targets[i] = ANNFrameworkFunctions::addNoise(targets[i], min, max);
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
		inputs[i] = ANNFrameworkFunctions::addNoise(inputs[i], min, max);
		targets[i] = ANNFrameworkFunctions::addNoise(targets[i], min, max);
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
}

int TrainingSet::getPatternCount() const
{
	return inputs.size();
}

TrainingSet &TrainingSet::operator=(const TrainingSet &trset)
{
	setInputs(trset.getInputs());
	setTargets(trset.getTargets());

	return *this;
}

bool TrainingSet::operator==(const TrainingSet &trset)
{
	if(trset.getInputs() == inputs && trset.getTargets() == targets){
		return true;
	}
	return false;
}

bool TrainingSet::operator!=(const TrainingSet &trset)
{
	if(trset.getInputs() == inputs && trset.getTargets() == targets){
		return false;
	}
	return true;
}

void TrainingSet::initTS(const vector<vector<double> > &inputs, const vector<vector<double> > &targets)
{
	setInputs(inputs);
	setTargets(targets);

//	originalTS = new TrainingSet(*this);
}

void TrainingSet::resizeVectorSet(vector<vector<double> > &vec, int s, double fill)
{
	size_t sInputs = vec.size();

	for(size_t i = 0; i < sInputs; i++){
		vec[i].resize(s, fill);
	}
}

void TrainingSet::appendPattern(const vector<double> &inputs, const vector<double> &targets)
{
	switch(inputsNorType){
		case ITrainingSet::BipolarFixedThreshold:
			this->inputs.push_back(ANNFrameworkFunctions::normalizeBipolarFixedThreshold(inputs, inputsNorm.getThreshold()));
			break;
		case ITrainingSet::BipolarAutoThreshold:
			this->inputs.push_back(ANNFrameworkFunctions::normalizeBipolarAutoThreshold(inputs, NULL));
			break;
		case ITrainingSet::UnipolarFixedThreshold:
			this->inputs.push_back(ANNFrameworkFunctions::normalizeUnipolarFixedThreshold(inputs, inputsNorm.getThreshold()));
			break;
		case ITrainingSet::UnipolarAutoThreshold:
			this->inputs.push_back(ANNFrameworkFunctions::normalizeUnipolarAutoThreshold(inputs, NULL));
			break;
		case ITrainingSet::LinearFixedRange:
			this->inputs.push_back(ANNFrameworkFunctions::normalizeLinearFixedRange(inputs, inputsNorm.getMinValue(), inputsNorm.getMaxValue()));
			break;
		case ITrainingSet::LinearAutoRange:
			this->inputs.push_back(ANNFrameworkFunctions::normalizeLinearAutoRange(inputs, NULL, NULL));
			break;
		case ITrainingSet::Tanh:
			this->inputs.push_back(ANNFrameworkFunctions::normalizeTanh(inputs));
			break;
		case ITrainingSet::Sigmoid:
			this->inputs.push_back(ANNFrameworkFunctions::normalizeSigmoid(inputs));
			break;
		case ITrainingSet::Nothing:
		default:
			this->inputs.push_back(inputs);
			break;
	}

	switch(targetsNorType){
		case ITrainingSet::BipolarFixedThreshold:
			this->targets.push_back(ANNFrameworkFunctions::normalizeBipolarFixedThreshold(targets, targetsNorm.getThreshold()));
			break;
		case ITrainingSet::BipolarAutoThreshold:
			this->targets.push_back(ANNFrameworkFunctions::normalizeBipolarAutoThreshold(targets, NULL));
			break;
		case ITrainingSet::UnipolarFixedThreshold:
			this->targets.push_back(ANNFrameworkFunctions::normalizeUnipolarFixedThreshold(targets, targetsNorm.getThreshold()));
			break;
		case ITrainingSet::UnipolarAutoThreshold:
			this->targets.push_back(ANNFrameworkFunctions::normalizeUnipolarAutoThreshold(targets, NULL));
			break;
		case ITrainingSet::LinearFixedRange:
			this->targets.push_back(ANNFrameworkFunctions::normalizeLinearFixedRange(targets, targetsNorm.getMinValue(), targetsNorm.getMaxValue()));
			break;
		case ITrainingSet::LinearAutoRange:
			this->targets.push_back(ANNFrameworkFunctions::normalizeLinearAutoRange(targets, NULL, NULL));
			break;
		case ITrainingSet::Tanh:
			this->targets.push_back(ANNFrameworkFunctions::normalizeTanh(targets));
			break;
		case ITrainingSet::Sigmoid:
			this->targets.push_back(ANNFrameworkFunctions::normalizeSigmoid(targets));
			break;

		case ITrainingSet::Nothing:
		default:
			this->targets.push_back(targets);
			break;
	}


	emit patternAdded(inputs, targets);
}

void TrainingSet::save(const QString &file)
{
	//TODO:
	(void)file;
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
	return inputs[pat][index];
}

double TrainingSet::getTarget(int pat, int index) const
{
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

void TrainingSet::normalizeTanh(double inAmp, double inElong, double tarAmp, double tarElong)
{
	inputs = ANNFrameworkFunctions::normalizeTanh(inputs, inAmp, inElong);
	inputsNorm.setNormalization(Normalization::Tanh);
	inputsNorType = Tanh;

	targets = ANNFrameworkFunctions::normalizeTanh(targets, tarAmp, tarElong);
	targetsNorm.setNormalization(Normalization::Tanh);
	targetsNorType = Tanh;
}

void TrainingSet::normalizeInputsTanh(double amp, double elong)
{
	inputs = ANNFrameworkFunctions::normalizeTanh(inputs, amp, elong);
	inputsNorm.setNormalization(Normalization::Tanh);
	inputsNorType = Tanh;
}

void TrainingSet::normalizeTargetsTanh(double amp, double elong)
{
	targets = ANNFrameworkFunctions::normalizeTanh(targets, amp, elong);
	targetsNorm.setNormalization(Normalization::Tanh);
	targetsNorType = Tanh;
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

void TrainingSet::normalizeSigmoid(double inAmp, double inElong, double tarAmp, double tarElong)
{
	inputs = ANNFrameworkFunctions::normalizeSigmoid(inputs, inAmp, inElong);
	targets = ANNFrameworkFunctions::normalizeSigmoid(targets, tarAmp, tarElong);

	inputsNorm.setNormalization(Normalization::Sigmoid);
	inputsNorType = Sigmoid;

	targetsNorm.setNormalization(Normalization::Sigmoid);
	targetsNorType = Sigmoid;
}

void TrainingSet::normalizeInputsSigmoid(double amp, double elong)
{
	inputs = ANNFrameworkFunctions::normalizeSigmoid(inputs, amp, elong);

	inputsNorm.setNormalization(Normalization::Sigmoid);
	inputsNorType = Sigmoid;
}

void TrainingSet::normalizeTargetsSigmoid(double amp, double elong)
{
	targets = ANNFrameworkFunctions::normalizeSigmoid(targets, amp, elong);

	targetsNorm.setNormalization(Normalization::Sigmoid);
	targetsNorType = Sigmoid;
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

void TrainingSet::normalizeMeanDistance()
{
	inputs = ANNFrameworkFunctions::normalizeMeanDistance(inputs);
	targets = ANNFrameworkFunctions::normalizeMeanDistance(targets);

	inputsNorm.setNormalization(Normalization::MeanDistance);
	inputsNorType = MeanDistance;

	targetsNorm.setNormalization(Normalization::MeanDistance);
	targetsNorType = MeanDistance;
}

void TrainingSet::normalizeInputsMeanDistance()
{
	inputs = ANNFrameworkFunctions::normalizeMeanDistance(inputs);

	inputsNorm.setNormalization(Normalization::MeanDistance);
	inputsNorType = MeanDistance;
}

void TrainingSet::normalizeTargetsMeanDistance()
{
	targets = ANNFrameworkFunctions::normalizeMeanDistance(targets);

	targetsNorm.setNormalization(Normalization::MeanDistance);
	targetsNorType = MeanDistance;
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
