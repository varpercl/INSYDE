#ifndef SIMPLEPATTERN_H
#define SIMPLEPATTERN_H

#include "RNALibrary_global.h"
#include <vector>

using namespace std;

class RNALIBRARY_EXPORT SimpleInputPattern
{
	public:

		/**
		  Inicializa este patron con un numero inicial de entradas indicado por @code{ninputs}
		  y la salida en @code{false}

		  El vector de entradas se inicializa en cero

		  @param int ninputs Numero de entradas que tendra este patron
		  */
		explicit SimpleInputPattern(int ninputs);

		/**
		  Inicializa el patron con un vector de entradas previamente inicializado

		  @param vector<double> inputs Vector de valores de entrada entradas
		  */
		explicit SimpleInputPattern(const vector<double> &inputs);

		explicit SimpleInputPattern(double *inputs, size_t s);

		/**
		  Asigna los valores de entradas para este patron

		  @param vector<double> &inputs
		  */
		void setInputs(const vector<double> &inputs);

		void setInputs(double *inputs, size_t s);

		/**
		  Devuelve el vector de entradas de este patron particular

		  @return vector<double> Vector de entradas
		  */
		vector<double> &getInputs();

	private:

		//vector de entradas de este patron
		vector<double> inputs;

};

#endif // SIMPLEPATTERN_H
