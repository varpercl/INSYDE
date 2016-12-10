#ifndef GRAPHICCURSORELEMENT_H
#define GRAPHICCURSORELEMENT_H

#include <QRect>

#include "share_core_lib.h"
#include "graphicobject.h"

/*!
 * \brief The GraphicCursorElement class
 *
 * TODO: definir concretamente para que se usa esta clase
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT Cursor : public GraphicObject
{
	public:

		explicit Cursor(const QRect &rect);
		explicit Cursor(int x, int y, int w, int h);

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
