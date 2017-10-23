#include "dotmatrixdetailedwindow.h"

core::DotMatrixDetailedWindow::DotMatrixDetailedWindow(const vector<double> &data, QWidget *parent) :
	DetailedWindow(parent)
{
//    Q_INIT_RESOURCE(core_media);
	init(data);
}

core::DotMatrixDetailedWindow::DotMatrixDetailedWindow(DotMatrix *dm, QWidget *parent) :
	DetailedWindow(parent)
{
//    Q_INIT_RESOURCE(core_media);
	init(dm);
}

core::DotMatrixDetailedWindow::~DotMatrixDetailedWindow()
{

}

void core::DotMatrixDetailedWindow::setDotMatrixObject(DotMatrix *dm)
{
	if(this->dm != dm){
		this->dm = dm;
	}
}

core::DotMatrix *core::DotMatrixDetailedWindow::getDotMatrixObject() const
{
	return dm;
}

void core::DotMatrixDetailedWindow::setSize(const QSizeF &size)
{
	dm->setSize(size);
	getGraphicsDetailedView()->setSceneRect(dm->boundingRect());
}

QSizeF core::DotMatrixDetailedWindow::getSize() const
{
	return dm->getSize();
}

void core::DotMatrixDetailedWindow::setWidth(double w)
{
	dm->setCols(w);
	getGraphicsDetailedView()->setSceneRect(dm->boundingRect());
}

double core::DotMatrixDetailedWindow::getWidth() const
{
	return dm->getCols();
}

void core::DotMatrixDetailedWindow::setHeight(double h)
{
	dm->setRows(h);
	getGraphicsDetailedView()->setSceneRect(dm->boundingRect());
}

double core::DotMatrixDetailedWindow::getHeight() const
{
	return dm->getRows();
}

void core::DotMatrixDetailedWindow::setEnableEdit(bool edit)
{
	dm->setEnableEdit(edit);
}

bool core::DotMatrixDetailedWindow::getEnableEdit() const
{
	return dm->getEnableEdit();
}

void core::DotMatrixDetailedWindow::save()
{

}

void core::DotMatrixDetailedWindow::init(const vector<double> &data)
{
	pair<int, int> wh = common::getWidthHeight((int)data.size());

	dm = new DotMatrix(3, wh.first, wh.second);

	dm->setInputs(data);

	setupUI();
}

void core::DotMatrixDetailedWindow::init(DotMatrix *dm)
{
	this->dm = dm;

	setupUI();
}

void core::DotMatrixDetailedWindow::setupUI()
{
	dm->setObjectLocked(true);
//	dm->setEnableEdit(false);
	dm->getLockAction()->setVisible(false);
//	dm->getPropertiesAction()->setEnabled(false);
	dm->getOpenAction()->setVisible(false);
	dm->getRemoveAction()->setVisible(false);

	getGraphicsDetailedView()->scene()->addItem(dm);
}

