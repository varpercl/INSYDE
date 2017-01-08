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
 * \class
 *
 * \brief The ImageDetailedWindow class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT ImageDetailedWindow : public DetailedWindow
{
	public:

		/*!
		 * \brief ImageDetailedWindow
		 * \param parent
		 */
		explicit ImageDetailedWindow(QWidget *parent = 0);
		explicit ImageDetailedWindow(QImage *image, QWidget *parent = 0);

		~ImageDetailedWindow();

		void setImage(QImage *img);
		QImage *getImage() const;

		QImage getImageSegment() const;

		void setImageObject(Image *pmitm);
		Image *getImageObject();

		//		void setBorderVisible(bool bv);
		//		bool getBorderVisible() const;

		//		void setBorderColor(const QColor &color);
		//		QColor getBorderColor() const;

		void setSelectionRectVisible(bool srv);
		bool getSelectionRectVisible() const;

		void setSelectionRectColor(const QColor &color);
		QColor getSelectionRectColor() const;

		void setSelectionRect(const QRect &rect);
		QRect getSelectionRect() const;

	private:
		Q_OBJECT

		Image *pmItm;

		void init(QImage *img);
};
}
#endif
