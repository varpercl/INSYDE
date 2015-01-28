#include "trainingsetdialog.h"

TrainingSetDialog::TrainingSetDialog(TrainingSet *ts, QWidget *parent):
	QDialog(parent)
{
	init(ts->getInputs(), ts->getInputsSize(), ts->getTargets(), ts->getTargetsSize());
}

TrainingSetDialog::TrainingSetDialog(int inputCount, int targetCount, int nPatterns, QWidget *parent) :
	QDialog(parent)
{
	init(vector<vector<double> >(nPatterns, vector<double>(inputCount, 0)), inputCount, vector<vector<double> >(nPatterns, vector<double>(targetCount, 0)), targetCount);
}

TrainingSetDialog::TrainingSetDialog(const vector<vector<double> > &inputs, int is, const vector<vector<double> > &targets, int ts, QWidget *parent) :
	QDialog(parent)
{
	init(inputs, is, targets, ts);
}

TrainingSetDialog::TrainingSetDialog(vector<MultilayerPerceptronPattern *> ts, QWidget *parent) :
	QDialog(parent)
{
	//TODO: se debe implementar este constructor
	//	tsCopy = new TrainingSet(ts);
	init(ts);
}//TrainingSetDialog

TrainingSetDialog::~TrainingSetDialog()
{
	delete addPatternMenu;
	delete file;
	delete btnMsgBoxFirstPixels;
	delete btnMsgBoxImageSegment;
	delete btnCancel;
	delete hlRepresentation;
	delete gbGraphicTargetsRepresentation;
	delete gbGraphicInputsRepresentation;
	delete mainSubHorizontalLayout;
	delete inputsPatternToolbar;
	delete addPatternButton;
	delete delPatternButton;
	delete tstInputs;
	delete buttonBox;
	//FIXME: SIGSEV cuando cierro la ventana sin hacer nada
//	delete imgRepresentation;
	delete dmRepresentation;
	delete fileDialog;
	delete menuBar;
}//~TrainingSetDialog

void TrainingSetDialog::setTrainingSetTable(TrainingSetTable *tst)
{
	tstInputs = tst;
}

TrainingSetTable *TrainingSetDialog::getTrainingSetTable() const
{
	return tstInputs;
}

TrainingSet *TrainingSetDialog::getTrainingSet() const
{
	return ts;
}

void TrainingSetDialog::onInputsNormalizationTypeChanged(Normalization nt)
{
	double
			dblInputsThreshold = 0,
			dblInputsMinValue = 0,
			dblInputsMaxValue = 0;

	switch(nt.getType()){
		case Normalization::Nothing:
			ts->normalizeInputsNothing();
			break;
		case Normalization::BipolarFixedThreshold:{
			ts->normalizeInputsBipolarFixedThreshold(inw->getThresholdValue());
			break;
		}
		case Normalization::BipolarAutoThreshold:{
			ts->normalizeInputsBipolarAutoThreshold(&dblInputsThreshold);
			inw->setThresholdValue(dblInputsThreshold);
			break;
		}
		case Normalization::UnipolarFixedThreshold:{
			ts->normalizeInputsUnipolarFixedThreshold(inw->getThresholdValue());
			break;
		}
		case Normalization::UnipolarAutoThreshold:{
			ts->normalizeInputsUnipolarAutoThreshold(&dblInputsThreshold);
			inw->setThresholdValue(dblInputsThreshold);
			break;
		}
		case Normalization::LinearFixedRange:{
			ts->normalizeInputsLinearFixedRange(inw->getMinValue(), inw->getMaxValue());
			break;
		}
		case Normalization::LinearAutoRange:{
			ts->normalizeInputsLinearAutoRange(&dblInputsMinValue, &dblInputsMaxValue);
			inw->setMinValue(dblInputsMinValue);
			inw->setMaxValue(dblInputsMaxValue);
			break;
		}
		case Normalization::Tanh:{
			ts->normalizeInputsTanh(inw->getAmplitudeValue(), inw->getElongationValue());
			break;
		}
		case Normalization::Sigmoid:{
			ts->normalizeInputsSigmoid(inw->getAmplitudeValue(), inw->getElongationValue());
			break;
		}
		case Normalization::MeanDistance:
			ts->normalizeInputsMeanDistance();
			break;
	}
}

