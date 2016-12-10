#ifndef SAMPLESDIALOG_H
#define SAMPLESDIALOG_H

#define IMPORT_ANN_BASE_LIB

#include <QtGui>
#include <QtWidgets>

#include "share_ann_gui_lib.h"
#include "../ann_base/mlp.h"

using namespace ann_base;

namespace Ui {
	class SamplesDialog;
}

/*!
 * \class
 *
 * \brief The SamplesDialog class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_GUI_LIB_IMPORT_EXPORT SamplesDialog : public QDialog
{

	public:
		explicit SamplesDialog(MLPTrainingResult *tr, QWidget *parent = 0);
		~SamplesDialog();

		int getSampleCount();

	private slots:
		void on_cbAllSamples_toggled(bool checked);

	private:

		Q_OBJECT

		MLPTrainingResult *tres;
		Ui::SamplesDialog *ui;

		void initDialog(MLPTrainingResult *tr);
};

#endif // SAMPLESDIALOG_H
