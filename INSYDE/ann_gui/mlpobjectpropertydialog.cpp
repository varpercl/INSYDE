#include "mlpobjectpropertydialog.h"
#include "ui_graphicmlpelementpropertydialog.h"

ann_gui::MLPObjectPropertyDialog::MLPObjectPropertyDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::GraphicMLPElementPropertyDialog)
{
	ui->setupUi(this);
}

ann_gui::MLPObjectPropertyDialog::~MLPObjectPropertyDialog()
{
	delete ui;
}
