#ifndef ADDDOTMATRIXDIALOG_H
#define ADDDOTMATRIXDIALOG_H

#include <QDialog>

#include "../core/common.h"
#include "../core/dotmatrix.h"

//using namespace ann_base;

namespace Ui {
class AddDotMatrixDialog;
}

/*!
 * \brief The AddDotMatrixDialog class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT AddDotMatrixDialog : public QDialog
{

	public:
		explicit AddDotMatrixDialog(QWidget *parent = 0);
		~AddDotMatrixDialog();

		int getRowSize();
		int getColSize();
		DotMatrix::DataType getDataType();

	private:
		Q_OBJECT

		Ui::AddDotMatrixDialog *ui;
};

#endif // ADDDOTMATRIXDIALOG_H
