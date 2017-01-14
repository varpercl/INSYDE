#ifndef ECFUNCTIONS_H
#define ECFUNCTIONS_H

#include "share_ec_gui.h"
#include "agent.h"
namespace ec_gui
{
namespace common
{

	/**
	  Devuelve la distancia euclidea entre dos agentes.

	  @param &agent1 Agente al cual se hara referencia para el calculo de la distancia
	  @param &agent2 Agente al cual se hara referencia para el calculo de la distancia

	  @return double Distancia entre ambos agentes.
	  */
	EC_GUI_LIB_IMPORT_EXPORT double distanceBetweenUnits(const Agent &agent1, const Agent &agent2);

}
}
#endif // ECFUNCTIONS_H
