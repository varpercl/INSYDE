#ifndef MLPTRAININGDIALOG_H
#define MLPTRAININGDIALOG_H

#include <InSyDeGui.h>
#include <mlptrainingthread.h>
#include <samplesdialog.h>

#include <ANNFramework/multilayerperceptron.h>

namespace Ui {
	class MLPTrainingDialog;
}
class GraphicMLPElement;
class TrainingSetDialog;

class MLPTrainingDialog : public QDialog
{

	public:
		Ui::MLPTrainingDialog *ui;

		//		explicit MLPTrainingDialog(MultilayerPerceptron *gmlp, QWidget *parent = 0);
		explicit MLPTrainingDialog(GraphicMLPElement *gmlp, QWidget *parent = 0);
		~MLPTrainingDialog();

	protected:
		void closeEvent(QCloseEvent *);

	private slots:
		void exportData();

		void trainingFinished();

		void updateStatusLabels();

		void on_btnEditTrainingSet_clicked();

		void on_cbTrainingAlgorithm_currentIndexChanged(int index);

		void on_cbTrasnferFunction_currentIndexChanged(int index);

		void on_btnTrain_clicked();

		void on_btnCancel_clicked();

		void on_btnRandomize_clicked();

		void onTblLayersCellChanged(int row, int column);


		void on_btnEditValidationTest_clicked();

		void on_btnEditTestSet_clicked();

		void on_btnAddLayer_clicked();

		void on_btnDeleteLayer_clicked();

		void on_btnMultipleTraining_clicked();

	private:
		Q_OBJECT

		QAction *saveFile;
		//		double minNoise, maxNoise;
		//		double initialAcceptance;
		//		double startCondition;
		//		double Tmin;
		//		int nChanges;
		QMenuBar *menuBar;
		MultilayerPerceptron::TrainingAlgorithm ta;
		MultilayerPerceptron::TrainingResult tres;
		QTime t;
		clock_t time;
		MLPTrainingThread *mlptt;
		bool isTraining;
		QTimer timer;
		//		vector<vector<double> > inputs;
		//		vector<vector<double> > targets;
		GraphicMLPElement *gmlp;
		MultilayerPerceptron *mlp;
		TrainingSetDialog *tsMLP;

		void initDialog(GraphicMLPElement *gmlp);
		void createFile(QString path, MultilayerPerceptron::TrainingResult tr, int interval);
		void setEnabledControls(bool enabled);
};

#endif // MLPTRAININGDIALOG_H
