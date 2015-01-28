#include "normalizationwidget.h"
#include "ui_normalizationwidget.h"

//NormalizationWidget::NormalizationWidget(Normalization *nor, QWidget *parent)
//{

//}

//NormalizationWidget::NormalizationWidget(TrainingSet *ts, QWidget *parent)
//{
//	//TODO: implementar

//	(void) ts;
//	(void) parent;
//}

NormalizationWidget::NormalizationWidget(const QString &title, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::NormalizationWidget)
{
	initNW(title);
}

NormalizationWidget::~NormalizationWidget()
{
	delete lsbwAmplitude;
	delete lsbwElongation;
	delete lsbwThreshold;
	delete mmvw;
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

void NormalizationWidget::setNormalization(Normalization no)
{
	//TODO: corregir que actualice todos los parametros al llamar a esta funcion
	size_t sIndex = normList.size();
	for(size_t i = 0; i < sIndex; i++){
		if(no == normList[i].norm){
			//Se bloquea las señales ya que no se quiere que se llame al evento indexChanged
			ui->cbNormalizationType->blockSignals(true);

			ui->cbNormalizationType->setCurrentIndex(normList[i].index);
			lsbwAmplitude->setValue(no.getAmplitude());
			lsbwElongation->setValue(no.getElongation());
			lsbwThreshold->setValue(no.getThreshold());
			mmvw->setMinValue(no.getMinValue());
			mmvw->setMaxValue(no.getMaxValue());

			ui->cbNormalizationType->blockSignals(false);
			break;
		}
	}
}

void NormalizationWidget::setNormalization(Normalization::Type nt)
{
	size_t sIndex = normList.size();
	for(size_t i = 0; i < sIndex; i++){
		if(nt == normList[i].norm.getType()){
			ui->cbNormalizationType->setCurrentIndex(normList[i].index);
			break;
		}
	}
}

Normalization NormalizationWidget::getNormalization() const
{
	size_t sIndex = normList.size();

	//Realiza un pareo del tipo de normalizacion segun el indice del ComboBox
	for(size_t i = 0; i < sIndex; i++){
		if(normList[i].index == ui->cbNormalizationType->currentIndex()){
			return normList[i].norm;
			break;
		}
	}
	return Normalization();
}

void NormalizationWidget::hideNormalization(Normalization nor)
{
	size_t sVis = normList.size();
	for(size_t i = 0; i < sVis; i++){
		if(normList[i].norm.getType() == nor.getType()){
			normList[i].visibility = false;
		}
	}
	updateNormalizationList();
	on_cbNormalizationType_currentIndexChanged(0);
}

void NormalizationWidget::initNW(const QString &title)
{
	ui->setupUi(this);
	ui->groupBox->setTitle(title);
	ui->groupBox->setObjectName(title);
	ui->horizontalLayout->setAlignment(Qt::AlignLeft);

	const int
			decimals = 10,
			maxVal = 1000,
			minVal = -1000,
			maxWidth = 60;

	normList.push_back({Normalization(Normalization::Nothing), true, QString::fromLatin1("Ninguna"), -1});
	normList.push_back({Normalization(Normalization::BipolarFixedThreshold), true, QString::fromLatin1("Bipolar de rango fijo"), -1});
	normList.push_back({Normalization(Normalization::BipolarAutoThreshold), true, QString::fromLatin1("Bipolar de rango automático"), -1});
	normList.push_back({Normalization(Normalization::UnipolarFixedThreshold), true, QString::fromLatin1("Unipolar de rango fijo"), -1});
	normList.push_back({Normalization(Normalization::UnipolarAutoThreshold), true, QString::fromLatin1("Unipolar de rango automático"), -1});
	normList.push_back({Normalization(Normalization::LinearFixedRange), true, QString::fromLatin1("Lineal de rango fijo"), -1});
	normList.push_back({Normalization(Normalization::LinearAutoRange), true, QString::fromLatin1("Lineal de rango automático"), -1});
	normList.push_back({Normalization(Normalization::Tanh), true, QString::fromLatin1("Tangente hiperbolica"), -1});
	normList.push_back({Normalization(Normalization::Sigmoid), true, QString::fromLatin1("Sigmoide"), -1});
	normList.push_back({Normalization(Normalization::MeanDistance), true, QString::fromLatin1("Distancia media"), -1});

	lsbwThreshold = new LabeledDoubleSpinBoxWidget(0, QString::fromLatin1("Umbral"));
	lsbwThreshold->setMaximumValue(maxVal);
	lsbwThreshold->setMinimumValue(minVal);
	lsbwThreshold->setDecimals(decimals);
	lsbwThreshold->getDoubleSpinBox()->setMaximumWidth(maxWidth);
	ui->horizontalLayout->addWidget(lsbwThreshold);

	lsbwAmplitude = new LabeledDoubleSpinBoxWidget(1, QString::fromLatin1("Amplitud"));
	lsbwAmplitude->setMaximumValue(maxVal);
	lsbwAmplitude->setMinimumValue(minVal);
	lsbwAmplitude->setDecimals(decimals);
	lsbwAmplitude->getDoubleSpinBox()->setMaximumWidth(maxWidth);
	ui->horizontalLayout->addWidget(lsbwAmplitude);

	lsbwElongation = new LabeledDoubleSpinBoxWidget(1, QString::fromLatin1("Elongación"));
	lsbwElongation->setMaximumValue(maxVal);
	lsbwElongation->setMinimumValue(minVal);
	lsbwElongation->setDecimals(decimals);
	lsbwElongation->getDoubleSpinBox()->setMaximumWidth(maxWidth);
	ui->horizontalLayout->addWidget(lsbwElongation);

	mmvw = new DoubleMinMaxValueWidget();
	mmvw->getMaxDoubleSpinBox()->setMaximumWidth(maxWidth);
	mmvw->getMinDoubleSpinBox()->setMaximumWidth(maxWidth);
	mmvw->setDecimals(decimals);
	ui->horizontalLayout->addWidget(mmvw);

	//NOTE: se debe llamar luego de inicializar los demas widgets
	updateNormalizationList();
	on_cbNormalizationType_currentIndexChanged(0);
//	setCurrentNormalization(Normalization::Nothing);

	connect(lsbwAmplitude->getDoubleSpinBox(), SIGNAL(valueChanged(double)), SLOT(onAmplitudeValueChanged(double)));
	connect(lsbwElongation->getDoubleSpinBox(), SIGNAL(valueChanged(double)), SLOT(onElongationValueChanged(double)));
	connect(lsbwThreshold->getDoubleSpinBox(), SIGNAL(valueChanged(double)), SLOT(onThresholdChanged(double)));
	connect(mmvw->getMaxDoubleSpinBox(), SIGNAL(valueChanged(double)), SLOT(onMaxValueChanged(double)));
	connect(mmvw->getMinDoubleSpinBox(), SIGNAL(valueChanged(double)), SLOT(onMinValueChanged(double)));
}

void NormalizationWidget::updateNormalizationList()
{
	size_t sVis = normList.size();

	ui->cbNormalizationType->blockSignals(true);
	ui->cbNormalizationType->clear();
	for(size_t i = 0; i < sVis; i++){
		if(normList[i].visibility){
			ui->cbNormalizationType->addItem(normList[i].name);
			normList[i].index = ui->cbNormalizationType->count() - 1;
		}else{
			normList[i].index = -1;
			continue;
		}
	}
	ui->cbNormalizationType->blockSignals(false);
//	on_cbNormalizationType_currentIndexChanged(0);
}

void NormalizationWidget::on_cbNormalizationType_currentIndexChanged(int index)
{
	Normalization curSel;
	size_t sIndex = normList.size();

	//Realiza un pareo del tipo de normalizacion segun el indice del ComboBox
	for(size_t i = 0; i < sIndex; i++){
		if(normList[i].index == index){
			curSel = normList[i].norm;
			break;
		}
	}

	switch(curSel.getType()){
		case Normalization::Nothing://Ninguna

			mmvw->setVisible(false);
			lsbwThreshold->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);
			break;

		case Normalization::BipolarFixedThreshold://BipolarFixedThreshold

			lsbwAmplitude->setValue(normList[1].norm.getAmplitude());
			lsbwElongation->setValue(normList[1].norm.getElongation());
			lsbwThreshold->setValue(normList[1].norm.getThreshold());
			mmvw->setMinValue(normList[1].norm.getMinValue());
			mmvw->setMaxValue(normList[1].norm.getMaxValue());

			mmvw->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);
			lsbwThreshold->setEnabled(true);
			lsbwThreshold->setVisible(true);

			break;
		case Normalization::BipolarAutoThreshold://BipolarAutoThreshold

			lsbwAmplitude->setValue(normList[2].norm.getAmplitude());
			lsbwElongation->setValue(normList[2].norm.getElongation());
			lsbwThreshold->setValue(normList[2].norm.getThreshold());
			mmvw->setMinValue(normList[2].norm.getMinValue());
			mmvw->setMaxValue(normList[2].norm.getMaxValue());

			mmvw->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);
			lsbwThreshold->setEnabled(false);
			lsbwThreshold->setVisible(true);
			break;
		case Normalization::UnipolarFixedThreshold://UnipolarFixedThreshold

			lsbwAmplitude->setValue(normList[3].norm.getAmplitude());
			lsbwElongation->setValue(normList[3].norm.getElongation());
			lsbwThreshold->setValue(normList[3].norm.getThreshold());
			mmvw->setMinValue(normList[3].norm.getMinValue());
			mmvw->setMaxValue(normList[3].norm.getMaxValue());

			mmvw->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);
			lsbwThreshold->setEnabled(true);
			lsbwThreshold->setVisible(true);
			break;
		case Normalization::UnipolarAutoThreshold://UnipolarAutoThreshold

			lsbwAmplitude->setValue(normList[4].norm.getAmplitude());
			lsbwElongation->setValue(normList[4].norm.getElongation());
			lsbwThreshold->setValue(normList[4].norm.getThreshold());
			mmvw->setMinValue(normList[4].norm.getMinValue());
			mmvw->setMaxValue(normList[4].norm.getMaxValue());

			mmvw->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);
			lsbwThreshold->setEnabled(false);
			lsbwThreshold->setVisible(true);
			break;
		case Normalization::LinearFixedRange://LinearFixedRange

			lsbwAmplitude->setValue(normList[5].norm.getAmplitude());
			lsbwElongation->setValue(normList[5].norm.getElongation());
			lsbwThreshold->setValue(normList[5].norm.getThreshold());
			mmvw->setMinValue(normList[5].norm.getMinValue());
			mmvw->setMaxValue(normList[5].norm.getMaxValue());

			lsbwThreshold->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);
			mmvw->setEnabled(true);
			mmvw->setVisible(true);
			break;
		case Normalization::LinearAutoRange://Rango variable

			lsbwAmplitude->setValue(normList[6].norm.getAmplitude());
			lsbwElongation->setValue(normList[6].norm.getElongation());
			lsbwThreshold->setValue(normList[6].norm.getThreshold());
			mmvw->setMinValue(normList[6].norm.getMinValue());
			mmvw->setMaxValue(normList[6].norm.getMaxValue());

			lsbwThreshold->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);
			mmvw->setEnabled(false);
			mmvw->setVisible(true);
			break;
		case Normalization::Tanh://Tanh

			lsbwAmplitude->setValue(normList[7].norm.getAmplitude());
			lsbwElongation->setValue(normList[7].norm.getElongation());
			lsbwThreshold->setValue(normList[7].norm.getThreshold());
			mmvw->setMinValue(normList[7].norm.getMinValue());
			mmvw->setMaxValue(normList[7].norm.getMaxValue());

			lsbwThreshold->setVisible(false);
			mmvw->setEnabled(false);
			mmvw->setVisible(false);
			lsbwAmplitude->setVisible(true);
			lsbwElongation->setVisible(true);
			break;
		case Normalization::Sigmoid://Sigmoid

			lsbwAmplitude->setValue(normList[8].norm.getAmplitude());
			lsbwElongation->setValue(normList[8].norm.getElongation());
			lsbwThreshold->setValue(normList[8].norm.getThreshold());
			mmvw->setMinValue(normList[8].norm.getMinValue());
			mmvw->setMaxValue(normList[8].norm.getMaxValue());

			lsbwThreshold->setVisible(false);
			mmvw->setEnabled(false);
			mmvw->setVisible(false);
			lsbwAmplitude->setVisible(true);
			lsbwElongation->setVisible(true);
			break;
		case Normalization::MeanDistance://Mean Distance

			lsbwAmplitude->setValue(normList[9].norm.getAmplitude());
			lsbwElongation->setValue(normList[9].norm.getElongation());
			lsbwThreshold->setValue(normList[9].norm.getThreshold());
			mmvw->setMinValue(normList[9].norm.getMinValue());
			mmvw->setMaxValue(normList[9].norm.getMaxValue());

			mmvw->setVisible(false);
			lsbwThreshold->setVisible(false);
			mmvw->setEnabled(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);

	}
	emit normalizationChanged(curSel);
}

