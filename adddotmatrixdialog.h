#ifndef ADDDOTMATRIXDIALOG_H
#define ADDDOTMATRIXDIALOG_H

#include <QDialog>
#include <dotmatrix.h>

namespace Ui {
class AddDotMatrixDialog;
}
//class DotMatrix;

class AddDotMatrixDialog : public QDialog
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
