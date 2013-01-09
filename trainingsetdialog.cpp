#include "trainingsetdialog.h"

TrainingSetDialog::TrainingSetDialog(TrainingSetType type, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TrainingSetDialog),
	inputCount(1),
	targetCount(1)
{
	initDialog(1, 1);
//	loadMLPData();
}

TrainingSetDialog::TrainingSetDialog(int inputCount, int outputCount, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TrainingSetDialog),
	targetCount(outputCount)
{
	initDialog(inputCount, outputCount);
}

TrainingSetDialog::TrainingSetDialog(vector<vector<double> > inputs, vector<vector<double> > targets, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TrainingSetDialog),
	targetCount(targets[0].size())
{
	initDialog(inputs, targets);
}

TrainingSetDialog::TrainingSetDialog(vector<MultilayerPerceptronPattern *> ts, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TrainingSetDialog),
	targetCount(ts.size())
{
	initDialog(ts);
}

vector<vector<double> > TrainingSetDialog::getInputs()
{
	int nRows = ui->patternTable->rowCount();
	inputs = vector<vector<double> > (nRows, vector<double>(inputCount, 0));
	for(int i = 0; i < nRows; i++){
		inputs[i].resize(inputCount);
		for(int j = 0; j < inputCount; j++){
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
	inputCount = size;

	ui->patternTable->setColumnCount(targetCount + inputCount);
	updateHeaders();
}

vector<vector<double> > TrainingSetDialog::getTargets()
{
	int nRows = ui->patternTable->rowCount();
	targets = vector<vector<double> > (nRows, vector<double>(targetCount, 0));
	for(int i = 0; i < nRows; i++){
		for(int j = inputCount; j < ui->patternTable->columnCount(); j++){
			QTableWidgetItem *itm = ui->patternTable->item(i,j);
			if(itm){
				targets[i][j - inputCount] = itm->text().toDouble();
			}else{
				targets[i][j - inputCount] = 0;
			}
		}
	}
	return targets;
}

void TrainingSetDialog::setTargetSize(int size)
{
	targetCount = size;
	ui->patternTable->setColumnCount(targetCount + inputCount);
	updateHeaders();
}

void TrainingSetDialog::appendPattern(vector<double> input, vector<double> target)
{
	setInputSize(input.size());
	setTargetSize(target.size());
	ui->patternTable->setRowCount(ui->patternTable->rowCount() + 1);

	int nRows = ui->patternTable->rowCount();
	for(int i = 0; i < inputCount; i++){
		ui->patternTable->setItem(nRows-1, i, new QTableWidgetItem(QString::number(input[i])));
	}
	for(int j = inputCount; j < inputCount + targetCount; j++){
		ui->patternTable->setItem(nRows-1, j, new QTableWidgetItem(QString::number(target[j-inputCount])));
	}
}

void TrainingSetDialog::appendPattern(vector<int> input, vector<int> target)
{
	setInputSize(input.size());
	setTargetSize(target.size());
	ui->patternTable->setRowCount(ui->patternTable->rowCount() + 1);

	int nRows = ui->patternTable->rowCount();
	for(int i = 0; i < inputCount; i++){
		ui->patternTable->setItem(nRows-1, i, new QTableWidgetItem(QString::number(input[i])));
	}
	for(int j = inputCount; j <  inputCount + targetCount; j++){
		ui->patternTable->setItem(nRows-1, j, new QTableWidgetItem(QString::number(target[j-inputCount])));
	}
}

void TrainingSetDialog::appendPattern(QVector<double> input, QVector<double> target)
{
	setInputSize(input.size());
	setTargetSize(target.size());
	ui->patternTable->setRowCount(ui->patternTable->rowCount() + 1);

	int nRows = ui->patternTable->rowCount();
	for(int i = 0; i < inputCount; i++){
		ui->patternTable->setItem(nRows-1, i, new QTableWidgetItem(QString::number(input[i])));
	}
	for(int j = inputCount; j <  inputCount + targetCount; j++){
		ui->patternTable->setItem(nRows-1, j, new QTableWidgetItem(QString::number(target[j-inputCount])));
	}
}

void TrainingSetDialog::appendPattern(QVector<int> input, QVector<int> target)
{
	setInputSize(input.size());
	setTargetSize(target.size());
	ui->patternTable->setRowCount(ui->patternTable->rowCount() + 1);

	int nRows = ui->patternTable->rowCount();
	for(int i = 0; i < inputCount; i++){
		ui->patternTable->setItem(nRows-1, i, new QTableWidgetItem(QString::number(input[i])));
	}
	for(int j = inputCount; j < inputCount + targetCount; j++){
		ui->patternTable->setItem(nRows-1, j, new QTableWidgetItem(QString::number(target[j-inputCount])));
	}
}

void TrainingSetDialog::removePattern(int i)
{
	ui->patternTable->removeRow(i);
}

int TrainingSetDialog::getPatternCount()
{
	return ui->patternTable->rowCount();
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

	QMenu *file = new QMenu(tr("Archivo"));
	file->addAction("Desde archivo...", this, SLOT(fromFile()));

	menuBar = new QMenuBar(this);
	menuBar->addMenu(file);
	layout()->setMenuBar(menuBar);
	setInputSize(inputs);
	setTargetSize(outputs);

//	loadMLPData();
}

void TrainingSetDialog::initDialog(const vector<vector<double> > &inputs, const vector<vector<double> > &targets)
{
	ui->setupUi(this);

	QMenu *file = new QMenu(tr("Archivo"));
	file->addAction("Desde archivo...", this, SLOT(fromFile()));

	menuBar = new QMenuBar(this);
	menuBar->addMenu(file);
	layout()->setMenuBar(menuBar);

	const int nPatterns = (inputs.size() >= targets.size() ? inputs.size() : targets.size());
	size_t sInputs, sTargets;
	for(int i = 0; i < nPatterns; i++){
		ui->patternTable->setRowCount(ui->patternTable->rowCount()+1);
		sInputs = inputs[i].size();
		for(size_t j = 0; j < sInputs; j++){
			QTableWidgetItem *itm = new QTableWidgetItem();
			itm->setText(QString::number(inputs[i][j]));
			ui->patternTable->setItem(i, j, itm);
		}
		sTargets = targets[i].size();
		for(size_t j = 0; j < sTargets; j++){
			QTableWidgetItem *itm = new QTableWidgetItem();
			itm->setText(QString::number(targets[i][j]));
			ui->patternTable->setItem(i, j + inputCount, itm);
		}
	}
}

void TrainingSetDialog::initDialog(const vector<MultilayerPerceptronPattern *> ts)
{
	ui->setupUi(this);

	QMenu *file = new QMenu(tr("Archivo"));
	file->addAction("Desde archivo...", this, SLOT(fromFile()));

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
	for(int i = 0; i < inputCount; i++){
		headers.append("In " + QString::number(i+1));
	}
	for(int i = inputCount; i < inputCount + targetCount; i++){
		headers.append("Out " + QString::number(i - inputCount + 1));
	}
	ui->patternTable->setHorizontalHeaderLabels(headers);
}

void TrainingSetDialog::fromFile()
{
	QString file = QFileDialog::getOpenFileName(this, "Abrir archivo", "", "Archivos de datos (*.ts *.csv *.xls *.txt *.xml)");
}

//template<class TrainingPattern>
//TrainingSetDialog<TrainingPattern>::TrainingSetDialog(int size, QWidget *parent) :
//    TrainingSetObject(parent)
//{
//    ts.resize(size);
//    ui->patternTable->setRowCount(size);
//}

//template<class TrainingPattern>
//TrainingSetDialog<TrainingPattern>::TrainingSetDialog(QVector<TrainingPattern> ts, QWidget *parent) :
//    TrainingSetObject(parent)
//{

//}

//template<class TrainingPattern>
//void TrainingSetDialog<TrainingPattern>::initTS(QVector<TrainingPattern> ts)
//{
//    this->ts = ts;
//    ui->patternTable->setRowCount(ts.size());
//}

//template<class TrainingPattern>
//void TrainingSetDialog<TrainingPattern>::initTS(int size)
//{
//    ts.resize(size);
//    ui->patternTable->setRowCount(size);
//}


//template<class TrainingPattern>
//void TrainingSetDialog<TrainingPattern>::setTrainingSet(const QVector<TrainingPattern> &ts)
//{
//    this->ts = ts;
//    ui->patternTable->setRowCount(ts.size());
//}

//template<class TrainingPattern>
//QVector<TrainingPattern> TrainingSetDialog<TrainingPattern>::getTrainingSet() const
//{
//    return ts;
//}

