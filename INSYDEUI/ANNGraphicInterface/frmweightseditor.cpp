#include "frmweightseditor.h"
#include "ui_frmweightseditor.h"

WeightsEditorDialog::WeightsEditorDialog(SimplePerceptron *sp, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::frmWeightsEditor)
{
	initWE(sp);
}

WeightsEditorDialog::~WeightsEditorDialog()
{
	delete ui;
}//~WeightsEditorDialog

void WeightsEditorDialog::setSimplePerceptron(SimplePerceptron *sp)
{
	this->sp = sp;
}//setSimplePerceptron

SimplePerceptron *WeightsEditorDialog::getSimplePerceptron() const
{
	return sp;
}//getSimplePerceptron

void WeightsEditorDialog::setWeights(vector<double> weights)
{
	//TODO: implementar
	(void)weights;
}//setWeights

vector<double> WeightsEditorDialog::getWeights() const
{
	int rows = sp->getInputSize();
	vector<double> newWeights(rows);

	for(int i = 0; i < rows; i++){
		newWeights[i] = ui->weightsTable->item(i, 0)->text().toDouble();
	}

	return newWeights;
}//getWeights

void WeightsEditorDialog::initWE(SimplePerceptron *sp)
{
	ui->setupUi(this);


	fileDialog = new QFileDialog(this);

	//Iniciamos la configuracion de los menus
	QMenu *file = new QMenu(tr("Archivo"));
	file->addAction("Desde archivo...", this, SLOT(fromFile()));
	QMenuBar *menuBar = new QMenuBar(this);
	menuBar->addMenu(file);
	layout()->setMenuBar(menuBar);

	//En este punto se inicia el relleno de la tabla con los valores de los pesos del perceptron

	setSimplePerceptron(sp);
	const int nWeights = sp->getInputSize();
	vector<double> weights = sp->getWeightsVector();

	ui->weightsTable->setColumnCount(1);

	QStringList headers("Wi");
	ui->weightsTable->setHorizontalHeaderLabels(headers);

	QTableWidgetItem *itm;

	ui->weightsTable->setRowCount(weights.size());

	QStringList vertHeaders;
	for(int i = 0; i < nWeights; i++){
		vertHeaders.append(QString::number(i));
		itm = new QTableWidgetItem(QString::number(weights[i]));
		itm->setTextAlignment(Qt::AlignRight);
		ui->weightsTable->setItem(i, 0, itm);
	}
	ui->weightsTable->setVerticalHeaderLabels(vertHeaders);

	ui->weightsTable->selectRow(0);

	//Se configura el comportamiento ante los botones OK y Cancel
	connect(ui->okCancelButtons, SIGNAL(accepted()), SLOT(accept()));
	connect(ui->okCancelButtons, SIGNAL(rejected()), SLOT(reject()));

}//initWE

void WeightsEditorDialog::fromFile()
{
	if(fileDialog->exec() == QDialog::Accepted){
		//TODO: implementar el menu para importar archivos para asignar los pesos al perceptron.
	}
}//fromFile