void TrainingSetDialog::onTargetsNormalizationTypeChanged(Normalization nt)
{
	switch(nt.getType()){
		case Normalization::Nothing:
			ts->normalizeTargetsNothing();
			break;
		case Normalization::Tanh:{
			ts->normalizeTargetsTanh(tnw->getAmplitudeValue(), tnw->getElongationValue());
			break;
		}
		case Normalization::Sigmoid:{
			ts->normalizeTargetsSigmoid(tnw->getAmplitudeValue(), tnw->getElongationValue());
			break;
		}
		case Normalization::BipolarFixedThreshold:
		case Normalization::BipolarAutoThreshold:
		case Normalization::UnipolarFixedThreshold:
		case Normalization::UnipolarAutoThreshold:
		case Normalization::LinearFixedRange:
		case Normalization::LinearAutoRange:
		case Normalization::MeanDistance:
		default:
			break;
	}
}

void TrainingSetDialog::onInputsCellClicked(const QModelIndex &index)
{
	(void)index;
	tstTargets->clearSelection();
}

void TrainingSetDialog::onTargetsCellClicked(const QModelIndex &index)
{
	(void)index;
	tstInputs->clearSelection();
}

void TrainingSetDialog::onInputsAmplitudeChanged(double val)
{
	(void)val;
	tnInputsAmplitude.start();
}

void TrainingSetDialog::onInputsAmplitudeTimed()
{
	onInputsNormalizationTypeChanged(inw->getNormalization());
}

void TrainingSetDialog::onInputsElongationChanged(double val)
{
	(void)val;
	tnInputsElongation.start();
}

void TrainingSetDialog::onInputsElongationTimed()
{
	onInputsNormalizationTypeChanged(inw->getNormalization());
}

void TrainingSetDialog::onInputsThresholdChanged(double val)
{
	(void)val;
//	dblInputsThreshold = val;
	tnInputsThreshold.start();
}

void TrainingSetDialog::onInputsThresholdTimed()
{
	onInputsNormalizationTypeChanged(inw->getNormalization());
}

void TrainingSetDialog::onInputsMinValueChanged(double val)
{
	(void)val;
//	dblInputsMinValue = val;
	tnInputsMinValue.start();
}

void TrainingSetDialog::onInputsMinValueTimed()
{
	onInputsNormalizationTypeChanged(inw->getNormalization());
}

void TrainingSetDialog::onInputsMaxValueChanged(double val)
{
	(void)val;
//	dblInputsMaxValue = val;
	tnInputsMaxValue.start();
}

void TrainingSetDialog::onInputsMaxValueTimed()
{
	onInputsNormalizationTypeChanged(inw->getNormalization());
}

void TrainingSetDialog::onTargetsAmplitudeChanged(double val)
{
	(void)val;
	tnTargetsAmplitude.start();
}

void TrainingSetDialog::onTargetsAmplitudeTimed()
{
	onTargetsNormalizationTypeChanged(tnw->getNormalization());
}

void TrainingSetDialog::onTargetsElongationChanged(double val)
{
	(void)val;
	tnTargetsElongation.start();
}

void TrainingSetDialog::onTargetsElongationTimed()
{
	onTargetsNormalizationTypeChanged(tnw->getNormalization());
}

void TrainingSetDialog::onTargetsThresholdChanged(double val)
{
	(void)val;
//	dblTargetsThreshold = val;
	tnTargetsThreshold.start();
}

void TrainingSetDialog::onTargetsThresholdTimed()
{
	onTargetsNormalizationTypeChanged(tnw->getNormalization());
}

void TrainingSetDialog::onTargetsMinValueChanged(double val)
{
	(void)val;
//	dblTargetsMinValue = val;
	tnTargetsMinValue.start();
}

void TrainingSetDialog::onTargetsMinValueTimed()
{
	onTargetsNormalizationTypeChanged(tnw->getNormalization());
}

void TrainingSetDialog::onTargetsMaxValueChanged(double val)
{
	(void)val;
//	dblTargetsMaxValue = val;
	tnTargetsMaxValue.start();
}

void TrainingSetDialog::onTargetsMaxValueTimed()
{
	onTargetsNormalizationTypeChanged(tnw->getNormalization());
}

void TrainingSetDialog::onInputsWidthChanged(int width)
{
	((ImageRepresentationWidget*)gbGraphicInputsRepresentation->getRepresentationWidget())->getIntegerSizeWidget()->setWidth(width);
}

void TrainingSetDialog::onInputsHeightChanged(int height)
{
	((ImageRepresentationWidget*)gbGraphicInputsRepresentation->getRepresentationWidget())->getIntegerSizeWidget()->setHeight(height);
}

void TrainingSetDialog::onTargetsWidthChanged(int width)
{
	((ImageRepresentationWidget*)gbGraphicTargetsRepresentation->getRepresentationWidget())->getIntegerSizeWidget()->setWidth(width);
}

