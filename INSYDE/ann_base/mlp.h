#ifndef MLP_H
#define MLP_H

#include <QtCore>

#include <iostream>
#include <vector>
#include <queue>
#include <time.h>

#include "share_ann_base_lib.h"
#include "globals.h"
#include "bptrainingsettings.h"
#include "satrainingsettings.h"
#include "trainingset.h"
#include "mlppattern.h"
#include "mlptrainingresult.h"
#include "artificialneuralnetwork.h"

#include <tbb/concurrent_vector.h>

using namespace std;
using namespace tbb;

namespace ann_base{

class BackpropagationSettings;
class SimulatedAnnealingSettings;
class MultilayerPerceptronPattern;
class TrainingSet;
class MLPTrainingResult;

/*!
 * \class
 *
 * \brief El perceptron multicapa representa un modelo matematico de una o mas capas de neuronas intermedias
 * entre las entradas y las salidas. Estas redes son comunmente entrenadas con el algoritmo Backpropagation, aunque
 * existen otros algoritmos que tambien aplican y que pueden presentar mejor convergencia ante distintos conjuntos
 * de entrenamiento
 *
 * La clase MultilayerPerceptron contiene todas las funciones necesarias para realizar operaciones con
 * perceptrones multicapa. Dicha clace permite crear un Perceptron Multicapa con cualquier cantidad de capas,
 * neuronas internas, entradas y salidas.
 *
 * Ademas se puede realizar el entrenamiento del mismo con diferentes algoritmos y optimizaciones de los mismos.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */

class ANN_BASE_LIB_IMPORT_EXPORT MultilayerPerceptron : public QThread, public ArtificialNeuralNetwork
{
	public:

		/*!
		 * \brief The ClasifierOutputType enum Tipo de salida en el caso de que la red se use como
		 * una red para clasificacion
		 *
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

		/*!
		 * \brief MultilayerPerceptron Instancia de una red multicapa. La red inicialmente se generara con valores aleatorios en sus pesos
		 * sinapticos.
		 * \param [in] ninputs Numero de entradas
		 * \param [in] noutputs Numero de salidas
		 * \param [in] layersizes Tamaños de cada capa
		 * \param [in] tf Funcion de transferencia
		 */
		explicit MultilayerPerceptron(int ninputs, int noutputs, const vector<int> &layersizes, const TransferFunctionType &tf = Sigmoid);

		//		void setLayerWeights(const vector<vector<vector<double> > > &weights);
		//		void setOutputWeights(const vector<vector<double> > &oweights);

		~MultilayerPerceptron();

		/*!
		 * \brief setSaveTrainingResults Establece si se guardaran los datos obtenidos en cada epoca de entrenamiento.
		 * Esto es necesario si, por ejemplo, se necesita graficar los resultados o generar algun reporte posterior.
		 * \param estr Indica si se desea o no guardar los resultados
		 */
		void setSaveTrainingResults(bool estr);

		/*!
		 * \brief getSaveTrainingResults Devuelve \code{true} en caso de que se esten guardando los datos o \code{false} en caso contrario
		 * \return
		 */
		bool getSaveTrainingResults() const;

		/*!
		 * \brief setLayerSize Tama�o de la capa \code{layer}
		 * \param layer Indice de la capa que se redimensionara.
		 * \param size Tama�o que se le asignara a la capa de indice \code{layer}
		 */
		void setLayerSize(unsigned int layer, int size);

		/**
		 * @brief getLayerSize Devuelve el tama�o de la capa @code{layer}
		 * @param layer Indice de la capa que se devolvera
		 * @return Tamaño de la capa con indice @code{layer}
		 */
		int getLayerSize(unsigned int layer) const;

		/**
		 * @brief setLayerSizes Asigna los tamaños de las capas ocultas de la red neuronal
		 * @param sizes Vector con los tamaños de cada capa
		 */
		void setLayerSizes(const vector<int> &sizes);

		/**
		 * @brief getLayerSizes Obtiene un vector con los tamaños de las capas ocultas de la red multicapa
		 * @return Vector de valores enteros que contiene el tamaño de cada capa
		 */
		vector<int> getLayerSizes() const;

		/*!
		 * \brief getLayerCount Returns the number of layers this neural network has
		 * \return
		 */
		int getHiddenLayerCount() const;

		/**
		 * @brief setOutputSize Indica el tamaño de la salida de la red neuronal
		 * @param size Valor que indica el tamaño de la red neuronal
		 */
		void setOutputSize(int size);

