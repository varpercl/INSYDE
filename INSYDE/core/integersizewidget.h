#ifndef SIZEWIDGET_H
#define SIZEWIDGET_H

#include <QtWidgets>

#include "share_core_lib.h"
#include "labeledintegerspinbox.h"
#include "undo.h"
#include "iresizable.h"

namespace core{

/*!
 * \brief The IntegerSizeWidget class represents a widget that allows users to set width and height
 * properties.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 *
 * TODO: 16/4/16 upgrade this class to implement comonly used controls developed in this project (labeled-boxes)
 */
class CORE_LIB_IMPORT_EXPORT IntegerSizeWidget : public QWidget, public IResizable
{
	public:

		enum Measure{
			Width,
			Height
		};

		//TODO: 16/4/15 should add volume, time units.
		enum Units{
			Nothing,
			Pixels,
			Dots,
			Milimeters,
			Centimeters,
			Kilometers,
			Meters,
			Inches,
			Feets,
			Miles
		};

		explicit IntegerSizeWidget(QWidget *parent = 0);
		explicit IntegerSizeWidget(const QSize &size, const QPair<Units, Units> &units = QPair<Units, Units>(Nothing, Nothing), QWidget *parent = 0);
		explicit IntegerSizeWidget(int width, int height, const QPair<Units, Units> &units = QPair<Units, Units>(Nothing, Nothing), QWidget *parent = 0);
		~IntegerSizeWidget();

		void setSize(const QSize &size) override;
		QSize getSize() const override;

		void setUnits(const QPair<Units, Units> &units);
		void setUnits(Units widthUnit, Units heightUnit);
		QPair<Units, Units> getUnits() const;

		void setWidth(int width) override;
		int getWidth() const;

		void setHeight(int height) override;
		int getHeight() const override;

		void setLabelAlignment(const Qt::Alignment &al);
		Qt::Alignment getLabelAlignment() const;

		void setMinimumSizeValues(const QSize &min);
		QSize getMinimumnSizeValues() const;

		void setMinimumSizeValues(int w, int h);

		void setMaximumSizeValues(const QSize &max);
		QSize getMaximumSizeValues() const;

		void setMaximumSizeValues(int w, int h);

		LabeledIntegerSpinBox *getLabeledIntegerSpinBox(Measure dimention);

	signals:

		void sizeChanged(QSize arg);
		void unitsChanged(const QPair<Units, Units> &arg);
		void widthChanged(int nw);
		void heightChanged(int nh);

	private slots:
		void onHeightChanged(int val);
		void onWidthChanged(int val);

	private:
		Q_OBJECT

		QFormLayout *mainLayout;

		QLabel
		*widthLabel,
		*heightLabel;

		LabeledIntegerSpinBox
		*widthField,
		*heightField;

		QPair<Units, Units> units;

		void init(const QSize &size, const QPair<Units, Units> &units);

};
}
#endif // SIZEWIDGET_H
