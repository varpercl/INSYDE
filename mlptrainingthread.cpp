#include "mlptrainingthread.h"

MLPTrainingThread::MLPTrainingThread(MultilayerPerceptron *mlp, const vector<vector<double> > &inputs, const vector<vector<double> > &targets, unsigned int epochs, double errormin, double learningRate, MultilayerPerceptron::TrainingAlgorithm ta, QObject *parent) :
	QThread(parent)
{
	this->inputs = inputs;
	this->targets = targets;
	this->epochs = epochs;
	this->errormin = errormin;
	this->learningRate = learningRate;
	this->ta = ta;

	this->mlp = mlp;
}


MLPTrainingThread::MLPTrainingThread(MultilayerPerceptron *mlp, QObject *parent):
	QThread(parent)
{
	this->mlp = mlp;
}

void MLPTrainingThread::run()
{
	mlp->startTraining(inputs, targets, epochs, errormin, learningRate, ta);
}

void MLPTrainingThread::setTrainingParameters(const vector<vector<double> > &inputs, const vector<vector<double> > &targets, unsigned int epochs, double errormin, double learningRate, MultilayerPerceptron::TrainingAlgorithm ta)
{
	this->inputs = inputs;
	this->targets = targets;
	this->epochs = epochs;
	this->errormin = errormin;
	this->learningRate = learningRate;
	this->ta = ta;
}

MultilayerPerceptron::TrainingResult MLPTrainingThread::getTrainingSnapshot()
{
	return mlp->getTrainingSnapshot();
}
