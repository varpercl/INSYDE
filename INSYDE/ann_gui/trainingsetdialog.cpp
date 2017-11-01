#include "trainingsetdialog.h"

ann_gui::TrainingSetDialog::TrainingSetDialog(QWidget *parent) :
	BasicDialog(parent)
{

	init(new TrainingSet());
}

ann_gui::TrainingSetDialog::TrainingSetDialog(TrainingSet *ts, QWidget *parent):
	BasicDialog(parent)
{
//    Q_INIT_RESOURCE(ann_gui_media); //never call it inside a namespace, instead use a wrapper function

	init(ts);
}

ann_gui::TrainingSetDialog::TrainingSetDialog(int inputCount, int targetCount, int nPatterns, QWidget *parent) :
	BasicDialog(parent)
{
//    Q_INIT_RESOURCE(ann_gui_media); //never call it inside a namespace, instead use a wrapper function

	init(new TrainingSet(vector<vector<double> >(nPatterns, vector<double>(inputCount, 0)),
						 inputCount,
						 vector<vector<double> >(nPatterns, vector<double>(targetCount, 0)),
						 targetCount));
}

ann_gui::TrainingSetDialog::TrainingSetDialog(const vector<vector<double> > &inputs, int is, const vector<vector<double> > &targets, int ts, QWidget *parent) :
	BasicDialog(parent)
{
//    Q_INIT_RESOURCE(ann_gui_media); //never call it inside a namespace, instead use a wrapper function

	init(new TrainingSet(inputs, is, targets, ts));
}

ann_gui::TrainingSetDialog::TrainingSetDialog(ArtificialNeuralNetwork *ann, QWidget *parent) :
	BasicDialog(parent)
{
//    Q_INIT_RESOURCE(ann_gui_media); //never call it inside a namespace, instead use a wrapper function

	switch(ann->getType()){
		case ann_base::ArtificialNeuralNetwork::Adaline:
			break;
		case ann_base::ArtificialNeuralNetwork::SimplePerceptron:
			break;
		case ann_base::ArtificialNeuralNetwork::MultilayerPerceptron:
		{
			MultilayerPerceptron *mlp = dynamic_cast<MultilayerPerceptron *>(ann);
			init(new TrainingSet(mlp->getInputSize(), mlp->getOutputSize()));
			break;
		}
		case ann_base::ArtificialNeuralNetwork::Hopfiel:
			break;
		case ann_base::ArtificialNeuralNetwork::Kohonen:
			break;

	}
}

ann_gui::TrainingSetDialog::~TrainingSetDialog()
{
	delete btnMsgBoxFirstPixels;
	delete btnMsgBoxImageSegment;
	delete btnCancel;
	delete gbTargetsRepresentation;
	delete gbInputsRepresentation;
	delete addPatternButton;
	delete delPatternButton;
	delete tstInputs;
}

void ann_gui::TrainingSetDialog::canEditInputSize(bool c)
{
	lisbInputsSize->getIntegerSpinBox()->setEnabled(c);
}

void ann_gui::TrainingSetDialog::canEditTargetSize(bool c)
{
	lisbTargetsSize->getIntegerSpinBox()->setEnabled(c);
}

void ann_gui::TrainingSetDialog::setTrainingSet(TrainingSet *ts)
{
	if(this->ts != ts){
		this->ts = ts;

		tstInputs->setTrainingSet(ts);
		inw->setNormalization(ts->getInputsNormalization());
		gbInputsRepresentation->setDataRepresentation(ts->getInputsDataRepresentation());

		tstTargets->setTrainingSet(ts);
		tnw->setNormalization(ts->getTargetsNormalization());
		gbTargetsRepresentation->setDataRepresentation(ts->getTargetsDataRepresentation());

		connectTrainingSetSignals();
	}
}

TrainingSet *ann_gui::TrainingSetDialog::getTrainingSet() const
{
	return ts;
}

void ann_gui::TrainingSetDialog::onExportClick()
{
	//TODO: 15/4/16 onExportClick implement
}

void ann_gui::TrainingSetDialog::onInputsCellClicked(const QModelIndex &index)
{
	(void)index;
	getCutAction()->setEnabled(tstInputs->getCutAction()->isEnabled());
	tstTargets->clearSelection();
}

