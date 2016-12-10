#include "detailedwindow.h"
#include "definitions.h"

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

void DetailedWindow::setGraphicDetailedView(GraphicDetailedView *gv)
{
	if(this->gdv != gv){
		this->gdv = gv;

		connectGVSignals();
	}
}

GraphicDetailedView *DetailedWindow::getGraphicsDetailedView() const
{
	return gdv;
}

void DetailedWindow::onZoomChanged(int zoom)
{
	double
			newZoom = double(zoom)/100,
			scaleFactor;

	scaleFactor = newZoom/curZoom;

	curZoom = newZoom;
	getGraphicsDetailedView()->scale(scaleFactor, scaleFactor);

}

void DetailedWindow::init()
{
	gdv = new GraphicDetailedView(new Enviroment());
	gdv->setAlignment(Qt::AlignCenter);
	gdv->setMouseTracking(true);
	gdv->setContextMenuPolicy(Qt::DefaultContextMenu);
	gdv->setCenterMarkerVisible(false);
	gdv->setGridVisible(false);


	mainToolbar = new QToolBar();
	mainToolbar->setLayoutDirection(Qt::RightToLeft);

	curZoom = 1;
	zc = new ZoomControl();
	actionZoomControl = mainToolbar->addWidget(zc);

	mainLayout = new QVBoxLayout();
	mainLayout->setMargin(0);
	mainLayout->setAlignment(Qt::AlignTop);
	mainLayout->addWidget(mainToolbar);
	mainLayout->addWidget(gdv);

	//Se debe establecer en falso para asegurarse que al llamar setEnableZooming(true) actualice los controles
	zooming = false;
	setEnableZooming(true);

	setLayout(mainLayout);

	connectGVSignals();

	connect(zc, SIGNAL(zoomChanged(int)), SLOT(onZoomChanged(int)));
}
