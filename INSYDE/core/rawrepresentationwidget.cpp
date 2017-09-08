#include "rawrepresentationwidget.h"

core::RawRepresentationWidget::RawRepresentationWidget(const vector<double> &data, QWidget *parent):
	DataRepresentationWidget(data, parent)
{

//    Q_INIT_RESOURCE(core_media);
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

