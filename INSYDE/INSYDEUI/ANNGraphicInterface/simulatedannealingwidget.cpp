#include "simulatedannealingwidget.h"

SimulatedAnnealingWidget::SimulatedAnnealingWidget(QWidget *parent) :
	QWidget(parent)
{
	init(0, 0, 0, 0, 0, 0, 0);
}

SimulatedAnnealingWidget::SimulatedAnnealingWidget(double start, int changes, double minTime, double fdec, double itemp, double minNoise, double maxNoise, QWidget *parent) :
	QWidget(parent)
{
	init(start, changes, minTime, fdec, itemp, minNoise, maxNoise);
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

void SimulatedAnnealingWidget::init(double start, int changes, double minTime, double fdec, double itemp, double minNoise, double maxNoise)
{
	const int decimals = 5;
	mainLayout = new QVBoxLayout(this);
	mainLayout->setObjectName("mainLayout");

	startCondition = new LabeledDoubleSpinBoxWidget(start, QString::fromLatin1("Condición de inicio"), this);
	startCondition->setDecimals(decimals);

	mainLayout->addWidget(startCondition);

	nChanges = new LabeledIntegerSpinBoxWidget(changes, QString::fromLatin1("Número de cambios"), this);

	mainLayout->addWidget(nChanges);

	minTemperature = new LabeledDoubleSpinBoxWidget(minTime, QString::fromLatin1("Temperatura minima"), this);
	minTemperature->setDecimals(decimals);

	mainLayout->addWidget(minTemperature);

	decTempFactor = new LabeledDoubleSpinBoxWidget(fdec, QString::fromLatin1("Decrecimiento de temp."),this);
	decTempFactor->setDecimals(decimals);

	mainLayout->addWidget(decTempFactor);

	startTemperature = new LabeledDoubleSpinBoxWidget(itemp, QString::fromLatin1("Temperatura inicial"),this);
	startTemperature->setDecimals(decimals);

	mainLayout->addWidget(startTemperature);

	this->minNoise = new LabeledDoubleSpinBoxWidget(minNoise, QString::fromLatin1("Ruido mínimo"),this);
	this->minNoise->setDecimals(decimals);

	mainLayout->addWidget(this->minNoise);

	this->maxNoise = new LabeledDoubleSpinBoxWidget(maxNoise, QString::fromLatin1("Ruido máximo"),this);
	this->maxNoise->setDecimals(decimals);

	mainLayout->addWidget(this->maxNoise);
}
