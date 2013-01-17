#include "perceptronpage.h"
#include "ui_perceptronpage.h"

PerceptronPage::PerceptronPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::PerceptronPage)
{
    ui->setupUi(this);

    initPage();
}

PerceptronPage::~PerceptronPage()
{
    delete ui;
}

void PerceptronPage::updatePerceptron()
{
    on_sbInputs_editingFinished();
    tupdate.stop();
}

void PerceptronPage::initPage()
{
    SimplePerceptron::TransferFunctionType tf = (SimplePerceptron::TransferFunctionType)(ui->cbTransferFunction->currentIndex());
    SimplePerceptron::LearningRule lr = (SimplePerceptron::LearningRule)(ui->cbLearningRule->currentIndex());

    perceptron = new PerceptronDetailedDisplay(new SimplePerceptron(ui->sbInputs->value(), tf, lr));
    ui->gvPerceptronDisplay->setRenderHint(QPainter::Antialiasing, true);
    ui->gvPerceptronDisplay->setScene(perceptron);

    connect(&tupdate, SIGNAL(timeout()), SLOT(updatePerceptron()));
}

void PerceptronPage::on_sbInputs_valueChanged(int arg1)
{
    Q_UNUSED(arg1);

    tupdate.start(300);
}

void PerceptronPage::on_sbInputs_editingFinished()
{
    perceptron->setInputSize(ui->sbInputs->value());
}

void PerceptronPage::on_cbTransferFunction_currentIndexChanged(int index)
{
    perceptron->getPerceptron()->setTransferFunction((SimplePerceptron::TransferFunctionType)index);
}

void PerceptronPage::on_cbLearningRule_currentIndexChanged(int index)
{
    perceptron->getPerceptron()->setLearningRule((SimplePerceptron::LearningRule) index);
}

void PerceptronPage::on_btnTrainingSet_clicked()
{
    TrainingSetDialog *tsd = new TrainingSetDialog(ui->sbInputs->value(), 1);
    tsd->setModal(true);
    tsd->show();
}
