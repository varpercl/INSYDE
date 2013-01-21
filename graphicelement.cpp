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

int GraphicElement::type() const
{
	return GraphicElementType;
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
	Q_UNUSED(widget);

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

void GraphicElement::onDeleteClick()
{
	scene()->removeItem(this);
}

void GraphicElement::initGE(const QRectF &rect, int border)
{
//	cntxMenu = 0;
#if _MSC_VER == 1600
	setAcceptHoverEvents(true);
#else
	setAcceptsHoverEvents(true);
#endif
	setFlags(ItemIsMovable | ItemIsSelectable);

	this->border = border;
	rectangle = rect;
}
