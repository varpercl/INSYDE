#include "adalinetrainingpattern.h"
namespace ann_base{

AdalineTrainingPattern::AdalineTrainingPattern(int ninputs) :
	SimpleInputPattern(ninputs)
{
	output = 0;
}

AdalineTrainingPattern::AdalineTrainingPattern(const vector<double> &inputs, double output) :
	SimpleInputPattern(inputs)
{
	this->output = output;
}

void AdalineTrainingPattern::setOutput(double out)
{
	output = out;
}

double AdalineTrainingPattern::getOutput() const
{
	return output;
}

}
