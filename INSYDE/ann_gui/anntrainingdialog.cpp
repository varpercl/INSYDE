#include "anntrainingdialog.h"
#include "ui_mlptrainingdialog.h"

ANNTrainingDialog::ANNTrainingDialog(MultilayerPerceptron *mlp, TrainingSet *ts, QWidget *parent) :
	BasicDialog(parent)
{
	init(mlp, ts, NULL, NULL);
}

ANNTrainingDialog::ANNTrainingDialog(MultilayerPerceptron *mlp, TrainingSet *ts, TrainingSet *vs, TrainingSet *testset, QWidget *parent):
	BasicDialog(parent)
{
	init(mlp, ts, vs, testset);
}

ANNTrainingDialog::ANNTrainingDialog(GraphicMLPElement *gmlp, QWidget *parent) :
	BasicDialog(parent)
{
	init(gmlp->getMultilayerPerceptron(),
		 gmlp->getTrainingSet(),
		 gmlp->getValidationSet(),
		 gmlp->getTestSet());
}

ANNTrainingDialog::~ANNTrainingDialog()
{
}

void ANNTrainingDialog::setTrainingSet(TrainingSet *ts)
{
	if(trainingSet != ts){
		trainingSet = ts;
	}
}

TrainingSet *ANNTrainingDialog::getTrainingSet() const
{
	return trainingSet;
}

void ANNTrainingDialog::setValidationSet(TrainingSet *vs)
{
	if(validationSet != vs){
		validationSet = vs;
	}
}

TrainingSet *ANNTrainingDialog::getValidationSet() const
{
	return validationSet;
}

void ANNTrainingDialog::setTestSet(TrainingSet *ts)
{
	if (testSet != ts) {
		testSet = ts;
	}
}

TrainingSet *ANNTrainingDialog::getTestSet() const
{
	return testSet;
}

void ANNTrainingDialog::setMultilayerPerceptron(MultilayerPerceptron *mlp)
{
	this->mlp = mlp;
}

MultilayerPerceptron *ANNTrainingDialog::getMultilayerPerceptron() const
{
	return mlp;
}

void ANNTrainingDialog::saveClick()
{

}

void ANNTrainingDialog::closeEvent(QCloseEvent *)
{
	mlp->stopTraining();
}

void ANNTrainingDialog::onTrainingFinished(MLPTrainingResult tres)
{
	(void)tres;
	switch(currentTrainingStatus){
		case ANNTrainingDialog::Running:
			setTrainingStatus(Finished);
			break;
		case ANNTrainingDialog::Pausing:
			setTrainingStatus(Paused);
			break;
		case ANNTrainingDialog::Stopping:
			this->tres->clear();
			setTrainingStatus(Stopped);
			break;

		case ANNTrainingDialog::Paused:
		case ANNTrainingDialog::Stopped:
		case ANNTrainingDialog::Finished:
		default:
			break;
	}

}

void ANNTrainingDialog::multipleTrainingResult(MLPTrainingResult *tres)
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

void ANNTrainingDialog::onBtnEditTrainingSetClicked()
{
	trainingSetDialog = new TrainingSetDialog(trainingSet);

	if(trainingSetDialog->exec() == QDialog::Accepted){

		TrainingSet *ts;;
		if(isValidTrainingSet(ts = trainingSetDialog->getTrainingSet())){
			trainingSet = ts;
		}else{

		}
	}
}

void ANNTrainingDialog::onTrainingAlgorithmChanged(int index)
{
	switch(index){
		case 0:
			ta = MultilayerPerceptron::Backpropagation;
			break;
		case 1:
			ta = MultilayerPerceptron::GradientDescendent;
			break;
		case 2:
			ta = MultilayerPerceptron::ScaledConjugateGradient;
			break;
	}
}

void ANNTrainingDialog::onTrasnferFunctionChanged(int index)
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

