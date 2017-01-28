#ifndef APUNTADOR_H
#define APUNTADOR_H

#include <QtGui>
#include <QtWidgets>

#include "../core/common.h"
#include "graphicobject.h"

namespace core{

/*!
 * \brief The GraphicPointer class
 *
 * La clase @code{GraphicPointer} consiste en una flecha que indicara la direccion final en la que se quiere
 * que los agentes queden apuntando al llegar al destino final asignado.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class GraphicPointer : public GraphicObject
{
	private:
//        qreal width;
//        qreal height;

		//Ancho de los bordes de este apuntador
		int lineWidth;

		//Forma actual de este apuntador
		QPainterPath curShape;

		/**
		  Inicializa todas las propiedades de este apuntador, incluyendo principalmente
		  el ancho y el alto

		  @param w Ancho del apuntador
		  @param h Alto del apuntador
		  */
		void iniciarApuntador(double w, double h);

	public:

		/**
		  Constructor de la clase, no utiliza parametros.
		  */
		explicit GraphicPointer();

		/**
		  Construye un objeto con un ancho de bordes especifico

		  @param width Ancho del borde de este apuntador
		  */
		explicit GraphicPointer(double width);

		~GraphicPointer();

		QString getXML() const;

	protected:

		/**
		  Heredada de @code{QGraphicsItem}, vease documentacion para mayor informacion
		  */
		QPainterPath shape() const;

		/**
		  Heredada de @code{QGraphicsItem}, vease documentacion para mayor informacion
		  */
		QRectF boundingRect() const;

		/**
		  Heredada de @code{QGraphicsItem}, vease documentacion para mayor informacion
		  */
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};
}
#endif // APUNTADOR_H
