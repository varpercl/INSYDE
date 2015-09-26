#include "normalizationwidget.h"

NormalizationWidget::NormalizationWidget(Normalization *nor, const QString &title, QWidget *parent) :
	QWidget(parent)
{
	init(title, nor);
}

NormalizationWidget::NormalizationWidget(const QString &title, QWidget *parent) :
	QWidget(parent)
{
	init(title, new Normalization());
}

NormalizationWidget::~NormalizationWidget()
{
	delete lcbNormalization;
	delete lsbwAmplitude;
	delete lsbwElongation;
	delete lsbwThreshold;
	delete mmvw;
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

void NormalizationWidget::setNormalization(Normalization *no)
{
	//TODO: corregir que actualice todos los parametros al llamar a esta funcion

	QComboBox *cb = lcbNormalization->getComboBox();

	foreach (NormProp np, normList) {
		if(no->getType() == np.norm->getType()){
			//Se bloquea las señales ya que no se quiere que se llame al evento indexChanged
			cb->blockSignals(true);

			cb->setCurrentIndex(np.index);
			*np.norm = *no;
			lsbwAmplitude->setValue(no->getAmplitude());
			lsbwElongation->setValue(no->getElongation());
			lsbwThreshold->setValue(no->getThreshold());
			mmvw->setMinValue(no->getMinValue());
			mmvw->setMaxValue(no->getMaxValue());

			cb->blockSignals(false);
			break;
		}
	}

	currentNormalization = no;

	emit normalizationChanged(currentNormalization);
}

void NormalizationWidget::setNormalization(Normalization::Type nt)
{
	QComboBox *cb = lcbNormalization->getComboBox();

	foreach(NormProp np, normList){
		if(nt == np.norm->getType()){
			cb->setCurrentIndex(np.index);
			break;
		}
	}

	currentNormalization->setType(nt);
}

Normalization *NormalizationWidget::getNormalization() const
{
	return currentNormalization;
}

void NormalizationWidget::hideNormalization(Normalization nor)
{
	foreach(NormProp np, normList){
		if(np.norm->getType() == nor.getType()){
			np.visibility = false;
		}
	}
	updateNormalizationList();
	cbNormalizationIndexChanged(0);
}

void NormalizationWidget::setDecimals(int dec)
{
	decimals = dec;
	lsbwAmplitude->setDecimals(dec);
	lsbwElongation->setDecimals(dec);
	lsbwThreshold->setDecimals(dec);
	mmvw->setDecimals(dec);
}

int NormalizationWidget::getDecimals() const
{
	return decimals;
}

void NormalizationWidget::setEnableUpdateDelay(bool en)
{
	enableUpdateDelay = en;
}

bool NormalizationWidget::getEnableUpdateDelay() const
{
	return enableUpdateDelay;
}

void NormalizationWidget::setUpdateDelay(int delay)
{
	updateDelay = delay;
}

int NormalizationWidget::getUpdateDelay() const
{
	return updateDelay;
}

void NormalizationWidget::amplitudeTimeout()
{
	double val = lsbwAmplitude->getValue();
	normList[getNormalization()->getType()].norm->setAmplitude(val);
	currentNormalization->setAmplitude(val);

	emit amplitudeValueChanged(val);
}

void NormalizationWidget::elongationTimeout()
{
	double val = lsbwElongation->getValue();
	normList[getNormalization()->getType()].norm->setElongation(val);
	currentNormalization->setElongation(val);

	emit elongationValueChanged(val);
}

void NormalizationWidget::maxValueTimeout()
{
	double val = mmvw->getMaxValue();
	normList[getNormalization()->getType()].norm->setMaxValue(val);
	currentNormalization->setMaxValue(val);

	emit maxValueChanged(val);
}

void NormalizationWidget::minValueTimeout()
{
	double val = mmvw->getMinValue();
	normList[getNormalization()->getType()].norm->setMinValue(val);
	currentNormalization->setMinValue(val);

	emit minValueChanged(val);
}

void NormalizationWidget::thresholdTimeout()
{
	double val = lsbwThreshold->getValue();
	normList[getNormalization()->getType()].norm->setThreshold(val);
	currentNormalization->setThreshold(val);

	emit thresholdValueChanged(val);
}

void NormalizationWidget::init(const QString &title, Normalization *nor)
{
	enableUpdateDelay = false;

	const int
			maxVal = 1000,
			minVal = -1000;

	lcbNormalization = new LabeledComboBox(QString::fromLatin1("Normalización"));

	gbLayout = new QVBoxLayout();
	gbLayout->addWidget(lcbNormalization);

	lsbwThreshold = new LabeledDoubleSpinBox(QString::fromLatin1("Umbral"));
	lsbwThreshold->setMaximumValue(maxVal);
	lsbwThreshold->setMinimumValue(minVal);
	gbLayout->addWidget(lsbwThreshold);

	lsbwAmplitude = new LabeledDoubleSpinBox(QString::fromLatin1("Amplitud"), 1);
	lsbwAmplitude->setMaximumValue(maxVal);
	lsbwAmplitude->setMinimumValue(minVal);
	gbLayout->addWidget(lsbwAmplitude);

	lsbwElongation = new LabeledDoubleSpinBox(QString::fromLatin1("Elongación"), 1);
	lsbwElongation->setMaximumValue(maxVal);
	lsbwElongation->setMinimumValue(minVal);
	gbLayout->addWidget(lsbwElongation);

	mmvw = new DoubleMinMaxWidget();
	gbLayout->addWidget(mmvw);

	groupBox = new QGroupBox();
	groupBox->setTitle(title);
	groupBox->setLayout(gbLayout);

	mainLayout = new QVBoxLayout();
	mainLayout->setMargin(0);
	mainLayout->addWidget(groupBox);
	mainLayout->setAlignment(Qt::AlignTop);

	setLayout(mainLayout);

	normList.insert(Normalization::Nothing, {new Normalization(Normalization::Nothing), true, QString::fromLatin1("Ninguna"), 0});
	normList.insert(Normalization::BipolarFixedThreshold, {new Normalization(Normalization::BipolarFixedThreshold), true, QString::fromLatin1("Bipolar de rango fijo"), 1});
	normList.insert(Normalization::BipolarAutoThreshold, {new Normalization(Normalization::BipolarAutoThreshold), true, QString::fromLatin1("Bipolar de rango automático"), 2});
	normList.insert(Normalization::UnipolarFixedThreshold, {new Normalization(Normalization::UnipolarFixedThreshold), true, QString::fromLatin1("Unipolar de rango fijo"), 3});
	normList.insert(Normalization::UnipolarAutoThreshold, {new Normalization(Normalization::UnipolarAutoThreshold), true, QString::fromLatin1("Unipolar de rango automático"), 4});
	normList.insert(Normalization::LinearFixedRange, {new Normalization(Normalization::LinearFixedRange), true, QString::fromLatin1("Lineal de rango fijo"), 5});
	normList.insert(Normalization::LinearAutoRange, {new Normalization(Normalization::LinearAutoRange), true, QString::fromLatin1("Lineal de rango automático"), 6});
	normList.insert(Normalization::Tanh, {new Normalization(Normalization::Tanh), true, QString::fromLatin1("Tangente hiperbolica"), 7});
	normList.insert(Normalization::Sigmoid, {new Normalization(Normalization::Sigmoid), true, QString::fromLatin1("Sigmoide"), 8});
	normList.insert(Normalization::MeanDistance, {new Normalization(Normalization::MeanDistance), true, QString::fromLatin1("Distancia media"), 9});

	tmrAmplitude.setSingleShot(true);
	tmrElongation.setSingleShot(true);
	tmrThreshold.setSingleShot(true);
	tmrMinValue.setSingleShot(true);
	tmrMaxValue.setSingleShot(true);

	//NOTE: se debe llamar luego de inicializar los demas widgets

	setDecimals(3);
	setNormalization(nor);
	setUpdateDelay(1000);
	setEnableUpdateDelay(true);

	updateNormalizationList();
	cbNormalizationIndexChanged(0);

	connect(&tmrAmplitude, SIGNAL(timeout()), SLOT(amplitudeTimeout()));
	connect(&tmrElongation, SIGNAL(timeout()), SLOT(elongationTimeout()));
	connect(&tmrMaxValue, SIGNAL(timeout()), SLOT(maxValueTimeout()));
	connect(&tmrMinValue, SIGNAL(timeout()), SLOT(minValueTimeout()));
	connect(&tmrThreshold, SIGNAL(timeout()), SLOT(thresholdTimeout()));

	connect(lcbNormalization->getComboBox(), SIGNAL(currentIndexChanged(int)), SLOT(cbNormalizationIndexChanged(int)));
	connect(lsbwAmplitude->getDoubleSpinBox(), SIGNAL(valueChanged(double)), SLOT(onAmplitudeValueChanged(double)));
	connect(lsbwElongation->getDoubleSpinBox(), SIGNAL(valueChanged(double)), SLOT(onElongationValueChanged(double)));
	connect(lsbwThreshold->getDoubleSpinBox(), SIGNAL(valueChanged(double)), SLOT(onThresholdChanged(double)));
	connect(mmvw->getMaxDoubleSpinBox(), SIGNAL(valueChanged(double)), SLOT(onMaxValueChanged(double)));
	connect(mmvw->getMinDoubleSpinBox(), SIGNAL(valueChanged(double)), SLOT(onMinValueChanged(double)));
}

void NormalizationWidget::updateNormalizationList()
{
	QComboBox *cb = lcbNormalization->getComboBox();

	cb->blockSignals(true);
	cb->clear();
	foreach(NormProp np, normList){
		if(np.visibility){
			cb->addItem(np.name);
			np.index = cb->count() - 1;
		}else{
			np.index = -1;
			continue;
		}
	}
	cb->blockSignals(false);
}

void NormalizationWidget::cbNormalizationIndexChanged(int index)
{
	Normalization *curSel = 0;

	//Realiza un pareo del tipo de normalizacion segun el indice del ComboBox
	foreach(NormProp np, normList){
		if(np.index == index){
			curSel = np.norm;
			break;
		}
	}

	//NOTE: No se quiere cambiar el puntero de currentNormalization debido a que si el usuario asigno un objeto de
	//normalizacion en especifico no es conveniente que este cambie sin la peticion del usuario (simplemente se hace una
	//clonacion de las variables miembro)
	*currentNormalization = *curSel;

	Normalization::Type type = currentNormalization->getType();

	lsbwAmplitude->setValue(currentNormalization->getAmplitude());
	lsbwElongation->setValue(currentNormalization->getElongation());
	lsbwThreshold->setValue(currentNormalization->getThreshold());
	mmvw->setMinValue(currentNormalization->getMinValue());
	mmvw->setMaxValue(currentNormalization->getMaxValue());

	switch(type){
		case Normalization::Nothing://Ninguna

			mmvw->setVisible(false);
			lsbwThreshold->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);

			break;

		case Normalization::BipolarFixedThreshold://BipolarFixedThreshold

			mmvw->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);
			lsbwThreshold->setEnabled(true);
			lsbwThreshold->setVisible(true);

			break;
		case Normalization::BipolarAutoThreshold://BipolarAutoThreshold

			mmvw->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);
			lsbwThreshold->setEnabled(false);
			lsbwThreshold->setVisible(true);

			break;
		case Normalization::UnipolarFixedThreshold://UnipolarFixedThreshold

			mmvw->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);
			lsbwThreshold->setEnabled(true);
			lsbwThreshold->setVisible(true);

			break;
		case Normalization::UnipolarAutoThreshold://UnipolarAutoThreshold

			mmvw->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);
			lsbwThreshold->setEnabled(false);
			lsbwThreshold->setVisible(true);

			break;
		case Normalization::LinearFixedRange://LinearFixedRange

			lsbwThreshold->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);
			mmvw->setEnabled(true);
			mmvw->setVisible(true);

			break;
		case Normalization::LinearAutoRange://Rango variable

			lsbwThreshold->setVisible(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);
			mmvw->setEnabled(false);
			mmvw->setVisible(true);

			break;
		case Normalization::Tanh://Tanh

			lsbwThreshold->setVisible(false);
			mmvw->setEnabled(false);
			mmvw->setVisible(false);
			lsbwAmplitude->setVisible(true);
			lsbwElongation->setVisible(true);

			break;
		case Normalization::Sigmoid://Sigmoid

			lsbwThreshold->setVisible(false);
			mmvw->setEnabled(false);
			mmvw->setVisible(false);
			lsbwAmplitude->setVisible(true);
			lsbwElongation->setVisible(true);

			break;
		case Normalization::MeanDistance://Mean Distance

			mmvw->setVisible(false);
			lsbwThreshold->setVisible(false);
			mmvw->setEnabled(false);
			lsbwAmplitude->setVisible(false);
			lsbwElongation->setVisible(false);

			break;
	}

	emit typeChanged(type);
	emit normalizationChanged(curSel);
}

void NormalizationWidget::onAmplitudeValueChanged(double val)
{
	(void)val;
	if(enableUpdateDelay){
		tmrAmplitude.start(updateDelay);
	}else{
		amplitudeTimeout();
	}
}

void NormalizationWidget::onElongationValueChanged(double val)
{
	(void)val;
	if(enableUpdateDelay){
		tmrElongation.start(updateDelay);
	}else{
		elongationTimeout();
	}
}

void NormalizationWidget::onThresholdChanged(double val)
{
	(void)val;
	if(enableUpdateDelay){
		tmrThreshold.start(updateDelay);
	}else{
		thresholdTimeout();
	}
}

void NormalizationWidget::onMinValueChanged(double val)
{
	(void)val;
	if(enableUpdateDelay){
		tmrMinValue.start(updateDelay);
	}else{
		minValueTimeout();
	}
}

void NormalizationWidget::onMaxValueChanged(double val)
{
	(void)val;
	if(enableUpdateDelay){
		tmrMaxValue.start(updateDelay);
	}else{
		maxValueTimeout();
	}
}