void NormalizationWidget::onAmplitudeValueChanged(double val)
{
//	Normalization nor = getNormalization();
	switch(getNormalization().getType()){
		case Normalization::Nothing:
			normList[0].norm.setAmplitude(val);
			break;
		case Normalization::BipolarFixedThreshold:
			normList[1].norm.setAmplitude(val);
			break;
		case Normalization::BipolarAutoThreshold:
			normList[2].norm.setAmplitude(val);
			break;
		case Normalization::UnipolarFixedThreshold:
			normList[3].norm.setAmplitude(val);
			break;
		case Normalization::UnipolarAutoThreshold:
			normList[4].norm.setAmplitude(val);
			break;
		case Normalization::LinearFixedRange:
			normList[5].norm.setAmplitude(val);
			break;
		case Normalization::LinearAutoRange:
			normList[6].norm.setAmplitude(val);
			break;
		case Normalization::Tanh:
			normList[7].norm.setAmplitude(val);
			break;
		case Normalization::Sigmoid:
			normList[8].norm.setAmplitude(val);
			break;
		case Normalization::MeanDistance:
			normList[9].norm.setAmplitude(val);
			break;
	}

	emit amplitudeValueChanged(val);
}

void NormalizationWidget::onElongationValueChanged(double val)
{
	switch(getNormalization().getType()){
		case Normalization::Nothing:
			normList[0].norm.setElongation(val);
			break;
		case Normalization::BipolarFixedThreshold:
			normList[1].norm.setElongation(val);
			break;
		case Normalization::BipolarAutoThreshold:
			normList[2].norm.setElongation(val);
			break;
		case Normalization::UnipolarFixedThreshold:
			normList[3].norm.setElongation(val);
			break;
		case Normalization::UnipolarAutoThreshold:
			normList[4].norm.setElongation(val);
			break;
		case Normalization::LinearFixedRange:
			normList[5].norm.setElongation(val);
			break;
		case Normalization::LinearAutoRange:
			normList[6].norm.setElongation(val);
			break;
		case Normalization::Tanh:
			normList[7].norm.setElongation(val);
			break;
		case Normalization::Sigmoid:
			normList[8].norm.setElongation(val);
			break;
		case Normalization::MeanDistance:
			normList[9].norm.setElongation(val);
			break;
	}
	emit elongationValueChanged(val);
}

