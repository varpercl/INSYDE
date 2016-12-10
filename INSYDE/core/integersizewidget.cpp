#include "integersizewidget.h"

IntegerSizeWidget::IntegerSizeWidget(QWidget *parent) :
	QWidget(parent)
{
	init(QSize(0,0),
			QPair<IntegerSizeWidget::Units, IntegerSizeWidget::Units>(IntegerSizeWidget::Pixels, IntegerSizeWidget::Pixels));
}

IntegerSizeWidget::IntegerSizeWidget(const QSize &size, const QPair<Units, Units> &units, QWidget *parent) :
	QWidget(parent)
{
	init(size, units);
}

IntegerSizeWidget::IntegerSizeWidget(int width, int height, const QPair<Units, Units> &units, QWidget *parent) :
	QWidget(parent)
{
	init(QSize(width, height), units);
}

IntegerSizeWidget::~IntegerSizeWidget()
{
}

QSize IntegerSizeWidget::getSize() const
{
	return QSize(widthField->getValue(), heightField->getValue());
}

QPair<IntegerSizeWidget::Units, IntegerSizeWidget::Units> IntegerSizeWidget::getUnits() const
{
	return units;
}

void IntegerSizeWidget::setWidth(int width)
{
	if(widthField->getValue() != width){
		widthField->setValue(width);

		emit sizeChanged(QSize(width, heightField->getValue()));
		emit widthChanged(width);
	}
}

int IntegerSizeWidget::getWidth() const
{
	return widthField->getValue();
}

void IntegerSizeWidget::setHeight(int height)
{
	if(heightField->getValue() != height){
		heightField->setValue(height);

		emit sizeChanged(QSize(widthField->getValue(), height));
		emit heightChanged(height);
	}
}

int IntegerSizeWidget::getHeight() const
{
	return heightField->getValue();
}

void IntegerSizeWidget::setLabelAlignment(const Qt::Alignment &al)
{
	mainLayout->setLabelAlignment(al);
}

Qt::Alignment IntegerSizeWidget::getLabelAlignment() const
{
	return mainLayout->labelAlignment();
}

void IntegerSizeWidget::setMinimumSizeValues(const QSize &min)
{
	widthField->setMinimumValue(min.width());
	heightField->setMinimumValue(min.height());
}

QSize IntegerSizeWidget::getMinimumnSizeValues() const
{
	return QSize(widthField->getMinimumValue(), heightField->getMinimumValue());
}

void IntegerSizeWidget::setMinimumSizeValues(int w, int h)
{
	widthField->setMinimumValue(w);
	heightField->setMinimumValue(h);
}

void IntegerSizeWidget::setMaximumSizeValues(const QSize &max)
{
	widthField->setMaximumValue(max.width());
	heightField->setMaximumValue(max.height());
}

QSize IntegerSizeWidget::getMaximumSizeValues() const
{
	return QSize(widthField->getMaximumValue(), heightField->getMaximumValue());
}

void IntegerSizeWidget::setMaximumSizeValues(int w, int h)
{
	widthField->setMaximumValue(w);
	heightField->setMaximumValue(h);
}

LabeledIntegerSpinBox *IntegerSizeWidget::getLabeledIntegerSpinBox(IntegerSizeWidget::Measure dimention)
{
	switch(dimention){
		case IntegerSizeWidget::Width:
			return widthField;
		case IntegerSizeWidget::Height:
			return heightField;
		default:
			return Q_NULLPTR;
	}
}

void IntegerSizeWidget::setSize(const QSize &size)
{
	QSize sizeValue(widthField->getValue(), heightField->getValue());
	if (sizeValue != size) {
		widthField->blockSignals(true);
		widthField->setValue(size.width());
		widthField->blockSignals(false);

		heightField->blockSignals(true);
		heightField->setValue(size.height());
		heightField->blockSignals(false);

		emit sizeChanged(size);
		emit widthChanged(size.width());
		emit heightChanged(size.height());
	}
}

void IntegerSizeWidget::setUnits(const QPair<Units, Units> &units)
{
	this->units = units;
	switch(this->units.first){
		case IntegerSizeWidget::Nothing:
			widthField->setLabelText("");
			break;
		case IntegerSizeWidget::Pixels:
			widthField->setLabelText("px");
			break;
		case IntegerSizeWidget::Dots:
			widthField->setLabelText("dots");
			break;
		case IntegerSizeWidget::Milimeters:
			widthField->setLabelText("mm");
			break;
		case IntegerSizeWidget::Centimeters:
			widthField->setLabelText("cm");
			break;
		case IntegerSizeWidget::Kilometers:
			widthField->setLabelText("Km");
			break;
		case IntegerSizeWidget::Meters:
			widthField->setLabelText("m");
			break;
		case IntegerSizeWidget::Inches:
			widthField->setLabelText("in");
			break;
		case IntegerSizeWidget::Feets:
			widthField->setLabelText("ft");
			break;
		case IntegerSizeWidget::Miles:
			widthField->setLabelText("miles");
			break;

	}

	switch(this->units.second){
		case IntegerSizeWidget::Nothing:
			heightField->setLabelText("");
			break;
		case IntegerSizeWidget::Pixels:
			heightField->setLabelText("px");
			break;
		case IntegerSizeWidget::Dots:
			heightField->setLabelText("dots");
			break;
		case IntegerSizeWidget::Milimeters:
			heightField->setLabelText("mm");
			break;
		case IntegerSizeWidget::Centimeters:
			heightField->setLabelText("cm");
			break;
		case IntegerSizeWidget::Kilometers:
			heightField->setLabelText("Km");
			break;
		case IntegerSizeWidget::Meters:
			heightField->setLabelText("m");
			break;
		case IntegerSizeWidget::Inches:
			heightField->setLabelText("in");
			break;
		case IntegerSizeWidget::Feets:
			heightField->setLabelText("ft");
			break;
		case IntegerSizeWidget::Miles:
			heightField->setLabelText("miles");
			break;

	}

	emit unitsChanged(units);
}

void IntegerSizeWidget::setUnits(IntegerSizeWidget::Units widthUnit, IntegerSizeWidget::Units heightUnit)
{
	setUnits(QPair<Units, Units>(widthUnit, heightUnit));
}

void IntegerSizeWidget::init(const QSize &size, const QPair<Units, Units> &units)
{

	widthLabel = new QLabel("Width");
	widthLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

	heightLabel = new QLabel("Height");
	heightLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

	heightField = new LabeledIntegerSpinBox(tr("Width"), 0, LabeledWidget::Right);

	widthField = new LabeledIntegerSpinBox(tr("Height"), 0, LabeledWidget::Right);

	mainLayout = new QFormLayout();
	mainLayout->setMargin(0);
	mainLayout->addRow(widthLabel, widthField);
	mainLayout->addRow(heightLabel, heightField);
	mainLayout->setAlignment(widthLabel, Qt::AlignVCenter);
	mainLayout->setAlignment(heightLabel, Qt::AlignVCenter);

	setSize(size);
	setUnits(units);

	setLayout(mainLayout);

	connect(widthField, SIGNAL(valueChanged(int)), SLOT(onWidthChanged(int)));
	connect(heightField, SIGNAL(valueChanged(int)), SLOT(onHeightChanged(int)));
}

void IntegerSizeWidget::onHeightChanged(int val)
{
	emit sizeChanged(QSize(widthField->getValue(), val));
	emit heightChanged(val);
}

void IntegerSizeWidget::onWidthChanged(int val)
{
	emit sizeChanged(QSize(val, heightField->getValue()));
	emit widthChanged(val);
}
