#ifndef PERCEPTRONPAGE_H
#define PERCEPTRONPAGE_H

#include <InSyDeGui.h>
#include <ANNFramework/simpleperceptron.h>

namespace Ui{
    class PerceptronPage;
}

class PerceptronDetailedDisplay;

class PerceptronPage : public QWizardPage
{
        Q_OBJECT


    public:
        explicit PerceptronPage(QWidget *parent = 0);
        ~PerceptronPage();

    signals:

    public slots:
        void updatePerceptron();

    private slots:
        void on_sbInputs_valueChanged(int arg1);

        void on_sbInputs_editingFinished();

        void on_cbTransferFunction_currentIndexChanged(int index);

        void on_cbLearningRule_currentIndexChanged(int index);

        void on_btnTrainingSet_clicked();

    private:
        Ui::PerceptronPage *ui;

//        SimplePerceptron *sp;

        PerceptronDetailedDisplay *perceptron;

        QTimer tupdate;

        void initPage();

};

#endif // PERCEPTRONPAGE_H
