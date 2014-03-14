#include "graphicimageelementpropertydialog.h"
#include "ui_graphicimageelementpropertydialog.h"

GraphicImageElementPropertyDialog::GraphicImageElementPropertyDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::GraphicImageElementPropertyDialog)
{
	ui->setupUi(this);
}

GraphicImageElementPropertyDialog::~GraphicImageElementPropertyDialog()
{
	delete ui;
}
