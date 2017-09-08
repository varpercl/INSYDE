#ifndef ARTIFICIALNEURALNETWORK_H
#define ARTIFICIALNEURALNETWORK_H

#include <QtCore>

#include "share_ann_base_lib.h"

namespace ann_base{
/*!
 * \brief The ArtificialNeuralNetwork class defines a generic ANN with base properties.
 *
 * \note: Temporarily an ANN object inherit the QThread class to process all background training process.
 * This approach will be replaced by a well implemented tbb threading processing (not inheritance needed)
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_BASE_LIB_IMPORT_EXPORT ArtificialNeuralNetwork : public QThread
{
	public:

		/*!
		 * \brief The Type enum
		 */
		enum Type{
			Adaline,
			SimplePerceptron,
			MultilayerPerceptron,
			Hopfiel,
			Kohonen
		};

		/*!
		 * \brief Returns the type of the ann.
		 * \return The type of the ANN
		 */
		virtual Type getType() const = 0;

		/*!
		 * \brief Returns a string name representation of the ann type
		 * \return The name of the ann
		 */
		virtual QString getName() const = 0;

		/*!
		 * \brief Obtains the size of the outputs
		 * \return The output size
		 */
		virtual int getOutputSize() const = 0;

		/*!
		 * \brief Obtains the size of the inputs
		 * \return The input size
		 */
		virtual int getInputSize() const = 0;

	public slots:
		/*!
		 * \brief Randomizes all weights of this ann
		 * \param min The minimum possible value
		 * \param max The maximum possible value
		 */
		virtual void randomizeWeights(double min = -0.01, double max = 0.01) = 0;

		/*!
		 * \brief Establish the input size of this ann.
		 * \param i The number of inputs
		 */
		virtual void setInputSize(int i) = 0;

		/*!
		 * \brief Establish the output size of this ann.
		 * \param o The number of outputs
		 */
		virtual void setOutputSize(int o) = 0;

	private:

		Q_OBJECT

};
}

#endif // ARTIFICIALNEURALNETWORK_H
