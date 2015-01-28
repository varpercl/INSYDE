#include "adaline.h"

void Adaline::initADALINE(int ninputs, double *weights, TransferFunctionType ft){
	setWeights(ninputs, weights);
	setAlfa(1);
	setThreshold(getRandomValues(1)[0]);
	setTransferFunction(ft);
}

void Adaline::initADALINE(int ninputs, TransferFunctionType ft)
{
	if(ninputs > 0){
		setAlfa(1);
		setNumberInputs(ninputs);
		setTransferFunction(ft);
	}else{
		qWarning()<<"Se debe asignar al menos una entrada a un perceptron simple";
	}
}

void Adaline::initADALINE(const vector<double> &weights, TransferFunctionType tf)
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
{
	initADALINE(ninputs, tf);
}

Adaline::Adaline(int ninputs, double *weights, Adaline::TransferFunctionType tf)
{
	initADALINE(ninputs, weights, tf);
}


Adaline::Adaline(const vector<double> &weights, TransferFunctionType tf)
{
	initADALINE(weights, tf);
}

void Adaline::setNumberInputs(size_t n)
{
	if(n != weights.size()){
		setWeights(getRandomValues(n));
		setThreshold(getRandomValues(1)[0]);
	}else{
		qWarning("No se realizo cambio alguno porque el numero de entradas no vario");
	}
}

int Adaline::getNumberInputs()
{
	return weights.size();
}

void Adaline::setWeights(double *w)
{
	int sInputs = weights.size();
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

void Adaline::setWeight(int pos, double value)
{
	weights[pos] = value;
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

void Adaline::randomizeWeights()
{
	setWeights(getRandomValues(weights.size()));
	threshold = getRandomValues(1)[0];
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
	Q_UNUSED(wut);

	size_t sTS = ts.size();
	vector<vector<double> > inputs(sTS);
	vector<double> outputs(sTS);

	for(size_t i = 0; i < sTS; i++){
		inputs[i] = ts[i].getInputs();
		outputs[i] = ts[i].getOutput();
	}
	return train(inputs, outputs, error, nEpochs, learningFactor);
}

AdalineTrainingPattern::AdalineTrainingPattern(int ninputs) :
	SimpleInputPattern(ninputs)
{
	output = 0;
}

AdalineTrainingPattern::AdalineTrainingPattern(const vector<double> &inputs, double output) :
	SimpleInputPattern(inputs)
{
	this->output = output;
}

void AdalineTrainingPattern::setOutput(double out)
{
	output = out;
}

double AdalineTrainingPattern::getOutput() const
{
	return output;
}