void ann_gui::TrainingSetDialog::onTargetsCellClicked(const QModelIndex &index)
{
	(void)index;
	getCutAction()->setEnabled(tstTargets->getCutAction()->isEnabled());
	tstInputs->clearSelection();
}

void ann_gui::TrainingSetDialog::onInputsWidthChanged(int width)
{
	ts->getInputsDataRepresentation()->setWidth(width);
}

void ann_gui::TrainingSetDialog::onInputsHeightChanged(int height)
{
	ts->getInputsDataRepresentation()->setHeight(height);
}

void ann_gui::TrainingSetDialog::onTargetsWidthChanged(int width)
{
	ts->getTargetsDataRepresentation()->setWidth(width);
}

void ann_gui::TrainingSetDialog::onTargetsHeightChanged(int height)
{
	ts->getTargetsDataRepresentation()->setHeight(height);
}

void ann_gui::TrainingSetDialog::deleteRows()
{
	QItemSelectionModel *ism = 0;
	QModelIndexList mil;

	if(tstInputs->hasFocus()){
		ism = tstInputs->selectionModel();
	}

	if(tstTargets->hasFocus()){
		ism = tstTargets->selectionModel();
	}
	if(ism){
		mil = ism->selection().indexes();
		for(int i = 0; i < mil.size(); i++){
			ts->removeRow(mil.at(i).row());
		}

		isEditingTS = true;
	}
}

void ann_gui::TrainingSetDialog::deleteColumns()
{

	QItemSelectionModel *ism = 0;
	QModelIndexList mil;

	if(tstInputs->hasFocus()){
		ism = tstInputs->selectionModel();
	}

	if(tstTargets->hasFocus()){
		ism = tstTargets->selectionModel();
	}

	if(ism){
		mil = ism->selection().indexes();
		for(int i = 0; i < mil.size(); i++){
			ts->removeColumn(mil.at(i).column());
		}

		isEditingTS = true;
	}
}

void ann_gui::TrainingSetDialog::onInputsSizeChanged(int val)
{
	ts->setInputsSize(val);

	isEditingTS = true;
}

void ann_gui::TrainingSetDialog::onTargetsSizeChanged(int val)
{
	ts->setTargetsSize(val);

	isEditingTS = true;
}

void ann_gui::TrainingSetDialog::onInputsNormalizationChanged(Normalization *nor)
{
	if(nor->getType() != Normalization::Nothing){
		tstInputs->getPasteAction()->setEnabled(false);
		getPasteAction()->setEnabled(false);
	}else{
		tstInputs->getPasteAction()->setEnabled(true);
		getPasteAction()->setEnabled(true);
	}

	isEditingTS = true;
}

void ann_gui::TrainingSetDialog::onTargetsNormalizationChanged(Normalization *nor)
{
	if(nor->getType() != Normalization::Nothing){
		tstTargets->getPasteAction()->setEnabled(false);
		getPasteAction()->setEnabled(false);
	}else{
		tstTargets->getPasteAction()->setEnabled(true);
		getPasteAction()->setEnabled(true);
	}

	isEditingTS = true;
}

void ann_gui::TrainingSetDialog::on_addPatternButton_clicked()
{

	ts->appendPattern();

	isEditingTS = true;
}

void ann_gui::TrainingSetDialog::on_delPatternButton_clicked()
{
	if(tstInputs->hasFocus()){
		ts->removePattern(tstInputs->currentIndex().row());
	}else if(tstTargets->hasFocus()){
		ts->removePattern(tstTargets->currentIndex().row());
	}
}


