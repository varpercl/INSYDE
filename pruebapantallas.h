#ifndef PRUEBAPANTALLAS_H
#define PRUEBAPANTALLAS_H

#include <graphicimageeffectelementpropertydialog.h>
#include <mlptrainingdialog.h>
#include <binaryoutputelement.h>
#include <dotmatrix.h>
#include <graphicmlpelement.h>
#include <mainwindow.h>

namespace Ui {
class PruebaPantalla;
}
//class DotMatrix;
//class GraphicMLPElement;
//class MainWindow;

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
		void on_trainingSetButton_clicked();
		void on_systemButton_clicked();
		void onVisorClicked(QMouseEvent *event);

		void on_pushButton_clicked();

		void on_pushButton_2_clicked();

	private:
		Q_OBJECT

		GraphicMLPElement *mlpe;
		Visor *visor;
		Ui::PruebaPantalla *ui;
};

#endif // PRUEBAPANTALLAS_H
