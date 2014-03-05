#include "trainingsetdialog.h"

TrainingSetDialog::TrainingSetDialog(TrainingSet *ts, QWidget *parent):
	QDialog(parent),
	normalizedTS(new TrainingSet)
{
	initDialog(ts->getInputs(), ts->getTargets());

//	QString file = "C:/Users/Edixon Vargas/Google Drive/Programacion/C++/Qt/INSYDE/INSYDEUI/imagenes/0-pat-13x31-5.bmp";
//	imageFile = QImage(file);
//	int tSize = ts->getTargetSize();
//	vector<long> longInputs;
//	vector<double> dblinputs;
//	TrainingSet *tempTS = patternTable->getTrainingSet();

//	longInputs = CommonFunctions::imageToIntVector(imageFile, CommonFunctions::NormalUnsigned);
//	dblinputs = vector<double>(longInputs.begin(), longInputs.end());

//	if(tempTS != ts){
//		tempTS->appendPattern(dblinputs, vector<double>(tSize, 0));
//	}
//	ts->appendPattern(dblinputs, vector<double>(tSize, 0));
//	lastButtonPressed = btnMsgBoxFirstPixels;
}

TrainingSetDialog::TrainingSetDialog(int inputCount, int targetCount, int nPatterns, QWidget *parent) :
	QDialog(parent)
{
	initDialog(vector<vector<double> >(nPatterns, vector<double>(inputCount, 0)), vector<vector<double> >(nPatterns, vector<double>(targetCount, 0)));
}

TrainingSetDialog::TrainingSetDialog(const vector<vector<double> > &inputs, const vector<vector<double> > &targets, QWidget *parent) :
	QDialog(parent)
{
	initDialog(inputs, targets);
}

TrainingSetDialog::TrainingSetDialog(vector<MultilayerPerceptronPattern *> ts, QWidget *parent) :
	QDialog(parent)
{
	//TODO: se debe implementar este constructor
	//	tsCopy = new TrainingSet(ts);
	initDialog(ts);
}//TrainingSetDialog

TrainingSetDialog::~TrainingSetDialog()
{
	delete addPatternMenu;
	delete file;
	delete sisd;
	delete lastButtonPressed;
	delete btnMsgBoxFirstPixels;
	delete btnMsgBoxImageSegment;
	delete btnCancel;
	delete hlRepresentation;
	delete gbGraphicTargetRepresentation;
	delete gbGraphicInputRepresentation;
	delete mainVertlLayout;
	delete horizontalLayout;
	delete horizontalSpacer;
	delete addPatternButton;
	delete delPatternButton;
	delete patternTable;
	delete buttonBox;
	delete itm;
	delete imgRepresentation;
	delete dmRepresentation;
	delete fileDialog;
	delete menuBar;
}//~TrainingSetDialog

void TrainingSetDialog::setTrainingSetTable(TrainingSetTable *tst)
{
	patternTable = tst;
}

TrainingSetTable *TrainingSetDialog::getTrainingSetTable() const
{
	return patternTable;
}

void TrainingSetDialog::onInputsNormalizationTypeChanged(ITrainingSet::NormalizationType nt)
{
	switch(nt){
		case ITrainingSet::Nothing:
			normalizedTS->setInputs(ts->getInputs());
			break;
		case ITrainingSet::BipolarFixedThreshold:{
			dblInputsThreshold = inw->getThresholdValue();

			normalizedTS->setInputs(ts->getNormalizedInputsBipolarFixedThreshold(dblInputsThreshold));
			break;
		}
		case ITrainingSet::BipolarAutoThreshold:{
			normalizedTS->setInputs(ts->getNormalizedInputsBipolarAutoThreshold(&dblInputsThreshold));
			inw->setThresholdValue(dblInputsThreshold);
			break;
		}
		case ITrainingSet::UnipolarFixedThreshold:{
			dblInputsThreshold = inw->getThresholdValue();

			normalizedTS->setInputs(ts->getNormalizedInputsUnipolarFixedThreshold(dblInputsThreshold));
			break;
		}
		case ITrainingSet::UnipolarAutoThreshold:{
			double *threshold = new double;

			normalizedTS->setInputs(ts->getNormalizedInputsUnipolarAutoThreshold(threshold));
			inw->setThresholdValue(*threshold);
			break;
		}
		case ITrainingSet::LinearFixedRange:{
			dblInputsMinValue = inw->getMinValue(),
			dblInputsMaxValue = inw->getMaxValue();

			normalizedTS->setInputs(ts->getNormalizedInputsLinearFixedRange(dblInputsMinValue, dblInputsMaxValue));
			break;
		}
		case ITrainingSet::LinearAutoRange:{
			double
					*min = new double,
					*max = new double;

			normalizedTS->setInputs(ts->getNormalizedInputsLinearAutoRange(min, max));
			inw->setMinValue(*min);
			inw->setMaxValue(*max);
			break;
		}
		case ITrainingSet::Tanh:{
			*normalizedTS = ts->getNormalized(nt);
			break;
		}
		case ITrainingSet::Sigmoid:{
			*normalizedTS = ts->getNormalized(nt);
			break;
		}
	}
	patternTable->setTrainingSet(normalizedTS);
}

