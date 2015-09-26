#ifndef SIMPLEPERCEPTRON_H
#define SIMPLEPERCEPTRON_H

#ifdef QT_CORE_LIB
#include <QtCore>
#endif

#include "../core/common.h"
#include "trainingset.h"
#include "simplepattern.h"
#include "artificialneuralnetwork.h"

#include <vector>
#include <math.h>
#include <time.h>

namespace ann_base{

using namespace std;

class PerceptronTrainingPattern;
/*!
 * \class
 *
 * \brief Es uno de los modelos mas simples de redes neuronales
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class Q_DECL_EXPORT SimplePerceptron : public ArtificialNeuralNetwork
{

	public:

		/**
		  Contiene informacion sobre el resultado de un entrenamiento, como el numero
		  de epocas que le tomo el entrenamiento, un historial de cambios de los pesos
		  sinapticos, que lo hace ideal si queremos realizar graficas o analisis del
		  avance de los mismos.
		  */
		struct TrainResult{
				int epochs;
				vector<double> changedWeights;
				vector<vector<double> > weightHistory;
				vector<double> thresholdHistory;
		};

		/**
		  Establece que regla de aprendizaje utilizara este perceptron
		  */
		enum LearningRule{
			SimpleRule,
			DeltaRule
		};

		/**
		  @enum TransferFunctionType

		  Indica los tipos de funciones de transferencias para un perceptron simple

		  Parametros:

		  alpha = Indica la pendiente de la funcion de transferencia, solamente es considerado en algunos casos
		  suminput = Sumatoria de todas las entradas multiplicadas por los pesos correspondientes

		  @name Threshold Funcion tipo escalon unitario si la sumatoria es mayor que cero la salida sera 1
		  @name Signus Parecida a la funcion threshold salvo que tiene los valores -1 y 1
		  @name Log Esta funcion es del tipo y = 1 / (1 + exp(-alpha*suminputs))
		  @name Tanh Esta funcion es del tipo y = tanh(suminputs/2) = (1 - exp(-alpha*suminputs))/(1 + exp(-alpha*suminputs))
		  @name Linear La funcion @code{Linear} es igual al valor de la sumatoria, es decir, y = suminputs
		  @name LimitedLinear Similar a @code{Linear} salvo que en este caso esta limitada en 0 y 1
		  @name SimetricLimitedLinear Similar a @code{Linear} salvo que en este caso esta limitada en -1 y 1
		  */
		enum TransferFunctionType{
			Step,
			Bipolar,
			Sigmoid,
			Tanh,
			Linear,
			LimitedLinear,
			SimetricLimitedLinear
		};

		/**
		  Crea un objeto SimplePerceptron con un numero de entradas @code{ninputs} inicialmente puestas en 0
		  y una funcion de transferencia.

		  @param int ninputs Numero de entradas que tendra este perceptron
		  @param TransferFunctionType tf Funcion de transferencia.
		  */
		explicit SimplePerceptron(int ninputs, TransferFunctionType tf = Step, LearningRule lr = SimpleRule);

		/**
		  Crea una instancia de SimplePerceptron con un puntero a un arreglo de valores de entrada, al igual
		  que un puntero a los pesos sinapticos, un threshold y una funcion de transferencia.

		  @param double *inputs Puntero que indica la direccion de un arreglo de entradas ya preestablecidas
		  @param int ninputs Numero de entradas que se consideraran de el arreglo @code{inputs}
		  @param double *weights Puntero a un arreglo de pesos sinapticos, el tamaño sera el mismo que @code{ninputs}
		  @param double threshold Valor de disparo de la funcion de transferencia.
		  @param TranferFunctionType tf Funcion de transferencia que se le asignara a este perceptron

		  */
		explicit SimplePerceptron(int ninputs, double *weights, TransferFunctionType tf = Step, LearningRule lr = SimpleRule);

		/**
		  Crea un objeto de SimplePerceptron con un vector de entradas y un vector de pesos sinapticos, asimismo se
		  inicializa el valor de disparo de la funcion de transferencia y se le asigna una funcion de transferencia.

		  @param vector<double> inputs Vector que contiene las entradas de este perceptron.
		  @param vector<double> weights Vector que contiene los pesos sinapticos de cada entrada
		  @param double threshold Valor de disparo de la funcion de transferencia
		  @param TransferFunctionType tf Tipo de funcion de transferencia que se le asignara
		  */
		explicit SimplePerceptron(vector<double> weights, TransferFunctionType tf = Step, LearningRule lr = SimpleRule);

		/**
		  Establece el numero de entradas de este perceptron. Al utilizarse esta funcion
		  automaticamente todos los pesos sinapticos se estableceran en valores aleatorios

		  @param int n Numero de entradas que tendra este perceptron
		  */
		void setInputSize(size_t n);

