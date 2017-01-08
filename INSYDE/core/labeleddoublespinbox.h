#ifndef LABELEDSPINBOXWIDGET_H
#define LABELEDSPINBOXWIDGET_H

#include <QtWidgets>

#include "share_core_lib.h"
#include "labeledwidget.h"

namespace core{

/*!
 * \class
 *
 * \brief The LabeledDoubleSpinBoxWidget class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT LabeledDoubleSpinBox : public LabeledWidget
{

	public:

		explicit LabeledDoubleSpinBox(const QString &label = "Value", double value = 0, const LabeledWidget::Position &pos = LabeledWidget::Left, QWidget *parent = 0);

		~LabeledDoubleSpinBox();

		void setValue(double val);
		double getValue() const;

		void setMaximumValue(double val);
		double getMaximumValue() const;

		void setMinimumValue(double val);
		double getMinimumValue() const;

		void setDecimals(int dec);
		int getDecimals() const;

		void setLabelVisible(bool vis);
		bool getLabelVisible() const;

		void setDoubleSpinBox(QDoubleSpinBox *sb);
		QDoubleSpinBox *getDoubleSpinBox() const;

	signals:

		void valueChanged(double val);

	private slots:

		void onValueChanged(double val);

	private:
		Q_OBJECT

		QDoubleSpinBox *sbValue;

		void init(double value);

};
}
#endif // LABELEDSPINBOXWIDGET_H
