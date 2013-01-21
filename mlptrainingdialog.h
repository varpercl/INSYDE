#ifndef MLPTRAININGDIALOG_H
#define MLPTRAININGDIALOG_H

//#include <InSyDeGui.h>
#include <QMessageBox>
#include <QTime>
#include <QTimer>
#include <QFile>
#include <QMenuBar>
#include <QInputDialog>
#include <QVector>
#include <samplesdialog.h>

#include <graphicmlpelement.h>
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

		void trainingFinished(MLPTrainingResult tres);

		void multipleTrainingResult(MLPTrainingResult tres);

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

		void on_cbStopCondition_currentIndexChanged(int index);

		void on_chkSA_toggled(bool checked);

	private:
		Q_OBJECT

		int fileIndex;
		QString multipleReportPath;
		QAction *saveFile;
		//		double minNoise, maxNoise;
		//		double initialAcceptance;
		//		double startCondition;
		//		double Tmin;
		//		int nChanges;
		QMenuBar *menuBar;
		MultilayerPerceptron::TrainingAlgorithm ta;
		MLPTrainingResult tres;
		QTime t;
		clock_t time;
		//		MLPTrainingThread *mlptt;
		bool isTraining;
		QTimer timer;
		//		vector<vector<double> > inputs;
		//		vector<vector<double> > targets;
		GraphicMLPElement *gmlp;
		MultilayerPerceptron *mlp;
		TrainingSetDialog *tsMLP;

		void initDialog(GraphicMLPElement *gmlp);
		void createFile(QString path, MLPTrainingResult tr, int interval);
		void disableAllControls();
		void setSAEnabledControls(bool enabled);
		void setBPEnabledControls(bool enabled);
};

#endif // MLPTRAININGDIALOG_H

