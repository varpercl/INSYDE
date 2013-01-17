#ifndef SAMPLESDIALOG_H
#define SAMPLESDIALOG_H

#include <QDialog>
#include <ANNFramework/multilayerperceptron.h>

namespace Ui {
	class SamplesDialog;
}

class SamplesDialog : public QDialog
{
		
	public:
		explicit SamplesDialog(MultilayerPerceptron::TrainingResult tr, QWidget *parent = 0);
		~SamplesDialog();
		
		int getSampleCount();

	private slots:
		void on_cbAllSamples_toggled(bool checked);

	private:

		Q_OBJECT

		MultilayerPerceptron::TrainingResult tres;
		Ui::SamplesDialog *ui;

		void initDialog(MultilayerPerceptron::TrainingResult tr);
};

#endif // SAMPLESDIALOG_H
