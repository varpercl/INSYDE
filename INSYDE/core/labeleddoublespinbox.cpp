#include "labeleddoublespinbox.h"

core::LabeledDoubleSpinBox::LabeledDoubleSpinBox(const QString &label, double value, const Position &pos, QWidget *parent) :
	LabeledWidget(label, pos, parent)
{
//    Q_INIT_RESOURCE(core_media);
	init(value);
}

core::LabeledDoubleSpinBox::~LabeledDoubleSpinBox()
{
}

void core::LabeledDoubleSpinBox::setValue(double val)
{
	sbValue->setValue(val);
}

double core::LabeledDoubleSpinBox::getValue() const
{
	return sbValue->value();
}

void core::LabeledDoubleSpinBox::setMaximumValue(double val)
{
	sbValue->setMaximum(val);
}

double core::LabeledDoubleSpinBox::getMaximumValue() const
{
	return sbValue->maximum();
}

void core::LabeledDoubleSpinBox::setMinimumValue(double val)
{
	sbValue->setMinimum(val);
}

double core::LabeledDoubleSpinBox::getMinimumValue() const
{
	return sbValue->minimum();
}

void core::LabeledDoubleSpinBox::setDecimals(int dec)
{
	sbValue->setDecimals(dec);
	sbValue->setSingleStep(1/pow(10, dec));
}

int core::LabeledDoubleSpinBox::getDecimals() const
{
	return sbValue->decimals();
}

void core::LabeledDoubleSpinBox::setLabelVisible(bool vis)
{
	label->setVisible(vis);
}

bool core::LabeledDoubleSpinBox::getLabelVisible() const
{
	return label->isVisible();
}

void core::LabeledDoubleSpinBox::setDoubleSpinBox(QDoubleSpinBox *sb)
{
	sbValue = sb;
}

QDoubleSpinBox *core::LabeledDoubleSpinBox::getDoubleSpinBox() const
{
	return sbValue;
}

void core::LabeledDoubleSpinBox::onValueChanged(double val)
{
	emit valueChanged(val);
}

void core::LabeledDoubleSpinBox::init(double value)
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
