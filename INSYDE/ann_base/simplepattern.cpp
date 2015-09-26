#include "simplepattern.h"
using namespace ann_base;

SimpleInputPattern::SimpleInputPattern(int ninputs)
{
	inputs.resize(ninputs);
}

SimpleInputPattern::SimpleInputPattern(const vector<double> &inputs)
{
	this->inputs  = inputs;
}

SimpleInputPattern::SimpleInputPattern(double *inputs, size_t s)
{
	setInputs(inputs, s);
}

void SimpleInputPattern::setInputs(const vector<double> &inputs)
{
	this->inputs = inputs;
}

void SimpleInputPattern::setInputs(double *inputs, size_t s)
{
	this->inputs.assign(inputs, inputs + s);
}

vector<double> &SimpleInputPattern::getInputs()
{
	return inputs;
}
