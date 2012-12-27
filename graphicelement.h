#ifndef GRAPHICELEMENT_H
#define GRAPHICELEMENT_H

#include <QtGui>

class GraphicElement : public QGraphicsObject
{
	public:
		explicit GraphicElement();
		explicit GraphicElement(const QRectF &rect, int border = 2);

		~GraphicElement();


		virtual QMenu* getContextMenu(QMenu *menu);
		void setBorderWidth(int width);
		void setRectangle(const QRectF &rect);
		QRectF getRectangle();

	protected:

//		QMenu *cntxMenu;

//		void mousePressEvent(QGraphicsSceneMouseEvent *event);

		QPainterPath shape() const;
		QRectF boundingRect() const;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

		//        void mousePressEvent(QGraphicsSceneMouseEvent *event);
		//        void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
		//        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

	protected slots:
		virtual void onPropertyClick();
		virtual void onDeleteClick();

	private:

		Q_OBJECT

		int border;
		QRectF rectangle, intRectangle;

		void initGE(const QRectF &rect, int border);
};

#endif // GRAPHICELEMENT_H
