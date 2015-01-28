#ifndef LABELEDINTEGERSPINBOXWIDGET_H
#define LABELEDINTEGERSPINBOXWIDGET_H

#include <QtWidgets>

namespace Ui {
	class LabeledIntegerSpinBoxWidget;
}

class LabeledIntegerSpinBoxWidget : public QFrame
{

	public:

		explicit LabeledIntegerSpinBoxWidget(QWidget *parent = 0);
		explicit LabeledIntegerSpinBoxWidget(double value, QWidget *parent = 0);
		explicit LabeledIntegerSpinBoxWidget(double value, const QString &label, QWidget *parent = 0);

		~LabeledIntegerSpinBoxWidget();

		void setLabelText(const QString &text);
		QString getLabelText() const;

		void setValue(double val);
		double getValue() const;

		void setMaximumValue(double val);
		double getMaximumValue() const;

		void setMinimumValue(double val);
		double getMinimumValue() const;

		void setIntegerSpinBox(QSpinBox *sb);
		QSpinBox *getIntegerSpinBox() const;

	private:
		Q_OBJECT

		Ui::LabeledIntegerSpinBoxWidget *ui;

		void init(double value, const QString &label);

};

#endif // LABELEDINTEGERSPINBOXWIDGET_H
