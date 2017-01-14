#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QGraphicsItem>
#include <QGraphicsPolygonItem>

#include "share_ec_gui.h"

namespace ec_gui
{
/**
  @class Obstacle
  @author Edixon Vargas
  @date 08-06-2012

  Un @code{Obstacle} es un objeto fijo que obstruye el movimiento de un agente movil u otro elemento que se desplace
  en un entorno

  */
class EC_GUI_LIB_IMPORT_EXPORT Obstacle : public QGraphicsPolygonItem
{
	public:

		/**
		  Crea un nuevo obstaculo asignado a un ambiente.
		  */
		explicit Obstacle();

	signals:

	public slots:

};
}
#endif // OBSTACULO_H
