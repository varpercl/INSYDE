#include "graphiccursorelement.h"

Cursor::Cursor(const QRect &rect) :
	GraphicObject()
{
	grect = new QGraphicsRectItem(rect, this);
	setCursorRect(rect);
	setCursorVisible(false);
}

Cursor::Cursor(int x, int y, int w, int h)
{
	grect = new QGraphicsRectItem(QRect(x, y, w, h), this);
	setCursorRect(QRect(x, y, w, h));
	setCursorVisible(false);
}


void Cursor::setCursorRect(const QRect &rect)
{
	grect->setRect(rect);
}

void Cursor::setCursorRect(int x, int y, int w, int h)
{
	grect->setRect(QRect(x, y, w, h));
}

void Cursor::setCursorVisible(bool vis)
{
	grect->setVisible(vis);
}
