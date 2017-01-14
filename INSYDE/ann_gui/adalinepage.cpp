#include "adalinepage.h"
#include "ui_adalinepage.h"

ann_gui::AdalinePage::AdalinePage() :
    QWizardPage(),
    ui(new Ui::AdalinePage())
{
    ui->setupUi(this);
}

int ann_gui::AdalinePage::nextId() const
{
    return 0;
}
