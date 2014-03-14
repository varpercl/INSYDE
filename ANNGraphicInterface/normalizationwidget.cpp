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
	lsbwThreshold->setValue(val);
}

double NormalizationWidget::getThresholdValue() const
{
	return lsbwThreshold->getValue();
}

void NormalizationWidget::setThresholdValueMaximum(double val)
{
	lsbwThreshold->setMaximumValue(val);
}

double NormalizationWidget::getThresholdValueMaximum() const
{
	return lsbwThreshold->getMaximumValue();
}

void NormalizationWidget::setThresholdValueMinimum(double val)
{
	lsbwThreshold->setMinimumValue(val);
}

double NormalizationWidget::getThresholdValueMinimum() const
{
	return lsbwThreshold->getMinimumValue();
}

void NormalizationWidget::setAmplitudeValue(double amp)
{
	lsbwAmplitude->setValue(amp);
}

double NormalizationWidget::getAmplitudeValue() const
{
	return lsbwAmplitude->getValue();
}

void NormalizationWidget::setElongationValue(double elong)
{
	lsbwElongation->setValue(elong);
}

double NormalizationWidget::getElongationValue() const
{
	return lsbwElongation->getValue();
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

	const int
			decimals = 10,
			maxVal = 1000,
			minVal = -1000;

	lsbwThreshold = new LabeledDoubleSpinBoxWidget(0, "Umbral");
	lsbwThreshold->setMaximumValue(maxVal);
	lsbwThreshold->setMinimumValue(minVal);
	lsbwThreshold->setDecimals(decimals);
	ui->horizontalLayout->addWidget(lsbwThreshold);

	lsbwAmplitude = new LabeledDoubleSpinBoxWidget(1, "Amplitud");
	lsbwAmplitude->setMaximumValue(maxVal);
	lsbwAmplitude->setMinimumValue(minVal);
	lsbwAmplitude->setDecimals(decimals);
	ui->horizontalLayout->addWidget(lsbwAmplitude);

	lsbwElongation = new LabeledDoubleSpinBoxWidget(1, QString::fromLatin1("Elongación"));
	lsbwElongation->setMaximumValue(maxVal);
	lsbwElongation->setMinimumValue(minVal);
	lsbwElongation->setDecimals(decimals);
	ui->horizontalLayout->addWidget(lsbwElongation);

	mmvw = new DoubleMinMaxValueWidget();
	ui->horizontalLayout->addWidget(mmvw);

	on_cbNormalizationType_currentIndexChanged(ui->cbNormalizationType->currentIndex());

	connect(lsbwAmplitude->getDoubleSpinBox(), SIGNAL(valueChanged(double)), SLOT(onAmplitudeValueChanged(double)));
	connect(lsbwElongation->getDoubleSpinBox(), SIGNAL(valueChanged(double)), SLOT(onElongationValueChanged(double)));
	connect(lsbwThreshold->getDoubleSpinBox(), SIGNAL(valueChanged(double)), SLOT(onThresholdChanged(double)));
	connect(mmvw->getMaxDoubleSpinBox(), SIGNAL(valueChanged(double)), SLOT(onMaxValueChanged(double)));
	connect(mmvw->getMinDoubleSpinBox(), SIGNAL(valueChanged(double)), SLOT(onMinValueChanged(double)));
}

void NormalizationWidget::on_cbNormalizationType_currentIndexChanged(int index)
{
	Normalization nor;
	switch(index){
		case 0://Ninguna
			mmvw->setVisible(false);
			lsbwThreshold->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);

			nor.setNormalization(Normalization::Nothing);
			emit normalizationChanged(nor);
			emit normalizationChanged(ITrainingSet::Nothing);
			break;
		case 1://BipolarFixedThreshold
			mmvw->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);
			lsbwThreshold->setEnabled(true);
			lsbwThreshold->setVisible(true);

			nor.setNormalization(Normalization::BipolarFixedThreshold);
			emit normalizationChanged(nor);
			emit normalizationChanged(ITrainingSet::BipolarFixedThreshold);
			break;
		case 2://BipolarAutoThreshold
			mmvw->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);
			lsbwThreshold->setEnabled(false);
			lsbwThreshold->setVisible(true);

			nor.setNormalization(Normalization::BipolarAutoThreshold);
			emit normalizationChanged(nor);
			emit normalizationChanged(ITrainingSet::BipolarAutoThreshold);
			break;
		case 3://UnipolarFixedThreshold
			mmvw->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);
			lsbwThreshold->setEnabled(true);
			lsbwThreshold->setVisible(true);

			nor.setNormalization(Normalization::UnipolarFixedThreshold);
			emit normalizationChanged(nor);
			emit normalizationChanged(ITrainingSet::UnipolarFixedThreshold);
			break;
		case 4://UnipolarAutoThreshold
			mmvw->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);
			lsbwThreshold->setEnabled(false);
			lsbwThreshold->setVisible(true);

			nor.setNormalization(Normalization::UnipolarAutoThreshold);
			emit normalizationChanged(nor);
			emit normalizationChanged(ITrainingSet::UnipolarAutoThreshold);
			break;
		case 5://LinearFixedRange
			lsbwThreshold->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);
			mmvw->setEnabled(true);
			mmvw->setVisible(true);

			nor.setNormalization(Normalization::LinearFixedRange);
			emit normalizationChanged(nor);
			emit normalizationChanged(ITrainingSet::LinearFixedRange);
			break;
		case 6://Rango variable
			lsbwThreshold->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);
			mmvw->setEnabled(false);
			mmvw->setVisible(true);

			nor.setNormalization(Normalization::LinearAutoRange);
			emit normalizationChanged(nor);
			emit normalizationChanged(ITrainingSet::LinearAutoRange);
			break;
		case 7://Tanh
			lsbwThreshold->setVisible(false);
			mmvw->setEnabled(false);
			mmvw->setVisible(false);
			lsbwAmplitude->setVisible(true);
			lsbwElongation->setVisible(true);

			nor.setNormalization(Normalization::Tanh);
			emit normalizationChanged(nor);
			emit normalizationChanged(ITrainingSet::Tanh);
			break;
		case 8://Sigmoid
			lsbwThreshold->setVisible(false);
			mmvw->setEnabled(false);
			mmvw->setVisible(false);
			lsbwAmplitude->setVisible(true);
			lsbwElongation->setVisible(true);

			nor.setNormalization(Normalization::Sigmoid);
			emit normalizationChanged(nor);
			emit normalizationChanged(ITrainingSet::Sigmoid);
			break;
		case 9://Mean Distance
			mmvw->setVisible(false);
			lsbwThreshold->setVisible(false);
			mmvw->setEnabled(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);

			nor.setNormalization(Normalization::MeanDistance);
			emit normalizationChanged(nor);
			emit normalizationChanged(ITrainingSet::MeanDistance);
	}
}

void NormalizationWidget::onAmplitudeValueChanged(double val)
{
	emit amplitudeValueChanged(val);
}

void NormalizationWidget::onElongationValueChanged(double val)
{
	emit elongationValueChanged(val);
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
