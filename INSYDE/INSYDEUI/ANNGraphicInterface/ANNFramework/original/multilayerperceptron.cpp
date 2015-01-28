#include "multilayerperceptron.h"
//#include <complex>

void MultilayerPerceptron::setSaveTrainingResults(bool estr)
{
	enabledSaveTrainingResults = estr;
}

bool MultilayerPerceptron::getSaveTrainingResults() const
{
	return enabledSaveTrainingResults;
}

MultilayerPerceptron::MultilayerPerceptron(int ninputs,
										   int noutputs,
										   const vector<int> &layersizes,
										   const TransferFunctionType &tf) :
	QThread(0)
{
	init(ninputs, noutputs, layersizes, tf);
}

MultilayerPerceptron::~MultilayerPerceptron()
{
	mutex.lock();
	training = false;
//	tres->clear();
	mutex.unlock();

	deltaHidden.clear();
	__outputs.clear();
	__inputs.clear();
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

	nInputs = ninputs;

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

	//	vector<double> __outputs(10);
	//	vector<double> __inputs(inputs);
	vector<vector<double> > layerOutputs(layerWeights.size() + 1);
	__inputs = inputs;

	for(size_t layeri = 0; layeri <= nLayers; layeri++){
		nNeurons = (layeri == nLayers ? outputWeights.size() : layerWeights[layeri].size());
		//		vector<double> __outputs = vector<double>(nNeurons, 0);
		__outputs = vector<double>(nNeurons, 0);

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

		layerOutputs[layeri] = vector<double>(__outputs);
	}

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
			weights.newWeights[layer][neuron] = ANNFrameworkFunctions::addNoise(weights.newWeights[layer][neuron], min, max);
		}
	}
	nOutputs = weights.newOutputWeights.size();
	for(size_t i = 0; i < nOutputs; i++){
		weights.newOutputWeights[i] = ANNFrameworkFunctions::addNoise(weights.newOutputWeights[i], min, max);
	}
	return weights;
}

void MultilayerPerceptron::addLayer(int nElements)
{
	//Se agrega la nueva capa
	layerWeights.push_back(vector<vector<double> >(nElements, vector<double>(getInputSize() + 1, 0)));

	//Se ajusta el numero de pesos de la capa antecesora
	size_t
			pIndex = layerWeights.size()-2,
			sPrevious = layerWeights[pIndex].size();
	for(size_t n = 0; n < sPrevious; n++){
		layerWeights[pIndex][n].resize(nElements + 1);
	}
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
	size_t nLayers = layerWeights.size();

	layerWeights[layer].resize(size);

	//Si la capa a redimensionar es anterior a la penultima capa
	if(layer <= nLayers - 2){
		size_t nNeurons = layerWeights[layer+1].size();
		for(size_t i = 0; i < nNeurons; i++){
			layerWeights[layer+1][i] = getRandomValues(size+1);
		}
	}else if(layer == nLayers - 1){
		size_t nNeurons = outputWeights.size();
		for(size_t i = 0; i < nNeurons; i++){
			outputWeights[i] = getRandomValues(size+1);
		}
	}
}

int MultilayerPerceptron::getLayerSize(unsigned int layer)
{
	return layerWeights[layer].size();
}

void MultilayerPerceptron::setLayerSizes(const vector<int> &sizes)
{
	//    layerSizes = sizes;
	//	this->hiddenLayerSizes = sizes;
	size_t nLayers = sizes.size();
	layerWeights = vector<vector<vector<double> > >(nLayers);
	for(size_t i = 0; i < nLayers; i++){
		layerWeights[i] = vector<vector<double > >(sizes[i]);
		for(int j = 0; j < sizes[i]; j++){
			if(i == 0){
				layerWeights[i][j] = getRandomValues(nInputs + 1);
			}else{
				layerWeights[i][j] = getRandomValues(sizes[i - 1] + 1);
			}
		}
		//		setLayerSize(i, sizes[i]);
	}
	//	outputWeights.resize();
	size_t nOutputWeights = layerWeights[layerWeights.size()-1].size();
	size_t sOutputs = outputWeights.size();
	for(size_t i = 0; i < sOutputs; i++){
		outputWeights[i] = getRandomValues(nOutputWeights + 1);
	}
}

