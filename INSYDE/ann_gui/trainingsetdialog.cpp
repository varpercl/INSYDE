#include "trainingsetdialog.h"

TrainingSetDialog::TrainingSetDialog(TrainingSet *ts, QWidget *parent):
	BasicDialog(parent)
{
	init(ts);
}

TrainingSetDialog::TrainingSetDialog(int inputCount, int targetCount, int nPatterns, QWidget *parent) :
	BasicDialog(parent)
{
	init(new TrainingSet(vector<vector<double> >(nPatterns, vector<double>(inputCount, 0)),
						 inputCount,
						 vector<vector<double> >(nPatterns, vector<double>(targetCount, 0)),
						 targetCount));
}

TrainingSetDialog::TrainingSetDialog(const vector<vector<double> > &inputs, int is, const vector<vector<double> > &targets, int ts, QWidget *parent) :
	BasicDialog(parent)
{
	init(new TrainingSet(inputs, is, targets, ts));
}

TrainingSetDialog::~TrainingSetDialog()
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

void TrainingSetDialog::setTrainingSet(TrainingSet *ts)
{
	if(this->ts != ts){
		this->ts = ts;

		tstInputs->setTrainingSet(ts);

		tstTargets->setTrainingSet(ts);

		connectTrainingSetSignals();
	}
}

TrainingSet *TrainingSetDialog::getTrainingSet() const
{
	return ts;
}

void TrainingSetDialog::onInputsCellClicked(const QModelIndex &index)
{
	(void)index;
	getCutAction()->setEnabled(tstInputs->getCutAction()->isEnabled());
	tstTargets->clearSelection();
}

void TrainingSetDialog::onTargetsCellClicked(const QModelIndex &index)
{
	(void)index;
	getCutAction()->setEnabled(tstTargets->getCutAction()->isEnabled());
	tstInputs->clearSelection();
}

void TrainingSetDialog::onInputsWidthChanged(int width)
{
	ts->getInputsDataRepresentation()->setWidth(width);
}

void TrainingSetDialog::onInputsHeightChanged(int height)
{
	ts->getInputsDataRepresentation()->setHeight(height);
}

void TrainingSetDialog::onTargetsWidthChanged(int width)
{
	ts->getTargetsDataRepresentation()->setWidth(width);
}

void TrainingSetDialog::onTargetsHeightChanged(int height)
{
	ts->getTargetsDataRepresentation()->setHeight(height);
}

void TrainingSetDialog::on_addPatternButton_clicked()
{
	ts->appendPattern();
}

void TrainingSetDialog::on_delPatternButton_clicked()
{
	if(tstInputs->hasFocus()){
		ts->removePattern(tstInputs->currentIndex().row());
	}else if(tstTargets->hasFocus()){
		ts->removePattern(tstTargets->currentIndex().row());
	}
}


void TrainingSetDialog::init(TrainingSet *ts)
{
	const double
			minRange = 100;

	this->ts = ts;

	mainLayout = new QVBoxLayout();

	gridLayout = new QGridLayout();

	QMenu *importMenu = new QMenu("Importar");
	importMenu->addAction(ICON_IMPORT, "Entradas...", this, SLOT(importInputsClick()));
	importMenu->addAction(ICON_IMPORT, "Salidas...", this, SLOT(importTargetsClick()));
	importMenu->addAction(ICON_IMPORT, "Conjunto de entrenamiento...", this, SLOT(importTrainingSetClick()));

	getImportAction()->setMenu(importMenu);

	addPatternButton = new QToolButton();
	addPatternButton->setIcon(ICON_PLUS);
	addPatternButton->setPopupMode(QToolButton::MenuButtonPopup);
	addPatternButton->setMenu(importMenu);

	delPatternButton = new QToolButton();
	delPatternButton->setIcon(ICON_MINUS);

	mainToolBar = new QToolBar();
	mainToolBar->addWidget(addPatternButton);
	mainToolBar->addWidget(delPatternButton);

	inw = new NormalizationWidget(this->ts->getInputsNormalization(), QString::fromLatin1("Normalización de entradas"));

	inw->setMinValueMaximum(minRange);
	inw->setMinValueMinimum(-minRange);
	inw->setMaxValueMaximum(minRange);
	inw->setMaxValueMinimum(-minRange);
	inw->setThresholdValueMaximum(minRange);
	inw->setThresholdValueMinimum(-minRange);

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
	gbInputsRepresentation->setTitle("Patron de entrada");

	gbTargetsRepresentation = new DataRepresentationBox(vector<double>(), this->ts->getTargetsDataRepresentation());
	gbTargetsRepresentation->setTitle("Patron de salida");

	gridLayout->addWidget(inw, 0, 0);
	gridLayout->addWidget(tnw, 0, 1);
	gridLayout->addWidget(tstInputs, 1, 0);
	gridLayout->addWidget(tstTargets, 1, 1);
	gridLayout->addWidget(gbInputsRepresentation, 2, 0);
	gridLayout->addWidget(gbTargetsRepresentation, 2, 1);

	mainLayout->addWidget(mainToolBar);
	mainLayout->addLayout(gridLayout);

	//TODO: implementar UNDO
	setEnableUnDoFramework(false);

	getAboutAction()->setVisible(false);
	getCutAction()->setEnabled(false);

	getMainWindow()->centralWidget()->setLayout(mainLayout);

	initMsgBoxes();

	connectTrainingSetSignals();

	connect(addPatternButton, SIGNAL(clicked()), SLOT(on_addPatternButton_clicked()));
	connect(delPatternButton, SIGNAL(clicked()), SLOT(on_delPatternButton_clicked()));
	connect(tstInputs, SIGNAL(clicked(QModelIndex)), SLOT(onInputsCellClicked(QModelIndex)));
	connect(tstTargets, SIGNAL(clicked(QModelIndex)), SLOT(onTargetsCellClicked(QModelIndex)));

}

