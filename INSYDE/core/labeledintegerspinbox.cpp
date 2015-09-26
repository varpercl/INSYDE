#include "labeledintegerspinbox.h"

LabeledIntegerSpinBox::LabeledIntegerSpinBox(const QString &label, int value, const Position &pos, QWidget *parent) :
	LabeledWidget(label, pos, parent)
{
	init(value);
}

LabeledIntegerSpinBox::~LabeledIntegerSpinBox()
{
	delete sbValue;
}

void LabeledIntegerSpinBox::setValue(int val)
{
	if(sbValue->value() != val){
		sbValue->setValue(val);

		emit valueChanged(val);
	}
}

int LabeledIntegerSpinBox::getValue() const
{
	return sbValue->value();
}

void LabeledIntegerSpinBox::setMaximumValue(int val)
{
	sbValue->setMaximum(val);
}

int LabeledIntegerSpinBox::getMaximumValue() const
{
	return sbValue->maximum();
}

void LabeledIntegerSpinBox::setMinimumValue(int val)
{
	sbValue->setMinimum(val);
}

int LabeledIntegerSpinBox::getMinimumValue() const
{
	return sbValue->minimum();
}

void LabeledIntegerSpinBox::setIntegerSpinBox(QSpinBox *sb)
{
	sbValue = sb;
}

QSpinBox *LabeledIntegerSpinBox::getIntegerSpinBox() const
{
	return sbValue;
}

void LabeledIntegerSpinBox::onValueChanged(int val)
{
	emit valueChanged(val);
}

void LabeledIntegerSpinBox::init(double value)
{

	sbValue = new QSpinBox();
	sbValue->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
	sbValue->setAlignment(Qt::AlignRight);
	sbValue->setRange(-50, 50);

	QGridLayout *gl = (QGridLayout *)layout();
	gl->addWidget(sbValue, 1, 1);

	setMinimumValue(-999999999);
	setMaximumValue(999999999);
	setValue(value);

	connect(sbValue, SIGNAL(valueChanged(int)), SLOT(onValueChanged(int)));
}
