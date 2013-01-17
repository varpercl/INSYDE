#include "multilayerperceptron.h"
//#include <complex>

MultilayerPerceptronPattern::MultilayerPerceptronPattern(int ninputs, int ntargets) :
	SimpleInputPattern(ninputs)
{
	initMLPP(ntargets);
}

MultilayerPerceptronPattern::MultilayerPerceptronPattern(vector<double> inputs, vector<double> targets) :
	SimpleInputPattern(inputs)
{
	initMLPP(targets);
}

MultilayerPerceptronPattern::MultilayerPerceptronPattern(double *inputs, size_t sinputs, double *targets, size_t stargets) :
	SimpleInputPattern(inputs, sinputs)
{
	initMLPP(targets, stargets);
}

void MultilayerPerceptronPattern::setTargets(double *v, size_t s)
{

	targets.assign(v, v + s);
}

void MultilayerPerceptronPattern::setTargets(vector<double> targets)
{
	this->targets = targets;
}

vector<double> MultilayerPerceptronPattern::getTargets()
{
	return targets;
}

void MultilayerPerceptronPattern::initMLPP(int ntargets)
{
	targets.resize(ntargets);
}

void MultilayerPerceptronPattern::initMLPP(vector<double> targets)
{
	this->targets = targets;
}

void MultilayerPerceptronPattern::initMLPP(double *targets, size_t s)
{
	setTargets(targets, s);
}

MultilayerPerceptron::MultilayerPerceptron(int ninputs, int noutputs, const vector<int> &layersizes, const TransferFunctionType &tf)
{
	initMLP(ninputs, noutputs, layersizes, tf);
}

void MultilayerPerceptron::initMLP(int ninputs, int noutputs, const vector<int> &hiddenLayerSizes, const TransferFunctionType &tf)
{
	nInputs = ninputs;
	setAlfa(1);
	setLayerSizes(hiddenLayerSizes);
	setInputSize(ninputs);
	setOutputSize(noutputs);
	setTransferFunctionType(tf);
	randomizeWeights();
}

vector<vector<double> > MultilayerPerceptron::getLayerOutputs(const vector<double> &inputs)
{
	size_t  nLayers = layerWeights.size(),
			nNeurons, nWeights;
	double sum;

	//	vector<double> __outputs(10);
	//	vector<double> __inputs(inputs);
	vector<vector<double> > layerOutputs(layerWeights.size() + 1);
	__inputs = vector<double>(inputs);

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
		layerOutputs[layeri] = __outputs;
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
			weights.newWeights[layer][neuron] = addNoise(weights.newWeights[layer][neuron], min, max);
		}
	}
	nOutputs = weights.newOutputWeights.size();
	for(size_t i = 0; i < nOutputs; i++){
		weights.newOutputWeights[i] = addNoise(weights.newOutputWeights[i], min, max);
	}
	return weights;
}

vector<double> MultilayerPerceptron::addNoise(const vector<double> &vec, double min, double max)
{
	vector<double> cVec = vec;
	size_t sVec = cVec.size();
	//	srand(clock());
	for(size_t i = 0; i < sVec; i++){
		cVec[i] += randomNumber(min, max);
	}
	return cVec;
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
	return layerWeights[0][0].size() - 1;
}

vector<double> MultilayerPerceptron::getOutput(const vector<double> &inputs)
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

