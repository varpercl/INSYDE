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
//	delete inputElement;
//	delete outputElement;
}

QMenu *GraphicElement::getContextMenu(QMenu *menu)
{
	menu->addAction("Borrar", this, SLOT(onDeleteClick()));
	menu->addAction("Propiedades", this, SLOT(onPropertyClick()));
	return menu;
}

void GraphicElement::setBorderWidth(int width)
{
	border = width;
}

void GraphicElement::setRectangle(const QRectF &rect)
{
	rectangle = rect;
	update();
}

void GraphicElement::setRectangle(const QRect &rect)
{
	rectangle = QRectF(rect);
	update();
}

QRectF GraphicElement::getRectangle() const
{
	return rectangle;
}

GraphicElement *GraphicElement::getInputElement() const
{
	return inputElement;
}

void GraphicElement::setOutputElement(GraphicElement *ge)
{
	outputElement = ge;
}

GraphicElement *GraphicElement::getOutputElement() const
{
	return outputElement;
}

int GraphicElement::type() const
{
	return GraphicElementType;
}

QPainterPath GraphicElement::shape() const
{
	QPainterPath path;
	path.addRect(rectangle.adjusted(-(border + sep), -(border + sep), (border + sep), (border + sep)));
	return path;
}

QRectF GraphicElement::boundingRect() const
{
	return rectangle.adjusted(-(border + sep), -(border + sep), (border + sep), (border + sep));
}

void GraphicElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(widget);

	QPen pen;
	painter->save();
	pen.setWidth(border);
//	pen.setColor(Qt::gray);
//	pen.setColor(Qt::transparent);
	painter->setPen(pen);
	if(option->state & (QStyle::State_Selected | QStyle::State_MouseOver)) {
		painter->setBrush(QColor(240,240,240));
		painter->drawRect(rectangle.adjusted(-(border + sep), -(border + sep), (border + sep), (border + sep)));
	}else{
		painter->drawRect(rectangle.adjusted(-border/2, -border/2, border/2, border/2));
	}
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

	sep = 5;
	this->border = border;
	rectangle = rect;
}
