#ifndef GRAPHICELEMENTDETAILEDWINDOW_H
#define GRAPHICELEMENTDETAILEDWINDOW_H

#include <QtCore>
#include <QtWidgets>

#include "../core/graphicdetailedview.h"

#include "share_core_lib.h"
#include "zoomcontrol.h"
#include "definitions.h"

namespace core{

/*!
 * \class
 *
 * \brief The ElementDetailedWindow class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT DetailedWindow : public QWidget
{

	public:
		explicit DetailedWindow(QWidget *parent = 0);

		~DetailedWindow();

		void setVisibleToolbar(bool vtb);

		/*!
		 * \brief setEnableZooming allows user zooming over represented object.
		 * \param zoom
		 */
		void setEnableZooming(bool curZoom);

		/*!
		 * \brief getEnableZooming
		 * \return
		 */
		bool getEnableZooming() const;

		/*!
		 * \brief setGraphicView
		 * \param gv
		 */
		void setGraphicDetailedView(GraphicDetailedView *gdv);

		/*!
		 * \brief getGraphicsView
		 * \return
		 */
		GraphicDetailedView *getGraphicsDetailedView() const;

		/*!
		 * \brief setToolbar
		 * \param tb
		 */
		void setToolbar(QToolBar *tb);

		/*!
		 * \brief getToolbar
		 * \return
		 */
		QToolBar *getToolbar();

	protected slots:

		/*!
		 * \brief save
		 */
		virtual void save(){}

	private slots:

		/*!
		 * \brief onZoomChanged
		 * \param curZoom
		 */
		void onZoomChanged(int curZoom);

	private:
		Q_OBJECT

		bool zooming;

		double curZoom;

		QAction
		*actionZoomControl;

		ZoomControl *zc;

		QToolBar *mainToolbar;
		GraphicDetailedView *gdv;
		QVBoxLayout *mainLayout;

		void connectGVSignals();

		void init();

};
}
#endif // GRAPHICELEMENTDETAILEDWINDOW_H
