#include "graphicimageelementdetailedwindow.h"

GraphicImageElementDetailedWindow::GraphicImageElementDetailedWindow(QImage *image, QWidget *parent) :
	GraphicElementDetailedWindow(parent)
{
	initWindow(image);
}

QGraphicsView *GraphicImageElementDetailedWindow::getGraphicsView()
{
	return gv;
}

void GraphicImageElementDetailedWindow::setImage(QImage *img)
{
	this->img = img;
//	QGraphicsPixmapItem *pmItm = dynamic_cast<QGraphicsPixmapItem*>(itm);
	itm->setPixmap(QPixmap::fromImage(*img));
	rect->setRect(itm->boundingRect());
	gv->scene()->setSceneRect(itm->boundingRect());
	gv->update();
}

QImage *GraphicImageElementDetailedWindow::getImage()
{
	return img;
}

void GraphicImageElementDetailedWindow::setGraphicsPixmapItem(QGraphicsPixmapItem *pmitm)
{
	itm = pmitm;
}

QGraphicsPixmapItem *GraphicImageElementDetailedWindow::getGraphicsPixmapItem()
{
	return itm;
}


void GraphicImageElementDetailedWindow::initWindow(QImage *img)
{
	this->img = new QImage(*img);
	gv = new QGraphicsView(new QGraphicsScene(), this);
	itm = gv->scene()->addPixmap(QPixmap::fromImage(*img));

	rect = new QGraphicsRectItem(itm->boundingRect());
	gv->scene()->addItem(rect);

	gv->setContextMenuPolicy(Qt::CustomContextMenu);

	QToolButton *qtbZoomIn = new QToolButton();
	qtbZoomIn->setIcon(QIcon(QPixmap(":imagenes/Zoom in.png")));
	mainToolbar->addWidget(qtbZoomIn);

	zoom = 1;
	tZoom = new QLineEdit();
	tZoom->setReadOnly(true);
	tZoom->setMaximumWidth(50);
	tZoom->setAlignment(Qt::AlignCenter);
	tZoom->setText("100%");
	mainToolbar->addWidget(tZoom);

	QToolButton *qtbZoomOut = new QToolButton();
	qtbZoomOut->setIcon(QIcon(QPixmap(":imagenes/Zoom out.png")));
	mainToolbar->addWidget(qtbZoomOut);

	setVisibleToolbar(true);
	layout()->addWidget(gv);

	connect(qtbZoomIn, SIGNAL(clicked()), SLOT(onZoomInClick()));
	connect(qtbZoomOut, SIGNAL(clicked()), SLOT(onZoomOutClick()));
	connect(gv, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu(QPoint)));
}

//void GraphicImageElementDetailedWindow::contextMenuEvent(QContextMenuEvent *event)
//{


////	QList<QGraphicsItem*> listItems = items(p);
////	if(areDifferentTypes(listItems)){
////		cntxMenu = new QMenu();
////		cntxMenu->addAction("Borrar", this, SLOT(deleteSelected()));
////		cntxMenu->exec(mapToGlobal(p));
////		delete cntxMenu;
////	}else if(!listItems.empty()){
////		cntxMenu = dynamic_cast<GraphicElement*>(itemAt(p))->getContextMenu(new QMenu());
////		cntxMenu->exec(mapToGlobal(p));
////		delete cntxMenu;
//	//	}
//}

void GraphicImageElementDetailedWindow::contextMenu(QPoint pos)
{
	QMenu *cntxMenu = new QMenu();

	cntxMenu->addAction("Guardar...", this, SLOT(saveImage()));
	cntxMenu->exec(gv->mapToGlobal(pos));
	delete cntxMenu;
}

void GraphicImageElementDetailedWindow::saveImage()
{
	QString path = QFileDialog::getSaveFileName(0, "Guardar imagen", ".", "Portable Network Graphics (*.png);; Bitmap File (*.bmp);; JPEG File(*.jpg)");
//	QGraphicsPixmapItem *pmItm = itm;
	itm->pixmap().save(path, "", 100);
}

void GraphicImageElementDetailedWindow::onZoomInClick()
{
	if(zoom + 0.1 <= 10){
		gv->scale(1.1, 1.1);
		zoom += 0.1;
		tZoom->setText(QString::number(zoom*100) + "%");
	}
}

void GraphicImageElementDetailedWindow::onZoomOutClick()
{
	if(zoom - 0.1 > 0){
		gv->scale(0.9, 0.9);
		zoom -= 0.1;
		tZoom->setText(QString::number(zoom*100) + "%");
	}
}
