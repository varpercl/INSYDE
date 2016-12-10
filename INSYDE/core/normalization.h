#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include <QtCore>

#include <math.h>

#include "share_core_lib.h"
#include "common.h"


/*!
 * \class
 *
 * \brief This class is intendet to be a Normalization Model which can save all information about a Normalization
 * Normalization is important in many algorithms due to dificulties when it try to converge at any point, it's common to
 * see normalized values or set of values between 0 and 1 or -1 and 1.
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
class CORE_LIB_IMPORT_EXPORT Normalization : public QObject
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

#endif // NORMALIZATION_H
