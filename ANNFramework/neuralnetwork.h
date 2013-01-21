#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#ifdef QT_CORE_LIB
#include <QtCore>
#endif

#include "ANNFramework_global.h"
#include "itrainable.h"

class NeuralNetwork
{
	protected:

		//Vector con las entradas de esta red neuronal
		vector<double> inputs;

	public:
		explicit NeuralNetwork();

		/**
		  Asigna las entradas a esta red, estas entradas permaneceran en su mismo estado hasta que se vuelva
		  a llamar setInputs

		  @param vector<int> Vector con las entradas que tendra la red neuronal
		  */
		void setInputs(vector<double> inputs);

		/**
		  Devuelve un vector de salidas donde cada posicion representa la salida de cada neurona,
		  las salidas son binarias y pueden ser desde -1 hasta 1 o 0 y 1 dependiendo de la funcion
		  de transferencia previamente configurada.

		  La salida generada en esta funcion dependera del valor de entrada previamente establecido mediante
		  setInput, el tamaño del vector de salidas es igual al vector de entradas.

		  @return vector<int> Vector de enteros que contiene en cada posicion el valor de la salida de la red neuronal
		  */
		virtual vector<int> getOutput() = 0;

		/**
		  Devuelve un vector de salidas donde cada posicion representa la salida de cada neurona,
		  las salidas son binarias y pueden ser desde -1 hasta 1 o 0 y 1 dependiendo de la funcion
		  de transferencia previamente configurada.

		  La salida generada en esta funcion dependera del valor de entrada previamente establecido mediante
		  setInput, el tamaño del vector de salidas es igual al vector de entradas.

		  @return vector<int> Vector de enteros que contiene en cada posicion el valor de la salida de la red neuronal
		  */
		virtual vector<int> getOutput(vector<int> inputs) = 0;
};

#endif // NEURALNETWORK_H
