#include "mlp.h"
using namespace ann_base;

MultilayerPerceptron::MultilayerPerceptron(int ninputs,
										   int noutputs,
										   const vector<int> &layersizes,
										   const TransferFunctionType &tf)
//	:
//	ArtificialNeuralNetwork(ninputs, noutputs)
{
	init(ninputs, noutputs, layersizes, tf);
}

MultilayerPerceptron::~MultilayerPerceptron()
{
	stopTraining();

	layerWeights.clear();
	outputWeights.clear();

//	delete tres;
	delete ts;
	delete mlpbpts;
	delete mlpsats;
}

void MultilayerPerceptron::init(int ninputs, int noutputs, const vector<int> &hiddenLayerSizes, const TransferFunctionType &tf)
{
	tres = new MLPTrainingResult();

//	nInputs = ninputs;
	training = false;

	setDefaultRandomRange(-1, 1);

	blockSignals(true);
	setSaveTrainingResults(false);

	setElapsedEpochsTrigger(50);
	setElapsedTimeTrigger(1000);

	setEnabledElapsedEpochsEvent(false);
	setEnabledElapsedTimeEvent(false);

	setAlfa(1);
	setLayerSizes(hiddenLayerSizes);
	setInputSize(ninputs);
	setOutputSize(noutputs);
	setTransferFunctionType(tf);
	//	setOutputType(Continuous);

	randomizeWeights();
	blockSignals(false);

	//TODO: 3/9/15 validate saturation range to weight assigment
//	setSaturationRange(-50, 50);

//	connect(this, SIGNAL(finished()), SLOT(deleteLater()));
	connect(this, SIGNAL(finished()), SLOT(finished()), Qt::BlockingQueuedConnection);
	connect(this, SIGNAL(appendRecord(double,double,double)), SLOT(onRecordAppened(double,double,double)), Qt::BlockingQueuedConnection);
	connect(&timeTrigger, SIGNAL(timeout()), SLOT(onTimeTrigger())/*, Qt::BlockingQueuedConnection*/);
}

vector<vector<double> > MultilayerPerceptron::getLayerOutputs(const vector<double> &inputs)
{
	size_t  nLayers = layerWeights.size(),
			nNeurons, nWeights;
	double sum;

	vector<double>
			__outputs,
			__inputs(inputs);

	vector<vector<double> > layerOutputs(layerWeights.size() + 1);
//	__inputs = inputs;
//	QMutex mutex;

//	mutex.lock();
	for(size_t layeri = 0; layeri <= nLayers; layeri++){
		nNeurons = (layeri == nLayers ? outputWeights.size() : layerWeights[layeri].size());
		//		vector<double> __outputs = vector<double>(nNeurons, 0);
		__outputs.resize(nNeurons, 0);

		for(size_t neuron = 0; neuron < nNeurons; neuron++){
			nWeights = (layeri == nLayers ? outputWeights[neuron].size() : layerWeights[layeri][neuron].size());
			sum = 0;
			for(size_t weight = 0; weight < nWeights; weight++){
				if(weight == nWeights - 1){
					sum += (layeri == nLayers ? -outputWeights[neuron][weight] : -layerWeights[layeri][neuron][weight]);
				}else{
					sum += (layeri == nLayers ? outputWeights[neuron][weight]*__inputs[weight] : layerWeights[layeri][neuron][weight]*__inputs[weight]);
				}
			}
			switch(tf){
				case Sigmoid:
					__outputs[neuron] = 1/(1+exp(-alfa*sum));
					break;
				case Tanh:
					__outputs[neuron] = tanh(alfa*sum);
					break;
			}
		}
		__inputs = __outputs;

		layerOutputs[layeri] =__outputs;
	}
//	mutex.unlock();

	return layerOutputs;
}

MultilayerPerceptron::NewState MultilayerPerceptron::addNoise(double min, double max)
{

	NewState weights;
	weights.newWeights = layerWeights;
	weights.newOutputWeights = outputWeights;

	size_t
			nLayers = weights.newWeights.size(),
			layer, neuron,
			nNeurons,
			nOutputs;

	srand(clock());
	for(layer = 0; layer < nLayers; layer++){
		nNeurons = weights.newWeights[layer].size();
		for(neuron = 0; neuron < nNeurons; neuron++){
			weights.newWeights[layer][neuron] = math::addNoise(weights.newWeights[layer][neuron], min, max);
		}
	}
	nOutputs = weights.newOutputWeights.size();
	for(size_t i = 0; i < nOutputs; i++){
		weights.newOutputWeights[i] = math::addNoise(weights.newOutputWeights[i], min, max);
	}

	emit weightsChanged();

	return weights;
}

