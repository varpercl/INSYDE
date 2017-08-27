#ifndef ADALINE_H
#define ADALINE_H

#include <QtCore>

#include "share_ann_base_lib.h"
#include "../core/imath.h"
#include "../core/common.h"
#include "artificialneuralnetwork.h"
#include "adalinetrainingpattern.h"

#include <vector>
#include <time.h>


namespace ann_base{

using namespace std;

/*!
 * \brief The Adaline class represent one basic ANN topology which consist in one neuron with
 * only one output with a transfer function.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_BASE_LIB_IMPORT_EXPORT Adaline : public ArtificialNeuralNetwork
{
	public:

		/*!
		 * \brief The WeightUpdateType enum indicates the way the ADALINE weights are updated.
		 * This influences the way the ADALINE is trained.
		 *
		 * \author Edixon V
		 */
		enum WeightUpdateType{
			ContinuousUpdate, /*!< Updates every weight everytime an input/target pair is presented */
			BatchUpdate /*!< Updates all weights once all patterns have been passed to the training algorithm */
		};

		/*!
		 * \brief The TrainResult struct stores all information about a in-course or finished training,
		 * information like epochs to finish the training, a weight history of every weight, this is
		 * ideal if we want to graph or analyse how every weight runs over its training routine.
		 */
		struct TrainResult{
				int epochs; /*!< Indicates the number of epochs until now */
				vector<double> errorHistory; /*!< A history of the error through the training routine */
				vector<vector<double> > weightHistory; /*!< The history of weight changes */
				vector<double> thresholdHistory; /*!< The change history of the threshold */
		};

		/*!
		 * \brief The TransferFunctionType enum indicates the transfer function types for a simple perceptron.
		 */
		enum TransferFunctionType{
			Sigmoid, /**!< Indicates the transfer function is y = 1 / (1 + exp(-alpha * suminputs)) */
			Linear /**!< The transfer function is y = suminputs */
		};

		/*!
		 * \brief Creates an ADALINE with \p ninputs.
		 * \param ninputs The number of inputs of this ADALINE.
		 * \param tf The transfer function.
		 */
		explicit Adaline(int ninputs, TransferFunctionType tf);

		/*!
		 * \brief Creates an ADALINE object with a determined list of \p weights.
		 * \note \p weights pointer should point to an array of values with the same size of ninputs.
		 *
		 * \param ninputs The number of inputs.
		 * \param weights The pointer to the list of weights.
		 * \param tf The transfer function.
		 */
		explicit Adaline(int ninputs, double *weights, TransferFunctionType tf);

		/*!
		 * \brief Creates an ADALINE with a determined list of \p weights.
		 *
		 * \note The number of inputs will be the same of the \p weights size.
		 *
		 * \param weights The weights list.
		 * \param tf The transfer function.
		 */
		explicit Adaline(const vector<double> &weights, TransferFunctionType tf);

		/*!
		 * \brief Establish the number of inputs of this ADALINE object.
		 * \param n The number of inputs.
		 */
		void setNumberInputs(size_t n);

		/*!
		 * \brief Returns the number of inputs of this ADALINE.
		 * \return The number of inputs.
		 */
#define getInputsCount getNumberInputs
		int getNumberInputs();

		/*!
		 * \brief Returns the inputs of this ADALINE.
		 *
		 * \note The inputs can be modified when accessing to this pointer.
		 *
		 * \return A pointer to the list of inputs of this ADALINE.
		 */
		double *getInputs();

		/**
			Establece los pesos sinapticos actuales de este perceptron.

			@param double *w Puntero a un arreglo de pesos sinapticos. Se tomaran solo el numero de valores correspondientes al numero de entradas, por eso no es necesario especificar el numero de valores que se tomara de este puntero.
			*/
		/*!
		 * \brief Establish a list of weights of this ADALINE.
		 * \param w A pointer with a list of weights.
		 *
		 * \note The pointer array should be the same size as getNumberInputs
		 */
		void setWeights(double *w);

