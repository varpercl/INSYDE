#include "detailedwindow.h"
#include "icons.h"

DetailedWindow::DetailedWindow(QWidget *parent) :
	QWidget(parent)
{
	init();
}

DetailedWindow::~DetailedWindow()
{
	delete mainLayout;
	delete mainToolbar;
}

void DetailedWindow::connectGVSignals()
{

}

void DetailedWindow::setVisibleToolbar(bool vtb)
{
	mainToolbar->setVisible(vtb);
}

void DetailedWindow::setEnableZooming(bool zoom)
{
	if(zooming != zoom){
		if(zoom){
			mainToolbar->addAction(actionZoomControl);
		}else{
			mainToolbar->removeAction(actionZoomControl);
		}

		zooming = zoom;
	}
}

bool DetailedWindow::getEnableZooming() const
{
	return zooming;
}

void DetailedWindow::setToolbar(QToolBar *tb)
{
	mainToolbar = tb;
}

QToolBar *DetailedWindow::getToolbar()
{
	return mainToolbar;
}

void DetailedWindow::setGraphicView(QGraphicsView *gv)
{
	if(this->gv != gv){
		this->gv = gv;

		connectGVSignals();
	}
}

QGraphicsView *DetailedWindow::getGraphicsView() const
{
	return gv;
}

void DetailedWindow::onZoomChanged(int zoom)
{

	double dZoom = this->zoom;
	this->zoom = ((double)zoom) / 100;
	dZoom = this->zoom - dZoom; //obtiene el delta zoom

	//TODO: se debe corregir el problema de zooming
	getGraphicsView()->scale(1 + dZoom, 1 + dZoom);
}

void DetailedWindow::init()
{
	gv = new QGraphicsView(new QGraphicsScene());
	gv->setAlignment(Qt::AlignCenter);
	gv->setMouseTracking(true);
	gv->setContextMenuPolicy(Qt::DefaultContextMenu);
//	gv->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
//	gv->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

	mainToolbar = new QToolBar();
	mainToolbar->setLayoutDirection(Qt::RightToLeft);

	zoom = 1;
	zc = new ZoomControl();
	actionZoomControl = mainToolbar->addWidget(zc);

	mainLayout = new QVBoxLayout();
	mainLayout->setMargin(0);
	mainLayout->setAlignment(Qt::AlignTop);
	mainLayout->addWidget(mainToolbar);
	mainLayout->addWidget(gv);

	//Se debe establecer en falso para asegurarse que al llamar setEnableZooming(true) actualice los controles
	zooming = false;
	setEnableZooming(true);

	setLayout(mainLayout);

	connectGVSignals();

	connect(zc, SIGNAL(zoomChanged(int)), SLOT(onZoomChanged(int)));
}