void MultilayerPerceptron::addLayer(int nElements)
{
	QMutex mutex;
	QMutexLocker locker(&mutex);

	int last = (int)layerWeights.size();
	layerWeights.push_back(vector<vector<double> >(nElements, vector<double>(getInputSize() + 1)));

	randomizeWeights(defaultRandomMinimum, defaultRandomMaximum);

	emit layerCountChanged(last, (int)layerWeights.size());
	emit layerCountChanged();
}

void MultilayerPerceptron::insertLayer(int after, int elements)
{
	//TODO: 05/04/16 insertLayer implement
	(void)after;
	(void)elements;
}

void MultilayerPerceptron::removeLayer(unsigned int l)
{
	QMutex mutex;
	QMutexLocker locker(&mutex);

	if(layerWeights.size() > 1){
		layerWeights.erase(layerWeights.begin() + l);
		randomizeWeights(defaultRandomMinimum, defaultRandomMaximum);
	}

	emit layerRemoved(l);
}

bool MultilayerPerceptron::isTraining()
{
	return training;
}

void MultilayerPerceptron::setElapsedEpochsTrigger(int trigger)
{
	if(trigger < 1){
		epochsTriggerInterval = 1;
	}else{
		epochsTriggerInterval = trigger;
	}
}

void MultilayerPerceptron::setEnabledElapsedEpochsEvent(bool en)
{
	epochsTriggerEnabled = en;
}

bool MultilayerPerceptron::getEnabledElapsedEpochsEvent() const
{
	return epochsTriggerEnabled;
}

void MultilayerPerceptron::setElapsedTimeTrigger(int mili)
{
	if(mili < 1){
		timeTriggerInterval = 1;
	}else{
		timeTriggerInterval = mili;
	}
}

void MultilayerPerceptron::setEnabledElapsedTimeEvent(bool en)
{
	if((timeTriggerEnabled = en)){
		connect(&timeTrigger, SIGNAL(timeout()), SLOT(onTimeTrigger()));
	}else{
		timeTrigger.stop();
		timeTrigger.disconnect(this);
	}
}

bool MultilayerPerceptron::getEnabledElapsedTimeEvent() const
{
	return timeTriggerEnabled;
}

ArtificialNeuralNetwork::Type MultilayerPerceptron::getType() const
{
	return ArtificialNeuralNetwork::MultilayerPerceptron;
}

QString MultilayerPerceptron::getName() const
{
	return "MLP";
}

void MultilayerPerceptron::setSaturationRange(double min, double max)
{
	//TODO: must be validated the maxSat and minSat on each weight assigment
	minSat = min;
	maxSat = max;
}

vector<vector<vector<double> > > MultilayerPerceptron::getWeights() const
{
	QMutex mutex;
	QMutexLocker locker(&mutex);

	vector<vector<vector<double> > > out = layerWeights;
	out.push_back(outputWeights);

	return out;
}

void MultilayerPerceptron::setDefaultRandomRange(double min, double max)
{
	defaultRandomMinimum = min;
	defaultRandomMaximum = max;
}

pair<double, double> MultilayerPerceptron::getDefaultRandomRange() const
{
	return make_pair(defaultRandomMinimum, defaultRandomMaximum);
}

void MultilayerPerceptron::setDefaultRandomMinimum(double min)
{
	defaultRandomMinimum = min;
}

double MultilayerPerceptron::getDefaultRandomMinimum() const
{
	return defaultRandomMinimum;
}

void MultilayerPerceptron::setDefaultRandomMaximum(double max)
{
	defaultRandomMaximum = max;
}

double MultilayerPerceptron::getDefaultRandonMaximum() const
{
	return defaultRandomMaximum;
}

double MultilayerPerceptron::getNewMSE(const vector<vector<vector<double> > > &lweights, const vector<vector<double> > &oweights, const vector<vector<double> > &inputs, const vector<vector<double> > &targets)
{
	size_t nPatterns = inputs.size();
	double pMSE = 0;
	vector<double> yObtained;
	size_t nOutputs = getOutputSize();
	for(size_t p = 0; p < nPatterns; p++){
		yObtained = getAuxOutput(lweights, oweights, inputs[p]);
		for(size_t neuron = 0; neuron < nOutputs; neuron++){
			pMSE += (targets[p][neuron] - yObtained[neuron])*(targets[p][neuron] - yObtained[neuron]);
		}
	}
	return pMSE / 2;
}

