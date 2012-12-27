#ifndef VISOR_H
#define VISOR_H

//#include <QtCore>
//#include <QtGui>


//#include <statusanimation.h>
//#include <mapa.h>
//#include <agent.h>
////#include <unidad.h>
//#include <apuntador.h>
//#include <vector2d.h>
//#include <shootingunit.h>

#include <InSyDeGui.h>
class GraphicPointer;
class Unit;

/**
  @class Visor
  @author Edixon Vargas
  @date 08-06-2012

  La clase @{Visor} es una clase que permite la visualizacion de los entornos de simulacion.

  */
class Visor : public QGraphicsView
{
		Q_OBJECT

		//        int updateViewPort;
		QRect selectionRect;
		Enviroment *map;
		Status simulationStatus;
		GraphicPointer *apuntador;
		QPointF posInicialMouse;
		QPointF posActualMouse;

		bool areDifferentTypes(const QList<QGraphicsItem*> &list);

		void showPointer(double angle);
		void removePointer();

	public:
		explicit Visor(QWidget *parent = 0);

		void setSimulationStatus(Status sta);
		Status getSimulationStatus();

	protected:
		//        void timerEvent(QTimerEvent *event);
		void mouseDoubleClickEvent(QMouseEvent *event);
		void mousePressEvent(QMouseEvent *event);
		void mouseMoveEvent(QMouseEvent *event);
		void mouseReleaseEvent(QMouseEvent *event);
		//        void drawForeground(QPainter *painter, const QRectF &rect);
		//        void paintEvent(QPaintEvent *event);
		//        void resizeEvent(QResizeEvent *event);

	signals:
		void clicked(QMouseEvent *event);

	protected slots:
		void contextualMenu(QPoint p);

	public slots:
		void deleteSelected();

};

#endif // MAPA_H
