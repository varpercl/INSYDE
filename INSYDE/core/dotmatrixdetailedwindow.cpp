#include "dotmatrixdetailedwindow.h"

DotMatrixDetailedWindow::DotMatrixDetailedWindow(const vector<double> &data, QWidget *parent) :
	DetailedWindow(parent)
{
	init(data);
}

DotMatrixDetailedWindow::DotMatrixDetailedWindow(DotMatrix *dm, QWidget *parent) :
	DetailedWindow(parent)
{
	init(dm);
}

DotMatrixDetailedWindow::~DotMatrixDetailedWindow()
{

}

void DotMatrixDetailedWindow::setDotMatrixObject(DotMatrix *dm)
{
	if(this->dm != dm){
		this->dm = dm;
	}
}

DotMatrix *DotMatrixDetailedWindow::getDotMatrixObject() const
{
	return dm;
}

void DotMatrixDetailedWindow::setSize(const QSizeF &size)
{
	dm->setSize(size);
	getGraphicsDetailedView()->setSceneRect(dm->boundingRect());
}

QSizeF DotMatrixDetailedWindow::getSize() const
{
	return dm->getSize();
}

void DotMatrixDetailedWindow::setWidth(double w)
{
	dm->setCols(w);
	getGraphicsDetailedView()->setSceneRect(dm->boundingRect());
}

double DotMatrixDetailedWindow::getWidth() const
{
	return dm->getCols();
}

void DotMatrixDetailedWindow::setHeight(double h)
{
	dm->setRows(h);
	getGraphicsDetailedView()->setSceneRect(dm->boundingRect());
}

double DotMatrixDetailedWindow::getHeight() const
{
	return dm->getRows();
}

void DotMatrixDetailedWindow::setEnableEdit(bool edit)
{
	dm->setEnableEdit(edit);
}

bool DotMatrixDetailedWindow::getEnableEdit() const
{
	return dm->getEnableEdit();
}

void DotMatrixDetailedWindow::save()
{

}

void DotMatrixDetailedWindow::init(const vector<double> &data)
{
	pair<int, int> wh = common::getWidthHeight((int)data.size());

	dm = new DotMatrix(3, wh.first, wh.second);

	dm->setInputs(data);

	setupUI();
}

void DotMatrixDetailedWindow::init(DotMatrix *dm)
{
	this->dm = dm;

	setupUI();
}

void DotMatrixDetailedWindow::setupUI()
{
	dm->setObjectLocked(true);
	dm->getLockAction()->setVisible(false);
//	dm->getPropertiesAction()->setEnabled(false);
	dm->getOpenAction()->setVisible(false);
	dm->getRemoveAction()->setVisible(false);

	getGraphicsDetailedView()->scene()->addItem(dm);
}