void MultilayerPerceptron::setLayerSize(unsigned int layer, int size)
{
	size_t
			nLayers = layerWeights.size(),
			lastSize = layerWeights[layer].size();

	layerWeights[layer].resize(size);

	if(nLayers > 1){//In case of multiple hidden layers
		if(layer == nLayers - 1){//when layer is penultimate
			size_t nNeurons = outputWeights.size();
			for(size_t i = 0; i < nNeurons; i++){
				outputWeights[i] = math::getRandomValues(size + 1, defaultRandomMinimum, defaultRandomMaximum);
			}
		}else if(layer <= nLayers - 2){
			size_t nNeurons = layerWeights[layer+1].size();
			for(size_t n = 0; n < nNeurons; n++){
				layerWeights[layer+1][n] = math::getRandomValues(size + 1, defaultRandomMinimum, defaultRandomMaximum);
			}
		}
	}else{
		size_t nNeurons = outputWeights.size();
		for(size_t i = 0; i < nNeurons; i++){
			outputWeights[i] = math::getRandomValues(size + 1, defaultRandomMinimum, defaultRandomMaximum);
		}

	}
	if(layer == 0){
		for(size_t n = 0; n < layerWeights[layer].size(); n++){
			layerWeights[layer][n] = math::getRandomValues(getInputSize() + 1, defaultRandomMinimum, defaultRandomMaximum);
		}
	}else{
		for(size_t n = 0; n < layerWeights[layer].size(); n++){
			layerWeights[layer][n] = math::getRandomValues((int)layerWeights[layer - 1].size() + 1, defaultRandomMinimum, defaultRandomMaximum);
		}
	}

	if(lastSize != layerWeights[layer].size()){
		emit layerSizeChanged(layer, (int)lastSize, (int)layerWeights[layer].size());
		emit layerSizeChanged(layer);
	}
	emit weightsChanged();
}

int MultilayerPerceptron::getLayerSize(unsigned int layer) const
{
	return (int)layerWeights[layer].size();
}

void MultilayerPerceptron::setLayerSizes(const vector<int> &sizes)
{
	size_t
			nLayers = sizes.size(),
			lSize = layerWeights.size();

	layerWeights = vector<vector<vector<double> > >(nLayers);
	for(size_t l = 0; l < nLayers; l++){
		layerWeights[l] = vector<vector<double > >(sizes[l]);
		for(int n = 0; n < sizes[l]; n++){
			if(l == 0){
				layerWeights[l][n] = math::getRandomValues(nInputs + 1, defaultRandomMinimum, defaultRandomMaximum);
			}else{
				layerWeights[l][n] = math::getRandomValues(sizes[l - 1] + 1, defaultRandomMinimum, defaultRandomMaximum);
			}
		}
	}
	size_t nOutputWeights = layerWeights[layerWeights.size()-1].size();
	size_t sOutputs = outputWeights.size();
	for(size_t i = 0; i < sOutputs; i++){
		outputWeights[i] = math::getRandomValues((int)(nOutputWeights + 1), defaultRandomMinimum, defaultRandomMaximum);
	}

	if(lSize != nLayers){
		emit layerCountChanged((int) lSize, (int) nLayers);
		emit layerCountChanged();
	}

	emit weightsChanged();
}

vector<int> MultilayerPerceptron::getLayerSizes() const
{
	size_t nLayers = layerWeights.size();
	vector<int> lsizes(nLayers);
	for(size_t i = 0; i < nLayers; i++){
		lsizes[i] = (int)layerWeights[i].size();
	}
	return lsizes;
}

int MultilayerPerceptron::getHiddenLayerCount() const
{
	return (int) layerWeights.size();
}

void MultilayerPerceptron::setOutputSize(int size)
{
	int lastSize = (int) outputWeights.size();

	outputWeights.resize(size);
	int nOutputWeights = (int)layerWeights[layerWeights.size() - 1].size();
	for(int i = 0; i < size; i++){
		outputWeights[i] = math::getRandomValues(nOutputWeights + 1, defaultRandomMinimum, defaultRandomMaximum);
	}
	if(lastSize != (int)outputWeights.size()){
		emit outputSizeChanged();
		emit outputSizeChanged(lastSize, (int) outputWeights.size());
	}
	emit weightsChanged();
}

int MultilayerPerceptron::getOutputSize() const
{
	return (int)outputWeights.size();
}

