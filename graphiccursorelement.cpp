#include "graphiccursorelement.h"

GraphicCursorElement::GraphicCursorElement(const QRect &rect) :
	GraphicElement()
{
	grect = new QGraphicsRectItem(rect, this);
	setCursorRect(rect);
	setCursorVisible(false);
}

GraphicCursorElement::GraphicCursorElement(int x, int y, int w, int h)
{
	grect = new QGraphicsRectItem(QRect(x, y, w, h), this);
	setCursorRect(QRect(x, y, w, h));
	setCursorVisible(false);
}


void GraphicCursorElement::setCursorRect(const QRect &rect)
{
	grect->setRect(rect);
}

void GraphicCursorElement::setCursorRect(int x, int y, int w, int h)
{
	grect->setRect(QRect(x, y, w, h));
}

void GraphicCursorElement::setCursorVisible(bool vis)
{
	grect->setVisible(vis);
}
