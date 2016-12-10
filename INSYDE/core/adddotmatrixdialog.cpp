#include "adddotmatrixdialog.h"

AddDotMatrixDialog::AddDotMatrixDialog(int rows, int cols, QWidget *parent) :
	BasicDialog(parent)
{
	init(rows, cols);
}

AddDotMatrixDialog::~AddDotMatrixDialog()
{

}

int AddDotMatrixDialog::getRows()
{
	return iswSize->getHeight();
}

int AddDotMatrixDialog::getCols()
{
	return iswSize->getWidth();
}

DotMatrix::DataType AddDotMatrixDialog::getDataType()
{
	switch(lcbDataType->getComboBox()->currentIndex()){
		case 1:
			return DotMatrix::Bipolar;
		case 0:
		default:
			return DotMatrix::Unipolar;
	}
}

void AddDotMatrixDialog::init(int rows, int cols)
{
	//Initialize IntegerSizeWidget
	iswSize = new IntegerSizeWidget(rows, cols, qMakePair(IntegerSizeWidget::Dots, IntegerSizeWidget::Dots));

	//Initialize LabeledComboBox
	lcbDataType = new LabeledComboBox("Tipo de dato", QStringList()<< "Unipolar" << "Bipolar");

	mainLayout = new QVBoxLayout();




	mainLayout->addWidget(iswSize);
	mainLayout->addWidget(lcbDataType);
	mainLayout->addStretch(1);

	getMainWindow()->centralWidget()->setLayout(mainLayout);

	setApplyButtonVisible(false);
	setHelpButtonVisible(false);
	getMainWindow()->menuBar()->hide();
	getMainToolbar()->hide();

//	setFixedSize(sizeHint());
}
