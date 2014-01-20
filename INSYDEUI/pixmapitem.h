#ifndef PIXMAPITEM_H
#define PIXMAPITEM_H

#include <QtWidgets>

class PixmapItem : public QGraphicsPixmapItem
{
	public:

		explicit PixmapItem(const QPixmap &pm, QGraphicsItem *parent = 0);

		void setSelectionRectVisible(bool rv);
		bool getSelectionRectVisible() const;

		void setSelectionRect(const QRectF &sr);
		QRectF getSelectionRect() const;

		void setSelectionRectColor(const QColor &color);
		QColor getSelectionRectColor() const;

	protected:

		void mousePressEvent(QGraphicsSceneMouseEvent *event);
		void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	private:

		bool mouseIsOverSelectionRect;
		QColor rectColor;
		bool rectVisible;
		QRectF rect;

		void initPI();
};

#endif // PIXMAPITEM_H
