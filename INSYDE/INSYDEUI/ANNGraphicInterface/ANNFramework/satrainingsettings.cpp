#include "satrainingsettings.h"

SimulatedAnnealingSettings::SimulatedAnnealingSettings()
{
	initSATS(0, 0, 0, 0, 0, 0, 0);
}

SimulatedAnnealingSettings::SimulatedAnnealingSettings(double minTemperature, int numberOfChanges, double sCondition, double To, double minNoise, double maxNoise, double tdf)
{
	initSATS(minTemperature, numberOfChanges, sCondition, To, minNoise, maxNoise, tdf);
}

void SimulatedAnnealingSettings::setMinTemperature(double tmin)
{
	Tmin = tmin;
}

double SimulatedAnnealingSettings::getMinTemperature() const
{
	return Tmin;
}

void SimulatedAnnealingSettings::setChanges(unsigned int nchanges)
{
	nChanges = nchanges;
}

unsigned int SimulatedAnnealingSettings::getChanges() const
{
	return nChanges;
}

void SimulatedAnnealingSettings::setStartCondition(double lmd)
{
	localMinimumStartCondition = lmd;
}

double SimulatedAnnealingSettings::getStartCondition() const
{
	return localMinimumStartCondition;
}

void SimulatedAnnealingSettings::setTo(double to)
{
	To = to;
}

double SimulatedAnnealingSettings::getTo() const
{
	return To;
}

void SimulatedAnnealingSettings::setMinNoise(double minnoise)
{
	minNoise = minnoise;
}

double SimulatedAnnealingSettings::getMinNoise() const
{
	return minNoise;
}

void SimulatedAnnealingSettings::setMaxNoise(double maxnoise)
{
	maxNoise = maxnoise;
}

double SimulatedAnnealingSettings::getMaxNoise() const
{
	return maxNoise;
}

void SimulatedAnnealingSettings::setDecTempFactor(double decfactor)
{
	temperatureDecrementFactor = decfactor;
}

double SimulatedAnnealingSettings::getDecTempFactor() const
{
	return temperatureDecrementFactor;
}

SimulatedAnnealingSettings SimulatedAnnealingSettings::operator =(const SimulatedAnnealingSettings &mlpsa)
{
	setChanges(mlpsa.getChanges());
	setStartCondition(mlpsa.getStartCondition());
	setMaxNoise(mlpsa.getMaxNoise());
	setMinNoise(mlpsa.getMinNoise());
	setMinTemperature(mlpsa.getMinTemperature());
	setDecTempFactor(mlpsa.getDecTempFactor());
	setTo(mlpsa.getTo());
	return *this;
}

void SimulatedAnnealingSettings::initSATS(double minTemperature, int numberOfChanges, double sCondition, double To, double minNoise, double maxNoise, double tdf)
{
	setMinTemperature(minTemperature);
	setChanges(numberOfChanges);
	setStartCondition(sCondition);
	setTo(To);
	setMinNoise(minNoise);
	setMaxNoise(maxNoise);
	setDecTempFactor(tdf);
}
