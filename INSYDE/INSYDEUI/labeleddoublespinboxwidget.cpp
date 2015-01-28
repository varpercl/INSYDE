#include "labeleddoublespinboxwidget.h"
#include "ui_labeleddoublespinboxwidget.h"

LabeledDoubleSpinBoxWidget::LabeledDoubleSpinBoxWidget(QWidget *parent) :
	QFrame(parent),
	ui(new Ui::LabeledSpinBoxWidget)
{
	init(0, "Value");
}

LabeledDoubleSpinBoxWidget::LabeledDoubleSpinBoxWidget(double value, QWidget *parent) :
	QFrame(parent),
	ui(new Ui::LabeledSpinBoxWidget)
{
	init(value, "Value");
}

LabeledDoubleSpinBoxWidget::LabeledDoubleSpinBoxWidget(double value, const QString &label, QWidget *parent) :
	QFrame(parent),
	ui(new Ui::LabeledSpinBoxWidget)
{
	init(value, label);
}

LabeledDoubleSpinBoxWidget::~LabeledDoubleSpinBoxWidget()
{
	delete ui;
}

void LabeledDoubleSpinBoxWidget::setLabelText(const QString &text)
{
	ui->label->setText(text);
}

QString LabeledDoubleSpinBoxWidget::getLabelText() const
{
	return ui->label->text();
}

void LabeledDoubleSpinBoxWidget::setValue(double val)
{
	ui->sbValue->setValue(val);
}

double LabeledDoubleSpinBoxWidget::getValue() const
{
	return ui->sbValue->value();
}

void LabeledDoubleSpinBoxWidget::setMaximumValue(double val)
{
	ui->sbValue->setMaximum(val);
}

double LabeledDoubleSpinBoxWidget::getMaximumValue() const
{
	return ui->sbValue->maximum();
}

void LabeledDoubleSpinBoxWidget::setMinimumValue(double val)
{
	ui->sbValue->setMinimum(val);
}

double LabeledDoubleSpinBoxWidget::getMinimumValue() const
{
	return ui->sbValue->minimum();
}

void LabeledDoubleSpinBoxWidget::setDecimals(int dec)
{
	ui->sbValue->setDecimals(dec);
}

int LabeledDoubleSpinBoxWidget::getDecimals() const
{
	return ui->sbValue->decimals();
}

void LabeledDoubleSpinBoxWidget::setDoubleSpinBox(QDoubleSpinBox *sb)
{
	ui->sbValue = sb;
}

QDoubleSpinBox *LabeledDoubleSpinBoxWidget::getDoubleSpinBox() const
{
	return ui->sbValue;
}

void LabeledDoubleSpinBoxWidget::init(double value, const QString &label)
{
	ui->setupUi(this);

	ui->gridLayout->setAlignment(Qt::AlignJustify);

	ui->label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

	ui->sbValue->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

//	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	ui->sbValue->setMinimum(-999999999);
	ui->sbValue->setMaximum(999999999);
	setValue(value);
	setLabelText(label);
}