void TrainingSetDialog::onTargetsNormalizationTypeChanged(ITrainingSet::NormalizationType nt)
{
	double
			min = 0,
			max = 0,
			threshold = 0;
	switch(nt){
		case ITrainingSet::Nothing:
			normalizedTS->setTargets(ts->getTargets());
			break;
		case ITrainingSet::BipolarFixedThreshold:{
			threshold = inw->getThresholdValue();

			normalizedTS->setTargets(ts->getNormalizedTargetsBipolarFixedThreshold(threshold));
			break;
		}
		case ITrainingSet::BipolarAutoThreshold:{
			double
					*threshold = new double;

			normalizedTS->setTargets(ts->getNormalizedTargetsBipolarAutoThreshold(threshold));
			inw->setThresholdValue(*threshold);
			break;
		}
		case ITrainingSet::UnipolarFixedThreshold:{
			threshold = inw->getThresholdValue();

			normalizedTS->setTargets(ts->getNormalizedTargetsUnipolarFixedThreshold(threshold));
			break;
		}
		case ITrainingSet::UnipolarAutoThreshold:{
			double	*threshold = new double;

			normalizedTS->setTargets(ts->getNormalizedTargetsUnipolarAutoThreshold(threshold));
			tnw->setThresholdValue(*threshold);
			break;
		}
		case ITrainingSet::LinearFixedRange:{
			min = inw->getMinValue(),
			max = inw->getMaxValue();

			normalizedTS->setTargets(ts->getNormalizedTargetsLinearFixedRange(min, max));
			break;
		}
		case ITrainingSet::LinearAutoRange:{
			double
					*min = new double,
					*max = new double,
					*minTar = new double,
					*maxTar = new double;

			normalizedTS->setTargets(ts->getNormalizedTargetsLinearAutoRange(min, max));
			tnw->setMinValue(*minTar);
			tnw->setMaxValue(*maxTar);
			break;
		}
		case ITrainingSet::Tanh:
			*normalizedTS = ts->getNormalized(nt);
			break;
		case ITrainingSet::Sigmoid:
			*normalizedTS = ts->getNormalized(nt);
			break;
	}
	patternTable->setTrainingSet(normalizedTS);
}

void TrainingSetDialog::onInputsThresholdChanged(double val)
{
	(void)val;
//	dblInputsThreshold = val;
	tnInputsThreshold.start();
}

void TrainingSetDialog::onInputsThresholdTimed()
{
	onInputsNormalizationTypeChanged(inw->getCurrentNormalization());
}

void TrainingSetDialog::onInputsMinValueChanged(double val)
{
	(void)val;
//	dblInputsMinValue = val;
	tnInputsMinValue.start();
}

void TrainingSetDialog::onInputsMinValueTimed()
{
	onInputsNormalizationTypeChanged(inw->getCurrentNormalization());
}

void TrainingSetDialog::onInputsMaxValueChanged(double val)
{
	(void)val;
//	dblInputsMaxValue = val;
	tnInputsMaxValue.start();
}

void TrainingSetDialog::onInputsMaxValueTimed()
{
	onInputsNormalizationTypeChanged(inw->getCurrentNormalization());
}

void TrainingSetDialog::onTargetsThresholdChanged(double val)
{
	(void)val;
//	dblTargetsThreshold = val;
	tnTargetsThreshold.start();
}

void TrainingSetDialog::onTargetsThresholdTimed()
{
	onTargetsNormalizationTypeChanged(tnw->getCurrentNormalization());
}

