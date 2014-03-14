#ifndef TRAININGSETDIALOG_H
#define TRAININGSETDIALOG_H

#include <typeinfo>

#include <QApplication>
#include <QHeaderView>
#include <QDialogButtonBox>
#include <QSpinBox>
#include <QLabel>
#include <QRadioButton>
#include <QGroupBox>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QFileDialog>
#include <QPushButton>
#include <QMessageBox>

#include "trainingsettable.h"
#include "normalizationwidget.h"
#include "../selectimagesegmentdialog.h"
#include "datarepresentationbox.h"
#include "../graphicimageelementdetailedwindow.h"
#include "../dotmatrix.h"
#include "../INSYDEUI_global.h"
#include "ANNFramework/trainingset.h"
#include "ANNFramework/multilayerperceptron.h"

using namespace std;

class DotMatrix;
class PerceptronTrainingPattern;

class INSYDEUISHARED_EXPORT TrainingSetDialog : public QDialog/*, public ITrainingSet*/
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
		explicit TrainingSetDialog(const vector<vector<double> > &inputs, const vector<vector<double> > &targets, QWidget *parent = 0);

		/**
		 * @brief TrainingSetDialog Genera una instancia de un cuadro de dialogo para generar un conjunto de entrenamiento
		 * a partir de un vector con patrones de entrenamiento definidos para un MLP
		 * @param ts Vector con los patrones de entrenamiento
		 * @param parent Widget padre
		 */
		explicit TrainingSetDialog(vector<MultilayerPerceptronPattern*> ts, QWidget *parent = 0);

		~TrainingSetDialog();

		/*!
		 * \brief getInputs
		 * \return
		 */
		//		vector<vector<double> > getInputs() const;

		/*!
		 * \brief getTargets
		 * \return
		 */
		//		vector<vector<double> > getTargets() const;

		/**
		 * @brief getPatternCount Devuelve el numero de patrones de entrenamiento que tiene este conjunto
		 * @return Numero de patrones
		 */
		//		int getPatternCount() const;

		/**
		 * @brief setTrainingSet Asigna un conjunto de entrenamiento a este dialogo para que sea editado por el usuario.
		 * @param ts Conjunto de entrenamiento que sera asignado. Este puede ser obtenido desde alguna red neuronal.
		 */
		//		void setTrainingSet(TrainingSet *ts);

		/**
		 * @brief getTrainingSet Devuelve el objeto TrainingSet asociado a este cuadro de dialogo
		 * @return Puntero al objeto
		 */
		//		TrainingSet *getTrainingSet() const;

		//		int getInputSize() const;

		//		int getTargetSize() const;

		//		NormalizationType getNormalizationType() const;

		//		TrainingSetTable *getTrainingSetTable() const;

		// ITrainingSet interface
		//		void setInputSize(int is, double fill = 0);
		//		void setTargetSize(int ts, double fill = 0);
		//		void insertPattern(const vector<double> &inputs, const vector<double> &targets, int index);
		//		void insertPattern(const vector<int> &inputs, const vector<int> &targets, int index);
		//		void deletePattern(int index);
		//		void setInputs(const vector<vector<double> > &inputs);
		//		void setInputs(const vector<vector<int> > &inputs);
		//		void setTargets(const vector<vector<double> > &targets);
		//		void setTargets(const vector<vector<int> > &targets);
		//		void addNoiseToInputs(double min, double max);
		//		void addNoiseToInputs(double a);
		//		void addNoiseToTargets(double min, double max);
		//		void addNoiseToTargets(double a);
		//		void addNoiseToAll(double min, double max);
		//		void addNoiseToAll(double a);
		//		void setPatternCount(int s);

		//		void appendPattern(const vector<float> &inputs, const vector<float> &targets);
		//		void appendPattern(const vector<double> &inputs, const vector<double> &targets);
		//		void appendPattern(const vector<long double> &inputs, const vector<long double> &targets);
		//		void appendPattern(const vector<char> &inputs, const vector<char> &targets);
		//		void appendPattern(const vector<int> &inputs, const vector<int> &targets);
		//		void appendPattern(const vector<short> &inputs, const vector<short> &targets);
		//		void appendPattern(const vector<long> &inputs, const vector<long> &targets);
		//		void appendPattern(const vector<unsigned char> &inputs, const vector<unsigned char> &targets);
		//		void appendPattern(const vector<unsigned int> &inputs, const vector<unsigned int> &targets);
		//		void appendPattern(const vector<unsigned short> &inputs, const vector<unsigned short> &targets);
		//		void appendPattern(const vector<unsigned long> &inputs, const vector<unsigned long> &targets);

		//		void setInput(int pat, int index, double value);
		//		void setTarget(int pattern, int index, double value);
		//		double getInput(int pat, int index) const;
		//		double getTarget(int pat, int index) const;
		//		void setPattern(int index, const vector<double> &inputs, const vector<double> &targets);
		//		pair<vector<double>, vector<double> > getPattern(int index) const;

		//		void normalize(double minInputs, double maxInputs, double minTargets, double maxTargets);
		//		void normalize(double *minInputs, double *maxInputs, double *minTargets, double *maxTargets);
		//		void normalize(NormalizationType no);

		//		TrainingSet getNormalized(NormalizationType no) const;
		//		TrainingSet getNormalized(double *minInputs, double *maxInputs, double *minTargets, double *maxTargets) const;
		//		TrainingSet getNormalized(double minInputs, double maxInputs, double minTargets, double maxTargets) const;

		void setTrainingSetTable(TrainingSetTable *tst);
		TrainingSetTable *getTrainingSetTable() const;

	public slots:

		/**
		 * @brief setNormalizationType Establece el tipo de normalizacion de los datos de entrenamiento.
		 *
		 * La normalizacion de los datos previene que el entrenamiento sea mucho mas largo e inestable al presentar
		 * datos que se encuentran entre rangos pequeños de valores (0 y 1 por ejemplo)
		 *
		 * @param nt
		 *
		 */
		//		void setNormalizationType(ITrainingSet::NormalizationType nt);

	private:
		Q_OBJECT

		double
		dblInputsThreshold,
		dblInputsMinValue,
		dblInputsMaxValue,
		dblInputsAmpValue,
		dblInputsElongValue,
		dblTargetsThreshold,
		dblTargetsMinValue,
		dblTargetsMaxValue,
		dblTargetsAmpValue,
		dblTargetsElongValue;

		QTimer
		tnInputsAmplitude,
		tnInputsElongation,
		tnInputsThreshold,
		tnInputsMaxValue,
		tnInputsMinValue,
		tnTargetsAmplitude,
		tnTargetsElongation,
		tnTargetsThreshold,
		tnTargetsMaxValue,
		tnTargetsMinValue;

		TrainingSet *ts;
		TrainingSet *normalizedTS;
		NormalizationWidget
		*inw,
		*tnw;
		QMessageBox mbImageSegmentMessage;
		QMessageBox mbErrorLoadingImageMessage;
		QMenu *addPatternMenu;
		QMenu *file;
		QImage imageFile;
		SelectImageSegmentDialog *sisd;
		QPushButton *lastButtonPressed;
		QPushButton *btnMsgBoxFirstPixels;
		QPushButton *btnMsgBoxImageSegment;
		QPushButton *btnCancel;
		QHBoxLayout *hlRepresentation;
		DataRepresentationBox *gbGraphicTargetRepresentation;
		DataRepresentationBox *gbGraphicInputRepresentation;
		QVBoxLayout *mainVertlLayout;
		QHBoxLayout *horizontalLayout;
		QSpacerItem *horizontalSpacer;
		QToolButton *addPatternButton;
		QToolButton *delPatternButton;
		TrainingSetTable *patternTable;
		QDialogButtonBox *buttonBox;

		QGraphicsItem *itm;
		QImage *imgRepresentation;
		DotMatrix *dmRepresentation;

		QFileDialog *fileDialog;

		QMenuBar *menuBar;

		//Tipo de conjunto de entrenamiento
		TrainingSetType tst;

		//		int inputSize, targetSize; /**< Tamaño de las entradas y objetivos */

		/**
		 * @brief initDialog Es un metodo auxiliar para inicializar este cuadro de dialogo
		 * @param inputs Numero de entradas
		 * @param outputs Numero de salidas
		 */
		//		void initDialog(int inputs, int outputs);

		/**
		 * @brief initDialog
		 * @param inputs
		 * @param outputs
		 */
		void initDialog(const vector<vector<double> > &inputs, const vector<vector<double> > &outputs);

		/**
		 * @brief initDialog
		 * @param ts
		 */
		void initDialog(const vector<MultilayerPerceptronPattern*> ts);

		/**
		 * @brief initMsgBoxes Inicializa los cuadros de mensajes al usuario.
		 */
		void initMsgBoxes();

		/**
		 * @brief updateHeaders Actualiza la cabecera de la tabla que muestra el conjunto de entrenamiento
		 */
		void updateHeaders();

		void updateRepresentation(int row);

		void setupUi(TrainingSet *ts, QWidget *TrainingSetDialog); // setupUi

		void retranslateUi(QWidget *TrainingSetDialog); // retranslateUi

	private slots:

		/**
		 * @brief fromFile Se activa cuando se hace click en el menu cargar desde archivo
		 */
		void fromFile();

		/**
		 * @brief fromImages Carga una imagen desde un archivo de imagen en el discoduro
		 */
		void fromImages();

		void on_patternTable_cellChanged(int row, int column);

		void on_patternTable_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

		void onMessageBoxButtonClicked(QAbstractButton *button);

		//Eventos de controles
		void on_addPatternButton_clicked();

		void on_delPatternButton_clicked();

		void onIgnoreAlphaChannelToogled(bool);

		void onInputsNormalizationTypeChanged(ITrainingSet::NormalizationType nt);

		void onTargetsNormalizationTypeChanged(ITrainingSet::NormalizationType nt);

		void onInputsAmplitudeChanged(double val);
		void onInputsAmplitudeTimed();

		void onInputsElongationChanged(double val);
		void onInputsElongationTimed();

		void onInputsThresholdChanged(double val);
		void onInputsThresholdTimed();

		void onInputsMinValueChanged(double val);
		void onInputsMinValueTimed();

		void onInputsMaxValueChanged(double val);
		void onInputsMaxValueTimed();

		void onTargetsAmplitudeChanged(double val);
		void onTargetsAmplitudeTimed();

		void onTargetsElongationChanged(double val);
		void onTargetsElongationTimed();

		void onTargetsThresholdChanged(double val);
		void onTargetsThresholdTimed();

		void onTargetsMinValueChanged(double val);
		void onTargetsMinValueTimed();

		void onTargetsMaxValueChanged(double val);
		void onTargetsMaxValueTimed();

		void onWidthChanged(int width);
		void onHeightChanged(int height);
};
#endif // TRAININGSETDIALOG_H
