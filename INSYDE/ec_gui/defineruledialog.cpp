#include "defineruledialog.h"
#include "ui_defineruledialog.h"

ec_gui::DefineRuleDialog::DefineRuleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DefineRuleDialog)
{
    ui->setupUi(this);
}

ec_gui::DefineRuleDialog::~DefineRuleDialog()
{
    delete ui;
}
