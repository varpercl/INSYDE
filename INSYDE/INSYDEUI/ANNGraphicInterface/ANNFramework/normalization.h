#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include "ANNglobal.h"

#include <QString>

#include <math.h>

class ANNFRAMEWORK_EXPORT Normalization
{
	public:
		enum Type{
			Nothing,
			BipolarFixedThreshold,
			BipolarAutoThreshold,
			UnipolarFixedThreshold,
			UnipolarAutoThreshold,
			LinearFixedRange,
			LinearAutoRange,
			Tanh,
			Sigmoid,
			MeanDistance
		};

		explicit Normalization(Type nt, double max = 999999999, double min = -999999999, double threshold = 0, double amp = 1, double elong = 1);

		explicit Normalization();

		void setType(Type nt);
		Type getType() const;

		void setMaxValue(double max);
		double getMaxValue() const;

		void setMinValue(double min);
		double getMinValue() const;

		void setThreshold(double threshold);
		double getThreshold() const;

		void setAmplitude(double amp);
		double getAmplitude() const;

		void setElongation(double elong);
		double getElongation() const;

		QString getNormalizationName() const;

		Normalization operator=(const Normalization &nor);
		bool operator==(const Normalization &param1);
		bool operator!=(const Normalization &param1);

	private:

		double
		amplitude,
		elongation,
		maxValue,
		minValue,
		threshold;

		Type norType;
};

#endif // NORMALIZATION_H
