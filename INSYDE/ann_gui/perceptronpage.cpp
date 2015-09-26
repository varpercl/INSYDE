#include "perceptronpage.h"
#include "ui_perceptronpage.h"

PerceptronPage::PerceptronPage(QWidget *parent) :
	QWizardPage(parent),
	ui(new Ui::PerceptronPage)
{
//	initPage();
}

PerceptronPage::~PerceptronPage()
{
	delete ui;
}//~PerceptronPage

void PerceptronPage::setSimplePerceptron(SimplePerceptron *sp)
{
	this->sp = sp;
}//setSimplePerceptron

SimplePerceptron *PerceptronPage::getSimplePerceptron() const
{
	return sp;
}//getSimplePerceptron

void PerceptronPage::updatePerceptron()
{
	on_sbInputs_editingFinished();
	tupdate.stop();
}//updatePerceptron

void PerceptronPage::initializePage()
{
	ui->setupUi(this);

	SimplePerceptron::TransferFunctionType tf = (SimplePerceptron::TransferFunctionType)(ui->cbTransferFunction->currentIndex());
	SimplePerceptron::LearningRule lr = (SimplePerceptron::LearningRule)(ui->cbLearningRule->currentIndex());

	setSimplePerceptron(new SimplePerceptron(ui->sbInputs->value(), tf, lr));
	perceptronDisplay = new PerceptronDisplay(sp);

	wed = new WeightEditorDialog(sp);

	ui->gvPerceptronDisplay->setRenderHint(QPainter::Antialiasing, true);
	ui->gvPerceptronDisplay->setScene(perceptronDisplay);

	connect(&tupdate, SIGNAL(timeout()), SLOT(updatePerceptron()));
}//initializePage

void PerceptronPage::on_sbInputs_valueChanged(int arg1)
{
	Q_UNUSED(arg1);

	tupdate.start(300);
}//on_sbInputs_valueChanged

void PerceptronPage::on_sbInputs_editingFinished()
{
	perceptronDisplay->setInputSize(ui->sbInputs->value());
}//on_sbInputs_editingFinished

void PerceptronPage::on_cbTransferFunction_currentIndexChanged(int index)
{
	sp->setTransferFunction((SimplePerceptron::TransferFunctionType)index);
}//on_cbTransferFunction_currentIndexChanged

void PerceptronPage::on_cbLearningRule_currentIndexChanged(int index)
{
	sp->setLearningRule((SimplePerceptron::LearningRule) index);
}//on_cbLearningRule_currentIndexChanged

void PerceptronPage::on_btnEditWeights_clicked()
{
	wed->exec();
}//on_btnEditWeights_clicked

void PerceptronPage::on_btnEditTrainingSet_clicked()
{
	TrainingSetDialog *tsd = new TrainingSetDialog(ui->sbInputs->value(), 1, 1);
	tsd->exec();

	delete tsd;
}//on_btnEditTrainingSet_clicked
