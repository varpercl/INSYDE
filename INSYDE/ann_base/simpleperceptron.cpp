#include "simpleperceptron.h"

using namespace ann_base;
using namespace math;

void SimplePerceptron::init(int ninputs, double *weights, TransferFunctionType ft, LearningRule lr){
	setWeights(ninputs, weights);
	setAlfa(1);
	setThreshold(getRandomValues(1)[0]);
	setTransferFunction(ft);
	setLearningRule(lr);
}

void SimplePerceptron::init(int ninputs, TransferFunctionType ft, LearningRule lr)
{
	if(ninputs > 0){
		setAlfa(1);
		setInputSize(ninputs);
		setTransferFunction(ft);
		setLearningRule(lr);
	}else{
		qWarning()<<"Se debe asignar al menos una entrada a un perceptron simple";
	}
}

void SimplePerceptron::init(vector<double> weights, TransferFunctionType tf, LearningRule lr)
{
	size_t sWeights = weights.size();
	if(sWeights > 0){
		setWeights(weights);
		setAlfa(1);
		setThreshold(getRandomValues(1)[0]);
		setTransferFunction(tf);
		setLearningRule(lr);
	}else{
		qWarning() << "Se debe asignar al menos una entrada a un perceptron simple";
	}
}

SimplePerceptron::SimplePerceptron(int ninputs, TransferFunctionType tf, LearningRule lr)
{
	init(ninputs, tf, lr);
}

SimplePerceptron::SimplePerceptron(int ninputs, double *weights, TransferFunctionType ft, LearningRule lr)
{
	init(ninputs, weights, ft, lr);
}

SimplePerceptron::SimplePerceptron(vector<double> weights, TransferFunctionType tf, LearningRule lr)
{
	init(weights, tf, lr);
}

void SimplePerceptron::setInputSize(size_t n)
{
	if(n != weights.size()){
		setWeights(getRandomValues((int)n));
		setThreshold(getRandomValues(1)[0]);
	}else{
		qWarning("No se realizo cambio alguno porque el numero de entradas no vario");
	}
}

int SimplePerceptron::getInputSize()
{
	return (int)weights.size();
}

void SimplePerceptron::setWeights(double *w)
{
	int sInputs = (int)weights.size();
	for(int i = 0; i < sInputs; i++){
		weights[i] = w[i];
	}
}

void SimplePerceptron::setWeights(int ninputs, double *w)
{
	weights.resize(ninputs, 0);
	for(int i = 0; i < ninputs; i++){
		weights[i] = w[i];
	}
}

void SimplePerceptron::setWeights(const vector<double> &w)
{
	weights = w;
}

void SimplePerceptron::setWeight(int pos, double value)
{
	weights[pos] = value;
}

double *SimplePerceptron::getWeights()
{
	return &weights[0];
}

vector<double> SimplePerceptron::getWeightsVector(){
	return weights;
}


void SimplePerceptron::setThreshold(double value)
{
	this->threshold = value;
}

double SimplePerceptron::getThreshold()
{
	return threshold;
}

void SimplePerceptron::setTransferFunction(SimplePerceptron::TransferFunctionType tf)
{
	this->tf = tf;
}

SimplePerceptron::TransferFunctionType SimplePerceptron::getTransferFunction()
{
	return tf;
}

bool SimplePerceptron::getOutput(const vector<double> &inputs)
{
	double out = 0;
	double sum = 0;
	size_t sData = inputs.size();
//    if(sData == weights.size()){
		for(unsigned int i = 0; i < sData; i++){
			sum += weights[i]*inputs[i];
		}
		sum -= threshold;
		switch(tf){
			case Step:
				if(sum >= 0)
					return true;
				else
					return false;
			case Bipolar:
				if(sum > 0)
					out = 1;
				else if (sum == 0)
					out = 0;
				else
					out = -1;
				break;
			case Sigmoid:
				return (1/(1 + exp(-alfa*sum))) > 0.5 ? true : false;
			case Tanh:
				out = (1 - exp(-alfa*sum))/(1 + exp(-alfa*sum));
				break;
			case Linear:
				out = sum;
				break;
			case LimitedLinear:
				if(sum < 0)
					out = 0;
				else if(sum >= 0 && sum <= 1)
					out = alfa*sum;
				else
					out = 1;
				return out > 0.5 ? true : false;
			case SimetricLimitedLinear:
				if(sum < -1)
					out = -1;
				else if(sum >= -1 && sum <= 1)
					out = alfa*sum;
				else
					out = 1;
				break;
		}
		return out > 0 ? true : false;
//    }else{
//        qWarning("El numero de entradas de datos no corresponde con el numero de pesos");
//        return 0;
//    }
}

