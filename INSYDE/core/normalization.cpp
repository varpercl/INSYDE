#include "normalization.h"

Normalization::Normalization() :
	QObject()
{
	init(Nothing, 999999999, -999999999, 0, 1, 1);
}

Normalization::Normalization(Type nt, double max, double min, double threshold, double amp, double elong) :
	QObject()
{
	init(nt, max, min, threshold, amp, elong);
}

Normalization::Normalization(const Normalization &nor) :
	QObject()
{
	*this = nor;
}

Normalization::~Normalization()
{

}

void Normalization::setType(Normalization::Type nt)
{
	if(norType != nt){
		norType = nt;

		emit typeChanged((int)nt);
	}
}

Normalization::Type Normalization::getType() const
{
	return norType;
}

void Normalization::setMaxValue(double max)
{
	if(maxValue != max){
		maxValue = max;

		emit maxValueChanged(max);
	}
}

double Normalization::getMaxValue() const
{
	return maxValue;
}

void Normalization::setMinValue(double min)
{
	if(minValue != min){
		minValue = min;

		emit minValueChanged(min);
	}
}

double Normalization::getMinValue() const
{
	return minValue;
}

void Normalization::setThreshold(double threshold)
{
	if(this->threshold != threshold){
		this->threshold = threshold;

		emit thresholdChanged(threshold);
	}
}

double Normalization::getThreshold() const
{
	return threshold;
}

void Normalization::setAmplitude(double amp)
{
	if(amplitude != amp){
		amplitude = amp;

		emit amplitudeChanged(amp);
	}
}

double Normalization::getAmplitude() const
{
	return amplitude;
}

void Normalization::setElongation(double elong)
{
	if(elongation != elong){
		elongation = elong;

		emit elongationChanged(elong);
	}
}

double Normalization::getElongation() const
{
	return elongation;
}

QString Normalization::getName() const
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

Normalization &Normalization::operator=(const Normalization &nor)
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

bool Normalization::operator==(const Normalization &param1)
{
	return (param1.getMaxValue() == this->getMaxValue() &&
			param1.getMinValue() == this->getMinValue() &&
			param1.getThreshold() == this->getThreshold() &&
			param1.getElongation() == this->getElongation() &&
			param1.getAmplitude() == this->getAmplitude() &&
			param1.getType() == this->getType() &&
			param1.getName() == this->getName());
}

bool Normalization::operator!=(const Normalization &param1)
{
	return !(param1.getMaxValue() == this->getMaxValue() &&
			 param1.getMinValue() == this->getMinValue() &&
			 param1.getThreshold() == this->getThreshold() &&
			 param1.getElongation() == this->getElongation() &&
			 param1.getAmplitude() == this->getAmplitude() &&
			 param1.getType() == this->getType() &&
			 param1.getName() == this->getName());
}

void Normalization::init(Normalization::Type nt, double max, double min, double threshold, double amp, double elong)
{
	setType(nt);
	setMaxValue(max);
	setMinValue(min);
	setThreshold(threshold);
	setAmplitude(amp);
	setElongation(elong);
}