void ANNTrainingDialog::init(MultilayerPerceptron *imlp, TrainingSet *ts, TrainingSet *vs, TrainingSet *testS)
{
	QSpinBox
			*sbInValue,
			*sbOutValue;

	const int
			decimals = 5,
			max = 999999,
			min = -999999/*,
			step = 0.01*/;

	const double
			minError = 0.5;

	//Se inicializan todos los QVBoxLayout
	vlyMainScrollArea = new QVBoxLayout();
	vlyTrainingConditions = new QVBoxLayout();
	vlyToolButtons = new QVBoxLayout();
	vlyStopConditionBox = new QVBoxLayout();
	vlyOptimizationInternalLayout = new QVBoxLayout();
	vlyOptimizationWidget = new QVBoxLayout();

	//Initialize every QHBoxLayout
	lyInitialSettings = new QHBoxLayout();
	hlyStopConditionError = new QHBoxLayout();
	hlyLayers = new QHBoxLayout();
	hlyRandomize = new QHBoxLayout();

	//Initialize every QGridLayout
	vlyPlotter = new QVBoxLayout();

	//Se inicializan todos los QScrollArea
	scrollArea = new QScrollArea();
	saOptimization = new QScrollArea();

	//Initialize every QWidget
	scrollAreaContent = new QWidget();
	wOptimizations = new QWidget();

	//Initialize every QGroupBox
	gbProperties = new QGroupBox("Propiedades de la red");
	gbStopCondition = new QGroupBox(QString::fromLatin1("Condición de parada"));
	gbOptimization = new QGroupBox(QString::fromLatin1("Optimización"));
	gbPlotter = new QGroupBox("Resultados");

	//Inicilize every QFormLayout
	flyPropertiesBox = new QFormLayout();

	//Initialize every LabeledIntegerSpinBox
	lisbInputs = new LabeledIntegerSpinBox("Entradas");
	lisbOutputs = new LabeledIntegerSpinBox("Salidas");
	lisbEpochs = new LabeledIntegerSpinBox(QString::fromLatin1("Épocas"), 200000);

	//Initialize every LabeledComboBox
	lcbAlgorithm = new LabeledComboBox("Algoritmo");
	lcbTransferFunction = new LabeledComboBox(QString::fromLatin1("Función de transferencia"));

	//Initializa every LabeledDoubleSpinBoxWidget
	ldsbLearningRate = new LabeledDoubleSpinBox("Taza de aprendizaje", 0.5);
	ldsbSlope = new LabeledDoubleSpinBox("Pendiente", 1);
	ldsbThreshold = new LabeledDoubleSpinBox("Umbral", 0.5);
	ldsbRndFrom = new LabeledDoubleSpinBox("desde", -0.01);
	ldsbRndTo = new LabeledDoubleSpinBox("hasta", 0.01);
	ldsbMinError = new LabeledDoubleSpinBox("", minError);

	//Initialize every QPushButton
	btnEditTrainingSet = new QPushButton("Conjunto de entrenamiento...");
	btnEditValidationSet = new QPushButton(QString::fromLatin1("Conjunto de validación..."));
	btnEditTestSet = new QPushButton("Conjunto de prueba...");

	//Initialize every QToolButton
	btnTraining = new QToolButton();
	btnAddLayer = new QToolButton();
	btnDeleteLayer = new QToolButton();
	btnWeights = new QToolButton();

	//Initialize every QSpacerItem
	verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
	horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

	//Initialize every QComboBox
	cbStopCondition = new QComboBox();

	//Initialize every QTableWidget
	tblLayers = new QTreeView();

	//Initialize every QCheckBox
	chkSA = new QCheckBox("Simulated Annealing");

	//Initialize every QLabel
	lblTime = new QLabel();

	//Initialize every QMenu
	mnuTraining = new QMenu();
	mnuWeights = new QMenu();

	//Initialize every QAction
	actionStartTraining = new QAction(ICON_TRAINING, "Entrenar", mnuTraining);
	actionStopTraining = new QAction(ICON_STOP, "Detener", mnuTraining);
	actionMultipleTraining = new QAction(ICON_MULTIPLE_TRAINING, "Programar entrenamiento...", mnuTraining);
	actionClearChart = new QAction(ICON_CLEAR, QString::fromLatin1("Limpiar gráfica"), mnuTraining);

	//Initialize every SimulatedAnnealingWidget
	wSimulatedAnnealing = new SimulatedAnnealingWidget(0.01, 200, 50,  1, 0.9, 4, -0.02, 0.02);

	//Initialize every KDChart::Chart
	chart = new KDChart::Chart();

	//Initialize every KDChart::Plotter
	plotter = new KDChart::Plotter();

	//Initialize every KDChart::CartesianAxis
	xAxis = new KDChart::CartesianAxis(plotter);
	yAxis = new KDChart::CartesianAxis(plotter);

	//Initialize every KDChart::Legend
	legend = new KDChart::Legend(plotter, chart);

	//Initialize every WeightEditorDialog
	weightEditor = new WeightEditorDialog();








	//==================================================================================================================
	sbInValue = lisbInputs->getIntegerSpinBox();
	sbInValue->setButtonSymbols(QSpinBox::NoButtons);
	sbInValue->setReadOnly(true);

	//==================================================================================================================
	sbOutValue = lisbOutputs->getIntegerSpinBox();
	sbOutValue->setButtonSymbols(QSpinBox::NoButtons);
	sbOutValue->setReadOnly(true);

	//==================================================================================================================
//	tblLayers->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
//	tblLayers->setAlternatingRowColors(true);
//	tblLayers->setColumnCount(2);
//	tblLayers->verticalHeader()->setVisible(false);
////	tblLayers->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

	//==================================================================================================================
	btnAddLayer->setIcon(ICON_PLUS);

	//==================================================================================================================
	btnDeleteLayer->setIcon(ICON_MINUS);

	//==================================================================================================================
	vlyToolButtons->addWidget(btnAddLayer);
	vlyToolButtons->addWidget(btnDeleteLayer);
	vlyToolButtons->addItem(verticalSpacer);

	//==================================================================================================================
	hlyLayers->addWidget(tblLayers);
	hlyLayers->addLayout(vlyToolButtons);

	//==================================================================================================================
	lcbAlgorithm->getComboBox()->addItem("Backpropagation");

	//==================================================================================================================
	lcbTransferFunction->getComboBox()->addItem("Sigmoide");
	lcbTransferFunction->getComboBox()->addItem("Tangente");

	//==================================================================================================================
	ldsbSlope->setDecimals(decimals);
//	ldsbSlope->getDoubleSpinBox()->setSingleStep(step);

	//==================================================================================================================
	ldsbLearningRate->setDecimals(decimals);
//	ldsbLearningRate->getDoubleSpinBox()->setSingleStep(step);

	//==================================================================================================================
	cbStopCondition->addItem(QString::fromLatin1("MSE mínimo"));
	cbStopCondition->addItem(QString::fromLatin1("RMSE mínimo"));
	cbStopCondition->addItem(QString::fromLatin1("CE mínimo"));

	//==================================================================================================================
	ldsbMinError->setLabelVisible(false);
	ldsbMinError->setDecimals(decimals);
	ldsbMinError->setMaximumValue(max);
	ldsbMinError->setValue(minError);

	//==================================================================================================================
	hlyStopConditionError->addWidget(cbStopCondition);
	hlyStopConditionError->addWidget(ldsbMinError);

	//==================================================================================================================
	ldsbThreshold->setDecimals(decimals);

	//==================================================================================================================
	ldsbRndFrom->setMinimumValue(min);
	ldsbRndFrom->setMaximumValue(max);
	ldsbRndFrom->setDecimals(decimals);

	//==================================================================================================================
	ldsbRndTo->setMinimumValue(min);
	ldsbRndTo->setMaximumValue(max);
	ldsbRndTo->setDecimals(decimals);

	//==================================================================================================================
	actionRandomizeWeights = mnuWeights->addAction(ICON_DICE, "Aleatorizar pesos");
	actionEditWeights = mnuWeights->addAction(ICON_EDIT, "Editar pesos...");

	//==================================================================================================================
	btnWeights->setDefaultAction(actionRandomizeWeights);
	btnWeights->setPopupMode(QToolButton::MenuButtonPopup);
	btnWeights->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	btnWeights->setText(actionRandomizeWeights->text());
	btnWeights->setMenu(mnuWeights);

	//==================================================================================================================
	hlyRandomize->addWidget(btnWeights);
	hlyRandomize->addWidget(ldsbRndFrom);
	hlyRandomize->addWidget(ldsbRndTo);

	//==================================================================================================================
	vlyStopConditionBox->addLayout(hlyStopConditionError);
	vlyStopConditionBox->addWidget(lisbEpochs);
	vlyStopConditionBox->addWidget(ldsbThreshold);
	vlyStopConditionBox->addLayout(hlyRandomize);

	//==================================================================================================================
	gbStopCondition->setLayout(vlyStopConditionBox);

	//==================================================================================================================
	vlyOptimizationWidget->setAlignment(Qt::AlignTop);
	vlyOptimizationWidget->addWidget(chkSA);
	vlyOptimizationWidget->addWidget(wSimulatedAnnealing);

	//==================================================================================================================
	wOptimizations->setLayout(vlyOptimizationWidget);

	//==================================================================================================================
//	saOptimization->setWidgetResizable(true);
	saOptimization->setWidget(wOptimizations);

	//==================================================================================================================
	vlyOptimizationInternalLayout->addWidget(saOptimization);

	//==================================================================================================================
	gbOptimization->setLayout(vlyOptimizationInternalLayout);

	//==================================================================================================================
	vlyTrainingConditions->addWidget(gbStopCondition);
	vlyTrainingConditions->addWidget(gbOptimization);

	//==================================================================================================================
	xAxis->setPosition(KDChart::CartesianAxis::Bottom);
//	xAxis->setAlignment(Qt::AlignJustify);
	xAxis->setTitleText("Epocas");

	//==================================================================================================================
	yAxis->setPosition(KDChart::CartesianAxis::Left);
	yAxis->setTitleText("Error");

	//==================================================================================================================

	legend->setPosition(KDChart::Position::East);
	legend->setAlignment(Qt::AlignCenter);
	legend->setTitleText(tr("Leyenda"));
	legend->setOrientation(Qt::Vertical);
	legend->setShowLines(false);
	legend->setVisible(true);

	//==================================================================================================================
	plotter->addAxis(xAxis);
	plotter->addAxis(yAxis);

	//==================================================================================================================
	chart->addLegend(legend);
	chart->coordinatePlane()->replaceDiagram(plotter);
	chart->coordinatePlane()->setRubberBandZoomingEnabled(true);

	//==================================================================================================================
	vlyPlotter->addWidget(chart);
	vlyPlotter->addWidget(lblTime);

	//==================================================================================================================
	gbPlotter->setLayout(vlyPlotter);

	//==================================================================================================================
	actionStopTraining->setEnabled(false);

	actionClearChart->setEnabled(false);

	//==================================================================================================================
	mnuTraining->addAction(actionStartTraining);
	mnuTraining->addAction(actionStopTraining);
	mnuTraining->addAction(actionClearChart);
	mnuTraining->addAction(actionMultipleTraining);
	mnuTraining->setDefaultAction(actionStartTraining);

	//==================================================================================================================
	btnTraining->setPopupMode(QToolButton::MenuButtonPopup);
	btnTraining->setDefaultAction(actionStartTraining);
	btnTraining->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	btnTraining->setMenu(mnuTraining);

	//==================================================================================================================
	flyPropertiesBox->addRow(lisbInputs);
	flyPropertiesBox->addRow(lisbOutputs);
	flyPropertiesBox->addRow(hlyLayers);
	flyPropertiesBox->addRow(lcbAlgorithm);
	flyPropertiesBox->addRow(lcbTransferFunction);
	flyPropertiesBox->addRow(ldsbSlope);
	flyPropertiesBox->addRow(ldsbLearningRate);
	flyPropertiesBox->addRow(btnEditTrainingSet);
	flyPropertiesBox->addRow(btnEditValidationSet);
	flyPropertiesBox->addRow(btnEditTestSet);

	//==================================================================================================================
	gbProperties->setLayout(flyPropertiesBox);

	//==================================================================================================================
	lyInitialSettings->addWidget(gbProperties);
	lyInitialSettings->addLayout(vlyTrainingConditions);

	//==================================================================================================================
	vlyMainScrollArea->addLayout(lyInitialSettings);
	vlyMainScrollArea->addWidget(gbPlotter);

	//==================================================================================================================
	scrollAreaContent->setLayout(vlyMainScrollArea);

	//==================================================================================================================
	scrollArea->setWidgetResizable(true);
	scrollArea->setWidget(scrollAreaContent);

	//==================================================================================================================
	setEnableNew(false);
	setEnableExport(false);
	setEnableImport(false);
	setEnableUnDoFramework(false);
	setEnableClipboardFramework(false);
	getRejectButton()->setText("Cerrar");
	setAcceptButtonVisible(false);

	//Must be inserted after index 1 because 0 is Stretch Item
	insertButton(1, btnTraining);
	getMainWindow()->setCentralWidget(scrollArea);
	setWindowModality(Qt::NonModal);
	setWindowFlags(Qt::Window);

	//Se asigna el perceptron
	setMultilayerPerceptron(imlp);

	mlp->setSaveTrainingResults(true);
	mlp->setEnabledElapsedTimeEvent(true);

	tres = mlp->getTrainingResult();
	plotter->setModel(tres);

	setTrainingSet(ts);
	setValidationSet(vs);
	setTestSet(testS);

	setTrainingStatus(Stopped);

	ta = MultilayerPerceptron::Backpropagation;
	//	this->gmlp = gmlp;
	//	isTraining = false;
	lisbInputs->setValue(mlp->getInputsSize());
	lisbOutputs->setValue(mlp->getOutputsSize());

	annModel = new ANNModelWrapper(mlp);

	annModel->setCanEditLayerSize(true);
	annModel->setVisibleNeurons(false);
	annModel->setVisibleWeightValues(false);
	annModel->setViewType(ANNModelWrapper::Table);

	tblLayers->setModel(annModel);

//	//Inicializa la tabla de las capas
//	for(size_t i = 0; i < mlp->getLayerSizes().size(); i++){
//		tblLayers->setRowCount(tblLayers->rowCount() + 1);
//		QTableWidgetItem *layerNumberCell = new QTableWidgetItem(QString::number(i+1));
//		layerNumberCell->setFlags(Qt::NoItemFlags);
//		layerNumberCell->setTextAlignment(Qt::AlignHCenter);
//		tblLayers->setItem(i, 0, layerNumberCell);
//		QTableWidgetItem *nElementsCell = new QTableWidgetItem(QString::number(mlp->getLayerSize(i)));
//		nElementsCell->setTextAlignment(Qt::AlignHCenter);
//		tblLayers->setItem(i, 1, nElementsCell);
//	}

	btnDeleteLayer->setEnabled(mlp->getLayerCount() > 1);
	lcbAlgorithm->getComboBox()->setCurrentIndex(0);

	onCbStopConditionCurrentIndexChanged(0);
	onBtnRandomizeClicked();
	wSimulatedAnnealing->setVisible(false);


	//Connect save action
	connect(getFileMenu()->actions()[1], SIGNAL(triggered()), SLOT(saveClick()));
	connect(actionClearChart, SIGNAL(triggered()), SLOT(onClearChartClicked()));
	connect(lcbTransferFunction->getComboBox(), SIGNAL(currentIndexChanged(int)), SLOT(onTrasnferFunctionChanged(int)));
	connect(lcbAlgorithm->getComboBox(), SIGNAL(currentIndexChanged(int)), SLOT(onTrainingAlgorithmChanged(int)));
	connect(actionStartTraining, SIGNAL(triggered()), SLOT(onTrainClicked()));
	connect(actionStopTraining, SIGNAL(triggered()), SLOT(onStopTrainingClicked()));
	connect(actionMultipleTraining, SIGNAL(triggered()), SLOT(onMultipleTrainingClicked()));
	connect(chkSA, SIGNAL(toggled(bool)), SLOT(onChkSimAnnToggled(bool)));
	connect(actionRandomizeWeights, SIGNAL(triggered()), SLOT(onBtnRandomizeClicked()));
	connect(actionEditWeights, SIGNAL(triggered()), SLOT(onEditWeightsClicked()));
	connect(cbStopCondition, SIGNAL(currentIndexChanged(int)), SLOT(onCbStopConditionCurrentIndexChanged(int)));
	connect(btnEditTrainingSet, SIGNAL(clicked()), SLOT(onBtnEditTrainingSetClicked()));
	connect(btnEditValidationSet, SIGNAL(clicked()), SLOT(onBtnEditValidationTestClicked()));
	connect(btnEditTestSet, SIGNAL(clicked()), SLOT(onBtnEditTestSetClicked()));
	connect(btnAddLayer, SIGNAL(clicked()), SLOT(onBtnAddLayerClicked()));
	connect(btnDeleteLayer, SIGNAL(clicked()), SLOT(onDeleteLayerClicked()));
	connect(mlp, SIGNAL(elapsedTime(MLPTrainingResult)), SLOT(updateStatusLabels(MLPTrainingResult)));
	connect(mlp, SIGNAL(trainingFinished(MLPTrainingResult)), SLOT(onTrainingFinished(MLPTrainingResult)));
}