		/**
		 * @brief getOutputSize Devuelve el tamaño de la salida de la red neuronal
		 * @return  Valor entero del tamaño de la salida de la red
		 */
		int getOutputsSize();

		/**
		 * @brief setInputSize Asigna el tamaño de la entrada de la red neuronal
		 * @param size Tama�oo que se le asignara a la red
		 */
		void setInputSize(int size);

		/**
		 * @brief getInputSize Devuelve el tamaño de la entrada de esta red neuronal
		 * @return Tamaño de la entrada de la red
		 */
		int getInputsSize();

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
		 * @brief getOutput
		 * @param inputs
		 * @return
		 */
		vector<double> getOutput(const vector<long> &inputs);

		/*!
		 * \brief getClasifierOutput Devuelve las salidas de la red neuronales en la forma de clasificador, los valores de salida
		 * dependeran del valor @code{threshold}, el cual indica el punto en el cual pasara a ser un nivel alto o nivel bajo.
		 * \param inputs Entradas que se le presentan a la red para generar la salida
		 * \param threshold Valor de comparacion para generar las salidas binarias
		 * \param cot Tipo de salida de la red neuronal, Unipolar o Bipolar
		 * \return Vector de salidas de la red neuronal
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
		/*!
		 * \brief randomizeWeights Randomize all weights between a range near to zero. This will make training more
		 * efficient
		 * \param min Minimum random value for weights
		 * \param max Maximum random value for weights
		 */
		void randomizeWeights(double min = -0.01, double max = 0.01);

		/*!
		 * \brief setWeight Sets a particular weight \code{value} inside MLP in layer \code{l}, neuron \code{n} and weight \code{w}.
		 * \param l Indicates the layer where the weight is, where l = getLayerCount() indicates output layer. l = 0
		 * indicates layer 1.
		 * \param n Indicates the neuron where the weight is.
		 * \param w Indicates the index of the weight you want to set.
		 * \param value The value you want to set. Notice that value must be between a valid saturation range.
		 *
		 * \see setSaturationRange();
		 */
		void setWeight(int l, int n, int w, double value);

		/**
		 * @brief startTraining Inicia el entrenamiento de la red neuronal con el algoritmo Backpropagation, para este entrenamiento solo se le presenta
		 * un conjunto de entrenamiento y las configuraciones del algoritmo BackPropagation
		 * @param ts Conjunto de entrenamiento que se le presentara a la red
		 * @param mlpts Configuraciones del algoritmo Backpropagation
		 */
		void startTraining(TrainingSet *ts, BackpropagationSettings *mlpts);

		/**
		 * @brief startTraining Inicializa el entrenamiento de la red neuronal haciendo uso de BP + SA (Backpropagation y Simulated Annealing).
		 * @param ts Conjunto de entrenamiento que se le presentara a la red
		 * @param mlpts Configuracion que tendra el algoritmo backpropagation
		 * @param mlpsats Configuracion que tendra el algoritmo Simulated Annealing
		 */
		void startTraining(TrainingSet *ts,
						   BackpropagationSettings *mlpts,
						   SimulatedAnnealingSettings *mlpsats);

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

		/*!
		 * \brief getTrainingSnapshot Devuelve un puntero al estado actual del entrenamiento
		 *
		 * Esta funcion puede ser llamada en cualquier momento, sin embargo, esta devolvera un puntero
		 * al estado del ultimo entrenamiento que se realizo.
		 *
		 * En caso de que sea llamada mientras se ejecuta algun entrenamiento, se devolvera el estado actual
		 * de dicho entrenamiento (MSE, RMSE, CE, etc).
		 *
		 * El estado del entrenamiento se reseteara automaticamente al llamar \code{randomizeWeights()} o
		 * al iniciar un nuevo entrenamiento.
		 *
		 * Esta funcion es concurrente y realiza un bloqueo mutex antes de devolver el valor.
		 *
		 * \return
		 */
		MLPTrainingResult *getTrainingResult();

		/*!
		 * \brief stopTraining Detiene el entrenamiento que esta actualmente en curso.
		 *
		 * Automaticamente la funcion \code{isTraining()} devuelve false
		 */
		void stopTraining();

		/*!
		 * \brief setAlfa Establece el factor alfa o la pendiente de la funcion de transferencia en caso de ser
		 * tangencial o logaritmica.
		 * \param a Un valor mayor o igual que cero y menor o igual que 1
		 *
		 * \see getAlfa
		 */
		void setAlfa(double a);

