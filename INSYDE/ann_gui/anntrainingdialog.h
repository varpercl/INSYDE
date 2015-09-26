#ifndef ANNTRAININGDIALOG_H
#define ANNTRAININGDIALOG_H

#include <QtGui>

#include <KDChart/KDChart>
#include <KDChart/KDChartPlotter>
#include <KDChart/KDChartThreeDBarAttributes>

#include "samplesdialog.h"
#include "simulatedannealingwidget.h"
#include "trainingsetdialog.h"
#include "graphicmlpelement.h"
#include "weighteditordialog.h"

#include "../core/labeledintegerspinbox.h"
#include "../core/common.h"
#include "../core/icons.h"
#include "../core/basicdialog.h"
#include "../core/labeledcombobox.h"
#include "../core/labeledintegerspinbox.h"

#include "../ann_base/mlp.h"


class TrainingSetDialog;
class GraphicMLPElement;


/*!
 * \class
 *
 * \brief The ANNTrainingDialog class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class Q_DECL_EXPORT ANNTrainingDialog : public BasicDialog
{
	public:

		/*!
		 * \brief ANNTrainingDialog
		 * \param mlp
		 * \param ts
		 * \param parent
		 */
		explicit ANNTrainingDialog(MultilayerPerceptron *mlp, TrainingSet *ts, QWidget *parent = 0);

		/*!
		 * \brief ANNTrainingDialog
		 * \param mlp
		 * \param ts
		 * \param vs
		 * \param testset
		 * \param parent
		 */
		explicit ANNTrainingDialog(MultilayerPerceptron *mlp, TrainingSet *ts, TrainingSet *vs, TrainingSet *testset, QWidget *parent = 0);

		/*!
		 * TODO: Evaluate if this should be removed, could be deprecated
		 * \brief ANNTrainingDialog
		 * \param gmlp
		 * \param parent
		 */
		explicit ANNTrainingDialog(GraphicMLPElement *gmlp, QWidget *parent = 0);

		~ANNTrainingDialog();

		void setTrainingSet(TrainingSet *ts);
		TrainingSet *getTrainingSet() const;

		void setValidationSet(TrainingSet *vs);
		TrainingSet *getValidationSet() const;

		void setTestSet(TrainingSet *ts);
		TrainingSet *getTestSet() const;

		void setMultilayerPerceptron(MultilayerPerceptron *mlp);
		MultilayerPerceptron *getMultilayerPerceptron() const;

		void saveClick();


		/*!
		 * \brief canEditANNType Indicate if user can change ANN type. This implies a partial or total restructuration
		 * of ANNTrainingDialog to adapt to ANN properties.
		 *
		 * \param b
		 *
		 * TODO: 5/9/15 implement canChangeANNType
		 */
		void canEditANNType(bool b);

		/*!
		 * \brief canEditInputSize Indicate if user can edit ANN input size. It's restrictive for some cases, for
		 * example, SimplePerceptron, ADALINE, HOPFIELD, wich have particular output/input size properties.
		 * \param b
		 */
		void canEditInputSize(bool b);

		/*!
		 * \brief canEditOutputSize Indicate if user can edit ANN output size. It's restrictive for some cases, for
		 * example, SimplePerceptron, ADALINE, HOPFIELD, wich have particular output/input size properties.
		 * \param b
		 */
		void canEditOutputSize(bool b);

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
		void updateStatusLabels(MLPTrainingResult tres);

		//Eventos de controles
		void onBtnEditTrainingSetClicked();

		void onTrainingAlgorithmChanged(int index);

		void onTrasnferFunctionChanged(int index);

		void onTrainClicked();

		void onStopTrainingClicked();

		void onClearChartClicked();

		void onCancelClicked();

		void onBtnRandomizeClicked();

		void onEditWeightsClicked();

		void onBtnEditValidationTestClicked();

		void onBtnEditTestSetClicked();

		void onBtnAddLayerClicked();

		void onDeleteLayerClicked();

		void onMultipleTrainingClicked();

		void onCbStopConditionCurrentIndexChanged(int index);

		void onChkSimAnnToggled(bool checked);

		void generateReport();

	private:
		Q_OBJECT

		enum TrainingStatus{
			Running,
			Finished,
			Pausing,
			Paused,
			Stopping,
			Stopped
		};

		WeightEditorDialog *weightEditor;

		TrainingStatus currentTrainingStatus;

		QMenu
		*mnuTraining,
		*mnuWeights;

		LabeledIntegerSpinBox
		*lisbInputs,
		*lisbOutputs;

		LabeledDoubleSpinBox
		*ldsbRndFrom,
		*ldsbRndTo,
		*ldsbThreshold,
		*ldsbSlope,
		*ldsbLearningRate,
		*ldsbMinError;

		LabeledComboBox
		*lcbAlgorithm,
		*lcbTransferFunction;

		QVBoxLayout
		*vlyMainScrollArea,
		*vlyToolButtons,
		*vlyTrainingConditions,
		*vlyStopConditionBox,
		*vlyOptimizationInternalLayout,
		*vlyOptimizationWidget;

		QHBoxLayout
		*lyInitialSettings,
		*hlyLayers,
		*hlyStopConditionError,
		*hlyRandomize;

		QScrollArea
		*scrollArea,
		*saOptimization;

		QWidget
		*scrollAreaContent,
		*wOptimizations;

		QGroupBox
		*gbProperties,
		*gbStopCondition,
		*gbOptimization,
		*gbPlotter;

		QFormLayout *flyPropertiesBox;

		QLabel
		*lblTime;

		QToolButton
		*btnAddLayer,
		*btnDeleteLayer,
		*btnTraining,
		*btnWeights;

		QSpacerItem
		*verticalSpacer,
		*horizontalSpacer_2;

		QComboBox
		*cbStopCondition;

		QPushButton
		*btnEditTrainingSet,
		*btnEditValidationSet,
		*btnEditTestSet;

		QTreeView *tblLayers;

		QCheckBox *chkSA;

		QVBoxLayout *vlyPlotter;

		QAction
		*actionEditWeights,
		*actionRandomizeWeights,
		*actionClearChart,
		*actionMultipleTraining,
		*actionStartTraining,
		*actionStopTraining;

		QMutex mutex;
		//		MLPTrainingResult *trainingResults;

		KDChart::Legend *legend;

		KDChart::CartesianAxis
		*xAxis,
		*yAxis;

		KDChart::Plotter *plotter;

		KDChart::Chart *chart;

		SimulatedAnnealingWidget *wSimulatedAnnealing;

		LabeledIntegerSpinBox *lisbEpochs;

		int fileIndex;

		//Ruta del archivo de resultados multiples
		QString multipleReportPath;

		QAction *genReport;

		QMenuBar *menuBar;

		//Algoritmo que se usara para el entrenamiento de la red neuronal
		MultilayerPerceptron::TrainingAlgorithm ta;

		//Resultado obtenido de la red neuronal
		MLPTrainingResult
		*tres,
		*plotterTrainingData;

		//Medicion de tiempo
		clock_t time;

		//Conjuntos de entrenamientos y pruebas
		TrainingSet
		*trainingSet,
		*validationSet,
		*testSet;

		ANNModelWrapper *annModel;

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

		void updateSAControls();

		/*!
		 * \brief updateActionClearChart
		 */
		void updateActionClearChart();

		/*!
		 * \brief isValidTrainingSet Determines wether \code{ts} is a valid training set. This means having the same
		 * inputs and targets number as MultilayerPerceptron have.
		 * \param ts Training set to be validated
		 * \return
		 */
		bool isValidTrainingSet(TrainingSet *ts);

		void setTrainingStatus(TrainingStatus ts);

		void updateTableLayers();
};

#endif // MLPTRAININGDIALOG_H

