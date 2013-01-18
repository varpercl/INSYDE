#include "addagentsdialog.h"

AddAgentsDialog::AddAgentsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAgentsDialog)
{
    ui->setupUi(this);
//    this->setFixedSize(400, 245);
    ui->cmbAgentType->setCurrentIndex(1);
//    on_cmbAgentType_currentIndexChanged(ui->cmbAgentType->currentIndex());
}

AddAgentsDialog::~AddAgentsDialog()
{
    delete ui;
}

//void AddAgentsDialog::closeEvent(QCloseEvent *event)
// {
//     QSettings settings("VARPER Tech", "JuegoEstrategia");
//     settings.setValue("geometry", saveGeometry());
////     settings.setValue("windowState", );
//     QMainWindow::closeEvent(event);
// }

void AddAgentsDialog::on_cmbAgentType_currentIndexChanged(int index)
{
    switch(index){
        case 0:
            ui->gbShootingUnit->setEnabled(false);
            break;
        case 1:
            ui->gbShootingUnit->setEnabled(true);
            break;
    }
}
