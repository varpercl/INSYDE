#ifndef PIXMAPITEM_H
#define PIXMAPITEM_H

#include <QtWidgets>

class PixmapItem : public QGraphicsPixmapItem
{
	public:

		explicit PixmapItem(const QPixmap &pm, QGraphicsItem *parent = 0);

		void setSelectionRectVisible(bool rv);
		bool getSelectionRectVisible() const;

		void setSelectionRect(const QRect &sr);
		QRect getSelectionRect() const;

		void setSelectionRectColor(const QColor &color);
		QColor getSelectionRectColor() const;

		QImage getImageSegment() const;

	protected:

		void mousePressEvent(QGraphicsSceneMouseEvent *event);
		void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	private:

		bool mouseIsOverSelectionRect;
		QColor rectColor;
		bool rectVisible;
		QRect rect;

		void initPI();
};

#endif // PIXMAPITEM_H
