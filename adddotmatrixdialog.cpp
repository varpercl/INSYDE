#include "adddotmatrixdialog.h"
#include "ui_adddotmatrixdialog.h"

AddDotMatrixDialog::AddDotMatrixDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::AddDotMatrixDialog)
{
	ui->setupUi(this);
}

AddDotMatrixDialog::~AddDotMatrixDialog()
{
	delete ui;
}

int AddDotMatrixDialog::getRowSize()
{
	return ui->sbRowSize->value();
}

int AddDotMatrixDialog::getColSize()
{
	return ui->sbColSize->value();
}

DotMatrix::DataType AddDotMatrixDialog::getDataType()
{
	switch(ui->cbDataType->currentIndex()){
		case 1:
			return DotMatrix::Bipolar;
		case 0:
		default:
			return DotMatrix::Unipolar;
	}
}