void TrainingSetDialog::initMsgBoxes()
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

void TrainingSetDialog::connectTrainingSetSignals()
{
	connect(this->ts, SIGNAL(inputChanged(int,int,double,double)), this, SLOT(onInputChanged(int,int,double,double)));
	connect(this->ts, SIGNAL(targetChanged(int,int,double,double)), this, SLOT(onTargetChanged(int,int,double,double)));

	connect(tstInputs->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), SLOT(onTstInputsSelectionChanged(QItemSelection,QItemSelection)));
	connect(tstTargets->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), SLOT(onTstTargetsSelectionChanged(QItemSelection,QItemSelection)));
}

void TrainingSetDialog::importInputsClick()
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

void TrainingSetDialog::importTargetsClick()
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

void TrainingSetDialog::onMessageBoxButtonClicked(QAbstractButton *button)
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

void TrainingSetDialog::appendVector(const vector<double> &vec)
{
	if(importingInputs){
		tstTargets->clearSelection();
		ts->appendPattern(vec, vector<double>(ts->getTargetsSize(), 0));
	}else{
		tstInputs->clearSelection();
		ts->appendPattern(vector<double>(ts->getInputsSize(), 0), vec);
	}
}

void TrainingSetDialog::saveClick()
{
	QString path = QFileDialog::getSaveFileName(this,
												"Guardar conjunto de entrenamiento",
												"",
												"Conjunto de entrenamiento (*.tsf);; Valores separados por comas (*.csv)",
												new QString("Conjunto de entrenamiento (*.tsf)"));
	if(path != ""){
		TrainingSetFile tsf(ts, path);

		if(!tsf.flush()){
			QMessageBox msg;
			msg.setText(QString::fromLatin1("Ocurrio un error al guardar"));
			msg.setInformativeText("Ocurrio un error desconocido mientras se guardaba el archivo. \nPor favor intente de nuevo.");
			msg.setWindowTitle("Error");
			msg.setIcon(QMessageBox::Critical);
		}
	}
}

void TrainingSetDialog::onInputChanged(int pat, int index, double value, double curValue)
{
	(void)index; (void)value; (void)curValue;
	gbInputsRepresentation->setInputs(ts->getInputs()[pat]);
}

void TrainingSetDialog::onTargetChanged(int pat, int index, double value, double curValue)
{
	(void)index; (void)value; (void)curValue;
	gbTargetsRepresentation->setInputs(ts->getTargets()[pat]);
}

void TrainingSetDialog::onTstInputsSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
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

void TrainingSetDialog::onTstTargetsSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
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

void TrainingSetDialog::openClick()
{
	QString openDir = QFileDialog::getOpenFileName(this, //widget
												  "Abrir conjunto de entrenamiento", //caption
												  "/home/edixon/programacion/INSYDE/TrainingSets", //dir
												  "Conjunto de entrenamiento (*.tsf)", //filter
												  new QString("Conjunto de entrenamiento (*.tsf)"));

	if(openDir == "") return;

	TrainingSetFile::TSFResult tsFile = TrainingSetFile::fromFile(openDir);

	if(tsFile.errnum == TrainingSetFile::NoError){

		//Se asigna el conjunto de entrenamiento
		setTrainingSet(tsFile.ts);

		//Se asigna el tipo de normalizacion
		inw->setNormalization(ts->getInputsNormalization());
		tnw->setNormalization(ts->getTargetsNormalization());

		//Se asignan las representaciones
		gbInputsRepresentation->setDataRepresentation(ts->getInputsDataRepresentation());
		gbTargetsRepresentation->setDataRepresentation(ts->getTargetsDataRepresentation());

	}else{
		mbLoadFileError.setText("Ha ocurrido un error durante la lectura del archivo:\n\r" + openDir + "\n\r" + "Con el mensaje de error: " + tsFile.errormsg + ".");
		mbLoadFileError.exec();
	}
}

void TrainingSetDialog::copyClick()
{
	if(tstInputs->hasFocus()){
		tstInputs->copyClick();
	}else if(tstTargets->hasFocus()){
		tstTargets->copyClick();
	}
}

void TrainingSetDialog::pasteClick()
{
	if(tstInputs->hasFocus()){
		tstInputs->pasteClick();
	}else if(tstTargets->hasFocus()){
		tstTargets->pasteClick();
	}
}

void TrainingSetDialog::newClick()
{
	//TODO: newClick must be implemented
}

void TrainingSetDialog::importTrainingSetClick()
{
	//TODO: importTrainingSetClicked must be implemented
}
