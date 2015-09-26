#include "dotmatrixrepresentation.h"

DotMatrixRepresentation::DotMatrixRepresentation(const vector<double> &inputs, QWidget *parent) :
	DataRepresentationWidget(inputs, parent)
{
	init();
}

DotMatrixRepresentation::~DotMatrixRepresentation()
{
	//	delete isw;
}

void DotMatrixRepresentation::setInputs(const vector<double> &inputs)
{
	dmWidget->getDotMatrixObject()->setInputs(inputs);
}

vector<double> DotMatrixRepresentation::getInputs() const
{
	//TODO: corregir esto
//	return dmWidget->getDotMatrix()->getInputs();

	return vector<double>();
}

void DotMatrixRepresentation::setSize(const QSize &size)
{
	if(isw->getSize() != size){
		isw->blockSignals(true);
		isw->setSize(size);
		isw->blockSignals(false);

		dmWidget->setSize(size);

		update();
		emit sizeChanged(size);
		emit widthChanged(size.width());
		emit heightChanged(size.height());
	}
}

QSize DotMatrixRepresentation::getSize() const
{
	return isw->getSize();
}

void DotMatrixRepresentation::setWidth(int w)
{
	if(isw->getWidth() != w){
		isw->blockSignals(true);
		isw->setWidth(w);
		isw->blockSignals(false);

		dmWidget->setWidth(w);
		emit sizeChanged(QSize(w, isw->height()));
		emit widthChanged(w);
	}
}

int DotMatrixRepresentation::getWidth() const
{
	return isw->getWidth();
}

void DotMatrixRepresentation::setHeight(int h)
{
	if(isw->getHeight() != h){
		isw->blockSignals(true);
		isw->setHeight(h);
		isw->blockSignals(false);

		dmWidget->setHeight(h);
		emit sizeChanged(QSize(isw->width(), h));
		emit heightChanged(h);
	}
}

int DotMatrixRepresentation::getHeight() const
{
	return isw->getHeight();
}

void DotMatrixRepresentation::setDotMatrixObject(DotMatrix *obj)
{
	dmWidget->setDotMatrixObject(obj);
}

DotMatrix *DotMatrixRepresentation::getDotMatrixObject() const
{
	return dmWidget->getDotMatrixObject();
}

void DotMatrixRepresentation::onWidgetSizeChanged(const QSize &s)
{
	dmWidget->setSize(s);
}

void DotMatrixRepresentation::init()
{
	dmWidget = new DotMatrixDetailedWindow(getInputs());
	DotMatrix *dm = dmWidget->getDotMatrixObject();
	dm->setEnableEdit(false);
	dmWidget->setEnableZooming(true);

	isw = new IntegerSizeWidget(dm->getSize());

	gbPropLayout = new QVBoxLayout();
	gbPropLayout->addWidget(isw);

	gbProperties = new QGroupBox("Propiedades");
	gbProperties->setLayout(gbPropLayout);

	layout()->addWidget(gbProperties);
	layout()->addWidget(dmWidget);

	connect(isw, SIGNAL(sizeChanged(QSize)), SLOT(onWidgetSizeChanged(QSize)));
}

