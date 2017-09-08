#include "bnsubwidget.h"
#include "ui_bnsubwidget.h"

core::BNSubWidget::BNSubWidget(double threshold, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::BNSubWidget)
{
//    Q_INIT_RESOURCE(core_media); //At least in linux, never call this inside user namespace, instead use a wrapper function
	ui->setupUi(this);

	init(threshold);
}

core::BNSubWidget::~BNSubWidget()
{
	delete ui;
}

void core::BNSubWidget::setThreshold(double ts)
{
	if(ts > 1){
		ts = 1;
	}else if(ts < 0){
		ts = 0;
	}
    ui->hsThreshold->setValue(ts * 100);
}

double core::BNSubWidget::getThreshold()
{
	return ui->hsThreshold->value() / 100;
}

void core::BNSubWidget::init(double threshold)
{
	setThreshold(threshold);
}
