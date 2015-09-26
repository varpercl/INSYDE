#ifndef SAMPLESDIALOG_H
#define SAMPLESDIALOG_H

#include <QtGui>
#include <QtWidgets>

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
class Q_DECL_EXPORT SamplesDialog : public QDialog
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
