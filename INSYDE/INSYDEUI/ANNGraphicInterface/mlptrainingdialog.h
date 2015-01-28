#ifndef MLPTRAININGDIALOG_H
#define MLPTRAININGDIALOG_H

#include <QtGui>
#include "samplesdialog.h"

#include <KDChart/KDChart>
#include <KDChart/KDChartPlotter>
#include <KDChart/KDChartAbstractDiagram>
#include <KDChart/KDChartLegend>

#include "simulatedannealingwidget.h"
#include "../labeledintegerspinboxwidget.h"
#include "../INSYDEUI_global.h"
#include "trainingsetdialog.h"
#include "graphicmlpelement.h"
#include "ANNFramework/mlp.h"
#include "../progressplotter.h"
#include "../plotterdata.h"

namespace Ui {
	class MLPTrainingDialog;
}

class TrainingSetDialog;
class GraphicMLPElement;

class INSYDEUISHARED_EXPORT MLPTrainingDialog : public QDialog
{
	public:
		Ui::MLPTrainingDialog *ui;

		explicit MLPTrainingDialog(MultilayerPerceptron *mlp, TrainingSet *ts, QWidget *parent = 0);
		explicit MLPTrainingDialog(GraphicMLPElement *gmlp, QWidget *parent = 0);
		~MLPTrainingDialog();

		void setTrainingSet(TrainingSet *ts);
		TrainingSet *getTrainingSet() const;

		void setValidationSet(TrainingSet *vs);
		TrainingSet *getValidationSet() const;

		void setTestSet(TrainingSet *ts);
		TrainingSet *getTestSet() const;

		void setMultilayerPerceptron(MultilayerPerceptron *mlp);
		MultilayerPerceptron *getMultilayerPerceptron() const;

	protected:
		void closeEvent(QCloseEvent *);

	private slots:

		/**
		 * @brief exportData Exporta los datos obtenidos durante el entrenamiento de la red neuronal
		 */
		void exportData();

		/**
		 * @brief trainingFinished Indica cuando ha finalizado el entrenamiento de la red neuronal
		 * @param tres El resultado devuelto por el entrenamiento
		 */
		void onTrainingFinished(MLPTrainingResult tres);

		/**
		 * @brief multipleTrainingResult Devuelve el resultado obtenido al realizar multiples entrenamientos
		 * @param tres Resultado devuelto
		 */
		void multipleTrainingResult(MLPTrainingResult *tres);

		/**
		 * @brief updateStatusLabels Actualiza las etiquetas que indican los valores actuales del entrenamiento red neuronal
		 */
		void updateStatusLabels(const MLPTrainingResult tres);

		//Eventos de controles
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

		void generateReport();

	private:
		Q_OBJECT

		QMutex mutex;
		//		MLPTrainingResult *trainingResults;

		KDChart::Legend *legend;
		KDChart::CartesianAxis
		*xAxis,
		*yAxis;
		KDChart::Plotter *plotter;
		KDChart::Chart *chart;

		SimulatedAnnealingWidget *saWidget;

		LabeledDoubleSpinBoxWidget
		*rndFrom,
		*rndTo,
		*sbThreshold,
		*sbSlope,
		*sbLearningRate;

		LabeledIntegerSpinBoxWidget *sbEpochs;

		int fileIndex;

		//Ruta del archivo de resultados multiples
		QString multipleReportPath;
		QAction
		*saveFile,
		*genReport;
		//		double minNoise, maxNoise;
		//		double initialAcceptance;
		//		double startCondition;
		//		double Tmin;
		//		int nChanges;
		QMenuBar *menuBar;

		//Algoritmo que se usara para el entrenamiento de la red neuronal
		MultilayerPerceptron::TrainingAlgorithm ta;

		//Resultado obtenido de la red neuronal
		MLPTrainingResult
		*tres,
		*plotterTrainingData;

		//Contador de tiempo de entrenamiento
		QTime t;

		//Medicion de tiempo
		clock_t time;
		//		MLPTrainingThread *mlptt;

		//Si esta entrenando
//		bool isTraining;

		//Temporizador para actualizacion de las etiquetas de estatus
//		QTimer timer;
		//		vector<vector<double> > inputs;
		//		vector<vector<double> > targets;

		//Conjuntos de entrenamientos y pruebas
		TrainingSet
		*trainingSet,
		*validationSet,
		*testSet;

		//Objeto con la algoritmia para el entrenamiento del MLP
		MultilayerPerceptron *mlp;

		//Cuadro de dialogo del conjunto de entrenamiento
		TrainingSetDialog
		*trainingSetDialog,
		*validationSetDialog,
		*testSetDialog;

		/*!
		 * \brief init Inicia el cuadro de dialogo
		 * \param imlp Perceptron multicapa asignado
		 * \param ts Conjunto de entrenamiento
		 * \param vs Conjunto de validacion
		 * \param testS Conjunto de pruebas
		 */
		void init(MultilayerPerceptron *imlp, TrainingSet *ts, TrainingSet *vs, TrainingSet *testS);

		/**
		 * @brief createFile Metodo para la creacion de un archivo de resultados de entrenamiento
		 * @param path Ruta del archivo
		 * @param tr Resultado obtenido
		 * @param interval Intervalo que se usara para generar el archivo
		 */
		void createFile(QString path, MLPTrainingResult *tr, int interval);

		/**
		 * @brief disableAllControls Bloquea todos los controles, por lo general usado cuando se inicializa el entrenamiento
		 */
		void disableAllControls();

		/**
		 * @brief setBPEnabledControls Habilita o deshabilita los controles para BackPropagation
		 * @param enabled Indica si se habilitara o deshabilitara
		 */
		void setBPEnabledControls(bool enabled);

};

#endif // MLPTRAININGDIALOG_H

