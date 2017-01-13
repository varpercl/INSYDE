#include "addnewmlpdialog.h"
#include "ui_addnewmlpdialog.h"

ann_gui::AddNewMLPDialog::AddNewMLPDialog(QWidget *parent) :
	BasicDialog(parent)
{
	init();
}

ann_gui::AddNewMLPDialog::~AddNewMLPDialog()
{

}

MultilayerPerceptron::TransferFunctionType ann_gui::AddNewMLPDialog::getTransferFunction()
{
	switch(lcbTrasnferFunction->getComboBox()->currentIndex()){
		case 0:
			return MultilayerPerceptron::Sigmoid;
		case 1:
		default:
			return MultilayerPerceptron::Tanh;
	}
}

int ann_gui::AddNewMLPDialog::getInputSize()
{
	return lisbInputSize->getValue();
}

int ann_gui::AddNewMLPDialog::getOutputSize()
{
	return lisbOutputSize->getValue();
}

double ann_gui::AddNewMLPDialog::getSlope()
{
	return ldsbSlope->getValue();
}

vector<int> ann_gui::AddNewMLPDialog::getLayerSizes()
{
	vector<int> sizes;
	int rows = tblLayers->rowCount();
	for(int i = 0; i < rows; i++){
		sizes.push_back(tblLayers->item(i, 1)->text().toInt());
	}
	return sizes;
}

void ann_gui::AddNewMLPDialog::accept()
{
	if(checkLayers()){
		done(1);
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
			done(0);
		}
	}
}

void ann_gui::AddNewMLPDialog::on_btnAddLayer_clicked()
{
	tblLayers->setRowCount(tblLayers->rowCount() + 1);
	//		tblLayers->setItem(tblLayers->rowCount()-1, 1, new QTableWidgetItem(val));

	QTableWidgetItem *layerNumberCell = new QTableWidgetItem(QString::number(tblLayers->rowCount()));
	layerNumberCell->setFlags(Qt::ItemIsEnabled);
	layerNumberCell->setTextAlignment(Qt::AlignHCenter);
	tblLayers->setItem(tblLayers->rowCount()-1, 0, layerNumberCell);
	QTableWidgetItem *nElementsCell = new QTableWidgetItem("20");
	nElementsCell->setTextAlignment(Qt::AlignHCenter);
	tblLayers->setItem(tblLayers->rowCount()-1, 1, nElementsCell);
}

void ann_gui::AddNewMLPDialog::on_btnDeleteLayer_clicked()
{
	tblLayers->setRowCount(tblLayers->rowCount() - 1);
}

void ann_gui::AddNewMLPDialog::on_buttonBox_rejected()
{
	reject();
}

void ann_gui::AddNewMLPDialog::init()
{
	//QVBoxLayout
	mainLayout = new QVBoxLayout();
	vlyBtnLayout = new QVBoxLayout();

	//QHBoxLayout
	hlyLayers = new QHBoxLayout();

	//LabeledIntegerSpinBox
	lisbInputSize = new LabeledIntegerSpinBox("Entradas", 20);
	lisbOutputSize = new LabeledIntegerSpinBox("Salidas", 10);

	//QTableWidget
	tblLayers = new QTableWidget();

	btnAddLayer = new QToolButton();
	btnDeleteLayer = new QToolButton();

	lcbTrasnferFunction = new LabeledComboBox(QString::fromLatin1("Función de transferencia"), QStringList()<< "Sigmoide" << "Tangente hiperbolica");


	QStringList headers;
	headers.append("Capa");
	headers.append("Elementos");

	tblLayers->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
	tblLayers->setAlternatingRowColors(true);
	tblLayers->setColumnCount(2);
	tblLayers->horizontalHeader()->setCascadingSectionResizes(false);
//    tblLayers->horizontalHeader()->setDefaultSectionSize(74);
//    tblLayers->horizontalHeader()->setMinimumSectionSize(27);
//    tblLayers->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
	tblLayers->horizontalHeader()->setStretchLastSection(false);
	tblLayers->horizontalHeader()->setVisible(true);
	tblLayers->verticalHeader()->setVisible(false);
	tblLayers->setHorizontalHeaderLabels(headers);

	hlyLayers->addWidget(tblLayers);

	btnAddLayer->setIcon(ICON_PLUS);
	btnAddLayer->setText("Add layer");

	btnDeleteLayer->setIcon(ICON_MINUS);
	btnDeleteLayer->setText("Remove layer");

	vlyBtnLayout->addWidget(btnAddLayer);
	vlyBtnLayout->addWidget(btnDeleteLayer);
	vlyBtnLayout->addStretch(1);

	hlyLayers->addLayout(vlyBtnLayout);

	mainLayout->addWidget(lisbInputSize);
	mainLayout->addWidget(lisbOutputSize);
	mainLayout->addLayout(hlyLayers);
	mainLayout->addWidget(lcbTrasnferFunction);

	getMainWindow()->centralWidget()->setLayout(mainLayout);

	setApplyButtonVisible(false);
	setHelpButtonVisible(false);
	getMainWindow()->menuBar()->hide();
	getMainToolbar()->hide();

	on_btnAddLayer_clicked();

	connect(btnAddLayer, SIGNAL(clicked()), SLOT(on_btnAddLayer_clicked()));
	connect(btnDeleteLayer, SIGNAL(clicked()), SLOT(on_btnDeleteLayer_clicked()));
	getAcceptButton()->disconnect(SIGNAL(clicked()));
	connect(getAcceptButton(), SIGNAL(clicked()), SLOT(accept()));
}

bool ann_gui::AddNewMLPDialog::checkLayers()
{
	if(lisbInputSize->getValue() > 0 && lisbOutputSize->getValue() > 0){
		if(tblLayers->rowCount() > 0){
			for(int i = 0; i < tblLayers->rowCount(); i++){
				QString txtItem(tblLayers->item(i, 1)->text());
				int value = txtItem.toInt();
				if(value == 0){
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