void MultilayerPerceptron::setInputSize(int size)
{
	nInputs = size;
	int sNeurons = (int)layerWeights[0].size();

	for(int i = 0; i < sNeurons; i++){
		//NOTE: this line was write to solve a problem when resizing inputs after a training process. It should be validated
//		layerWeights[0][i].reserve(nInputs+1);
		layerWeights[0][i] = math::getRandomValues(nInputs + 1, defaultRandomMinimum, defaultRandomMaximum);
	}
	emit weightsChanged();
}

int MultilayerPerceptron::getInputSize() const
{
//	return layerWeights[0][0].size() - 1;
	return nInputs;
}

vector<double> MultilayerPerceptron::getOutput(const vector<double> &inputs)
{
	size_t  nLayers = layerWeights.size(),
			nNeurons, nWeights;
	double sum;

	vector<double> __outputs;
	vector<double> __inputs(inputs);

	for(size_t layeri = 0; layeri <= nLayers; layeri++){
		nNeurons = (layeri == nLayers ? outputWeights.size() : layerWeights[layeri].size());
		__outputs.resize(nNeurons, 0);

		for(size_t neuron = 0; neuron < nNeurons; neuron++){
			nWeights = (layeri == nLayers ? outputWeights[neuron].size() : layerWeights[layeri][neuron].size());
			sum = 0;
			for(size_t weight = 0; weight < nWeights; weight++){
				if(weight == nWeights - 1){
					sum += (layeri == nLayers ? -outputWeights[neuron][weight] : -layerWeights[layeri][neuron][weight]);
				}else{
					sum += (layeri == nLayers ? outputWeights[neuron][weight]*__inputs[weight] : layerWeights[layeri][neuron][weight]*__inputs[weight]);
				}
			}
			switch(tf){
				case Sigmoid:
					__outputs[neuron] = 1/(1+exp(-alfa*sum));
					break;
				case Tanh:
					__outputs[neuron] = tanh(alfa*sum);
					break;
			}
		}
		__inputs = __outputs;
	}

	return __outputs;
}

vector<int> MultilayerPerceptron::getClasifierOutput(const vector<double> &inputs, double threshold, MultilayerPerceptron::ClasifierOutputType cot)
{
	vector<double> yObtained = getOutput(inputs);
	vector<int> out(yObtained.size());
	int os = getOutputSize();
	for(int i = 0; i < os; i++){
		switch(cot){
			case UnipolarClasifier:
				out[i] = (yObtained[i] >= threshold ? 1 : 0);
				break;
			case BipolarClasifier:
				out[i] = (yObtained[i] > threshold ? 1 : -1);
				break;
		}

	}
	return out;
}

vector<double> MultilayerPerceptron::getOutput(const vector<int> &inputs)
{
	return getOutput(vector<double>(inputs.begin(), inputs.end()));
}

vector<double> MultilayerPerceptron::getOutput(const vector<long> &inputs)
{
	return getOutput(vector<double>(inputs.begin(), inputs.end()));
}

vector<double> MultilayerPerceptron::getAuxOutput(const vector<vector<vector<double> > > &layerWeights, const vector<vector<double> > &outputWeights, const vector<double> &inputs)
{
	size_t  nLayers = layerWeights.size(),
			nNeurons, nWeights;
	double sum;

	vector<double>
			__outputs,
			__inputs(inputs);

	for(size_t layeri = 0; layeri <= nLayers; layeri++){
		nNeurons = (layeri == nLayers ? outputWeights.size() : layerWeights[layeri].size());
		__outputs.resize(nNeurons, 0);

		for(size_t neuron = 0; neuron < nNeurons; neuron++){
			nWeights = (layeri == nLayers ? outputWeights[neuron].size() : layerWeights[layeri][neuron].size());
			sum = 0;
			for(size_t weight = 0; weight < nWeights; weight++){
				if(weight == nWeights - 1){
					sum += (layeri == nLayers ? -outputWeights[neuron][weight] : -layerWeights[layeri][neuron][weight]);
				}else{
					sum += (layeri == nLayers ? outputWeights[neuron][weight]*__inputs[weight] : layerWeights[layeri][neuron][weight]*__inputs[weight]);
				}
			}
			switch(tf){
				case Sigmoid:
					__outputs[neuron] = 1/(1+exp(-alfa*sum));
					break;
				case Tanh:
					__outputs[neuron] = tanh(alfa*sum);
					break;
			}
		}
		__inputs = __outputs;
	}

	return __outputs;
}

