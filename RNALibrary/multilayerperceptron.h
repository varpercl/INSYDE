#ifndef MULTILAYERPERCEPTRON_H
#define MULTILAYERPERCEPTRON_H
#include <iostream>
#include <vector>
#include "RNALibrary_global.h"
#include "trainingset.h"
#include "simplepattern.h"
#include "general.h"
#include <time.h>

using namespace std;

class MultilayerPerceptronPattern;

class RNALIBRARY_EXPORT MultilayerPerceptron
{
	public:

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

		typedef struct {
				unsigned long epochs;
				double MSE;
				double time;
				vector<double> MSEHistory;
				vector<vector<vector<vector<double> > > >layerWeightsHistory;
				vector<vector<vector<double> > > outputWeightsHistory;
//				vector<vector<vector<double> > > thresholdHistory;
		}TrainingResult;

		explicit MultilayerPerceptron(int ninputs, int noutputs, const vector<int> &layersizes, const TransferFunctionType &tf);

		void setLayerSize(unsigned int layer, int size);
		int getLayerSize(unsigned int layer);

		void setLayerSizes(const vector<int> &sizes);
		vector<int> getLayerSizes();

		void setOutputSize(size_t size);
		int getOutputSize();

		void setInputSize(int size);
		int getInputSize();

		vector<double> getOutput(const vector<double> &inputs);

		void setTransferFunctionType(TransferFunctionType tf);
		TransferFunctionType getTransferFunctionType();

		void randomizeWeights();

		TrainingResult startTraining(const vector<MultilayerPerceptronPattern*> &ts, unsigned int epochs, double errormin, double learningRate = 1, TrainingAlgorithm ta = Backpropagation);
		TrainingResult startTraining(const vector<vector<double> > &inputs, const vector<vector<double> > &targets, unsigned int epochs, double errormin, double learningRate = 1, TrainingAlgorithm ta = Backpropagation);

		TrainingResult getTrainingSnapshot();
		void stopTraining();

		void setAlfa(double a);
		double getAlfa();

	private:

		vector<vector<double> > deltaHidden;
		TrainingResult tr;
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

		void initMLP(int ninputs, int noutputs, const vector<int> &layersizes, const TransferFunctionType &tf);

		vector<vector<double> > getLayerOutputs(const vector<double> &inputs);
};

class RNALIBRARY_EXPORT MultilayerPerceptronPattern : public SimpleInputPattern
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
