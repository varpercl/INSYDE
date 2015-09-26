#include "imagedetailedwindow.h"

ImageDetailedWindow::ImageDetailedWindow(const QImage &image, QWidget *parent) :
	DetailedWindow(parent)
{
	init(image);
}

void ImageDetailedWindow::setImage(const QImage &img)
{
//	QGraphicsPixmapItem *pmItm = dynamic_cast<QGraphicsPixmapItem*>(itm);
	pmItm->setImage(img);
	rect->setRect(pmItm->boundingRect().adjusted(-1, -1, 0, 0));
	getGraphicsView()->scene()->setSceneRect(pmItm->boundingRect());
	getGraphicsView()->update();
}//setImage

QImage ImageDetailedWindow::getImage() const
{
	return pmItm->getImage();
}//getImage

QImage ImageDetailedWindow::getImageSegment() const
{
	return pmItm->getImageSelection();
}

void ImageDetailedWindow::setImageObject(Image *pmitm)
{
	pmItm = pmitm;
}//setGraphicsPixmapItem

Image *ImageDetailedWindow::getImageObject()
{
	return pmItm;
}//getGraphicsPixmapItem

void ImageDetailedWindow::setBorderVisible(bool bv)
{
	rect->setVisible(bv);
}//setBorderVisible

bool ImageDetailedWindow::getBorderVisible() const
{
	return rect->isVisible();
}//getBorderVisible

void ImageDetailedWindow::setBorderColor(const QColor &color)
{
	rect->setPen(QPen(color));
}//setBorderColor

QColor ImageDetailedWindow::getBorderColor() const
{
	return rect->pen().color();
}//getBorderColor

void ImageDetailedWindow::setSelectionRectVisible(bool srv)
{
	pmItm->setSelectionRectVisible(srv);
}//setSelectionRectVisible

bool ImageDetailedWindow::getSelectionRectVisible() const
{
	return pmItm->getSelectionRectVisible();
}//getSelectionRectVisible

void ImageDetailedWindow::setSelectionRectColor(const QColor &color)
{
	pmItm->setSelectionRectColor(color);
}//setSelectionRectColor

QColor ImageDetailedWindow::getSelectionRectColor() const
{
	return pmItm->getSelectionRectColor();
}

void ImageDetailedWindow::setSelectionRect(const QRect &rect)
{
	pmItm->setSelectionRect(rect);
}

QRect ImageDetailedWindow::getSelectionRect() const
{
	return pmItm->getSelectionRect();
}

void ImageDetailedWindow::init(const QImage &img)
{
	pmItm = new Image();

	rect = new QGraphicsRectItem();

	setImage(img);

	getGraphicsView()->scene()->addItem(pmItm);
	getGraphicsView()->scene()->addItem(rect);

	pmItm->grabMouse();

	setEnableZooming(true);

}//initWindow
