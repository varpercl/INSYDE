#include "mlpobjectpropertydialog.h"
#include "ui_graphicmlpelementpropertydialog.h"

namespace ann_gui{

MLPObjectPropertyDialog::MLPObjectPropertyDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::GraphicMLPElementPropertyDialog)
{
    Q_INIT_RESOURCE(ann_gui_media);

	ui->setupUi(this);
}

MLPObjectPropertyDialog::~MLPObjectPropertyDialog()
{
	delete ui;
}

}
