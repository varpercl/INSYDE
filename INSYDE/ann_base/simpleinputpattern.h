#ifndef SIMPLEPATTERN_H
#define SIMPLEPATTERN_H

#include <vector>

#include "share_ann_base_lib.h"
#include "globals.h"

using namespace std;

namespace ann_base{
/*!
 * \brief The SimpleInputPattern class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_BASE_LIB_IMPORT_EXPORT SimpleInputPattern
{
	public:

		explicit SimpleInputPattern();

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

		SimpleInputPattern(const SimpleInputPattern &copy);

		~SimpleInputPattern();

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

//		SimpleInputPattern &operator==(const SimpleInputPattern &va);
	private:

		//vector de entradas de este patron
		vector<double> inputs;

};
}

#endif // SIMPLEPATTERN_H
