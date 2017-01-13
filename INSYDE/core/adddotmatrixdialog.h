#ifndef ADDDOTMATRIXDIALOG_H
#define ADDDOTMATRIXDIALOG_H

#include <QtWidgets>

#include "share_core_lib.h"
#include "../core/common.h"
#include "../core/dotmatrix.h"


/*!
 * \namespace core
 * \brief The core namespace stores a lot of classes and helper function to perform
 * from graphical functionalities to math calculations. Also stores some GUI classes
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 14/01/17
 */
namespace core{

/*!
 * \brief The AddDotMatrixDialog class represents an specified dialog that allows user to
 * add some DotMatrix objects into the enviroment. A matrix can be initialy configured
 * stablishing width and height parameters and another properties as well.
 *
 * The dot matrix object is, as its name says, a matrix containing lots of dots that can
 * be pushed by the user to change their status. This dots are a visual representation of
 * values 0 or 1, or -1 and 1 depending on settings stablished by the user.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT AddDotMatrixDialog : public BasicDialog
{

	public:

		/*!
		 * \brief Construct a dialog with standard initialization, no parameters are needed
		 * and default size of the matrix is 10x10.
		 *
		 * If you want to set a different size you should choose the overloaded version of this constructor
		 * or manually set the height and width.
		 *
		 * \param[in] parent Specifies the parent of this dialog.
		 *
		 * \see setRows, setCols
		 */
		explicit AddDotMatrixDialog(QWidget *parent = 0);

		/*!
		 * \brief Construct a dialog that allows to create a DotMatrix object with
		 * \a rows and \a cols.
		 *
		 * \param[in] rows Number of rows of the DotMatrix object.
		 * \param[in] cols Number of cols of the DotMatrix object.
		 * \param[in] parent The parent of this dialog.
		 *
		 * \see setRows, setCols
		 */
		explicit AddDotMatrixDialog(int rows, int cols, QWidget *parent = 0);

		~AddDotMatrixDialog();

		/*!
		 * \brief Obtains the amount of rows of the DotMatrix object to be created.
		 * \return The number of rows.
		 */
		int getRows() const;

		/*!
		 * \brief Obtains the amount of cols of the DotMatrix object to be created.
		 * \return The number of cols.
		 */
		int getCols() const;

		/*!
		 * \brief Sets the rows of the DotMatrix object to be created.
		 * \param[in] r Specifies the rows.
		 */
		void setRows(int r);

		/*!
		 * \brief Sets the cols of the DotMatrix object to be created.
		 *
		 * \param[in] c Specifies the cols.
		 */
		void setCols(int c);

		/*!
		 * \brief Returns the current data format of this matrix, data format can be unipolar
		 * or bipolar, which means values of 0 or 1 for unipolar and -1 or 1 for bipolar.
		 *
		 * \return The data format of the DotMatrix object to be created.
		 */
		DotMatrix::DataFormat getDataType();

	private:
		Q_OBJECT

		IntegerSizeWidget *iswSize;

		LabeledComboBox *lcbDataType;

		QVBoxLayout *mainLayout;

		/*!
		 * \brief initializes all controls inside this dialog and ajust all sizes and shapes.
		 *
		 * \param[in] rows Specifies the rows of the DotMatrix object to be created.
		 * \param[in] cols Specifies the cols of the DotMatrix object to be created.
		 */
		void init(int rows, int cols);
};
}
#endif // ADDDOTMATRIXDIALOG_H
