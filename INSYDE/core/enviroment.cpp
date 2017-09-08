#include "enviroment.h"

core::Enviroment::Enviroment(QObject *parent) : QGraphicsScene(parent)
{
//    Q_INIT_RESOURCE(core_media);
	init();
}

void core::Enviroment::setGridVisible(bool b)
{
	visibleGrid = b;
}

bool core::Enviroment::getGridVisible() const
{
	return visibleGrid;
}

void core::Enviroment::setCenterMarkerVisible(bool b)
{
	visibleCenterMarker = b;
}

bool core::Enviroment::getCenterMarkerVisible() const
{
	return visibleCenterMarker;
}

void core::Enviroment::drawBackground(QPainter *painter, const QRectF &rect)
{
	painter->save();

	//TODO: revisar ya que accidentalmente se borro una parte
//	r.setTopLeft(QPointF(math::distanceBetweenPoints(, math::trunkedValue(rect.y(), gridSpace)));
	if(visibleGrid){
		QRectF r(rect);
		painter->drawTiledPixmap(r, grid);
	}

	if(visibleCenterMarker){
		painter->drawLine(-20,0, 20, 0);
		painter->drawLine(0,-20,0,20);
	}

	painter->restore();

}

//void Enviroment::dragEnterEvent(QGraphicsSceneDragDropEvent *e)
//{
//	if(e->mimeData()->hasFormat("text/plain")){
//		e->acceptProposedAction();
//	}
//}

void core::Enviroment::init()
{
	visibleGrid = true;
	visibleCenterMarker = true;

	gridSpace = 10;
	grid = QPixmap(gridSpace, gridSpace);
	grid.fill(Qt::white);
	QPainter gridPainter(&grid);
	gridPainter.drawPoint(0,0);
	gridPainter.drawPoint(gridSpace, gridSpace);

	setItemIndexMethod(NoIndex);

}