void ann_gui::TrainingSetDialog::init(TrainingSet *ts)
{
    initAnnGuiResources();

	const double
			minRange = 100;

	this->ts = ts;

	//Initialize QVBoxLayout
	mainLayout = new QVBoxLayout();

	//Initialize QGridLayout
	gridLayout = new QGridLayout();

	lisbInputsSize = new LabeledIntegerSpinBox(tr("Inputs"), ts->getInputsSize());
	lisbTargetsSize = new LabeledIntegerSpinBox(tr("Outputs"), ts->getTargetsSize());

	actionImportFromDatabase = new QAction(tr("From SQL Database..."));

	btnTables = new QToolButton();

	mnuTables = new QMenu();

	QMenu *importMenu = new QMenu(tr("Import"));
	importMenu->addAction(ICON_IMPORT, tr("Inputs..."), this, SLOT(importInputsClick()));
	importMenu->addAction(ICON_IMPORT, tr("Outputs..."), this, SLOT(importTargetsClick()));
	importMenu->addAction(ICON_IMPORT_DB, tr("From SQL Database..."), this, SLOT(importFromDBClick()));
	//TODO: 16/4/15 implement this
//	importMenu->addAction(ICON_IMPORT, "Conjunto de entrenamiento...", this, SLOT(importTrainingSetClick()));

	getImportAction()->setMenu(importMenu);

	addPatternButton = new QToolButton();
	addPatternButton->setIcon(ICON_PLUS);
	addPatternButton->setPopupMode(QToolButton::MenuButtonPopup);
	addPatternButton->setMenu(importMenu);

	QMenu *delMenu = new QMenu(tr("Remove"));
	QAction *defaultDelMenuAction;
	actionDeleteRow = defaultDelMenuAction = delMenu->addAction(ICON_MINUS, tr("Remove row"), this, SLOT(deleteRows()));
	actionDeleteCol = delMenu->addAction(ICON_MINUS, tr("Remove column"), this, SLOT(deleteColumns()));
	delMenu->setDefaultAction(defaultDelMenuAction);

	delPatternButton = new QToolButton();
	delPatternButton->setIcon(ICON_MINUS);
	delPatternButton->setPopupMode(QToolButton::MenuButtonPopup);
	delPatternButton->setMenu(delMenu);

	btnTables->setMenu(mnuTables);

	mainToolBar = new QToolBar();
	mainToolBar->addWidget(addPatternButton);
	mainToolBar->addWidget(delPatternButton);
	mainToolBar->addSeparator();
	mainToolBar->addWidget(btnTables);

	inw = new NormalizationWidget(this->ts->getInputsNormalization(), QString::fromLatin1("Normalización de entradas"));

	inw->setMinValueMaximum(minRange);
	inw->setMinValueMinimum(-minRange);
	inw->setMaxValueMaximum(minRange);
	inw->setMaxValueMinimum(-minRange);
	inw->setThresholdValueMaximum(minRange);
	inw->setThresholdValueMinimum(-minRange);

	//FIXME: 25/4/16 this normalization should be fixed because it doesnt deliver correct values. It's temporaly hidden
	inw->hideNormalization(Normalization(Normalization::MeanDistance));

	tnw = new NormalizationWidget(this->ts->getTargetsNormalization(), QString::fromLatin1("Normalización de salidas"));
	tnw->setMinValueMaximum(minRange);
	tnw->setMinValueMinimum(-minRange);
	tnw->setMaxValueMaximum(minRange);
	tnw->setMaxValueMinimum(-minRange);
	tnw->setThresholdValueMaximum(minRange);
	tnw->setThresholdValueMinimum(-minRange);

	tnw->hideNormalization(Normalization(Normalization::BipolarFixedThreshold));
	tnw->hideNormalization(Normalization(Normalization::BipolarAutoThreshold));
	tnw->hideNormalization(Normalization(Normalization::UnipolarFixedThreshold));
	tnw->hideNormalization(Normalization(Normalization::UnipolarAutoThreshold));
	tnw->hideNormalization(Normalization(Normalization::LinearFixedRange));
	tnw->hideNormalization(Normalization(Normalization::LinearAutoRange));
	tnw->hideNormalization(Normalization(Normalization::MeanDistance));

	tstInputs = new TrainingSetTable(this->ts);
	tstInputs->setTargetsVisible(false);

	tstTargets = new TrainingSetTable(this->ts);
	tstTargets->setInputsVisible(false);

	gbInputsRepresentation = new DataRepresentationBox(vector<double>(), this->ts->getInputsDataRepresentation());
	gbInputsRepresentation->setTitle(QString::fromLatin1("Patrón de entrada"));

	gbTargetsRepresentation = new DataRepresentationBox(vector<double>(), this->ts->getTargetsDataRepresentation());
	gbTargetsRepresentation->setTitle(QString::fromLatin1("Patrón de salida"));

	gridLayout->addWidget(lisbInputsSize, 0, 0);
	gridLayout->addWidget(lisbTargetsSize, 0, 1);
	gridLayout->addWidget(inw, 1, 0);
	gridLayout->addWidget(tnw, 1, 1);
	gridLayout->addWidget(tstInputs, 2, 0);
	gridLayout->addWidget(tstTargets, 2, 1);
	gridLayout->addWidget(gbInputsRepresentation, 3, 0);
	gridLayout->addWidget(gbTargetsRepresentation, 3, 1);

	mainLayout->addWidget(mainToolBar);
	mainLayout->addLayout(gridLayout);

	setWindowFlags(Qt::Window);

	setEnableSaveAs(false);
	setEnablePreferences(false);

	//TODO: implementar UNDO
	setEnableUnDoFramework(false);

	setToolsMenuVisible(false);
	setViewMenuVisible(false);
	setHelpMenuVisible(false);

	getAboutAction()->setVisible(false);
	getCutAction()->setEnabled(false);

	getMainWindow()->centralWidget()->setLayout(mainLayout);

	isEditingTS = false;

	initMsgBoxes();

	setWindowTitle(tr("Training Set Tool"));

	connectTrainingSetSignals();

	connect(addPatternButton, SIGNAL(clicked()), SLOT(on_addPatternButton_clicked()));
	connect(delPatternButton, SIGNAL(clicked()), SLOT(on_delPatternButton_clicked()));
	connect(tstInputs, SIGNAL(clicked(QModelIndex)), SLOT(onInputsCellClicked(QModelIndex)));
	connect(tstTargets, SIGNAL(clicked(QModelIndex)), SLOT(onTargetsCellClicked(QModelIndex)));
	connect(lisbInputsSize->getIntegerSpinBox(), SIGNAL(valueChanged(int)), SLOT(onInputsSizeChanged(int)));
	connect(lisbTargetsSize->getIntegerSpinBox(), SIGNAL(valueChanged(int)), SLOT(onTargetsSizeChanged(int)));
}

