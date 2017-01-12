#ifndef ADALINETRAININGPATTERN_H
#define ADALINETRAININGPATTERN_H

#include "share_ann_base_lib.h"
#include "simpleinputpattern.h"

namespace ann_base{

class ANN_BASE_LIB_IMPORT_EXPORT AdalineTrainingPattern : public SimpleInputPattern
{
	public:

		/**
			  Inicializa este patron con un numero inicial de entradas indicado por @code{ninputs}
	  y la salida en @code{false}

	  El vector de entradas se inicializa en cero

	  @param int ninputs Numero de entradas que tendra este patron
	  */
		/*!
			 * \brief AdalineTrainingPattern
			 * \param ninputs
			 */
		explicit AdalineTrainingPattern(int ninputs);

		/**
	  Inicializa este patron con un vector de entradas y un valor de salida

	  @param vector<double> &inputs Vector de entradas del patron
	  @param bool output Salida deseada para este patron de entrenamiento
	  */
		/*!
			 * \brief AdalineTrainingPattern
			 * \param inputs
			 * \param output
			 */
		explicit AdalineTrainingPattern(const vector<double> &inputs, double output);

		void setOutput(double out);

		double getOutput() const;

	private:
		double output;
};

}
#endif // ADALINETRAININGPATTERN_H