		/**
			Establece los pesos sinapticos actuales de este ADALINE. En este metodo
			se incluye un parametro @code{ninputs} que modifica el numero de entradas
			del ADALINE (si es diferente). A diferencia de @code{setWeights(double *w)}
			que asigna los pesos de acuerdo al numero de entradas que actualmente tiene
			asignado el ADALINE

			@param double *w Puntero a un arreglo de pesos sinapticos. Se tomaran solo el numero de valores correspondientes al numero de entradas, por eso no es necesario especificar el numero de valores que se tomara de este puntero.
			@param int ninputs Numero de entradas que se asignaran al ADALINE
			*/

		/*!
		 * \brief Establish the weights of this ADALINE object. In this case, this method
		 * can modify the number of inputs of the current ADALINE.
		 *
		 * \param ninputs The number of inputs.
		 * \param w A pointer with a list of weights.
		 */
		void setWeights(int ninputs, double *w);

		/*!
		 * \brief Establish the weights of this ADALINE object.
		 *
		 * \note The vector \p w should be the same size as the inputs count of this object.
		 *
		 * \param w The list of weights.
		 *
		 * TODO: implements a second parameter (possibly alterSize) which ask users if want to
		 * set the current inputs number to the same size of the \p w vector.
		 */
		void setWeights(const vector<double> &w);

		/**
			Establece el valor de un peso a la vez indicandole el indice @code{pos}

			@param int pos Indice del peso que se actualizara
			@param double value Valor que se le asignara al peso en la posicion @code{pos}
			*/
		/*!
		 * \brief Establish the value of the weight \p n to \p value.
		 * \param n The index of the weight.
		 * \param value The new value.
		 */
		void setWeight(int n, double value);

		/*!
		 * \brief Returns the pointer to the weights list.
		 * \return A pointer to the weights list.
		 */
		double *getWeights();

		/*!
		 * \brief Returns the list of weights.
		 *
		 * \note This returned object will be a copy of the values.
		 *
		 * \return A vector object with the copy of the values.
		 */
		vector<double> getWeightVector();

		/*!
		 * \brief Returns a reference to the current weights list.
		 * \return The weight list.
		 */
		inline vector<double> &getRefWeightVector(){return weights;}

		/*!
		 * \brief Establish the threeshold of the transfer function.
		 * \param value The threshold value.
		 */
		void setThreshold(double value);

		/**
			Obtiene el valor de disparo de la funcion de transferencia

			@return double Valor de disparo actual de la funcion de transferencia.

			@see setThreshold
			*/
		double getThreshold();

		/*!
		 * \brief Establish the transfer function type to \p tf.
		 * \param tf The new transfer function.
		 */
		void setTransferFunction(TransferFunctionType tf);

		/*!
		 * \brief Returns the current transfer function.
		 * \return The transfer function type.
		 */
		TransferFunctionType getTransferFunction();

		/**
		  Inicia el entrenamiento con un conjunto de entrenamiento donde
		  @code{inputs} es un conjunto de entradas y @code{targets} es el conjunto de salidas
		  deseadas para ese conjunto de entradas.

		  @param vector<vector<double> > &inputs Conjunto de entradas
		  @param vector<double> &targets Conjunto de valores deseados para cada muestra de entradas
		  @param int error Error maximo antes de que se detenga el entrenamiento
		  @param int nEpochs Numero maximo de epocas de entrenamiento
		  @param double learningFactor Indica la rapidez con la cual el perceptron aprendera
		  */
		/*!
		 * \brief Starts the training process with a determined start condition.
		 * \param inputs The list of inputs of the trainit set.
		 * \param targets The targets of the training set.
		 * \param error The minimum error to stop training.
		 * \param nEpochs The maximum epochs to stop trainint.
		 * \param learningFactor The learning factor of the transfer function.
		 * \param wut The way the weights will be updated.
		 * \return Returns the training result.
		 */
		TrainResult train(const vector<vector<double> > &inputs, const vector<double> &targets, double error, int nEpochs, double learningFactor, WeightUpdateType wut = BatchUpdate);

