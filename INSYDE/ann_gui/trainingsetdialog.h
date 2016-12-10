#ifndef TRAININGSETDIALOG_H
#define TRAININGSETDIALOG_H

#include <QtGui>

#include <typeinfo>

#include "../core/basicdialog.h"
#include "../core/normalizationwidget.h"
#include "../core/datarepresentationbox.h"
#include "../core/imagedetailedwindow.h"
#include "../core/dotmatrix.h"
#include "../core/common.h"
#include "../core/definitions.h"
#include "../ann_base/trainingsetfile.h"
#include "../ann_base/trainingset.h"
#include "../core/selectimagesegmentdialog.h"

#include "share_ann_gui_lib.h"
#include "trainingsettable.h"

using namespace std;

class SelectImageSegmentDialog;
class DataRepresentationBox;
class DotMatrix;
class PerceptronTrainingPattern;

/*!
 * \class
 *
 * \brief The TrainingSetDialog class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_GUI_LIB_IMPORT_EXPORT TrainingSetDialog : public BasicDialog
{

	public:

		/**
		 * @brief The TrainingSetType enum Indica el tipo de cuadro de dialogo y los campos que poseera
		 */
		enum TrainingSetType{
			OnlyInputs,
			MultipleInputsAndTargets,
			MultipleInputsOneTarget
		};

		explicit TrainingSetDialog(QWidget *parent = 0);

		//		explicit TrainingSetDialog(TrainingSetType type, QWidget *parent = 0);

		/**
		 * @brief TrainingSetDialog Genera una instancia de un cuadro de dialogo para generar un conjunto de entrenamiento
		 * @param ts Conjunto de entrenamiento asignado (Si se desea crear a partir de tal)
		 * @param parent Widget padre
		 */
		explicit TrainingSetDialog(TrainingSet *ts, QWidget *parent = 0);

		/**
		 * @brief TrainingSetDialog TrainingSetDialog Genera una instancia de un cuadro de dialogo para generar un conjunto de entrenamiento
		 * sin tener nada previamente construido, solo se indican el numero de entradas y salidas
		 * @param inputSize Numero de entradas
		 * @param targetSize Numero de salidas (u objetivos)
		 * @param parent Widget padre
		 */
		explicit TrainingSetDialog(int inputSize, int targetCount, int nPatterns, QWidget *parent = 0);

		/**
		 * @brief TrainingSetDialog Genera una instancia de un cuadro de dialogo para generar un conjunto de entrenamiento
		 * a partir de vectores con las entradas y los objetivos. Ambos vectores deben tener el mismo numero de elementos, salvo
		 * el numero de entradas u objetivos
		 * @param inputs Vector con las entradas
		 * @param targets Vector con los objetivos
		 * @param parent Widget padre
		 */
		explicit TrainingSetDialog(const vector<vector<double> > &inputs, int is, const vector<vector<double> > &targets, int ts, QWidget *parent = 0);

		explicit TrainingSetDialog(ArtificialNeuralNetwork *ann, QWidget *parent = 0);

		~TrainingSetDialog();

		/*!
		 * \brief setTrainingSet
		 * \param ts
		 */
		void setTrainingSet(TrainingSet *ts);

		/*!
		 * \brief getTrainingSet
		 * \return
		 */
		TrainingSet *getTrainingSet() const;

	public slots:

		/*!
		 * \brief onExportClick
		 */
		void onExportClick();

		/*!
		 * \brief onInputChanged
		 * \param pat
		 * \param index
		 * \param lstValue
		 * \param curValue
		 */
		void onInputChanged(int pat, int index, double lstValue, double curValue);

		/*!
		 * \brief onTargetChanged
		 * \param pat
		 * \param index
		 * \param lstValue
		 * \param curValue
		 */
		void onTargetChanged(int pat, int index, double lstValue, double curValue);

		/*!
		 * \brief saveClick
		 */
		void saveClick();

		void saveAsClick();

		/*!
		 * \brief openClick
		 */
		void openClick();

		void copyClick();

		void pasteClick();

		void newClick();


	private slots:

		void onTstInputsSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

		void onTstTargetsSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

		void appendVector(const vector<double> &vec);

		void importTrainingSetClick();

		void importInputsClick();

		void importTargetsClick();

		void onMessageBoxButtonClicked(QAbstractButton *button);

		void on_addPatternButton_clicked();

		void on_delPatternButton_clicked();

		void onInputsCellClicked(const QModelIndex &index);
		void onTargetsCellClicked(const QModelIndex &index);

		void onInputsWidthChanged(int width);
		void onInputsHeightChanged(int height);

		void onTargetsWidthChanged(int width);
		void onTargetsHeightChanged(int height);

		void deleteRows();
		void deleteColumns();

		void onInputsSizeChanged(int val);
		void onTargetsSizeChanged(int val);

		void onInputsNormalizationChanged(Normalization *nor);
		void onTargetsNormalizationChanged(Normalization *nor);

	private:
		Q_OBJECT

		bool
		isEditingTS;

		TrainingSetFile *currentFile;

		LabeledIntegerSpinBox
		*lisbInputsSize,
		*lisbTargetsSize;

		TrainingSet
		*ts;

		NormalizationWidget
		*inw, /**< Inputs Normalization Widget */
		*tnw; /**< Targets Normalization Widget */

		DataRepresentationBox
		*gbTargetsRepresentation,
		*gbInputsRepresentation;

		TrainingSetTable
		//TrainingSetTable Inputs
		*tstInputs,
		//TrainingSetTable Targets
		*tstTargets;

		QMessageBox
		mbImageSegmentMessage,
		mbErrorLoadingImageMessage,
		mbLoadFileError;

		QImage imageFile;

		SelectImageSegmentDialog *sisd;

		QPushButton
		*lastButtonPressed,
		*btnMsgBoxFirstPixels,
		*btnMsgBoxImageSegment,
		*btnCancel;

		QVBoxLayout *mainLayout;
		QGridLayout *gridLayout;

		QToolButton
		*addPatternButton,
		*delPatternButton;

		QAction
		*actionDeleteRow,
		*actionDeleteCol;

		QToolBar *mainToolBar;

		bool importingInputs;

		/*!
		 * \brief init
		 * \param ts
		 */
		void init(TrainingSet *ts);

		/*/
		 * \brief initMsgBoxes Initialize user messages.
		 */
		void initMsgBoxes();

		/*!
		 * \brief connectTrainingSetSignals
		 */
		void connectTrainingSetSignals();

		QMessageBox::StandardButton askForLosingInformation();

		void beginOpenDialog();

};
#endif // TRAININGSETDIALOG_H
