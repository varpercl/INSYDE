#include "simpleinputpattern.h"
using namespace ann_base;

SimpleInputPattern::SimpleInputPattern()
{

}

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

SimpleInputPattern::SimpleInputPattern(const SimpleInputPattern &copy)
{
	(void) copy;
}

SimpleInputPattern::~SimpleInputPattern()
{

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

//SimpleInputPattern &SimpleInputPattern::operator==(const SimpleInputPattern &va)
//{
//	//TODO: Must be implemented
//	(void)va;
//	return SimpleInputPattern(va);
//}
