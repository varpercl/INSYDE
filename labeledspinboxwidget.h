#ifndef LABELEDSPINBOXWIDGET_H
#define LABELEDSPINBOXWIDGET_H

#include <QtWidgets>

namespace Ui {
	class LabeledSpinBoxWidget;
}

class LabeledDoubleSpinBoxWidget : public QWidget
{

	public:

		explicit LabeledDoubleSpinBoxWidget(QWidget *parent = 0);
		explicit LabeledDoubleSpinBoxWidget(double value, QWidget *parent = 0);
		explicit LabeledDoubleSpinBoxWidget(double value, const QString &label, QWidget *parent = 0);

		~LabeledDoubleSpinBoxWidget();

		void setLabelText(const QString &text);
		QString getLabelText() const;

		void setValue(double val);
		double getValue() const;

		void setMaximumValue(double val);
		double getMaximumValue() const;

		void setMinimumValue(double val);
		double getMinimumValue() const;

		void setDecimals(int dec);
		int getDecimals() const;

		void setDoubleSpinBox(QDoubleSpinBox *sb);
		QDoubleSpinBox *getDoubleSpinBox() const;

	private:
		Q_OBJECT

		Ui::LabeledSpinBoxWidget *ui;

		void initLDSBW(double value, const QString &label);

};

#endif // LABELEDSPINBOXWIDGET_H
