#include "mlppattern.h"
using namespace ann_base;

MultilayerPerceptronPattern::MultilayerPerceptronPattern(int ninputs, int ntargets) :
	SimpleInputPattern(ninputs)
{
	init(ntargets);
}

MultilayerPerceptronPattern::MultilayerPerceptronPattern(vector<double> inputs, vector<double> targets) :
	SimpleInputPattern(inputs)
{
	init(targets);
}

MultilayerPerceptronPattern::MultilayerPerceptronPattern(double *inputs, size_t sinputs, double *targets, size_t stargets) :
	SimpleInputPattern(inputs, sinputs)
{
	init(targets, stargets);
}

void MultilayerPerceptronPattern::setTargets(double *v, size_t s)
{

	targets.assign(v, v + s);
}

void MultilayerPerceptronPattern::setTargets(vector<double> targets)
{
	this->targets = targets;
}

vector<double> MultilayerPerceptronPattern::getTargets()
{
	return targets;
}

void MultilayerPerceptronPattern::init(int ntargets)
{
	targets.resize(ntargets);
}

void MultilayerPerceptronPattern::init(vector<double> targets)
{
	this->targets = targets;
}

void MultilayerPerceptronPattern::init(double *targets, size_t s)
{
	setTargets(targets, s);
}
