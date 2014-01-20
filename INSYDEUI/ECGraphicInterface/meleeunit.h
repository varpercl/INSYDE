#ifndef MELEEUNIT_H
#define MELEEUNIT_H

#include <QtCore>
#include <QtGui>

#include "ofensiveunit.h"

/**
  @class MeleeUnit
  @author Edixon Vargas
  @date 08-06-2012

  La clase @code{MeleeUnit} define un tipo de unidades que tienen un enfrentamiento cuerpo a cuerpo, estas unidades atacan
  de forma distinta a las unidades con proyectiles (alcance).

  */

class MeleeUnit : public OfensiveUnit
{
		Q_OBJECT

		/**
		  Inicializa todas las variables miembro de este objeto
		  */
		void initMU();

	public:
		explicit MeleeUnit();

		/**
		  Inicia un ataque sobre la unidad a la que se le indique como parametro.

		  @param *ag Puntero a la unidad a la que se le va a atacar

		  */
		void attackTo(Unit *ag);

		/**
		  Inicia un ataque sobre un punto fijo si es posible.

		  @param &pt Punto sobre el cual se realizara el ataque
		  */
		void attackTo(const QPointF &pt);

	protected:

		/**
		  Heredada de QGraphicsView, vease documentacion para mas detalle
		  */
		QPainterPath shape() const;

		/**
		  Heredada de QGraphicsView, vease documentacion para mas detalle
		  */
		QRectF boundingRect();

		/**
		  Heredada de QGraphicsView, vease documentacion para mas detalle
		  */
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // MELEEUNIT_H
