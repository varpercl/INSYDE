#ifndef VISOR_H
#define VISOR_H

#include <QtGui>

#include "apuntador.h"
#include "mapa.h"
#include "statusanimation.h"
#include "../ann_gui/graphicmlpelement.h"
#include "../ec_gui/shootingunit.h"
#include "../core/common.h"



class GraphicPointer;
class Unit;

/*!
 * \brief La clase \code{Visor} permite la visualizacion de los entornos de simulacion.
 * Es la clase base para poder simular/visualizar cualquier sistema creado por el usuario.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 08/06/2012
 */
class Q_DECL_EXPORT Visor : public QGraphicsView
{

	public:
		explicit Visor(QWidget *parent = 0);

		~Visor();

		void setSimulationStatus(Status sta);
		Status getSimulationStatus();

	protected:

		void contextMenuEvent(QContextMenuEvent *event);
		void mouseDoubleClickEvent(QMouseEvent *event);
		void mousePressEvent(QMouseEvent *event);
		void mouseMoveEvent(QMouseEvent *event);
		void mouseReleaseEvent(QMouseEvent *event);

	signals:

		void clicked(QMouseEvent *event);

	public slots:

		void removeSelected();

	private:
		Q_OBJECT

		QRect selectionRect;
		Enviroment *_map;
		Status simulationStatus;
		GraphicPointer *apuntador;
		QPointF posInicialMouse;
		QPointF posActualMouse;

		void init();

		bool areDifferentTypes(const QList<QGraphicsItem*> &list);

		void showPointer(double angle);

		void removePointer();
};

#endif // MAPA_H