void TrainingSetDialog::onTargetsHeightChanged(int height)
{
	((ImageRepresentationWidget*)gbGraphicTargetsRepresentation->getRepresentationWidget())->getIntegerSizeWidget()->setHeight(height);
}

void TrainingSetDialog::on_addPatternButton_clicked()
{
	ts->appendPattern();
}//on_addPatternButton_clicked

void TrainingSetDialog::on_delPatternButton_clicked()
{
	//TODO: implementar
//	ts->removePattern(curRow);

}//on_delPatternButton_clicked

/*!
 * \brief TrainingSetDialog::onIgnoreAlphaChannelToogled
 *
 * FIXME: se debe corregir este metodo para que inhiba el canal alfa sin que
 * se pierdan los datos y luego se puedan volver a recuperar
 */
void TrainingSetDialog::onIgnoreAlphaChannelToogled(bool)
{
	//TODO: implementar
//	QTableWidgetItem *itm;

//	//	int nPat = getPatternCount();
//	//	int sInputs = getInputSize();
//	TrainingSet *tempTS = tstInputs->getTrainingSet();
//	int nPat = tempTS->getPatternCount();
//	int sInputs = tempTS->getInputsSize();
//	for(int i = 0; i < nPat; i++){
//		for(int j = 0; j < sInputs; j++){
//			itm = new QTableWidgetItem(QString::number(tstInputs->item(i,j)->text().toInt() | 0xff000000));
//			tstInputs->setItem(i, j, itm);
//		}
//	}
}//onIgnoreAlphaChannelToogled

void TrainingSetDialog::init(const vector<vector<double> > &inputs, int is, const vector<vector<double> > &targets, int ts)
{
	const int tUpdateInterval = 1000; //milliseconds

	this->ts = new TrainingSet(inputs, is, targets, ts);

	setupUi(this->ts, this);
	initMsgBoxes();

	fileDialog = new QFileDialog(this);

//	QMenu *file = new QMenu(tr("Archivo"));
//	file->addAction("Desde archivo...", this, SLOT(onImportInputs()));
//	file->addAction("Desde imagenes...", this, SLOT(onImportTargets()));

//	menuBar = new QMenuBar(this);
//	menuBar->addMenu(file);
//	layout()->setMenuBar(menuBar);

	gbGraphicInputsRepresentation->setDataInput(inputs[0]);
	gbGraphicTargetsRepresentation->setDataInput(targets[0]);

	tnInputsAmplitude.setSingleShot(true);
	tnInputsAmplitude.setInterval(tUpdateInterval);

	tnInputsElongation.setSingleShot(true);
	tnInputsElongation.setInterval(tUpdateInterval);

	tnInputsThreshold.setSingleShot(true);
	tnInputsThreshold.setInterval(tUpdateInterval);

	tnInputsMinValue.setSingleShot(true);
	tnInputsMinValue.setInterval(tUpdateInterval);

	tnInputsMaxValue.setSingleShot(true);
	tnInputsMaxValue.setInterval(tUpdateInterval);

	tnTargetsAmplitude.setSingleShot(true);
	tnTargetsAmplitude.setInterval(tUpdateInterval);

	tnTargetsElongation.setSingleShot(true);
	tnTargetsElongation.setInterval(tUpdateInterval);

	tnTargetsThreshold.setSingleShot(true);
	tnTargetsThreshold.setInterval(tUpdateInterval);

	tnTargetsMinValue.setSingleShot(true);
	tnTargetsMinValue.setInterval(tUpdateInterval);

	tnTargetsMaxValue.setSingleShot(true);
	tnTargetsMaxValue.setInterval(tUpdateInterval);


}//initDialog

void TrainingSetDialog::init(const vector<MultilayerPerceptronPattern*> ts)
{
	//TODO: implementar el metodo con patrones para cada tipo de red neuronal
	(void)ts;
	//	setupUi(ts[0]. this);

	//	fileDialog = new QFileDialog(this);

	//	QMenu *file = new QMenu(tr("Archivo"));
	//	file->addAction("Desde archivo...", this, SLOT(fromFile()));
	//	file->addAction("Desde imagenes...", this, SLOT(fromImages()));

	//	menuBar = new QMenuBar(this);
	//	menuBar->addMenu(file);
	//	layout()->setMenuBar(menuBar);

	//	const int nPatterns = ts.size();

	//	//	setInputSize(inputs[0].size());
	//	//	setTargetSize(targets[0].size());
	//	for(int i = 0; i < nPatterns; i++){
	//		appendPattern(ts[i]->getInputs(), ts[i]->getTargets());
	//	}
}//initDialog

