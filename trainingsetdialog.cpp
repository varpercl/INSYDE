#include "trainingsetdialog.h"

//TrainingSetDialog::TrainingSetDialog(TrainingSetType type, QWidget *parent) :
//	QDialog(parent),
//	ui(new Ui::TrainingSetDialog),
//	inputCount(1),
//	targetCount(1)
//{
//    Q_UNUSED(type);

//	initDialog(1, 1);
////	loadMLPData();
//}

TrainingSetDialog::TrainingSetDialog(const TrainingSet *ts, QWidget *parent):
	QDialog(parent),
	ui(new Ui::TrainingSetDialog),
	targetSize(ts->getTargetSize())
{
	initDialog(ts->getInputs(), ts->getTargets());
}

TrainingSetDialog::TrainingSetDialog(int inputCount, int outputCount, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TrainingSetDialog),
	targetSize(outputCount)
{
	initDialog(inputCount, outputCount);
}

TrainingSetDialog::TrainingSetDialog(vector<vector<double> > inputs, vector<vector<double> > targets, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TrainingSetDialog),
	targetSize(targets[0].size())
{
	initDialog(inputs, targets);
}

TrainingSetDialog::TrainingSetDialog(vector<MultilayerPerceptronPattern *> ts, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TrainingSetDialog),
	targetSize(ts.size())
{
	initDialog(ts);
}

vector<vector<double> > TrainingSetDialog::getInputs() const
{
	int nRows = ui->patternTable->rowCount();
	vector<vector<double> >
			inputs = vector<vector<double> > (nRows, vector<double>(inputSize, 0));

	for(int i = 0; i < nRows; i++){
		inputs[i].resize(inputSize);
		for(int j = 0; j < inputSize; j++){
			QTableWidgetItem *itm = ui->patternTable->item(i,j);
			if(itm){
				inputs[i][j] = ui->patternTable->item(i,j)->text().toDouble();
			}else{
				inputs[i][j] = 0;
			}
		}
	}
	return inputs;
}

void TrainingSetDialog::setInputSize(int size)
{
	inputSize = size;

	ui->patternTable->setColumnCount(targetSize + inputSize);
	updateHeaders();
}

vector<vector<double> > TrainingSetDialog::getTargets() const
{
	int nRows = ui->patternTable->rowCount();
	vector<vector<double> >
			targets = vector<vector<double> > (nRows, vector<double>(targetSize, 0));

	for(int i = 0; i < nRows; i++){
		for(int j = inputSize; j < ui->patternTable->columnCount(); j++){
			QTableWidgetItem *itm = ui->patternTable->item(i,j);
			if(itm){
				targets[i][j - inputSize] = itm->text().toDouble();
			}else{
				targets[i][j - inputSize] = 0;
			}
		}
	}
	return targets;
}

void TrainingSetDialog::setTargetSize(int size)
{
	targetSize = size;
	ui->patternTable->setColumnCount(targetSize + inputSize);
	updateHeaders();
}

//void TrainingSetDialog::appendPattern(const vector<double> &input, const vector<double> &target)
//{
//	setInputSize(input.size());
//	setTargetSize(target.size());
//	ui->patternTable->setRowCount(ui->patternTable->rowCount() + 1);

//	int nRows = ui->patternTable->rowCount();
//	for(int i = 0; i < inputSize; i++){
//		QTableWidgetItem *itm = new QTableWidgetItem(QString::number((uint)input[i]));
//		itm->setTextAlignment(Qt::AlignRight);
//		ui->patternTable->setItem(nRows-1, i, itm);
//	}
//	for(int j = inputSize; j < inputSize + targetSize; j++){
//		QTableWidgetItem *itm = new QTableWidgetItem(QString::number(target[j-inputSize]));
//		itm->setTextAlignment(Qt::AlignRight);
//		ui->patternTable->setItem(nRows-1, j, itm);
//	}
//}

//template<typename I, typename T>
//void TrainingSetDialog::appendPattern(const vector<I> &input, const vector<T> &target)
//{
//	setInputSize(input.size());
//	setTargetSize(target.size());
//	ui->patternTable->setRowCount(ui->patternTable->rowCount() + 1);