		/**
			Devuelve el numero de entradas que tiene este perceptron

			@return int Numero de entradas del perceptron actualmente
			*/
		int getInputSize();

		/**
			Establece los pesos sinapticos actuales de este perceptron.

			@param double *w Puntero a un arreglo de pesos sinapticos. Se tomaran solo el numero de valores correspondientes al numero de entradas, por eso no es necesario especificar el numero de valores que se tomara de este puntero.
			*/
		void setWeights(double *w);

		/**
			Establece los pesos sinapticos actuales de este perceptron. En este metodo
			se incluye un parametro @code{ninputs} que modifica el numero de entradas
			del perceptron (si es diferente). A diferencia de @code{setWeights(double *w)}
			que asigna los pesos de acuerdo al numero de entradas que actualmente tiene
			asignado el perceptron

			@param double *w Puntero a un arreglo de pesos sinapticos. Se tomaran solo el numero de valores correspondientes al numero de entradas, por eso no es necesario especificar el numero de valores que se tomara de este puntero.
			@param int ninputs Numero de entradas que se asignaran al Perceptron
			*/
		void setWeights(int ninputs, double *w);

		/**
			Establece los pesos actuales de este perceptron.

			@param vector<double> w Vector con los pesos sinapticos. El tamaño del vector debe ser el mismo que el numero de entradas. Caso contrario no se asignara ningun valor y se devolvera un error.
			*/
		void setWeights(const vector<double> &w);

		/**
			Establece el valor de un peso a la vez indicandole el indice @code{pos}

			@param int pos Indice del peso que se actualizara
			@param double value Valor que se le asignara al peso en la posicion @code{pos}
			*/
		void setWeight(int pos, double value);

		/**
			Obtiene un puntero a un arreglo con los pesos sinapticos.

			@return double* Puntero a un arreglo con los pesos sinapticos
			*/
		double *getWeights();

		/**
			Devuelve un vector con los pesos sinapticos actuales de este perceptron

			@return vector<double> Vector con los pesos sinapticos.
			*/
		vector<double> getWeightsVector();

		/**
			Devuelve una referencia al vector de pesos sinapticos actuales de este perceptron

			@return vector<double> Vector con los pesos sinapticos.
			*/
		inline vector<double> &getRefWeightsVector(){return weights;}


		/**
			Establece el valor de disparo de la funcion de transferencia

			@param double threshold Valor de disparo que se le asignara a la funcion.
			*/
		void setThreshold(double value);

		/**
			Obtiene el valor de disparo de la funcion de transferencia

			@return double Valor de disparo actual de la funcion de transferencia.

			@see setThreshold
			*/
		double getThreshold();

		/**
			Establece la funcion de transferencia que tendra este perceptron.

			@param TransferFunctionType tf Funcion de transferencia que se le asignara

			@see getTransferFunction
			*/
		void setTransferFunction(TransferFunctionType tf);

		/**
			Devuelve la funcion de transferencia actual de este perceptron

			@return TransferFunctionType Funcion de transferencia actual de este perceptron
			*/
		TransferFunctionType getTransferFunction();

		/**
			Inicia el entrenamiento de este perceptron con un conjunto de entrenamiento donde
			@code{inputs} es un conjunto de entradas y @code{targets} es el conjunto de salidas
			deseadas para ese conjunto de entradas.

			El numero de epocas maximas que se tomara el entrenamiento esta determinado por @code{epochs}.
			Tanto @code{epochs} como @code{nEpochosAfterChange} debe ser especificado debido a la necesidad
			de una condicion de parada en caso de que el entrenamiento sea muy largo o caiga en un ciclo infinito

			@param vector<vector<double> > &inputs Conjunto de entradas
			@param vector<bool> &targets Conjunto de valores deseados para cada muestra de entradas
			@param int epochs Numero maximo de epocas que podra entrenarse
			@param int nEpochsAfterNoChange Condicion de parada que indica que cuando hayan transcurrido @code{nEpochsAfterNoChange} sin cambios en los pesos sinapticos se detendra el entrenamiento
			@param double trainingFactor Indica la rapidez con la cual el perceptron aprendera
			*/
		TrainResult train(const vector<vector<double> > &inputs, const vector<bool> &targets, int epochs, int nEpochsAfterNoChange, double trainingFactor);

