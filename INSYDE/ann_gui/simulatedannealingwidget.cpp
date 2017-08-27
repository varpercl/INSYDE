#include "simulatedannealingwidget.h"

ann_gui::SimulatedAnnealingWidget::SimulatedAnnealingWidget(QWidget *parent) :
	QWidget(parent)
{
    Q_INIT_RESOURCE(ann_gui_media);

	init(0, 0, 0, 0, 0, 0, 0, 0);
}

ann_gui::SimulatedAnnealingWidget::SimulatedAnnealingWidget(double start, int samples, int changes, double minTemp, double fdec, double itemp, double minNoise, double maxNoise, QWidget *parent) :
	QWidget(parent)
{
    Q_INIT_RESOURCE(ann_gui_media);

	init(samples, start, changes, minTemp, fdec, itemp, minNoise, maxNoise);
}

void ann_gui::SimulatedAnnealingWidget::setSamples(int samples)
{
	lisbSamples->setValue(samples);
}

int ann_gui::SimulatedAnnealingWidget::getSamples() const
{
	return lisbSamples->getValue();
}

void ann_gui::SimulatedAnnealingWidget::setStartCondition(double sc)
{
	startCondition->setValue(sc);
}

double ann_gui::SimulatedAnnealingWidget::getStartCondition() const
{
	return startCondition->getValue();
}

void ann_gui::SimulatedAnnealingWidget::setNumberOfChanges(int noc)
{
	nChanges->setValue(noc);
}

int ann_gui::SimulatedAnnealingWidget::getNumberOfChanges() const
{
	return nChanges->getValue();
}

void ann_gui::SimulatedAnnealingWidget::setMinTemperature(double mt)
{
	minTemperature->setValue(mt);
}

double ann_gui::SimulatedAnnealingWidget::getMinTemperature() const
{
	return minTemperature->getValue();
}

void ann_gui::SimulatedAnnealingWidget::setDecTempFactor(double dtf)
{
	decTempFactor->setValue(dtf);
}

double ann_gui::SimulatedAnnealingWidget::getDecTempFactor() const
{
	return decTempFactor->getValue();
}

void ann_gui::SimulatedAnnealingWidget::setStartTemperature(double st)
{
	startTemperature->setValue(st);
}

double ann_gui::SimulatedAnnealingWidget::getStartTemperature() const
{
	return startTemperature->getValue();
}

void ann_gui::SimulatedAnnealingWidget::setMinNoise(double mn)
{
	minNoise->setValue(mn);
}

double ann_gui::SimulatedAnnealingWidget::getMinNoise() const
{
	return minNoise->getValue();
}

void ann_gui::SimulatedAnnealingWidget::setMaxNoise(double mn)
{
	maxNoise->setValue(mn);
}

double ann_gui::SimulatedAnnealingWidget::getMaxNoise() const
{
	return maxNoise->getValue();
}

void ann_gui::SimulatedAnnealingWidget::setSASettings(SimulatedAnnealingSettings *sats)
{
	startCondition->setValue(sats->getStartCondition());
	nChanges->setValue(sats->getChanges());
	minTemperature->setValue(sats->getMinTemperature());
	decTempFactor->setValue(sats->getDecTempFactor());
	startTemperature->setValue(sats->getTo());
	minNoise->setValue(sats->getMinNoise());
	maxNoise->setValue(sats->getMaxNoise());
}

SimulatedAnnealingSettings *ann_gui::SimulatedAnnealingWidget::getSimulatedAnnealingSettings()
{
	sats.setStartCondition(startCondition->getValue());
	sats.setChanges(nChanges->getValue());
	sats.setMinTemperature(minTemperature->getValue());
	sats.setDecTempFactor(decTempFactor->getValue());
	sats.setTo(startTemperature->getValue());
	sats.setMinNoise(minNoise->getValue());
	sats.setMaxNoise(maxNoise->getValue());
	return &sats;
}

void ann_gui::SimulatedAnnealingWidget::init(int samples, double start, int changes, double minTemp, double fdec, double itemp, double minNoise, double maxNoise)
{
	const int decimals = 5;
	mainLayout = new QVBoxLayout(this);
	mainLayout->setObjectName("mainLayout");

	lisbSamples = new LabeledIntegerSpinBox("Muestras", samples);
	lisbSamples->setMinimumValue(10);
	lisbSamples->setMaximumValue(10000);

	startCondition = new LabeledDoubleSpinBox(QString::fromLatin1("Condición de inicio"), start);
	startCondition->setMinimumValue(0);
	startCondition->setMaximumValue(10);
	startCondition->setDecimals(decimals);

	nChanges = new LabeledIntegerSpinBox(QString::fromLatin1("Número de cambios"), changes, LabeledIntegerSpinBox::Left);
	nChanges->setMinimumValue(1);

	minTemperature = new LabeledDoubleSpinBox(QString::fromLatin1("Temperatura mínima"), minTemp);
	minTemperature->setMinimumValue(0);
	minTemperature->setMaximumValue(10);
	minTemperature->setDecimals(decimals);

	decTempFactor = new LabeledDoubleSpinBox(QString::fromLatin1("Decrecimiento de temp."), fdec);
	decTempFactor->setDecimals(decimals);

	startTemperature = new LabeledDoubleSpinBox(QString::fromLatin1("Temperatura inicial"), itemp);
	startTemperature->setDecimals(decimals);

	this->minNoise = new LabeledDoubleSpinBox(QString::fromLatin1("Ruido mínimo"), minNoise);
	this->minNoise->setMinimumValue(-10);
	this->minNoise->setMaximumValue(10);
	this->minNoise->setDecimals(decimals);

	this->maxNoise = new LabeledDoubleSpinBox(QString::fromLatin1("Ruido máximo"), maxNoise);
	this->maxNoise->setMinimumValue(-10);
	this->maxNoise->setMaximumValue(10);
	this->maxNoise->setDecimals(decimals);

	mainLayout->addWidget(lisbSamples);
	mainLayout->addWidget(startCondition);
	mainLayout->addWidget(nChanges);
	mainLayout->addWidget(minTemperature);
	mainLayout->addWidget(decTempFactor);
	mainLayout->addWidget(startTemperature);
	mainLayout->addWidget(this->minNoise);
	mainLayout->addWidget(this->maxNoise);
}