//	int nRows = ui->patternTable->rowCount();
//	for(int i = 0; i < inputSize; i++){
//		QTableWidgetItem *itm = new QTableWidgetItem(QString::number((I)input[i]));
//		itm->setTextAlignment(Qt::AlignRight);
//		ui->patternTable->setItem(nRows-1, i, itm);
//	}
//	for(int j = inputSize; j <  inputSize + targetSize; j++){
//		QTableWidgetItem *itm = new QTableWidgetItem(QString::number((T)target[j-inputSize]));
//		itm->setTextAlignment(Qt::AlignRight);
//		ui->patternTable->setItem(nRows-1, j, itm);
//	}
//}

//void TrainingSetDialog::appendPattern(const vector<int> &input, const vector<int> &target)
//{
//	setInputSize(input.size());
//	setTargetSize(target.size());
//	ui->patternTable->setRowCount(ui->patternTable->rowCount() + 1);

//	int nRows = ui->patternTable->rowCount();
//	for(int i = 0; i < inputSize; i++){
//		QTableWidgetItem *itm = new QTableWidgetItem(QString::number((int)input[i], 16));
//		itm->setTextAlignment(Qt::AlignRight);
//		ui->patternTable->setItem(nRows-1, i, itm);
//	}
//	for(int j = inputSize; j <  inputSize + targetSize; j++){
//		QTableWidgetItem *itm = new QTableWidgetItem(QString::number(target[j-inputSize]));
//		itm->setTextAlignment(Qt::AlignRight);
//		ui->patternTable->setItem(nRows-1, j, itm);
//	}
//}

//void TrainingSetDialog::appendPattern(const vector<unsigned int> &input, const vector<unsigned int> &target)
//{
////	appendPattern(vector<unsigned int>(input.begin(), input.end()), vector<int>(target.begin(), target.end()));
//	appendPattern(input, target);
//}

//void TrainingSetDialog::appendPattern(const QVector<double> &input, const QVector<double> &target)
//{
//	appendPattern(input.toStdVector(), target.toStdVector());
//}

//void TrainingSetDialog::appendPattern(const QVector<int> &input, const QVector<int> &target)
//{
//	appendPattern(input.toStdVector(), target.toStdVector());
//}

void TrainingSetDialog::removePattern(int i)
{
	ui->patternTable->removeRow(i);
}

int TrainingSetDialog::getPatternCount()
{
	return ui->patternTable->rowCount();
}

void TrainingSetDialog::setTrainingSet(TrainingSet *ts)
{
	ui->patternTable->clear();

	int sTs = ts->getPatternCount();
	vector<vector<double> >
			inputs = ts->getInputs(),
			targets = ts->getTargets();

	for(int i = 0; i < sTs; i++){
		appendPattern(inputs[i], targets[i]);
	}
}

TrainingSet *TrainingSetDialog::getTrainingSet() const
{
	return new TrainingSet(getInputs(), getTargets());
}

void TrainingSetDialog::on_addPatternButton_clicked()
{
	ui->patternTable->setRowCount(ui->patternTable->rowCount()+1);
}

void TrainingSetDialog::on_delPatternButton_clicked()
{
	ui->patternTable->removeRow(ui->patternTable->currentRow());
	//    ui->patternTable->selectedItems();
}

void TrainingSetDialog::initDialog(int inputs, int outputs)
{
	ui->setupUi(this);

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

}

void TrainingSetDialog::initDialog(const vector<vector<double> > &inputs, const vector<vector<double> > &targets)
{
	ui->setupUi(this);

	ui->gvRepresentation->setVisible(false);

	fileDialog = new QFileDialog(this);
	imgRepresentation = new QImage(ui->sbWidth->value(), ui->sbHeight->value(), QImage::Format_RGB888);
	giedw = new GraphicImageElementDetailedWindow(imgRepresentation, this);
	ui->hlRepresentation->addWidget(giedw);

	QMenu *file = new QMenu(tr("Archivo"));
	file->addAction("Desde archivo...", this, SLOT(fromFile()));
	file->addAction("Desde imagenes...", this, SLOT(fromImages()));

	menuBar = new QMenuBar(this);
	menuBar->addMenu(file);
	layout()->setMenuBar(menuBar);

	const int nPatterns = inputs.size();
	//	size_t sInputs, sTargets;
	for(int i = 0; i < nPatterns; i++){
		appendPattern(inputs[i], targets[i]);
	}

	ui->patternTable->selectRow(0);

	//image initialization
//	QGraphicsScene *scn = new QGraphicsScene();

//	itm = scn->addPixmap(QPixmap::fromImage(*imgRepresentation));
	giedw->setImage(imgRepresentation);
//	giedw->getGraphicsView()->setScene(scn);
//	ui->gvRepresentation->setScene(scn);
}

