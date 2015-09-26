#ifndef SIZEWIDGET_H
#define SIZEWIDGET_H

#include <QtWidgets>

#include "labeledintegerspinbox.h"
#include "interfaces.h"

/*!
 * \class
 *
 * \brief The IntegerSizeWidget class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class IntegerSizeWidget : public QWidget, public Resizable
{
	public:

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

		void setSize(const QSize &size);
		QSize getSize() const;

		void setUnits(const QPair<Units, Units> &units);
		void setUnits(Units widthUnit, Units heightUnit);
		QPair<Units, Units> getUnits() const;

		void setWidth(int width);
		int getWidth() const;

		void setHeight(int height);
		int getHeight() const;

		void setLabelAlignment(const Qt::Alignment &al);
		Qt::Alignment getLabelAlignment() const;

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

#endif // SIZEWIDGET_H
