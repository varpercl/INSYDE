#ifndef ADALINE_H
#define ADALINE_H

#ifdef QT_CORE_LIB
#include <QtCore>
#endif

#include "ANNFramework_global.h"
#include <vector>
#include <time.h>

#include "itrainable.h"
#include "simplepattern.h"

using namespace std;
using namespace ANNFrameworkFunctions;

class AdalineTrainingPattern;

/**
  @class ADALINE
  @author Ing. Edixon Vargas <ingedixonvargas@gmail.com>

  Esta clase contiene las definiciones basicas del modelo de un perceptron simple.
  */

class ANNFRAMEWORK_EXPORT Adaline
{
	public:

		/**
		  Especifica la forma en que se actualizaran los pesos sinapticos.

		  @enum WeightUpdateType

		  @param ContinuousUpdate Se actualizaran los pesos con cada presentacion de un par entrada/objetivo
		  @param BatchUpdate Se actualizan los pesos una vez que se han pasado todos los pares del conjunto de entrenamiento

		  */
		enum WeightUpdateType{
			ContinuousUpdate,
			BatchUpdate
		};

		/**
		  Contiene informacion sobre el resultado de un entrenamiento, como el numero
		  de epocas que le tomo el entrenamiento, un historial de cambios de los pesos
		  sinapticos, que lo hace ideal si queremos realizar graficas o analisis del
		  avance de los mismos.
		  */
		struct TrainResult{
				int epochs;
				vector<double> errorHistory;
				vector<vector<double> > weightHistory;
				vector<double> thresholdHistory;
		};

		/**
		  @enum TransferFunctionType

		  Indica los tipos de funciones de transferencias para un perceptron simple

		  Parametros:

		  alpha = Indica la pendiente de la funcion de transferencia, solamente es considerado en algunos casos
		  suminput = Sumatoria de todas las entradas multiplicadas por los pesos correspondientes

		  @name Sigmoid Esta funcion es del tipo y = 1 / (1 + exp(-alpha*suminputs))
		  @name Linear La funcion @code{Linear} es igual al valor de la sumatoria, es decir, y = suminputs
		  */
		enum TransferFunctionType{
			Sigmoid,
			Linear
		};

		/**
		  Crea un objeto SimplePerceptron con un numero de entradas @code{ninputs} inicialmente puestas en 0
		  y una funcion de transferencia.

		  @param int ninputs Numero de entradas que tendra este perceptron
		  @param TransferFunctionType tf Funcion de transferencia.
		  */
		explicit Adaline(int ninputs, TransferFunctionType tf);

		/**
		  Crea una instancia de SimplePerceptron con un puntero a un arreglo de valores de entrada, al igual
		  que un puntero a los pesos sinapticos, un threshold y una funcion de transferencia.

		  @param double *inputs Puntero que indica la direccion de un arreglo de entradas ya preestablecidas
		  @param int ninputs Numero de entradas que se consideraran de el arreglo @code{inputs}
		  @param double *weights Puntero a un arreglo de pesos sinapticos, el tamaño sera el mismo que @code{ninputs}
		  @param double threshold Valor de disparo de la funcion de transferencia.
		  @param TranferFunctionType tf Funcion de transferencia que se le asignara a este perceptron

		  */
		explicit Adaline(int ninputs, double *weights, TransferFunctionType tf);

		/**
		  Crea un objeto de SimplePerceptron con un vector de entradas y un vector de pesos sinapticos, asimismo se
		  inicializa el valor de disparo de la funcion de transferencia y se le asigna una funcion de transferencia.

		  @param vector<double> inputs Vector que contiene las entradas de este perceptron.
		  @param vector<double> weights Vector que contiene los pesos sinapticos de cada entrada
		  @param double threshold Valor de disparo de la funcion de transferencia
		  @param TransferFunctionType tf Tipo de funcion de transferencia que se le asignara
		  */
		explicit Adaline(const vector<double> &weights, TransferFunctionType tf);


