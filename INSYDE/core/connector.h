#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QtCore>

#include "share_core_lib.h"
#include "graphicobject.h"
#include "graphicdetailedview.h"
#include "restrictedlinef.h"

/*!
 * \brief The Connector class
 */
class CORE_LIB_IMPORT_EXPORT Connector : public GraphicObject
{

	public:

		explicit Connector();

		explicit Connector(GraphicObject *begin, GraphicObject *end);

		~Connector();

		int type() const override;


		QSizeF getSize() const override;
		double getWidth() const override;
		double getHeight() const override;

		// GraphicObject interface
		void setInputElement(GraphicObject *ge) override;
		QString getXML() const override;

		/*!
		 * \brief setBeginObject
		 * \param begin
		 */
		void setBeginObject(GraphicObject *begin);

		/*!
		 * \brief setEndObject
		 * \param end
		 */
		void setEndObject(GraphicObject *end);

	protected slots:

		void propertyClick() override;

	protected:

		/*!
		 * \brief The CollidingResult struct involves a determined line and the current points it is intersecting at.
		 * This members means \code{line} intersects n \code{objects} at determined \code{points} (each point belongs to \code{line})
		 */
		struct CollidingResult{
			public:
				int lineIndex;
				RestrictedLineF *line;
				QList<QPointF*> points;
				QList<GraphicObject*> objects;
		};

		/*!
		 * \brief paint
		 * \param painter
		 * \param option
		 * \param widget
		 */
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

		/*!
		 * \brief hoverMoveEvent
		 * \param event
		 */
//		void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;

		/*!
		 * \brief eventFilter
		 * \param sender
		 * \param event
		 * \return
		 */
		bool eventFilter(QObject *sender, QEvent *event) override;

		/*!
		 * \brief boundingRect
		 * \return
		 */
		QRectF boundingRect() const override;

		QPainterPath shape() const override;

	private:
		Q_OBJECT

		bool isBuildingConector;

		QPolygonF shapeForm;

		double clearance;
		
		QVector<RestrictedLineF*> composedLine;

		QPointF
		beginPoint,
		endPoint;

		GraphicObject
		*beginObject,
		*endObject;

		void init(GraphicObject *begin, GraphicObject *end);

		//Temporary this object can not be clipboarded. Studying this for future

		/*!
		 * \brief copyClick
		 */
		void copyClick() override {}

		/*!
		 * \brief cutClick
		 */
		void cutClick() override {}

		/*!
		 * \brief pasteClick
		 */
		void pasteClick() override {}


		//This inherited method are now private and user can not use it to resize a conector object because it will
		//Resize itself by user mouse entry

		/*!
		 * \brief setSize
		 * \param size
		 */
		void setSize(const QSizeF &size) override {(void)size;}

		/*!
		 * \brief setWidth
		 * \param w
		 */
		void setWidth(double w) override {(void)w;}

		/*!
		 * \brief setHeight
		 * \param h
		 */
		void setHeight(double h) override {(void)h;}

		/*!
		 * \brief updateConectorLine Generates a set of lines that compose a conector with an origin and end.
		 * \param pos
		 */
		void updateConectorLine(const QPointF &begin, const QPointF &end);

		/*!
		 * \brief removeConectors Removes the conector itself and the \code{beginObject}
		 * \param list
		 * \return
		 */
		QList<QGraphicsItem *> removeIgnoredObjects(const QList<QGraphicsItem*> &list) const;

		/*!
		 * \brief removeIgnoredObjects Removes the conector itself and the \code{beginObject]
		 * \param list
		 * \return
		 */
		QList<GraphicObject *> removeIgnoredObjects(const QList<GraphicObject*> &list) const;

		/*!
		 * \brief closerItemPerif
		 * \param pos
		 * \param side
		 * \param list
		 * \return
		 */
		QGraphicsItem *closerItemPerif(const QPointF &pos, Port side, const QList<QGraphicsItem*> &list);

		/*!
		 * \brief collidingItems
		 * \param mode
		 * \return
		 */
		QList<CollidingResult> collidingObjects(const QVector<RestrictedLineF*> &lines) const;

		QVector<RestrictedLineF*> convertRect(const QRectF &rect) const;
};

#endif // CONNECTOR_H
