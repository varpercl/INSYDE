#ifndef BACKPROPAGATIONTRAININGSETTINGS_H
#define BACKPROPAGATIONTRAININGSETTINGS_H

#include <QtCore>

#include "share_ann_base_lib.h"
#include "globals.h"

namespace ann_base{

/*!
 * \class BackpropagationSettings
 *
 * \brief The BackpropagationSettings class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_BASE_LIB_IMPORT_EXPORT BackpropagationSettings
{
	public:

		//		enum EfficiencyMeasure{
		//			MeanSquareError,
		//			RootMeanSquareError,
		//			ClasificationError
		//		};

		explicit BackpropagationSettings();
		explicit BackpropagationSettings(unsigned int epochs, double MSEmin, double RMSEmin, double CEmin, double learningRate, StopCondition sp);
		explicit BackpropagationSettings(unsigned int epochs, StopCondition em, double emValue, double learningRate);

		void setMaxEpochs(unsigned int epochs);
		unsigned int getMaxEpochs() const;

		void setMinMSE(double msemin);
		double getMinMSE() const;

		void setMinRMSE(double rmsemin);
		double getMinRMSE() const;

		void setMinCE(double cemin);
		double getMinCE() const;

		void setLearningRate(double lr);
		double getLearningRate() const;

		void setStopParameter(StopCondition em);
		StopCondition getStopCondition() const;

		//		void setStopParameterValue(double value);
		//		double getStopParameterValue();

		BackpropagationSettings operator=(const BackpropagationSettings &mlpbp);

	private:

		StopCondition em;
		unsigned int epochs;
		double MSEmin;
		double RMSEmin;
		double CEmin;
		double stopParameterValue;

		double learningRate;

		void init(unsigned int epochs, double MSEmin, double RMSEmin, double CEmin, double learningRate, StopCondition em);
		void init(unsigned int epochs, StopCondition em, double emValue, double learningRate);
};
}

#endif // MLPBACKPROPAGATIONTRAININGSETTINGS_H
