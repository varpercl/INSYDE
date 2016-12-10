#ifndef PRUEBAPANTALLAS_H
#define PRUEBAPANTALLAS_H

#include <QtGui>

#include "../core/graphicobjectpropertydialog.h"
#include "../core/dotmatrixrepresentation.h"
#include "../core/basicdialog.h"
#include "../core/labeledcombobox.h"
#include "../core/datarepresentationbox.h"
#include "../core/dotmatrix.h"
#include "../core/zoomcontrol.h"
#include "../core/normalizationwidget.h"
#include "../core/doubleminmaxvaluewidget.h"
#include "../core/imageeffectpropertydialog.h"

#include "../ann_gui/perceptronpage.h"
#include "../ann_gui/anntrainingdialog.h"
#include "../ann_gui/mlpobject.h"
#include "../ann_gui/weighteditordialog.h"
#include "../ann_gui/trainingsettable.h"

#include "newprojectwizard.h"
#include "binaryoutputelement.h"
#include "mainwindow.h"
#include "view.h"
#include "newmainwindow.h"


namespace Ui {
	class PruebaPantalla;
}

/*!
 * \brief PruebaPantalla brinda la posibilidad de visualizar todas las ventanas u objetos ejecutandolas solamente
 * haciendo click en el respectivo boton
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class PruebaPantalla : public QWidget
{
	public:
		explicit PruebaPantalla(QWidget *parent = 0);

		~PruebaPantalla();

	signals:

	public slots:

	private slots:

		void on_newProjectButton_clicked();
		void on_mainWindowButton_clicked();
		void on_perceptronButton_clicked();
		void on_systemButton_clicked();
		void onVisorClicked(QMouseEvent *event);

		void on_ANNTrainingDialog_clicked();

		void on_TrainingSetDialogButton_clicked();

		void on_DataRepresentationBoxButton_clicked();

		void on_LabeledIntegerSpinBoxButton_clicked();

		void on_IntegerSizeWidgetButton_clicked();

		void on_SelectImageSegmentButton_clicked();

		void on_LabeledComboBoxButton_clicked();

		void on_BasicDialogButton_clicked();

		void on_DotMatrixRepresentationButton_clicked();

		void on_ZoomControlButton_clicked();

		void on_DetailedWindowButton_clicked();

		void on_NormalizationWidgetButton_clicked();

		void on_WeightEditorDialogButton_clicked();

		void on_DoubleMinMaxWidgetButton_clicked();

		void on_NewMainWindowButton_clicked();

		void on_GraphicObjectPropertyDialogButton_clicked();

	private:
		Q_OBJECT

		SelectImageSegmentDialog *sisd;
		MultilayerPerceptron *mlp;
		View *visor;
		Ui::PruebaPantalla *ui;
};

#endif // PRUEBAPANTALLAS_H
