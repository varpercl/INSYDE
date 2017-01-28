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
 * \brief The DetailedWindow class is a container that allows users to show a detailed view of
 * any GraphicObject. When users clicks on context menu's Open action a window will be opened.
 *
 * Also this class is used when wants to show detailed views inside TrainingSetDialog.
 *
 * TODO: This class should allow to set a GraphicObject at any time.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT DetailedWindow : public QWidget
{

	public:

		/*!
		 * \brief Builds a windows
		 * \param parent
		 */
		explicit DetailedWindow(QWidget *parent = 0);

		~DetailedWindow();

		/*!
		 * \brief Establish if wants to see a tool bar. This is important when showing some
		 * GraphicsObject because they have different properties.
		 * \param vtb True if want to show the toolbar.
		 */
		void setVisibleToolbar(bool vtb);

		/*!
		 * \brief Allows user zooming over represented object. Setting \p curZoom to \c true
		 * will make a zoom control to appear.
		 *
		 * \param zoom True if wants to have zoom control.
		 */
		void setEnableZooming(bool curZoom);

		/*!
		 * \brief Get the status of the zooming control.
		 *
		 * \return True if the zooming control is shown.
		 */
		bool getEnableZooming() const;

		/*!
		 * \brief Sets the current graphic view inside this widget.
		 * The \p gdv param must not be null.
		 *
		 * \note Setting a new GraphicDetailedView will make the last one to be hangling.
		 * So the user is responsible to manage memory.
		 *
		 * \param[in] gdv An instance of a GraphicDetailedView
		 */
		void setGraphicDetailedView(GraphicDetailedView *gdv);

		/*!
		 * \brief Gets a pointer tu the current GraphicDetailedView.
		 *
		 * \return A GraphicDetailedView pointer.
		 */
		GraphicDetailedView *getGraphicsDetailedView() const;

		/*!
		 * \brief Sets a new toolbar to this widget. By default when constructed this class
		 * has its own toolbar.
		 *
		 * \note User is responsible for freeing memory when the setting a new toolbar because
		 * the current will become to a hangling pointer.
		 *
		 * \param[in] tb A pointer to the new toolbar.
		 */
		void setToolbar(QToolBar *tb);

		/*!
		 * \brief Gets the pointer to the current toolbar.
		 *
		 * \return
		 */
		QToolBar *getToolbar();

	protected slots:

		/*!
		 * \brief Save the current status of this GraphicDetailedView.
		 * This function is virtual, so must be reimplemented in the derived classes.
		 */
		virtual void save(){}

	private slots:

		/*!
		 * \brief Thrown when the zooming control has changed its status.
		 *
		 * \param curZoom The current zoom.
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

		/*!
		 * \brief Connects all signals of this class.
		 */
		void connectGVSignals();

		/*!
		 * \brief Initializes all graphic interface.
		 */
		void init();

};
}
#endif // GRAPHICELEMENTDETAILEDWINDOW_H
