#include "mlptrainingdialog.h"
#include "ui_mlptrainingdialog.h"

MLPTrainingDialog::MLPTrainingDialog(MultilayerPerceptron *mlp, TrainingSet *ts, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::MLPTrainingDialog)
{
	init(mlp, ts, NULL, NULL);
}

MLPTrainingDialog::MLPTrainingDialog(GraphicMLPElement *gmlp, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::MLPTrainingDialog)
{
	init(gmlp->getMultilayerPerceptron(),
		 gmlp->getTrainingSet(),
		 gmlp->getValidationSet(),
		 gmlp->getTestSet());
}

MLPTrainingDialog::~MLPTrainingDialog()
{
	delete ui;
}

void MLPTrainingDialog::setTrainingSet(TrainingSet *ts)
{
	if(trainingSet != ts){
		trainingSet = ts;
	}
}

TrainingSet *MLPTrainingDialog::getTrainingSet() const
{
	return trainingSet;
}

void MLPTrainingDialog::setValidationSet(TrainingSet *vs)
{
	if(validationSet != vs){
		validationSet = vs;
	}
}

TrainingSet *MLPTrainingDialog::getValidationSet() const
{
	return validationSet;
}

void MLPTrainingDialog::setTestSet(TrainingSet *ts)
{
	if (testSet != ts) {
		testSet = ts;
	}
}

TrainingSet *MLPTrainingDialog::getTestSet() const
{
	return testSet;
}

void MLPTrainingDialog::setMultilayerPerceptron(MultilayerPerceptron *mlp)
{
	this->mlp = mlp;
}

MultilayerPerceptron *MLPTrainingDialog::getMultilayerPerceptron() const
{
	return mlp;
}

void MLPTrainingDialog::closeEvent(QCloseEvent *)
{
	mlp->stopTraining();
}

void MLPTrainingDialog::onTrainingFinished(MLPTrainingResult tres)
{
	ui->btnTrain->setText("Entrenar");

	updateStatusLabels(tres);
//	isTraining = false;
	if(tres.getEpochs() > 0){
		saveFile->setEnabled(true);
	}

	setBPEnabledControls(true);

	if(ui->chkSA->isChecked()){
		saWidget->setVisible(true);
	}

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
	createFile(wnefp + QString::number(fileIndex) + ext, tres, tres->getMSESize());
}

