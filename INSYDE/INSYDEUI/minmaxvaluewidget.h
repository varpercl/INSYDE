#ifndef MINMAXVALUEWIDGET_H
#define MINMAXVALUEWIDGET_H

#include <QtWidgets>

namespace Ui {
	class MinMaxValueWidget;
}

class DoubleMinMaxValueWidget : public QWidget
{
		Q_OBJECT

	public:
		explicit DoubleMinMaxValueWidget(QWidget *parent = 0);

		explicit DoubleMinMaxValueWidget(double min, double max, QWidget *parent = 0);

		~DoubleMinMaxValueWidget();

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
		Ui::MinMaxValueWidget *ui;

		void initDMMVW(double min, double max);
};

#endif // MINMAXVALUEWIDGET_H
