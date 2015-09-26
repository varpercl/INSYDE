#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include "common.h"

#include <QtCore>

#include <math.h>

namespace ann_base{
	/*!
 * \class
 *
 * \brief Esta clase contiene toda la informacion basica para manejar los tipos de normalizaciones mas comunes
 * utilizadas en diferentes algoritmos. La idea de una normalizacion de datos es muy implementada debido a las
 * dificultades de convergencia en diferentes algoritmos cuando los datos de entrada estan muy dispersos en rangos de
 * valores muy amplios.
 * La normalizacion permite que un conjunto de datos pueda ser representado en rangos normalizados desde 0 a 1 o desde
 * -1 a 1.
 * Existen varios tipos de normalizacion definidos
 * TODO: continuar
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
	class Q_DECL_EXPORT Normalization : public QObject
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

			explicit Normalization();

			explicit Normalization(Type nt, double max = 999999999, double min = -999999999, double threshold = 0, double amp = 1, double elong = 1);

			Normalization(const Normalization &nor);

			~Normalization();

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

			QString getName() const;

			Normalization &operator=(const Normalization &nor);
			bool operator==(const Normalization &param1);
			bool operator!=(const Normalization &param1);

		signals:

			void amplitudeChanged(double val);
			void elongationChanged(double val);
			void thresholdChanged(double val);
			void maxValueChanged(double val);
			void minValueChanged(double val);
			void typeChanged(int type);

		private:
			Q_OBJECT

			double
			amplitude,
			elongation,
			maxValue,
			minValue,
			threshold;

			Type norType;

			void init(Type nt, double max, double min, double threshold, double amp, double elong);
	};
}

#endif // NORMALIZATION_H
