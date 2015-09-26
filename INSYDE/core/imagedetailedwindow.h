#ifndef GRAPHICIMAGEELEMENTDETAILEDWINDOW_H
#define GRAPHICIMAGEELEMENTDETAILEDWINDOW_H

#include <QtCore>

#include "image.h"
#include "common.h"
#include "detailedwindow.h"

class Image;
/*!
 * \class
 *
 * \brief The ImageDetailedWindow class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT ImageDetailedWindow : public DetailedWindow
{
	public:

		explicit ImageDetailedWindow(const QImage &image, QWidget *parent = 0);

		void setImage(const QImage &img);
		QImage getImage() const;

		QImage getImageSegment() const;

		void setImageObject(Image *pmitm);
		Image *getImageObject();

		void setBorderVisible(bool bv);
		bool getBorderVisible() const;

		void setBorderColor(const QColor &color);
		QColor getBorderColor() const;

		void setSelectionRectVisible(bool srv);
		bool getSelectionRectVisible() const;

		void setSelectionRectColor(const QColor &color);
		QColor getSelectionRectColor() const;

		void setSelectionRect(const QRect &rect);
		QRect getSelectionRect() const;

	private:
		Q_OBJECT

		//Representa el rectangulo que rebordeara la imagen
		QGraphicsRectItem *rect;

		Image *pmItm;

		void init(const QImage &img);
};

#endif // GRAPHICIMAGEELEMENTDETAILEDWINDOW_H
