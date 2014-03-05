#include "minmaxvaluewidget.h"
#include "ui_minmaxvaluewidget.h"

DoubleMinMaxValueWidget::DoubleMinMaxValueWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::MinMaxValueWidget)
{
	initDMMVW(0, 1);
}

DoubleMinMaxValueWidget::DoubleMinMaxValueWidget(double min, double max, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::MinMaxValueWidget)
{
	initDMMVW(min, max);
}

DoubleMinMaxValueWidget::~DoubleMinMaxValueWidget()
{
	delete ui;
}

void DoubleMinMaxValueWidget::setMinValue(double val)
{
	ui->sbMin->setValue(val);
}

double DoubleMinMaxValueWidget::getMinValue() const
{
	return ui->sbMin->value();
}

void DoubleMinMaxValueWidget::setMinValueMaximum(double val)
{
	ui->sbMin->setMaximum(val);
}

double DoubleMinMaxValueWidget::getMinValueMaximum() const
{
	return ui->sbMin->maximum();
}

void DoubleMinMaxValueWidget::setMinValueMinimum(double val)
{
	ui->sbMin->setMinimum(val);
}

double DoubleMinMaxValueWidget::getMinValueMinimum() const
{
	return ui->sbMin->minimum();
}

void DoubleMinMaxValueWidget::setMaxValue(double val)
{
	ui->sbMax->setValue(val);
}

double DoubleMinMaxValueWidget::getMaxValue() const
{
	return ui->sbMax->value();
}

void DoubleMinMaxValueWidget::setMaxValueMaximum(double val)
{
	ui->sbMax->setMaximum(val);
}

double DoubleMinMaxValueWidget::getMaxValueMaximum() const
{
	return ui->sbMax->maximum();
}

void DoubleMinMaxValueWidget::setMaxValueMinimum(double val)
{
	ui->sbMax->setMinimum(val);
}

double DoubleMinMaxValueWidget::getMaxValueMinimum() const
{
	return ui->sbMax->minimum();
}

void DoubleMinMaxValueWidget::setMaxDoubleSpinBox(QDoubleSpinBox *sb)
{
	ui->sbMax = sb;
}

QDoubleSpinBox *DoubleMinMaxValueWidget::getMaxDoubleSpinBox() const
{
	return ui->sbMax;
}

void DoubleMinMaxValueWidget::setMinDoubleSpinBox(QDoubleSpinBox *sb)
{
	ui->sbMin = sb;
}

QDoubleSpinBox *DoubleMinMaxValueWidget::getMinDoubleSpinBox() const
{
	return ui->sbMin;
}

void DoubleMinMaxValueWidget::initDMMVW(double min, double max)
{
	ui->setupUi(this);
	setMinValue(min);
	setMaxValue(max);
}
