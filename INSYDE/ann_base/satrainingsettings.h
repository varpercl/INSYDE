#ifndef SIMULATEDANNEALINGTRAININGSETTINGS_H
#define SIMULATEDANNEALINGTRAININGSETTINGS_H

#include "share_ann_base_lib.h"
#include "settings.h"
#include "globals.h"

namespace ann_base{
/*!
 * \brief The SimulatedAnnealingSettings class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_BASE_LIB_IMPORT_EXPORT SimulatedAnnealingSettings : public Settings
{
	public:
		explicit SimulatedAnnealingSettings();

		/*!
		 * \brief SimulatedAnnealingSettings
		 * \param minTemperature Minimum Temperature
		 * \param numberOfChanges Changes when SA activate
		 * \param sCondition Stop condition
		 * \param To Initial temperature
		 * \param minNoise Minimum noise
		 * \param maxNoise Maximum noise
		 * \param tdf Decrement Temperature Factor
		 */
		explicit SimulatedAnnealingSettings(double minTemperature, int samples, int numberOfChanges, double sCondition, double To, double minNoise, double maxNoise, double tdf);

		void setSamples(int samples);
		int getSamples() const;

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

		unsigned int
		nChanges,
		samples;

		double
		Tmin,
		localMinimumStartCondition,
		To,
		minNoise,
		maxNoise,
		temperatureDecrementFactor;

		void init(double minTemperature, int samples, int numberOfChanges, double sCondition, double To, double minNoise, double maxNoise, double tdf);
};
}

#endif // MLPSIMULATEDANNEALINGTRAININGSETTINGS_H