void ann_gui::TrainingSetDialog::initMsgBoxes()
{
	mbLoadFileError.setIcon(QMessageBox::Critical);
	mbLoadFileError.setModal(true);
	mbLoadFileError.setWindowTitle("Error al cargar archivo");
	mbLoadFileError.setStandardButtons(QMessageBox::Ok);

	//Se configura el mensaje indicando error al cargar una imagen
	mbErrorLoadingImageMessage.setIcon(QMessageBox::Critical);
	mbErrorLoadingImageMessage.setModal(true);
	mbErrorLoadingImageMessage.setWindowTitle("Error con imagen");
	mbErrorLoadingImageMessage.setStandardButtons(QMessageBox::Ok);

	//Se configura el mensaje indicando la incongruencia en los tamaños/formatos de la imagen cargada
	mbImageSegmentMessage.setIcon(QMessageBox::Warning);
	mbImageSegmentMessage.setModal(true);
	mbImageSegmentMessage.setWindowTitle(QString::fromLatin1("No coincide el tamaño"));

	mbImageSegmentMessage.setCheckBox(new QCheckBox(QObject::tr("Aplicar a todos los casos iguales"), &mbImageSegmentMessage));
	btnMsgBoxFirstPixels = mbImageSegmentMessage.addButton(QString::fromLatin1("Tomar los primeros pixeles"), QMessageBox::ActionRole);
	btnMsgBoxImageSegment = mbImageSegmentMessage.addButton(QString::fromLatin1("Escoger segmento de imagen"), QMessageBox::ActionRole);
	btnCancel = mbImageSegmentMessage.addButton(QMessageBox::Cancel);

	connect(&mbImageSegmentMessage, SIGNAL(buttonClicked(QAbstractButton*)), SLOT(onMessageBoxButtonClicked(QAbstractButton*)));
}

