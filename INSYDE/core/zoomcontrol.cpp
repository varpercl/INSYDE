#include "zoomcontrol.h"
#include "definitions.h"

ZoomControl::ZoomControl(QWidget *parent) :
	QToolBar(parent)
{
	init();
}

ZoomControl::~ZoomControl()
{
	delete btnZoomIn;
	delete btnZoomOut;
	delete sbZoom;
}

void ZoomControl::setMinZoom(int min)
{
	sbZoom->setMinimum(min);
}

int ZoomControl::getMinZoom() const
{
	return sbZoom->minimum();
}

void ZoomControl::setMaxZoom(int max)
{
	sbZoom->setMaximum(max);
}

int ZoomControl::getMaxZoom() const
{
	return sbZoom->maximum();
}

void ZoomControl::setZoomRange(int min, int max)
{
	sbZoom->setRange(min, max);
}

void ZoomControl::setZoom(int percentaje)
{
	if(sbZoom->value() != percentaje){
		sbZoom->setValue(percentaje);

		emit zoomChanged(percentaje);
	}
}

int ZoomControl::getZoom() const
{
	return sbZoom->value();
}

void ZoomControl::onEditZoomChanged(int val)
{
	emit zoomChanged(val);
}

void ZoomControl::init()
{
	Q_INIT_RESOURCE(core_media);

	layout()->setMargin(0);

	btnZoomIn = new QToolButton();
	btnZoomIn->setIcon(ICON_ZOOMIN);

	btnZoomOut = new QToolButton();
	btnZoomOut->setIcon(ICON_ZOOMOUT);

	sbZoom = new QSpinBox();
	sbZoom->setAlignment(Qt::AlignCenter);
	sbZoom->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
	sbZoom->setKeyboardTracking(true);
	sbZoom->setRange(10, 1000);
	sbZoom->setSingleStep(10);
	sbZoom->setButtonSymbols(QSpinBox::NoButtons);
	sbZoom->setSuffix("%");
	sbZoom->setValue(100);
	sbZoom->setAccelerated(true);

	addWidget(btnZoomIn);
	addWidget(sbZoom);
	addWidget(btnZoomOut);

	connect(sbZoom, SIGNAL(valueChanged(int)), SLOT(onEditZoomChanged(int)));
	connect(btnZoomIn, SIGNAL(pressed()), sbZoom, SLOT(stepUp()));
	connect(btnZoomOut, SIGNAL(pressed()), sbZoom, SLOT(stepDown()));
}

