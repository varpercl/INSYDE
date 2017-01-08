#ifndef GRAPHICDETAILEDVIEW_H
#define GRAPHICDETAILEDVIEW_H

#include <QtCore>
#include <QtWidgets>

#include "share_core_lib.h"
#include "graphicpointer.h"
#include "vector2d.h"
#include "enviroment.h"

namespace core{

class CORE_LIB_IMPORT_EXPORT GraphicDetailedView : public QGraphicsView
{
	public:

		/*!
		 * \brief GraphicDetailedView
		 */
		explicit GraphicDetailedView(QWidget *parent = 0);

		/*!
		 * \brief GraphicDetailedView
		 * \param env
		 * \param parent
		 */
		explicit GraphicDetailedView(Enviroment *env, QWidget *parent = 0);

		~GraphicDetailedView();

		/*!
		 * \brief setEnableGrid Determines if dotted grid will be visible
		 * \param b
		 */
		void setGridVisible(bool b);

		/*!
		 * \brief getEnableGrid
		 * \return
		 */
		bool getGridVisible() const;

		/*!
		 * \brief setCenterMarkerVisible Determine wether a marker will be drawn at the center of the enviroment
		 * \param b
		 */
		void setCenterMarkerVisible(bool b);

		/*!
		 * \brief getCenterMarkerVisible
		 * \return
		 */
		bool getCenterMarkerVisible() const;

	public slots:

		/*!
		 * \brief removeSelected
		 */
		void removeSelected();

	protected:

		/*!
		 * \brief contextMenuEvent
		 * \param event
		 */
		void contextMenuEvent(QContextMenuEvent *event) override;

		/*!
		 * \brief mousePressEvent
		 * \param event
		 */
		void mousePressEvent(QMouseEvent *event) override;

		/*!
		 * \brief mouseMoveEvent
		 * \param event
		 */
		void mouseMoveEvent(QMouseEvent *event) override;

		/*!
		 * \brief mouseReleaseEvent
		 * \param event
		 */
		void mouseReleaseEvent(QMouseEvent *event) override;

	signals:

		/*!
		 * \brief clicked
		 * \param event
		 */
		void mousePressed(QMouseEvent *event);

	private:
		Q_OBJECT

		QPointF
		posInicialMouse,
		posActualMouse;

		GraphicPointer *apuntador;

		Enviroment *enviroment;

		void init(Enviroment *env);

		void showPointer(double angle);

		void removePointer();

		bool areDifferentTypes(const QList<QGraphicsItem*> &list);
};
}
#endif // GRAPHICDETAILEDVIEW_H
