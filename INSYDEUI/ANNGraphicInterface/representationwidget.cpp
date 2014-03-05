#include "representationwidget.h"

RepresentationWidget::RepresentationWidget(const vector<double> &datainput, QWidget *parent) :
	QWidget(parent)
{
	initRW(datainput);
}

void RepresentationWidget::setDataInput(const vector<double> &datainput)
{
	dataInput = datainput;
	updateRepresentation();
}//setDataInput

vector<double> RepresentationWidget::getDataInput() const
{
	return dataInput;
}//getDataInput

void RepresentationWidget::initRW(const vector<double> &dataInput)
{
	(void)dataInput;
}