		/**
		  Establece el numero de entradas de este perceptron. Al utilizarse esta funcion
		  automaticamente todos los pesos sinapticos se estableceran en valores aleatorios

		  @param int n Numero de entradas que tendra este perceptron
		  */
		void setNumberInputs(size_t n);

		/**
			Devuelve el numero de entradas que tiene este perceptron

			@return int Numero de entradas del perceptron actualmente
			*/
		int getNumberInputs();

		/**
			Devuelve un puntero a un arreglo de entradas actuales de este perceptron.

			@return double* Puntero a un arreglo de valores de entradas.
			*/
		double *getInputs();

		/**
			Establece los pesos sinapticos actuales de este perceptron.

			@param double *w Puntero a un arreglo de pesos sinapticos. Se tomaran solo el numero de valores correspondientes al numero de entradas, por eso no es necesario especificar el numero de valores que se tomara de este puntero.
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
		vector<double> getWeightVector();

		/**
			Devuelve una referencia al vector de pesos sinapticos actuales de este perceptron

			@return vector<double> Vector con los pesos sinapticos.
			*/
		inline vector<double> &getRefWeightVector(){return weights;}

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
		  Inicia el entrenamiento con un conjunto de entrenamiento donde
		  @code{inputs} es un conjunto de entradas y @code{targets} es el conjunto de salidas
		  deseadas para ese conjunto de entradas.

		  @param vector<vector<double> > &inputs Conjunto de entradas
		  @param vector<double> &targets Conjunto de valores deseados para cada muestra de entradas
		  @param int error Error maximo antes de que se detenga el entrenamiento
		  @param int nEpochs Numero maximo de epocas de entrenamiento
		  @param double learningFactor Indica la rapidez con la cual el perceptron aprendera
		  */
		TrainResult train(const vector<vector<double> > &inputs, const vector<double> &targets, double error, int nEpochs, double learningFactor, WeightUpdateType wut = BatchUpdate);

		/**

		  */
		TrainResult train(vector<AdalineTrainingPattern> &ts, double error, int nEpochs, double learningFactor, WeightUpdateType wut = BatchUpdate);

		/**
			Obtiene la salida actual de este perceptron dada un conjunto de datos de entrada presentado.

			@param vector<double> &data Conjunto de datos de entrada para calcular la salida.
			@param double alfa Indica la pendiente de la funcion de transferencia en algunas donde es necesario como

			@return double Respuesta que genera este perceptron ante la entrada @code{data}
			*/
		double getOutput(const vector<double> &data);

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
		  void initADALINE(int ninputs, double *weights, TransferFunctionType ft);

		  /**
		  Inicializa el perceptron a partir de un arreglo de entradas, y los pesos sinapticos seran asignados aleatoriamente

		  @param double *inputs Puntero a un arreglo de entradas
		  @param int ninputs Numero de entradas que se consideraran del puntero @code{inputs}
		  @param double threshold Punto de disparo de la funcion de transferencia
		  @param TransferFunctionType tf Funcion de transferencia que tendra este perceptron

		  */
		  void initADALINE(int ninputs, TransferFunctionType ft);

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
		  void initADALINE(const vector<double> &weights, TransferFunctionType tf);

//          class TrainThis : public QThread{
//              public:

//                  vector<double> weights;
//                  double threshold;

//                  void run();
//          };
};

class ANNFRAMEWORK_EXPORT AdalineTrainingPattern : public SimpleInputPattern
{
	public:

		/**
		  Inicializa este patron con un numero inicial de entradas indicado por @code{ninputs}
		  y la salida en @code{false}

		  El vector de entradas se inicializa en cero

		  @param int ninputs Numero de entradas que tendra este patron
		  */
		explicit AdalineTrainingPattern(int ninputs);

		/**
		  Inicializa este patron con un vector de entradas y un valor de salida

		  @param vector<double> &inputs Vector de entradas del patron
		  @param bool output Salida deseada para este patron de entrenamiento
		  */
		explicit AdalineTrainingPattern(const vector<double> &inputs, double output);

		void setOutput(double out);

		double getOutput() const;

	private:
		double output;
};

#endif // ADALINE_H