void ann_gui::TrainingSetDialog::connectTrainingSetSignals()
{
	connect(ts, SIGNAL(inputChanged(int,int,double,double)), this, SLOT(onInputChanged(int,int,double,double)));
	connect(ts, SIGNAL(targetChanged(int,int,double,double)), this, SLOT(onTargetChanged(int,int,double,double)));
//	connect(ts, SIGNAL(inputsNormalizationChanged(Normalization*)), this, SLOT(onInputsNormalizationChanged(Normalization*)));
//	connect(ts, SIGNAL(targetsNormalizationChanged(Normalization*)), this, SLOT(onTargetsNormalizationChanged(Normalization*)));

	connect(inw, SIGNAL(normalizationChanged(Normalization*)), SLOT(onInputsNormalizationChanged(Normalization*)));
	connect(tnw, SIGNAL(normalizationChanged(Normalization*)), SLOT(onTargetsNormalizationChanged(Normalization*)));

	connect(tstInputs->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), SLOT(onTstInputsSelectionChanged(QItemSelection,QItemSelection)));
	connect(tstTargets->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), SLOT(onTstTargetsSelectionChanged(QItemSelection,QItemSelection)));
}

QMessageBox::StandardButton ann_gui::TrainingSetDialog::askForLosingInformation()
{
	QMessageBox msg;
	msg.setWindowTitle(QString::fromLatin1("Conjunto de entranemiento en edición"));
	msg.setIcon(QMessageBox::Warning);
	msg.setText(QString::fromLatin1("Actualmente se encuentra en edición un conjunto de entrenamiento, ¿Desea perder esta información?"));
	msg.setStandardButtons(QMessageBox::Ok | QMessageBox::No);

	return (QMessageBox::StandardButton)msg.exec();
}

void ann_gui::TrainingSetDialog::beginOpenDialog()
{
	QString openDir = QFileDialog::getOpenFileName(this, //widget
												  "Abrir conjunto de entrenamiento", //caption
												  "/home/edixon/programacion/INSYDE/TrainingSets", //dir
												  "Conjunto de entrenamiento (*.tsf)", //filter
												  new QString("Conjunto de entrenamiento (*.tsf)"));

	if(openDir == "") return;

	TrainingSetFile::TSFResult tsFile = TrainingSetFile::fromFile(openDir);

	if(tsFile.errnum == TrainingSetFile::NoError){

		//Set the current file asociated to this TS
		currentFile = tsFile.file;

		//Se asigna el conjunto de entrenamiento
		setTrainingSet(tsFile.file->getTrainingSet());

	}else{
		mbLoadFileError.setText("Ha ocurrido un mientras se abria el archivo:\n\r" + openDir + "\n\r" + "Con el mensaje de error: " + tsFile.errormsg + ".");
		mbLoadFileError.exec();
	}
}

void ann_gui::TrainingSetDialog::importInputsClick()
{
	//TODO: corregir los errores
	QStringList files = QFileDialog::getOpenFileNames(this,
													 "Abrir archivo",
													 "INSYDEUI/imagenes",
													 "Conjuntos de entrenamiento (*.tsf);; Imagenes (*.bmp *.png *.jpg *.gif);; Archivos separados por comas (*.csv)",
													 new QString("Imagenes (*.bmp *.png *.jpg *.gif)"));

	importingInputs = true;
	tstInputs->blockSignals(true);
	foreach(QString file, files){
		imageFile = QImage(file);
		if(imageFile.isNull()){
			mbErrorLoadingImageMessage.setText("Ocurrio un error durante la carga de la imagen: " + file);
			mbErrorLoadingImageMessage.exec();
		}else{
			int nPixels = imageFile.width() * imageFile.height();
			if(nPixels > ts->getInputsSize()){
				if(mbImageSegmentMessage.checkBox()->checkState() != Qt::Checked){
					mbImageSegmentMessage.setText(QString::fromLatin1("El numero de pixeles que contiene la imagen " + file.toLatin1() + " es mayor que el numero de entradas que permite el conjunto de entrenamiento ¿Que desea hacer?\n\r"));
					mbImageSegmentMessage.exec();
				}else{
					onMessageBoxButtonClicked(lastButtonPressed);
				}
			}else{
				onMessageBoxButtonClicked(btnMsgBoxFirstPixels);
			}
		}
	}
	tstInputs->selectRow(ts->getPatternCount() - 1);
	tstInputs->blockSignals(false);
}

