#include "normalization.h"

Normalization::Normalization()
{
	setType(LinearAutoRange);
	setMaxValue(999999999);
	setMinValue(-999999999);
	setThreshold(0);
	setAmplitude(1);
	setElongation(1);
}

Normalization::Normalization(Type nt, double max, double min, double threshold, double amp, double elong)
{
	setType(nt);
	setMaxValue(max);
	setMinValue(min);
	setThreshold(threshold);
	setAmplitude(amp);
	setElongation(elong);
}

void Normalization::setType(Normalization::Type nt)
{
	norType = nt;
}

Normalization::Type Normalization::getType() const
{
	return norType;
}

void Normalization::setMaxValue(double max)
{
	maxValue = max;
}

double Normalization::getMaxValue() const
{
	return maxValue;
}

void Normalization::setMinValue(double min)
{
	minValue = min;
}

double Normalization::getMinValue() const
{
	return minValue;
}

void Normalization::setThreshold(double threshold)
{
	this->threshold = threshold;
}

double Normalization::getThreshold() const
{
	return threshold;
}

void Normalization::setAmplitude(double amp)
{
	amplitude = amp;
}

double Normalization::getAmplitude() const
{
	return amplitude;
}

void Normalization::setElongation(double elong)
{
	elongation = elong;
}

double Normalization::getElongation() const
{
	return elongation;
}

QString Normalization::getNormalizationName() const
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

Normalization Normalization::operator=(const Normalization &nor)
{
//	Normalization this;
	this->setMaxValue(nor.getMaxValue());
	this->setMinValue(nor.getMinValue());
	this->setThreshold(nor.getThreshold());
	this->setType(nor.getType());
	this->setAmplitude(nor.getAmplitude());
	this->setElongation(nor.getElongation());

	return *this;
}

bool Normalization::operator==(const Normalization &param1)
{
	if(param1.getMaxValue() == this->getMaxValue() &&
	   param1.getMinValue() == this->getMinValue() &&
	   param1.getThreshold() == this->getThreshold() &&
	   param1.getElongation() == this->getElongation() &&
	   param1.getAmplitude() == this->getAmplitude() &&
	   param1.getNormalizationName() == this->getNormalizationName()){
		return true;
	}else{
		return false;
	}
}

bool Normalization::operator!=(const Normalization &param1)
{
	if(param1.getMaxValue() != this->getMaxValue() ||
	   param1.getMinValue() != this->getMinValue() ||
	   param1.getThreshold() != this->getThreshold() ||
	   param1.getElongation() != this->getElongation() ||
	   param1.getAmplitude() != this->getAmplitude() ||
	   param1.getNormalizationName() != this->getNormalizationName()){
		return true;
	}else{
		return false;
	}
}
