#ifndef SIZEWIDGET_H
#define SIZEWIDGET_H

#include <QWidget>

namespace Ui {
	class IntegerSizeWidget;
}

class IntegerSizeWidget : public QWidget
{
	public:

		enum UnitType{
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
		explicit IntegerSizeWidget(const QSize &size, const QPair<UnitType, UnitType> &units, QWidget *parent = 0);
		explicit IntegerSizeWidget(int width, int height, const QPair<UnitType, UnitType> &units, QWidget *parent = 0);
		~IntegerSizeWidget();

		void setSizeValue(const QSize &size);
		QSize getSizeValue() const;

		void setUnits(const QPair<UnitType, UnitType> &units);
		void setUnits(UnitType widthUnit, UnitType heightUnit);
		QPair<UnitType, UnitType> getUnits() const;

		void setWidth(int width);
		int getWidth() const;

		void setHeight(int height);
		int getHeight() const;

	signals:
		void sizeValueChanged(QSize arg);
		void unitsChanged(const QPair<UnitType, UnitType> &arg);
		void widthChanged(int nw);
		void heightChanged(int nh);

	private:
		Q_OBJECT

		QPair<UnitType, UnitType> units;
		Ui::IntegerSizeWidget *ui;

		void initISW(const QSize &size, const QPair<UnitType, UnitType> &units);

	private slots:
		void onHeightChanged(int val);
		void onWidthChanged(int val);
};

#endif // SIZEWIDGET_H