void ANNTrainingDialog::createFile(QString path, MLPTrainingResult *tr, int nsamples){
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

void ANNTrainingDialog::disableAllControls()
{
	chkSA->setEnabled(false);
	cbStopCondition->setEnabled(false);
	lcbAlgorithm->setEnabled(false);
	lcbTransferFunction->setEnabled(false);
	tblLayers->setEnabled(false);
	btnAddLayer->setEnabled(false);
	btnDeleteLayer->setEnabled(false);
	btnEditTestSet->setEnabled(false);
	btnEditTrainingSet->setEnabled(false);
	btnEditValidationSet->setEnabled(false);
	btnWeights->setEnabled(false);
	ldsbMinError->setEnabled(false);

	lisbEpochs->setEnabled(false);
	ldsbLearningRate->setEnabled(false);
	ldsbRndFrom->setEnabled(false);
	ldsbRndTo->setEnabled(false);
	ldsbSlope->setEnabled(false);

	wSimulatedAnnealing->setEnabled(false);
}

void ANNTrainingDialog::setBPEnabledControls(bool enabled)
{
	cbStopCondition->setEnabled(enabled);
	chkSA->setEnabled(enabled);
	lcbAlgorithm->setEnabled(enabled);
	lcbTransferFunction->setEnabled(enabled);

	tblLayers->setEnabled(enabled);

	btnAddLayer->setEnabled(enabled);
	btnDeleteLayer->setEnabled(enabled);
	btnEditTestSet->setEnabled(enabled);
	btnEditTrainingSet->setEnabled(enabled);
	btnEditValidationSet->setEnabled(enabled);
	btnWeights->setEnabled(enabled);

	lisbEpochs->setEnabled(enabled);
	ldsbLearningRate->setEnabled(enabled);
	if(enabled){
		onCbStopConditionCurrentIndexChanged(cbStopCondition->currentIndex());
	}else{
		ldsbMinError->setEnabled(enabled);
		//		ui->sbMinErrorClasification->setEnabled(enabled);
		//		ui->sbMinRMSError->setEnabled(enabled);
	}
	ldsbRndFrom->setEnabled(enabled);
	ldsbRndTo->setEnabled(enabled);
	ldsbSlope->setEnabled(enabled);
}

void ANNTrainingDialog::updateSAControls()
{
	wSimulatedAnnealing->setVisible(chkSA->isChecked());
	wSimulatedAnnealing->setEnabled(chkSA->isChecked());
}

void ANNTrainingDialog::updateActionClearChart()
{
	if(tres->rowCount() > 0 && !mlp->isTraining()){
		actionClearChart->setEnabled(true);
	}else{
		actionClearChart->setEnabled(false);
	}

}

bool ANNTrainingDialog::isValidTrainingSet(TrainingSet *ts)
{
	if(ts->getInputsSize() == mlp->getInputsSize() &&
	   ts->getTargetsSize() == mlp->getOutputsSize()){
		return true;
	}

	return false;
}

void ANNTrainingDialog::setTrainingStatus(ANNTrainingDialog::TrainingStatus ts)
{
	switch(ts){
		case ANNTrainingDialog::Finished:
			updateActionClearChart();
			updateStatusLabels(*tres);
			setBPEnabledControls(true);
			updateSAControls();

			actionStartTraining->setIcon(ICON_TRAINING);
			actionStartTraining->setText("Entrenar");
			actionStopTraining->setEnabled(false);
			btnTraining->setText(actionStartTraining->text());

			currentTrainingStatus = Finished;

			raise();
			break;
		case ANNTrainingDialog::Running:{
			disableAllControls();

			actionStartTraining->setIcon(ICON_PAUSE);
			actionStartTraining->setText("Pausar");
			actionStopTraining->setEnabled(true);
			btnTraining->setText(actionStartTraining->text());
			actionClearChart->setEnabled(false);

			BackpropagationSettings *bp = new BackpropagationSettings(
											  lisbEpochs->getValue(),
											  (StopCondition)cbStopCondition->currentIndex(),
											  ldsbMinError->getValue(),
											  ldsbLearningRate->getValue());

			SimulatedAnnealingSettings *sa = new SimulatedAnnealingSettings(
												 wSimulatedAnnealing->getMinTemperature(),
												 wSimulatedAnnealing->getSamples(),
												 wSimulatedAnnealing->getNumberOfChanges(),
												 wSimulatedAnnealing->getStartCondition(),
												 wSimulatedAnnealing->getStartTemperature(),
												 wSimulatedAnnealing->getMinNoise(),
												 wSimulatedAnnealing->getMaxNoise(),
												 wSimulatedAnnealing->getDecTempFactor());
			//Si esta habilitado Simulated Annealing
			if(chkSA->isChecked()){
				mlp->startTraining(trainingSet, bp, sa);
			}else{
				mlp->startTraining(trainingSet, bp);
			}

			currentTrainingStatus = Running;
			break;
		}
		case ANNTrainingDialog::Pausing:
			mlp->stopTraining();
			actionStartTraining->setIcon(ICON_WAITING);
			actionStartTraining->setText("Pausando...");
			actionStopTraining->setEnabled(false);
			btnTraining->setText(actionStartTraining->text());
			actionClearChart->setEnabled(false);

			currentTrainingStatus = Pausing;
			break;
		case ANNTrainingDialog::Paused:
			updateActionClearChart();
			updateStatusLabels(*tres);
			setBPEnabledControls(true);
			updateSAControls();

			actionStartTraining->setIcon(ICON_TRAINING);
			actionStartTraining->setText("Continuar");
			actionStopTraining->setEnabled(true);
			btnTraining->setText(actionStartTraining->text());

			currentTrainingStatus = Paused;
			break;
		case ANNTrainingDialog::Stopping:
			mlp->stopTraining();

			actionStartTraining->setIcon(ICON_WAITING);
			actionStartTraining->setText("Deteniendo...");
			actionStopTraining->setEnabled(false);
			btnTraining->setText(actionStartTraining->text());
			actionClearChart->setEnabled(false);

			currentTrainingStatus = Stopping;
			break;
		case ANNTrainingDialog::Stopped:
			updateActionClearChart();
			updateStatusLabels(*tres);
			setBPEnabledControls(true);
			updateSAControls();

			actionStartTraining->setIcon(ICON_TRAINING);
			actionStartTraining->setText("Entrenar");
			actionStopTraining->setEnabled(false);
			btnTraining->setText(actionStartTraining->text());

			raise();

			currentTrainingStatus = Stopped;
			break;

		default:
			break;
	}
}

void ANNTrainingDialog::updateTableLayers()
{

	//TODO: 13/9/15 this method should be removed
//	tblLayers->blockSignals(true);

//	int lc = mlp->getLayerCount();
//	tblLayers->setRowCount(lc);
//	QTableWidgetItem
//			*nLayer,
//			*cNeurons;

//	for(int i = 0; i < lc; i++){
//		nLayer = new QTableWidgetItem(QString::number(i + 1));
//		nLayer->setTextAlignment(Qt::AlignCenter);
//		tblLayers->setItem(i, 0, nLayer);

//		cNeurons = new QTableWidgetItem(QString::number(mlp->getLayerSizes()[i]));
//		cNeurons->setTextAlignment(Qt::AlignCenter);
//		tblLayers->setItem(i, 1, cNeurons);
//	}

//	tblLayers->blockSignals(false);
}

void ANNTrainingDialog::onTrainClicked()
{
	switch(currentTrainingStatus){
		case ANNTrainingDialog::Running:
			setTrainingStatus(Pausing);
			break;
		case ANNTrainingDialog::Pausing:
		case ANNTrainingDialog::Stopping:
			break;
		case ANNTrainingDialog::Finished:
		case ANNTrainingDialog::Paused:
		case ANNTrainingDialog::Stopped:
		default:
			setTrainingStatus(Running);
			break;

	}
}

void ANNTrainingDialog::onStopTrainingClicked()
{
	switch(currentTrainingStatus){
		case ANNTrainingDialog::Running:
			setTrainingStatus(Stopping);
			break;
		case ANNTrainingDialog::Paused:
			tres->clear();
			setTrainingStatus(Stopped);
			break;
		case ANNTrainingDialog::Finished:
		case ANNTrainingDialog::Pausing:
		case ANNTrainingDialog::Stopping:
		case ANNTrainingDialog::Stopped:
			break;

	}
}

void ANNTrainingDialog::onClearChartClicked()
{
	if(tres->rowCount() != 0){
		tres->clear();
		actionClearChart->setEnabled(false);
	}
}

void ANNTrainingDialog::onCancelClicked()
{
	//WARNING: onCancelClicked must be validated to finish training before close
	close();
}

void ANNTrainingDialog::onBtnRandomizeClicked()
{
	mlp->randomizeWeights(ldsbRndFrom->getValue(), ldsbRndTo->getValue());
}

void ANNTrainingDialog::onEditWeightsClicked()
{
	weightEditor = new WeightEditorDialog(mlp);

	weightEditor->setWindowModality(Qt::NonModal);

	weightEditor->show();
}

void ANNTrainingDialog::updateStatusLabels(MLPTrainingResult tres)
{
	if(tres.isEmpty()){
		xAxis->setTitleText("Epocas: 0");

		lblTime->setText("Tiempo transcurrido: 0");
	}else{
		xAxis->setTitleText("Epocas: " + QString::number(tres.getEpochs()));

		lblTime->setText("Tiempo transcurrido: " + QString::number(tres.getTime()));
		//	lblTime->setText("Tiempo transcurrido: " + QTime(0, 0, tres.getTime()).toString("hh:mm:ss"));
	}
}

void ANNTrainingDialog::generateReport()
{
	//TODO: implementar
}

void ANNTrainingDialog::exportData()
{
	if(!tres->isEmpty()){
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
				//TODO: corregir boton de guardar
				//				saveFile->setEnabled(false);
				return;
			}
		}
	}else{
		QMessageBox::critical(this, "Error", "No hay ningun dato para guardar");
		//		QMessageBox msgBox;
		//		msgBox.setText("No hay ningun dato para guardar");
		//		msgBox.exec();
	}

	//TODO: corregir boton de guardar
	//	saveFile->setEnabled(true);
}