double MultilayerPerceptron::getCorrectValue(double value)
{
	if(value < minSat){
		return minSat;
	}else if(value > maxSat){
		return maxSat;
	}else{
		return value;
	}
}

void MultilayerPerceptron::setTransferFunctionType(MultilayerPerceptron::TransferFunctionType tf)
{
	this->tf = tf;
}

MultilayerPerceptron::TransferFunctionType MultilayerPerceptron::getTransferFunctionType()
{
	return tf;
}

void MultilayerPerceptron::randomizeWeights(double min, double max)
{
	QMutex mutex;
	QMutexLocker locker(&mutex);

	size_t
			nLayers = layerWeights.size(),
			layer, neuron,
			nNeurons,
			nOutputs;

	srand(clock());
	for(layer = 0; layer < nLayers; layer++){
		nNeurons = layerWeights[layer].size();
		for(neuron = 0; neuron < nNeurons; neuron++){
			layerWeights[layer][neuron] = (layer == 0 ? math::getRandomValues(getInputSize()+1, min, max) : math::getRandomValues((int)(layerWeights[layer-1].size()+1), min, max));
		}
	}
	nOutputs = outputWeights.size();
	for(size_t i = 0; i < nOutputs; i++){
		outputWeights[i] = math::getRandomValues((int)(layerWeights[nLayers-1].size() + 1), min, max);
	}

	emit weightsChanged();
}

void MultilayerPerceptron::setWeight(int l, int n, int w, double value)
{
	//TODO: 4/9/15 implement this line when saturation range has been implemente
	//value = getCorrectValue(value);

	if(l == (int)layerWeights.size()){
		outputWeights[n][w] = value;
	}else{
		layerWeights[l][n][w] = value;
	}

	emit weightsChanged();
}

void MultilayerPerceptron::startTraining(TrainingSet *ts,
										 BackpropagationSettings *mlpts)
{
	this->ts = ts;
	mlpbpts = mlpts;

	sa = false;

	timeTrigger.start(timeTriggerInterval);

	start(NormalPriority);
}

void MultilayerPerceptron::startTraining(TrainingSet *ts,
										 BackpropagationSettings *mlpts,
										 SimulatedAnnealingSettings *mlpsats)
{
	this->ts = ts;
	mlpbpts = mlpts;
	this->mlpsats = mlpsats;

	sa = true;

	timeTrigger.start(timeTriggerInterval);

	start(NormalPriority);
}

void MultilayerPerceptron::startTraining(TrainingSet *ts,
										 unsigned int epochs,
										 double MSEmin,
										 double RMSEmin,
										 double CEmin,
										 double learningRate,
										 //										 MultilayerPerceptron::TrainingAlgorithm ta,
										 StopCondition sc)
{
	this->ts = ts;
	mlpbpts = new BackpropagationSettings(epochs,
												 MSEmin,
												 RMSEmin,
												 CEmin,
												 learningRate,
												 sc);

	sa = false;

	timeTrigger.start(timeTriggerInterval);

	start(NormalPriority);
}

void MultilayerPerceptron::startTraining(const vector<MultilayerPerceptronPattern*> &ts,
										 unsigned int epochs,
										 double MSEmin,
										 double RMSEmin,
										 double CEmin,
										 double learningRate,
										 //										 TrainingAlgorithm ta,
										 StopCondition sc)
{
	size_t sTS = ts.size();
	vector<vector<double> > inputs(sTS);
	vector<vector<double> > targets(sTS);
	for(size_t i = 0; i < sTS; i++){
		inputs[i] = ts[i]->getInputs();
		targets[i] = ts[i]->getTargets();
	}

	this->ts = new TrainingSet(inputs, getInputSize(), targets, getOutputSize());
	mlpbpts = new BackpropagationSettings(epochs,
												 MSEmin,
												 RMSEmin,
												 CEmin,
												 learningRate,
													 (StopCondition)sc);

	sa = false;
	timeTrigger.start(timeTriggerInterval);

	start(NormalPriority);
}

void MultilayerPerceptron::startTraining(const vector<vector<double> > &inputs,
										 const vector<vector<double> > &targets,
										 unsigned int epochs,
										 double MSEmin,
										 double RMSEmin,
										 double CEmin,
										 double learningRate,
										 //										 TrainingAlgorithm ta,
										 StopCondition sc)
{
	ts = new TrainingSet(inputs, getInputSize(), targets, getOutputSize());
	mlpbpts = new BackpropagationSettings(epochs,
												 MSEmin,
												 RMSEmin,
												 CEmin,
												 learningRate,
												 (StopCondition)sc);

	sa = false;
	timeTrigger.start(timeTriggerInterval);

	start(NormalPriority);
}