void TrainingSetDialog::initDialog(const vector<MultilayerPerceptronPattern*> ts)
{
	ui->setupUi(this);

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
}

void TrainingSetDialog::updateHeaders()
{
	QStringList headers;
	for(int i = 0; i < inputSize; i++){
		headers.append("In " + QString::number(i+1));
	}
	for(int i = inputSize; i < inputSize + targetSize; i++){
		headers.append("Out " + QString::number(i - inputSize + 1));
	}
	ui->patternTable->setHorizontalHeaderLabels(headers);
}

void TrainingSetDialog::updateRepresentation()
{
	vector<vector<double> > inputs = getInputs();
	int
			h = imgRepresentation->height(),
			w = imgRepresentation->width(),
			cr = ui->patternTable->currentRow();

	if(cr == -1) return;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			imgRepresentation->setPixel(j, i, inputs[cr][w*i + j] > 0 ? 0xffffffff: 0xff000000);
		}
	}
//	QGraphicsPixmapItem *pmItm = dynamic_cast<QGraphicsPixmapItem*>(itm);
//	QGraphicsPixmapItem *pmItm = giedw->getGraphicsPixmapItem();
//	pmItm->setPixmap(QPixmap::fromImage(*imgRepresentation));

	giedw->setImage(imgRepresentation);

//	giedw->getGraphicsView()->scene()->setSceneRect(pmItm->boundingRect());
//	giedw->getGraphicsView()->update();

//	ui->gvRepresentation->scene()->setSceneRect(pmItm->boundingRect());
//	ui->gvRepresentation->update();
}

void TrainingSetDialog::fromFile()
{

//	QString file = QFileDialog::getOpenFileName(this, "Abrir archivo", "", "Archivos de datos (*.csv *.xls *.txt *.xml)");
//	QStringList filters;
//	filters << "Archivos de datos (*.csv *.xls *.xml)"
//			<< "Archivos de texto (*.txt)"
//			<< "Any files (*)";

//	fileDialog->setFileMode(QFileDialog::ExistingFile);
//	fileDialog->setNameFilters(filters);

//	file = fileDialog->getOpenFileName(this, "Abrir archivo");
}

void TrainingSetDialog::fromImages()
{
	QStringList files = QFileDialog::getOpenFileNames(this, "Abrir archivo", "", "Bitmap (*.bmp);; Portable Network Graphic (*.png);; JPEG Image (*.jpg);; (*.gif)");

	foreach(QString file, files){
		appendPattern(CommonFunctions::imageToIntVector(QImage(file), CommonFunctions::Bipolar), vector<int>(targetSize, 0));
	}
	ui->patternTable->setCurrentCell(ui->patternTable->rowCount()-1, 0);
	updateRepresentation();
}

void TrainingSetDialog::on_patternTable_cellChanged(int row, int column)
{
	vector<vector<double> > inputs = getInputs();
	int
			i, j,
//			h = imgRepresentation->height(),
			w = imgRepresentation->width(),
			cr = ui->patternTable->currentRow();

	//	column = w*i + j;
	i = column/w;
	j = column - w*i;

	if(cr == -1) return;
	imgRepresentation->setPixel(j, i, inputs[row][column] > 0 ? qRgb(255, 255, 255): qRgb(0, 0, 0));

//	QGraphicsPixmapItem *pmItm = dynamic_cast<QGraphicsPixmapItem*>(itm);
	QGraphicsPixmapItem *pmItm = giedw->getGraphicsPixmapItem();
	pmItm->setPixmap(QPixmap::fromImage(*imgRepresentation));

	giedw->getGraphicsView()->scene()->setSceneRect(pmItm->boundingRect());
	giedw->getGraphicsView()->update();

//	ui->gvRepresentation->scene()->setSceneRect(pmItm->boundingRect());
//	ui->gvRepresentation->update();
}

void TrainingSetDialog::on_sbWidth_valueChanged(int arg1)
{
	*imgRepresentation = imgRepresentation->scaled(arg1, ui->sbHeight->value());
	updateRepresentation();
}

void TrainingSetDialog::on_sbHeight_valueChanged(int arg1)
{
	*imgRepresentation = imgRepresentation->scaled(ui->sbWidth->value(), arg1);
	updateRepresentation();
}

void TrainingSetDialog::on_patternTable_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
	(void)currentColumn;
	(void)previousColumn;
	if(currentRow != previousRow){
		updateRepresentation();
	}
}
