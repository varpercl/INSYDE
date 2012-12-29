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

void MLPTrainingDialog::closeEvent(QCloseEvent *)
{
	mlp->stopTraining();
}

void MLPTrainingDialog::trainingFinished()
{
	ui->btnTrain->setText("Entrenar");
	timer.stop();
	isTraining = false;
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
	isTraining = false;
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

	mlptt = new MLPTrainingThread(mlp);

	connect(&timer, SIGNAL(timeout()), SLOT(updateStatusLabels()));
	connect(mlptt, SIGNAL(finished()), SLOT(trainingFinished()));
}

void MLPTrainingDialog::on_btnTrain_clicked()
{
	if(isTraining){
		ui->btnTrain->setText("Entrenar");
		timer.stop();
		mlp->stopTraining();
	}else{
		ui->btnTrain->setText("Detener");
		mlptt->setTrainingParameters(inputs, targets, ui->sbEpochs->value(), ui->sbMinError->value(), ui->sbLearningRate->value());
		mlptt->start();
		timer.start(100);
		t.start();
	}
	isTraining = !isTraining;
//	MultilayerPerceptron::TrainingResult tr = mlp->startTraining(inputs, targets, ui->sbEpochs->value(), ui->sbMinError->value(), ui->sbLearningRate->value());

}

void MLPTrainingDialog::on_btnCancel_clicked()
{
	close();
}

void MLPTrainingDialog::on_btnRandomize_clicked()
{
	mlp->randomizeWeights();
}

void MLPTrainingDialog::updateStatusLabels(){
	tres = mlp->getTrainingSnapshot();
	ui->lblEpochs->setText(QString::number(tres.epochs));
	ui->lblMinError->setText(QString::number(tres.MSE));
	ui->lblTime->setText(QTime(0,0,0).addMSecs(t.elapsed()).toString("hh:mm:ss.zzz"));
}