MLPTrainingResult *MultilayerPerceptron::getTrainingResult()
{
	QReadWriteLock rwlock;
	QReadLocker locker(&rwlock);
	return tres;
}

void MultilayerPerceptron::stopTraining()
{
	timeTrigger.stop();
	training = false;
}

void MultilayerPerceptron::setAlfa(double a)
{
	if(a >= 0 && a <= 1){
		alfa = a;
	}else if(a < 0){
		alfa = 0;
	}else{
		alfa = 1;
	}
}

double MultilayerPerceptron::getAlfa()
{
	return alfa;
}

double MultilayerPerceptron::getMSE(const vector<vector<double> > &inputs, const vector<vector<double> > &targets)
{
	size_t nPatterns = inputs.size();
	double pMSE = 0;

	vector<double> yObtained;
//	yObtained.clear();

	size_t nOutputs = getOutputSize();
	for(size_t p = 0; p < nPatterns; p++){
		yObtained = getOutput(inputs[p]);
		for(size_t neuron = 0; neuron < nOutputs; neuron++){
			pMSE += (targets[p][neuron] - yObtained[neuron])*(targets[p][neuron] - yObtained[neuron]);
		}
	}

	return pMSE / 2;
}

double MultilayerPerceptron::getRMSE(const vector<vector<double> > &inputs, const vector<vector<double> > &targets)
{
	size_t nPatterns = inputs.size();

	double
			pMSE = 0,
			yn,
			tpn;

	vector<double> yObtained;

	size_t nOutputs = getOutputSize();

	for(size_t p = 0; p < nPatterns; p++){
		yObtained = getOutput(inputs[p]);
		for(size_t neuron = 0; neuron < nOutputs; neuron++){
			tpn = targets[p][neuron];
			yn = yObtained[neuron];
			pMSE += (tpn - yn)*(tpn - yn);
		}
	}

	return sqrt(pMSE)/(nPatterns*nOutputs);
}


double MultilayerPerceptron::getCE(const vector<vector<double> > &inputs, const vector<vector<double> > &targets)
{
	size_t sInputs = inputs.size();
	int os = getOutputSize();
	int errCount = 0;
	int n = 0;
	vector<int> yObtained;
	for(size_t p = 0; p < sInputs; p++){
		yObtained = getClasifierOutput(inputs[p],
									   (cot == UnipolarClasifier ? 0.5 : 0),
									   cot);
		for(int element = 0; element < os; element++){
			switch(cot){
				case UnipolarClasifier:
					if(math::toUnipolar(targets[p], 0.5)[element] != yObtained[element]){
						errCount++;
					}
					break;
				case BipolarClasifier:
					if(math::toBipolar(targets[p], 0)[element] != yObtained[element]){
						errCount++;
					}
					break;
			}
			n++;
		}
	}
//	yObtained.clear();
	return errCount/n;
}

