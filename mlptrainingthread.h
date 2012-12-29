#ifndef MLPTRAININGTHREAD_H
#define MLPTRAININGTHREAD_H

#include <RNALibrary/multilayerperceptron.h>
#include <QThread>

class MLPTrainingThread : public QThread
{
	public:
		explicit MLPTrainingThread(MultilayerPerceptron *mlp, const vector<vector<double> > &inputs, const vector<vector<double> > &targets, unsigned int epochs, double errormin, double learningRate = 1, MultilayerPerceptron::TrainingAlgorithm ta = MultilayerPerceptron::Backpropagation, QObject *parent = 0);
		explicit MLPTrainingThread(MultilayerPerceptron *mlp, QObject *parent = 0);

		void setTrainingParameters(const vector<vector<double> > &inputs, const vector<vector<double> > &targets, unsigned int epochs, double errormin, double learningRate = 1, MultilayerPerceptron::TrainingAlgorithm ta = MultilayerPerceptron::Backpropagation);
		MultilayerPerceptron::TrainingResult getTrainingSnapshot();

	protected:

		void run();

	private:

		Q_OBJECT

		MultilayerPerceptron::TrainingResult tresult;
		vector<vector<double> > inputs, targets;
		unsigned int epochs;
		double errormin, learningRate;
		MultilayerPerceptron::TrainingAlgorithm ta;
		MultilayerPerceptron *mlp;
		
};

#endif // MLPTRAININGTHREAD_H