void SimplePerceptron::setLearningRule(SimplePerceptron::LearningRule lr)
{
	this->lr = lr;
}

SimplePerceptron::LearningRule SimplePerceptron::getLearningRule()
{
	return lr;
}

void SimplePerceptron::randomizeWeights()
{
	setWeights(getRandomValues((int)weights.size()));
	threshold = getRandomValues(1)[0];
}

void SimplePerceptron::setAlfa(double value)
{
	if(value >= 0 && value <= 1){
		alfa = value;
	}else if(value < 0){
		alfa = 0;
	}else{
		alfa = 1;
	}
}

double SimplePerceptron::getAlfa()
{
	return alfa;
}

ArtificialNeuralNetwork::Type SimplePerceptron::getType() const
{
	return ArtificialNeuralNetwork::SimplePerceptron;
}

void SimplePerceptron::randomizeWeights(double min, double max)
{
	(void)min;
	(void)max;
	//TODO: 5/9/15 randomizeWeights must be implemented
}

SimplePerceptron::TrainResult SimplePerceptron::train(const vector<vector<double> > &inputs, const vector<bool> &targets, int epochs, int nEpochsAfterNoChange, double learningFactor)
{
	size_t sTrainingSet = inputs.size();
	size_t nInputs =  weights.size();

	//Valor de actualizacion del peso actual
	double deltaW;

	//Error actual
	int e = 0;

	//Numero de Pesos Sinapticos actualizados
	int nUpdatedWeights = 0;

	//Contador que se incrementa cada vez que no se actualiza ningun peso sinaptico
	int notUpdatedWeightsCounter = 0;

	//Resultado del entrenamiento
	SimplePerceptron::TrainResult tr;

	tr.epochs = 0;
	tr.changedWeights.push_back(0);
	tr.weightHistory.push_back(weights);
	tr.thresholdHistory.push_back(threshold);
	do{
		//Presenta el conjunto de entrenamiento al perceptron
		for(size_t i = 0; i < sTrainingSet; i++){
			switch(lr){
				case SimpleRule:
					learningFactor = 1;
				case DeltaRule:
					if(targets[i] == getOutput(inputs[i])){
						e = 0;
					}else if(targets[i] && !getOutput(inputs[i])){
						e = 1;
					}else if(!targets[i] && getOutput(inputs[i])){
						e = -1;
					}
//                    e = targets[i] - getOutput(inputs[i]);
					if(e != 0){
						for(size_t j = 0; j <= nInputs; j++){
							if(j != nInputs)
								deltaW = e * learningFactor * inputs[i][j];
							else{
								deltaW = - e * learningFactor;
							}
							if(deltaW != 0){
								nUpdatedWeights++;
								if(j == nInputs){
									threshold += deltaW;
								}else{
									weights[j] += deltaW;
								}
							}
						}
					}
					break;
			}
		}
		tr.changedWeights.push_back(nUpdatedWeights);
		tr.weightHistory.push_back(weights);
		tr.thresholdHistory.push_back(threshold);
		tr.epochs++;

		if(nUpdatedWeights == 0){
			notUpdatedWeightsCounter++;
		}else{
			notUpdatedWeightsCounter = 0;
		}
		nUpdatedWeights = 0;
		/*
		  Itera hasta que haya un numero determinado de epocas sin cambios en los pesos
		  o hasta que un numero fijo de epocas haya transcurrido
		  */
	}while(notUpdatedWeightsCounter < nEpochsAfterNoChange && tr.epochs < epochs);

	//Retorna la estructura que contiene informacion sobre el entrenamiento
	return tr;
}

ann_base::SimplePerceptron::TrainResult ann_base::SimplePerceptron::train(vector<ann_base::PerceptronTrainingPattern> &ts, int epochs, int nEpochsAfterNoChange, double learningFactor)
{
	size_t sTS = ts.size();
	vector<vector<double> > inputs(sTS);
	vector<bool> outputs(sTS);

	for(size_t i = 0; i < sTS; i++){
		inputs[i] = ts[i].getInputs();
		outputs[i] = ts[i].getOutput();
	}

	return train(inputs, outputs, epochs, nEpochsAfterNoChange, learningFactor);
}


