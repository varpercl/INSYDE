#include "doubleminmaxvaluewidget.h"

DoubleMinMaxWidget::DoubleMinMaxWidget(QWidget *parent) :
	QWidget(parent)
{
	init(0, 1);
}

DoubleMinMaxWidget::DoubleMinMaxWidget(double min, double max, QWidget *parent) :
	QWidget(parent)
{
	init(min, max);
}

DoubleMinMaxWidget::~DoubleMinMaxWidget()
{
}

void DoubleMinMaxWidget::setMinValue(double val)
{

}

double DoubleMinMaxWidget::getMinValue() const
{
	return 0;
}

void DoubleMinMaxWidget::setMinValueMaximum(double val)
{

}

double DoubleMinMaxWidget::getMinValueMaximum() const
{
	return 0;
}

void DoubleMinMaxWidget::setMinValueMinimum(double val)
{

}

double DoubleMinMaxWidget::getMinValueMinimum() const
{
	return 0;
}

void DoubleMinMaxWidget::setMaxValue(double val)
{

}

double DoubleMinMaxWidget::getMaxValue() const
{
	return 0;
}

void DoubleMinMaxWidget::setMaxValueMaximum(double val)
{

}

double DoubleMinMaxWidget::getMaxValueMaximum() const
{
	return 0;
}

void DoubleMinMaxWidget::setMaxValueMinimum(double val)
{

}

double DoubleMinMaxWidget::getMaxValueMinimum() const
{
	return 0;
}

void DoubleMinMaxWidget::setDecimals(int n)
{

}

int DoubleMinMaxWidget::getDecimals() const
{
	return 0;
}

void DoubleMinMaxWidget::setMaxDoubleSpinBox(QDoubleSpinBox *sb)
{

}

QDoubleSpinBox *DoubleMinMaxWidget::getMaxDoubleSpinBox() const
{
	return 0;
}

void DoubleMinMaxWidget::setMinDoubleSpinBox(QDoubleSpinBox *sb)
{

}

QDoubleSpinBox *DoubleMinMaxWidget::getMinDoubleSpinBox() const
{
	return 0;
}

void DoubleMinMaxWidget::init(double min, double max)
{
	setMinValue(min);
	setMaxValue(max);
}
