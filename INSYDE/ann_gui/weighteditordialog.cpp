#include "weighteditordialog.h"

ann_gui::WeightEditorDialog::WeightEditorDialog(QWidget *parent) :
	BasicDialog(parent)
{
	init();
}

ann_gui::WeightEditorDialog::WeightEditorDialog(ArtificialNeuralNetwork *sp, QWidget *parent) :
	BasicDialog(parent)
{
	init(sp);
}

ann_gui::WeightEditorDialog::WeightEditorDialog(ANNModelWrapper *mw, QWidget *parent) :
	BasicDialog(parent)
{
	init(mw);
}

ann_gui::WeightEditorDialog::~WeightEditorDialog()
{

}

void ann_gui::WeightEditorDialog::setArtificialNeuralNetwork(ArtificialNeuralNetwork *sp)
{
	this->ann = sp;
}

ArtificialNeuralNetwork *ann_gui::WeightEditorDialog::getArtificialNeuralNetwork() const
{
	return ann;
}

void ann_gui::WeightEditorDialog::onRandomizeClicked()
{
	model->randomizeWeights(ldsbFrom->getDoubleSpinBox()->value(), ldsbTo->getDoubleSpinBox()->value());
}

void ann_gui::WeightEditorDialog::onUpdateClicked()
{
	emit model->dataChanged(QModelIndex(), QModelIndex());
	//	btWeights->update(QModelIndex());
}

void ann_gui::WeightEditorDialog::onTrainingAboutStart()
{
	btnRandomize->setEnabled(false);
}

void ann_gui::WeightEditorDialog::onTrainingFinished()
{
	btnRandomize->setEnabled(true);
}

void ann_gui::WeightEditorDialog::init()
{
	model = 0;

	setupUI();
}

void ann_gui::WeightEditorDialog::init(ANNModelWrapper *mw)
{
	model = mw;

	setupUI();

	btWeights->setModel(model);
}

void ann_gui::WeightEditorDialog::init(ArtificialNeuralNetwork *ann)
{
	model = new ANNModelWrapper(ann);

	setupUI();

	btWeights->setModel(model);
}

void ann_gui::WeightEditorDialog::setupUI()
{

	//Construct BasicTree
	btWeights = new QTreeView();

	//Construct QToolButton
	btnRandomize = new QToolButton();
	btnUpdate = new QToolButton();

	//Construct LabeledDoubleSpinBox
	ldsbFrom = new LabeledDoubleSpinBox("desde", -0.01);
	ldsbTo = new LabeledDoubleSpinBox("hasta", 0.01);

	//Construct QHBoxLayout
	hlyRandomize = new QHBoxLayout();

	//Construct QVBoxLayout
	mainLayout = new QVBoxLayout();

	centralWidget = getMainWindow()->centralWidget();

	btnUpdate->setIcon(ICON_UPDATE);
	btnUpdate->setText("Actualizar");

	btnRandomize->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	btnRandomize->setIcon(ICON_DICE);
	btnRandomize->setText("Aleatorizar");


	hlyRandomize->addWidget(btnUpdate);
	hlyRandomize->addStretch(10);
	hlyRandomize->addWidget(btnRandomize);
	hlyRandomize->addWidget(ldsbFrom);
	hlyRandomize->addWidget(ldsbTo);

//	btWeights->setAnimated(true);
	btWeights->setSelectionBehavior(QAbstractItemView::SelectItems);
	btWeights->setEditTriggers(QAbstractItemView::DoubleClicked |
							   QAbstractItemView::SelectedClicked |
							   QAbstractItemView::EditKeyPressed);

	mainLayout->addLayout(hlyRandomize);
	mainLayout->addWidget(btWeights);

	centralWidget->setLayout(mainLayout);

	setEnableExport(false);
	setEnableImport(false);
	setEnableNew(false);
	setEnableSave(false);
	setEnableOpen(false);
	setEnableClipboardFramework(false);
	setEnableUnDoFramework(false);

	getRejectButton()->setVisible(false);
	getAcceptButton()->setText("Ok");

	setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowContextHelpButtonHint | Qt::WindowSystemMenuHint);

	setArtificialNeuralNetwork(ann);

	connect(btnRandomize, SIGNAL(clicked()), SLOT(onRandomizeClicked()));
	connect(btnUpdate, SIGNAL(clicked()), SLOT(onUpdateClicked()));

}
