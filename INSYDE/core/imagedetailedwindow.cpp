#include "imagedetailedwindow.h"

ImageDetailedWindow::ImageDetailedWindow(QWidget *parent) :
	DetailedWindow(parent)
{
	init(new QImage());
}

ImageDetailedWindow::ImageDetailedWindow(QImage *image, QWidget *parent) :
	DetailedWindow(parent)
{
	init(image);
}

ImageDetailedWindow::~ImageDetailedWindow()
{

}

void ImageDetailedWindow::setImage(QImage *img)
{
	pmItm->setImage(img);

	getGraphicsDetailedView()->scene()->setSceneRect(pmItm->boundingRect().adjusted(-10, -10, 10, 10));
	getGraphicsDetailedView()->update();
}

QImage *ImageDetailedWindow::getImage() const
{
	return pmItm->getImage();
}

QImage ImageDetailedWindow::getImageSegment() const
{
	return pmItm->getImageSelection();
}

void ImageDetailedWindow::setImageObject(Image *pmitm)
{
	pmItm = pmitm;
}

Image *ImageDetailedWindow::getImageObject()
{
	return pmItm;
}

//void ImageDetailedWindow::setBorderVisible(bool bv)
//{
//	pmItm->setBorder();
//}

//bool ImageDetailedWindow::getBorderVisible() const
//{
//	return rect->isVisible();
//}

//void ImageDetailedWindow::setBorderColor(const QColor &color)
//{
//	rect->setPen(QPen(color));
//}

//QColor ImageDetailedWindow::getBorderColor() const
//{
//	return rect->pen().color();
//}

void ImageDetailedWindow::setSelectionRectVisible(bool srv)
{
	pmItm->setSelectionRectVisible(srv);
}

bool ImageDetailedWindow::getSelectionRectVisible() const
{
	return pmItm->getSelectionRectVisible();
}

void ImageDetailedWindow::setSelectionRectColor(const QColor &color)
{
	pmItm->setSelectionRectColor(color);
}

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

void ImageDetailedWindow::init(QImage *img)
{
	pmItm = new Image(img);

	getGraphicsDetailedView()->scene()->addItem(pmItm);

	pmItm->getRemoveAction()->setVisible(false);
	pmItm->getCutAction()->setVisible(false);
	pmItm->getPasteAction()->setVisible(false);
	pmItm->getOpenAction()->setVisible(false);
	pmItm->setShowOnlyThumbnail(false);
	pmItm->setFlag(Image::ItemIsMovable, false);

	setImage(img);

	setEnableZooming(true);

}