void MLPTrainingDialog::on_btnEditTrainingSet_clicked()
{
	trainingSetDialog = new TrainingSetDialog(trainingSet);

	if(trainingSetDialog->exec() == QDialog::Accepted){
		//		int sPatterns = tsMLP->getPatternCount();
		//		vector<MultilayerPerceptronPattern*> ts(sPatterns);
		//		for(int i = 0; i < sPatterns; i++){
		//			vector<vector<double> > in = tsMLP->getInputs();
		//			vector<vector<double> > out = tsMLP->getTargets();
		//			ts[i] = new MultilayerPerceptronPattern(in[i], out[i]);
		//		}

		trainingSet = trainingSetDialog->getTrainingSetTable()->getTrainingSet();
		//		gmlp->setTrainingSet(tsDialog->getTrainingSetTable()->getTrainingSet());
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

void MLPTrainingDialog::init(MultilayerPerceptron *imlp, TrainingSet *ts, TrainingSet *vs, TrainingSet *testS)
{
	const int decimals = 5;
	const int
			max = 999999,
			min = -999999;

	ui->setupUi(this);
	ui->tblLayers->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

	//Se asigna el perceptron
	setMultilayerPerceptron(imlp);
	mlp->setSaveTrainingResults(true);
	tres = mlp->getTrainingResult();

	//Instalacion de un menu principal
	QMenu *file = new QMenu(tr("Archivo"));
	saveFile = file->addAction("Exportar datos...", this, SLOT(exportData()));
	saveFile->setShortcut(QKeySequence::Save);
	saveFile->setEnabled(false);

	genReport = file->addAction("Generar reporte...", this, SLOT(generateReport()));
	genReport->setEnabled(false);

	menuBar = new QMenuBar(this);
	menuBar->addMenu(file);
	layout()->setMenuBar(menuBar);

	sbSlope = new LabeledDoubleSpinBoxWidget(1, "Pendiente");
	sbSlope->setDecimals(decimals);
	ui->horizontalLayout_2->addWidget(sbSlope);

	sbLearningRate = new LabeledDoubleSpinBoxWidget(0.5, "Taza de aprendizaje");
	sbLearningRate->setDecimals(decimals);
	//	sbLearningRate->setGeometry(0, 0, ui->formLayout->);
	ui->formLayout->insertRow(8, sbLearningRate);

	sbEpochs = new LabeledIntegerSpinBoxWidget(200000, QString::fromLatin1("Épocas"));

	sbThreshold = new LabeledDoubleSpinBoxWidget(0.5, "Umbral");
	sbThreshold->setDecimals(decimals);

	rndFrom = new LabeledDoubleSpinBoxWidget(-0.005, "desde");
	rndFrom->setMinimumValue(min);
	rndFrom->setMaximumValue(max);
	rndFrom->setDecimals(decimals);

	rndTo = new LabeledDoubleSpinBoxWidget(0.005, "hasta");
	rndTo->setMinimumValue(min);
	rndTo->setMaximumValue(max);
	rndTo->setDecimals(decimals);

	ui->horizontalLayout_5->addWidget(rndFrom);
	ui->horizontalLayout_5->addWidget(rndTo);

	ui->verticalLayout_2->insertWidget(1, sbEpochs);
	ui->verticalLayout_2->insertWidget(2, sbThreshold);
	ui->verticalLayout_2->setAlignment(Qt::AlignLeft);

	saWidget = new SimulatedAnnealingWidget(15, 100, 10, 0.2, 0.5, 0.1, 0.9, this);

	ui->saOptimization->widget()->layout()->setAlignment(Qt::AlignTop);
	ui->saOptimization->widget()->layout()->addWidget(saWidget);

	chart = new KDChart::Chart();

	plotter = new KDChart::Plotter();

	plotter->setModel(tres);

	xAxis = new KDChart::CartesianAxis(plotter);
	xAxis->setPosition(KDChart::CartesianAxis::Bottom);
	xAxis->setAlignment(Qt::AlignJustify);
	xAxis->setTitleText("Epocas");

	plotter->addAxis(xAxis);

	yAxis = new KDChart::CartesianAxis(plotter);
	yAxis->setPosition(KDChart::CartesianAxis::Left);
	yAxis->setTitleText("Error");

	plotter->addAxis(yAxis);

	//Inicia la configuracion de la leyenda
	legend = new KDChart::Legend(plotter, chart);
	legend->setPosition(KDChart::Position::North);
	legend->setAlignment(Qt::AlignCenter);
	legend->setShowLines(false);
	legend->setTitleText(tr("Leyenda"));
	legend->setOrientation(Qt::Horizontal);

	chart->addLegend(legend);
	legend->show();

//	QList<uint> hdata;
//	hdata.append(1);
//	legend->setHiddenDatasets(hdata);

	chart->coordinatePlane()->replaceDiagram(plotter);

	ui->gbPlotter->layout()->addWidget(chart);
	setWindowModality(Qt::NonModal);
	setWindowFlags(Qt::Window);

	//	QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+S"), this);

	setTrainingSet(ts);
	setValidationSet(vs);
	setTestSet(testS);

	ta = MultilayerPerceptron::Backpropagation;
	//	this->gmlp = gmlp;
//	isTraining = false;
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
	saWidget->setVisible(false);

	mlp->setEnabledElapsedTimeEvent(true);

	connect(mlp, SIGNAL(elapsedTime(MLPTrainingResult)), SLOT(updateStatusLabels(MLPTrainingResult)));
	connect(mlp, SIGNAL(trainingFinished(MLPTrainingResult)), SLOT(onTrainingFinished(MLPTrainingResult)));
	connect(ui->tblLayers, SIGNAL(cellChanged(int,int)), SLOT(onTblLayersCellChanged(int,int)));
}

void MLPTrainingDialog::createFile(QString path, MLPTrainingResult *tr, int nsamples){
	QFile *f = new QFile(path);
	if (f->open(QFile::ReadWrite)) { // file opened successfully
		f->write("", qstrlen(""));
		QTextStream t( f ); // use a text stream
		QString s("");
		const QString sep = "\t";
		//		int sWeights;
		int inc = tr->getEpochs() / nsamples < 1 ? 1 : tr->getEpochs() / nsamples;
		for(unsigned int i = 0; i <= tr->getEpochs(); i += inc){
			s += QString::number(i) + sep + QString::number(tr->getMSEHistory()[i]) + "\n\r";
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
	ui->sbEMValue->setEnabled(false);

	sbEpochs->setEnabled(false);
	sbLearningRate->setEnabled(false);
	rndFrom->setEnabled(false);
	rndTo->setEnabled(false);
	sbSlope->setEnabled(false);

	saWidget->setEnabled(false);
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

	sbEpochs->setEnabled(enabled);
	sbLearningRate->setEnabled(enabled);
	if(enabled){
		on_cbStopCondition_currentIndexChanged(ui->cbStopCondition->currentIndex());
	}else{
		ui->sbEMValue->setEnabled(enabled);
		//		ui->sbMinErrorClasification->setEnabled(enabled);
		//		ui->sbMinRMSError->setEnabled(enabled);
	}
	rndFrom->setEnabled(enabled);
	rndTo->setEnabled(enabled);
	sbSlope->setEnabled(enabled);
}

void MLPTrainingDialog::on_btnTrain_clicked()
{
	if(mlp->isTraining()){ //if perceptron status is training

		mlp->stopTraining();
		ui->btnTrain->setText("Deteniendo...");

	}else{
		disableAllControls();

		mutex.lock();
		tres->clear();
		mutex.unlock();

		ui->btnTrain->setText("Detener");

		BackpropagationSettings *bp = new BackpropagationSettings(
					sbEpochs->getValue(),
					(StopCondition)ui->cbStopCondition->currentIndex(),
					ui->sbEMValue->value(),
					sbLearningRate->getValue());

		SimulatedAnnealingSettings *sa = new SimulatedAnnealingSettings(
					saWidget->getMinTemperature(),
					saWidget->getNumberOfChanges(),
					saWidget->getStartCondition(),
					saWidget->getStartTemperature(),
					saWidget->getMinNoise(),
					saWidget->getMaxNoise(),
					saWidget->getDecTempFactor());
		//Si esta habilitado Simulated Annealing
		if(ui->chkSA->isChecked()){
			mlp->startTraining(trainingSet, bp, sa);
		}else{
			mlp->startTraining(trainingSet, bp);
		}

		t.start();
	}
}

void MLPTrainingDialog::on_btnCancel_clicked()
{
	close();
}

void MLPTrainingDialog::on_btnRandomize_clicked()
{
	mlp->randomizeWeights(rndFrom->getValue(), rndTo->getValue());
}

void MLPTrainingDialog::updateStatusLabels(const MLPTrainingResult tres){

	xAxis->setTitleText("Epocas"/*: " + QString::number(tres.getEpochs())*/);

//	legend->setText(0, "MSE: " + QString::number(tres.getMeanSquareError()));

//	legend->setText(1, "RMSE: " + QString::number(tres.getRootMeanSquareError()));

//	legend->setText(2, "CE: " + QString::number(tres.getClasificationError()));

	//FIXME: hacer correccion cuando se implemente el registro de tiempo en TrainingResult
//	ui->lblTime->setText(QTime(0,0,0).addMSecs(t.elapsed()).toString("hh:mm:ss"));
	int secs = tres.getTime();
	ui->lblTime->setText(QTime(0, 0, secs).toString("hh:mm:ss"));
}

void MLPTrainingDialog::onTblLayersCellChanged(int row, int column)
{
	if(column != 0){
		vector<int> ls = mlp->getLayerSizes();
		ls[row] = ui->tblLayers->item(row,column)->text().toInt();
		mlp->setLayerSizes(ls);
	}
}

void MLPTrainingDialog::generateReport()
{
	//TODO: implementar
}

void MLPTrainingDialog::exportData()
{
	if(tres->getEpochs() > 1){
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
	if(validationSet != NULL){
		validationSetDialog = new TrainingSetDialog(validationSet);
	}else{
		validationSetDialog = new TrainingSetDialog(validationSet = new TrainingSet(mlp->getInputSize(), mlp->getOutputSize()));
	}
	if(validationSetDialog->exec() == QDialog::Accepted){
		validationSet = validationSetDialog->getTrainingSet();
	}
	delete validationSetDialog;
}

void MLPTrainingDialog::on_btnEditTestSet_clicked()
{
	if(testSet != NULL){
		testSetDialog = new TrainingSetDialog(testSet);
	}else{
		testSetDialog = new TrainingSetDialog(testSet = new TrainingSet(mlp));
	}
	if(testSetDialog->exec() == QDialog::Accepted){
		testSet = testSetDialog->getTrainingSet();
	}
	delete testSet;
}

void MLPTrainingDialog::on_btnAddLayer_clicked()
{
	bool ok = false;
	int val = QInputDialog::getInt(this,
								   "Numero de elementos",
								   "Neuronas",
								   10,
								   1,
								   999999,
								   1,
								   &ok);


	if(ok){
		ui->tblLayers->blockSignals(true);
		ui->tblLayers->setRowCount(ui->tblLayers->rowCount() + 1);

		QTableWidgetItem *nLayer = new QTableWidgetItem(QString::number(ui->tblLayers->rowCount()));
		nLayer->setTextAlignment(Qt::AlignCenter);
		ui->tblLayers->setItem(ui->tblLayers->rowCount() - 1, 0, nLayer);

		QTableWidgetItem *cNeurons = new QTableWidgetItem(QString::number(val));
		cNeurons->setTextAlignment(Qt::AlignCenter);
		ui->tblLayers->setItem(ui->tblLayers->rowCount() - 1, 1, cNeurons);
		ui->tblLayers->blockSignals(false);
		mlp->addLayer(val);
	}
}

void MLPTrainingDialog::on_btnDeleteLayer_clicked()
{
	//TODO: implementar
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
		//		TrainingSet *trainingSet = gmlp->getTrainingSet();

		BackpropagationSettings *bp = new BackpropagationSettings(
					sbEpochs->getValue(),
					(StopCondition)ui->cbStopCondition->currentIndex(),
					ui->sbEMValue->value(),
					//											  ui->sbMinRMSError->value(),
					//											  ui->sbMinErrorClasification->value(),
					sbLearningRate->getValue());

		//		SimulatedAnnealingSettings *sa = new SimulatedAnnealingSettings(
		//					saWidget->getMinTemperature(),
		//					saWidget->getNumberOfChanges(),
		//					saWidget->getStartCondition(),
		//					saWidget->getStartTemperature(),
		//					saWidget->getMinNoise(),
		//					saWidget->getMaxNoise(),
		//					saWidget->getDecTempFactor());
		SimulatedAnnealingSettings *sa = saWidget->getSimulatedAnnealingSettings();

		for(int i = 0; i < nSamples; i++){
			arr[i] = new MultilayerPerceptron(mlp->getInputSize(),
											  mlp->getOutputSize(),
											  mlp->getLayerSizes(),
											  mlp->getTransferFunctionType());

			arr[i]->randomizeWeights(rndFrom->getValue(), rndTo->getValue());

			connect(arr[i], SIGNAL(onTrainingFinished(MLPTrainingResult)), SLOT(multipleTrainingResult(MLPTrainingResult)));

			//Si esta habilitado Simulated Annealing
			if(ui->chkSA->isChecked()){
				arr[i]->startTraining(trainingSet, bp, sa);
			}else{
				arr[i]->startTraining(trainingSet, bp);
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
			sbThreshold->setEnabled(false);
			break;
		case 1:
			//			ui->sbMinRMSError->setEnabled(true);
			//			ui->sbMinErrorClasification->setEnabled(false);
			sbThreshold->setEnabled(false);
			break;
		case 2:
			//			ui->sbMinRMSError->setEnabled(false);
			//			ui->sbMinErrorClasification->setEnabled(true);
			sbThreshold->setEnabled(true);
	}
}

void MLPTrainingDialog::on_chkSA_toggled(bool checked)
{
	saWidget->setVisible(checked);
}
