#include "addagentsdialog.h"
#include "ui_addagentsdialog.h"

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

int AddAgentsDialog::getMaxVitality()
{
	return ui->sbMaxVitality->value();
}

int AddAgentsDialog::getInitialVitality()
{
	return ui->sbInitialVitality->value();
}

int AddAgentsDialog::getMaxEnergy()
{
	return ui->sbMaxEnergy->value();
}

int AddAgentsDialog::getInitialEnergy()
{
	return ui->sbInitialEnergy->value();
}

int AddAgentsDialog::getSpeed()
{
	return ui->sbSpeed->value();
}

int AddAgentsDialog::getVisualScope()
{
	return ui->sbVisualScope->value();
}

int AddAgentsDialog::getNumOfUnits()
{
	return ui->sbNumOfUnits->value();
}

int AddAgentsDialog::getCurrentController()
{
	return ui->cmbController->currentIndex();
}

int AddAgentsDialog::getCurrentColor()
{
	return ui->cmbColorList->currentIndex();
}

int AddAgentsDialog::getCurrentAgentType()
{
	return ui->cmbAgentType->currentIndex();
}

int AddAgentsDialog::getPowerValue()
{
	return ui->sbPowerValue->value();
}

int AddAgentsDialog::getRangeValue()
{
	return ui->sbRangeValue->value();
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
