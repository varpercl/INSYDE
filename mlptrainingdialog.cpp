#include "mlptrainingdialog.h"
#include "ui_mlptrainingdialog.h"

//MLPTrainingDialog::MLPTrainingDialog(MultilayerPerceptron *mlp, QWidget *parent) :
//	QDialog(parent),
//	ui(new Ui::MLPTrainingDialog)
//{
//	ui->setupUi(this);
//	initDialog(mlp);
//}

MLPTrainingDialog::MLPTrainingDialog(GraphicMLPElement *gmlp, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::MLPTrainingDialog)
{
	initDialog(gmlp);
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
	updateStatusLabels();
	isTraining = false;
}

void MLPTrainingDialog::on_btnEditTrainingSet_clicked()
{
	tsMLP = new TrainingSetDialog(gmlp->getTrainingSet());

	if(tsMLP->exec() == QDialog::Accepted){
		int sPatterns = tsMLP->getPatternCount();
		vector<MultilayerPerceptronPattern*> ts(sPatterns);
		for(int i = 0; i < sPatterns; i++){
			vector<vector<double> > in = tsMLP->getInputs();
			vector<vector<double> > out = tsMLP->getTargets();
			ts[i] = new MultilayerPerceptronPattern(in[i], out[i]);
		}
		gmlp->setTrainingSet(ts);
		//		targets = tsMLP->getTargets();
		//		inputs = tsMLP->getInputs();
	}
}

void MLPTrainingDialog::on_cbTrainingAlgorithm_currentIndexChanged(int index)
{
	switch(index){
		case 0:
			ta = MultilayerPerceptron::Backpropagation;
			break;
		case 1:
			ta = MultilayerPerceptron::SimulatedAnnealing;
			break;
		case 2:
			ta = MultilayerPerceptron::GradientDescendent;
			break;
		case 3:
			ta = MultilayerPerceptron::ScaledConjugateGradient;
			break;
	}
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

void MLPTrainingDialog::initDialog(GraphicMLPElement *gmlp)
{
	ui->setupUi(this);

	ta = MultilayerPerceptron::Backpropagation;
	this->gmlp = gmlp;
	mlp = gmlp->getMultilayerPerceptron();
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

	ui->cbTrainingAlgorithm->setCurrentIndex(1);

	connect(&timer, SIGNAL(timeout()), SLOT(updateStatusLabels()));
	connect(mlptt, SIGNAL(finished()), SLOT(trainingFinished()));
	connect(ui->tblLayers, SIGNAL(cellChanged(int,int)), SLOT(onTblLayersCellChanged(int,int)));
}

void MLPTrainingDialog::on_btnTrain_clicked()
{
	if(isTraining){
		ui->btnTrain->setText("Entrenar");
		timer.stop();
		mlp->stopTraining();
	}else{
		ui->btnTrain->setText("Detener");
		vector<MultilayerPerceptronPattern*> ts =gmlp->getTrainingSet();
		mlptt->setTrainingParameters(ts, ui->sbEpochs->value(), ui->sbMinError->value(), ui->sbLearningRate->value(), ta);
		mlp->setSAParameters(
					ui->sbMinTemperature->value(),
					ui->sbNChanges->value(),
					ui->sbStartCondition->value(),
					ui->sbInitialAcceptance->value(),
					ui->sbMinNoise->value(),
					ui->sbMaxNoise->value());

		mlptt->start(QThread::LowestPriority);
		timer.start(500);
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

void MLPTrainingDialog::onTblLayersCellChanged(int row, int column)
{
	vector<int> ls = mlp->getLayerSizes();
	ls[row] = ui->tblLayers->item(row,column)->text().toInt();
	mlp->setLayerSizes(ls);
}

