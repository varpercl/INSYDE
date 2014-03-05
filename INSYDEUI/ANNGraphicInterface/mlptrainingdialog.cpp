#include "mlptrainingdialog.h"
#include "ui_mlptrainingdialog.h"

//MLPTrainingDialog::MLPTrainingDialog(MultilayerPerceptron *mlp, QWidget *parent) :
//	QDialog(parent),
//	ui(new Ui::MLPTrainingDialog)
//{
//	ui->setupUi(this);
//	initDialog(mlp);
//}

MLPTrainingDialog::MLPTrainingDialog(MultilayerPerceptron *mlp, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::MLPTrainingDialog)
{
	initDialog(mlp);
}

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
	delete tres;
}

void MLPTrainingDialog::closeEvent(QCloseEvent *)
{
	mlp->stopTraining();
}

void MLPTrainingDialog::trainingFinished(MLPTrainingResult *tres)
{
	ui->btnTrain->setText("Entrenar");
	timer.stop();
	updateStatusLabels();
	isTraining = false;
	if(tres->epochs > 0){
		saveFile->setEnabled(true);
	}
	setBPEnabledControls(true);
	setSAEnabledControls(true);
	activateWindow();
	raise();
}

void MLPTrainingDialog::multipleTrainingResult(MLPTrainingResult *tres)
{
	QString wnefp = multipleReportPath;
	wnefp.truncate(multipleReportPath.lastIndexOf('.'));

	QString ext =  multipleReportPath;
	ext = ext.mid(ext.lastIndexOf('.'));

	while(QFile::exists(wnefp + QString::number(fileIndex) + ext)){
		fileIndex++;
	}
	createFile(wnefp + QString::number(fileIndex) + ext, tres, tres->MSEHistory.size());
}

