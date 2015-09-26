#include "dotmatrixdetailedwindow.h"

DotMatrixDetailedWindow::DotMatrixDetailedWindow(const vector<double> &data, QWidget *parent) :
	DetailedWindow(parent)
{
	init(data);
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

void DotMatrixDetailedWindow::setSize(const QSize &size)
{
	dm->setSize(size);
	getGraphicsView()->setSceneRect(dm->boundingRect());
}

QSize DotMatrixDetailedWindow::getSize() const
{
	return dm->getSize();
}

void DotMatrixDetailedWindow::setWidth(int w)
{
	dm->setCols(w);
	getGraphicsView()->setSceneRect(dm->boundingRect());
}

int DotMatrixDetailedWindow::getWidth() const
{
	return dm->getCols();
}

void DotMatrixDetailedWindow::setHeight(int h)
{
	dm->setRows(h);
	getGraphicsView()->setSceneRect(dm->boundingRect());
}

int DotMatrixDetailedWindow::getHeight() const
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
	pair<int, int> wh = common::getWidthHeight(data.size());

	dm = new DotMatrix(3, wh.first, wh.second);
	dm->setFlag(QGraphicsItem::ItemIsMovable, false);
	dm->setInputs(data);

	getGraphicsView()->scene()->addItem(dm);
}

