#ifndef BACKPROPAGATIONTRAININGSETTINGS_H
#define BACKPROPAGATIONTRAININGSETTINGS_H

//#include "multilayerperceptron.h"
#include "ANNglobal.h"

//class MultilayerPerceptron;

class ANNFRAMEWORK_EXPORT BackpropagationSettings
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

#endif // MLPBACKPROPAGATIONTRAININGSETTINGS_H
