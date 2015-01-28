#ifndef SIMULATEDANNEALINGTRAININGSETTINGS_H
#define SIMULATEDANNEALINGTRAININGSETTINGS_H

#include "ANNglobal.h"

//class MultilayerPerceptron;

class ANNFRAMEWORK_EXPORT SimulatedAnnealingSettings
{
	public:
		explicit SimulatedAnnealingSettings();
		explicit SimulatedAnnealingSettings(double minTemperature, int numberOfChanges, double sCondition, double To, double minNoise, double maxNoise, double tdf);

		void setMinTemperature(double tmin);
		double getMinTemperature() const;

		void setChanges(unsigned int nchanges);
		unsigned int getChanges() const;

		void setStartCondition(double lmd);
		double getStartCondition() const;

		void setTo(double to);
		double getTo() const;

		void setMinNoise(double minnoise);
		double getMinNoise() const;

		void setMaxNoise(double maxnoise);
		double getMaxNoise() const;

		void setDecTempFactor(double decfactor);
		double getDecTempFactor() const;

		SimulatedAnnealingSettings operator=(const SimulatedAnnealingSettings &mlpsa);

	private:

		double Tmin;
		unsigned int nChanges;
		double localMinimumStartCondition;
		double To;
		double minNoise;
		double maxNoise;
		double temperatureDecrementFactor;

		void initSATS(double minTemperature, int numberOfChanges, double sCondition, double To, double minNoise, double maxNoise, double tdf);
};

#endif // MLPSIMULATEDANNEALINGTRAININGSETTINGS_H
