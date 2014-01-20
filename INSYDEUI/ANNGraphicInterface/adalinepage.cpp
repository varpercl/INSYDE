#include "adalinepage.h"
#include "ui_adalinepage.h"

AdalinePage::AdalinePage() :
    QWizardPage(),
    ui(new Ui::AdalinePage())
{
    ui->setupUi(this);
}

int AdalinePage::nextId() const
{
    return 0;
}
