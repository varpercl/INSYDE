#ifndef ADDNEWMLPDIALOG_H
#define ADDNEWMLPDIALOG_H

#include <QtWidgets>

#include "../core/common.h"
#include "../ann_base/mlp.h"

using namespace ann_base;

namespace Ui {
class addNewMLPDialog;
}

/*!
 * \class
 *
 * \brief The AddNewMLPDialog class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class Q_DECL_EXPORT AddNewMLPDialog : public QDialog
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
