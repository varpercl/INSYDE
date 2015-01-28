#ifndef ADDNEWMLPDIALOG_H
#define ADDNEWMLPDIALOG_H

#include <QDialog>
#include <QInputDialog>
#include <QMessageBox>

#include "../INSYDEUI_global.h"
#include "ANNFramework/mlp.h"

namespace Ui {
class addNewMLPDialog;
}

class INSYDEUISHARED_EXPORT AddNewMLPDialog : public QDialog
{
		Q_OBJECT
		
	public:
		explicit AddNewMLPDialog(QWidget *parent = 0);
		~AddNewMLPDialog();

		MultilayerPerceptron::TransferFunctionType getTransferFunction();
		int getInputSize();
		int getOutputSize();
		double getSlope();
		vector<int> getLayerSizes();

	private slots:
		void on_buttonBox_accepted();

		void on_btnAddLayer_clicked();

		void on_btnDeleteLayer_clicked();

		void on_buttonBox_rejected();

	private:
		Ui::addNewMLPDialog *ui;

		bool checkLayers();
};

#endif // ADDNEWMLPDIALOG_H