vector<int> MultilayerPerceptron::getLayerSizes()
{
	size_t nLayers = layerWeights.size();
	vector<int> lsizes(nLayers);
	for(size_t i = 0; i < nLayers; i++){
		lsizes[i] = (layerWeights[i].size());
	}
	return lsizes;
}

void MultilayerPerceptron::setOutputSize(size_t size)
{
	outputWeights.resize(size);
	size_t nOutputWeights = layerWeights[layerWeights.size()-1].size();
	for(size_t i = 0; i < size; i++){
		outputWeights[i] = getRandomValues(nOutputWeights + 1);
	}
}

int MultilayerPerceptron::getOutputSize()
{
	return outputWeights.size();
}

void MultilayerPerceptron::setInputSize(int size)
{
	nInputs = size;
	int sNeurons = layerWeights[0].size();

	for(int i = 0; i < sNeurons; i++){
		layerWeights[0][i] = getRandomValues(nInputs + 1);
	}
}

int MultilayerPerceptron::getInputSize()
{
//	return layerWeights[0][0].size() - 1;
	return nInputs;
}

vector<double> MultilayerPerceptron::getOutput(const vector<double> &inputs)
{
	size_t  nLayers = layerWeights.size(),
			nNeurons, nWeights;
	double sum;

	__inputs = /*vector<double>*/(inputs);

	for(size_t layeri = 0; layeri <= nLayers; layeri++){
		nNeurons = (layeri == nLayers ? outputWeights.size() : layerWeights[layeri].size());
		__outputs = vector<double>(nNeurons, 0);

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

vector<int> MultilayerPerceptron::getClasifierOutput(const vector<double> &inputs, double threshold, ClasifierOutputType cot)
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
	//NOTE: se reemplazo este segmento de codigo por algo mas eficiente
//	int sInputs = inputs.size();
//	vector<double> dblInputs(sInputs);
//	for(int i = 0; i < sInputs; i++){
//		dblInputs[i] = double(inputs[i]);
//	}
//	return getOutput(dblInputs);

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

	__inputs = vector<double>(inputs);

	for(size_t layeri = 0; layeri <= nLayers; layeri++){
		nNeurons = (layeri == nLayers ? outputWeights.size() : layerWeights[layeri].size());
		__outputs = vector<double>(nNeurons, 0);

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
	size_t
			nLayers = layerWeights.size(),
			layer, neuron,
			nNeurons,
			nOutputs;

	srand(clock());
	for(layer = 0; layer < nLayers; layer++){
		nNeurons = layerWeights[layer].size();
		for(neuron = 0; neuron < nNeurons; neuron++){
			layerWeights[layer][neuron] = (layer == 0 ? getRandomValues(getInputSize()+1, min, max) : getRandomValues(layerWeights[layer-1].size()+1, min, max));
		}
	}
	nOutputs = outputWeights.size();
	for(size_t i = 0; i < nOutputs; i++){
		outputWeights[i] = getRandomValues(layerWeights[nLayers-1].size() + 1, min, max);
	}
}

void MultilayerPerceptron::startTraining(TrainingSet *ts,
										 BackpropagationSettings *mlpts)
{
	this->ts = ts;
	mlpbpts = mlpts;

	sa = false;

	timeTrigger.start(timeTriggerInterval);

	//	return startTraining(ts.getInputs(), ts.getTargets(), mlpts.getMaxEpochs(), mlpts.getMSEmin(), mlpts.getRMSEmin(), mlpts.getClasificationErrorMin(), mlpts.getLearningRate());
	start(LowestPriority);
}

void MultilayerPerceptron::startTraining(TrainingSet *ts,
										 BackpropagationSettings *mlpts,
										 SimulatedAnnealingSettings *mlpsats)
{

	this->ts = ts;
	mlpbpts = mlpts;
	this->mlpsats = mlpsats;

	sa = true;

	start(LowestPriority);

	//	setSAParameters(mlpsats.getMinTemperature(),
	//					mlpsats.getChanges(),
	//					mlpsats.getLocalMinimumCondition(),
	//					mlpsats.getTo(),
	//					mlpsats.getMinNoise(),
	//					mlpsats.getMaxNoise(),
	//					mlpsats.getTempDecrementFactor());

	//	return startTraining(ts.getInputs(),
	//						 ts.getTargets(),
	//						 mlpts.getMaxEpochs(),
	//						 mlpts.getMSEmin(),
	//						 mlpts.getLearningRate(),
	//						 SimulatedAnnealing);
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

	start(LowestPriority);

	//	return startTraining(ts.getInputs(), ts.getTargets(), epochs, MSEmin, RMSEmin, CEmin, learningRate, ta, sc);
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
	start(LowestPriority);
	//	return startTraining(inputs, targets, epochs, MSEmin, RMSEmin, CEmin, learningRate, ta, sc);
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
	start(LowestPriority);
}

MLPTrainingResult *MultilayerPerceptron::getTrainingResult()
{
	QReadLocker locker(&rwlock);
	return tres;
}

void MultilayerPerceptron::stopTraining()
{
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

//void MultilayerPerceptron::setSAParameters(double minTemperature, int numberOfChanges, double sCondition, double To, double minNoise, double maxNoise, double tdf)
//{
//	Tmin = minTemperature;
//	nChanges = numberOfChanges;
//	startCondition = sCondition;
//	this->To = To;
//	this->minNoise = minNoise;
//	this->maxNoise = maxNoise;
//	tempDecFactor = tdf;
//}

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
//	yObtained.clear();
	return pMSE / 2;
}

double MultilayerPerceptron::getRMSE(const vector<vector<double> > &inputs, const vector<vector<double> > &targets)
{
	size_t nPatterns = inputs.size();
	double pMSE = 0;
	vector<double> yObtained;
	size_t nOutputs = getOutputSize();
	for(size_t p = 0; p < nPatterns; p++){
		yObtained = getOutput(inputs[p]);
		for(size_t neuron = 0; neuron < nOutputs; neuron++){
			pMSE += (targets[p][neuron] - yObtained[neuron])*(targets[p][neuron] - yObtained[neuron]);
		}
	}
//	yObtained.clear();
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
					if(toUnipolar(targets[p], 0.5)[element] != yObtained[element]){
						errCount++;
					}
					break;
				case BipolarClasifier:
					if(toBipolar(targets[p], 0)[element] != yObtained[element]){
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
	clock_t t_ini = clock();


    vector<vector<double> >
            inputs = (ts->getInputs()),
            targets = (ts->getTargets());

	StopCondition
			//BP parameters
			sc = (StopCondition)mlpbpts->getStopCondition();

	double
			//SA parameters
			startCondition = 0,
			To = 0,
			minNoise = 0,
			maxNoise = 0,
			tempDecFactor = 0,
			Tmin = 0,

			//BP parameters
			learningRate = mlpbpts->getLearningRate(),
			MSEmin = mlpbpts->getMinMSE(),
			RMSEmin = mlpbpts->getMinRMSE(),
			CEmin = mlpbpts->getMinCE(),
			pMSE,
			sumDeltas,
			condMSE,
			condRMSE,
			condCE,
			whileTraining;

	long long
			condEpochs = 0;

	unsigned int
			//SA parameters
			nChanges = 0,

			//BP parameters
			maxEpochs = mlpbpts->getMaxEpochs();

	if(sa){
		startCondition = mlpsats->getStartCondition();
		To = mlpsats->getTo();
		minNoise = mlpsats->getMinNoise();
		maxNoise = mlpsats->getMaxNoise();
		tempDecFactor = mlpsats->getDecTempFactor();
		Tmin = mlpsats->getMinTemperature();
		nChanges = mlpsats->getChanges();
	}

	size_t
			nPatterns,
			nNeurons,
			nBOutputs,
			nOutputs;

	vector<double>
			yObtained,
			deltaOut(outputWeights.size(), 0);
	//	vector<vector<double> > deltaHidden(layerWeights.size());
	deltaHidden.resize(layerWeights.size());
	for(size_t i = 0; i < deltaHidden.size(); i++){
		size_t sLayer = layerWeights[i].size();
		deltaHidden[i].resize(sLayer, 0);
	}


	nPatterns = inputs.size();
	int nLayers  = int(layerWeights.size());

	nOutputs = getOutputSize();
	//	MultilayerPerceptron::TrainingResult tr;

//	static MLPTrainingResult *tres = new MLPTrainingResult();

//	tres->clear();

//	emit appendRecord(getMSE(inputs, targets), getRMSE(inputs, targets), getCE(inputs, targets));

//	tres->appendRecord(getMSE(inputs, targets), getRMSE(inputs, targets), getCE(inputs, targets));

	vector<vector<double> > layerOutputs;

	long double
			T = 0,
			sumDeltaF = 0,
			deltaF = 0,
			Pa = 0,
			avgDeltaF = 0;
	int c = 0;


	//En este punto se inicia la rutina de entrenamiento

	mutex.lock();
	training = true;
	mutex.unlock();

	do{
		//		tr.MSE = 0;
		//				pMSE = 0;
		for(size_t p = 0; p < nPatterns; p++){

			//Se obtienen las salidas para cada una de las capas
			mutex.lock();
			layerOutputs = getLayerOutputs(inputs[p]);
			mutex.unlock();

			yObtained = layerOutputs[layerOutputs.size() - 1];
			for(int layer = nLayers; layer >= 0; layer--){
				nNeurons = (layer == nLayers ? outputWeights.size() : layerWeights[layer].size());
				//				deltaOut = vector<double>(nNeurons, 0);
				for(size_t neuron = 0; neuron <= nNeurons; neuron++){

					//Se inicia el calculo de todos los deltas
					if(layer == nLayers){ //Si es la capa de salida
						if(neuron < nNeurons){
							switch(tf){
								case Sigmoid:
									deltaOut[neuron] = alfa * yObtained[neuron] * (1 - yObtained[neuron]) * (targets[p][neuron] - yObtained[neuron]);
									break;
								case Tanh:
									deltaOut[neuron] = alfa * (1 - (yObtained[neuron]*yObtained[neuron])) * (targets[p][neuron] - yObtained[neuron]);
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

						switch(tf){
							case Sigmoid:
								deltaHidden[layer][neuron] = alfa * layerOutputs[layer][neuron] * (1 - layerOutputs[layer][neuron]) * sumDeltas;
								break;
							case Tanh:
								deltaHidden[layer][neuron] = alfa * (1 - (layerOutputs[layer][neuron]*layerOutputs[layer][neuron])) * sumDeltas;
								break;
						}
					}
				}
			}

			//Comienza la actualizacion de los pesos
			for(int layer = nLayers; layer >= 0; layer--){
				nNeurons = (layer == nLayers ? nOutputs : layerWeights[layer].size());
				for(size_t i = 0; i < nNeurons; i++){
					nBOutputs = (layer == 0 ? inputs[p].size() : layerWeights[layer - 1].size());
					for(size_t j = 0; j <= nBOutputs; j++){
						if(layer == nLayers){
							outputWeights[i][j] += (j == nBOutputs ? -learningRate*deltaOut[i] : learningRate*deltaOut[i]*layerOutputs[layer-1][j]);
						}else if(layer == 0){
							layerWeights[layer][i][j] += (j == nBOutputs ?
															  -learningRate*deltaHidden[layer][i] :
															  learningRate*deltaHidden[layer][i]*inputs[p][j]);
						}else{
							layerWeights[layer][i][j] += (j == nBOutputs ? -learningRate*deltaHidden[layer][i] : learningRate*deltaHidden[layer][i]*layerOutputs[layer-1][j]);
						}
					}
				}
			}
		}

		pMSE = getMSE(inputs, targets);

		if(sa){//if Simulated annealing actived
//			deltaF = pMSE - tres->getMeanSquareError();
			deltaF = pMSE - condMSE;
			sumDeltaF += deltaF; // Se calcula deltaF promedio
			c++;
			avgDeltaF = sumDeltaF / c;
		}

		condMSE = pMSE;
		condRMSE = getRMSE(inputs, targets);
		condCE = getCE(inputs, targets);
		condEpochs++;

//		rwlock.lockForWrite();
		if(enabledSaveTrainingResults){
//			mutex.lock();
//			tres->appendRecord(pMSE, getRMSE(inputs, targets), getCE(inputs, targets));
//			mutex.unlock();

			//Se debe hacer la operacion lanzando una señal, vease el tipo de conexion que tiene esta
//			mutex.lock();
//			emit appendRecord(pMSE, getRMSE(inputs, targets), getCE(inputs, targets));
//			emit appendRecord(condMSE, condRMSE, condCE);
//			mutex.unlock();
		}
//		rwlock.unlock();

		//Emite el evento elapsedEpochs


//		long long whileEpochs = tres->getEpochs();
		if(condEpochs > 0){
			if(condEpochs % epochsTriggerInterval == 0 && epochsTriggerEnabled){
//				*copyTres = (*tres);
				mutex.lock();
				emit elapsedEpochs(*tres);
				mutex.unlock();
			}
		}

		if(sa){
			if(fabs(avgDeltaF) < startCondition && c > 999){
				//					double avgDeltaF = sumDeltaF / c;
				//					T = avgDeltaF / log(initialAcceptance);
				//                    T = 1 / log(initialAcceptance) * avgDeltaF;
				//                    T = deltaF / log(Pa);
				//                    T = -deltaF;
				//                    T = To;
				T = To;
				double fNew;
				NewState ns;
				//					int n = 0;
//				mutex.lock();
				double fOld = condMSE;
//				mutex.unlock();

				double rnd = 0;
				do{
					for(unsigned int i = 0; i < nChanges; i++){
						ns = addNoise(minNoise, maxNoise);
						fNew = getNewMSE(ns.newWeights, ns.newOutputWeights, inputs, targets);
						deltaF = fNew - fOld;
						Pa = exp(-deltaF/T);
						rnd = randomNumber(0,1);
						if(deltaF < 0
						   || rnd < Pa
						   ){
//							mutex.lock();
							layerWeights = ns.newWeights;
							outputWeights = ns.newOutputWeights;
							fOld = getMSE(inputs, targets);
//							mutex.unlock();
						}
					}
					//						T = T / (1 + n);
					T = tempDecFactor*T;
					//						n++;
				}while(T > Tmin);
				c = 0;
				sumDeltaF = 0;
			}
		}
		//Se bloquea para otros threads
		mutex.lock();
//		whileMSE = tres->getMeanSquareError();
//		whileRMSE = tres->getRootMeanSquareError();
//		whileCE = tres->getClasificationError();
//		whileEpochs = tres->getEpochs();
		whileTraining = training;
		mutex.unlock();

	}while(((condMSE >= MSEmin && sc == MSE) ||
			(condRMSE >= RMSEmin && sc == RMSE) ||
			(condCE >= CEmin && sc == CE)) &&
		   condEpochs < maxEpochs &&
		   whileTraining);

//    inputs.clear();
//    targets.clear();
//	mutex.lock();
	training = false;
    tres->setTime(double(clock() - t_ini)/CLOCKS_PER_SEC);
//	mutex.unlock();
}

void MultilayerPerceptron::finished()
{
//	QReadLocker locker(&rwlock);
	timeTrigger.stop();
	timeTrigger.disconnect(this);

	mutex.lock();

//	*copyTres = *tres;
	emit trainingFinished(/*MLPTrainingResult*/(*tres));
	mutex.unlock();
}

void MultilayerPerceptron::onTimeTrigger()
{
	QReadLocker locker(&rwlock);
//	*copyTres = *tres;
	emit elapsedTime(*tres);
}

void MultilayerPerceptron::onRecordAppened(double mse, double rmse, double ce)
{
//	rwlock.lockForWrite();
	tres->appendRecord(mse, rmse, ce);
//	rwlock.unlock();
}

