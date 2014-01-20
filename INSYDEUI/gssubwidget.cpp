#include "gssubwidget.h"
#include "ui_gssubwidget.h"

GSSubWidget::GSSubWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::GSSubWidget)
{
	ui->setupUi(this);
}

GSSubWidget::~GSSubWidget()
{
	delete ui;
}