		/*!
		 * \brief getAlfa Devuelve el valor del factor alfa de la funcion
		 * \return
		 *
		 * \see setAlfa
		 */
		double getAlfa();

		/*!
		 * \brief getMSE Devuelve el valor del Error Cuadratico Medio (Mean Square Error) para un conjunto de entrenamiento dado
		 * Este es el indicador mas adecuado para medir la convergencia del entrenamiento de cualquier red neuronal.
		 *
		 * \param inputs Conjunto de valores de entrada que se presentaran al Perceptron Multicapa
		 * \param targets Conjunto de valores de salida que se presentaran al Perceptron Multicapa
		 * \return Valor del Error Cuadratico Medio
		 *
		 * \see getRMSE, getCE
		 */
		//		double getMSE(const vector<vector<double> > &inputs, const vector<vector<double> > &targets);
		double getMSE(const vector<vector<double> > &inputs, const vector<vector<double> > &targets);

		/*!
		 * \brief getRMSE Devuelve el valor de la Raiz del Error Cuadratico Medio (Root Mean Square Error). Similar a \code{getMSE} sin embargo
		 * este representa un error medio por cada salida. A diferencia de \code{getMSE} que representa un total del error absoluto
		 * \param inputs Entradas que se le presentaran al Perceptron Multicapa
		 * \param targets Salidas que se le presentaran al Perceptron Multicapa
		 * \return Valor de la Raiz del Error Cuadratico Medio
		 *
		 * \see getMSE, getCE
		 */
		//		double getRMSE(const vector<vector<double> > &inputs, const vector<vector<double> > &targets);
		double getRMSE(const vector<vector<double> > &inputs, const vector<vector<double> > &targets);

		/*!
		 * \brief getCE Devuelve el error de clasificacion el cual es calculado
		 * \param inputs
		 * \param targets
		 * \return Devuelve el error de clasificacion
		 *
		 * \see getRMSE, getMSE
		 */
		double getCE(const vector<vector<double> > &inputs, const vector<vector<double> > &targets);

		/*!
		 * \brief addNoise Agrega ruido a los pesos de la red neuronal con una amplitud \code{a}
		 * \param a Pico maximo de ruido que se le agregara a los pesos sinapticos
		 */
		void addNoise(double a);

		/*!
		 * \brief addLayer Agrega una capa mas al conjunto de capas de la red neuronal
		 * \param nElements Indica el numero de elementos que tendra la nueva capa
		 */
		void addLayer(int nElements);

		/*!
		 * \brief insertLayer
		 * \param after
		 * \param elements
		 *
		 */
		void insertLayer(int after, int elements);

		/*!
		 * \brief removeLayer This method remove layer with index \code{l} from this neural network if it is possible.
		 * You can not remove output layer nor input layer. Multilayer Perceptron has to have one or more layers. When
		 * any layer is removed all weights will be randomized.
		 *
		 * \param layer The layer will be removed. Index 0 correspond to the first layer and so on.
		 */
		void removeLayer(unsigned int l);

		/*!
		 * \brief isTraining Indica si en este momento se esta o no entrenando la red neuronal.
		 * \return Devuelve \code{true} en caso de que se este llevando a cabo un entrenamiento y \code{false} en caso contrario
		 */
		bool isTraining();

		/*!
		 * \brief setElapsedEpochsTrigger Establece el intervalo de epocas en el que se disparara el evento \code{elapsedEpochs()}
		 *
		 * Este metodo es especialmente importante si el usuario quiere realizar una actualizacion de datos transcurrida cierta cantidad
		 * de epocas.
		 *
		 * \param trigger
		 */
		void setElapsedEpochsTrigger(int trigger);

		/*!
		 * \brief setEnableElapsedEpochsEvent Activa o desactiva el evento \code{elapsedEpochs()}
		 *
		 * \param en Indica si se desea activar o no el evento \code{elapsedEpochs()}
		 */
		void setEnabledElapsedEpochsEvent(bool en);

		/*!
		 * \brief getEnabledElapsedEpochsEvent Indica si esta activo o no el evento \code{elapsedEpochs()}
		 * \return Devuelve \code{true} en caso de que este activo y \code{false} en caso contrario
		 */
		bool getEnabledElapsedEpochsEvent() const;

