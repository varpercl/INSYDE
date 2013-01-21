#include "samplesdialog.h"
#include "ui_samplesdialog.h"

SamplesDialog::SamplesDialog(MLPTrainingResult tr, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SamplesDialog)
{
	initDialog(tr);
}

SamplesDialog::~SamplesDialog()
{
	delete ui;
}

int SamplesDialog::getSampleCount()
{
	if(ui->cbAllSamples->checkState() == Qt::Checked){
		return tres.MSEHistory.size();
	}else{
		return ui->sbNSamples->value();
	}
}

void SamplesDialog::initDialog(MLPTrainingResult tr)
{
	ui->setupUi(this);

	tres = tr;
	ui->sbNSamples->setMinimum(0);
	ui->sbNSamples->setMaximum(tr.MSEHistory.size());
	ui->sbNSamples->setValue(tr.MSEHistory.size());
	ui->cbAllSamples->setChecked(true);
}

void SamplesDialog::on_cbAllSamples_toggled(bool checked)
{
	if(checked){
		ui->sbNSamples->setEnabled(false);
		ui->label->setEnabled(false);
	}else{
		ui->sbNSamples->setEnabled(true);
		ui->label->setEnabled(true);
	}
}
