#include "doubleminmaxvaluewidget.h"

core::DoubleMinMaxWidget::DoubleMinMaxWidget(QWidget *parent) :
	QWidget(parent)
{
//    Q_INIT_RESOURCE(core_media);
	init(0, 1);
}

core::DoubleMinMaxWidget::DoubleMinMaxWidget(double min, double max, QWidget *parent) :
	QWidget(parent)
{
//    Q_INIT_RESOURCE(core_media);
	init(min, max);
}

core::DoubleMinMaxWidget::~DoubleMinMaxWidget()
{
}

void core::DoubleMinMaxWidget::setMinValue(double val)
{
	ldsbMin->setValue(val);
}

double core::DoubleMinMaxWidget::getMinValue() const
{
	return ldsbMin->getValue();
}

void core::DoubleMinMaxWidget::setMinValueMaximum(double val)
{
	ldsbMin->getDoubleSpinBox()->setMaximum(val);
}

double core::DoubleMinMaxWidget::getMinValueMaximum() const
{
	return ldsbMin->getDoubleSpinBox()->maximum();
}

void core::DoubleMinMaxWidget::setMinValueMinimum(double val)
{
	ldsbMin->getDoubleSpinBox()->setMinimum(val);
}

double core::DoubleMinMaxWidget::getMinValueMinimum() const
{
	return ldsbMin->getDoubleSpinBox()->minimum();
}

void core::DoubleMinMaxWidget::setMaxValue(double val)
{
	ldsbMax->setValue(val);
}

double core::DoubleMinMaxWidget::getMaxValue() const
{
	return ldsbMax->getValue();
}

void core::DoubleMinMaxWidget::setMaxValueMaximum(double val)
{
	ldsbMax->getDoubleSpinBox()->setMaximum(val);
}

double core::DoubleMinMaxWidget::getMaxValueMaximum() const
{
	return ldsbMax->getDoubleSpinBox()->maximum();
}

void core::DoubleMinMaxWidget::setMaxValueMinimum(double val)
{
	ldsbMax->getDoubleSpinBox()->setMinimum(val);
}

double core::DoubleMinMaxWidget::getMaxValueMinimum() const
{
	return ldsbMax->getDoubleSpinBox()->minimum();
}

void core::DoubleMinMaxWidget::setDecimals(int n)
{
	ldsbMin->setDecimals(n);
	ldsbMax->setDecimals(n);
}

int core::DoubleMinMaxWidget::getDecimals() const
{
	return ldsbMin->getDecimals();
}

void core::DoubleMinMaxWidget::setMaxDoubleSpinBox(QDoubleSpinBox *sb)
{
	ldsbMax->setDoubleSpinBox(sb);
}

QDoubleSpinBox *core::DoubleMinMaxWidget::getMaxDoubleSpinBox() const
{
	return ldsbMax->getDoubleSpinBox();
}

void core::DoubleMinMaxWidget::setMinDoubleSpinBox(QDoubleSpinBox *sb)
{
	ldsbMin->setDoubleSpinBox(sb);
}

QDoubleSpinBox *core::DoubleMinMaxWidget::getMinDoubleSpinBox() const
{
	return ldsbMin->getDoubleSpinBox();
}

void core::DoubleMinMaxWidget::setAligment(Qt::Orientation alig)
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

Qt::Orientation core::DoubleMinMaxWidget::getAlignment() const
{
	return alignment;
}

void core::DoubleMinMaxWidget::init(double min, double max)
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
