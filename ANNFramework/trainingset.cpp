#include "trainingset.h"

TrainingSet::TrainingSet()
{
	setPatternCount(1);
	setInputSize(1);
	setTargetSize(1);
}

TrainingSet::TrainingSet(int inputsize, double targetsize, int n)
{
	setPatternCount(n);
	setInputSize(inputsize);
	setTargetSize(targetsize);
}

TrainingSet::TrainingSet(const vector<vector<double> > &inputs, const vector<vector<double> > &targets)
{
	initTS(inputs, targets);
}

TrainingSet::TrainingSet(double **inputs,
						 unsigned int sinputs,
						 double **targets,
						 unsigned int stargets,
						 unsigned int spatterns)
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

TrainingSet::~TrainingSet()
{
	inputs.clear();
	targets.clear();
}

void TrainingSet::setInputSize(int is)
{
	setInputSize(is, 0);
}

void TrainingSet::setInputSize(int is, double fill)
{
	resizeVectorSet(inputs, is, fill);
}

int TrainingSet::getInputSize()
{
	return inputs[0].size();
}

void TrainingSet::setTargetSize(int ts)
{
	setTargetSize(ts, 0);
}

void TrainingSet::setTargetSize(int ts, double fill)
{
	resizeVectorSet(targets, ts, fill);
}

int TrainingSet::getTargetSize() const
{
	return targets[0].size();
}

void TrainingSet::insertTrainingPattern(const vector<double> &inputs, const vector<double> &targets, int i)
{
	vector<vector<double> >::iterator it;

	it = this->inputs.begin();
	this->inputs.insert(it + i, inputs);

	it = this->targets.begin();
	this->targets.insert(it + i, targets);
}

void TrainingSet::insertTrainingPattern(const vector<int> &inputs, const vector<int> &targets, int i)
{
	vector<vector<double> >::iterator it;

	it = this->inputs.begin();
	this->inputs.insert(it + i, vector<double>(inputs.begin(), inputs.end()));

	it = this->targets.begin();
	this->targets.insert(it + i, vector<double>(targets.begin(), targets.end()));
}

void TrainingSet::deleteTrainingPattern(int i)
{
	vector<vector<double> >::iterator it;

	it = inputs.begin();
	inputs.erase(it + i);

	it = targets.begin();
	targets.erase(it + i);
}

void TrainingSet::setInputs(const vector<vector<double> > &inputs)
{
	this->inputs = inputs;
}

void TrainingSet::setInputs(const vector<vector<int> > &inputs)
{
	this->inputs = toDouble(inputs);
}

void TrainingSet::setTargets(const vector<vector<double> > &targets)
{
	this->targets = targets;
}

void TrainingSet::setTargets(const vector<vector<int> > &targets)
{
	this->targets = toDouble(targets);
}

vector<vector<double> > TrainingSet::getInputs() const
{
	return inputs;
}

vector<vector<double> > TrainingSet::getTargets() const
{
	return targets;
}

void TrainingSet::normalize(double min, double max)
{
	size_t sPatterns = getPatternCount();
	size_t sInputs = getInputSize();
	size_t sTargets = getTargetSize();
	double mean;
	double stddv;
	for(size_t i = 0; i < sPatterns; i++){
		mean = getAverage(inputs[i]);
		stddv = getStandardDeviation(inputs[i]);
		for(size_t j = 0; j < sInputs; j++){
			inputs[i][j] = (inputs[i][j] - min)/(max - min);

		}
		mean = getAverage(targets[i]);
		stddv = getStandardDeviation(targets[i]);
		for(size_t j = 0; j < sTargets; j++){
			targets[i][j] = (targets[i][j] - min)/(max - min);
		}
	}
}

void TrainingSet::normalize(NormalizeOption no)
{
	size_t sPatterns = getPatternCount();
	size_t sInputs = getInputSize();
	size_t sTargets = getTargetSize();
	double mean;
	double stddv;
	double nor;
	for(size_t i = 0; i < sPatterns; i++){
		mean = getAverage(inputs[i]);
		stddv = getStandardDeviation(inputs[i]);
		for(size_t j = 0; j < sInputs; j++){
			nor = (inputs[i][j] - mean)/stddv;
			switch(no){
				case Standart:
					inputs[i][j] = nor;
					break;
				case Sigmoid:
					//CHECKME: no estoy seguro de que esto sea asi
					inputs[i][j] = 1/(1 + exp(-nor));
					break;
				case Tanh:
					inputs[i][j] = (1 - exp(-nor))/(1 + exp(-nor));
					break;
			}

		}
		mean = getAverage(targets[i]);
		stddv = getStandardDeviation(targets[i]);
		for(size_t j = 0; j < sTargets; j++){
			nor = (targets[i][j] - mean)/stddv;
			switch(no){
				case Standart:
					targets[i][j] = nor;
					break;
				case Sigmoid:
					//CHECKME: no estoy seguro de que esto sea asi
					targets[i][j] = 1/(1 + exp(-nor));
					break;
				case Tanh:
					targets[i][j] = (1 - exp(-nor))/(1 + exp(-nor));
					break;
			}
		}
	}
}

void TrainingSet::addNoiseToInputs(double min, double max)
{
	size_t sPatterns = getPatternCount();

	for(size_t i = 0; i < sPatterns; i++){
		inputs[i] = addNoise(inputs[i], min, max);
	}
}

void TrainingSet::addNoiseToInputs(double a)
{
	addNoiseToInputs(-a, a);
}

void TrainingSet::addNoiseToTargets(double min, double max)
{
	size_t sPatterns = getPatternCount();

	for(size_t i = 0; i < sPatterns; i++){
		targets[i] = addNoise(targets[i], min, max);
	}
}

void TrainingSet::addNoiseToTargets(double a)
{
	addNoiseToTargets(-a, a);
}

void TrainingSet::addNoiseToAll(double min, double max)
{
	size_t sPatterns = getPatternCount();

	for(size_t i = 0; i < sPatterns; i++){
		inputs[i] = addNoise(inputs[i], min, max);
		targets[i] = addNoise(targets[i], min, max);
	}
}

void TrainingSet::addNoiseToAll(double a)
{
	addNoiseToAll(-a, a);
}

void TrainingSet::appendPattern(const vector<double> &inputs, const vector<double> &targets)
{
	this->inputs.push_back(inputs);
	this->targets.push_back(targets);
}

void TrainingSet::appendPattern(const vector<int> &inputs, const vector<double> &targets)
{
	this->inputs.push_back(vector<double>(inputs.begin(), inputs.end()));
	this->targets.push_back(vector<double>(targets.begin(), targets.end()));
}

void TrainingSet::setPatternCount(int s)
{
	inputs.resize(s);
	targets.resize(s);
}

int TrainingSet::getPatternCount()
{
	return inputs.size();
}

TrainingSet TrainingSet::operator=(const TrainingSet &trset)
{
	setInputs(trset.getInputs());
	setTargets(trset.getTargets());
	return *this;
}

void TrainingSet::initTS(const vector<vector<double> > &inputs, const vector<vector<double> > &targets)
{
	setInputs(inputs);
	setTargets(targets);
}

void TrainingSet::resizeVectorSet(vector<vector<double> > &vec, int s, double fill)
{
	size_t sInputs = vec.size();

	for(size_t i = 0; i < sInputs; i++){
		vec[i].resize(s, fill);
	}
}
