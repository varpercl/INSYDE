#ifndef PERCEPTRONPAGE_H
#define PERCEPTRONPAGE_H

#include <QtWidgets>

#include "share_ann_gui_lib.h"
#include "weighteditordialog.h"
#include "../core/common.h"
#include "trainingsetdialog.h"
#include "perceptrondisplay.h"
#include "../ann_base/simpleperceptron.h"

namespace Ui{
class PerceptronPage;
}

namespace ann_gui
{

class PerceptronDisplay;

/*!
 * \class
 *
 * \brief The PerceptronPage class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_GUI_LIB_IMPORT_EXPORT PerceptronPage : public QWizardPage
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
		WeightEditorDialog *wed;
		SimplePerceptron *sp;
		Ui::PerceptronPage *ui;
		PerceptronDisplay *perceptronDisplay;
		QTimer tupdate;

		void initializePage();

};
}
#endif // PERCEPTRONPAGE_H
