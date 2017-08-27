#ifndef GRAPHICDETAILEDVIEW_H
#define GRAPHICDETAILEDVIEW_H

#include <QtCore>
#include <QtWidgets>

#include "share_core_lib.h"
#include "graphicpointer.h"
#include "vector2d.h"
#include "enviroment.h"

namespace core{

/*!
 * \brief The GraphicDetailedView class a graphic detailed view is a speciallized QGraphicsView class
 * which allows to draw any kind of GraphicObject in detail.
 *
 * It is commonly used in the graphic data representations.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date
 */
class CORE_LIB_IMPORT_EXPORT GraphicDetailedView : public QGraphicsView
{
	public:

		/*!
		 * \brief An empty instance with a \p parent.
		 *
		 * \param[in] parent The parent of this widget.
		 */
		explicit GraphicDetailedView(QWidget *parent = 0);

		/*!
		 * \brief An instance with a defined Enviroment \p env.
		 *
		 * \param[in] env The default enviroment.
		 * \param[in] parent The parent of this view.
		 */
		explicit GraphicDetailedView(Enviroment *env, QWidget *parent = 0);

		~GraphicDetailedView();

		/*!
		 * \brief Determines if dotted grid will be visible.
		 *
		 * TODO: evaluate if this method is necessary becaus Enviroment class has a similar method.
		 * \param b True in case of grid visible.
		 */
		void setGridVisible(bool b);

		/*!
		 * \brief Makes the grid visible.
		 *
		 * TODO: evaluate if this method is necessary becaus Enviroment class has a similar method.
		 * \return True in case of grid visible.
		 */
		bool getGridVisible() const;

		/*!
		 * \brief Determines wether a marker will be drawn at the center of the enviroment.
		 *
		 * TODO: evaluate if this method is necessary becaus Enviroment class has a similar method.
		 *
		 * \param b True in case the marker will be visible.
		 */
		void setCenterMarkerVisible(bool b);

		/*!
		 * \brief Gets the visibility of the marker.
		 *
		 * TODO: evaluate if this method is necessary becaus Enviroment class has a similar method.
		 *
		 * \return True in case of marker visible.
		 */
		bool getCenterMarkerVisible() const;

	public slots:

		/*!
		 * \brief Removes the selected GraphicObjects.
		 */
		void removeSelected();

	protected:

		void contextMenuEvent(QContextMenuEvent *event) override;
		void mousePressEvent(QMouseEvent *event) override;
		void mouseMoveEvent(QMouseEvent *event) override;
		void mouseReleaseEvent(QMouseEvent *event) override;

	signals:

		/*!
		 * \brief A signal to comunicate the click event to other objects.
		 *
		 * \param event The event object.
		 */
		void mousePressed(QMouseEvent *event);

	private:
		Q_OBJECT

		QPointF
		posInicialMouse,
		posActualMouse;

		GraphicPointer *apuntador;

		Enviroment *enviroment;

		/*!
		 * \brief Initializes all graphic interface.
		 * \param env The default enviroment.
		 */
		void init(Enviroment *env);

		/*!
		 * \brief Determines if want to show a pointer pointing in the direction of the mouse drag.
		 *
		 * TODO: evaluate if this method is necessary in this class.
		 *
		 * \param angle The angle of the pointer.
		 */
		void showPointer(double angle);

		/*!
		 * \brief Removes the visible pointer.
		 */
		void removePointer();

		/*!
		 * \brief Determines if the GraphicObjects \p list are different.
		 * \param list The list of objects.
		 * \return True in case at least one is different than others.
		 */
		bool areDifferentTypes(const QList<QGraphicsItem*> &list);
};
}
#endif // GRAPHICDETAILEDVIEW_H
