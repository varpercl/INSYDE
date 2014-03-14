#include "defineruledialog.h"
#include "ui_defineruledialog.h"

DefineRuleDialog::DefineRuleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DefineRuleDialog)
{
    ui->setupUi(this);
}

DefineRuleDialog::~DefineRuleDialog()
{
    delete ui;
}
