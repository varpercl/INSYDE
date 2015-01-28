#ifndef NORMALIZATIONWIDGET_H
#define NORMALIZATIONWIDGET_H

#include <QWidget>

#include "../labeleddoublespinboxwidget.h"
#include "../minmaxvaluewidget.h"
#include "ANNFramework/itrainingset.h"

namespace Ui {
	class NormalizationWidget;
}

class NormalizationWidget : public QWidget
{

	public:

//		explicit NormalizationWidget(Normalization *nor, QWidget *parent = 0);
//		explicit NormalizationWidget(TrainingSet *ts, QWidget *parent = 0);
		explicit NormalizationWidget(const QString &title = "Normalization", QWidget *parent = 0);

		~NormalizationWidget();

		/*!
		 * \brief setMinValue Establece el minimo valor bajo el cual sera normalizado el conjunto de datos
		 * \param val Valor minimo
		 */
		void setMinValue(double val);

		/*!
		 * \brief getMinValue Devuelve el valor minimo de la normalizacion
		 * \return  Un numero \code{double} que corresponde al valor minimo de la normalizacion
		 */
		double getMinValue() const;

		/*!
		 * \brief setMinValueMaximum Establece el maximo valor al cual se puede establecer el valor minimo de la normalizacion.
		 * Esto no es mas que un renombramiento de la propiedad \code{QDoubleSpinBox::setMaximum}
		 * \param val Valor que se asignara
		 *
		 * \see getMinValueMaximum
		 */
		void setMinValueMaximum(double val);

		/*!
		 * \brief getMinValueMaximum Devuelve el minimo valor que se puede asignar al elemento \code{QDoubleSpinBox}
		 *
		 * \return Devuelve un valor doble que se establecio como propiedad \code{QDoubleSpinBox::setMaximum}
		 *
		 * \see setMinValueMaximum
		 */
		double getMinValueMaximum() const;

		/*!
		 * \brief setMinValueMinimum Analogo a \code{setMinValueMaximum}
		 * \param val Valor que se asignara
		 *
		 * \see setMinValueMaximum
		 */
		void setMinValueMinimum(double val);

		/*!
		 * \brief getMinValueMinimum Analogo a \code{getMinValueMaximum}
		 * \return Valor que se asigno a la propiedad \code{QDoubleSpinBox::setMinimum}
		 *
		 * \see getMinValueMaximum
		 */
		double getMinValueMinimum() const;

		/*!
		 * \brief setMaxValue Analogo a \code{setMinValue}
		 *
		 * \param val Valor asignado a la propiedad
		 *
		 * \see setMinValue
		 */
		void setMaxValue(double val);

		/*!
		 * \brief getMaxValue Analogo a \code{getMinValue()}
		 *
		 * \return Valor asignado a la propiedad
		 *
		 * \see getMinValue()
		 */
		double getMaxValue() const;

		/*!
		 * \brief setMaxValueMaximum Analogo a \code{setMinValueMaximum()}
		 * \param val Valor asignado a la propiedad
		 *
		 * \see setMinValueMaximum
		 */
		void setMaxValueMaximum(double val);

		/*!
		 * \brief getMaxValueMaximum Analogo a \code{getMinValueMaximum}
		 *
		 * \return Devuelve el valor asignado a la propiedad
		 *
		 * \see getMinValueMaximum()
		 */
		double getMaxValueMaximum() const;

		void setMaxValueMinimum(double val);
		double getMaxValueMinimum() const;

		void setThresholdValue(double val);
		double getThresholdValue() const;

		void setThresholdValueMaximum(double val);
		double getThresholdValueMaximum() const;

		void setThresholdValueMinimum(double val);
		double getThresholdValueMinimum() const;

		void setAmplitudeValue(double amp);
		double getAmplitudeValue() const;

		void setElongationValue(double elong);
		double getElongationValue() const;

		void setNormalization(Normalization no);
		void setNormalization(Normalization::Type nt);
		Normalization getNormalization() const;

		void hideNormalization(Normalization nor);

	signals:

		void normalizationChanged(Normalization nor);
		void amplitudeValueChanged(double val);
		void elongationValueChanged(double val);
		void thresholdValueChanged(double val);
		void minValueChanged(double val);
		void maxValueChanged(double val);

	private slots:
		void on_cbNormalizationType_currentIndexChanged(int index);

		void onAmplitudeValueChanged(double val);
		void onElongationValueChanged(double val);
		void onThresholdChanged(double val);
		void onMinValueChanged(double val);
		void onMaxValueChanged(double val);

	private:

		Q_OBJECT

		//Contiene los datos de visualizacion y control de cada tipo de normalizacion
		struct NormProp{
			public:
				Normalization norm;
				bool visibility;
				QString name;
				int index;
		};

		vector<NormProp> normList;
		LabeledDoubleSpinBoxWidget *lsbwAmplitude;
		LabeledDoubleSpinBoxWidget *lsbwElongation;
		LabeledDoubleSpinBoxWidget *lsbwThreshold;
		DoubleMinMaxValueWidget *mmvw;
		Ui::NormalizationWidget *ui;

		void initNW(const QString &title);

		void updateNormalizationList();
};

#endif // NORMALIZATIONWIDGET_H
