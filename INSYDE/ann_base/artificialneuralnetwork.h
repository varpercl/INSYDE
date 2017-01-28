#ifndef ARTIFICIALNEURALNETWORK_H
#define ARTIFICIALNEURALNETWORK_H

#include <QtCore>

#include "share_ann_base_lib.h"

namespace ann_base{
/*!
 * \brief The ArtificialNeuralNetwork class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_BASE_LIB_IMPORT_EXPORT ArtificialNeuralNetwork
{
	public:

		explicit ArtificialNeuralNetwork();

		enum Type{
			NoType,
			Adaline,
			SimplePerceptron,
			MultilayerPerceptron,
			Hopfiel,
			Kohonen
		};

		virtual Type getType() const;

		virtual QString getName() const;

		virtual void randomizeWeights(double min = -0.01, double max = 0.01) = 0;

	private:
};
}

#endif // ARTIFICIALNEURALNETWORK_H
