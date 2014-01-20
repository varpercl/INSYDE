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

class INSYDEUISHARED_EXPORT TrainingSetDialog : public QDialog
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
		explicit TrainingSetDialog(const TrainingSet *ts, QWidget *parent = 0);

		/**
		 * @brief TrainingSetDialog TrainingSetDialog Genera una instancia de un cuadro de dialogo para generar un conjunto de entrenamiento
		 * sin tener nada previamente construido, solo se indican el numero de entradas y salidas
		 * @param inputSize Numero de entradas
		 * @param targetSize Numero de salidas (u objetivos)
		 * @param parent Widget padre
		 */
		explicit TrainingSetDialog(int inputSize, int targetSize, QWidget *parent = 0);

		/**
		 * @brief TrainingSetDialog Genera una instancia de un cuadro de dialogo para generar un conjunto de entrenamiento
		 * a partir de vectores con las entradas y los objetivos. Ambos vectores deben tener el mismo numero de elementos, salvo
		 * el numero de entradas u objetivos
		 * @param inputs Vector con las entradas
		 * @param targets Vector con los objetivos
		 * @param parent Widget padre
		 */
		explicit TrainingSetDialog(vector<vector<double> > inputs, vector<vector<double> > targets, QWidget *parent = 0);

		/**
		 * @brief TrainingSetDialog Genera una instancia de un cuadro de dialogo para generar un conjunto de entrenamiento
		 * a partir de un vector con patrones de entrenamiento definidos para un MLP
		 * @param ts Vector con los patrones de entrenamiento
		 * @param parent Widget padre
		 */
		explicit TrainingSetDialog(vector<MultilayerPerceptronPattern*> ts, QWidget *parent = 0);

		~TrainingSetDialog();

		/**
		 * @brief getInputs Devuelve las entradas de este conjunto de entrenamiento
		 * @return Matriz con las entradas que posee este conjunto de entrenamiento
		 */
		vector<vector<double> > getInputs() const;

		/**
		 * @brief setInputSize Redimensiona el tamaño de las entradas del conjunto de entrenamiento
		 * @param size Tamaño de la entrada
		 */
		void setInputSize(int size);

		/**
		 * @brief getTargets Devuelve los objetivos de este conjunto de entrenamiento
		 * @return Vector con los valores objetivos
		 */
		vector<vector<double> > getTargets() const;

		/**
		 * @brief setTargetSize Redimensiona el tamaño de los valores objetivos del conjunto de entrenamiento
		 * @param size Tamaño que se asignara
		 */
		void setTargetSize(int size);

		/**
		 * @brief appendPattern Agrega un patron de entrenamiento al conjunto de entrenamiento
		 * @param input Entradas de este patron (double)
		 * @param target Valores objetivo de este patron (double)
		 */
		//		void appendPattern(const vector<double> &input, const vector<double> &target);

		/**
		 * @brief appendPattern Agrega un patron de entrenamiento al conjunto de entrenamiento
		 * @param input Entradas de este patron (int)
		 * @param target Valores objetivo de este patron (int)
		 */
		template<typename I, typename T>
		void appendPattern(const vector<I> &input, const vector<T> &target){
			patternTable->setRowCount(patternTable->rowCount() + 1);

			int nRows = patternTable->rowCount();
			for(int i = 0; i < inputSize; i++){
				QTableWidgetItem *itm = new QTableWidgetItem(QString::number((I)input[i]));
				itm->setTextAlignment(Qt::AlignRight);
				patternTable->setItem(nRows-1, i, itm);
			}
			for(int j = inputSize; j <  inputSize + targetSize; j++){
				QTableWidgetItem *itm = new QTableWidgetItem(QString::number((T)target[j-inputSize]));
				itm->setTextAlignment(Qt::AlignRight);
				patternTable->setItem(nRows-1, j, itm);
			}
		}

		//		void appendPattern(const vector<unsigned int> &input, const vector<unsigned int> &target);

		/**
		 * @brief appendPattern Agrega un patron de entrenamiento al conjunto de entrenamiento. En este caso se utiliza la clase QVector
		 * @param input Entradas de este patron (double)
		 * @param target Valores objetivo de este patron (double)
		 */
		//		void appendPattern(const QVector<double> &input, const QVector<double> &target);

		/**
		 * @brief appendPattern Agrega un patron de entrenamiento al conjunto de entrenamiento. En este caso se utiliza la clase QVector
		 * @param input Entradas de este patron (int)
		 * @param target Valores objetivo de este patron (int)
		 */
		//		void appendPattern(const QVector<int> &input, const QVector<int> &target);

		/**
		 * @brief removePattern Elimina el patron en la posicion @code{i}
		 * @param i Indice del patron que se eliminara
		 */
		void removePattern(int i);

		/**
		 * @brief getPatternCount Devuelve el numero de patrones de entrenamiento que tiene este conjunto
		 * @return Numero de patrones
		 */
		int getPatternCount();

		/**
		 * @brief setTrainingSet Asigna un conjunto de entrenamiento a este dialogo para que sea editado por el usuario.
		 * @param ts Conjunto de entrenamiento que sera asignado. Este puede ser obtenido desde alguna red neuronal.
		 */
		void setTrainingSet(TrainingSet *ts);

		/**
		 * @brief getTrainingSet Devuelve el objeto TrainingSet asociado a este cuadro de dialogo
		 * @return Puntero al objeto
		 */
		TrainingSet *getTrainingSet() const;

	private slots:

		//Eventos de controles
		void on_addPatternButton_clicked();

		void on_delPatternButton_clicked();

	private:
		Q_OBJECT

		QMenu *addPatternMenu;
		QMenu *file;
		QImage imageFile;
		SelectImageSegmentDialog *sisd;
		QPushButton *btnMsgBoxFirstPixels;
		QPushButton *btnMsgBoxImageSegment;
		QHBoxLayout *hlRepresentation;
		DataRepresentationBox *gbGraphicTargetRepresentation;
		DataRepresentationBox *gbGraphicInputRepresentation;
		QVBoxLayout *mainVertlLayout;
		QHBoxLayout *horizontalLayout;
		QSpacerItem *horizontalSpacer;
		QToolButton *addPatternButton;
		QToolButton *delPatternButton;
		QTableWidget *patternTable;
		QDialogButtonBox *buttonBox;

		QGraphicsItem *itm;
		QImage *imgRepresentation;
		DotMatrix *dmRepresentation;

		QFileDialog *fileDialog;

		QMenuBar *menuBar;

		//Tipo de conjunto de entrenamiento
		TrainingSetType tst;

		//Tama�o de las entradas y salidas
		int inputSize, targetSize;

		/**
		 * @brief initDialog Es un metodo auxiliar para inicializar este cuadro de dialogo
		 * @param inputs Numero de entradas
		 * @param outputs Numero de salidas
		 */
		void initDialog(int inputs, int outputs);

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
		 * @brief updateHeaders Actualiza la cabecera de la tabla que muestra el conjunto de entrenamiento
		 */
		void updateHeaders();

		void updateRepresentation(int row);

		void setupUi(QDialog *TrainingSetDialog); // setupUi

		void retranslateUi(QDialog *TrainingSetDialog); // retranslateUi

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
};
#endif // TRAININGSETDIALOG_H
