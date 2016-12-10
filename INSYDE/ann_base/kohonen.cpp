#include "kohonen.h"

namespace ann_base{

Kohonen::Kohonen()
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

}
