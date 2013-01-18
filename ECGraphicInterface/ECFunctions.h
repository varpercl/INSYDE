#ifndef ECFUNCTIONS_H
#define ECFUNCTIONS_H

#include <agent.h>
namespace ECFunctions {

	/**
	  Devuelve la distancia euclidea entre dos agentes.

	  @param &agent1 Agente al cual se hara referencia para el calculo de la distancia
	  @param &agent2 Agente al cual se hara referencia para el calculo de la distancia

	  @return double Distancia entre ambos agentes.
	  */
	double ECGRAPHICINTERFACESHARED_EXPORT distanceBetweenUnits(const Agent &agent1, const Agent &agent2);

}
#endif // ECFUNCTIONS_H