		/*!
		 * \brief setElapsedTimeTrigger Establece el intervalo de tiempo en el que se disparara el evento \code{elapsedTime()}
		 *
		 * Con este metodo se puede establecer un rango de tiempo para que se dispare el evento mencionado anteriormente. Especialmente
		 * importante cuando se necesita un intervalo de actualizacion fijo. En casos donde las redes neuronales sean muy complejas puede
		 * haber un largo tiempo entre cada epoca, por lo cual no es aconsejable el uso del evento \code{elapsedEpochs()}
		 * \param mili
		 */
		void setElapsedTimeTrigger(int mili);

		/*!
		 * \brief setEnableElapsedTimeEvent Activa o desactiva el evento \code{elapsedTime()}
		 * \param en
		 */
		void setEnabledElapsedTimeEvent(bool en);

		/*!
		 * \brief getEnabledElapsedTimeEvent Indica si esta activo el evento \code{elapsedTime()}
		 * \return Devuelve \code{true} en caso de estar activo y \code{false} en caso contrario
		 */
		bool getEnabledElapsedTimeEvent() const;

		/*!
		 * \brief getType
		 * \return
		 */
		Type getType() const;

		/*!
		 * \brief getName
		 * \return
		 */
		QString getName() const;

		/*!
		 * \brief setSaturationRange Establish maximum and minimum weight value for any synaptic conection between
		 * neurons, this values must be stablished acording to any specific application to avoid weight saturation.
		 *
		 * It is recommended to set a balanced range, this means \code{max} and \code{min} must have an equal absolute
		 * value but \code{min} has to have a negative value. Remember weights can take real values (positive and negative
		 * floating point).
		 *
		 * Considere \code{min} must be less than \code{max}, otherwise behavior is undefined.
		 *
		 * \param min Minimum saturation value
		 * \param max Maximum saturation value
		 */
		void setSaturationRange(double min, double max);

		/*!
		 * \brief getWeights Returns a 3D vector with all weights in this MLP, including output weights.
		 * First index correspond to a layer, second index correspond to a neuron and third index correspond to a weight.
		 *
		 * \return A 3D vector with all weights in this MLP.
		 */
		vector<vector<vector<double> > > getWeights() const;

		/*!
		 * \brief setDefaultRandomRange
		 * \param min
		 * \param max
		 */
		void setDefaultRandomRange(double min, double max);

		/*!
		 * \brief getDefaultRandomRange
		 * \return
		 */
		pair<double, double> getDefaultRandomRange() const;

		/*!
		 * \brief setDefaultRandomMinimum
		 * \param min
		 */
		void setDefaultRandomMinimum(double min);

		/*!
		 * \brief getDefaultRandomMinimum
		 * \return
		 */
		double getDefaultRandomMinimum() const;

		/*!
		 * \brief setDefaultRandomMaximum
		 * \param max
		 */
		void setDefaultRandomMaximum(double max);

		/*!
		 * \brief getDefaultRandonMaximum
		 * \return
		 */
		double getDefaultRandonMaximum() const;

	signals:

		/*!
		 * \brief trainingAboutStart
		 */
		void trainingAboutStart();

		/*!
		 * \brief trainingFinished Esta se�al se dispara cuando el entrenamiento se ha finalizado
		 */
		void trainingFinished();

		/*!
		 * \brief trainingFinished Esta se�al se dispara cuando el entrenamiento se ha finalizado
		 * \param tres Contiene los datos del entrenamiento en caso de que \code{setSaveTrainingResults()} haya sido activado
		 */
		void trainingFinished(const MLPTrainingResult tres);

		/*!
		 * \brief elapsedEpochs Esta se�al es lanzada cuando cierto numero de epocas han transcurrido.
		 * \param tres Contiene los datos del entrenamiento en caso de que \code{setElapsedEpochsTrigger()} haya sido activado
		 */
		void elapsedEpochs(const MLPTrainingResult tres);

		/*!
		 * \brief elapsedTime Esta se�al es lanzada a intervalos de tiempo establecidos por \code{setElapsedTimeTrigger()}.
		 * Solo es lanzada durante el entrenamiento. Es frecuentemente utilizada para graficar o actualizar informacion
		 * a intervalos de tiempo fijos
		 * \param tres Contiene los datos del entrenamiento en caso de que \code{setSaveTrainingResults()} haya sido activado
		 */
		void elapsedTime(const MLPTrainingResult tres);

