#ifndef FRMWEIGHTSEDITOR_H
#define FRMWEIGHTSEDITOR_H

#include <QtWidgets>

#include "ANNFramework/simpleperceptron.h"

namespace Ui {
class frmWeightsEditor;
}

class WeightsEditorDialog : public QDialog
{
		Q_OBJECT
		
	public:
		explicit WeightsEditorDialog(SimplePerceptron *sp, QWidget *parent = 0);
		~WeightsEditorDialog();
		
		void setSimplePerceptron(SimplePerceptron *sp);
		SimplePerceptron *getSimplePerceptron() const;

		void setWeights(vector<double> weights);
		vector<double> getWeights() const;

	private:

		SimplePerceptron *sp;
		QFileDialog *fileDialog;
		Ui::frmWeightsEditor *ui;

		void initWE(SimplePerceptron *sp);

	private slots:
		void fromFile();
};

#endif // FRMWEIGHTSEDITOR_H
