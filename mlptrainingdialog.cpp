#include "mlptrainingdialog.h"
#include "ui_mlptrainingdialog.h"

MLPTrainingDialog::MLPTrainingDialog(MultilayerPerceptron *mlp, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::MLPTrainingDialog)
{
	ui->setupUi(this);
	initDialog(mlp);
}

MLPTrainingDialog::~MLPTrainingDialog()
{
	delete ui;
	delete tsMLP;
}

void MLPTrainingDialog::on_btnEditTrainingSet_clicked()
{
	tsMLP = new TrainingSetDialog(mlp->getInputSize(), mlp->getOutputSize());

	if(tsMLP->exec() == QDialog::Accepted){
		targets = tsMLP->getTargets();
		inputs = tsMLP->getInputs();
	}
}

void MLPTrainingDialog::on_cbTrainingAlgorithm_currentIndexChanged(int index)
{

}

void MLPTrainingDialog::on_cbTrasnferFunction_currentIndexChanged(int index)
{
	switch(index){
		case 0:
			mlp->setTransferFunctionType(MultilayerPerceptron::Sigmoid);
			break;
		case 1:
			mlp->setTransferFunctionType(MultilayerPerceptron::Tanh);
			break;
	}
}

void MLPTrainingDialog::initDialog(MultilayerPerceptron *mlp)
{
	this->mlp = mlp;
	ui->lblInputs->setText(QString::number(mlp->getInputSize()));
	ui->lblOutputs->setText(QString::number(mlp->getOutputSize()));

	ui->buttonsLayout->setAlignment(ui->buttonsLayout, Qt::AlignBottom);

	QStringList headers;
	headers.append("Capa");
	headers.append("Elementos");
	ui->tblLayers->setHorizontalHeaderLabels(headers);

//	ui->tblLayers->setRowCount(ui->tblLayers->rowCount() + 1);
	for(size_t i = 0; i < mlp->getLayerSizes().size(); i++){
		ui->tblLayers->setRowCount(ui->tblLayers->rowCount() + 1);
		ui->tblLayers->setItem(i, 0, new QTableWidgetItem(QString::number(i+1)));
		ui->tblLayers->setItem(i, 1, new QTableWidgetItem(QString::number(mlp->getLayerSize(i))));
	}
}

void MLPTrainingDialog::on_btnTrain_clicked()
{
	MultilayerPerceptron::TrainingResult tr = mlp->train(inputs, targets, ui->sbEpochs->value(), ui->sbMinError->value(), ui->sbLearningRate->value());
	ui->lblEpochs->setText(QString::number(tr.epochs));
	ui->lblMinError->setText(QString::number(tr.MSE));
	ui->lblTime->setText(QString::number(tr.time));
}

void MLPTrainingDialog::on_btnCancel_clicked()
{
	close();
}

void MLPTrainingDialog::on_btnRandomize_clicked()
{
	mlp->randomizeWeights();
}
