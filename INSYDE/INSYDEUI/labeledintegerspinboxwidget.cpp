#include "labeledintegerspinboxwidget.h"
#include "ui_labeledintegerspinboxwidget.h"

LabeledIntegerSpinBoxWidget::LabeledIntegerSpinBoxWidget(QWidget *parent) :
	QFrame(parent),
	ui(new Ui::LabeledIntegerSpinBoxWidget)
{
	init(0, "Value");
}

LabeledIntegerSpinBoxWidget::LabeledIntegerSpinBoxWidget(double value, QWidget *parent) :
	QFrame(parent),
	ui(new Ui::LabeledIntegerSpinBoxWidget)
{
	init(value, "Value");
}

LabeledIntegerSpinBoxWidget::LabeledIntegerSpinBoxWidget(double value, const QString &label, QWidget *parent) :
	QFrame(parent),
	ui(new Ui::LabeledIntegerSpinBoxWidget)
{
	init(value, label);
}

LabeledIntegerSpinBoxWidget::~LabeledIntegerSpinBoxWidget()
{
	delete ui;
}

void LabeledIntegerSpinBoxWidget::setLabelText(const QString &text)
{
	ui->label->setText(text);
}

QString LabeledIntegerSpinBoxWidget::getLabelText() const
{
	return ui->label->text();
}

void LabeledIntegerSpinBoxWidget::setValue(double val)
{
	ui->sbValue->setValue(val);
}

double LabeledIntegerSpinBoxWidget::getValue() const
{
	return ui->sbValue->value();
}

void LabeledIntegerSpinBoxWidget::setMaximumValue(double val)
{
	ui->sbValue->setMaximum(val);
}

double LabeledIntegerSpinBoxWidget::getMaximumValue() const
{
	return ui->sbValue->maximum();
}

void LabeledIntegerSpinBoxWidget::setMinimumValue(double val)
{
	ui->sbValue->setMinimum(val);
}

double LabeledIntegerSpinBoxWidget::getMinimumValue() const
{
	return ui->sbValue->minimum();
}

void LabeledIntegerSpinBoxWidget::setIntegerSpinBox(QSpinBox *sb)
{
	ui->sbValue = sb;
}

QSpinBox *LabeledIntegerSpinBoxWidget::getIntegerSpinBox() const
{
	return ui->sbValue;
}

void LabeledIntegerSpinBoxWidget::init(double value, const QString &label)
{
	ui->setupUi(this);
	ui->horizontalLayout->setAlignment(Qt::AlignLeft);

	ui->label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

	ui->sbValue->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

	setMaximumValue(999999999);
	setValue(value);
	setLabelText(label);
}
