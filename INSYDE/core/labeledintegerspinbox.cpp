#include "labeledintegerspinbox.h"

core::LabeledIntegerSpinBox::LabeledIntegerSpinBox(const QString &label, int value, const Position &pos, QWidget *parent) :
	LabeledWidget(label, pos, parent)
{
//    Q_INIT_RESOURCE(core_media);
	init(value);
}

core::LabeledIntegerSpinBox::~LabeledIntegerSpinBox()
{
	delete sbValue;
}

void core::LabeledIntegerSpinBox::setValue(int val)
{
	if(sbValue->value() != val){
		sbValue->setValue(val);

		emit valueChanged(val);
	}
}

int core::LabeledIntegerSpinBox::getValue() const
{
	return sbValue->value();
}

void core::LabeledIntegerSpinBox::setMaximumValue(int val)
{
	sbValue->setMaximum(val);
}

int core::LabeledIntegerSpinBox::getMaximumValue() const
{
	return sbValue->maximum();
}

void core::LabeledIntegerSpinBox::setMinimumValue(int val)
{
	sbValue->setMinimum(val);
}

int core::LabeledIntegerSpinBox::getMinimumValue() const
{
	return sbValue->minimum();
}

void core::LabeledIntegerSpinBox::setIntegerSpinBox(QSpinBox *sb)
{
	sbValue = sb;
}

QSpinBox *core::LabeledIntegerSpinBox::getIntegerSpinBox() const
{
	return sbValue;
}

void core::LabeledIntegerSpinBox::setUnits(LabeledWidget::Units unit)
{
	LabeledWidget::setUnits(unit);

	switch(unit){
		case LabeledWidget::Percentaje:
			sbValue->setSuffix(" %");
			break;
		case LabeledWidget::Pixels:
			sbValue->setSuffix(" px");
			break;
		case LabeledWidget::Dots:
			sbValue->setSuffix(" dots");
			break;
		case LabeledWidget::Points:
			sbValue->setSuffix(" pt");
			break;
		case LabeledWidget::Milimeters:
			sbValue->setSuffix(" mm");
			break;
		case LabeledWidget::Centimeters:
			sbValue->setSuffix(" cm");
			break;
		case LabeledWidget::Kilometers:
			sbValue->setSuffix(" Km");
			break;
		case LabeledWidget::Meters:
			sbValue->setSuffix(" m");
			break;
		case LabeledWidget::Inches:
			sbValue->setSuffix(" in");
			break;
		case LabeledWidget::Feets:
			sbValue->setSuffix(" ft");
			break;
		case LabeledWidget::Miles:
			sbValue->setSuffix(" mi");
			break;

		case LabeledWidget::Nothing:
		default:
			break;
	}
	sbValue->update();
}

void core::LabeledIntegerSpinBox::onValueChanged(int val)
{
	emit valueChanged(val);
}

void core::LabeledIntegerSpinBox::init(double value)
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
