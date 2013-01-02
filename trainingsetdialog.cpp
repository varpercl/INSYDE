#include "trainingsetdialog.h"
#include <letterdeclarations.h>

TrainingSetDialog::TrainingSetDialog(TrainingSetType type, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TrainingSetDialog),
	inputCount(1),
	targetCount(1)
{
	initDialog(1, 1);
	loadMLPData();
}

TrainingSetDialog::TrainingSetDialog(int inputCount, int outputCount, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TrainingSetDialog),
	targetCount(outputCount)
{
	initDialog(inputCount, outputCount);
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

void TrainingSetDialog::setOutputSize(int size)
{
	targetCount = size;
	ui->patternTable->setColumnCount(targetCount + inputCount);
	updateHeaders();
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
	setOutputSize(outputs);

	loadMLPData();
}

void TrainingSetDialog::initDialog(const vector<vector<double> > &inputs, const vector<vector<double> > &targets)
{
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

void TrainingSetDialog::loadMLPData()
{
	const int nPatterns = 26;
	for(int i = 0; i < nPatterns; i++){
		ui->patternTable->setRowCount(ui->patternTable->rowCount()+1);
		for(int j = 0; j < 35; j++){
			QTableWidgetItem *itm = new QTableWidgetItem();
			itm->setText(QString::number(letters[i][j]));
			ui->patternTable->setItem(i, j, itm);
		}
		for(int j = 0; j < 26; j++){
			QTableWidgetItem *itm = new QTableWidgetItem();
			itm->setText(QString::number(LetterTargets[i][j]));
			ui->patternTable->setItem(i, j + inputCount, itm);
		}
	}
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

