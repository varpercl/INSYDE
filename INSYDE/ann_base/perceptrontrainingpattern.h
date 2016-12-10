#ifndef PERCEPTRONTRAININGPATTERN_H
#define PERCEPTRONTRAININGPATTERN_H

#include <QtCore>

#include "share_ann_base_lib.h"
#include "simpleinputpattern.h"

namespace ann_base{

class ANN_BASE_LIB_IMPORT_EXPORT PerceptronTrainingPattern : public SimpleInputPattern
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

#endif // PERCEPTRONTRAININGPATTERN_H
