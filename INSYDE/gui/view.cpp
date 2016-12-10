#include "view.h"

View::View(QWidget *parent) :
	DetailedWindow(parent)
{
	init();
}

View::~View()
{
}

void View::setSimulationStatus(Status sta)
{
	QList<QGraphicsItem*> itms = getGraphicsDetailedView()->items();
	Unit *un;
	switch(sta){
		case Running:
			foreach(QGraphicsItem *itm, itms){
				if((un = dynamic_cast<Unit*>(itm)))
					un->setFlag(QGraphicsItem::ItemIsMovable, false);
				un->run();
			}
			break;
		case Paused:
			foreach(QGraphicsItem *itm, itms){
				if((un=dynamic_cast<Unit*>(itm)))
					un->setFlag(QGraphicsItem::ItemIsMovable, false);
				un->stop();
			}
			break;
		case Stopped:
			foreach(QGraphicsItem *itm, itms){
				if((un = dynamic_cast<Unit*>(itm))){
					un->setFlag(QGraphicsItem::ItemIsMovable);
					un->clearPoints();
				}
			}
	}
	simulationStatus = sta;
}

Status View::getSimulationStatus()
{
	return simulationStatus;
}

int rectArea(QRect rect){
	return rect.width() * rect.height();
}

void View::init()
{
	GraphicDetailedView *gdv = getGraphicsDetailedView();
	setSimulationStatus(Stopped);
	//    setFrameStyle(0);

	gdv->setCenterMarkerVisible(true);
	gdv->setGridVisible(true);

	gdv->setOptimizationFlags(QGraphicsView::DontAdjustForAntialiasing|
						 QGraphicsView::DontSavePainterState
						 );
	gdv->setRenderHint(QPainter::HighQualityAntialiasing);
	setAttribute(Qt::WA_TranslucentBackground, false);
//	gdv->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	//    updateViewPort = startTimer(50);
}
