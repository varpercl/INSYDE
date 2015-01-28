#include "integersizewidget.h"
#include "ui_integersizewidget.h"

IntegerSizeWidget::IntegerSizeWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::IntegerSizeWidget)
{
	initISW(QSize(0,0),
			QPair<IntegerSizeWidget::UnitType, IntegerSizeWidget::UnitType>(IntegerSizeWidget::Pixels, IntegerSizeWidget::Pixels));
}

IntegerSizeWidget::IntegerSizeWidget(const QSize &size, const QPair<UnitType, UnitType> &units, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::IntegerSizeWidget)
{
	initISW(size, units);
}

IntegerSizeWidget::IntegerSizeWidget(int width, int height, const QPair<UnitType, UnitType> &units, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::IntegerSizeWidget)
{
	initISW(QSize(width, height), units);
}

IntegerSizeWidget::~IntegerSizeWidget()
{
	delete ui;
}

QSize IntegerSizeWidget::getSizeValue() const
{
	return QSize(ui->sbWidth->value(), ui->sbHeight->value());
}

QPair<IntegerSizeWidget::UnitType, IntegerSizeWidget::UnitType> IntegerSizeWidget::getUnits() const
{
	return units;
}

void IntegerSizeWidget::setWidth(int width)
{
	ui->sbWidth->setValue(width);
}

int IntegerSizeWidget::getWidth() const
{
	return ui->sbWidth->value();
}

void IntegerSizeWidget::setHeight(int height)
{
	ui->sbHeight->setValue(height);
}

int IntegerSizeWidget::getHeight() const
{
	return ui->sbHeight->value();
}

void IntegerSizeWidget::setSizeValue(const QSize &size)
{
	QSize sizeValue(ui->sbWidth->value(), ui->sbWidth->value());
	if (sizeValue != size) {
		ui->sbWidth->blockSignals(true);
		ui->sbWidth->setValue(size.width());
		ui->sbWidth->blockSignals(false);

		ui->sbHeight->blockSignals(true);
		ui->sbHeight->setValue(size.height());
		ui->sbHeight->blockSignals(false);

		emit sizeValueChanged(size);
		emit widthChanged(size.width());
		emit heightChanged(size.height());
	}
}

void IntegerSizeWidget::setUnits(const QPair<UnitType, UnitType> &units)
{
	this->units = units;
	switch(this->units.first){
		case IntegerSizeWidget::Pixels:
			ui->lblWidthUnit->setText("px");
			break;
		case IntegerSizeWidget::Dots:
			ui->lblWidthUnit->setText("dots");
			break;
		case IntegerSizeWidget::Milimeters:
			ui->lblWidthUnit->setText("mm");
			break;
		case IntegerSizeWidget::Centimeters:
			ui->lblWidthUnit->setText("cm");
			break;
		case IntegerSizeWidget::Kilometers:
			ui->lblWidthUnit->setText("Km");
			break;
		case IntegerSizeWidget::Meters:
			ui->lblWidthUnit->setText("m");
			break;
		case IntegerSizeWidget::Inches:
			ui->lblWidthUnit->setText("in");
			break;
		case IntegerSizeWidget::Feets:
			ui->lblWidthUnit->setText("ft");
			break;
		case IntegerSizeWidget::Miles:
			ui->lblWidthUnit->setText("miles");
			break;

	}

	switch(this->units.second){
		case IntegerSizeWidget::Pixels:
			ui->lblHeightUnit->setText("px");
			break;
		case IntegerSizeWidget::Dots:
			ui->lblHeightUnit->setText("dots");
			break;
		case IntegerSizeWidget::Milimeters:
			ui->lblHeightUnit->setText("mm");
			break;
		case IntegerSizeWidget::Centimeters:
			ui->lblHeightUnit->setText("cm");
			break;
		case IntegerSizeWidget::Kilometers:
			ui->lblHeightUnit->setText("Km");
			break;
		case IntegerSizeWidget::Meters:
			ui->lblHeightUnit->setText("m");
			break;
		case IntegerSizeWidget::Inches:
			ui->lblHeightUnit->setText("in");
			break;
		case IntegerSizeWidget::Feets:
			ui->lblHeightUnit->setText("ft");
			break;
		case IntegerSizeWidget::Miles:
			ui->lblHeightUnit->setText("miles");
			break;

	}

	emit unitsChanged(units);
}

void IntegerSizeWidget::setUnits(IntegerSizeWidget::UnitType widthUnit, IntegerSizeWidget::UnitType heightUnit)
{
	setUnits(QPair<UnitType, UnitType>(widthUnit, heightUnit));
}

void IntegerSizeWidget::initISW(const QSize &size, const QPair<UnitType, UnitType> &units)
{
	ui->setupUi(this);

	setSizeValue(size);
	setUnits(units);

	connect(ui->sbWidth, SIGNAL(valueChanged(int)), SLOT(onWidthChanged(int)));
	connect(ui->sbHeight, SIGNAL(valueChanged(int)), SLOT(onHeightChanged(int)));
}

void IntegerSizeWidget::onHeightChanged(int val)
{
	emit sizeValueChanged(QSize(ui->sbWidth->value(), val));
	emit heightChanged(val);
}

void IntegerSizeWidget::onWidthChanged(int val)
{
	emit sizeValueChanged(QSize(val, ui->sbHeight->value()));
	emit widthChanged(val);
}
