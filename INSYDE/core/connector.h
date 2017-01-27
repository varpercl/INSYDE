#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QtCore>

#include "share_core_lib.h"
#include "graphicobject.h"
#include "graphicdetailedview.h"
#include "restrictedlinef.h"

namespace core{

/*!
 * \brief The Connector class represents an interactive composed line which represents
 * a graphic connection between two GraphicObjects.
 * A connector must have an origin and end.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 *
 */
class CORE_LIB_IMPORT_EXPORT Connector : public GraphicObject
{

	public:

		/*!
		 * \brief The basic constructor, represents a null connector. This means
		 * a connector who has no origin object and no end object.
		 *
		 * This can be drawn depending on position where the connector is placed.
		 *
		 */
		explicit Connector();

		/*!
		 * \brief A connector who will start connected to \p begin and will end connected to
		 * \p end object respectively.
		 *
		 * \param begin The begining object.
		 * \param end The end object.
		 */
		explicit Connector(GraphicObject *begin, GraphicObject *end);

		~Connector();

		/*!
		 * \brief The type of this object. In this case type will be \c GraphicObjectTypes::gotConnector.
		 *
		 * \return An integer representing the type of this object.
		 */
		int type() const override;


		QSizeF getSize() const override;
		double getWidth() const override;
		double getHeight() const override;

		// GraphicObject interface
		void setInputElement(GraphicObject *ge) override;
		QString getXML() const override;

		/*!
		 * \brief Establish who will be the origin object the connector will start at.
		 *
		 * \note This method doesn't delete the current begining object. So the user is
		 * responsible for memory administration.
		 *
		 * \param begin The origin object.
		 */
		void setBeginObject(GraphicObject *begin);

		/*!
		 * \brief Establish who will be the end object the connector will end at.
		 *
		 * \note This method doesn't delete the current ending object. So the user is
		 * responsible for memory administration.
		 *
		 * \param end The ending object.
		 */
		void setEndObject(GraphicObject *end);

	protected slots:

		void propertyClick() override;

	protected:

		/*!
		 * \brief The CollidingResult struct involves a determined line and the current points it is intersecting at.
		 * This members means \c line intersects \i n \c objects  at determined \c points  (each point belongs to
		 * \c line)
		 */
		struct CollidingResult{
			public:
				int lineIndex;
				RestrictedLineF *line;
				QList<QPointF*> points;
				QList<GraphicObject*> objects;
		};

		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

		/*!
		 * \brief hoverMoveEvent
		 * \param event
		 */
//		void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;

		bool eventFilter(QObject *sender, QEvent *event) override;

		QRectF boundingRect() const override;

		QPainterPath shape() const override;

	private:
		Q_OBJECT

		bool isBuildingConector; /**< Holds the current status of the connector. If it's being built this variable will be true */

		QPolygonF shapeForm; /**< The shape of this connector, this is used to perform collition detections */

		double clearance;
		
		QVector<RestrictedLineF*> composedLine;

		QPointF
		beginPoint,
		endPoint;

		GraphicObject
		*beginObject,
		*endObject;

		void init(GraphicObject *begin, GraphicObject *end);

		//Temporarily this object can not be clipboarded. Studying this for future

		void copyClick() override {}
		void cutClick() override {}
		void pasteClick() override {}


		//This inherited method are now private and user can not use it to resize a conector object because it will
		//Resize itself by user mouse entry

		void setSize(const QSizeF &size) override {(void)size;}
		void setWidth(double w) override {(void)w;}
		void setHeight(double h) override {(void)h;}

		/*!
		 * \brief Generates a set of lines that compose a conector with an origin and end.
		 * \param begin The point where the connector will start at.
		 * \param end The point where the connector will end at.
		 */
		void updateConectorLine(const QPointF &begin, const QPointF &end);

		/*!
		 * \brief This helper function will remove ignored objects during colition detection.
		 *
		 * \param list The list of items that will be scanned.
		 * \return A cleaned items list without the ignored items.
		 *
		 */
		QList<QGraphicsItem *> removeIgnoredObjects(const QList<QGraphicsItem*> &list) const;

		/*!
		 * \overload
		 */
		QList<GraphicObject *> removeIgnoredObjects(const QList<GraphicObject*> &list) const;

		/*!
		 * \brief Returns the closer item to \p pos located on the container \p list.
		 * This function basicly checks the perimeter of each item in \p list and performs calculus
		 * to determine which is closer.
		 *
		 * \param pos The position to be compared.
		 * \param side The side of the items the user wants to check.
		 * \param list The list of items to be checked.
		 * \return A pointer to the closer item.
		 */
		QGraphicsItem *closerItemPerif(const QPointF &pos, Port side, const QList<QGraphicsItem*> &list);

		/*!
		 * \brief Gets a list of all objects in colition with a set of \p lines.
		 *
		 * \param lines The set of lines to be analyzed.
		 *
		 * \return A list of items that colides with the set of \p lines.
		 */
		QList<CollidingResult> collidingObjects(const QVector<RestrictedLineF*> &lines) const;

		/*!
		 * \brief Performs a convertion from a basic QRectF to a set of RestrictedLineFs.
		 *
		 * \param rect The rectangle to be converted.
		 *
		 * \return A set of four lines which represents the converted \p rect.
		 */
		QVector<RestrictedLineF*> convertRect(const QRectF &rect) const;

};
}
#endif // CONNECTOR_H