void TrainingSetDialog::initMsgBoxes()
{
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
}//initMsgBoxes

void TrainingSetDialog::updateRepresentation(int row)
{
	if(row >= 0 && row < ts->getPatternCount()){
		gbGraphicInputsRepresentation->setDataInput(ts->getInputs()[row]);

		gbGraphicTargetsRepresentation->setDataInput(ts->getTargets()[row]);
	}
}//updateRepresentation

void TrainingSetDialog::onImportInputs()
{
	//TODO: corregir los errores
//	QStringList files = fileDialog->getOpenFileNames(this,
//													 "Abrir archivo",
//													 "INSYDEUI/imagenes",
//													 "Conjuntos de entrenamiento (*.tsf);; Imagenes (*.bmp *.png *.jpg *.gif);; Archivos separados por comas (*.csv)");

//	TrainingSet *tempTS = tstInputs->getTrainingSet();

//	importingInputs = true;
//	tstInputs->blockSignals(true);
//	foreach(QString file, files){
//		imageFile = QImage(file);
//		if(imageFile.isNull()){
//			mbErrorLoadingImageMessage.setText("Ocurrio un error durante la carga de la imagen: " + file);
//			mbErrorLoadingImageMessage.exec();
//		}else{
//			int nPixels = imageFile.width() * imageFile.height();
//			if(nPixels > tempTS->getInputsSize()){
//				if(mbImageSegmentMessage.checkBox()->checkState() != Qt::Checked){
//					mbImageSegmentMessage.setText(QString::fromLatin1("El numero de pixeles que contiene la imagen " + file.toLatin1() + " es mayor que el numero de entradas que permite el conjunto de entrenamiento ¿Que desea hacer?\n\r"));
//					mbImageSegmentMessage.exec();
//				}else{
//					onMessageBoxButtonClicked(lastButtonPressed);
//				}
//			}else{
//				onMessageBoxButtonClicked(btnMsgBoxFirstPixels);
//			}
//		}
//	}
//	tstInputs->setCurrentCell(tstInputs->rowCount()-1, 0);
//	tstInputs->blockSignals(false);
}//onImportInputs

void TrainingSetDialog::onImportTargets()
{
	//TODO: corregir los errores
//	QStringList files = fileDialog->getOpenFileNames(this,
//													 "Abrir archivo",
//													 "INSYDEUI/imagenes",
//													 "Conjuntos de entrenamiento (*.tsf);; Imagenes (*.bmp *.png *.jpg *.gif);; Valores separados por comas (*.csv)");

//	TrainingSet *tempTS = tstTargets->getTrainingSet();

//	tstTargets->blockSignals(true);

//	importingInputs = false;
//	foreach(QString file, files){
//		imageFile = QImage(file);
//		if(imageFile.isNull()){
//			mbErrorLoadingImageMessage.setText("Ocurrio un error durante la carga de la imagen: " + file);
//			mbErrorLoadingImageMessage.exec();
//		}else{
//			int nPixels = imageFile.width() * imageFile.height();
//			if(nPixels > tempTS->getTargetsSize()){
//				if(mbImageSegmentMessage.checkBox()->checkState() != Qt::Checked){
//					mbImageSegmentMessage.setText(QString::fromLatin1("El numero de pixeles que contiene la imagen " + file.toLatin1() + " es mayor que el numero de salidas que permite el conjunto de entrenamiento ¿Que desea hacer?\n\r"));
//					mbImageSegmentMessage.exec();
//				}else{
//					onMessageBoxButtonClicked(lastButtonPressed);
//				}
//			}else{
//				onMessageBoxButtonClicked(btnMsgBoxFirstPixels);
//			}
//		}
//	}
//	tstTargets->setCurrentCell(tstTargets->rowCount() - 1, 0);
//	tstTargets->blockSignals(false);
}//onImportTargets

void TrainingSetDialog::onInputsTableActivated(const QModelIndex &index)
{
	updateRepresentation(index.row());
}

void TrainingSetDialog::onTargetsTableActivated(const QModelIndex &index)
{
	updateRepresentation(index.row());
}

