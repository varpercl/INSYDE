#ifndef MLPTRAININGDIALOG_H
#define MLPTRAININGDIALOG_H

#include <QtGui>
#include "samplesdialog.h"

#include "../INSYDEUI_global.h"
#include "trainingsetdialog.h"
#include "graphicmlpelement.h"
#include "ANNFramework/multilayerperceptron.h"

namespace Ui {
	class MLPTrainingDialog;
}

class TrainingSetDialog;
class GraphicMLPElement;

class INSYDEUISHARED_EXPORT MLPTrainingDialog : public QDialog
{

	public:
		Ui::MLPTrainingDialog *ui;

		//		explicit MLPTrainingDialog(MultilayerPerceptron *gmlp, QWidget *parent = 0);
		explicit MLPTrainingDialog(GraphicMLPElement *gmlp, QWidget *parent = 0);
		~MLPTrainingDialog();

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
		void trainingFinished(MLPTrainingResult *tres);

		/**
		 * @brief multipleTrainingResult Devuelve el resultado obtenido al realizar multiples entrenamientos
		 * @param tres Resultado devuelto
		 */
		void multipleTrainingResult(MLPTrainingResult *tres);

		/**
		 * @brief updateStatusLabels Actualiza las etiquetas que indican los valores actuales del entrenamiento red neuronal
		 */
		void updateStatusLabels();

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

	private:
		Q_OBJECT

		int fileIndex;

		//Ruta del archivo de resultados multiples
		QString multipleReportPath;
		QAction *saveFile;
		//		double minNoise, maxNoise;
		//		double initialAcceptance;
		//		double startCondition;
		//		double Tmin;
		//		int nChanges;
		QMenuBar *menuBar;

		//Algoritmo que se usara para el entrenamiento de la red neuronal
		MultilayerPerceptron::TrainingAlgorithm ta;

		//Resultado obtenido de la red neuronal
		MLPTrainingResult *tres;

		//Contador de tiempo de entrenamiento
		QTime t;

		//Medicion de tiempo
		clock_t time;
		//		MLPTrainingThread *mlptt;

		//Si esta entrenando
		bool isTraining;

		//Temporizador para actualizacion de las etiquetas de estatus
		QTimer timer;
		//		vector<vector<double> > inputs;
		//		vector<vector<double> > targets;

		//Objeto grafico del Multilayer Perceptron
		GraphicMLPElement *gmlp;

		//Objeto con la algoritmia para el entrenamiento del MLP
		MultilayerPerceptron *mlp;

		//Cuadro de dialogo del conjunto de entrenamiento
		TrainingSetDialog *tsMLP;

		/**
		 * @brief initDialog Es un metodo auxiliar para inicializar el cuadro de dialogo
		 * @param gmlp Elemento MLP grafico que se le asignara
		 */
		void initDialog(GraphicMLPElement *gmlp);

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
		 * @brief setSAEnabledControls Deshabilita los controles usados para Simulated Annealing. Generalmente usado
		 *cuando solo se usa Backpropagation
		 * @param enabled Indica si se bloquean o desbloquean
		 */
		void setSAEnabledControls(bool enabled);

		/**
		 * @brief setBPEnabledControls Habilita o deshabilita los controles para BackPropagation
		 * @param enabled Indica si se habilitara o deshabilitara
		 */
		void setBPEnabledControls(bool enabled);
};

#endif // MLPTRAININGDIALOG_H