		/*!
			Inicia el entrenamiento de este perceptron con un conjunto de entrenamiento @code{ts}

			El numero de epocas maximas que se tomara el entrenamiento esta determinado por @code{epochs}.
			Tanto @code{epochs} como @code{nEpochosAfterChange} debe ser especificado debido a la necesidad
			de una condicion de parada en caso de que el entrenamiento sea muy largo o caiga en un ciclo infinito

			@param TrainingSet<PerceptronTrainingPattern> &ts Conjunto de entrenamiento
			@param int epochs Numero de epocas maximas que se tomara el entrenamiento
			@param int nEpochsAfterNoChange Condicion de parada que indica que cuando hayan transcurrido @code{nEpochsAfterNoChange} sin cambios en los pesos sinapticos se detendra el entrenamiento
			@param double trainingFactor Indica la rapidez con la cual el perceptron aprendera

			*/
		TrainResult train(vector<PerceptronTrainingPattern> &ts, int epochs, int nEpochsAfterNoChange, double learningFactor);

		/**
			Obtiene la salida actual de este perceptron dada un conjunto de datos de entrada presentado.

			@param vector<double> &data Conjunto de datos de entrada para calcular la salida.
			@param double alfa Indica la pendiente de la funcion de transferencia en algunas donde es necesario como

			@return double Respuesta que genera este perceptron ante la entrada @code{data}
			*/
		bool getOutput(const vector<double> &inputs);

		/**
			Establece la regla de aprendizaje de este perceptron

			@param LearningRule lr Regla de aprendizaje que se le asignara
			*/
		void setLearningRule(LearningRule lr);

		/**
			Devuelve la regla de aprendizaje asignada a este perceptron

			@return LearningRule Regla de aprendizaje actualmente asignada
			*/
		LearningRule getLearningRule();

		/**
			Establece todos los pesos sinapticos incluyendo el umbral
			en un valor aleatorio.
			*/
		void randomizeWeights();


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

		void randomizeWeights(double min = -0.01, double max = 0.01);

	private:
		//Factor de crecimiento en la funcion de transferencia de salida
		double alfa;

		//Indica la regla de aprendizaje que utilizara
		LearningRule lr;

		//Vector de pesos sinapticos de este perceptron
		vector<double> weights;

		//Valor del bias o threshold de este perceptron
		double threshold;

		//Funcion de transferencia que se utilizara en este perceptron
		TransferFunctionType tf;

		/**
			Inicializa este perceptron con un numero @code{ninputs} de entradas, y un puntero a un
			arreglo de pesos sinapticos tambien se puede establecer la funcion de transferencia que
			tendra este perceptron.

			@param int ninputs Numero de entradas que se consideraran de el puntero de entradas
			@param double *weights Puntero a un arreglo de pesos sinapticos.
			@param TransferFunctionType tf Funcion de transferencia que tendra este perceptron

			*/
		void init(int ninputs, double *weights, TransferFunctionType tf, LearningRule lr);

		/**
			Inicializa este perceptron con un numero @code{ninputs} de entradas, tambien
			se puede especificar la funcion de transferencia que tendra este perceptron.
			Todos los pesos sinapticos se inicializaran aleatoriamente.

			@param int ninputs Numero de entradas que se tomaran del puntero @code{inputs}
			@param TransferFunctionType tf Tipo de funcion de transferencia de este perceptron
			*/
		void init(int ninputs, TransferFunctionType tf, LearningRule lr);

		/**
			Inicializa un perceptron con un vector de pesos, asi commo
			tambien una funcion de transferencia.

			A cada indice de las entradas inputs le corresponde el elemento en la misma posicion del vector de pesos,
			es decir, cada entrada tiene su peso asignado, por lo cual el tamaño de inputs debe ser igual al tamaño de
			weights, de lo contrario ocurrira un error.

			@param vector<double> weights Vector con los pesos sinapticos asignados a cada entrada
			@param TransferFunctionType tf Funcion de transferencia de este perceptron
			*/
		void init(vector<double> weights, TransferFunctionType tf, LearningRule lr);

};

class Q_DECL_EXPORT PerceptronTrainingPattern : public SimpleInputPattern
{
	public:

		/**
		  Inicializa este patron con un numero inicial de entradas indicado por @code{ninputs}
		  y la salida en @code{false}

		  El vector de entradas se inicializa en cero

		  @param int ninputs Numero de entradas que tendra este patron
		  */
		explicit PerceptronTrainingPattern(int ninputs = 1);

		/**
		  Inicializa este patron con un vector de entradas y un valor de salida

		  @param vector<double> &inputs Vector de entradas del patron
		  @param bool output Salida deseada para este patron de entrenamiento
		  */
		explicit PerceptronTrainingPattern(const vector<double> &inputs, bool output);

		void setOutput(bool out);

		bool getOutput() const;

	private:
		bool output;
};
}

#endif // SIMPLEPERCEPTRON_COPY_H
