#ifndef ADDDOTMATRIXDIALOG_H
#define ADDDOTMATRIXDIALOG_H

#include <QDialog>

#include "INSYDEUI_global.h"
#include "dotmatrix.h"

namespace Ui {
class AddDotMatrixDialog;
}
//class DotMatrix;

class INSYDEUISHARED_EXPORT AddDotMatrixDialog : public QDialog
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