void TrainingSetDialog::onMessageBoxButtonClicked(QAbstractButton *button)
{
//	int tSize = ts->getTargetSize();
//	int iSize = ts->getInputSize();
	vector<long> longInputs;
	vector<double> result;
//	TrainingSet *tempTS = tstInputs->getTrainingSet();

	if(button == btnMsgBoxFirstPixels){//En caso de que se decidan tomar los primeros pixeles
		longInputs = CommonFunctions::imageToIntVector(imageFile, CommonFunctions::NormalUnsigned);
		result = vector<double>(longInputs.begin(), longInputs.end());

//		if(importingInputs){
//			if(tempTS != ts){
//				tempTS->appendPattern(result, vector<double>(tSize, 0));
//			}
//			ts->appendPattern(result, vector<double>(tSize, 0));
//		}else{
//			if(tempTS != ts){
//				tempTS->appendPattern(vector<double>(iSize, 0), result);
//			}
//			ts->appendPattern(vector<double>(iSize, 0), result);

//		}

		appendVector(result);
		lastButtonPressed = btnMsgBoxFirstPixels;

	}else if(button == btnMsgBoxImageSegment){//En caso de que se decidan tomar un segmento de la imagen
		QSize size;
		if(importingInputs){
			size = ((ImageRepresentationWidget*)gbGraphicInputsRepresentation->getRepresentationWidget())->getIntegerSizeWidget()->getSizeValue();
		}else{
			size = ((ImageRepresentationWidget*)gbGraphicTargetsRepresentation->getRepresentationWidget())->getIntegerSizeWidget()->getSizeValue();
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
			longInputs = CommonFunctions::imageToIntVector(sisd->getImageSegment(), CommonFunctions::NormalUnsigned);
			result = vector<double>(longInputs.begin(), longInputs.end());
//			if(tempTS != ts){
//				tempTS->appendPattern(result, vector<double>(tSize, 0));
//			}
//			ts->appendPattern(result, vector<double>(tSize, 0));
			appendVector(result);
		}
		delete sisd;
		lastButtonPressed = btnMsgBoxImageSegment;
	}else{
		mbImageSegmentMessage.checkBox()->setChecked(false);
		lastButtonPressed = btnCancel;
	}
}//onMessageBoxButtonClicked