vector<double> MultilayerPerceptron::getOutput(const vector<int> &inputs)
{
	int sInputs = inputs.size();
	vector<double> dblInputs(sInputs);
	for(int i = 0; i < sInputs; i++){
		dblInputs[i] = double(inputs[i]);
	}
	return getOutput(dblInputs);
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

MultilayerPerceptron::TrainingResult MultilayerPerceptron::startTraining(const vector<MultilayerPerceptronPattern*> &ts, unsigned int epochs, double errormin, double learningRate, TrainingAlgorithm ta)
{
	size_t sTS = ts.size();
	vector<vector<double> > inputs(sTS);
	vector<vector<double> > targets(sTS);
	for(size_t i = 0; i < sTS; i++){
		inputs[i] = ts[i]->getInputs();
		targets[i] = ts[i]->getTargets();
	}

	TrainingResult tr = startTraining(inputs, targets, epochs, errormin, learningRate, ta);

	return tr;
}

MultilayerPerceptron::TrainingResult MultilayerPerceptron::startTraining(const vector<vector<double> > &inputs, const vector<vector<double> > &targets, unsigned int epochs, double errormin, double learningRate, TrainingAlgorithm ta)
{

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

	double pMSE;
	//	unsigned long epc;

	double sumDeltas;
	nOutputs = getOutputSize();
	//	MultilayerPerceptron::TrainingResult tr;
	tr.time = 0;
	tr.epochs = 0;
	tr.MSE = getMSE(inputs, targets);
	tr.RMSE = getRMSE(inputs, targets);
	tr.layerWeightsHistory.clear();
	tr.outputWeightsHistory.clear();
	tr.MSEHistory.clear();
	tr.RMSEHistory.clear();

	tr.layerWeightsHistory.push_back(layerWeights);
	tr.outputWeightsHistory.push_back(outputWeights);
	tr.MSEHistory.push_back(tr.MSE);
	vector<vector<double> > layerOutputs;
	training = true;
	clock_t t_ini = clock();
	switch(ta){
		case Backpropagation:
			do{
				//		tr.MSE = 0;
				pMSE = 0;
				for(size_t p = 0; p < nPatterns; p++){

					//Se obtienen las salidas para cada una de las capas
					layerOutputs = getLayerOutputs(inputs[p]);
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
					//					yObtained = getOutput(inputs[p]);
					//					double diff;
					//					for(size_t neuron = 0; neuron < nOutputs; neuron++){
					//						diff = (targets[p][neuron] - yObtained[neuron]);
					//						pMSE += diff*diff;
					//					}
				}
				tr.RMSE = getRMSE(inputs, targets);
				tr.RMSEHistory.push_back(tr.RMSE);

				tr.MSE = getMSE(inputs, targets);
				tr.MSEHistory.push_back(tr.MSE);
				//		tr.layerWeightsHistory.push_back(layerWeights);
				//		tr.outputWeightsHistory.push_back(outputWeights);
				//		epc++;
				tr.epochs++;
			}while(tr.MSE >= errormin && tr.epochs < epochs && training);
			break;

		case SimulatedAnnealing:{

			long double
					T = 0,
					sumDeltaF = 0,
					deltaF = 0,
					Pa = 0;

			int c = 0;
			do{
				//		tr.MSE = 0;
				pMSE = 0;
				for(size_t p = 0; p < nPatterns; p++){

					//Se obtienen las salidas para cada una de las capas
					layerOutputs = getLayerOutputs(inputs[p]);
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
				tr.RMSE = getRMSE(inputs, targets);
				tr.RMSEHistory.push_back(tr.RMSE);

				pMSE = getMSE(inputs, targets);

				deltaF = pMSE - tr.MSE;
				sumDeltaF += deltaF; // Se calcula deltaF promedio
				c++;

				tr.MSE = pMSE;
				tr.MSEHistory.push_back(tr.MSE);
				//		tr.layerWeightsHistory.push_back(layerWeights);
				//		tr.outputWeightsHistory.push_back(outputWeights);
				//		epc++;

				double avgDeltaF = sumDeltaF / c;

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
					double fOld = tr.MSE;
					double rnd = 0;
					do{
						for(int i = 0; i < nChanges; i++){
							ns = addNoise(minNoise, maxNoise);
							fNew = getNewMSE(ns.newWeights, ns.newOutputWeights, inputs, targets);
							deltaF = fNew - fOld;
							Pa = exp(-deltaF/T);
							rnd = randomNumber(0,1);
							if(deltaF < 0
							   || rnd < Pa
							   ){
								layerWeights = ns.newWeights;
								outputWeights = ns.newOutputWeights;
								fOld = getMSE(inputs, targets);
							}
						}
						//						T = T / (1 + n);
						T = tempDecFactor*T;
						//						n++;
					}while(T > Tmin);
					c = 0;
					sumDeltaF = 0;
				}

				tr.epochs++;
			}while(tr.MSE >= errormin && tr.epochs < epochs && training);
			break;
		}
		case GradientDescendent:
			break;
		case ScaledConjugateGradient:
			break;
	}

	tr.time = double(clock() - t_ini)/CLOCKS_PER_SEC;

	return tr;
}

MultilayerPerceptron::TrainingResult MultilayerPerceptron::getTrainingSnapshot()
{
	return tr;
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

void MultilayerPerceptron::setSAParameters(double minTemperature, int numberOfChanges, double sCondition, double To, double minNoise, double maxNoise, double tdf)
{
	Tmin = minTemperature;
	nChanges = numberOfChanges;
	startCondition = sCondition;
	this->To = To;
	this->minNoise = minNoise;
	this->maxNoise = maxNoise;
	tempDecFactor = tdf;
}

double MultilayerPerceptron::getMSE(const vector<vector<double> > &inputs, const vector<vector<double> > &targets)
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
	return sqrt(pMSE)/(nPatterns*nOutputs);
}

