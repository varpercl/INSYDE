#include "mapa.h"

void Enviroment::initMapa(){
	gridSpace = 10;
	grid = QPixmap(gridSpace, gridSpace);
	grid.fill(Qt::white);
	QPainter gridPainter(&grid);
	gridPainter.drawPoint(0,0);
	gridPainter.drawPoint(gridSpace, gridSpace);

	setItemIndexMethod(NoIndex);

}

Enviroment::Enviroment(QObject *parent) : QGraphicsScene(parent)
{
	initMapa();
}

void Enviroment::drawBackground(QPainter *painter, const QRectF &rect)
{
	//    painter->save();

	QRectF r(rect);
	//TODO: revisar ya que accidentalmente se borro una parte
//	r.setTopLeft(QPointF(math::distanceBetweenPoints(, math::trunkedValue(rect.y(), gridSpace)));
	painter->drawTiledPixmap(r, grid);

	painter->drawLine(-20,0, 20, 0);
	painter->drawLine(0,-20,0,20);

	//    painter->restore();

}

void Enviroment::dragEnterEvent(QGraphicsSceneDragDropEvent *e)
{
	if(e->mimeData()->hasFormat("text/plain")){
		e->acceptProposedAction();
	}
}