		/*!
		 * \brief train
		 * \param ts
		 * \param error
		 * \param nEpochs
		 * \param learningFactor
		 * \param wut
		 * \return
		 */
		TrainResult train(vector<AdalineTrainingPattern> &ts, double error, int nEpochs, double learningFactor, WeightUpdateType wut = BatchUpdate);

		/**
			Obtiene la salida actual de este perceptron dada un conjunto de datos de entrada presentado.

			@param vector<double> &data Conjunto de datos de entrada para calcular la salida.
			@param double alfa Indica la pendiente de la funcion de transferencia en algunas donde es necesario como

			@return double Respuesta que genera este perceptron ante la entrada @code{data}
			*/
		/*!
		 * \brief getOutput
		 * \param data
		 * \return
		 */
		double getOutput(const vector<double> &data);

		/**
		  Establece todos los pesos sinapticos incluyendo el umbral
		  en un valor aleatorio.
		  */
		void randomizeWeights(double min = -1, double max = 1);

		/**
		  Establece el valor alfa de la funcion de transferencia. El factor alfa
		  es una constante que determina la pendiente de la curva de salida de la
		  funcion de transferencia.

		  El valor alfa esta permitido solo entre 0 y 1. Si esta fuera de ese rango
		  se ajustara al valor mas proximo

		  @param double value Valor del factor alfa
		  */
		void setAlfa(double value);

		/**
		  Devuelve el valor del factor alfa

		  @return double Valor de alfa
		  */
		double getAlfa();

		Type getType() const;
		QString getName() const;

	private:

		//Factor de crecimiento en la funcion de transferencia de salida
		double alfa;

		//Vector de pesos sinapticos de este perceptron
		vector<double> weights;

		//Valor del bias o threshold de este perceptron
		double threshold;

		//Funcion de transferencia que se utilizara en este perceptron
		TransferFunctionType tf;

		/**
		  Inicializa este perceptron a partir de un puntero a un arreglo de entradas, y un puntero a un
		  arreglo de pesos sinapticos, otros parametros tambien son pasados como el threshold y la funcion
		  de transferencia.

		  @param double *inputs Puntero a un arreglo de valores de entrada.
		  @param int ninputs Numero de entradas que se consideraran de el puntero de entradas
		  @param double *weights Puntero a un arreglo de pesos sinapticos.
		  @param double bias Valor de disparo de la funcion de transferencia
		  @param TransferFunctionType tf Funcion de transferencia que tendra este perceptron

		  */
		void init(int ninputs, double *weights, TransferFunctionType ft);

		/**
		  Inicializa el perceptron a partir de un arreglo de entradas, y los pesos sinapticos seran asignados aleatoriamente

		  @param double *inputs Puntero a un arreglo de entradas
		  @param int ninputs Numero de entradas que se consideraran del puntero @code{inputs}
		  @param double threshold Punto de disparo de la funcion de transferencia
		  @param TransferFunctionType tf Funcion de transferencia que tendra este perceptron

		  */
		void init(int ninputs, TransferFunctionType ft);

		/**
		  Inicializa un perceptron con un vector de entradas, un vector de pesos, un valor de disparo, asi commo
		  tambien una funcion de transferencia.

		  A cada indice de las entradas inputs le corresponde el elemento en la misma posicion del vector de pesos,
		  es decir, cada entrada tiene su peso asignado, por lo cual el tamaño de inputs debe ser igual al tamaño de
		  weights, de lo contrario ocurrira un error.

		  @param vector<double> inputs Vector con las entradas que tendra este perceptron
		  @param vector<double> weights Vector con los pesos sinapticos asignados a cada entrada
		  @param double threshold Valor de disparo de la funcion de transferencia
		  @param TransferFunctionType tf Funcion de transferencia de este perceptron
		  */
		void init(const vector<double> &weights, TransferFunctionType tf);

};

}

#endif // ADALINE_H

