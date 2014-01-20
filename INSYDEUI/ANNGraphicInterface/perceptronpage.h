#ifndef PERCEPTRONPAGE_H
#define PERCEPTRONPAGE_H

#include <QWizardPage>

#include "frmweightseditor.h"
#include "../INSYDEUI_global.h"
#include "trainingsetdialog.h"
#include "perceptrondisplay.h"
#include "ANNFramework/simpleperceptron.h"

namespace Ui{
class PerceptronPage;
}

class PerceptronDisplay;

class INSYDEUISHARED_EXPORT PerceptronPage : public QWizardPage
{

	public:
		explicit PerceptronPage(QWidget *parent = 0);
		~PerceptronPage();

		void setSimplePerceptron(SimplePerceptron *sp);
		SimplePerceptron *getSimplePerceptron() const;
	signals:

	public slots:
		void updatePerceptron();

	private slots:
		void on_sbInputs_valueChanged(int arg1);

		void on_sbInputs_editingFinished();

		void on_cbTransferFunction_currentIndexChanged(int index);

		void on_cbLearningRule_currentIndexChanged(int index);

		void on_btnEditWeights_clicked();

		void on_btnEditTrainingSet_clicked();

	private:
		Q_OBJECT

		SimplePerceptron *sp;
		Ui::PerceptronPage *ui;
		PerceptronDisplay *perceptronDisplay;
		QTimer tupdate;

		void initializePage();

};

#endif // PERCEPTRONPAGE_H
