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

class MLPBackpropagationTrainingSettings;
class MLPSimulatedAnnealingTrainingSettings;
class MultilayerPerceptronPattern;
class TrainingSet;
class MLPTrainingResult;


class ANNFRAMEWORK_EXPORT MultilayerPerceptron : public QThread
{
	public:

		/**
		 * @brief The StopCondition enum Indica cual es el criterio de parada para el entrenamiento de esta red
		 */
		enum StopCondition{
			MSE,
			RMSE,
			CE
		};

		/**
		 * @brief The ClasifierOutputType enum Tipo de salida en el caso de que la red se use como
		 * una red para clasificacion
		 */
		enum ClasifierOutputType{
			UnipolarClasifier,
			BipolarClasifier
		};

		/**
		 * @brief The TrainingAlgorithm enum Tipos de entrenamientos que se pueden aplicar a la red neuronal
		 */
		enum TrainingAlgorithm{
			Backpropagation,
			SimulatedAnnealing,
			GradientDescendent,
			ScaledConjugateGradient
		};

		/**
		 * @brief The TransferFunctionType enum Tipos de funciones de transferencia para esta red
		 */
		enum TransferFunctionType{
			Sigmoid,
			Tanh
		};

		/**
		 * @brief MultilayerPerceptron Instancia de una red multicapa. La red inicialmente se generara con valores aleatorios en sus pesos
		 * sinapticos.
		 * @param ninputs Numero de entradas
		 * @param noutputs Numero de salidas
		 * @param layersizes Tamaños de cada capa
		 * @param tf Funcion de transferencia
		 */
		explicit MultilayerPerceptron(int ninputs, int noutputs, const vector<int> &layersizes, const TransferFunctionType &tf);

		//		void setLayerWeights(const vector<vector<vector<double> > > &weights);
		//		void setOutputWeights(const vector<vector<double> > &oweights);

		~MultilayerPerceptron();

		/**
		 * @brief setLayerSize Tamaño de la capa @code{layer}
		 * @param layer Indice de la capa que se redimensionara.
		 * @param size Tamaño que se le asignara a la capa de indice @code{layer}
		 */
		void setLayerSize(unsigned int layer, int size);

		/**
		 * @brief getLayerSize Devuelve el tamaño de la capa @code{layer}
		 * @param layer Indice de la capa que se devolvera
		 * @return Tamaño de la capa con indice @code{layer}
		 */
		int getLayerSize(unsigned int layer);

		/**
		 * @brief setLayerSizes Asigna los tamaños de las capas ocultas de la red neuronal
		 * @param sizes Vector con los tamaños de cada capa
		 */
		void setLayerSizes(const vector<int> &sizes);

		/**
		 * @brief getLayerSizes Obtiene un vector con los tamaños de las capas ocultas de la red multicapa
		 * @return Vector de valores enteros que contiene el tamaño de cada capa
		 */
		vector<int> getLayerSizes();

		/**
		 * @brief setOutputSize Indica el tamaño de la salida de la red neuronal
		 * @param size Valor que indica el tamaño de la red neuronal
		 */
		void setOutputSize(size_t size);

		/**
		 * @brief getOutputSize Devuelve el tamaño de la salida de la red neuronal
		 * @return  Valor entero del tamaño de la salida de la red
		 */
		int getOutputSize();

		/**
		 * @brief setInputSize Asigna el tamaño de la entrada de la red neuronal
		 * @param size Tamaño que se le asignara a la red
		 */
		void setInputSize(int size);

		/**
		 * @brief getInputSize Devuelve el tamaño de la entrada de esta red neuronal
		 * @return Tamaño de la entrada de la red
		 */
		int getInputSize();

		/**
		 * @brief getOutput Devuelve un vector con los valores de las salidas de la red neuronal, dada las entradas (double)
		 * @code{inputs}
		 * @param inputs Vector de entradas
		 * @return Vector de salidas
		 */
		vector<double> getOutput(const vector<double> &inputs);

		/**
		 * @brief getOutput Devuelve un vector con los valores de las salidas de la red neuronal, dada las entradas (int)
		 * @code{inputs}
		 * @param inputs Vector de entradas
		 * @return Vector de salidas
		 */
		vector<double> getOutput(const vector<int> &inputs);

		/**
		 * @brief getClasifierOutput Devuelve las salidas de la red neuronales en la forma de clasificador, los valores de salida
		 * dependeran del valor @code{threshold}, el cual indica el punto en el cual pasara a ser un nivel alto o nivel bajo.
		 * @param inputs Entradas que se le presentan a la red para generar la salida
		 * @param threshold Valor de comparacion para generar las salidas binarias
		 * @param cot Tipo de salida de la red neuronal, Unipolar o Bipolar
		 * @return Vector de salidas de la red neuronal
		 */
		vector<int> getClasifierOutput(const vector<double> &inputs, double threshold, ClasifierOutputType cot);

		/**
		 * @brief setTransferFunctionType Indica el tipo de funcion de transferencia con la cual trabajara esta red neuronal
		 * @param tf Parametro que indica la funcion de transferencia
		 */
		void setTransferFunctionType(TransferFunctionType tf);

		/**
		 * @brief getTransferFunctionType Devuelve la funcion de transferencia de la red neuronal
		 * @return Funcion de transferencia usada para la red neuronal
		 */
		TransferFunctionType getTransferFunctionType();

		/**
		 * @brief randomizeWeights Aleatoriza los pesos, dados un rango de valores
		 * @param min Valor minimo de aleatorizacion
		 * @param max Valor maximo de aleatorizacion
		 */
		void randomizeWeights(double min = -1, double max = 1);

