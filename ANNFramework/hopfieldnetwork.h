#ifndef HOPFIELDNETWORK_H
#define HOPFIELDNETWORK_H

#include <QDebug>
#include <QFile>

#include <ANNFramework_global.h>
#include <vector>

using namespace std;
using namespace ANNFrameworkFunctions;

//typedef vector<vector<double> > Matriz;

//Matriz traspuesta(Matriz A);

//Matriz producto(Matriz A, Matriz B, size_t cf);

//Matriz opuesta(Matriz A);

//Matriz suma(Matriz A, Matriz B);

/**
  Calcula el producto punto de dos vectores de igual tamaño del tipo @param{T}

  @param vector<T> vec1 Primer vector para calculo del producto punto
  @param vector<T> vec2 Segundo vector para calculo del producto punto
  */
//template <typename T>
//T dotProduct(const vector<T> &vec1, const vector<T> &vec2){
//    size_t sVec = vec1.size();
//    T sum = 0;
//    for(size_t i = 0; i < sVec; i++){
//        sum += (vec1[i] * vec2[i]);
//    }
//    return sum;
//}

/**
  @class HopfieldNetwork

  Esta clase contiene todas las funciones y metodos para poner en funcionamiento una red neuronal de Hopfield.
  */
class ANNFRAMEWORK_EXPORT HopfieldNetwork
{
	public:

		/**
		  Tipo de propagacion de las unidades (neuronas) de la red
		  @param Random Propaga un elemento por vez de modo aleatorio
		  @param Secuential Propaga un elemento por vez pero de modo secuencial
		  */
		enum PropagationType{
			Random,
			Sequential
		};

		/**
		  Contiene informacion sobre el resultado de un entrenamiento, como el numero
		  de epocas que le tomo el entrenamiento, un historial de cambios de los pesos
		  sinapticos, que lo hace ideal si queremos realizar graficas o analisis del
		  avance de los mismos.
		  */
		struct OutputResult{
				int iterations;
				vector<double> output;
				vector<vector<double> > outputHistory;
//                vector<vector<double> > weightHistory;
//                vector<double> thresholdHistory;
		};

		/**
		  @enum TransferFunctionType

		  Indica los tipos de funciones de transferencias para un perceptron simple

		  Parametros:

		  alpha = Indica la pendiente de la funcion de transferencia, solamente es considerado en algunos casos
		  suminput = Sumatoria de todas las entradas multiplicadas por los pesos correspondientes

		  @name Step Funcion tipo escalon unitario si la sumatoria es mayor que cero la salida sera 1
		  @name Signus Parecida a la funcion threshold salvo que tiene los valores -1 y 1
		  */
		enum OutputType{
			Signus,
			Step
		};

		/**
		  Construye una red Hopfield con @code{neuronCount} neuronas y con una funcion de transferencia por defecto
		  Binaria, aunque puede ser bipolar (-1,1).

		  @param unsigned int neuronCount Numero de neuronas que tendra esta red. El numero minimo sera de 7 ya que las redes neuronales de Hopfiel necesitan tener al menos N = P / 0.15 neuronas para lograr la convergencia sin errores (minimos locales).
		  @param TransferFunctionType tf Tipo de funcion de transferencia, por defecto es Threshold (binaria), aunque puede ser tambien bipolar (-1,1)
		  */
		explicit HopfieldNetwork(unsigned int neuronNumber, OutputType tf = Signus);

		/**
		  Redimensiona la red (si es necesario) al nuevo numero de neuronas @code{nc}, si la cantidad de neuronas
		  a asignar es distinta a la anterior, se redimensionara la red y se asignaran pesos aleatorios.

		  @param unsigned int nc Numero de neuronas que se asignaran a la red.
		  */
		void setNumberNeurons(unsigned int nc);

		/**
		  Devuelve el numero actual de neuronas que tiene la red.

		  @return int Numero de neuronas actualmente asignadas a esta red
		  */
		unsigned int getNumberNeurons();

		/**
		  Establece la funcion de transferencia que tendra esta red.

		  @param TransferFunctionType tf Funcion de transferencia que se le asignara

		  @see getTransferFunction
		  */
		void setOutputFunction(OutputType tf);

		/**
		  Devuelve la funcion de transferencia actual de esta red.

		  @return TransferFunctionType Funcion de transferencia actual.
		  */
		OutputType getOutputFunction();

		/**
		  Calcula los pesos para esta red de hopfield. Esta funcion difiere
		  a una funcion de entrenamiento convencional en que el numero de
		  iteraciones es fijo y depende del numero de elementos en la red
		  asimismo no se necesita presentar un conjunto de entradas/objetivos
		  sino mas bien un conjunto de patrones que utilizara la red para
		  relacionar.

		  @param vector<vector<double> > &patterns Patrones para calcular los pesos de la red neuronal

		  */
		vector<vector<int> > calculateWeights(const vector<vector<double> > &patterns);

		/**
		  Obtiene un vector con las salidas generadas a partir de un patron presentado a la red

		  @param
		  */
		OutputResult getOutput(const vector<double> &inputs, const PropagationType &pt = Random);

	private:

		vector<double> miu;

		//Numero de elementos (neuronas) que tendra la red
		int neuronNumber;

		//Matriz de pesos sinapticos
		vector<vector<int> > weights;

		//Funcion de trasnferencia con la cual esta funcionando esta red
		OutputType tf;

		/**
		  Inicializa la red neuronal con un tamaño de @code{neuronCount} y asigna la
		  funcion de transferencia @code{tf}

		  @param unsigned int neuronCount Asigna el tamaño de la red, es decir, la cantidad de neuronas que tendra.
		  @param TransferFunctionType tf Asigna el tipo de funcion de transferencia

		  @see TransferFunctionType
		  */
		void initHopfield(unsigned int neuronCount, OutputType tf);

		bool propagateUnit(int i);

};

#endif // HOPFIELDNETWORK_H
