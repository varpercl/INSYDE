#include "datarepresentationwidget.h"

DataRepresentationWidget::DataRepresentationWidget(const vector<double> &datainput, QWidget *parent) :
	QWidget(parent)
{
	init(datainput);
}

void DataRepresentationWidget::setInputs(const vector<double> &datainput)
{
	inputs = datainput;
}

vector<double> DataRepresentationWidget::getInputs() const
{
	return inputs;
}

void DataRepresentationWidget::init(const vector<double> &dataInput)
{
	setInputs(dataInput);

	mainLayout = new QVBoxLayout();
	mainLayout->setMargin(0);

	setLayout(mainLayout);
}
