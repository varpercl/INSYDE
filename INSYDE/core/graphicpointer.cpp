#include "graphicpointer.h"

core::GraphicPointer::GraphicPointer()
{
//    Q_INIT_RESOURCE(core_media);
    init(40, 80);
}

core::GraphicPointer::GraphicPointer(double width)
{
//    Q_INIT_RESOURCE(core_media);
    init(width, width*2);
}

core::GraphicPointer::~GraphicPointer()
{
}

void core::GraphicPointer::init(double width, double height){
    lineWidth = 4;
    curShape.lineTo(QPointF(width, 0));
    curShape.lineTo(QPointF(width*0.7, -height*0.1));
    curShape.moveTo(QPointF(width, 0));
    curShape.lineTo(QPointF(width*0.7, height*0.1));
    curShape.moveTo(QPointF(0, -height/2));
    curShape.lineTo(QPointF(0, height/2));
}

void core::GraphicPointer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(widget);
    Q_UNUSED(option);
    QColor color;
    color.setRgb(200, 150, 0);

    QPen pen;
    pen.setWidth(lineWidth);
    pen.setColor(color);
    painter->save();
    painter->setPen(pen);
    painter->drawPath(curShape);
	painter->restore();
}

QString core::GraphicPointer::getXML() const
{
	//TODO: implement
	return "";
}

QPainterPath core::GraphicPointer::shape() const{
    return curShape;
}
QRectF core::GraphicPointer::boundingRect() const{
    QRectF rect = curShape.controlPointRect();
    rect.adjust(-lineWidth, -lineWidth, lineWidth, lineWidth);
    return rect;
}
