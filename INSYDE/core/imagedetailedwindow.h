#ifndef IMAGEDETAILEDWINDOW_H
#define IMAGEDETAILEDWINDOW_H

#include <QtCore>
#include <QtWidgets>

#include "share_core_lib.h"
#include "image.h"
//#include "common.h"
#include "detailedwindow.h"

class Image;

namespace core{

/*!
 * \brief The ImageDetailedWindow class involves a widget where an Image object will
 * be shown in detail. This allows to select image segments and edit them.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT ImageDetailedWindow : public DetailedWindow
{
	public:

		/*!
		 * \brief An empty widget with no Image.
		 *
		 * \param[in] parent The parent of this widget.
		 */
		explicit ImageDetailedWindow(QWidget *parent = 0);

		/*!
		 * \brief A widget with a \p image.
		 * \param image The pre-built image.
		 * \param parent The parent of this widget.
		 */
		explicit ImageDetailedWindow(QImage *image, QWidget *parent = 0);

		/*!
		 * \brief A widget with an Image loaded from \p imgpath.
		 * \param imgpath The path of the image file.
		 * \param parent The parent of this widget.
		 */
		explicit ImageDetailedWindow(const QString &imgpath, QWidget *parent = 0);

		~ImageDetailedWindow();

		/*!
		 * \brief Loads this Image object with a \p img image.
		 * \param img A pre-built image.
		 */
		void setImage(QImage *img);

		/*!
		 * \brief Gets a pointer to the image of this object.
		 * \return A QImage pointer.
		 */
		QImage *getImage() const;

		/*!
		 * \brief Gets a copy of the selected segment of the image.
		 * \return A QImage object which is the selected segment of the image.
		 */
		QImage getImageSegment() const;

		/*!
		 * \brief Sets a new pre-built Image object.
		 *
		 * This method is very useful when user wants to show a pre-existing Image object in details,
		 * ie. showing it in a new windows.
		 *
		 * \note User is responsible for managing hangling pointers.
		 *
		 * \param pmitm The pointer to the Image object.
		 */
		void setImageObject(Image *pmitm);

		/*!
		 * \brief Returns the Image object of this detailed window.
		 * \return The image object.
		 */
		Image *getImageObject();

		//		void setBorderVisible(bool bv);
		//		bool getBorderVisible() const;

		//		void setBorderColor(const QColor &color);
		//		QColor getBorderColor() const;

		/*!
		 * \brief Enables or not the selection rectangle.
		 * \param srv True if the rectangle will be visible.
		 */
		void setSelectionRectVisible(bool srv);

		/*!
		 * \brief Return the status of the visibility of the selection rectangle.
		 * \return A boolean which represents the status of the selection rectangle.
		 */
		bool getSelectionRectVisible() const;

		/*!
		 * \brief Sets the color of the selection rectangle. Useful to customize it.
		 * \param color The new color to assign.
		 */
		void setSelectionRectColor(const QColor &color);

		/*!
		 * \brief Returns the color of the selection rectangle.
		 * \return The color of the selection rectangle.
		 */
		QColor getSelectionRectColor() const;

		/*!
		 * \brief Sets a new selection rectangle.
		 *
		 * \param rect The new selection rectangle.
		 */
		void setSelectionRect(const QRect &rect);

		/*!
		 * \brief Returns the selection rectangle object.
		 * \return A copy of the current selection rectangle with all properties like coordinates and dimensions.
		 */
		QRect getSelectionRect() const;

	private:
		Q_OBJECT

		Image *pmItm;

		/*!
		 * \brief Initializes this window.
		 * \param img The image to be loaded to the Image object.
		 */
		void init(QImage *img);
};
}
#endif
