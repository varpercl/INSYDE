#include "adddotmatrixdialog.h"

core::AddDotMatrixDialog::AddDotMatrixDialog(QWidget *parent) :
	BasicDialog(parent)
{
	init(10, 10);
}

core::AddDotMatrixDialog::AddDotMatrixDialog(int rows, int cols, QWidget *parent) :
	BasicDialog(parent)
{
	init(rows, cols);
}

core::AddDotMatrixDialog::~AddDotMatrixDialog()
{

}

int core::AddDotMatrixDialog::getRows()
{
	return iswSize->getHeight();
}

int core::AddDotMatrixDialog::getCols()
{
	return iswSize->getWidth();
}

core::DotMatrix::DataType core::AddDotMatrixDialog::getDataType()
{
	switch(lcbDataType->getComboBox()->currentIndex()){
		case 1:
            return core::DotMatrix::Bipolar;
		case 0:
		default:
            return core::DotMatrix::Unipolar;
	}
}

void core::AddDotMatrixDialog::init(int rows, int cols)
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