void TrainingSetDialog::setupUi(TrainingSet *ts, QWidget *TrainingSetDialog)
{
	if (TrainingSetDialog->objectName().isEmpty())
		TrainingSetDialog->setObjectName(QString::fromUtf8("TrainingSetDialog"));

	TrainingSetDialog->setWindowFlags(Qt::Window);
	TrainingSetDialog->setMinimumWidth(800);

	mainVerticalLayout = new QVBoxLayout(TrainingSetDialog);
	mainVerticalLayout->setObjectName(QString::fromUtf8("mainVerticalLayout"));
	mainSubHorizontalLayout = new QGridLayout();
	mainSubHorizontalLayout->setColumnMinimumWidth(0, 300);
	mainSubHorizontalLayout->setColumnStretch(0, 200);
	mainSubHorizontalLayout->setColumnMinimumWidth(1, 300);
	mainSubHorizontalLayout->setColumnStretch(1, 200);
	mainSubHorizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
//	mainSubHorizontalLayout->

	inputsPatternToolbar = new QHBoxLayout();
	inputsPatternToolbar->setObjectName(QString::fromUtf8("horizontalLayout"));
	hlRepresentation = new QHBoxLayout();
	hlRepresentation->setObjectName(QString::fromUtf8("hlRepresentation"));
	inputsVerticalLayout = new QVBoxLayout();
	inputsVerticalLayout->setObjectName(QString::fromUtf8("inputsVerticalLayout"));
	targetsVerticalLayout = new QVBoxLayout();
	targetsVerticalLayout->setObjectName(QString::fromUtf8("targetsVerticalLayout"));

	horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

	inputsPatternToolbar->addItem(horizontalSpacer);

	file = new QMenu(tr("Archivo"));
	file->addAction(QIcon(":/images/Images/open-file-icon.png"), "Abrir conjunto de entrenamiento...", this, SLOT(onOpenTrainingSet()));
	file->addAction(QIcon(":/images/Images/Save-icon.png"), "Guardar conjunto de entrenamiento...", this, SLOT(onSaveTrainingSet()));
	file->addSeparator();
	file->addAction("Importar entradas...", this, SLOT(onImportInputs()));
	file->addAction("Importar salidas...", this, SLOT(onImportTargets()));
	file->addAction(QIcon(":/images/Images/import-icon.png"), "Importar conjunto de entrenamiento...", this, SLOT(onImportTrainingSet()));

	menuBar = new QMenuBar(TrainingSetDialog);
	menuBar->setObjectName(QString::fromUtf8("menuBar"));
	menuBar->addMenu(file);
//	menuBar->setMaximumHeight(15);
	layout()->setMenuBar(menuBar);

	addPatternMenu = new QMenu(QString::fromLatin1("Agregar patrón"));
	addPatternMenu->setObjectName(QString::fromUtf8("addPatternMenu"));
	addPatternMenu->addAction("Importar entradas...", this, SLOT(onImportInputs()));
	addPatternMenu->addAction("Importar salidas...", this, SLOT(onImportTargets()));

	addPatternButton = new QToolButton(TrainingSetDialog);
	addPatternButton->setObjectName(QString::fromUtf8("addPatternButton"));
	addPatternButton->setIcon(QIcon(QString::fromUtf8(":/imagenes/plus_icon.png")));
	addPatternButton->setIconSize(QSize(20, 20));
	addPatternButton->setPopupMode(QToolButton::MenuButtonPopup);
	addPatternButton->setAutoRaise(true);
	addPatternButton->setMenu(addPatternMenu);

//	inputsVerticalLayout->addWidget(addPatternButton);
	inputsPatternToolbar->addWidget(addPatternButton);

	delPatternButton = new QToolButton(TrainingSetDialog);
	delPatternButton->setObjectName(QString::fromUtf8("delPatternButton"));
	delPatternButton->setIcon(QIcon(QString::fromUtf8(":/imagenes/minus_icon.png")));
	delPatternButton->setIconSize(QSize(20, 20));
	delPatternButton->setAutoRaise(true);

//	inputsVerticalLayout->addWidget(delPatternButton);
	inputsPatternToolbar->addWidget(delPatternButton);

	mainVerticalLayout->addLayout(inputsPatternToolbar);
//	mainHorizontalLayout->addLayout(horizontalLayout);

	inw = new NormalizationWidget(QString::fromLatin1("Normalización de entradas"));
	inw->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
	inw->setMinValueMaximum(999999999999);
	inw->setMinValueMinimum(-999999999999);
	inw->setMaxValueMaximum(999999999999);
	inw->setMaxValueMinimum(-999999999999);
	inw->setThresholdValueMaximum(999999999999);
	inw->setThresholdValueMinimum(-999999999999);

	inputsVerticalLayout->addWidget(inw);

	tnw = new NormalizationWidget(QString::fromLatin1("Normalización de salidas"));
	tnw->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
	tnw->setMinValueMaximum(999999999999);
	tnw->setMinValueMinimum(-999999999999);
	tnw->setMaxValueMaximum(999999999999);
	tnw->setMaxValueMinimum(-999999999999);
	tnw->setThresholdValueMaximum(999999999999);
	tnw->setThresholdValueMinimum(-999999999999);

//	tnw->hideNormalization(Normalization::Nothing);
	tnw->hideNormalization(Normalization(Normalization::BipolarFixedThreshold));
	tnw->hideNormalization(Normalization(Normalization::BipolarAutoThreshold));
	tnw->hideNormalization(Normalization(Normalization::UnipolarFixedThreshold));
	tnw->hideNormalization(Normalization(Normalization::UnipolarAutoThreshold));
	tnw->hideNormalization(Normalization(Normalization::LinearFixedRange));
	tnw->hideNormalization(Normalization(Normalization::LinearAutoRange));
	tnw->hideNormalization(Normalization(Normalization::MeanDistance));

	tnw->setNormalization(Normalization(Normalization::Nothing));

	targetsVerticalLayout->addWidget(tnw);
//	QGridLayout *norLayout = new QGridLayout();
	//	norLayout->setAlignment(Qt::AlignLeft);
//	norLayout->setSizeConstraint(QLayout::SetFixedSize);
//	norLayout->addWidget(inw, 0, 0);
//	norLayout->addWidget(tnw, 0, 1);
	//	mainVertlLayout->setAlignment(Qt::AlignLeft);
//	mainHorizontalLayout->addLayout(norLayout);

	tstInputs = new TrainingSetTable(ts);
	tstInputs->setObjectName(QString::fromUtf8("tstInputs"));
	tstInputs->setTargetsVisible(false);

	inputsVerticalLayout->addWidget(tstInputs);

	tstTargets = new TrainingSetTable(ts);
	tstTargets->setObjectName(QString::fromUtf8("tstTargets"));
	tstTargets->setInputsVisible(false);
	tstTargets->verticalHeader()->hide();
	tstTargets->setVerticalScrollBar(tstInputs->verticalScrollBar());

	targetsVerticalLayout->addWidget(tstTargets);

//	QHBoxLayout *patternTableLayout = new QHBoxLayout();
//	patternTableLayout->addWidget(tstInputs);
//	patternTableLayout->addWidget(tstTargets);
//	mainHorizontalLayout->addLayout(patternTableLayout);

	gbGraphicInputsRepresentation = new DataRepresentationBox();
	gbGraphicInputsRepresentation->setTitle("Patron de entrada");

	inputsVerticalLayout->addWidget(gbGraphicInputsRepresentation);
//	hlRepresentation->addWidget(gbGraphicInputRepresentation);

	gbGraphicTargetsRepresentation = new DataRepresentationBox();
	gbGraphicTargetsRepresentation->setTitle("Patron de salida");

	targetsVerticalLayout->addWidget(gbGraphicTargetsRepresentation);
//	hlRepresentation->addWidget(gbGraphicTargetRepresentation);

//	mainHorizontalLayout->addLayout(hlRepresentation);
	mainSubHorizontalLayout->addLayout(inputsVerticalLayout, 0, 0);
	mainSubHorizontalLayout->addLayout(targetsVerticalLayout, 0, 1);

	buttonBox = new QDialogButtonBox(TrainingSetDialog);
	buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
	buttonBox->setOrientation(Qt::Horizontal);
	buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

	mainVerticalLayout->addLayout(mainSubHorizontalLayout);
	mainVerticalLayout->addWidget(buttonBox);
//	mainSubHorizontalLayout->addWidget(buttonBox);

	retranslateUi(TrainingSetDialog);
	connect(buttonBox, SIGNAL(accepted()), TrainingSetDialog, SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), TrainingSetDialog, SLOT(reject()));

	connect(tstInputs, SIGNAL(activated(QModelIndex)), SLOT(onInputsTableActivated(QModelIndex)));
	connect(tstInputs, SIGNAL(clicked(QModelIndex)), SLOT(onInputsCellClicked(QModelIndex)));

	connect(tstTargets, SIGNAL(activated(QModelIndex)), SLOT(onTargetsTableActivated(QModelIndex)));
	connect(tstTargets, SIGNAL(clicked(QModelIndex)), SLOT(onTargetsCellClicked(QModelIndex)));

	connect(inw, SIGNAL(normalizationChanged(Normalization)), SLOT(onInputsNormalizationTypeChanged(Normalization)));
	connect(inw, SIGNAL(amplitudeValueChanged(double)), SLOT(onInputsAmplitudeChanged(double)));
	connect(inw, SIGNAL(elongationValueChanged(double)), SLOT(onInputsElongationChanged(double)));
	connect(inw, SIGNAL(thresholdValueChanged(double)), SLOT(onInputsThresholdChanged(double)));
	connect(inw, SIGNAL(minValueChanged(double)), SLOT(onInputsMinValueChanged(double)));
	connect(inw, SIGNAL(maxValueChanged(double)), SLOT(onInputsMaxValueChanged(double)));

	connect(tnw, SIGNAL(amplitudeValueChanged(double)), SLOT(onTargetsAmplitudeChanged(double)));
	connect(tnw, SIGNAL(elongationValueChanged(double)), SLOT(onTargetsElongationChanged(double)));
	connect(tnw, SIGNAL(thresholdValueChanged(double)), SLOT(onTargetsThresholdChanged(double)));
	connect(tnw, SIGNAL(minValueChanged(double)), SLOT(onTargetsMinValueChanged(double)));
	connect(tnw, SIGNAL(maxValueChanged(double)), SLOT(onTargetsMaxValueChanged(double)));
	connect(tnw, SIGNAL(normalizationChanged(Normalization)), SLOT(onTargetsNormalizationTypeChanged(Normalization)));

	connect(&tnInputsAmplitude, SIGNAL(timeout()), SLOT(onInputsAmplitudeTimed()));
	connect(&tnInputsElongation, SIGNAL(timeout()), SLOT(onInputsElongationTimed()));
	connect(&tnInputsThreshold, SIGNAL(timeout()), SLOT(onInputsThresholdTimed()));
	connect(&tnInputsMaxValue, SIGNAL(timeout()), SLOT(onInputsMaxValueTimed()));
	connect(&tnInputsMinValue, SIGNAL(timeout()), SLOT(onInputsMinValueTimed()));

	connect(&tnTargetsAmplitude, SIGNAL(timeout()), SLOT(onTargetsAmplitudeTimed()));
	connect(&tnTargetsElongation, SIGNAL(timeout()), SLOT(onTargetsElongationTimed()));
	connect(&tnTargetsThreshold, SIGNAL(timeout()), SLOT(onTargetsThresholdTimed()));
	connect(&tnTargetsMaxValue, SIGNAL(timeout()), SLOT(onTargetsMaxValueTimed()));
	connect(&tnTargetsMinValue, SIGNAL(timeout()), SLOT(onTargetsMinValueTimed()));


	ImageRepresentationWidget *irw = (ImageRepresentationWidget*)gbGraphicInputsRepresentation->getRepresentationWidget();
	connect(irw->getIgnoreAlphaChannelCheckBox(), SIGNAL(toggled(bool)), SLOT(onIgnoreAlphaChannelToogled(bool)));

	QMetaObject::connectSlotsByName(TrainingSetDialog);
}

