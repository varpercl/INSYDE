#include "detailedwindow.h"
#include "definitions.h"

core::DetailedWindow::DetailedWindow(QWidget *parent) :
	QWidget(parent)
{
	init();
}

core::DetailedWindow::~DetailedWindow()
{
	delete mainLayout;
	delete mainToolbar;
}

void core::DetailedWindow::connectGVSignals()
{

}

void core::DetailedWindow::setVisibleToolbar(bool vtb)
{
	mainToolbar->setVisible(vtb);
}

void core::DetailedWindow::setEnableZooming(bool zoom)
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

bool core::DetailedWindow::getEnableZooming() const
{
	return zooming;
}

void core::DetailedWindow::setToolbar(QToolBar *tb)
{
	mainToolbar = tb;
}

QToolBar *core::DetailedWindow::getToolbar()
{
	return mainToolbar;
}

void core::DetailedWindow::setGraphicDetailedView(GraphicDetailedView *gv)
{
	if(this->gdv != gv){
		this->gdv = gv;

		connectGVSignals();
	}
}

core::GraphicDetailedView *core::DetailedWindow::getGraphicsDetailedView() const
{
	return gdv;
}

void core::DetailedWindow::onZoomChanged(int zoom)
{
	double
			newZoom = double(zoom)/100,
			scaleFactor;

	scaleFactor = newZoom/curZoom;

	curZoom = newZoom;
	getGraphicsDetailedView()->scale(scaleFactor, scaleFactor);

}

void core::DetailedWindow::init()
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
