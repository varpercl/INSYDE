#include "graphicmlpelementpropertydialog.h"
#include "ui_graphicmlpelementpropertydialog.h"

GraphicMLPElementPropertyDialog::GraphicMLPElementPropertyDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::GraphicMLPElementPropertyDialog)
{
	ui->setupUi(this);
}

GraphicMLPElementPropertyDialog::~GraphicMLPElementPropertyDialog()
{
	delete ui;
}
