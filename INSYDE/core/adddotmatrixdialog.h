#ifndef ADDDOTMATRIXDIALOG_H
#define ADDDOTMATRIXDIALOG_H

#include <QtWidgets>

#include "share_core_lib.h"
#include "../core/common.h"
#include "../core/dotmatrix.h"

namespace core{
/*!
 * \brief The AddDotMatrixDialog class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT AddDotMatrixDialog : public BasicDialog
{

	public:
		explicit AddDotMatrixDialog(int rows, int cols, QWidget *parent = 0);
		~AddDotMatrixDialog();

		int getRows();
		int getCols();
		DotMatrix::DataType getDataType();

	private:
		Q_OBJECT

		IntegerSizeWidget *iswSize;

		LabeledComboBox *lcbDataType;

		QVBoxLayout *mainLayout;

		void init(int rows, int cols);
};
}
#endif // ADDDOTMATRIXDIALOG_H
