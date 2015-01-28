#include "itrainingset.h"

void ITrainingSet::setInputsNormalization(const Normalization &nor)
{
	inputsNormalization = nor;
}

Normalization ITrainingSet::getInputsNormalization() const
{
	return inputsNormalization;
}

void ITrainingSet::setTargetsNormalization(const Normalization &nor)
{
	targetsNormalization = nor;
}

Normalization ITrainingSet::getTargetsNormalization() const
{
	return targetsNormalization;
}
