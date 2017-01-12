#ifndef ANNFRAMEWORK_GLOBAL_H
#define ANNFRAMEWORK_GLOBAL_H

#include <QtCore>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <exception>

//#include "share_ann_base_lib.h"

//#include <tbb/concurrent_vector.h>

//using namespace std;
//using namespace tbb;

namespace ann_base {


	/*!
	 * \enum
	 *
	 * \brief Indica cual es el criterio de parada para el entrenamiento de esta red
	 */
	enum StopCondition{
		MSE,
		RMSE,
		CE
	};

}

#endif // RNALIBRARY_GLOBAL_H