void MLPTrainingDialog::on_btnEditTrainingSet_clicked()
{
	tsMLP = new TrainingSetDialog(gmlp->getTrainingSet());

	if(tsMLP->exec() == QDialog::Accepted){
		//		int sPatterns = tsMLP->getPatternCount();
		//		vector<MultilayerPerceptronPattern*> ts(sPatterns);
		//		for(int i = 0; i < sPatterns; i++){
		//			vector<vector<double> > in = tsMLP->getInputs();
		//			vector<vector<double> > out = tsMLP->getTargets();
		//			ts[i] = new MultilayerPerceptronPattern(in[i], out[i]);
		//		}

		gmlp->setTrainingSet(tsMLP->getTrainingSetTable()->getTrainingSet());
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
//	tsMLP = new TrainingSetDialog(gmlp->getTrainingSet(), this);
	tres = new MLPTrainingResult;
	//Instalacion de un menu principal
	QMenu *file = new QMenu(tr("Archivo"));
	saveFile = file->addAction("Exportar datos...", this, SLOT(exportData())),
			saveFile->setShortcut(QKeySequence::Save);
	saveFile->setEnabled(false);

	//	QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+S"), this);

	menuBar = new QMenuBar(this);
	menuBar->addMenu(file);
	layout()->setMenuBar(menuBar);


	tres->epochs = 0;
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

	//Inicializa la tabla de las capas
	for(size_t i = 0; i < mlp->getLayerSizes().size(); i++){
		ui->tblLayers->setRowCount(ui->tblLayers->rowCount() + 1);
		QTableWidgetItem *layerNumberCell = new QTableWidgetItem(QString::number(i+1));
		layerNumberCell->setFlags(Qt::NoItemFlags);
		layerNumberCell->setTextAlignment(Qt::AlignHCenter);
		ui->tblLayers->setItem(i, 0, layerNumberCell);
		QTableWidgetItem *nElementsCell = new QTableWidgetItem(QString::number(mlp->getLayerSize(i)));
		nElementsCell->setTextAlignment(Qt::AlignHCenter);
		ui->tblLayers->setItem(i, 1, nElementsCell);
	}

	//	mlptt = new MLPTrainingThread(mlp);

	ui->cbTrainingAlgorithm->setCurrentIndex(0);

	on_cbStopCondition_currentIndexChanged(0);
	on_btnRandomize_clicked();
	on_chkSA_toggled(false);

	connect(&timer, SIGNAL(timeout()), SLOT(updateStatusLabels()));
	connect(mlp, SIGNAL(trainingFinished(MLPTrainingResult*)), SLOT(trainingFinished(MLPTrainingResult*)));
	connect(ui->tblLayers, SIGNAL(cellChanged(int,int)), SLOT(onTblLayersCellChanged(int,int)));
}

void MLPTrainingDialog::initDialog(MultilayerPerceptron *mlp)
{
	ui->setupUi(this);
//	tsMLP = new TrainingSetDialog(gmlp->getTrainingSet(), this);
	tres = new MLPTrainingResult;
	//Instalacion de un menu principal
	QMenu *file = new QMenu(tr("Archivo"));
	saveFile = file->addAction("Exportar datos...", this, SLOT(exportData())),
			saveFile->setShortcut(QKeySequence::Save);
	saveFile->setEnabled(false);

	//	QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+S"), this);

	menuBar = new QMenuBar(this);
	menuBar->addMenu(file);
	layout()->setMenuBar(menuBar);


	tres->epochs = 0;
	ta = MultilayerPerceptron::Backpropagation;
//	this->gmlp = gmlp;
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

	//Inicializa la tabla de las capas
	for(size_t i = 0; i < mlp->getLayerSizes().size(); i++){
		ui->tblLayers->setRowCount(ui->tblLayers->rowCount() + 1);
		QTableWidgetItem *layerNumberCell = new QTableWidgetItem(QString::number(i+1));
		layerNumberCell->setFlags(Qt::NoItemFlags);
		layerNumberCell->setTextAlignment(Qt::AlignHCenter);
		ui->tblLayers->setItem(i, 0, layerNumberCell);
		QTableWidgetItem *nElementsCell = new QTableWidgetItem(QString::number(mlp->getLayerSize(i)));
		nElementsCell->setTextAlignment(Qt::AlignHCenter);
		ui->tblLayers->setItem(i, 1, nElementsCell);
	}

	//	mlptt = new MLPTrainingThread(mlp);

	ui->cbTrainingAlgorithm->setCurrentIndex(0);

	on_cbStopCondition_currentIndexChanged(0);
	on_btnRandomize_clicked();
	on_chkSA_toggled(false);

	connect(&timer, SIGNAL(timeout()), SLOT(updateStatusLabels()));
	connect(mlp, SIGNAL(trainingFinished(MLPTrainingResult*)), SLOT(trainingFinished(MLPTrainingResult*)));
	connect(ui->tblLayers, SIGNAL(cellChanged(int,int)), SLOT(onTblLayersCellChanged(int,int)));
}

void MLPTrainingDialog::on_btnTrain_clicked()
{
	if(isTraining){
		ui->btnTrain->setText("Entrenar");
		timer.stop();
		mlp->stopTraining();

		setBPEnabledControls(true);

		if(ui->chkSA->isChecked()){
			setSAEnabledControls(true);
		}
	}else{
		disableAllControls();

		ui->btnTrain->setText("Detener");
		TrainingSet *ts = gmlp->getTrainingSet();
		//		mlptt->setTrainingSettings(ts,
		//								   ui->sbEpochs->value(),
		//								   ui->sbMinError->value(),
		//								   ui->sbLearningRate->value(),
		//								   ta);

		MLPBackpropagationTrainingSettings *bp = new MLPBackpropagationTrainingSettings(
													ui->sbEpochs->value(),
													(MultilayerPerceptron::StopCondition)ui->cbStopCondition->currentIndex(),
													ui->sbEMValue->value(),
													ui->sbLearningRate->value());

		MLPSimulatedAnnealingTrainingSettings *sa = new MLPSimulatedAnnealingTrainingSettings(
													   ui->sbMinTemperature->value(),
													   ui->sbNChanges->value(),
													   ui->sbStartCondition->value(),
													   ui->sbTo->value(),
													   ui->sbMinNoise->value(),
													   ui->sbMaxNoise->value(),
													   ui->sbDecFactor->value());
		//Si esta habilitado Simulated Annealing
		if(ui->chkSA->isChecked()){
			mlp->startTraining(ts, bp, sa);
		}else{
			mlp->startTraining(ts, bp);
		}

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
	mlp->randomizeWeights(ui->sbRndFrom->value(), ui->sbRndTo->value());
}

void MLPTrainingDialog::updateStatusLabels(){
	tres = mlp->getTrainingSnapshot();
	ui->lblEpochs->setText(QString::number(tres->epochs));
	ui->lblMinError->setText(QString::number(tres->MSE));
	ui->lblRMSE->setText(QString::number(tres->RMSE));
	ui->lblTime->setText(QTime(0,0,0).addMSecs(t.elapsed()).toString("hh:mm:ss.zzz"));
}

void MLPTrainingDialog::onTblLayersCellChanged(int row, int column)
{
	vector<int> ls = mlp->getLayerSizes();
	ls[row] = ui->tblLayers->item(row,column)->text().toInt();
	mlp->setLayerSizes(ls);
}

void MLPTrainingDialog::createFile(QString path, MLPTrainingResult *tr, int nsamples){
	QFile *f = new QFile(path);
	if (f->open(QFile::ReadWrite)) { // file opened successfully
		f->write("", qstrlen(""));
		QTextStream t( f ); // use a text stream
		QString s("");
		const QString sep = "\t";
		//		int sWeights;
		int inc = tr->epochs / nsamples < 1 ? 1 : tr->epochs / nsamples;
		for(unsigned int i = 0; i <= tr->epochs; i += inc){
			s += QString::number(i) + sep + QString::number(tr->MSEHistory[i]) + "\n\r";
		}
		t << s;
		f->close();
	}else if(path != ""){
		QString msg;
		switch(f->error()){
			case QFile::OpenError:
				msg = "No se pudo guardar el archivo.\nPosiblemente el archivo esta abierto o no existe.";
				break;
			case QFile::NoError:
			case QFile::ReadError:
			case QFile::WriteError:
			case QFile::FatalError:
			case QFile::ResourceError:
			case QFile::AbortError:
			case QFile::TimeOutError:
			case QFile::UnspecifiedError:
			case QFile::RemoveError:
			case QFile::RenameError:
			case QFile::PositionError:
			case QFile::ResizeError:
			case QFile::PermissionsError:
			case QFile::CopyError:
				msg = "Ocurrio un error inesperado al intentar guardar el archivo.\nPor favor intentelo de nuevo.";
				break;
		}
		QMessageBox::critical(this, "Error", msg);
	}
	delete f;
}

void MLPTrainingDialog::disableAllControls()
{
	ui->chkSA->setEnabled(false);
	ui->cbStopCondition->setEnabled(false);
	ui->cbTrainingAlgorithm->setEnabled(false);
	ui->cbTrasnferFunction->setEnabled(false);

	ui->tblLayers->setEnabled(false);

	ui->btnAddLayer->setEnabled(false);
	ui->btnDeleteLayer->setEnabled(false);
	ui->btnEditTestSet->setEnabled(false);
	ui->btnEditTrainingSet->setEnabled(false);
	ui->btnEditValidationTest->setEnabled(false);
	ui->btnRandomize->setEnabled(false);

	ui->sbDecFactor->setEnabled(false);
	ui->sbEpochs->setEnabled(false);
	ui->sbLearningRate->setEnabled(false);
	ui->sbMaxNoise->setEnabled(false);
	ui->sbEMValue->setEnabled(false);
//	ui->sbMinErrorClasification->setEnabled(false);
	ui->sbMinNoise->setEnabled(false);
//	ui->sbMinRMSError->setEnabled(false);
	ui->sbMinTemperature->setEnabled(false);
	ui->sbNChanges->setEnabled(false);
	ui->sbRndFrom->setEnabled(false);
	ui->sbRndTo->setEnabled(false);
	ui->sbSlope->setEnabled(false);
	ui->sbStartCondition->setEnabled(false);
	ui->sbTo->setEnabled(false);
}

void MLPTrainingDialog::setSAEnabledControls(bool enabled)
{
	ui->sbDecFactor->setEnabled(enabled);
	ui->sbMaxNoise->setEnabled(enabled);
	ui->sbMinNoise->setEnabled(enabled);
	ui->sbMinTemperature->setEnabled(enabled);
	ui->sbNChanges->setEnabled(enabled);
	ui->sbStartCondition->setEnabled(enabled);
	ui->sbTo->setEnabled(enabled);
}

void MLPTrainingDialog::setBPEnabledControls(bool enabled)
{
	ui->cbStopCondition->setEnabled(enabled);
	ui->chkSA->setEnabled(enabled);
	ui->cbTrainingAlgorithm->setEnabled(enabled);
	ui->cbTrasnferFunction->setEnabled(enabled);

	ui->tblLayers->setEnabled(enabled);

	ui->btnAddLayer->setEnabled(enabled);
	ui->btnDeleteLayer->setEnabled(enabled);
	ui->btnEditTestSet->setEnabled(enabled);
	ui->btnEditTrainingSet->setEnabled(enabled);
	ui->btnEditValidationTest->setEnabled(enabled);
	ui->btnRandomize->setEnabled(enabled);

	ui->sbEpochs->setEnabled(enabled);
	ui->sbLearningRate->setEnabled(enabled);
	if(enabled){
		on_cbStopCondition_currentIndexChanged(ui->cbStopCondition->currentIndex());
	}else{
		ui->sbEMValue->setEnabled(enabled);
//		ui->sbMinErrorClasification->setEnabled(enabled);
//		ui->sbMinRMSError->setEnabled(enabled);
	}
	ui->sbRndFrom->setEnabled(enabled);
	ui->sbRndTo->setEnabled(enabled);
	ui->sbSlope->setEnabled(enabled);
}


void MLPTrainingDialog::exportData()
{
	if(tres->epochs > 1){
		QString path = QFileDialog::getSaveFileName(
						   this,
						   "Ruta del archivo",
						   "resultado",
						   tr("Valores separados por comas (*.csv);;Archivo EXCEL (*.xls);;Archivo XML (*.xml)")
						   );
		if(path != ""){
			SamplesDialog sd(tres, this);
			if(sd.exec() == QDialog::Accepted){
				createFile(path, tres, sd.getSampleCount());
				saveFile->setEnabled(false);
				return;
			}
		}
	}else{
		QMessageBox::critical(this, "Error", "No hay ningun dato para guardar");
		//		QMessageBox msgBox;
		//		msgBox.setText("No hay ningun dato para guardar");
		//		msgBox.exec();
	}
	saveFile->setEnabled(true);
}

void MLPTrainingDialog::on_btnEditValidationTest_clicked()
{

}

void MLPTrainingDialog::on_btnEditTestSet_clicked()
{

}

void MLPTrainingDialog::on_btnAddLayer_clicked()
{
	bool ok = false;
	QString val = QString::number(QInputDialog::getInt(this,
													   "Numero de elementos",
													   "Neuronas",
													   10,
													   1,
													   999999,
													   1,
													   &ok));
	if(ok){
		ui->tblLayers->setRowCount(ui->tblLayers->rowCount() + 1);
		ui->tblLayers->setItem(ui->tblLayers->rowCount()-1, 1, new QTableWidgetItem(val));
	}
}

void MLPTrainingDialog::on_btnDeleteLayer_clicked()
{
}

void MLPTrainingDialog::on_btnMultipleTraining_clicked()
{
	bool ok = false;

	multipleReportPath = QFileDialog::getSaveFileName(
							 this,
							 "Ruta del archivo",
							 "resultado",
							 tr("Valores separados por comas (*.csv);;Archivo EXCEL (*.xls);;Archivo XML (*.xml)"),
							 0,
							 QFileDialog::ShowDirsOnly);
	if(multipleReportPath == ""){
		return;
	}

	int nSamples = QInputDialog::getInt(this,
										"Numero de entrenamientos",
										"Numero",
										1,
										1,
										1000000,
										1,
										&ok);
	fileIndex = 0;
	if(ok){
		QVector<MultilayerPerceptron*> arr(nSamples);
		TrainingSet *ts = gmlp->getTrainingSet();

		MLPBackpropagationTrainingSettings *bp = new MLPBackpropagationTrainingSettings(ui->sbEpochs->value(),
											  (MultilayerPerceptron::StopCondition)ui->cbStopCondition->currentIndex(),
											  ui->sbEMValue->value(),
//											  ui->sbMinRMSError->value(),
//											  ui->sbMinErrorClasification->value(),
											  ui->sbLearningRate->value());

		MLPSimulatedAnnealingTrainingSettings *sa = new MLPSimulatedAnnealingTrainingSettings(ui->sbMinTemperature->value(),
												 ui->sbNChanges->value(),
												 ui->sbStartCondition->value(),
												 ui->sbTo->value(),
												 ui->sbMinNoise->value(),
												 ui->sbMaxNoise->value(),
												 ui->sbDecFactor->value());

		for(int i = 0; i < nSamples; i++){
			arr[i] = new MultilayerPerceptron(mlp->getInputSize(),
											  mlp->getOutputSize(),
											  mlp->getLayerSizes(),
											  mlp->getTransferFunctionType());

			arr[i]->randomizeWeights(ui->sbRndFrom->value(), ui->sbRndTo->value());

			connect(arr[i], SIGNAL(trainingFinished(MLPTrainingResult)), SLOT(multipleTrainingResult(MLPTrainingResult)));
			//Si esta habilitado Simulated Annealing
			if(ui->chkSA->isChecked()){
				arr[i]->startTraining(ts, bp, sa);
			}else{
				arr[i]->startTraining(ts, bp);
			}
		}
	}
}

void MLPTrainingDialog::on_cbStopCondition_currentIndexChanged(int index)
{
	ui->sbEMValue->setEnabled(true);
	switch(index){
		case 0:
//			ui->sbMinRMSError->setEnabled(false);
//			ui->sbMinErrorClasification->setEnabled(false);
			ui->sbThreshold->setEnabled(false);
			break;
		case 1:
//			ui->sbMinRMSError->setEnabled(true);
//			ui->sbMinErrorClasification->setEnabled(false);
			ui->sbThreshold->setEnabled(false);
			break;
		case 2:
//			ui->sbMinRMSError->setEnabled(false);
//			ui->sbMinErrorClasification->setEnabled(true);
			ui->sbThreshold->setEnabled(true);
	}
}

void MLPTrainingDialog::on_chkSA_toggled(bool checked)
{
	setSAEnabledControls(checked);
}
