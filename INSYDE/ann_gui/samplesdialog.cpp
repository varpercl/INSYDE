#include "samplesdialog.h"
#include "ui_samplesdialog.h"

ann_gui::SamplesDialog::SamplesDialog(MLPTrainingResult *tr, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SamplesDialog)
{
//    Q_INIT_RESOURCE(ann_gui_media); //never call it inside a namespace, instead use a wrapper function

	initDialog(tr);
}

ann_gui::SamplesDialog::~SamplesDialog()
{
	delete ui;
}

int ann_gui::SamplesDialog::getSampleCount()
{
	if(ui->cbAllSamples->checkState() == Qt::Checked){
		return tres->getMSESize();
	}else{
		return ui->sbNSamples->value();
	}
}

void ann_gui::SamplesDialog::initDialog(MLPTrainingResult *tr)
{
	ui->setupUi(this);

	tres = tr;
	ui->sbNSamples->setMinimum(0);
	ui->sbNSamples->setMaximum(tr->getMSESize());
	ui->sbNSamples->setValue(tr->getMSESize());
	ui->cbAllSamples->setChecked(true);
}

void ann_gui::SamplesDialog::on_cbAllSamples_toggled(bool checked)
{
	if(checked){
		ui->sbNSamples->setEnabled(false);
		ui->label->setEnabled(false);
	}else{
		ui->sbNSamples->setEnabled(true);
		ui->label->setEnabled(true);
	}
}