void ann_gui::TrainingSetDialog::importTargetsClick()
{
	//TODO: corregir los errores
	QStringList files = QFileDialog::getOpenFileNames(this,
													 "Abrir archivo",
													 "INSYDEUI/imagenes",
													 "Conjuntos de entrenamiento (*.tsf);; Imagenes (*.bmp *.png *.jpg *.gif);; Valores separados por comas (*.csv)",
													 new QString("Imagenes (*.bmp *.png *.jpg *.gif)"));

	tstTargets->blockSignals(true);

	importingInputs = false;
	foreach(QString file, files){
		imageFile = QImage(file);
		if(imageFile.isNull()){
			mbErrorLoadingImageMessage.setText("Ocurrio un error durante la carga de la imagen: " + file);
			mbErrorLoadingImageMessage.exec();
		}else{
			int nPixels = imageFile.width() * imageFile.height();
			if(nPixels > ts->getTargetsSize()){
				if(mbImageSegmentMessage.checkBox()->checkState() != Qt::Checked){
					mbImageSegmentMessage.setText(QString::fromLatin1("El numero de pixeles que contiene la imagen " + file.toLatin1() + " es mayor que el numero de salidas que permite el conjunto de entrenamiento ¿Que desea hacer?\n\r"));
					mbImageSegmentMessage.exec();
				}else{
					onMessageBoxButtonClicked(lastButtonPressed);
				}
			}else{
				onMessageBoxButtonClicked(btnMsgBoxFirstPixels);
			}
		}
	}
	tstTargets->blockSignals(false);
	tstTargets->selectRow(ts->getPatternCount() - 1);
}

void ann_gui::TrainingSetDialog::onMessageBoxButtonClicked(QAbstractButton *button)
{
	vector<long> longInputs;
	vector<double> result;

	if(button == btnMsgBoxFirstPixels){//En caso de que se decidan tomar los primeros pixeles
		longInputs = common::imageToIntVector(imageFile, common::NormalUnsigned);
		result = vector<double>(longInputs.begin(), longInputs.end());

		appendVector(result);
		lastButtonPressed = btnMsgBoxFirstPixels;

	}else if(button == btnMsgBoxImageSegment){//En caso de que se decida tomar un segmento de la imagen
		QSize size;
		if(importingInputs){
			size = ts->getInputsDataRepresentation()->getSize();
		}else{
			size = ts->getTargetsDataRepresentation()->getSize();
		}
		QRect selrect(imageFile.rect().center(), size);
		sisd = new SelectImageSegmentDialog(imageFile, selrect);

		if(importingInputs){
			connect(sisd->getIntegerSizeWidget(), SIGNAL(widthChanged(int)), SLOT(onInputsWidthChanged(int)));
			connect(sisd->getIntegerSizeWidget(), SIGNAL(heightChanged(int)), SLOT(onInputsHeightChanged(int)));
		}else{
			connect(sisd->getIntegerSizeWidget(), SIGNAL(widthChanged(int)), SLOT(onTargetsWidthChanged(int)));
			connect(sisd->getIntegerSizeWidget(), SIGNAL(heightChanged(int)), SLOT(onTargetsHeightChanged(int)));
		}

		if(sisd->exec() == QDialog::Accepted){
			longInputs = common::imageToIntVector(sisd->getImageSegment(), common::NormalUnsigned);
			result = vector<double>(longInputs.begin(), longInputs.end());

			appendVector(result);
		}
		delete sisd;
		lastButtonPressed = btnMsgBoxImageSegment;
	}else{
		mbImageSegmentMessage.checkBox()->setChecked(false);
		lastButtonPressed = btnCancel;
	}
}

void ann_gui::TrainingSetDialog::appendVector(const vector<double> &vec)
{
	if(importingInputs){
		tstTargets->clearSelection();
		ts->appendPattern(vec, vector<double>(ts->getTargetsSize(), 0));
	}else{
		tstInputs->clearSelection();
		ts->appendPattern(vector<double>(ts->getInputsSize(), 0), vec);
	}
	isEditingTS = true;
}