		/*!
		 * \brief appendRecord Esta se�al es lanzada internamente para almacenar los datos de entrenamiento en la variable \code{tres}
		 * Esta se�al no debe ser utilizada fuera de la clase ya que podria ser contraproducente.
		 * \param mse Mean Square Error
		 * \param rmse Root Mean Square Error
		 * \param ce Clasification Error
		 */
		void appendRecord(double mse, double rmse, double ce);

		/*!
		 * \brief weightsChanged
		 */
		void weightsChanged();

		/*!
		 * \brief layerCountChanged
		 * \param last
		 * \param newCount
		 */
		void layerCountChanged(int last, int newCount);

		/*!
		 * \brief layerCountChanged
		 */
		void layerCountChanged();

		void outputSizeChanged();

		void outputSizeChanged(int lastSize, int newSize);

		void layerRemoved(int index);

		void layerSizeChanged(int layer, int lastSize, int newSize);

		void layerSizeChanged(int layer);

	protected:

		/*!
		 * \brief run Inicia un hilo donde se realizara el entrenamiento de la red neuronal. Este hilo se usa unicamente para dicho entrenamiento.
		 */
		void run();

	private slots:

		/*!
		 * \brief finished Este slot escuchado cuando se termina el procesamiento paralelo.
		 */
		void finished();

		/*!
		 * \brief onTimeTrigger Comienza la escucha de este slot cuando ha transcurrido el intervalo de tiempo establecido por
		 * \code{setElapsedTimeTrigger()}
		 */
		void onTimeTrigger();

		/*!
		 * \brief onRecordAppened Comienza la escucha de este slot para iniciar el proceso de agregar al registro de datos de entrenamiento
		 *
		 * \param mse Mean Square Error
		 * \param rmse Root Mean Square Error
		 * \param ce Clasification Error
		 */
		void onRecordAppened(double mse, double rmse, double ce);

	private:

		Q_OBJECT

		QTimer timeTrigger;

		double
		alfa,
		minSat,
		maxSat,
		defaultRandomMinimum,
		defaultRandomMaximum;

		int
		timeTriggerInterval,
		epochsTriggerInterval,
		nInputs;

		bool
		timeTriggerEnabled,
		epochsTriggerEnabled,
		training,
		sa,
		enabledSaveTrainingResults;

		struct NewState{
			public:
				vector<vector<vector<double> > > newWeights;
				vector<vector<double> > newOutputWeights;
		};

		TrainingSet *ts;
		BackpropagationSettings *mlpbpts;
		SimulatedAnnealingSettings *mlpsats;

		ClasifierOutputType cot;

		MLPTrainingResult
		*tres;

		/*!
		 * \brief outputWeights By convention this variable should be converted to concurrent_vector
		 */
		vector<vector<double> > outputWeights;

		/*!
		 * \brief layerWeights By convention this variable should be converted to concurrent_vector
		 */
		vector<vector<vector<double> > > layerWeights;

		TransferFunctionType tf;

		/*!
		 * \brief init
		 * \param ninputs
		 * \param noutputs
		 * \param layersizes
		 * \param tf
		 */
		void init(int ninputs, int noutputs, const vector<int> &layersizes, const TransferFunctionType &tf);

		/*!
		 * \brief getLayerOutputs Return an output matrix obtained from \code{inputs}.
		 * Each value belong to a respective neuron on each layer
		 * \param inputs
		 * \return
		 */
		vector<vector<double> > getLayerOutputs(const vector<double> &inputs);

		/*!
		 * \brief addNoise
		 * \param min
		 * \param max
		 * \return
		 */
		NewState addNoise(double min, double max);

		/*!
		 * \brief getNewMSE
		 * \param lweights
		 * \param oweights
		 * \param inputs
		 * \param targets
		 * \return
		 */
		double getNewMSE(const vector<vector<vector<double> > > &lweights, const vector<vector<double> > &oweights, const vector<vector<double> > &inputs, const vector<vector<double> > &targets);

		/*!
		 * \brief getAuxOutput Return an output with a diferent set of weights.
		 * \param lweights
		 * \param outputWeights
		 * \param inputs
		 * \return
		 */
		vector<double> getAuxOutput(const vector<vector<vector<double> > > &lweights, const vector<vector<double> > &outputWeights, const vector<double> &inputs);

		/*!
		 * \brief getCorrectValue Check if \code{value} is between \code{minSat} and \code{maxSat} values. In negative
		 * case, it will correct value and adjust to \code{minSat} or \code{maxSat} depending of case.
		 *
		 * \param value Value to be corrected.
		 * \return
		 */
		double getCorrectValue(double value);
};
}

#endif // MLP_H
