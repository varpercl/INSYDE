#include "mlpobjectpropertydialog.h"
#include "ui_graphicmlpelementpropertydialog.h"

MLPObjectPropertyDialog::MLPObjectPropertyDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::GraphicMLPElementPropertyDialog)
{
	ui->setupUi(this);
}

MLPObjectPropertyDialog::~MLPObjectPropertyDialog()
{
	delete ui;
}
