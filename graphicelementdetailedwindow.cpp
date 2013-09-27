#include "graphicelementdetailedwindow.h"
#include "ui_graphicelementdetailedwindow.h"

GraphicElementDetailedWindow::GraphicElementDetailedWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::GraphicElementDetailedWindow)
{
	ui->setupUi(this);
	initWindow();
}

GraphicElementDetailedWindow::~GraphicElementDetailedWindow()
{
	delete ui;
}

void GraphicElementDetailedWindow::setToolbar(QToolBar *tb)
{
	mainToolbar = tb;
}

QToolBar *GraphicElementDetailedWindow::getToolbar()
{
	return mainToolbar;
}

void GraphicElementDetailedWindow::setVisibleToolbar(bool vtb)
{
	mainToolbar->setVisible(vtb);
}

void GraphicElementDetailedWindow::initWindow()
{
	mainToolbar = new QToolBar(/*this*/);
	mainToolbar->setObjectName(QString::fromUtf8("mainToolbar"));
//	mainToolbar->setWindowSurface();
//	mainToolbar->setShown(true);
//	mainToolbar->setMovable(true);
	mainToolbar->setFloatable(true);
	setVisibleToolbar(false);

	layout()->addWidget(mainToolbar); /*addToolBar(Qt::TopToolBarArea, mainToolbar);*/
}
