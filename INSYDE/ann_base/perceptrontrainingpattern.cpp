#include "perceptrontrainingpattern.h"
using namespace ann_base;

PerceptronTrainingPattern::PerceptronTrainingPattern(int ninputs) :
	SimpleInputPattern(ninputs)
{
	output = false;
}

PerceptronTrainingPattern::PerceptronTrainingPattern(const vector<double> &inputs, bool output) :
	SimpleInputPattern(inputs)
{
	this->output = output;
}

void PerceptronTrainingPattern::setOutput(bool out)
{
	output = out;
}

bool PerceptronTrainingPattern::getOutput() const
{
	return output;
}