void ANNTrainingDialog::onBtnEditValidationTestClicked()
{
	if(validationSet != NULL){
		validationSetDialog = new TrainingSetDialog(validationSet);
	}else{
		validationSetDialog = new TrainingSetDialog(validationSet = new TrainingSet(mlp->getInputsSize(), mlp->getOutputsSize()));
	}
	if(validationSetDialog->exec() == QDialog::Accepted){
		validationSet = validationSetDialog->getTrainingSet();
	}
	delete validationSetDialog;
}

void ANNTrainingDialog::onBtnEditTestSetClicked()
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

void ANNTrainingDialog::onBtnAddLayerClicked()
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

		mlp->addLayer(val);

		updateTableLayers();

		btnDeleteLayer->setEnabled(mlp->getLayerCount() > 1);
	}
}

void ANNTrainingDialog::onDeleteLayerClicked()
{
	//TODO: 13/9/15 this method should be validated
//	int selRow = tblLayers->selectedItems()[0]->row();

//	mlp->removeLayer(selRow);

//	updateTableLayers();

//	btnDeleteLayer->setEnabled(mlp->getLayerCount() > 1);
}

void ANNTrainingDialog::onMultipleTrainingClicked()
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
										  lisbEpochs->getValue(),
										  (StopCondition)cbStopCondition->currentIndex(),
										  ldsbMinError->getValue(),
										  //											  ui->sbMinRMSError->value(),
										  //											  ui->sbMinErrorClasification->value(),
										  ldsbLearningRate->getValue());


		SimulatedAnnealingSettings *sa = wSimulatedAnnealing->getSimulatedAnnealingSettings();

		for(int i = 0; i < nSamples; i++){
			arr[i] = new MultilayerPerceptron(mlp->getInputsSize(),
											  mlp->getOutputsSize(),
											  mlp->getLayerSizes(),
											  mlp->getTransferFunctionType());

			arr[i]->randomizeWeights(ldsbRndFrom->getValue(), ldsbRndTo->getValue());

			connect(arr[i], SIGNAL(onTrainingFinished(MLPTrainingResult)), SLOT(multipleTrainingResult(MLPTrainingResult)));

			//Si esta habilitado Simulated Annealing
			if(chkSA->isChecked()){
				arr[i]->startTraining(trainingSet, bp, sa);
			}else{
				arr[i]->startTraining(trainingSet, bp);
			}
		}
	}
}

void ANNTrainingDialog::onCbStopConditionCurrentIndexChanged(int index)
{

	ldsbMinError->setEnabled(true);
	switch(index){
		case 0: //MSE
			ldsbThreshold->setEnabled(false);
			tres->setMSEVisible(true);
			tres->setRMSEVisible(false);
			tres->setCEVisible(false);
			break;
		case 1: //RMSE
			ldsbThreshold->setEnabled(false);
			tres->setMSEVisible(false);
			tres->setRMSEVisible(true);
			tres->setCEVisible(false);
			break;
		case 2: //CE
			ldsbThreshold->setEnabled(true);
			tres->setMSEVisible(false);
			tres->setRMSEVisible(false);
			tres->setCEVisible(true);
			break;
	}
}

void ANNTrainingDialog::onChkSimAnnToggled(bool checked)
{
	wSimulatedAnnealing->setVisible(checked);
	wSimulatedAnnealing->setEnabled(checked);
}

