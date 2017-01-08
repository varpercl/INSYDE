#include "datarepresentationwidget.h"

core::DataRepresentationWidget::DataRepresentationWidget(const vector<double> &datainput, QWidget *parent) :
	QWidget(parent)
{
	init(datainput);
}

void core::DataRepresentationWidget::setInputs(const vector<double> &datainput)
{
	inputs = datainput;
}

vector<double> core::DataRepresentationWidget::getInputs() const
{
	return inputs;
}

void core::DataRepresentationWidget::init(const vector<double> &dataInput)
{
	setInputs(dataInput);

	mainLayout = new QVBoxLayout();
	mainLayout->setMargin(0);

	setLayout(mainLayout);
}
