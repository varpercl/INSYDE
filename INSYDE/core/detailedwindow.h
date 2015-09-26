#ifndef GRAPHICELEMENTDETAILEDWINDOW_H
#define GRAPHICELEMENTDETAILEDWINDOW_H

#include <QtWidgets>

#include "zoomcontrol.h"
#include "icons.h"

/*!
 * \class
 *
 * \brief The ElementDetailedWindow class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT DetailedWindow : public QWidget
{

	public:
		explicit DetailedWindow(QWidget *parent = 0);
		~DetailedWindow();

		void setVisibleToolbar(bool vtb);

		/*!
		 * \brief setEnableZooming allows user zooming over represented object.
		 * \param zoom
		 */
		void setEnableZooming(bool zoom);
		bool getEnableZooming() const;

	protected:

		void setToolbar(QToolBar *tb);
		QToolBar *getToolbar();

		void setGraphicView(QGraphicsView *gv);
		QGraphicsView *getGraphicsView() const;

	protected slots:

		virtual void save(){}

	private slots:

		void onZoomChanged(int zoom);

	private:
		Q_OBJECT

		bool zooming;

		double zoom;

		QAction
		*actionZoomControl;

		ZoomControl *zc;

		QToolBar *mainToolbar;
		QGraphicsView *gv;
		QVBoxLayout *mainLayout;

		void connectGVSignals();

		void init();

};

#endif // GRAPHICELEMENTDETAILEDWINDOW_H