		/**
		 * @brief startTraining Inicia el entrenamiento de la red neuronal con el algoritmo Backpropagation, para este entrenamiento solo se le presenta
		 * un conjunto de entrenamiento y las configuraciones del algoritmo BackPropagation
		 * @param ts Conjunto de entrenamiento que se le presentara a la red
		 * @param mlpts Configuraciones del algoritmo Backpropagation
		 */
		void startTraining(TrainingSet *ts, MLPBackpropagationTrainingSettings *mlpts);

		/**
		 * @brief startTraining Inicializa el entrenamiento de la red neuronal haciendo uso de BP + SA (Backpropagation y Simulated Annealing).
		 * @param ts Conjunto de entrenamiento que se le presentara a la red
		 * @param mlpts Configuracion que tendra el algoritmo backpropagation
		 * @param mlpsats Configuracion que tendra el algoritmo Simulated Annealing
		 */
		void startTraining(TrainingSet *ts,
									 MLPBackpropagationTrainingSettings *mlpts,
									 MLPSimulatedAnnealingTrainingSettings *mlpsats);

		/**
		 *	@deprecated Este metodo ya no es usado
		 * @brief startTraining Inicializa el entrenamiento de la red neuronal indicandole los parametros de condicion de parada
		 * @param ts Conjunto de entrenamiento
		 * @param epochs Epocas maximas que tomara el entrenamiento
		 * @param MSEmin MSE minimo para parar el entrenamiento
		 * @param RMSEmin RMSE minimo para parar el entrenamiento
		 * @param CEmin CE minimo para parar el entrenamiento
		 * @param learningRate Tasa de aprendizaje
		 * @param sc Condicion de parada que sera considerada a la hora de detener el entrenamiento
		 */
		void startTraining(TrainingSet *ts,
									 unsigned int epochs,
									 double MSEmin,
									 double RMSEmin,
									 double CEmin,
									 double learningRate = 1,
									 StopCondition sc = MSE);
		/**
		 *	@deprecated Este metodo ya no es usado
		 * @brief startTraining Inicializa el entrenamiento de la red neuronal indicandole los parametros de condicion de parada
		 * @param ts Conjunto de entrenamiento de la red neuronal
		 * @param epochs Numero maximo de epocas que tardara el entrenamiento
		 * @param MSEmin MSE minimo para detener el entrenamiento
		 * @param RMSEmin RMSE minimo para detener el entrenamiento
		 * @param CEmin CE minimo para detener el entrenamiento
		 * @param learningRate Tasa de aprendizaje
		 * @param sc Condicion de parada que sera considerada para detener el entrenamiento
		 */
		void startTraining(const vector<MultilayerPerceptronPattern*> &ts,
									 unsigned int epochs,
									 double MSEmin,
									 double RMSEmin,
									 double CEmin,
									 double learningRate = 1,
									 StopCondition sc = MSE);

		/**
		 * @deprecated
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

		MLPTrainingResult *getTrainingSnapshot();
		void stopTraining();

		void setAlfa(double a);
		double getAlfa();

		double getMSE(const vector<vector<double> > &inputs, const vector<vector<double> > &targets);
		double getRMSE(const vector<vector<double> > &inputs, const vector<vector<double> > &targets);
		double getCE(const vector<vector<double> > &inputs, const vector<vector<double> > &targets);

		void addNoise(double a);
//		void setOutputType(ClasifierOutputType ot);
//		ClasifierOutputType getOutputType();

		bool isTraining();

	signals:
		void trainingFinished(MLPTrainingResult *tres);

	protected:
		void run();

	private slots:
		void finished();

	private:
		Q_OBJECT

		struct NewState{
				vector<vector<vector<double> > > newWeights;
				vector<vector<double> > newOutputWeights;
		};

		QReadWriteLock rwlock;
//		QMutex mutex;
		TrainingSet *ts;
		MLPBackpropagationTrainingSettings *mlpbpts;
		MLPSimulatedAnnealingTrainingSettings *mlpsats;
		bool sa;

		ClasifierOutputType ot;

		vector<vector<double> > deltaHidden;
		MLPTrainingResult *tres;
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

class ANNFRAMEWORK_EXPORT MLPBackpropagationTrainingSettings
{
	public:

//		enum EfficiencyMeasure{
//			MeanSquareError,
//			RootMeanSquareError,
//			ClasificationError
//		};

		explicit MLPBackpropagationTrainingSettings();
		explicit MLPBackpropagationTrainingSettings(unsigned int epochs, double MSEmin, double RMSEmin, double CEmin, double learningRate, MultilayerPerceptron::StopCondition sp);
		explicit MLPBackpropagationTrainingSettings(unsigned int epochs, MultilayerPerceptron::StopCondition em, double emValue, double learningRate);

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

		void setStopParameter(MultilayerPerceptron::StopCondition em);
		MultilayerPerceptron::StopCondition getStopParameter() const;

//		void setStopParameterValue(double value);
//		double getStopParameterValue();

		MLPBackpropagationTrainingSettings operator=(const MLPBackpropagationTrainingSettings &mlpbp);

	private:

		MultilayerPerceptron::StopCondition em;
		unsigned int epochs;
		double MSEmin;
		double RMSEmin;
		double CEmin;
		double stopParameterValue;

		double learningRate;

		void initMLPBTS(unsigned int epochs, double MSEmin, double RMSEmin, double CEmin, double learningRate, MultilayerPerceptron::StopCondition em);
		void initMLPBTS(unsigned int epochs, MultilayerPerceptron::StopCondition em, double emValue, double learningRate);
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
