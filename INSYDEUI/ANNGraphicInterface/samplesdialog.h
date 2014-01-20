#ifndef SAMPLESDIALOG_H
#define SAMPLESDIALOG_H

#include <QDialog>

#include "ANNFramework/multilayerperceptron.h"

namespace Ui {
	class SamplesDialog;
}

class SamplesDialog : public QDialog
{

	public:
		explicit SamplesDialog(MLPTrainingResult *tr, QWidget *parent = 0);
		~SamplesDialog();

		int getSampleCount();

	private slots:
		void on_cbAllSamples_toggled(bool checked);

	private:

		Q_OBJECT

		MLPTrainingResult *tres;
		Ui::SamplesDialog *ui;

		void initDialog(MLPTrainingResult *tr);
};

#endif // SAMPLESDIALOG_H
