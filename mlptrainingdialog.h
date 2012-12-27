#ifndef MLPTRAININGDIALOG_H
#define MLPTRAININGDIALOG_H

#include <InSyDeGui.h>
#include <RNALibrary/multilayerperceptron.h>

namespace Ui {
	class MLPTrainingDialog;
}

class TrainingSetDialog;

class MLPTrainingDialog : public QDialog
{

	public:
		Ui::MLPTrainingDialog *ui;

		explicit MLPTrainingDialog(MultilayerPerceptron *mlp, QWidget *parent = 0);
		~MLPTrainingDialog();

	private slots:
		void on_btnEditTrainingSet_clicked();

		void on_cbTrainingAlgorithm_currentIndexChanged(int index);

		void on_cbTrasnferFunction_currentIndexChanged(int index);

		void on_btnTrain_clicked();

		void on_btnCancel_clicked();

		void on_btnRandomize_clicked();

	private:
		Q_OBJECT

		vector<vector<double> > inputs;
		vector<vector<double> > targets;
		MultilayerPerceptron *mlp;
		TrainingSetDialog *tsMLP;

		void initDialog(MultilayerPerceptron *mlp);
		void loadMLPData();
};

#endif // MLPTRAININGDIALOG_H
