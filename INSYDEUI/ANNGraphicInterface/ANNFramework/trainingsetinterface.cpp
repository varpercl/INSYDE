#include "trainingsetinterface.h"

void ITrainingSet::setNormalization(const Normalization &nor)
{
	inputsNorm = nor;
}

Normalization ITrainingSet::getNormalization() const
{
	return inputsNorm;
}
