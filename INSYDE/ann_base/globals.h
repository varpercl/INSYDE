#ifndef ANNFRAMEWORK_GLOBAL_H
#define ANNFRAMEWORK_GLOBAL_H

#include <QtCore>

namespace ann_base {


	/*!
	 * \brief Indica cual es el criterio de parada para el entrenamiento de esta red
	 */
	enum StopCondition{
		MSE,
		RMSE,
		CE
	};

}

#endif // RNALIBRARY_GLOBAL_H
