#include "dotmatrixpropertydialog.h"

core::DotMatrixPropertyDialog::DotMatrixPropertyDialog(DotMatrix *dm, QWidget *parent) :
	PropertiesDialog(dm, parent)
{
	init(dm);
}

core::DotMatrixPropertyDialog::~DotMatrixPropertyDialog()
{

}

void core::DotMatrixPropertyDialog::onApplyClicked()
{
    dm->setMatrixSize(QSize(iswSize->getSize()));
	dm->setDotSize(lisbDotSize->getValue());
	dm->setInputsSize(lisbInputSize->getValue());

	switch(lcbDataTypes->getComboBox()->currentIndex()){
		case 0:
			dm->setDataType(DotMatrix::Unipolar);
			break;
		case 1:
			dm->setDataType(DotMatrix::Bipolar);
			break;
	}

}

void core::DotMatrixPropertyDialog::accept()
{
	onApplyClicked();

	close();
//	GraphicObjectPropertyDialog::accept(); //infinite loop
}

void core::DotMatrixPropertyDialog::init(DotMatrix *dm)
{
	//Initialize QVBoxLayout
	mainLayout = new QVBoxLayout();
	vlyGBConfig = new QVBoxLayout();
	vlyGBView = new QVBoxLayout();

	//Initialize QGroupBox
	gbConfig = new QGroupBox();
	gbView = new QGroupBox();

	//Initialize IntegerSizeWidget
	iswSize = new IntegerSizeWidget(dm->getMatrixSize(), qMakePair(IntegerSizeWidget::Dots, IntegerSizeWidget::Dots));

	//Initialize LabeledIntegerSpinBox
	lisbDotSize = new LabeledIntegerSpinBox(QString::fromLatin1("Tamaño de recuadro"), dm->getDotSize());
	lisbInputSize = new LabeledIntegerSpinBox(QString::fromLatin1("Tamaño de entrada"), dm->getInputsSize());

	//Initialize LabeledComboBox
	lcbDataTypes = new LabeledComboBox("Tipo de dato", QStringList() << "Unipolar" << "Bipolar");


	this->dm = dm;

	iswSize->setMinimumSizeValues(1, 1);

	vlyGBConfig->addWidget(lisbInputSize);
	vlyGBConfig->addWidget(iswSize);
	vlyGBConfig->addWidget(lcbDataTypes);

	gbConfig->setTitle("Propiedades");
	gbConfig->setLayout(vlyGBConfig);

	vlyGBView->addWidget(lisbDotSize);

	gbView->setTitle(QString::fromLatin1("Visualización"));
	gbView->setLayout(vlyGBView);


	mainLayout->addWidget(gbConfig);
	mainLayout->addWidget(gbView);
	mainLayout->addStretch(1);

	getMainWindow()->centralWidget()->setLayout(mainLayout);

	connect(this, SIGNAL(accepted()), SLOT(accept()));

}
