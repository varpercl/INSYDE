#include "pixmapitem.h"

PixmapItem::PixmapItem(const QPixmap &pm, QGraphicsItem *parent) :
	QGraphicsPixmapItem(pm, parent)
{
	initPI();
}

void PixmapItem::setSelectionRectVisible(bool rv)
{
//	setAcceptHoverEvents(rv);
	rectVisible = rv;
}

bool PixmapItem::getSelectionRectVisible() const
{
	return rectVisible;
}

void PixmapItem::setSelectionRect(const QRect &sr)
{
	rect = sr;
	update();
}

QRect PixmapItem::getSelectionRect() const
{
	return rect;
}

void PixmapItem::setSelectionRectColor(const QColor &color)
{
	rectColor = color;
}//setSelectionRectColor

QColor PixmapItem::getSelectionRectColor() const
{
	return rectColor;
}//getSelectionRectColor

QImage PixmapItem::getImageSegment() const
{
	return pixmap().copy(rect).toImage();
}//getImageSegment

void PixmapItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsPixmapItem::mousePressEvent(event);
	mouseMoveEvent(event);
}

void PixmapItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsPixmapItem::mouseMoveEvent(event);

	if(event->buttons() & Qt::LeftButton){
		int
				imageW = pixmap().width(),
				imageH = pixmap().height();

		double
				mouseX = event->pos().x(),
				mouseY = event->pos().y(),
				rectW = rect.width(),
				rectH = rect.height(),
				midRectW = rectW / 2,
				midRectH = rectH / 2;

		//En primera instancia se verifica que el recuadro se encuentre en la region interna de la imagen
		if(mouseX <= imageW - midRectW &&
		   mouseX >= midRectW &&
		   mouseY <= imageH - midRectH &&
		   mouseY >= midRectH){

			rect.moveTopLeft(QPoint(mouseX - midRectW, mouseY - midRectH));

			//Se verifica si el puntero se encuentra en la esquina superior izquierda
		}else if(mouseX < midRectW && mouseY < midRectH){

			rect.moveTopLeft(QPoint(0, 0));

			//Se verifica si el puntero se encuentra en la esquina superior derecha
		}else if(mouseX > imageW - midRectW && mouseY < midRectH){

			rect.moveTopRight(QPoint(imageW, 0));

			//Se verifica si el puntero se encuentra en la esquina inferior izquierda
		}else if(mouseX < midRectW && mouseY > imageH - midRectH){

			rect.moveBottomLeft(QPoint(0, imageH));

			//Se verifica si el puntero se encuentra en la esquina inferior derecha
		}else if(mouseX > imageW - midRectW && mouseY > imageH - midRectH){

			rect.moveBottomRight(QPoint(imageW, imageH));

			//Se verifica si el puntero se encuentra en la banda derecha
		}else if(mouseX > imageW - midRectW){

			rect.moveTopLeft(QPoint(imageW - rectW, mouseY - midRectH));

			//Se verifica si el puntero se encuentra en la banda izquierda
		}else if(mouseX < midRectW){

			rect.moveTopLeft(QPoint(0, mouseY - midRectH));

			//Se verifica si el puntero se encuentra en la banda inferior
		}else if(mouseY > imageH - midRectH){

			rect.moveTopLeft(QPoint(mouseX - midRectW, imageH - rectW));

			//Se verifica si el puntero se encuentra en la banda superior
		}else if(mouseY < midRectH){

			rect.moveTopLeft(QPoint(mouseX - midRectW, 0));

		}
	}

	if(rect.contains(event->pos().toPoint())){
		mouseIsOverSelectionRect = true;
	}else{
		mouseIsOverSelectionRect = false;
	}

	update();
}

void PixmapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QGraphicsPixmapItem::paint(painter, option, widget);
	painter->save();

//	painter->setBrush(Qt::black);
	if(mouseIsOverSelectionRect){
		painter->setOpacity(0.2);
	}else{
		painter->setOpacity(0.5);
	}
//	painter->setPen(rectColor);
	painter->fillRect(rect, Qt::black);
	painter->restore();
	painter->drawRect(rect);
}

void PixmapItem::initPI()
{
	setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
	setSelectionRect(QRect());
	setSelectionRectColor(qRgb(0, 0, 0));
	setSelectionRectVisible(false);
}
