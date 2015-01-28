#include "datarepresentationbox.h"
#include "ui_gbgraphicrepresentation.h"

DataRepresentationBox::DataRepresentationBox(const vector<double> &inputdata, QWidget *parent) :
	QGroupBox(parent),
	ui(new Ui::gbGraphicRepresentation)
{
	initGR(inputdata);
}//GraphicRepresentation

DataRepresentationBox::~DataRepresentationBox()
{
	delete ui;
}//~GraphicRepresentation

void DataRepresentationBox::setDataInput(const vector<double> &inputs)
{
	this->inputs = inputs;
	irw->setDataInput(inputs);
}//setInputs

vector<double> DataRepresentationBox::getDataInput() const
{
	return inputs;
}//getDataInput

RepresentationWidget *DataRepresentationBox::getRepresentationWidget() const
{
	return irw;
}

void DataRepresentationBox::initGR(const vector<double> &inputdata)
{
	ui->setupUi(this);

	irw = new ImageRepresentationWidget(getDataInput());
	ui->verticalLayout->addWidget(irw);

	setDataInput(inputdata);
}//initGR

