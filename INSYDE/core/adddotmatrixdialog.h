#ifndef ADDDOTMATRIXDIALOG_H
#define ADDDOTMATRIXDIALOG_H

#include <QtWidgets>

#include "share_core_lib.h"
#include "../core/common.h"
#include "../core/dotmatrix.h"

namespace core{
/*!
 * \brief The AddDotMatrixDialog class
 * This class represents a specified dialog that allows user to add some dialog into
 * the enviroment. A matrix can be initialy configured stablishing width and height
 * parameters and another properties as well.
 *
 * The dot matrix object is, as its name says, a matrix containing lots of dots that can
 * be pushed by the user to change their status. This dots are a visual representation of
 * values 0 or 1, or -1 and 1 depending on settings stablished by the user.
 *
 * \inherits BasicDialog
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT AddDotMatrixDialog : public BasicDialog
{

	public:

		/*!
		 * \brief AddDotMatrixDialog
		 * \param parent Specifies the parent of this dialog.
		 */
		explicit AddDotMatrixDialog(QWidget *parent = 0);

		/*!
		 * \brief AddDotMatrixDialog
		 * \param rows
		 * \param cols
		 * \param parent
		 */
		explicit AddDotMatrixDialog(int rows, int cols, QWidget *parent = 0);
		~AddDotMatrixDialog();

		/*!
		 * \brief getRows
		 * \return
		 */
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
