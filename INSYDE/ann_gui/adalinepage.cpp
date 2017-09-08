#include "adalinepage.h"
#include "ui_adalinepage.h"

ann_gui::AdalinePage::AdalinePage() :
    QWizardPage(),
    ui(new Ui::AdalinePage())
{
//    Q_INIT_RESOURCE(ann_gui_media); //never call it inside a namespace, instead use a wrapper function

    ui->setupUi(this);
}

int ann_gui::AdalinePage::nextId() const
{
    return 0;
}