void TrainingSetDialog::retranslateUi(QWidget *TrainingSetDialog)
{
	TrainingSetDialog->setWindowTitle(QApplication::translate("TrainingSetDialog", "Dialog", 0));
}

void TrainingSetDialog::appendVector(const vector<double> &vec)
{
	TrainingSet *tempTS = tstInputs->getTrainingSet();
	int tSize = ts->getTargetsSize();
	int iSize = ts->getInputsSize();

	if(importingInputs){
		if(tempTS != ts){
			tempTS->appendPattern(vec, vector<double>(tSize, 0));
		}
		ts->appendPattern(vec, vector<double>(tSize, 0));
	}else{
		if(tempTS != ts){
			tempTS->appendPattern(vector<double>(iSize, 0), vec);
		}
		ts->appendPattern(vector<double>(iSize, 0), vec);

	}
}

void TrainingSetDialog::onSaveTrainingSet()
{
	QString saveDir = fileDialog->getSaveFileName(this, //widget
												  "Guardar conjunto de entrenamiento", //caption
												  "/home/edixon/programacion/INSYDE/TrainingSets/", //dir
												  "Conjunto de entrenamiento (*.tsf);; Valores separados por comas (*.csv)" //filter
												  );

	if(saveDir == "") return;

	TrainingSetFile output(ts, saveDir);

	//Se determina las propiedades de la representacion que tendran las entradas

	//Inputs Representation Widget
	RepresentationWidget *irw = gbGraphicInputsRepresentation->getRepresentationWidget();

	//Inputs Representation Type
	RepresentationWidget::RepresentationType irt = irw->getRepresentationType();
	switch (irt) {
		case RepresentationWidget::Image:{

			//Inputs Image Representation Widget
			ImageRepresentationWidget *iirw = (ImageRepresentationWidget*)irw;
			output.setInputsWidth(iirw->getIntegerSizeWidget()->getWidth());
			output.setInputsHeight(iirw->getIntegerSizeWidget()->getHeight());
			output.setInputsDataRepresentation("image");
			break;
		}

		case RepresentationWidget::Matrix:
			break;
		default:
			break;
	}

	//Se determina las propiedades de la representacion que tendran las salidas

	RepresentationWidget *trw = gbGraphicTargetsRepresentation->getRepresentationWidget();
	RepresentationWidget::RepresentationType trt = trw->getRepresentationType();
	switch (trt) {
		case RepresentationWidget::Image:{
			//Targets Image Representation Widget
			ImageRepresentationWidget *tirw = (ImageRepresentationWidget*) trw;
			output.setTargetsWidth(tirw->getIntegerSizeWidget()->getWidth());
			output.setTargetsHeight(tirw->getIntegerSizeWidget()->getHeight());
			output.setTargetsDataRepresentation("image");
			break;
		}

		case RepresentationWidget::Matrix:
			break;
		default:
			break;
	}

	if(output.open(QIODevice::ReadWrite | QIODevice::Truncate)){
		output.flush();
		output.close();
	}
}

void TrainingSetDialog::onOpenTrainingSet()
{
	QString openDir = fileDialog->getOpenFileName(this, //widget
												  "Abrir conjunto de entrenamiento", //caption
												  "/home/edixon/programacion/INSYDE/TrainingSets", //dir
												  "Archivo de conjunto de entrenamiento (*.tsf)" //filter
												  );

	QPair<TrainingSet*, TrainingSetFile::Error> tsFile = TrainingSetFile::fromFile(openDir);

	if(tsFile.second.errnum == QXmlStreamReader::NoError){
		ts = tsFile.first;

		//Se asigna el tipo de normalizacion
		inw->setNormalization(ts->getInputsNormalization());
		tnw->setNormalization(ts->getTargetsNormalization());

		//Se cargan las entradas y salidas
		tstInputs->setTrainingSet(ts);
		tstTargets->setTrainingSet(ts);
	}
}

void TrainingSetDialog::onImportTrainingSet()
{

}
