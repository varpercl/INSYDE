#ifndef ADDNEWMLPDIALOG_H
#define ADDNEWMLPDIALOG_H

#include <QtWidgets>

#include "share_ann_gui_lib.h"

#include "../core/common.h"
#include "../core/basicdialog.h"
#include "../core/labeledcombobox.h"
#include "../core/labeleddoublespinbox.h"
#include "../core/labeledintegerspinbox.h"

#include "../ann_base/mlp.h"

using namespace ann_base;

/*!
 * \class
 *
 * \brief The AddNewMLPDialog class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_GUI_LIB_IMPORT_EXPORT AddNewMLPDialog : public BasicDialog
{

	public:

		/*!
		 * \brief AddNewMLPDialog
		 * \param parent
		 */
		explicit AddNewMLPDialog(QWidget *parent = 0);


		~AddNewMLPDialog();

		/*!
		 * \brief getTransferFunction
		 * \return
		 */
		MultilayerPerceptron::TransferFunctionType getTransferFunction();

		/*!
		 * \brief getInputSize
		 * \return
		 */
		int getInputSize();

		/*!
		 * \brief getOutputSize
		 * \return
		 */
		int getOutputSize();

		/*!
		 * \brief getSlope
		 * \return
		 */
		double getSlope();

		/*!
		 * \brief getLayerSizes
		 * \return
		 */
		vector<int> getLayerSizes();

	private slots:
		/*!
		 * \brief on_buttonBox_accepted
		 */
		void accept();

		/*!
		 * \brief on_btnAddLayer_clicked
		 */
		void on_btnAddLayer_clicked();

		/*!
		 * \brief on_btnDeleteLayer_clicked
		 */
		void on_btnDeleteLayer_clicked();

		/*!
		 * \brief on_buttonBox_rejected
		 */
		void on_buttonBox_rejected();

	private:
		Q_OBJECT

		QTableWidget
		*tblLayers;

		LabeledComboBox
		*lcbTrasnferFunction;

		LabeledIntegerSpinBox
		*lisbInputSize,
		*lisbOutputSize;

		LabeledDoubleSpinBox
		*ldsbSlope;

		QToolButton
		*btnAddLayer,
		*btnDeleteLayer;

		QVBoxLayout
		*mainLayout,
		*vlyBtnLayout;

		QHBoxLayout
		*hlyLayers;

		void init();

		bool checkLayers();
};

#endif // ADDNEWMLPDIALOG_H
