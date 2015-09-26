#ifndef ARTIFICIALNEURALNETWORK_H
#define ARTIFICIALNEURALNETWORK_H


namespace ann_base{
	/*!
 * \class ArtificialNeuralNetwork
 *
 * \brief The ArtificialNeuralNetwork class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
	class ArtificialNeuralNetwork
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

			virtual void randomizeWeights(double min = -0.01, double max = 0.01) = 0;

		private:
	};
}

#endif // ARTIFICIALNEURALNETWORK_H