void TrainingSetDialog::onTargetsMinValueChanged(double val)
{
	(void)val;
//	dblTargetsMinValue = val;
	tnTargetsMinValue.start();
}

void TrainingSetDialog::onTargetsMinValueTimed()
{
	onTargetsNormalizationTypeChanged(tnw->getCurrentNormalization());
}

void TrainingSetDialog::onTargetsMaxValueChanged(double val)
{
	(void)val;
//	dblTargetsMaxValue = val;
	tnTargetsMaxValue.start();
}

void TrainingSetDialog::onTargetsMaxValueTimed()
{
	onTargetsNormalizationTypeChanged(tnw->getCurrentNormalization());
}

void TrainingSetDialog::onWidthChanged(int width)
{
	((ImageRepresentationWidget*)gbGraphicInputRepresentation->getRepresentationWidget())->getIntegerSizeWidget()->setWidth(width);
}

void TrainingSetDialog::onHeightChanged(int height)
{
	((ImageRepresentationWidget*)gbGraphicInputRepresentation->getRepresentationWidget())->getIntegerSizeWidget()->setHeight(height);
}

void TrainingSetDialog::on_addPatternButton_clicked()
{
	TrainingSet *tempTS = patternTable->getTrainingSet();

	vector<double>
			newInputs(tempTS->getInputSize(), 0),
			newTargets(tempTS->getTargetSize(), 0);

	if(tempTS != ts){
		ts->appendPattern(newInputs, newTargets);
	}
	tempTS->appendPattern(newInputs, newTargets);
}//on_addPatternButton_clicked

void TrainingSetDialog::on_delPatternButton_clicked()
{
	TrainingSet *tempTS = patternTable->getTrainingSet();

	int curRow = patternTable->currentRow();
	if(tempTS != ts){
		ts->deletePattern(curRow);
	}
	tempTS->deletePattern(curRow);
}//on_delPatternButton_clicked

/*!
 * \brief TrainingSetDialog::onIgnoreAlphaChannelToogled
 *
 * FIXME: se debe corregir este metodo para que inhiba el canal alfa sin que
 * se pierdan los datos y luego se puedan volver a recuperar
 */
void TrainingSetDialog::onIgnoreAlphaChannelToogled(bool)
{

	QTableWidgetItem *itm;

	//	int nPat = getPatternCount();
	//	int sInputs = getInputSize();
	TrainingSet *tempTS = patternTable->getTrainingSet();
	int nPat = tempTS->getPatternCount();
	int sInputs = tempTS->getInputSize();
	for(int i = 0; i < nPat; i++){
		for(int j = 0; j < sInputs; j++){
			itm = new QTableWidgetItem(QString::number(patternTable->item(i,j)->text().toInt() | 0xff000000));
			patternTable->setItem(i, j, itm);
		}
	}
}//onIgnoreAlphaChannelToogled

void TrainingSetDialog::initDialog(const vector<vector<double> > &inputs, const vector<vector<double> > &targets)
{
	const int tUpdateInterval = 1000; //milliseconds

	ts = new TrainingSet(inputs, targets);
	*normalizedTS = TrainingSet(inputs, targets);

	setupUi(normalizedTS, this);
	initMsgBoxes();

	fileDialog = new QFileDialog(this);

	QMenu *file = new QMenu(tr("Archivo"));
	file->addAction("Desde archivo...", this, SLOT(fromFile()));
	file->addAction("Desde imagenes...", this, SLOT(fromImages()));

	menuBar = new QMenuBar(this);
	menuBar->addMenu(file);
	layout()->setMenuBar(menuBar);

	gbGraphicInputRepresentation->setDataInput(inputs[0]);
	gbGraphicTargetRepresentation->setDataInput(targets[0]);

	tnInputsThreshold.setSingleShot(true);
	tnInputsThreshold.setInterval(tUpdateInterval);

	tnInputsMinValue.setSingleShot(true);
	tnInputsMinValue.setInterval(tUpdateInterval);

	tnInputsMaxValue.setSingleShot(true);
	tnInputsMaxValue.setInterval(tUpdateInterval);

	tnTargetsThreshold.setSingleShot(true);
	tnTargetsThreshold.setInterval(tUpdateInterval);

	tnTargetsMinValue.setSingleShot(true);
	tnTargetsMinValue.setInterval(tUpdateInterval);

	tnTargetsMaxValue.setSingleShot(true);
	tnTargetsMaxValue.setInterval(tUpdateInterval);

}//initDialog

