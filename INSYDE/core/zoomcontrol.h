#ifndef ZOOMCONTROL_H
#define ZOOMCONTROL_H

#include <QtWidgets>

#include "share_core_lib.h"
#include "definitions.h"

namespace core{

/*!
 * \brief The ZoomControl class contains all properties of a zooming control. It allows
 * users to zoom in and zoom out, also users can change graphics properties like icons and so much.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT ZoomControl : public QToolBar
{
	public:

		/*!
		 * \brief Build a basic zoom control.
		 * \param parent The parent of this control.
		 */
		explicit ZoomControl(QWidget *parent = 0);

		~ZoomControl();

		/*!
		 * \brief Sets the minimum zoom allowed.
		 * \param min The minimum zoom.
		 */
		void setMinZoom(int min);

		/*!
		 * \brief Gets the minimum zoom allowed by this control.
		 * \return An integer that holds the minimum zoom allowed.
		 */
		int getMinZoom() const;

		/*!
		 * \brief Sets the maximum zoom allowed.
		 * \param max The maximum zoom.
		 */
		void setMaxZoom(int max);

		/*!
		 * \brief Gets the maximum zoom allowed by this control.
		 * \return An integer that holds the maximum zoom allowed.
		 */
		int getMaxZoom() const;

		/*!
		 * \brief Sets the maximum and minimum values to \p max and \p min respectively
		 * in one step.
		 * \param min The minimum zoom value.
		 * \param max The maximum zoom value.
		 */
		void setZoomRange(int min, int max);

		/*!
		 * \brief Sets the current zoom value.
		 * \param percentaje The new zoom value.
		 */
		void setZoom(int percentaje);

		/*!
		 * \brief Returns the current zoom value.
		 * \return  An integer that holds the zoom value.
		 */
		int getZoom() const;

	signals:

		/*!
		 * \brief This is thrown when zoom has changed.
		 *
		 * \param zoom The new zoom.
		 */
		void zoomChanged(int zoom);

	private slots:

		/*!
		 * \brief This slot just emit the zoomChanged signal when user has changed
		 * manually the value, ie writing inside spin box.
		 * \param val The new zoom value.
		 */
		void onEditZoomChanged(int val);

	private:
		Q_OBJECT

		QToolButton
		*btnZoomIn,
		*btnZoomOut;

		QSpinBox *sbZoom;

		/*!
		 * \brief Initializes all graphic interface.
		 */
		void init();
};
}
#endif // ZOOMCONTROL_H
