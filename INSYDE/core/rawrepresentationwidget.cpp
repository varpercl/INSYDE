#include "rawrepresentationwidget.h"

RawRepresentationWidget::RawRepresentationWidget(const vector<double> &data, QWidget *parent):
	DataRepresentationWidget(data, parent)
{

}

RawRepresentationWidget::~RawRepresentationWidget()
{

}

void RawRepresentationWidget::update()
{
	DataRepresentationWidget::update();
}

void RawRepresentationWidget::init(const vector<double> &inputs)
{
	//TODO:
	(void)inputs;
}