void ann_gui::TrainingSetDialog::saveClick()
{
	QString path = QFileDialog::getSaveFileName(this,
												"Guardar conjunto de entrenamiento",
												"",
												"Conjunto de entrenamiento (*.tsf);; Valores separados por comas (*.csv)",
												new QString("Conjunto de entrenamiento (*.tsf)"));
	if(path != ""){
		TrainingSetFile tsf(ts, path);

		if(tsf.open(QIODevice::OpenModeFlag::ReadWrite)){

		   if(!tsf.flush()){
			   //TODO: 25/4/16 saveClick should validate flushing. Currently always returns true but must be evaluated
			   //if some problems are experimented during flushing

			   QMessageBox msg;
			   msg.setText(tr("Ocurrio un error al guardar"));
			   msg.setInformativeText(tr("Ocurrio un error desconocido mientras se guardaba el archivo. \nPor favor intente de nuevo."));
			   msg.setWindowTitle(tr("Error"));
			   msg.setIcon(QMessageBox::Critical);

			   msg.exec();
		   }
		}else{
			QMessageBox msg;
			msg.setText(QString::fromLatin1("Ocurrio un error al guardar"));
			msg.setInformativeText("Ocurrio un error desconocido mientras se guardaba el archivo. \nPor favor intente de nuevo.");
			msg.setWindowTitle("Error");
			msg.setIcon(QMessageBox::Critical);

			msg.exec();
		}
	}
}

void ann_gui::TrainingSetDialog::saveAsClick()
{
	//TODO: 26/4/16 saveAsClick implement
}

void ann_gui::TrainingSetDialog::onInputChanged(int pat, int index, double value, double curValue)
{
	(void)index; (void)value; (void)curValue;
	gbInputsRepresentation->setInputs(ts->getInputs()[pat]);
	isEditingTS = true;
}

void ann_gui::TrainingSetDialog::onTargetChanged(int pat, int index, double value, double curValue)
{
	(void)index; (void)value; (void)curValue;
	gbTargetsRepresentation->setInputs(ts->getTargets()[pat]);
	isEditingTS = true;
}

void ann_gui::TrainingSetDialog::onTstInputsSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
	(void) deselected;
	if(selected.isEmpty()){
		if(!tstTargets->hasFocus()){
			delPatternButton->setEnabled(false);
		}
	}else{
		gbInputsRepresentation->setInputs(ts->getInputs()[selected.indexes().at(0).row()]);

		delPatternButton->setEnabled(true);
	}
}

void ann_gui::TrainingSetDialog::onTstTargetsSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
	(void) deselected;
	if(selected.isEmpty()){
		if(!tstInputs->hasFocus()){
			delPatternButton->setEnabled(false);
		}
	}else{
		gbTargetsRepresentation->setInputs(ts->getTargets()[selected.indexes().at(0).row()]);
		delPatternButton->setEnabled(true);
	}
}

void ann_gui::TrainingSetDialog::openClick()
{
	if(isEditingTS){
		if(askForLosingInformation() == QMessageBox::Ok){
			isEditingTS = false;
			beginOpenDialog();
		}
	}else{
		beginOpenDialog();
	}
}

void ann_gui::TrainingSetDialog::copyClick()
{
	if(tstInputs->hasFocus()){
		tstInputs->copyClick();
	}else if(tstTargets->hasFocus()){
		tstTargets->copyClick();
	}
}

void ann_gui::TrainingSetDialog::pasteClick()
{
	if(tstInputs->hasFocus()){
		tstInputs->pasteClick();
	}else if(tstTargets->hasFocus()){
		tstTargets->pasteClick();
	}
	isEditingTS = true;
}

void ann_gui::TrainingSetDialog::newClick()
{
	if(isEditingTS){
		if(askForLosingInformation() == QMessageBox::Ok){
			setTrainingSet(new TrainingSet(ts->getInputsSize(), ts->getTargetsSize()));
			isEditingTS = false;
		}
	}
}

void ann_gui::TrainingSetDialog::importFromDBClick()
{
	DatabaseConnectionDialog *dbConnectDialog = new DatabaseConnectionDialog();

	QSqlDatabase dbase = dbConnectDialog->getDatabase();
//	 db;

	if(dbase.isOpen()){
		QString table;

		DatabaseMapperDialog *dbmapdialog = new DatabaseMapperDialog(dbase);

		if(dbmapdialog->exec()){
			QMap<QString, QString> map = dbmapdialog->getMap();
			TrainingSetSQL *sqlTS = new TrainingSetSQL(table, map, dbase);
		}

	}

	qDebug() << tr("Error while opening database");
	return;

//	QSqlTableModel *sqlModel = new QSqlTableModel(this, database);

//	sqlModel->setTable(table);
//	sqlModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
}

void ann_gui::TrainingSetDialog::importTrainingSetClick()
{
	//TODO: 6/4/15 importTrainingSetClicked must be implemented
}
