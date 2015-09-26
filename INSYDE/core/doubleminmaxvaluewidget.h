#ifndef DOUBLEMINMAXVALUEWIDGET_H
#define DOUBLEMINMAXVALUEWIDGET_H

#include <QtWidgets>

/*!
 * \brief The DoubleMinMaxValueWidget class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class DoubleMinMaxWidget : public QWidget
{
	public:
		explicit DoubleMinMaxWidget(QWidget *parent = 0);

		explicit DoubleMinMaxWidget(double min, double max, QWidget *parent = 0);

		~DoubleMinMaxWidget();

		void setMinValue(double val);
		double getMinValue() const;

		void setMinValueMaximum(double val);
		double getMinValueMaximum() const;

		void setMinValueMinimum(double val);
		double getMinValueMinimum() const;

		void setMaxValue(double val);
		double getMaxValue() const;

		void setMaxValueMaximum(double val);
		double getMaxValueMaximum() const;

		void setMaxValueMinimum(double val);
		double getMaxValueMinimum() const;

		void setDecimals(int n);
		int getDecimals() const;

		void setMaxDoubleSpinBox(QDoubleSpinBox *sb);
		QDoubleSpinBox *getMaxDoubleSpinBox() const;

		void setMinDoubleSpinBox(QDoubleSpinBox *sb);
		QDoubleSpinBox *getMinDoubleSpinBox() const;

	private:
		Q_OBJECT

		void init(double min, double max);
};

#endif // MINMAXVALUEWIDGET_H
