#ifndef APUNTADOR_H
#define APUNTADOR_H

#include "INSYDEUI_global.h"
#include <QtGui>

#if QT_VERSION >= 0x050000
#include <QtWidgets/QGraphicsItem>
#else
#include <QtGui>
#endif

/**
  @class GraphicPointer
  @author Edixon Vargas
  @date 08-06-2012

  La clase @code{GraphicPointer} consiste en una flecha que indicara la direccion final en la que se quiere que los agentes
  queden apuntando al llegar al destino final asignado.
  */

class INSYDEUISHARED_EXPORT GraphicPointer : public QGraphicsItem
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

#endif // APUNTADOR_H