void TrainingSetDialog::initDialog(const vector<MultilayerPerceptronPattern*> ts)
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
	btnMsgBoxFirstPixels = mbImageSegmentMessage.addButton(QString::fromLatin1("Tomar los primeros pixeles"), QMessageBox::AcceptRole);
	btnMsgBoxImageSegment = mbImageSegmentMessage.addButton(QString::fromLatin1("Escoger segmento de imagen"), QMessageBox::AcceptRole);
	btnCancel = mbImageSegmentMessage.addButton(QMessageBox::Cancel);

	connect(&mbImageSegmentMessage, SIGNAL(buttonClicked(QAbstractButton*)), SLOT(onMessageBoxButtonClicked(QAbstractButton*)));
}//initMsgBoxes

void TrainingSetDialog::updateRepresentation(int row)
{
//	TrainingSet *tempTS = patternTable->getTrainingSet();
	gbGraphicInputRepresentation->setDataInput(ts->getInputs()[row]);

	gbGraphicTargetRepresentation->setDataInput(ts->getTargets()[row]);
}//updateRepresentation

void TrainingSetDialog::fromFile()
{
	//	TODO: implementar la carga desde archivos XML, CSV, EXCEL, etc.

	//	QString file = QFileDialog::getOpenFileName(this, "Abrir archivo", "", "Archivos de datos (*.csv *.xls *.txt *.xml)");
	//	QStringList filters;
	//	filters << "Archivos de datos (*.csv *.xls *.xml)"
	//			<< "Archivos de texto (*.txt)"
	//			<< "Any files (*)";

	//	fileDialog->setFileMode(QFileDialog::ExistingFile);
	//	fileDialog->setNameFilters(filters);

	//	file = fileDialog->getOpenFileName(this, "Abrir archivo");
}//fromFile

