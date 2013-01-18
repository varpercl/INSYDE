#ifndef GENERAL_H
#define GENERAL_H

#include "INSYDECommon_global.h"
#include <QPointF>
#include <math.h>

/**
  @namespace GeneralFunctions
  @author Edixon Vargas
  @date 08-06-2012

  Este espacio de nombres define una serie de funciones de uso general que no heredan de ninguna clase.

  */

namespace CommonFunctions {

	/**
	  Devuelve la distancia euclidea entre dos puntos.

	  @param &pt1 Primer punto para el calculo
	  @param &pt2 Segundo punto para el calculo

	  @return double Distancia euclidea entre ambos puntos
	  */
	double INSYDECOMMONSHARED_EXPORT distanceBetweenPoints(const QPointF &pt1, const QPointF &pt2);

	/**
	  Devuelve el minimo valor entero mas proximo a @code{val} multiplo de @code{divisor}.

	  Ejemplo: trunkedValue(105, 10) devuelve 10
			   trunkedValue(115, 10) devuelve 11
			   trunkedValue(444, 5) devuelve 440

	  @param val Valor que se quiere aproximar
	  @param divisor Valor del divisor al cual se quiere hacer la aproximacion

	  @return double Valor truncado
	  */
	double INSYDECOMMONSHARED_EXPORT trunkedValue(double val, double divisor);

	/**
	  Devuelve un valor redondeado al proximo multiplo de @code{divisor} mas cercano a @code{val}

	  Ejemplo  trunkedValue(105, 10) devuelve 11
			   trunkedValue(115, 10) devuelve 12
			   trunkedValue(444, 5) devuelve 445

	  @param val Valor que se quiere redondear
	  @param divisor Valor que servira de divisor de val

	  @return double Valor ya redondeado
	  */
	double INSYDECOMMONSHARED_EXPORT roundedValue(double val, double divisor);
}

#endif // GENERAL_H
