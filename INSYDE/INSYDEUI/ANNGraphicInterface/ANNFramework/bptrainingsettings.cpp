#include "backpropagationtrainingsettings.h"
BackpropagationSettings::BackpropagationSettings()
{
	init(0,0,0,0,0, MSE);
}

BackpropagationSettings::BackpropagationSettings(unsigned int epochs, double MSEmin, double RMSEmin, double CEmin, double learningRate, StopCondition sp)
{
	init(epochs, MSEmin, RMSEmin, CEmin, learningRate, sp);
}

BackpropagationSettings::BackpropagationSettings(unsigned int epochs, StopCondition em, double emValue, double learningRate)
{
	init(epochs, em, emValue, learningRate);
}

void BackpropagationSettings::setMaxEpochs(unsigned int epochs)
{
	this->epochs = epochs;
}

unsigned int BackpropagationSettings::getMaxEpochs() const
{
	return epochs;
}

void BackpropagationSettings::setMinMSE(double msemin)
{
	MSEmin = msemin;
}

double BackpropagationSettings::getMinMSE() const
{
	return MSEmin;
}

void BackpropagationSettings::setMinRMSE(double rmsemin)
{
	RMSEmin = rmsemin;
}

double BackpropagationSettings::getMinRMSE() const
{
	return RMSEmin;
}

void BackpropagationSettings::setMinCE(double cemin)
{
	CEmin = cemin;
}

double BackpropagationSettings::getMinCE() const
{
	return CEmin;
}

void BackpropagationSettings::setLearningRate(double lr)
{
	learningRate = lr;
}

double BackpropagationSettings::getLearningRate() const
{
	return learningRate;
}

void BackpropagationSettings::setStopParameter(StopCondition em)
{
	this->em = em;
}

BackpropagationSettings BackpropagationSettings::operator=(const BackpropagationSettings &mlpbp)
{
	setLearningRate(mlpbp.getLearningRate());
	setMaxEpochs(mlpbp.getMaxEpochs());
	setMinCE(mlpbp.getMinCE());
	setMinMSE(mlpbp.getMinMSE());
	setMinRMSE(mlpbp.getMinRMSE());
	setStopParameter(mlpbp.getStopCondition());
	return *this;
}

void BackpropagationSettings::init(unsigned int epochs, double MSEmin, double RMSEmin, double CEmin, double learningRate, StopCondition em)
{
	setMaxEpochs(epochs);
	setMinMSE(MSEmin);
	setMinRMSE(RMSEmin);
	setMinCE(CEmin);
	setLearningRate(learningRate);
	setStopParameter(em);
}

void BackpropagationSettings::init(unsigned int epochs, StopCondition em, double emValue, double learningRate)
{
	setMaxEpochs(epochs);
	setStopParameter(em);
	setMinMSE(emValue);
	setMinRMSE(emValue);
	setMinCE(emValue);
//	setStopParameterValue(emValue);
	setLearningRate(learningRate);
}

StopCondition BackpropagationSettings::getStopCondition() const
{
	return em;
}
