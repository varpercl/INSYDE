#include "apuntador.h"

GraphicPointer::GraphicPointer(){
    iniciarApuntador(40, 80);
}

GraphicPointer::GraphicPointer(double width){
    iniciarApuntador(width, width*2);
}

void GraphicPointer::iniciarApuntador(double width, double height){
    lineWidth = 4;
    curShape.lineTo(QPointF(width, 0));
    curShape.lineTo(QPointF(width*0.7, -height*0.1));
    curShape.moveTo(QPointF(width, 0));
    curShape.lineTo(QPointF(width*0.7, height*0.1));
    curShape.moveTo(QPointF(0, -height/2));
    curShape.lineTo(QPointF(0, height/2));
}

void GraphicPointer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
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

QPainterPath GraphicPointer::shape() const{
    return curShape;
}
QRectF GraphicPointer::boundingRect() const{
    QRectF rect = curShape.controlPointRect();
    rect.adjust(-lineWidth, -lineWidth, lineWidth, lineWidth);
    return rect;
}
