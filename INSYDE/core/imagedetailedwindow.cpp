#include "imagedetailedwindow.h"

core::ImageDetailedWindow::ImageDetailedWindow(QWidget *parent) :
	DetailedWindow(parent)
{
	init(new QImage());
}

core::ImageDetailedWindow::ImageDetailedWindow(QImage *image, QWidget *parent) :
	DetailedWindow(parent)
{
	init(image);
}

core::ImageDetailedWindow::~ImageDetailedWindow()
{

}

void core::ImageDetailedWindow::setImage(QImage *img)
{
	pmItm->setImage(img);

	getGraphicsDetailedView()->scene()->setSceneRect(pmItm->boundingRect().adjusted(-10, -10, 10, 10));
	getGraphicsDetailedView()->update();
}

QImage *core::ImageDetailedWindow::getImage() const
{
	return pmItm->getImage();
}

QImage core::ImageDetailedWindow::getImageSegment() const
{
	return pmItm->getImageSelection();
}

void core::ImageDetailedWindow::setImageObject(core::Image *pmitm)
{
	pmItm = pmitm;
}

core::Image *core::ImageDetailedWindow::getImageObject()
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

void core::ImageDetailedWindow::setSelectionRectVisible(bool srv)
{
	pmItm->setSelectionRectVisible(srv);
}

bool core::ImageDetailedWindow::getSelectionRectVisible() const
{
	return pmItm->getSelectionRectVisible();
}

void core::ImageDetailedWindow::setSelectionRectColor(const QColor &color)
{
	pmItm->setSelectionRectColor(color);
}

QColor core::ImageDetailedWindow::getSelectionRectColor() const
{
	return pmItm->getSelectionRectColor();
}

void core::ImageDetailedWindow::setSelectionRect(const QRect &rect)
{
	pmItm->setSelectionRect(rect);
}

QRect core::ImageDetailedWindow::getSelectionRect() const
{
	return pmItm->getSelectionRect();
}

void core::ImageDetailedWindow::init(QImage *img)
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