void TrainingSetDialog::fromImages()
{
	//	QStringList files = QFileDialog::getOpenFileNames(this, "Abrir archivo", "INSYDEUI/imagenes", "Bitmap (*.bmp);; Portable Network Graphic (*.png);; JPEG Image (*.jpg);; (*.gif)");
	QStringList files = fileDialog->getOpenFileNames(this, "Abrir archivo", "INSYDEUI/imagenes", "Bitmap (*.bmp);; Portable Network Graphic (*.png);; JPEG Image (*.jpg);; (*.gif)");
	//	QStringList files = fileDialog->getOpenFileNames(this, "Abrir archivo", "INSYDEUI/imagenes", "Bitmap (*.bmp);; Portable Network Graphic (*.png);; JPEG Image (*.jpg);; (*.gif)");

	TrainingSet *tempTS = patternTable->getTrainingSet();

	patternTable->blockSignals(true);
	foreach(QString file, files){
		imageFile = QImage(file);
		if(imageFile.isNull()){
			mbErrorLoadingImageMessage.setText("Ocurrio un error durante la carga de la imagen: " + file);
			mbErrorLoadingImageMessage.exec();
		}else{
			int nPixels = imageFile.width() * imageFile.height();
			if(nPixels > tempTS->getInputSize()){
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
	patternTable->setCurrentCell(patternTable->rowCount()-1, 0);
	patternTable->blockSignals(false);
}//fromImages

void TrainingSetDialog::on_patternTable_cellChanged(int row, int column)
{
	(void)column;

	updateRepresentation(row);
}//on_patternTable_cellChanged

void TrainingSetDialog::on_patternTable_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
	(void)currentColumn;
	(void)previousColumn;
	if(currentRow != previousRow && currentRow != -1 && previousRow != -1){
		updateRepresentation(currentRow);
	}
}//on_patternTable_currentCellChanged

void TrainingSetDialog::onMessageBoxButtonClicked(QAbstractButton *button)
{
	int tSize = ts->getTargetSize();
	vector<long> longInputs;
	vector<double> inputs;
	TrainingSet *tempTS = patternTable->getTrainingSet();

	if(button == btnMsgBoxFirstPixels){//En caso de que se decidan tomar los primeros pixeles
		longInputs = CommonFunctions::imageToIntVector(imageFile, CommonFunctions::NormalUnsigned);
		inputs = vector<double>(longInputs.begin(), longInputs.end());

		if(tempTS != ts){
			tempTS->appendPattern(inputs, vector<double>(tSize, 0));
		}
		ts->appendPattern(inputs, vector<double>(tSize, 0));
		lastButtonPressed = btnMsgBoxFirstPixels;

	}else if(button == btnMsgBoxImageSegment){//En caso de que se decidan tomar un segmento de la imagen
		QSize size = ((ImageRepresentationWidget*)gbGraphicInputRepresentation->getRepresentationWidget())->getIntegerSizeWidget()->getSizeValue();
		QRect selrect(QPoint(0, 0), size);
		sisd = new SelectImageSegmentDialog(imageFile, selrect);

		connect(sisd->getIntegerSizeWidget(), SIGNAL(widthChanged(int)), SLOT(onWidthChanged(int)));
		connect(sisd->getIntegerSizeWidget(), SIGNAL(heightChanged(int)), SLOT(onHeightChanged(int)));

		if(sisd->exec() == QDialog::Accepted){
			longInputs = CommonFunctions::imageToIntVector(sisd->getImageSegment(), CommonFunctions::NormalUnsigned);
			inputs = vector<double>(longInputs.begin(), longInputs.end());
			if(tempTS != ts){
				tempTS->appendPattern(inputs, vector<double>(tSize, 0));
			}
			ts->appendPattern(inputs, vector<double>(tSize, 0));
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
	mainVertlLayout = new QVBoxLayout(TrainingSetDialog);
	mainVertlLayout->setObjectName(QString::fromUtf8("verticalLayout"));
	horizontalLayout = new QHBoxLayout();
	horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
	hlRepresentation = new QHBoxLayout();
	hlRepresentation->setObjectName(QString::fromUtf8("hlRepresentation"));

	horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

	horizontalLayout->addItem(horizontalSpacer);

	file = new QMenu(tr("Archivo"));
	file->addAction("Desde archivo...", this, SLOT(fromFile()));
	file->addAction("Desde imagenes...", this, SLOT(fromImages()));

	menuBar = new QMenuBar(TrainingSetDialog);
	menuBar->setObjectName(QString::fromUtf8("menuBar"));
	menuBar->addMenu(file);
	menuBar->setMaximumHeight(15);
	mainVertlLayout->setMenuBar(menuBar);

	addPatternMenu = new QMenu(QString::fromLatin1("Agregar patrón"));
	addPatternMenu->setObjectName(QString::fromUtf8("addPatternMenu"));
	addPatternMenu->addAction("Desde archivo...", this, SLOT(fromFile()));
	addPatternMenu->addAction("Desde imagenes...", this, SLOT(fromImages()));

	addPatternButton = new QToolButton(TrainingSetDialog);
	addPatternButton->setObjectName(QString::fromUtf8("addPatternButton"));
	addPatternButton->setIcon(QIcon(QString::fromUtf8(":/imagenes/plus_icon.png")));
	addPatternButton->setIconSize(QSize(20, 20));
	addPatternButton->setPopupMode(QToolButton::MenuButtonPopup);
	addPatternButton->setAutoRaise(true);
	addPatternButton->setMenu(addPatternMenu);

	horizontalLayout->addWidget(addPatternButton);

	delPatternButton = new QToolButton(TrainingSetDialog);
	delPatternButton->setObjectName(QString::fromUtf8("delPatternButton"));
	delPatternButton->setIcon(QIcon(QString::fromUtf8(":/imagenes/minus_icon.png")));
	delPatternButton->setIconSize(QSize(20, 20));
	delPatternButton->setAutoRaise(true);

	horizontalLayout->addWidget(delPatternButton);

	mainVertlLayout->addLayout(horizontalLayout);

	inw = new NormalizationWidget(QString::fromLatin1("Normalización de entradas"));
	inw->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
	inw->setMinValueMaximum(999999999999);
	inw->setMinValueMinimum(-999999999999);
	inw->setMaxValueMaximum(999999999999);
	inw->setMaxValueMinimum(-999999999999);
	inw->setThresholdValueMaximum(999999999999);
	inw->setThresholdValueMinimum(-999999999999);

	tnw = new NormalizationWidget(QString::fromLatin1("Normalización de salidas"));
	tnw->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
	tnw->setMinValueMaximum(999999999999);
	tnw->setMinValueMinimum(-999999999999);
	tnw->setMaxValueMaximum(999999999999);
	tnw->setMaxValueMinimum(-999999999999);
	tnw->setThresholdValueMaximum(999999999999);
	tnw->setThresholdValueMinimum(-999999999999);

	QGridLayout *norLayout = new QGridLayout();
	//	norLayout->setAlignment(Qt::AlignLeft);
//	norLayout->setSizeConstraint(QLayout::SetFixedSize);
	norLayout->addWidget(inw, 0, 0);
	norLayout->addWidget(tnw, 0, 1);
	//	mainVertlLayout->setAlignment(Qt::AlignLeft);
	mainVertlLayout->addLayout(norLayout);

	patternTable = new TrainingSetTable(ts, TrainingSetDialog);
	patternTable->setObjectName(QString::fromUtf8("patternTable"));

	mainVertlLayout->addWidget(patternTable);

	gbGraphicInputRepresentation = new DataRepresentationBox();
	gbGraphicInputRepresentation->setTitle("Patron de entrada");

	hlRepresentation->addWidget(gbGraphicInputRepresentation);

	gbGraphicTargetRepresentation = new DataRepresentationBox();
	gbGraphicTargetRepresentation->setTitle("Patron de salida");

	hlRepresentation->addWidget(gbGraphicTargetRepresentation);

	mainVertlLayout->addLayout(hlRepresentation);

	buttonBox = new QDialogButtonBox(TrainingSetDialog);
	buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
	buttonBox->setOrientation(Qt::Horizontal);
	buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

	mainVertlLayout->addWidget(buttonBox);

	retranslateUi(TrainingSetDialog);
	connect(buttonBox, SIGNAL(accepted()), TrainingSetDialog, SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), TrainingSetDialog, SLOT(reject()));
	connect(patternTable, SIGNAL(cellChanged(int,int)), SLOT(on_patternTable_cellChanged(int,int)));
	connect(patternTable, SIGNAL(currentCellChanged(int,int,int,int)), SLOT(on_patternTable_currentCellChanged(int,int,int,int)));
	connect(inw, SIGNAL(normalizationChanged(ITrainingSet::NormalizationType)), SLOT(onInputsNormalizationTypeChanged(ITrainingSet::NormalizationType)));
	connect(tnw, SIGNAL(normalizationChanged(ITrainingSet::NormalizationType)), SLOT(onTargetNormalizationTypeChanged(ITrainingSet::NormalizationType)));

	connect(inw, SIGNAL(thresholdValueChanged(double)), SLOT(onInputsThresholdChanged(double)));
	connect(inw, SIGNAL(minValueChanged(double)), SLOT(onInputsMinValueChanged(double)));
	connect(inw, SIGNAL(maxValueChanged(double)), SLOT(onInputsMaxValueChanged(double)));

	connect(tnw, SIGNAL(thresholdValueChanged(double)), SLOT(onTargetsThresholdChanged(double)));
	connect(tnw, SIGNAL(minValueChanged(double)), SLOT(onTargetsMinValueChanged(double)));
	connect(tnw, SIGNAL(maxValueChanged(double)), SLOT(onTargetsMaxValueChanged(double)));

	connect(&tnInputsThreshold, SIGNAL(timeout()), SLOT(onInputsThresholdTimed()));
	connect(&tnInputsMaxValue, SIGNAL(timeout()), SLOT(onInputsMaxValueTimed()));
	connect(&tnInputsMinValue, SIGNAL(timeout()), SLOT(onInputsMinValueTimed()));

	connect(&tnTargetsThreshold, SIGNAL(timeout()), SLOT(onTargetsThresholdTimed()));
	connect(&tnTargetsMaxValue, SIGNAL(timeout()), SLOT(onTargetsMaxValueTimed()));
	connect(&tnTargetsMinValue, SIGNAL(timeout()), SLOT(onTargetsMinValueTimed()));


	ImageRepresentationWidget *irw = (ImageRepresentationWidget*)gbGraphicInputRepresentation->getRepresentationWidget();
	connect(irw->getIgnoreAlphaChannelCheckBox(), SIGNAL(toggled(bool)), SLOT(onIgnoreAlphaChannelToogled(bool)));

	QMetaObject::connectSlotsByName(TrainingSetDialog);
}

void TrainingSetDialog::retranslateUi(QWidget *TrainingSetDialog)
{
	TrainingSetDialog->setWindowTitle(QApplication::translate("TrainingSetDialog", "Dialog", 0));
}
