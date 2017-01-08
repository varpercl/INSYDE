#include "rawrepresentationwidget.h"

core::RawRepresentationWidget::RawRepresentationWidget(const vector<double> &data, QWidget *parent):
	DataRepresentationWidget(data, parent)
{

}

core::RawRepresentationWidget::~RawRepresentationWidget()
{

}

void core::RawRepresentationWidget::update()
{
	DataRepresentationWidget::update();
}

void core::RawRepresentationWidget::init(const vector<double> &inputs)
{
	//TODO:
	(void)inputs;
}

