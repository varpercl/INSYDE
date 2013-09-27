#ifndef GRAPHICCURSORELEMENT_H
#define GRAPHICCURSORELEMENT_H

#include <QRect>

#include <graphicelement.h>

/**
 * @brief The GraphicCursorElement class
 *
 *Abstracta
 */
class GraphicCursorElement : public GraphicElement
{
	public:
		explicit GraphicCursorElement(const QRect &rect);
		explicit GraphicCursorElement(int x, int y, int w, int h);

		void setCursorRect(const QRect &rect);
		void setCursorRect(int x, int y, int w, int h);
		void setCursorVisible(bool vis);

	signals:
		void cursorPositionChanged(QPoint pt);
		
	public slots:

	private:

		Q_OBJECT
		
		QGraphicsRectItem *grect;
};

#endif // GRAPHICCURSORELEMENT_H
