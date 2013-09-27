#include "dotmatrixelementpropertydialog.h"
#include "ui_dotmatrixelementpropertydialog.h"

DotMatrixElementPropertyDialog::DotMatrixElementPropertyDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DotMatrixElementPropertyDialog)
{
	ui->setupUi(this);
}

DotMatrixElementPropertyDialog::~DotMatrixElementPropertyDialog()
{
	delete ui;
}
