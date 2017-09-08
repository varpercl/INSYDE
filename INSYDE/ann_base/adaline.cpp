#include "adaline.h"

using namespace core::math;

namespace ann_base{

void Adaline::init(int ninputs, double *weights, TransferFunctionType ft){
	setWeights(ninputs, weights);
	setAlfa(1);
	setThreshold(getRandomValues(1)[0]);
	setTransferFunction(ft);
}

void Adaline::init(int ninputs, TransferFunctionType ft)
{
	if(ninputs > 0){
		setAlfa(1);
		setInputSize(ninputs);
		setTransferFunction(ft);
	}else{
		qWarning()<<"Se debe asignar al menos una entrada a un perceptron simple";
	}
}

void Adaline::init(const vector<double> &weights, TransferFunctionType tf)
{
	size_t sWeights = weights.size();
	if(sWeights > 0){
		setWeights(weights);
		setAlfa(1);
		setThreshold(getRandomValues(1)[0]);
		setTransferFunction(tf);
	}else{
		qWarning() << "Se debe asignar al menos una entrada a un perceptron simple";
	}
}

Adaline::Adaline(int ninputs, TransferFunctionType tf)
//	:
//	ArtificialNeuralNetwork(ninputs, 1)
{
	init(ninputs, tf);
}

Adaline::Adaline(int ninputs, double *weights, Adaline::TransferFunctionType tf)
//	:
//	ArtificialNeuralNetwork(ninputs, 1)
{
	init(ninputs, weights, tf);
}


Adaline::Adaline(const vector<double> &weights, TransferFunctionType tf)
//	:
//	ArtificialNeuralNetwork((int) weights.size(), 1)
{
	init(weights, tf);
}

Adaline::~Adaline()
{

}

void Adaline::setInputSize(int n)
{
	if(n != (int) weights.size()){
		setWeights(getRandomValues((int)n));
		setThreshold(getRandomValues(1)[0]);
	}else{
		qWarning("No se realizo cambio alguno porque el numero de entradas no vario");
	}
}

int Adaline::getNumberInputs()
{
	return (int)weights.size();
}

void Adaline::setWeights(double *w)
{
	int sInputs = (int)weights.size();
	for(int i = 0; i < sInputs; i++){
		weights.push_back(w[i]);
	}
}

void Adaline::setWeights(int ninputs, double *w)
{
	weights.resize(ninputs, 0);
	for(int i = 0; i < ninputs; i++){
		weights[i] = w[i];
	}
}

void Adaline::setWeights(const vector<double> &w)
{
	weights = w;
}

void Adaline::setWeight(int n, double value)
{
	weights[n] = value;
}

double *Adaline::getWeights()
{
	return &weights[0];
}

vector<double> Adaline::getWeightVector(){
	return weights;
}

void Adaline::setThreshold(double value)
{
	this->threshold = value;
}

double Adaline::getThreshold()
{
	return threshold;
}

void Adaline::setTransferFunction(TransferFunctionType tf)
{
	this->tf = tf;
}

Adaline::TransferFunctionType Adaline::getTransferFunction()
{
	return tf;
}

double Adaline::getOutput(const vector<double> &data)
{
	double sum = 0;
	size_t sData = data.size();
	if(sData == weights.size()){
		for(unsigned int i = 0; i < sData; i++){
			sum += weights[i]*data[i];
		}
		sum += threshold;
		switch(tf){
			case Sigmoid:
				return 1 / (1 + exp(-alfa*sum));
				break;
			case Linear:
				return alfa*sum;
				break;
		}
	}else{
		qWarning("El numero de entradas de datos no corresponde con el numero de pesos");
	}
	return 0;
}

void Adaline::randomizeWeights(double min, double max)
{
	setWeights(getRandomValues((int)weights.size(), min, max));
	threshold = getRandomValues(1, min, max)[0];
}

void Adaline::setAlfa(double value)
{
	if(value >= 0 && value <= 1){
		alfa = value;
	}else if(value < 0){
		alfa = 0;
	}else{
		alfa = 1;
	}
}

double Adaline::getAlfa()
{
	return alfa;
}

ArtificialNeuralNetwork::Type Adaline::getType() const
{
	return ArtificialNeuralNetwork::Adaline;
}

QString Adaline::getName() const
{
	return "adaline";
}

int Adaline::getInputSize() const
{
	return (int) weights.size();
}

Adaline::TrainResult Adaline::train(const vector<vector<double> > &inputs, const vector<double> &targets, double error, int nEpochs, double learningFactor, Adaline::WeightUpdateType wut)
{
	size_t sTrainingSet = inputs.size();
	size_t nInputs = weights.size();

	double delta;
	double currErr = 0;
	double out;
	double dsigma = 0;
	int curEpoch = 0;
	vector<double> deltaW;
	double deltaThreshold;

	Adaline::TrainResult tr;
	tr.epochs = 0;
	tr.errorHistory.push_back(0);
	tr.weightHistory.push_back(weights);
	tr.thresholdHistory.push_back(threshold);
	do {
		currErr = 0;
		deltaW = vector<double>(nInputs, 0);
		deltaThreshold = 0;
		for (size_t i = 0; i < sTrainingSet; i++) {

			out = getOutput(inputs[i]);
			switch(tf){
				case Linear:
					dsigma = 1;
					break;
				case Sigmoid:
					dsigma = out * (1 - out);
					break;
			}
			delta = targets[i] - out;
			currErr += delta * delta;

			/*
			  Actualizamos los pesos
			 */
			switch(wut){
				case BatchUpdate:
					for(size_t j = 0; j < nInputs; j++){
						deltaW[j] += learningFactor*delta*dsigma*inputs[i][j];
					}
					deltaThreshold += learningFactor*delta*dsigma;
					break;
				case ContinuousUpdate:
					for(size_t j = 0; j < nInputs; j++){
						weights[j] += learningFactor*delta*dsigma*inputs[i][j];
					}
					threshold += learningFactor*delta*dsigma;
			}


		}
		switch(wut){
			case BatchUpdate:
				for(size_t j = 0; j < nInputs; j++){
					weights[j] += deltaW[j];
				}
				threshold += deltaThreshold;
				break;
			case ContinuousUpdate:
				break;
		}

		curEpoch++;
		tr.epochs = curEpoch;
		tr.errorHistory.push_back(currErr);
		tr.weightHistory.push_back(weights);
		tr.thresholdHistory.push_back(threshold);
	} while (currErr >= error && tr.epochs < nEpochs);

	return tr;
}

Adaline::TrainResult Adaline::train(vector<AdalineTrainingPattern> &ts, double error, int nEpochs, double learningFactor, Adaline::WeightUpdateType wut)
{
	(void)wut;

	size_t sTS = ts.size();
	vector<vector<double> > inputs(sTS);
	vector<double> outputs(sTS);

	for(size_t i = 0; i < sTS; i++){
		inputs[i] = ts[i].getInputs();
		outputs[i] = ts[i].getOutput();
	}
	return train(inputs, outputs, error, nEpochs, learningFactor);
}

}
