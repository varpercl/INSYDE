#include "addnewmlpdialog.h"
#include "ui_addnewmlpdialog.h"

AddNewMLPDialog::AddNewMLPDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::addNewMLPDialog)
{
	ui->setupUi(this);

	QStringList headers;
	headers.append("Capa");
	headers.append("Elementos");

	ui->tblLayers->setHorizontalHeaderLabels(headers);
}

AddNewMLPDialog::~AddNewMLPDialog()
{
	delete ui;
}



MultilayerPerceptron::TransferFunctionType AddNewMLPDialog::getTransferFunction()
{
	switch(ui->cbTrasnferFunction->currentIndex()){
		case 0:
			return MultilayerPerceptron::Sigmoid;
		case 1:
		default:
			return MultilayerPerceptron::Tanh;
	}
}

int AddNewMLPDialog::getInputSize()
{
	return ui->sbInputSize->value();
}

int AddNewMLPDialog::getOutputSize()
{
	return ui->sbOutputSize->value();
}

double AddNewMLPDialog::getSlope()
{
	return ui->sbSlope->value();
}

vector<int> AddNewMLPDialog::getLayerSizes()
{
	vector<int> sizes;
	int rows = ui->tblLayers->rowCount();
	for(int i = 0; i < rows; i++){
		sizes.push_back(ui->tblLayers->item(i, 1)->text().toInt());
	}
	return sizes;
}

void AddNewMLPDialog::on_buttonBox_accepted()
{
	if(checkLayers()){
		accept();
	}else{
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Critical);
		msgBox.setWindowTitle("Capas incorrectas");
		msgBox.setText("Debe especificar un numero de capas y elementos correctos");
		QPushButton *connectButton = msgBox.addButton(tr("Corregir"), QMessageBox::ActionRole);
		msgBox.setStandardButtons(QMessageBox::Cancel);
		msgBox.setDefaultButton(connectButton);
		int ret = msgBox.exec();
		if(ret == QMessageBox::Cancel){
			reject();
		}
	}
}

void AddNewMLPDialog::on_btnAddLayer_clicked()
{
	bool ok = false;
	QString val = QString::number(QInputDialog::getInt(this,
													   "Numero de elementos",
													   "Neuronas",
													   10,
													   1,
													   999999,
													   1,
													   &ok));
	if(ok){
		ui->tblLayers->setRowCount(ui->tblLayers->rowCount() + 1);
//		ui->tblLayers->setItem(ui->tblLayers->rowCount()-1, 1, new QTableWidgetItem(val));

		QTableWidgetItem *layerNumberCell = new QTableWidgetItem(QString::number(ui->tblLayers->rowCount()));
		layerNumberCell->setFlags(Qt::ItemIsEnabled);
		layerNumberCell->setTextAlignment(Qt::AlignHCenter);
		ui->tblLayers->setItem(ui->tblLayers->rowCount()-1, 0, layerNumberCell);
		QTableWidgetItem *nElementsCell = new QTableWidgetItem(val);
		nElementsCell->setTextAlignment(Qt::AlignHCenter);
		ui->tblLayers->setItem(ui->tblLayers->rowCount()-1, 1, nElementsCell);
	}
}

void AddNewMLPDialog::on_btnDeleteLayer_clicked()
{
	ui->tblLayers->setRowCount(ui->tblLayers->rowCount() - 1);
}

void AddNewMLPDialog::on_buttonBox_rejected()
{
	reject();
}

bool AddNewMLPDialog::checkLayers()
{
	if(ui->sbInputSize->value() > 0 && ui->sbOutputSize->value() > 0){
		if(ui->tblLayers->rowCount() > 0){
			for(int i = 0; i < ui->tblLayers->rowCount(); i++){
				if(ui->tblLayers->item(i, 1)->text().toInt() == 0){
					return false;
				}
			}
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}
