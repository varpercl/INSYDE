#ifndef ANNFRAMEWORK_GLOBAL_H
#define ANNFRAMEWORK_GLOBAL_H

#include <vector>
#include <algorithm>
#include <math.h>
#include <exception>
#include <QtCore>

#include <tbb/concurrent_vector.h>

using namespace std;
using namespace tbb;


/*!
 * \namespace ann
 *
 * \brief
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
namespace ann_base Q_DECL_EXPORT{

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
