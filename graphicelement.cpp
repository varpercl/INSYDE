#include "graphicelement.h"

GraphicElement::GraphicElement()
{
	initGE(QRect(0,0,50,50), 2);
}


GraphicElement::GraphicElement(const QRectF &rect, int border)
{
	initGE(rect, border);
}

GraphicElement::~GraphicElement()
{
}

QMenu *GraphicElement::getContextMenu(QMenu *cntxMenu)
{
	cntxMenu->addAction("Borrar", this, SLOT(onDeleteClick()));
	cntxMenu->addAction("Propiedades", this, SLOT(onPropertyClick()));
	return cntxMenu;
}

void GraphicElement::setBorderWidth(int width)
{
	border = width;
}

void GraphicElement::setRectangle(const QRectF &rect)
{
	rectangle = rect;
}

QRectF GraphicElement::getRectangle()
{
	return rectangle;
}

//void GraphicElement::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//}

QPainterPath GraphicElement::shape() const
{
	QPainterPath path;
	path.addRect(rectangle.adjusted(-border, -border, border, border));
	return path;
}

QRectF GraphicElement::boundingRect() const
{
	return rectangle.adjusted(-border, -border, border, border);
}

void GraphicElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QPen pen;
	painter->save();
	pen.setWidth(border);
	pen.setColor(Qt::transparent);
	if(option->state & (QStyle::State_Selected | QStyle::State_MouseOver)) {
		painter->setBrush(QColor(240,240,240));
		pen.setColor(Qt::gray);
	}
	painter->setPen(pen);
	painter->drawRect(rectangle);
	painter->restore();
}

void GraphicElement::onPropertyClick()
{
	QWidget *w = new QWidget();
	w->show();
}

void GraphicElement::onDeleteClick()
{
}

//void GraphicElement::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    QGraphicsObject::mousePressEvent(event);
//}

//void GraphicElement::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
//{
//    QGraphicsObject::mouseDoubleClickEvent(event);
//}

//void GraphicElement::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//{
//    QGraphicsObject::mouseMoveEvent(event);
//}

void GraphicElement::initGE(const QRectF &rect, int border)
{
//	cntxMenu = 0;
	setAcceptsHoverEvents(true);
	setFlags(ItemIsMovable | ItemIsSelectable);

	this->border = border;
	rectangle = rect;
}
