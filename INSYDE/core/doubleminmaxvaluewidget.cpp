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
	ldsbMin->setValue(val);
}

double DoubleMinMaxWidget::getMinValue() const
{
	return ldsbMin->getValue();
}

void DoubleMinMaxWidget::setMinValueMaximum(double val)
{
	ldsbMin->getDoubleSpinBox()->setMaximum(val);
}

double DoubleMinMaxWidget::getMinValueMaximum() const
{
	return ldsbMin->getDoubleSpinBox()->maximum();
}

void DoubleMinMaxWidget::setMinValueMinimum(double val)
{
	ldsbMin->getDoubleSpinBox()->setMinimum(val);
}

double DoubleMinMaxWidget::getMinValueMinimum() const
{
	return ldsbMin->getDoubleSpinBox()->minimum();
}

void DoubleMinMaxWidget::setMaxValue(double val)
{
	ldsbMax->setValue(val);
}

double DoubleMinMaxWidget::getMaxValue() const
{
	return ldsbMax->getValue();
}

void DoubleMinMaxWidget::setMaxValueMaximum(double val)
{
	ldsbMax->getDoubleSpinBox()->setMaximum(val);
}

double DoubleMinMaxWidget::getMaxValueMaximum() const
{
	return ldsbMax->getDoubleSpinBox()->maximum();
}

void DoubleMinMaxWidget::setMaxValueMinimum(double val)
{
	ldsbMax->getDoubleSpinBox()->setMinimum(val);
}

double DoubleMinMaxWidget::getMaxValueMinimum() const
{
	return ldsbMax->getDoubleSpinBox()->minimum();
}

void DoubleMinMaxWidget::setDecimals(int n)
{
	ldsbMin->setDecimals(n);
	ldsbMax->setDecimals(n);
}

int DoubleMinMaxWidget::getDecimals() const
{
	return ldsbMin->getDecimals();
}

void DoubleMinMaxWidget::setMaxDoubleSpinBox(QDoubleSpinBox *sb)
{
	ldsbMax->setDoubleSpinBox(sb);
}

QDoubleSpinBox *DoubleMinMaxWidget::getMaxDoubleSpinBox() const
{
	return ldsbMax->getDoubleSpinBox();
}

void DoubleMinMaxWidget::setMinDoubleSpinBox(QDoubleSpinBox *sb)
{
	ldsbMin->setDoubleSpinBox(sb);
}

QDoubleSpinBox *DoubleMinMaxWidget::getMinDoubleSpinBox() const
{
	return ldsbMin->getDoubleSpinBox();
}

void DoubleMinMaxWidget::setAligment(Qt::Orientation alig)
{
	if(alignment == alig) return;

	if(alig == Qt::Horizontal){
		mainLayout->removeWidget(ldsbMax);
		mainLayout->addWidget(ldsbMax, 0, 1);
	}else{
		mainLayout->removeWidget(ldsbMax);
		mainLayout->addWidget(ldsbMax, 1, 0);
	}
	alignment = alig;
}

Qt::Orientation DoubleMinMaxWidget::getAlignment() const
{
	return alignment;
}

void DoubleMinMaxWidget::init(double min, double max)
{
	//Initialize LabeledDoubleSpinBox
	ldsbMin = new LabeledDoubleSpinBox("min", min);
	ldsbMax = new LabeledDoubleSpinBox("max", max);

	//Initialize QHBoxLayout
	mainLayout = new QGridLayout();

	mainLayout->addWidget(ldsbMin, 0, 0);
	mainLayout->addWidget(ldsbMax,0 ,1);

	setLayout(mainLayout);

	alignment = Qt::Horizontal;
}
