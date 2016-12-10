#ifndef LABELEDINTEGERSPINBOXWIDGET_H
#define LABELEDINTEGERSPINBOXWIDGET_H

#include "share_core_lib.h"
#include "labeledwidget.h"

/*!
 * \class
 *
 * \brief The LabeledIntegerSpinBox class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT LabeledIntegerSpinBox : public LabeledWidget
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

		//TODO: 16/4/15 must implement set/get aligment

		void setUnits(Units unit) Q_DECL_OVERRIDE;

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
