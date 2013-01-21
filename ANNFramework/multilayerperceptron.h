#ifndef MULTILAYERPERCEPTRON_H
#define MULTILAYERPERCEPTRON_H

#include <QReadLocker>
#include <QReadWriteLock>
#include <QThread>
#include <QMutex>
#include <iostream>
#include <vector>
#include <ANNFramework_global.h>
#include <trainingset.h>
#include <simplepattern.h>
#include <time.h>

using namespace std;
using namespace ANNFrameworkFunctions;

class MultilayerPerceptronPattern;
class TrainingSet;

class ANNFRAMEWORK_EXPORT MLPBackpropagationTrainingSettings
{
	public:

		enum EfficiencyMeasure{
			MeanSquareError,
			RootMeanSquareError,
			ClasificationError
		};

		explicit MLPBackpropagationTrainingSettings();
		explicit MLPBackpropagationTrainingSettings(unsigned int epochs, double MSEmin, double RMSEmin, double CEmin, double learningRate, EfficiencyMeasure sp);

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

		void setStopParameter(EfficiencyMeasure em);
		EfficiencyMeasure getStopParameter() const;

		MLPBackpropagationTrainingSettings operator=(const MLPBackpropagationTrainingSettings &mlpbp);

	private:

		EfficiencyMeasure em;
		unsigned int epochs;
		double MSEmin;
		double RMSEmin;
		double CEmin;
		double learningRate;

		void initMLPBTS(unsigned int epochs, double MSEmin, double RMSEmin, double CEmin, double learningRate, EfficiencyMeasure em);
};

class ANNFRAMEWORK_EXPORT MLPSimulatedAnnealingTrainingSettings
{
	public:
		explicit MLPSimulatedAnnealingTrainingSettings();
		explicit MLPSimulatedAnnealingTrainingSettings(double minTemperature, int numberOfChanges, double sCondition, double To, double minNoise, double maxNoise, double tdf);

		void setMinTemperature(double tmin);
		double getMinTemperature() const;

		void setChanges(unsigned int nchanges);
		unsigned int getChanges() const;

		void setLocalMinimunCondition(double lmd);
		double getLocalMinimumCondition() const;

		void setTo(double to);
		double getTo() const;

		void setMinNoise(double minnoise);
		double getMinNoise() const;

		void setMaxNoise(double maxnoise);
		double getMaxNoise() const;

		void setTempDecrementFactor(double decfactor);
		double getTempDecrementFactor() const;

		MLPSimulatedAnnealingTrainingSettings operator=(const MLPSimulatedAnnealingTrainingSettings &mlpsa);

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

class MLPTrainingResult{
	public:
		unsigned long epochs;
		double MSE;
		double RMSE;
		double CE;
		double time;
		vector<double> MSEHistory, RMSEHistory, CEHistory;
//				vector<vector<vector<vector<double> > > >layerWeightsHistory;
//				vector<vector<vector<double> > > outputWeightsHistory;
		//				vector<vector<vector<double> > > thresholdHistory;
};

class ANNFRAMEWORK_EXPORT MultilayerPerceptron : public QThread
{
	public:

		enum StopCondition{
			MSE,
			RMSE,
			CE
		};

		enum ClasifierOutputType{
			UnipolarClasifier,
			BipolarClasifier
		};

		enum TrainingAlgorithm{
			Backpropagation,
			SimulatedAnnealing,
			GradientDescendent,
			ScaledConjugateGradient
		};

		enum TransferFunctionType{
			Sigmoid,
			Tanh
		};

		explicit MultilayerPerceptron(int ninputs, int noutputs, const vector<int> &layersizes, const TransferFunctionType &tf);

		//		void setLayerWeights(const vector<vector<vector<double> > > &weights);
		//		void setOutputWeights(const vector<vector<double> > &oweights);

		void setLayerSize(unsigned int layer, int size);
		int getLayerSize(unsigned int layer);

		void setLayerSizes(const vector<int> &sizes);
		vector<int> getLayerSizes();

		void setOutputSize(size_t size);
		int getOutputSize();

		void setInputSize(int size);
		int getInputSize();

		vector<double> getOutput(const vector<double> &inputs);
		vector<double> getOutput(const vector<int> &inputs);
		vector<int> getClasifierOutput(const vector<double> &inputs, double threshold, ClasifierOutputType cot);

		void setTransferFunctionType(TransferFunctionType tf);
		TransferFunctionType getTransferFunctionType();

		void randomizeWeights(double min = -1, double max = 1);

		void startTraining(TrainingSet ts,
									 MLPBackpropagationTrainingSettings mlpts);

		void startTraining(TrainingSet ts,
									 MLPBackpropagationTrainingSettings mlpts,
									 MLPSimulatedAnnealingTrainingSettings mlpsats);

