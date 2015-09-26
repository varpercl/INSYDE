#include "simulatedannealingwidget.h"

SimulatedAnnealingWidget::SimulatedAnnealingWidget(QWidget *parent) :
	QWidget(parent)
{
	init(0, 0, 0, 0, 0, 0, 0, 0);
}

SimulatedAnnealingWidget::SimulatedAnnealingWidget(double start, int samples, int changes, double minTemp, double fdec, double itemp, double minNoise, double maxNoise, QWidget *parent) :
	QWidget(parent)
{
	init(samples, start, changes, minTemp, fdec, itemp, minNoise, maxNoise);
}

void SimulatedAnnealingWidget::setSamples(int samples)
{
	lisbSamples->setValue(samples);
}

int SimulatedAnnealingWidget::getSamples() const
{
	return lisbSamples->getValue();
}

void SimulatedAnnealingWidget::setStartCondition(double sc)
{
	startCondition->setValue(sc);
}

double SimulatedAnnealingWidget::getStartCondition() const
{
	return startCondition->getValue();
}

void SimulatedAnnealingWidget::setNumberOfChanges(int noc)
{
	nChanges->setValue(noc);
}

int SimulatedAnnealingWidget::getNumberOfChanges() const
{
	return nChanges->getValue();
}

void SimulatedAnnealingWidget::setMinTemperature(double mt)
{
	minTemperature->setValue(mt);
}

double SimulatedAnnealingWidget::getMinTemperature() const
{
	return minTemperature->getValue();
}

void SimulatedAnnealingWidget::setDecTempFactor(double dtf)
{
	decTempFactor->setValue(dtf);
}

double SimulatedAnnealingWidget::getDecTempFactor() const
{
	return decTempFactor->getValue();
}

void SimulatedAnnealingWidget::setStartTemperature(double st)
{
	startTemperature->setValue(st);
}

double SimulatedAnnealingWidget::getStartTemperature() const
{
	return startTemperature->getValue();
}

void SimulatedAnnealingWidget::setMinNoise(double mn)
{
	minNoise->setValue(mn);
}

double SimulatedAnnealingWidget::getMinNoise() const
{
	return minNoise->getValue();
}

void SimulatedAnnealingWidget::setMaxNoise(double mn)
{
	maxNoise->setValue(mn);
}

double SimulatedAnnealingWidget::getMaxNoise() const
{
	return maxNoise->getValue();
}

void SimulatedAnnealingWidget::setSASettings(SimulatedAnnealingSettings *sats)
{
	startCondition->setValue(sats->getStartCondition());
	nChanges->setValue(sats->getChanges());
	minTemperature->setValue(sats->getMinTemperature());
	decTempFactor->setValue(sats->getDecTempFactor());
	startTemperature->setValue(sats->getTo());
	minNoise->setValue(sats->getMinNoise());
	maxNoise->setValue(sats->getMaxNoise());
}

SimulatedAnnealingSettings *SimulatedAnnealingWidget::getSimulatedAnnealingSettings()
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

void SimulatedAnnealingWidget::init(int samples, double start, int changes, double minTemp, double fdec, double itemp, double minNoise, double maxNoise)
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
