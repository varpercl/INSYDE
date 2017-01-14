#include "addagentsdialog.h"
#include "ui_addagentsdialog.h"

ec_gui::AddAgentsDialog::AddAgentsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAgentsDialog)
{
    ui->setupUi(this);
//    this->setFixedSize(400, 245);
    ui->cmbAgentType->setCurrentIndex(1);
//    on_cmbAgentType_currentIndexChanged(ui->cmbAgentType->currentIndex());
}

ec_gui::AddAgentsDialog::~AddAgentsDialog()
{
	delete ui;
}

int ec_gui::AddAgentsDialog::getMaxVitality()
{
	return ui->sbMaxVitality->value();
}

int ec_gui::AddAgentsDialog::getInitialVitality()
{
	return ui->sbInitialVitality->value();
}

int ec_gui::AddAgentsDialog::getMaxEnergy()
{
	return ui->sbMaxEnergy->value();
}

int ec_gui::AddAgentsDialog::getInitialEnergy()
{
	return ui->sbInitialEnergy->value();
}

int ec_gui::AddAgentsDialog::getSpeed()
{
	return ui->sbSpeed->value();
}

int ec_gui::AddAgentsDialog::getVisualScope()
{
	return ui->sbVisualScope->value();
}

int ec_gui::AddAgentsDialog::getNumOfUnits()
{
	return ui->sbNumOfUnits->value();
}

int ec_gui::AddAgentsDialog::getCurrentController()
{
	return ui->cmbController->currentIndex();
}

int ec_gui::AddAgentsDialog::getCurrentColor()
{
	return ui->cmbColorList->currentIndex();
}

int ec_gui::AddAgentsDialog::getCurrentAgentType()
{
	return ui->cmbAgentType->currentIndex();
}

int ec_gui::AddAgentsDialog::getPowerValue()
{
	return ui->sbPowerValue->value();
}

int ec_gui::AddAgentsDialog::getRangeValue()
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

void ec_gui::AddAgentsDialog::on_cmbAgentType_currentIndexChanged(int index)
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
