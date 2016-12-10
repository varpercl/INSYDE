#include "artificialneuralnetwork.h"
using namespace ann_base;

ArtificialNeuralNetwork::ArtificialNeuralNetwork()
{

}

ArtificialNeuralNetwork::Type ArtificialNeuralNetwork::getType() const
{
	return NoType;
}

QString ArtificialNeuralNetwork::getName() const
{
	return "NoType";
}

