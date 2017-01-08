#include "normalization.h"

core::Normalization::Normalization() :
	QObject()
{
	init(Nothing, 999999999, -999999999, 0, 1, 1);
}

core::Normalization::Normalization(Type nt, double max, double min, double threshold, double amp, double elong) :
	QObject()
{
	init(nt, max, min, threshold, amp, elong);
}

core::Normalization::Normalization(const Normalization &nor) :
	QObject()
{
	*this = nor;
}

core::Normalization::~Normalization()
{

}

void core::Normalization::setType(Normalization::Type nt)
{
	if(norType != nt){
		norType = nt;

		emit typeChanged((int)nt);
	}
}

core::Normalization::Type core::Normalization::getType() const
{
	return norType;
}

void core::Normalization::setMaxValue(double max)
{
	if(maxValue != max){
		maxValue = max;

		emit maxValueChanged(max);
	}
}

double core::Normalization::getMaxValue() const
{
	return maxValue;
}

void core::Normalization::setMinValue(double min)
{
	if(minValue != min){
		minValue = min;

		emit minValueChanged(min);
	}
}

double core::Normalization::getMinValue() const
{
	return minValue;
}

void core::Normalization::setThreshold(double threshold)
{
	if(this->threshold != threshold){
		this->threshold = threshold;

		emit thresholdChanged(threshold);
	}
}

double core::Normalization::getThreshold() const
{
	return threshold;
}

void core::Normalization::setAmplitude(double amp)
{
	if(amplitude != amp){
		amplitude = amp;

		emit amplitudeChanged(amp);
	}
}

double core::Normalization::getAmplitude() const
{
	return amplitude;
}

void core::Normalization::setElongation(double elong)
{
	if(elongation != elong){
		elongation = elong;

		emit elongationChanged(elong);
	}
}

double core::Normalization::getElongation() const
{
	return elongation;
}

QString core::Normalization::getName() const
{
	switch(norType){
		default:
		case Normalization::Nothing:
			return "Nothing";
		case Normalization::BipolarFixedThreshold:
			return "BipolarFixedThreshold";
		case Normalization::BipolarAutoThreshold:
			return "BipolarAutoThreshold";
		case Normalization::UnipolarFixedThreshold:
			return "UnipolarFixedThreshold";
		case Normalization::UnipolarAutoThreshold:
			return "UnipolarAutoThreshold";
		case Normalization::LinearFixedRange:
			return "LinearFixedRange";
		case Normalization::LinearAutoRange:
			return "LinearAutoRange";
		case Normalization::Tanh:
			return "Tanh";
		case Normalization::Sigmoid:
			return "Sigmoid";
		case Normalization::MeanDistance:
			return "MeanDistance";
	}
}

core::Normalization &core::Normalization::operator=(const Normalization &nor)
{
	if(this != &nor){
		setMaxValue(nor.getMaxValue());
		setMinValue(nor.getMinValue());
		setThreshold(nor.getThreshold());
		setType(nor.getType());
		setAmplitude(nor.getAmplitude());
		setElongation(nor.getElongation());
	}
	return *this;
}

bool core::Normalization::operator==(const Normalization &param1)
{
	return (param1.getMaxValue() == this->getMaxValue() &&
			param1.getMinValue() == this->getMinValue() &&
			param1.getThreshold() == this->getThreshold() &&
			param1.getElongation() == this->getElongation() &&
			param1.getAmplitude() == this->getAmplitude() &&
			param1.getType() == this->getType() &&
			param1.getName() == this->getName());
}

bool core::Normalization::operator!=(const Normalization &param1)
{
	return !(param1.getMaxValue() == this->getMaxValue() &&
			 param1.getMinValue() == this->getMinValue() &&
			 param1.getThreshold() == this->getThreshold() &&
			 param1.getElongation() == this->getElongation() &&
			 param1.getAmplitude() == this->getAmplitude() &&
			 param1.getType() == this->getType() &&
			 param1.getName() == this->getName());
}

void core::Normalization::init(Normalization::Type nt, double max, double min, double threshold, double amp, double elong)
{
	setType(nt);
	setMaxValue(max);
	setMinValue(min);
	setThreshold(threshold);
	setAmplitude(amp);
	setElongation(elong);
}
