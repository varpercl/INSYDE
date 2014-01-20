#include "graphicimageelementdetailedwindow.h"

GraphicImageElementDetailedWindow::GraphicImageElementDetailedWindow(const QImage &image, QWidget *parent) :
	GraphicElementDetailedWindow(parent)
{
	initWindow(image);
}//GraphicImageElementDetailedWindow

QGraphicsView *GraphicImageElementDetailedWindow::getGraphicsView()
{
	return gv;
}//getGraphicsView

void GraphicImageElementDetailedWindow::setImage(const QImage &img)
{
	this->img = img;
//	QGraphicsPixmapItem *pmItm = dynamic_cast<QGraphicsPixmapItem*>(itm);
	pmItm->setPixmap(QPixmap::fromImage(img));
	rect->setRect(pmItm->boundingRect().adjusted(-1, -1, 0, 0));
	gv->scene()->setSceneRect(pmItm->boundingRect());
	gv->update();
}//setImage

QImage GraphicImageElementDetailedWindow::getImage() const
{
	return img;
}//getImage

void GraphicImageElementDetailedWindow::setGraphicsPixmapItem(PixmapItem *pmitm)
{
	pmItm = pmitm;
}//setGraphicsPixmapItem

QGraphicsPixmapItem *GraphicImageElementDetailedWindow::getGraphicsPixmapItem()
{
	return pmItm;
}//getGraphicsPixmapItem

void GraphicImageElementDetailedWindow::setBorderVisible(bool bv)
{
	rect->setVisible(bv);
}//setBorderVisible

bool GraphicImageElementDetailedWindow::getBorderVisible() const
{
	return rect->isVisible();
}//getBorderVisible

void GraphicImageElementDetailedWindow::setBorderColor(const QColor &color)
{
	rect->setPen(QPen(color));
}//setBorderColor

QColor GraphicImageElementDetailedWindow::getBorderColor() const
{
	return rect->pen().color();
}//getBorderColor

void GraphicImageElementDetailedWindow::setSelectionRectVisible(bool srv)
{
	pmItm->setSelectionRectVisible(srv);
}//setSelectionRectVisible

bool GraphicImageElementDetailedWindow::getSelectionRectVisible() const
{
	return pmItm->getSelectionRectVisible();
}//getSelectionRectVisible

void GraphicImageElementDetailedWindow::setSelectionRectColor(const QColor &color)
{
	pmItm->setSelectionRectColor(color);
}//setSelectionRectColor

QColor GraphicImageElementDetailedWindow::getSelectionRectColor() const
{
	return pmItm->getSelectionRectColor();
}//getSelectionRectColor

void GraphicImageElementDetailedWindow::setSelectionRect(const QRectF &rect)
{
	pmItm->setSelectionRect(rect);
}//setSelectionRect

QRectF GraphicImageElementDetailedWindow::getSelectionRect() const
{
	return pmItm->getSelectionRect();
}//getSelectionRect

void GraphicImageElementDetailedWindow::initWindow(const QImage &img)
{
	this->img = img;
	QGraphicsScene *scn = new QGraphicsScene();

	gv = new QGraphicsView(scn, this);
	gv->setMouseTracking(true);
	gv->setContextMenuPolicy(Qt::CustomContextMenu);

	pmItm = new PixmapItem(QPixmap::fromImage(img));
	scn->addItem(pmItm);
	pmItm->grabMouse();

	rect = new QGraphicsRectItem(pmItm->boundingRect().adjusted(-1, -1, 0, 0));
	scn->addItem(rect);

	mainToolbar->layout()->setSpacing(5);
	mainToolbar->setLayoutDirection(Qt::RightToLeft);

	mainToolbar->addAction(QIcon(QPixmap(":imagenes/Zoom in.png")), "Acercar", this, SLOT(onZoomInClick()));

	zoom = 1;
	tZoom = new QLineEdit();
	tZoom->setReadOnly(true);
	tZoom->setMaximumWidth(50);
	tZoom->setAlignment(Qt::AlignCenter);
//	tZoom->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
	tZoom->setText("100%");

	mainToolbar->addWidget(tZoom);

	mainToolbar->addAction(QIcon(QPixmap(":imagenes/Zoom out.png")), "Alejar", this, SLOT(onZoomOutClick()));

	setVisibleToolbar(true);
	layout()->addWidget(gv);

	connect(gv, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu(QPoint)));

}//initWindow

void GraphicImageElementDetailedWindow::contextMenu(QPoint pos)
{
	QMenu *cntxMenu = new QMenu();

	cntxMenu->addAction("Guardar...", this, SLOT(saveImage()));
	cntxMenu->exec(gv->mapToGlobal(pos));
	delete cntxMenu;
}//contextMenu

void GraphicImageElementDetailedWindow::saveImage()
{
	QString path = QFileDialog::getSaveFileName(0, "Guardar imagen", ".", "Portable Network Graphics (*.png);; Bitmap File (*.bmp);; JPEG File(*.jpg)");
//	QGraphicsPixmapItem *pmItm = itm;
	pmItm->pixmap().save(path, "", 100);
}//saveImage

void GraphicImageElementDetailedWindow::onZoomInClick()
{
	if(zoom + 0.1 <= 10){
		gv->scale(1.1, 1.1);
		zoom += 0.1;
		tZoom->setText(QString::number(zoom*100) + "%");
	}
}//onZoomInClick

void GraphicImageElementDetailedWindow::onZoomOutClick()
{
	if(zoom - 0.1 > 0){
		gv->scale(0.9, 0.9);
		zoom -= 0.1;
		tZoom->setText(QString::number(zoom*100) + "%");
	}
}//onZoomOutClick