void NormalizationWidget::onThresholdChanged(double val)
{
	switch(getNormalization().getType()){
		case Normalization::Nothing:
			normList[0].norm.setThreshold(val);
			break;
		case Normalization::BipolarFixedThreshold:
			normList[1].norm.setThreshold(val);
			break;
		case Normalization::BipolarAutoThreshold:
			normList[2].norm.setThreshold(val);
			break;
		case Normalization::UnipolarFixedThreshold:
			normList[3].norm.setThreshold(val);
			break;
		case Normalization::UnipolarAutoThreshold:
			normList[4].norm.setThreshold(val);
			break;
		case Normalization::LinearFixedRange:
			normList[5].norm.setThreshold(val);
			break;
		case Normalization::LinearAutoRange:
			normList[6].norm.setThreshold(val);
			break;
		case Normalization::Tanh:
			normList[7].norm.setThreshold(val);
			break;
		case Normalization::Sigmoid:
			normList[8].norm.setThreshold(val);
			break;
		case Normalization::MeanDistance:
			normList[9].norm.setThreshold(val);
			break;
	}
	emit thresholdValueChanged(val);
}

void NormalizationWidget::onMinValueChanged(double val)
{
	switch(getNormalization().getType()){
		case Normalization::Nothing:
			normList[0].norm.setMinValue(val);
			break;
		case Normalization::BipolarFixedThreshold:
			normList[1].norm.setMinValue(val);
			break;
		case Normalization::BipolarAutoThreshold:
			normList[2].norm.setMinValue(val);
			break;
		case Normalization::UnipolarFixedThreshold:
			normList[3].norm.setMinValue(val);
			break;
		case Normalization::UnipolarAutoThreshold:
			normList[4].norm.setMinValue(val);
			break;
		case Normalization::LinearFixedRange:
			normList[5].norm.setMinValue(val);
			break;
		case Normalization::LinearAutoRange:
			normList[6].norm.setMinValue(val);
			break;
		case Normalization::Tanh:
			normList[7].norm.setMinValue(val);
			break;
		case Normalization::Sigmoid:
			normList[8].norm.setMinValue(val);
			break;
		case Normalization::MeanDistance:
			normList[9].norm.setMinValue(val);
			break;
	}
	emit minValueChanged(val);
}

void NormalizationWidget::onMaxValueChanged(double val)
{
	switch(getNormalization().getType()){
		case Normalization::Nothing:
			normList[0].norm.setMaxValue(val);
			break;
		case Normalization::BipolarFixedThreshold:
			normList[1].norm.setMaxValue(val);
			break;
		case Normalization::BipolarAutoThreshold:
			normList[2].norm.setMaxValue(val);
			break;
		case Normalization::UnipolarFixedThreshold:
			normList[3].norm.setMaxValue(val);
			break;
		case Normalization::UnipolarAutoThreshold:
			normList[4].norm.setMaxValue(val);
			break;
		case Normalization::LinearFixedRange:
			normList[5].norm.setMaxValue(val);
			break;
		case Normalization::LinearAutoRange:
			normList[6].norm.setMaxValue(val);
			break;
		case Normalization::Tanh:
			normList[7].norm.setMaxValue(val);
			break;
		case Normalization::Sigmoid:
			normList[8].norm.setMaxValue(val);
			break;
		case Normalization::MeanDistance:
			normList[9].norm.setMaxValue(val);
			break;
	}
	emit maxValueChanged(val);
}
