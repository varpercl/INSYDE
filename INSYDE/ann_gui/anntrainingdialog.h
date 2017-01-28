#ifndef ANNTRAININGDIALOG_H
#define ANNTRAININGDIALOG_H

#include <QtGui>

#include <KDChart/KDChart>
#include <KDChart/KDChartPlotter>
#include <KDChart/KDChartThreeDBarAttributes>

#include "share_ann_gui_lib.h"
#include "samplesdialog.h"
#include "simulatedannealingwidget.h"
#include "trainingsetdialog.h"
#include "mlpobject.h"
#include "weighteditordialog.h"

#include "../core/labeledintegerspinbox.h"
#include "../core/common.h"
#include "../core/definitions.h"
#include "../core/basicdialog.h"
#include "../core/labeledcombobox.h"
#include "../core/labeledintegerspinbox.h"

#include "../ann_base/mlp.h"
#include "../ann_base/adaline.h"
#include "../ann_base/hopfield.h"
#include "../ann_base/kohonen.h"
#include "../ann_base/simpleperceptron.h"

namespace ann_gui
{

class TrainingSetDialog;
class MLPObject;
/*!
 * \class
 *
 * \brief The ANNTrainingDialog class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_GUI_LIB_IMPORT_EXPORT ANNTrainingDialog : public BasicDialog
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
		 * \param ts Training set
		 * \param vs Validation set
		 * \param testset Test set
		 * \param parent
		 */
		explicit ANNTrainingDialog(MultilayerPerceptron *mlp, TrainingSet *ts, TrainingSet *vs, TrainingSet *testset, QWidget *parent = 0);

		/*!
		 * TODO: Evaluate if this should be removed, could be deprecated
		 * \brief ANNTrainingDialog
		 * \param gmlp
		 * \param parent
		 */
		explicit ANNTrainingDialog(MLPObject *gmlp, QWidget *parent = 0);

		~ANNTrainingDialog();

		/*!
		 * \brief setUsingScrollArea This method stablish if want to show all graph and entire dialog inside a scroll
		 * area. Is suitable when the dialog becomes too big and all controlls don't fit in the screen
		 * \param u Indicate if you want or not to fit all controlls inside a scroll area
		 */
		void setUsingScrollArea(bool u);

		/*!
		 * \brief getUsingScrollArea Returns if is configured to fit all controlls inside a scroll area.
		 * \return
		 */
		bool getUsingScrollArea() const;

		void setTrainingSet(TrainingSet *ts);
		TrainingSet *getTrainingSet() const;

		void setValidationSet(TrainingSet *vs);
		TrainingSet *getValidationSet() const;

		void setTestSet(TrainingSet *ts);
		TrainingSet *getTestSet() const;

		void setArtificialNeuralNetwork(MultilayerPerceptron *mlp);
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
		void setCanEditANNType(bool b);

		/*!
		 * \brief getCanEditANNType
		 * \return
		 */
		bool getCanEditANNType() const;

		/*!
		 * \brief canEditInputSize Indicate if user can edit ANN input size. It's restrictive for some cases, for
		 * example, SimplePerceptron, ADALINE, HOPFIELD, wich have particular output/input size properties.
		 * \param b
		 */
		void setCanEditInputSize(bool b);

		/*!
		 * \brief getCanEditInputSize
		 * \return
		 */
		bool getCanEditInputSize() const;

		/*!
		 * \brief canEditOutputSize Indicate if user can edit ANN output size. It's restrictive for some cases, for
		 * example, SimplePerceptron, ADALINE, HOPFIELD, wich have particular output/input size properties.
		 * \param b
		 */
		void setCanEditOutputSize(bool b);

		/*!
		 * \brief getCanEditOutputSize
		 * \return
		 */
		bool getCanEditOutputSize() const;

		/*!
		 * \brief setEnableMultipleTraining
		 * \param b
		 */
		void setEnableMultipleTraining(bool b);

		/*!
		 * \brief getEnableMultipleTraining
		 * \return
		 */
		bool getEnableMultipleTraining() const;

	protected:

		/*!
		 * \brief closeEvent
		 */
		void closeEvent(QCloseEvent *);

	private slots:

		/*!
		 * \brief onOuputSizeChanged
		 */
		void onOuputSizeChanged();

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

		void onANNInputChanged(int value);

		void onANNOutputChanged(int value);

		void onAnnTypeSelectionChanged(int index);

		void onRndFromValueChanged(double value);

		void onRndToValueChanged(double value);

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

		bool
		usingScrollArea,
		canEditInSize,
		canEditOutSize,
		canEditANN;

		//Neural Networks
		MultilayerPerceptron *mlp;
		Adaline *adaline;
		Hopfield *hopfield;
		Kohonen *kohonen;
		SimplePerceptron *sp;

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
		*lcbTransferFunction,
		*lcbANNType;

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

//		QMutex mutex;

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

		ANNModelWrapper
		*annModel;

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

		/*!
		 * \brief updateSAControls
		 */
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

		/*!
		 * \brief setTrainingStatus Establish the different status before, during or after training.
		 * \param ts Current status to set
		 */
		void setTrainingStatus(TrainingStatus ts);

		/*!
		 * \brief updateControls Update all control positions and visibility according to ANN type
		 * \param type
		 */
		void updateControls(ArtificialNeuralNetwork *ann);


};
}
#endif // MLPTRAININGDIALOG_H

