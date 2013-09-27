#include "bnsubwidget.h"
#include "ui_bnsubwidget.h"

BNSubWidget::BNSubWidget(double threshold, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::BNSubWidget)
{
	ui->setupUi(this);

	initBNSW(threshold);
}

BNSubWidget::~BNSubWidget()
{
	delete ui;
}

void BNSubWidget::setThreshold(double ts)
{
	if(ts > 1){
		ts = 1;
	}else if(ts < 0){
		ts = 0;
	}
	ui->hsThreshold->setValue(ts*100);
}

double BNSubWidget::getThreshold()
{
	return ui->hsThreshold->value() / 100;
}

void BNSubWidget::initBNSW(double threshold)
{
	setThreshold(threshold);
}
