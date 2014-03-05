#include "normalizationwidget.h"
#include "ui_normalizationwidget.h"

NormalizationWidget::NormalizationWidget(const QString &title, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::NormalizationWidget)
{
	initNW(title);
}

NormalizationWidget::~NormalizationWidget()
{
	delete ui;
}

void NormalizationWidget::setMinValue(double val)
{
	mmvw->setMinValue(val);
}

double NormalizationWidget::getMinValue() const
{
	return mmvw->getMinValue();
}

void NormalizationWidget::setMinValueMaximum(double val)
{
	mmvw->setMinValueMaximum(val);
}

double NormalizationWidget::getMinValueMaximum() const
{
	return mmvw->getMinValueMaximum();
}

void NormalizationWidget::setMinValueMinimum(double val)
{
	mmvw->setMinValueMinimum(val);
}

double NormalizationWidget::getMinValueMinimum() const
{
	return mmvw->getMinValueMinimum();
}

void NormalizationWidget::setMaxValue(double val)
{
	mmvw->setMaxValue(val);
}

double NormalizationWidget::getMaxValue() const
{
	return mmvw->getMaxValue();
}

void NormalizationWidget::setMaxValueMaximum(double val)
{
	mmvw->setMaxValueMaximum(val);
}

double NormalizationWidget::getMaxValueMaximum() const
{
	return mmvw->getMaxValueMaximum();
}

void NormalizationWidget::setMaxValueMinimum(double val)
{
	mmvw->setMaxValueMinimum(val);
}

double NormalizationWidget::getMaxValueMinimum() const
{
	return mmvw->getMaxValueMinimum();
}

void NormalizationWidget::setThresholdValue(double val)
{
	lsbw->setValue(val);
}

double NormalizationWidget::getThresholdValue() const
{
	return lsbw->getValue();
}

void NormalizationWidget::setThresholdValueMaximum(double val)
{
	lsbw->setMaximumValue(val);
}

double NormalizationWidget::getThresholdValueMaximum() const
{
	return lsbw->getMaximumValue();
}

void NormalizationWidget::setThresholdValueMinimum(double val)
{
	lsbw->setMinimumValue(val);
}

double NormalizationWidget::getThresholdValueMinimum() const
{
	return lsbw->getMinimumValue();
}

void NormalizationWidget::setCurrentNormalization(ITrainingSet::NormalizationType nt)
{
	ui->cbNormalizationType->setCurrentIndex(nt);
}

ITrainingSet::NormalizationType NormalizationWidget::getCurrentNormalization() const
{
	return (ITrainingSet::NormalizationType)ui->cbNormalizationType->currentIndex();
}

void NormalizationWidget::initNW(const QString &title)
{
	ui->setupUi(this);
	ui->groupBox->setTitle(title);
	ui->horizontalLayout->setAlignment(Qt::AlignLeft);

	lsbw = new LabeledDoubleSpinBoxWidget();
	lsbw->setLabelText("Umbral");
	ui->horizontalLayout->addWidget(lsbw);

	mmvw = new DoubleMinMaxValueWidget();
	ui->horizontalLayout->addWidget(mmvw);

	on_cbNormalizationType_currentIndexChanged(ui->cbNormalizationType->currentIndex());

	connect(lsbw->getDoubleSpinBox(), SIGNAL(valueChanged(double)), SLOT(onThresholdChanged(double)));
	connect(mmvw->getMaxDoubleSpinBox(), SIGNAL(valueChanged(double)), SLOT(onMaxValueChanged(double)));
	connect(mmvw->getMinDoubleSpinBox(), SIGNAL(valueChanged(double)), SLOT(onMinValueChanged(double)));
}

void NormalizationWidget::on_cbNormalizationType_currentIndexChanged(int index)
{
	switch(index){
		case 0://Ninguna
			mmvw->setVisible(false);
			lsbw->setVisible(false);
			emit normalizationChanged(ITrainingSet::Nothing);
			break;
		case 1://BipolarFixedThreshold
			mmvw->setVisible(false);
			lsbw->setVisible(true);
			lsbw->setEnabled(true);
			emit normalizationChanged(ITrainingSet::BipolarFixedThreshold);
			break;
		case 2://BipolarAutoThreshold
			mmvw->setVisible(false);
			lsbw->setVisible(true);
			lsbw->setEnabled(false);
			emit normalizationChanged(ITrainingSet::BipolarAutoThreshold);
			break;
		case 3://UnipolarFixedThreshold
			mmvw->setVisible(false);
			lsbw->setVisible(true);
			lsbw->setEnabled(true);
			emit normalizationChanged(ITrainingSet::UnipolarFixedThreshold);
			break;
		case 4://UnipolarAutoThreshold
			mmvw->setVisible(false);
			lsbw->setVisible(true);
			lsbw->setEnabled(false);
			emit normalizationChanged(ITrainingSet::UnipolarAutoThreshold);
			break;
		case 5://LinearFixedRange
			mmvw->setVisible(true);
			lsbw->setVisible(false);
			mmvw->setEnabled(true);
			emit normalizationChanged(ITrainingSet::LinearFixedRange);
			break;
		case 6://Rango variable
			mmvw->setVisible(true);
			lsbw->setVisible(false);
			mmvw->setEnabled(false);
			emit normalizationChanged(ITrainingSet::LinearAutoRange);
			break;
		case 7://Tanh
			//TODO: implementar sigmoide
			emit normalizationChanged(ITrainingSet::Tanh);
			break;
		case 8://Sigmoid
			//TODO: implementar tangente hiperbolica
			emit normalizationChanged(ITrainingSet::Sigmoid);
			break;
	}
}

void NormalizationWidget::onThresholdChanged(double val)
{
	emit thresholdValueChanged(val);
}

void NormalizationWidget::onMinValueChanged(double val)
{
	emit minValueChanged(val);
}

void NormalizationWidget::onMaxValueChanged(double val)
{
	emit maxValueChanged(val);
}
