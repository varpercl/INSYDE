#ifndef KOHONEN_H
#define KOHONEN_H

#include "share_ann_base_lib.h"
#include "artificialneuralnetwork.h"

namespace ann_base{

	class ANN_BASE_LIB_IMPORT_EXPORT Kohonen : public ArtificialNeuralNetwork
	{
		public:
			explicit Kohonen();

			~Kohonen();

			Type getType() const;
			QString getName() const;
			void randomizeWeights(double min, double max);
	};
}

#endif // KOHONEN_H