void MultilayerPerceptron::run()
{
	emit trainingAboutStart();

	clock_t t_ini = clock();

	queue<double> errors;

	//NOTE: 23/12/14 this variable is strictly necessary to be concurrent. Dont know why this yet.
	concurrent_vector<concurrent_vector<double> >
			deltaHidden(layerWeights.size(), concurrent_vector<double>(layerWeights[0].size(), 0));

	vector<vector<double> >
			tsInputs = ts->getNormalizedInputs(),
			tsTargets = ts->getNormalizedTargets();

	StopCondition
			//BP parameters
			sc = (StopCondition)mlpbpts->getStopCondition();

	double
			//SA parameters
			samples = 0,
			startCondition = 0,
			To = 0,
			minNoise = 0,
			maxNoise = 0,
			decTemp = 0,
			Tmin = 0,

			//BP parameters
			learningRate = mlpbpts->getLearningRate(),
			MSEmin = mlpbpts->getMinMSE(),
			RMSEmin = mlpbpts->getMinRMSE(),
			CEmin = mlpbpts->getMinCE(),
			pMSE,
			sumDeltas,
			condMSE = 0,
			condRMSE,
			condCE;

	long long
			condEpochs = 0; //Contador de epocas para la condicion de parada

	unsigned int
			//SA parameters
			nChanges = 0,

			//BP parameters
			maxEpochs = mlpbpts->getMaxEpochs();

	if(sa){
		samples = mlpsats->getSamples();
		startCondition = mlpsats->getStartCondition();
		To = mlpsats->getTo();
		minNoise = mlpsats->getMinNoise();
		maxNoise = mlpsats->getMaxNoise();
		decTemp = mlpsats->getDecTempFactor();
		Tmin = mlpsats->getMinTemperature();
		nChanges = mlpsats->getChanges();
	}

	size_t
			nPatterns,
			nNeurons,
			nBOutputs,
			nOutputs;

	nPatterns = tsInputs.size();
	int nLayers  = int(layerWeights.size());

	nOutputs = getOutputSize();
	//	MultilayerPerceptron::TrainingResult tr;

//	static MLPTrainingResult *tres = new MLPTrainingResult();

//	tres->clear();

//	emit appendRecord(getMSE(inputs, targets), getRMSE(inputs, targets), getCE(inputs, targets));

//	tres->appendRecord(getMSE(inputs, targets), getRMSE(inputs, targets), getCE(inputs, targets));

	vector<double>
			yObtained,
			deltaOut;
	//01/12/2014 se esta probando si es necesario reservar memoria con concurrent_vector
//	yObtained.reserve(nOutputs);
	yObtained.resize(nOutputs);

//	deltaOut.reserve(nOutputs);
	deltaOut.resize(nOutputs);

	vector<vector<double> > layerOutputs;

	//Parametros Simulated Annealing
	long double
			T = 0,
			sumDeltaE = 0,
			deltaE = 0, //Difference between actual MSE and last MSE
			Pa = 0, //Acceptance probability
			avgDeltaE = 0;

	//Se inicia la rutina de entrenamiento

	//01/12/14: se esta probando si es o no necesario el uso de mutex
	training = true; //debe ser true

	do{
		for(size_t p = 0; p < nPatterns; p++){

			//Se obtienen las salidas para cada una de las capas
//			mutex.lock();
			layerOutputs = getLayerOutputs(tsInputs[p]);
			yObtained = layerOutputs[layerOutputs.size() - 1];
//			mutex.unlock();

			for(int layer = nLayers; layer >= 0; layer--){
				nNeurons = (layer == nLayers ? outputWeights.size() : layerWeights[layer].size());
				for(size_t neuron = 0; neuron < nNeurons; neuron++){

					//Se inicia el calculo de todos los deltas
					if(layer == nLayers){ //Si es la capa de salida
						if(neuron < nNeurons){
							double yN = yObtained[neuron];
							switch(tf){
								case Sigmoid:
									deltaOut[neuron] = alfa * yN * (1 - yN) * (tsTargets[p][neuron] - yN);
									break;
								case Tanh:
									deltaOut[neuron] = alfa * (1 - (yN * yN)) * (tsTargets[p][neuron] - yN);
									break;
							}
						}else{
							continue;
						}
					}else{
						size_t nDeltaElements = (layer == nLayers - 1 ? outputWeights.size() : layerWeights[layer + 1].size());
						sumDeltas = 0;
						for(size_t element = 0; element < nDeltaElements; element++){
							if(layer == nLayers - 1){
								sumDeltas += deltaOut[element] * outputWeights[element][neuron];
							}else{
								sumDeltas += deltaHidden[layer+1][element] * layerWeights[layer+1][element][neuron];
							}
						}
						double lOn = layerOutputs[layer][neuron];
						switch(tf){
							case Sigmoid:
								deltaHidden[layer][neuron] = alfa * lOn * (1 - lOn) * sumDeltas;
								break;
							case Tanh:
								deltaHidden[layer][neuron] = alfa * (1 - (lOn * lOn)) * sumDeltas;
								break;
						}
					}
				}
			}

			//Comienza la actualizacion de los pesos
			for(int layer = nLayers; layer >= 0; layer--){
				nNeurons = (layer == nLayers ? nOutputs : layerWeights[layer].size());
				for(size_t i = 0; i < nNeurons; i++){
					nBOutputs = (layer == 0 ? tsInputs[p].size() : layerWeights[layer - 1].size());
					for(size_t j = 0; j <= nBOutputs; j++){
						if(layer == nLayers){
							outputWeights[i][j] += (j == nBOutputs ? -learningRate*deltaOut[i] : learningRate*deltaOut[i]*layerOutputs[layer-1][j]);
						}else if(layer == 0){
							layerWeights[layer][i][j] += (j == nBOutputs ?
															  -learningRate*deltaHidden[layer][i] :
															  learningRate*deltaHidden[layer][i]*tsInputs[p][j]);
						}else{
							layerWeights[layer][i][j] += (j == nBOutputs ? -learningRate*deltaHidden[layer][i] : learningRate*deltaHidden[layer][i]*layerOutputs[layer-1][j]);
						}
					}
				}
			}
		}

		pMSE = getMSE(tsInputs, tsTargets);

		if(sa){//if Simulated annealing active

			deltaE = pMSE - condMSE;
			errors.push(deltaE);
			sumDeltaE += deltaE;

			if(errors.size() > samples){
				sumDeltaE -= errors.front();
				errors.pop();
			}

			avgDeltaE = sumDeltaE / errors.size(); //Calculates average Delta Error

			if(fabs(avgDeltaE) < startCondition){
				//					double avgDeltaF = sumDeltaF / c;
				//					T = avgDeltaF / log(initialAcceptance);
				//                    T = 1 / log(initialAcceptance) * avgDeltaF;
				//                    T = deltaF / log(Pa);
				//                    T = -deltaF;
				//                    T = To;
				T = To;
				double eNew;
				NewState ns;
//				int n = 0;
				double eOld = pMSE;

				double rnd = 0;
				do{
					for(unsigned int i = 0; i < nChanges; i++){
						ns = addNoise(minNoise, maxNoise);
						eNew = getNewMSE(ns.newWeights,
										 ns.newOutputWeights,
										 tsInputs,
										 tsTargets);

						deltaE = eNew - eOld;
						Pa = exp(-deltaE/T);
						rnd = math::randomNumber(0, 1);

						if(/*deltaE < 0 || */rnd <= Pa){
							layerWeights = ns.newWeights;
							outputWeights = ns.newOutputWeights;

							eOld = getMSE(tsInputs, tsTargets);

							if(enabledSaveTrainingResults && training){
								//Se debe hacer la operacion lanzando una señal, vease el tipo de conexion que tiene esta

								//TODO: Implement a method wich return all errors in one structure, to be mor efficient
								emit appendRecord(eOld, getRMSE(tsInputs, tsTargets), getCE(tsInputs, tsTargets));

//								tres->appendRecord(eOld, getRMSE(tsInputs, tsTargets), getCE(tsInputs, tsTargets));
								tres->setTime(double(clock() - t_ini)/CLOCKS_PER_SEC);
							}
						}
					}
//					T = T / (decTemp*(++n));
					T *= decTemp;
					//						n++;
				}while(T > Tmin && training);

				errors = queue<double>();

				sumDeltaE = 0;
			}
		}

		condMSE = getMSE(tsInputs, tsTargets);
		condRMSE = getRMSE(tsInputs, tsTargets);
		condCE = getCE(tsInputs, tsTargets);
		condEpochs++;

		if(enabledSaveTrainingResults && training){
			//Se debe hacer la operacion lanzando una señal, vease el tipo de conexion que tiene esta
			emit appendRecord(condMSE, condRMSE, condCE);

//			tres->appendRecord(condMSE, condRMSE, condCE);
			tres->setTime(double(clock() - t_ini)/CLOCKS_PER_SEC);
		}

		//NOTE: should be validated
		//emits event elapsedEpochs
		if(condEpochs > 0){
			if(condEpochs % epochsTriggerInterval == 0 && epochsTriggerEnabled){
				emit elapsedEpochs(*tres);
			}
		}

		emit weightsChanged();

	}while(((condMSE >= MSEmin && sc == MSE) ||
			(condRMSE >= RMSEmin && sc == RMSE) ||
			(condCE >= CEmin && sc == CE)) &&
		   condEpochs < maxEpochs &&
		   training);

	training = false;
	tres->setTime(double(clock() - t_ini)/CLOCKS_PER_SEC);
}

void MultilayerPerceptron::finished()
{
	timeTrigger.stop();
	emit trainingFinished();
	emit trainingFinished(*tres);
}

void MultilayerPerceptron::onTimeTrigger()
{
	QReadWriteLock rwlock;
	QReadLocker locker(&rwlock);
	emit elapsedTime(*tres);
}

void MultilayerPerceptron::onRecordAppened(double mse, double rmse, double ce)
{
	tres->appendRecord(mse, rmse, ce);
}

void MultilayerPerceptron::setSaveTrainingResults(bool estr)
{
	enabledSaveTrainingResults = estr;
}

bool MultilayerPerceptron::getSaveTrainingResults() const
{
	return enabledSaveTrainingResults;
}
