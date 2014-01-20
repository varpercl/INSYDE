#include "trainingsetdialog.h"

void TrainingSetDialog::setupUi(QDialog *TrainingSetDialog)
{
	if (TrainingSetDialog->objectName().isEmpty())
		TrainingSetDialog->setObjectName(QString::fromUtf8("TrainingSetDialog"));
//	TrainingSetDialog->resize(630, 650);
	TrainingSetDialog->setMinimumWidth(750);
	mainVertlLayout = new QVBoxLayout(TrainingSetDialog);
	mainVertlLayout->setObjectName(QString::fromUtf8("verticalLayout"));
	horizontalLayout = new QHBoxLayout();
	horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
	hlRepresentation = new QHBoxLayout();
	hlRepresentation->setObjectName(QString::fromUtf8("hlRepresentation"));

	horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

	horizontalLayout->addItem(horizontalSpacer);

	addPatternButton = new QPushButton(TrainingSetDialog);
	addPatternButton->setObjectName(QString::fromUtf8("addPatternButton"));
	QIcon icon;
	icon.addFile(QString::fromUtf8(":/imagenes/plus_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
	addPatternButton->setIcon(icon);

	horizontalLayout->addWidget(addPatternButton);

	delPatternButton = new QPushButton(TrainingSetDialog);
	delPatternButton->setObjectName(QString::fromUtf8("delPatternButton"));
	QIcon icon1;
	icon1.addFile(QString::fromUtf8(":/imagenes/minus_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
	delPatternButton->setIcon(icon1);

	horizontalLayout->addWidget(delPatternButton);


	mainVertlLayout->addLayout(horizontalLayout);

	patternTable = new QTableWidget(TrainingSetDialog);
	patternTable->setObjectName(QString::fromUtf8("patternTable"));
	patternTable->setAlternatingRowColors(true);
	patternTable->setRowCount(0);
	patternTable->setColumnCount(0);
	patternTable->verticalHeader()->setVisible(false);
	patternTable->verticalHeader()->setCascadingSectionResizes(true);
	patternTable->verticalHeader()->setHighlightSections(true);
	patternTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
	patternTable->verticalHeader()->setStretchLastSection(false);

	mainVertlLayout->addWidget(patternTable);

	gbGraphicInputRepresentation = new DataRepresentationBox(vector<double>());
	gbGraphicInputRepresentation->setTitle("Patron de entrada");

	hlRepresentation->addWidget(gbGraphicInputRepresentation);

	gbGraphicTargetRepresentation = new DataRepresentationBox(vector<double>());
	gbGraphicTargetRepresentation->setTitle("Patron de salida");

	hlRepresentation->addWidget(gbGraphicTargetRepresentation);

	mainVertlLayout->addLayout(hlRepresentation);

	buttonBox = new QDialogButtonBox(TrainingSetDialog);
	buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
	buttonBox->setOrientation(Qt::Horizontal);
	buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

	mainVertlLayout->addWidget(buttonBox);

	retranslateUi(TrainingSetDialog);
	QObject::connect(buttonBox, SIGNAL(accepted()), TrainingSetDialog, SLOT(accept()));
	QObject::connect(buttonBox, SIGNAL(rejected()), TrainingSetDialog, SLOT(reject()));

	QMetaObject::connectSlotsByName(TrainingSetDialog);
}

void TrainingSetDialog::retranslateUi(QDialog *TrainingSetDialog)
{
	TrainingSetDialog->setWindowTitle(QApplication::translate("TrainingSetDialog", "Dialog", 0));
}

TrainingSetDialog::TrainingSetDialog(const TrainingSet *ts, QWidget *parent):
	QDialog(parent),
	targetSize(ts->getTargetSize())
{
	initDialog(ts->getInputs(), ts->getTargets());
}

TrainingSetDialog::TrainingSetDialog(int inputCount, int outputCount, QWidget *parent) :
	QDialog(parent),
	targetSize(outputCount)
{
	initDialog(inputCount, outputCount);
}

TrainingSetDialog::TrainingSetDialog(vector<vector<double> > inputs, vector<vector<double> > targets, QWidget *parent) :
	QDialog(parent),
	targetSize(targets[0].size())
{
	initDialog(inputs, targets);
}

TrainingSetDialog::TrainingSetDialog(vector<MultilayerPerceptronPattern *> ts, QWidget *parent) :
	QDialog(parent),
	targetSize(ts.size())
{
	initDialog(ts);
}//TrainingSetDialog

TrainingSetDialog::~TrainingSetDialog()
{

}//~TrainingSetDialog

vector<vector<double> > TrainingSetDialog::getInputs() const
{
	int nRows = patternTable->rowCount();
	vector<vector<double> >
			inputs/* = vector<vector<double> > (nRows, vector<double>(inputSize, 0))*/;

	inputs.resize(nRows);
	for(int i = 0; i < nRows; i++){
		inputs[i].resize(inputSize);
		for(int j = 0; j < inputSize; j++){
			QTableWidgetItem *itm = patternTable->item(i,j);
			if(itm){
				inputs[i][j] = patternTable->item(i,j)->text().toDouble();
			}else{
				inputs[i][j] = 0;
			}
		}
	}
	return inputs;
}//getInputs

void TrainingSetDialog::setInputSize(int size)
{
	inputSize = size;

	patternTable->setColumnCount(targetSize + inputSize);
	updateHeaders();
}//setInputSize

vector<vector<double> > TrainingSetDialog::getTargets() const
{
	int nRows = patternTable->rowCount();
	vector<vector<double> >
			targets = vector<vector<double> > (nRows, vector<double>(targetSize, 0));

	for(int i = 0; i < nRows; i++){
		for(int j = inputSize; j < patternTable->columnCount(); j++){
			QTableWidgetItem *itm = patternTable->item(i,j);
			if(itm){
				targets[i][j - inputSize] = itm->text().toDouble();
			}else{
				targets[i][j - inputSize] = 0;
			}
		}
	}
	return targets;
}//getTargets

void TrainingSetDialog::setTargetSize(int size)
{
	targetSize = size;
	patternTable->setColumnCount(targetSize + inputSize);
	updateHeaders();
}//setTargetSize

void TrainingSetDialog::removePattern(int i)
{
	patternTable->removeRow(i);
}//removePattern

int TrainingSetDialog::getPatternCount()
{
	return patternTable->rowCount();
}//getPatternCount

void TrainingSetDialog::setTrainingSet(TrainingSet *ts)
{
	patternTable->clear();

	int sTs = ts->getPatternCount();
	vector<vector<double> >
			inputs = ts->getInputs(),
			targets = ts->getTargets();

	for(int i = 0; i < sTs; i++){
		appendPattern(inputs[i], targets[i]);
	}
}//setTrainingSet

TrainingSet *TrainingSetDialog::getTrainingSet() const
{
	return new TrainingSet(getInputs(), getTargets());
}//getTrainingSet

void TrainingSetDialog::on_addPatternButton_clicked()
{
	patternTable->setRowCount(patternTable->rowCount()+1);
}//on_addPatternButton_clicked

void TrainingSetDialog::on_delPatternButton_clicked()
{
	patternTable->removeRow(patternTable->currentRow());
	//    ui->patternTable->selectedItems();
}//on_delPatternButton_clicked

void TrainingSetDialog::initDialog(int inputs, int outputs)
{
	setupUi(this);

	fileDialog = new QFileDialog(this);

	QMenu *file = new QMenu(tr("Archivo"));
	file->addAction("Desde archivo...", this, SLOT(fromFile()));
	file->addAction("Desde imagenes...", this, SLOT(fromImages()));

	menuBar = new QMenuBar(this);
	menuBar->addMenu(file);
	layout()->setMenuBar(menuBar);
	setInputSize(inputs);
	setTargetSize(outputs);

	//image initialization

}//initDialog

void TrainingSetDialog::initDialog(const vector<vector<double> > &inputs, const vector<vector<double> > &targets)
{
	setupUi(this);

	fileDialog = new QFileDialog(this);

	QMenu *file = new QMenu(tr("Archivo"));
	file->addAction("Desde archivo...", this, SLOT(fromFile()));
	file->addAction("Desde imagenes...", this, SLOT(fromImages()));

	menuBar = new QMenuBar(this);
	menuBar->addMenu(file);
	layout()->setMenuBar(menuBar);

	const int nPatterns = inputs.size();

	setInputSize(inputs[0].size());
	setTargetSize(targets[0].size());
	for(int i = 0; i < nPatterns; i++){
		appendPattern(inputs[i], targets[i]);
	}

	patternTable->selectRow(0);

}//initDialog

void TrainingSetDialog::initDialog(const vector<MultilayerPerceptronPattern*> ts)
{
	setupUi(this);

	fileDialog = new QFileDialog(this);

	QMenu *file = new QMenu(tr("Archivo"));
	file->addAction("Desde archivo...", this, SLOT(fromFile()));
	file->addAction("Desde imagenes...", this, SLOT(fromImages()));

	menuBar = new QMenuBar(this);
	menuBar->addMenu(file);
	layout()->setMenuBar(menuBar);

	const int nPatterns = ts.size();
	//	size_t sInputs, sTargets;
	for(int i = 0; i < nPatterns; i++){
		appendPattern(ts[i]->getInputs(), ts[i]->getTargets());
	}
}//initDialog

void TrainingSetDialog::updateHeaders()
{
	QStringList headers;
	for(int i = 0; i < inputSize; i++){
		headers.append("In " + QString::number(i+1));
	}
	for(int i = inputSize; i < inputSize + targetSize; i++){
		headers.append("Out " + QString::number(i - inputSize + 1));
	}
	patternTable->setHorizontalHeaderLabels(headers);
}//updateHeaders

void TrainingSetDialog::updateRepresentation(int row)
{
	gbGraphicInputRepresentation->setDataInput(getInputs()[row]);

	gbGraphicTargetRepresentation->setDataInput(getTargets()[row]);
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
	QMessageBox msgBox;
	QStringList files = QFileDialog::getOpenFileNames(this, "Abrir archivo", "", "Bitmap (*.bmp);; Portable Network Graphic (*.png);; JPEG Image (*.jpg);; (*.gif)");

	foreach(QString file, files){
		imageFile = QImage(file);
		if(imageFile.isNull()){
			msgBox.setIcon(QMessageBox::Critical);
			msgBox.setModal(true);
			msgBox.setWindowTitle("Error con imagen");
			msgBox.setText("Ocurrio un error durante la carga de la imagen: " + file);
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.exec();
		}else{
			int nPixels = imageFile.width() * imageFile.height();
			if(nPixels > (int)getInputs().size()){
				msgBox.setIcon(QMessageBox::Warning);
				msgBox.setModal(true);
				msgBox.setWindowTitle(QString::fromLatin1("No coincide el tamaño"));
				msgBox.setText(QString::fromLatin1("El numero de pixeles que contiene la imagen " + file.toLatin1() + " es mayor que el numero de entradas que permite el conjunto de entrenamiento ¿Que desea hacer?"));
				btnMsgBoxFirstPixels = msgBox.addButton(QString::fromLatin1("Tomar los primeros pixeles"), QMessageBox::AcceptRole);
				btnMsgBoxImageSegment = msgBox.addButton(QString::fromLatin1("Escoger segmento de imagen"), QMessageBox::AcceptRole);
				msgBox.addButton(QMessageBox::Cancel);
				connect(&msgBox, SIGNAL(buttonClicked(QAbstractButton*)), SLOT(onMessageBoxButtonClicked(QAbstractButton*)));
				msgBox.exec();
			}
			appendPattern(CommonFunctions::imageToIntVector(imageFile, CommonFunctions::Bipolar), vector<int>(targetSize, 0));
		}
	}
	patternTable->setCurrentCell(patternTable->rowCount()-1, 0);

}//fromImages

void TrainingSetDialog::on_patternTable_cellChanged(int row, int column)
{
	(void)row;
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
	if(button == btnMsgBoxFirstPixels){

	}else if(button == btnMsgBoxImageSegment){
		sisd = new SelectImageSegmentDialog(imageFile);

		sisd->exec();

		delete sisd;
	}
}//onMessageBoxButtonClicked
