#ifndef LABELEDINTEGERSPINBOXWIDGET_H
#define LABELEDINTEGERSPINBOXWIDGET_H

#include "labeledwidget.h"

/*!
 * \class
 *
 * \brief The LabeledIntegerSpinBox class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class LabeledIntegerSpinBox : public LabeledWidget
{

	public:

		explicit LabeledIntegerSpinBox(const QString &label, int value = 0, const LabeledWidget::Position &pos = LabeledWidget::Left, QWidget *parent = 0);

		~LabeledIntegerSpinBox();

		void setValue(int val);
		int getValue() const;

		void setMaximumValue(int val);
		int getMaximumValue() const;

		void setMinimumValue(int val);
		int getMinimumValue() const;

		void setIntegerSpinBox(QSpinBox *sb);
		QSpinBox *getIntegerSpinBox() const;

	signals:
		void valueChanged(int val);

	private slots:

		void onValueChanged(int val);

	private:
		Q_OBJECT

		QSpinBox *sbValue;

		void init(double value);

};

#endif // LABELEDINTEGERSPINBOXWIDGET_H
