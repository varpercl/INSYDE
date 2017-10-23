#include "dotmatrixrepresentation.h"

core::DotMatrixRepresentation::DotMatrixRepresentation(const vector<double> &inputs, QWidget *parent) :
	DataRepresentationWidget(inputs, parent)
{
//    Q_INIT_RESOURCE(core_media);
	init();
}

core::DotMatrixRepresentation::~DotMatrixRepresentation()
{
	//	delete isw;
}

void core::DotMatrixRepresentation::setInputs(const vector<double> &inputs)
{
	dmWidget->getDotMatrixObject()->setInputs(inputs);
}

vector<double> core::DotMatrixRepresentation::getInputs() const
{
	//TODO: corregir esto
//	return dmWidget->getDotMatrix()->getInputs();

	return vector<double>();
}

void core::DotMatrixRepresentation::setSize(const QSize &size)
{
	if(isw->getSize() != size){
		isw->blockSignals(true);
		isw->setSize(size);
		isw->blockSignals(false);

		dmWidget->getDotMatrixObject()->setMatrixSize(size);

		update();
		emit sizeChanged(size);
		emit widthChanged(size.width());
		emit heightChanged(size.height());
	}
}

QSize core::DotMatrixRepresentation::getSize() const
{
	return isw->getSize();
}

void core::DotMatrixRepresentation::setWidth(int w)
{
	if(isw->getWidth() != w){
		isw->blockSignals(true);
		isw->setWidth(w);
		isw->blockSignals(false);

		dmWidget->getDotMatrixObject()->setMatrixSize(QSize(w, isw->height()));
		emit sizeChanged(QSize(w, isw->height()));
		emit widthChanged(w);
	}
}

int core::DotMatrixRepresentation::getWidth() const
{
	return isw->getWidth();
}

void core::DotMatrixRepresentation::setHeight(int h)
{
	if(isw->getHeight() != h){
		isw->blockSignals(true);
		isw->setHeight(h);
		isw->blockSignals(false);

		dmWidget->getDotMatrixObject()->setMatrixSize(QSize(isw->getWidth(), h));
		emit sizeChanged(QSize(isw->width(), h));
		emit heightChanged(h);
	}
}

int core::DotMatrixRepresentation::getHeight() const
{
	return isw->getHeight();
}

void core::DotMatrixRepresentation::setDotMatrixObject(core::DotMatrix *obj)
{
	dmWidget->setDotMatrixObject(obj);
}

core::DotMatrix *core::DotMatrixRepresentation::getDotMatrixObject() const
{
	return dmWidget->getDotMatrixObject();
}

void core::DotMatrixRepresentation::init()
{
	dmWidget = new DotMatrixDetailedWindow(getInputs());
	DotMatrix *dm = dmWidget->getDotMatrixObject();
	dm->setEnableEdit(false);
	dmWidget->setEnableZooming(true);

	isw = new IntegerSizeWidget(dm->getMatrixSize());
	isw->setMinimumSizeValues(0, 0);

	gbPropLayout = new QVBoxLayout();
	gbPropLayout->addWidget(isw);

	gbProperties = new QGroupBox(tr("Properties"));
	gbProperties->setLayout(gbPropLayout);

	layout()->addWidget(gbProperties);
	layout()->addWidget(dmWidget);

	connect(isw, &IntegerSizeWidget::sizeChanged,[=](const QSize &s) {

		dmWidget->getDotMatrixObject()->setMatrixSize(s);
	});
}

