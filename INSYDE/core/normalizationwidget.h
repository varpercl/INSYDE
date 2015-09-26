#ifndef NORMALIZATIONWIDGET_H
#define NORMALIZATIONWIDGET_H

#include <QWidget>

#include "labeledcombobox.h"
#include "labeleddoublespinbox.h"
#include "doubleminmaxvaluewidget.h"
#include "normalization.h"

#include <unordered_map>

using namespace std;
using namespace ann_base;

/*!
 * \class
 *
 * \brief
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class Q_DECL_EXPORT NormalizationWidget : public QWidget
{

	public:

		explicit NormalizationWidget(Normalization *currentNormalization, const QString &title = "Normalization", QWidget *parent = 0);
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

		/*!
		 * \brief setNormalization Asigna una nueva normalizacion a este widget, todos los parametros de los controles
		 * se ajustaran automaticamente segun los valores que contenga el parametro \code{no}
		 *
		 * \param no
		 */
		void setNormalization(Normalization *no);

		/*!
		 * \brief setNormalization esta funcion solamente cambiara el tipo de normalizacion permaneciendo los
		 * demas parametros tal como estaban. Actualiza automaticamente el tipo de normalizacion al objeto
		 * \code{Normalization} asignado a este widget.
		 *
		 * \param nt
		 */
		void setNormalization(Normalization::Type nt);

		/*!
		 * \brief getNormalization Devuelve el actual objeto \code{Normalization} asignado a este widget
		 * \return
		 */
		Normalization *getNormalization() const;

		void hideNormalization(Normalization currentNormalization);

		void setDecimals(int dec);
		int getDecimals() const;

		void setEnableUpdateDelay(bool en);

		bool getEnableUpdateDelay() const;

		void setUpdateDelay(int delay);

		int getUpdateDelay() const;

	signals:

		void normalizationChanged(Normalization *currentNormalization);
		void typeChanged(const Normalization::Type &type);
		void amplitudeValueChanged(double val);
		void elongationValueChanged(double val);
		void thresholdValueChanged(double val);
		void minValueChanged(double val);
		void maxValueChanged(double val);

	private slots:

		void amplitudeTimeout();
		void elongationTimeout();
		void maxValueTimeout();
		void minValueTimeout();
		void thresholdTimeout();

		void cbNormalizationIndexChanged(int index);
		void onAmplitudeValueChanged(double val);
		void onElongationValueChanged(double val);
		void onThresholdChanged(double val);
		void onMinValueChanged(double val);
		void onMaxValueChanged(double val);

	private:

		Q_OBJECT

		bool enableUpdateDelay;

		int
		decimals,
		updateDelay;

		QTimer
		tmrAmplitude,
		tmrElongation,
		tmrThreshold,
		tmrMaxValue,
		tmrMinValue;

		Normalization *currentNormalization;

		//Contiene los datos de visualizacion y control de cada tipo de normalizacion
		struct NormProp{
			public:
				Normalization *norm;
				bool visibility;
				QString name;
				int index;
		};

		QVBoxLayout
		*gbLayout,
		*mainLayout;

		QGroupBox *groupBox;

		QMap<Normalization::Type, NormProp> normList;

		LabeledComboBox *lcbNormalization;
		LabeledDoubleSpinBox *lsbwAmplitude;
		LabeledDoubleSpinBox *lsbwElongation;
		LabeledDoubleSpinBox *lsbwThreshold;
		DoubleMinMaxWidget *mmvw;

		void init(const QString &title, Normalization *currentNormalization);

		void updateNormalizationList();
};

#endif // NORMALIZATIONWIDGET_H
