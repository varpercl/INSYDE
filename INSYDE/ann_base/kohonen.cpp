#include "kohonen.h"

using namespace ann_base;

Kohonen::Kohonen()
//	:
//	ArtificialNeuralNetwork(1, 1) //TODO: define
{

}

Kohonen::~Kohonen()
{

}

ArtificialNeuralNetwork::Type Kohonen::getType() const
{
	return ArtificialNeuralNetwork::Kohonen;
}

QString Kohonen::getName() const
{
	return "Kohonen";
}

void Kohonen::randomizeWeights(double min, double max)
{
	//TODO: 17/4/16 randomizeWeights implement
	(void)min;
	(void)max;
}

int Kohonen::getOutputSize() const
{
	return 1;
}

int Kohonen::getInputSize() const
{
	return 1;
}

void Kohonen::setInputSize(int )
{

}

void Kohonen::setOutputSize(int )
{

}