		/**
		 *	@deprecated
		 * @brief startTraining
		 * @param ts
		 * @param epochs
		 * @param MSEmin
		 * @param RMSEmin
		 * @param CEmin
		 * @param learningRate
		 * @param ta
		 * @param sc
		 * @return
		 */
		void startTraining(TrainingSet ts,
									 unsigned int epochs,
									 double MSEmin,
									 double RMSEmin,
									 double CEmin,
									 double learningRate = 1,
									 StopCondition sc = MSE);
		/**
		 *	@deprecated
		 * @brief startTraining
		 * @param ts
		 * @param epochs
		 * @param MSEmin
		 * @param RMSEmin
		 * @param CEmin
		 * @param learningRate
		 * @param ta
		 * @param sc
		 * @return
		 */
		void startTraining(const vector<MultilayerPerceptronPattern*> &ts,
									 unsigned int epochs,
									 double MSEmin,
									 double RMSEmin,
									 double CEmin,
									 double learningRate = 1,
									 StopCondition sc = MSE);

		/**
		 *	@deprecated
		 *
		 * @brief startTraining
		 * @param inputs
		 * @param targets
		 * @param epochs
		 * @param MSEmin
		 * @param RMSEmin
		 * @param CEmin
		 * @param learningRate
		 * @param ta
		 * @param sc
		 * @return
		 */
		void startTraining(const vector<vector<double> > &inputs,
									 const vector<vector<double> > &targets,
									 unsigned int epochs,
									 double MSEmin,
									 double RMSEmin,
									 double CEmin,
									 double learningRate = 1,
									 StopCondition sc = MSE);

		MLPTrainingResult getTrainingSnapshot();
		void stopTraining();

		void setAlfa(double a);
		double getAlfa();

		double getMSE(const vector<vector<double> > &inputs, const vector<vector<double> > &targets);
		double getRMSE(const vector<vector<double> > &inputs, const vector<vector<double> > &targets);
		double getCE(const vector<vector<double> > &inputs, const vector<vector<double> > &targets);

		void addNoise(double a);
//		void setOutputType(ClasifierOutputType ot);
//		ClasifierOutputType getOutputType();

	signals:
		void trainingFinished(MLPTrainingResult tres);

	protected:
		void run();

	protected slots:
		void finished();

	private:
		Q_OBJECT

		struct NewState{
				vector<vector<vector<double> > > newWeights;
				vector<vector<double> > newOutputWeights;
		};

		QReadWriteLock rwlock;
//		QMutex mutex;
		TrainingSet ts;
		MLPBackpropagationTrainingSettings mlpbpts;
		MLPSimulatedAnnealingTrainingSettings mlpsats;
		bool sa;

		ClasifierOutputType ot;

//		double tempDecFactor;
//		double minNoise, maxNoise;
//		double To;
//		double startCondition;
//		double Tmin;
//		double initialCondition;
//		int nChanges;

		vector<vector<double> > deltaHidden;
		MLPTrainingResult tres;
		bool training;
		vector<double> __outputs;
		vector<double> __inputs;
		int nInputs;
		double alfa;
		//		vector<int> hiddenLayerSizes;
		vector<vector<vector<double> > > layerWeights;
		vector<vector<double> > outputWeights;

		//        int nInputs;
		//        int nOutputs;
		//        vector<int> layerSizes;
		TransferFunctionType tf;

		//Inherited from QThread
//		void start(Priority p);

		void initMLP(int ninputs, int noutputs, const vector<int> &layersizes, const TransferFunctionType &tf);

		vector<vector<double> > getLayerOutputs(const vector<double> &inputs);

		NewState addNoise(double min, double max);

		double getNewMSE(const vector<vector<vector<double> > > &lweights, const vector<vector<double> > &oweights, const vector<vector<double> > &inputs, const vector<vector<double> > &targets);
		vector<double> getAuxOutput(const vector<vector<vector<double> > > &lweights, const vector<vector<double> > &outputWeights, const vector<double> &inputs);
		void setSAParameters(double minTemperature, int numberOfChanges, double sCondition, double To, double minNoise, double maxNoise, double tdf);
};

class ANNFRAMEWORK_EXPORT MultilayerPerceptronPattern : public SimpleInputPattern
{
	public:
		explicit MultilayerPerceptronPattern(int ninputs, int ntargets);
		explicit MultilayerPerceptronPattern(vector<double> inputs, vector<double> targets);
		explicit MultilayerPerceptronPattern(double *inputs, size_t sinputs, double *targets, size_t stargets);

		void setTargets(double v[]);
		void setTargets(double *v, size_t s);
		void setTargets(vector<double> targets);
		vector<double> getTargets();

	private:

		vector<double> targets;

		void initMLPP(int ntargets);
		void initMLPP(vector<double> targets);
		void initMLPP(double *targets, size_t s);

};

#endif // MULTILAYERPERCEPTRON_H
