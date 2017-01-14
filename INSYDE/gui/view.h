#ifndef VISOR_H
#define VISOR_H

#include <QtGui>

#include "../core/graphicpointer.h"
#include "../core/enviroment.h"
#include "simulationcontrol.h"

#include "../core/common.h"
#include "../core/detailedwindow.h"

#include "../ann_gui/mlpobject.h"
#include "../ec_gui/shootingunit.h"

using namespace ec_gui;

namespace gui
{

class GraphicPointer;
class Unit;

/*!
 * \brief La clase \code{Visor} permite la visualizacion de los entornos de simulacion.
 * Es la clase base para poder simular/visualizar cualquier sistema creado por el usuario.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 08/06/2012
 */
class View : public DetailedWindow
{

	public:
		explicit View(QWidget *parent = 0);

		~View();

		void setSimulationStatus(Status sta);
		Status getSimulationStatus();


	private:
		Q_OBJECT

		QRect selectionRect;
		Status simulationStatus;

		void init();

};
}
#endif // MAPA_H
