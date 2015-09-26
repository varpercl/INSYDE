#include "labeleddoublespinbox.h"

LabeledDoubleSpinBox::LabeledDoubleSpinBox(const QString &label, double value, const LabeledWidget::Position &pos, QWidget *parent) :
	LabeledWidget(label, pos, parent)
{
	init(value);
}

LabeledDoubleSpinBox::~LabeledDoubleSpinBox()
{
}

void LabeledDoubleSpinBox::setValue(double val)
{
	sbValue->setValue(val);
}

double LabeledDoubleSpinBox::getValue() const
{
	return sbValue->value();
}

void LabeledDoubleSpinBox::setMaximumValue(double val)
{
	sbValue->setMaximum(val);
}

double LabeledDoubleSpinBox::getMaximumValue() const
{
	return sbValue->maximum();
}

void LabeledDoubleSpinBox::setMinimumValue(double val)
{
	sbValue->setMinimum(val);
}

double LabeledDoubleSpinBox::getMinimumValue() const
{
	return sbValue->minimum();
}

void LabeledDoubleSpinBox::setDecimals(int dec)
{
	sbValue->setDecimals(dec);
	sbValue->setSingleStep(1/pow(10, dec));
}

int LabeledDoubleSpinBox::getDecimals() const
{
	return sbValue->decimals();
}

void LabeledDoubleSpinBox::setLabelVisible(bool vis)
{
	label->setVisible(vis);
}

bool LabeledDoubleSpinBox::getLabelVisible() const
{
	return label->isVisible();
}

void LabeledDoubleSpinBox::setDoubleSpinBox(QDoubleSpinBox *sb)
{
	sbValue = sb;
}

QDoubleSpinBox *LabeledDoubleSpinBox::getDoubleSpinBox() const
{
	return sbValue;
}

void LabeledDoubleSpinBox::onValueChanged(double val)
{
	emit valueChanged(val);
}

void LabeledDoubleSpinBox::init(double value)
{
	sbValue = new QDoubleSpinBox();
	sbValue->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	sbValue->setAlignment(Qt::AlignRight);
	sbValue->setRange(-50, 50);
	sbValue->setAccelerated(true);

	QGridLayout *gl = (QGridLayout *)layout();
	gl->addWidget(sbValue, 1, 1);

	setMinimumValue(-999999999);
	setMaximumValue(999999999);
	setDecimals(3);
	setValue(value);

	connect(sbValue, SIGNAL(valueChanged(double)), SLOT(onValueChanged(double)));
}
