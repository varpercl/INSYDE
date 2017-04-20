#ifndef DOTMATRIXELEMENTPROPERTYDIALOG_H
#define DOTMATRIXELEMENTPROPERTYDIALOG_H

#include <QtWidgets>

#include "share_core_lib.h"
#include "basicdialog.h"
#include "integersizewidget.h"
#include "labeledintegerspinbox.h"
#include "dotmatrix.h"
#include "labeledcombobox.h"
#include "graphicobjectpropertydialog.h"

namespace core{

class DotMatrix;

/*!
 * \brief The DotMatrixElementPropertyDialog class is an derived class from GraphicObjectPropertyDialog.
 * These classes show a set of properties depending on the determined object.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT DotMatrixPropertyDialog : public PropertiesDialog
{

	public:

		/*!
		 * \brief Builds a property dialog with all properties of \p dm.
		 * \param[in] dm The DotMatrix object where the properties come from.
		 * \param[in] parent The parent of this dialog.
		 */
		explicit DotMatrixPropertyDialog(DotMatrix *dm, QWidget *parent = 0);

		~DotMatrixPropertyDialog();

	public slots:

		/*!
		 * \brief Performs actions when the Apply button is clicked.
		 */
		void onApplyClicked();

		/*!
		 * \brief Performs actions when the Accept button is clicked.
		 */
		void accept();

	private:
		Q_OBJECT

		DotMatrix *dm; /**< The DotMatrix associated to this properties dialog. */

		LabeledComboBox
		*lcbDataTypes;

		IntegerSizeWidget
		*iswSize;

		LabeledIntegerSpinBox
		*lisbDotSize,
		*lisbInputSize;

		QVBoxLayout
		*mainLayout,
		*vlyGBConfig,
		*vlyGBView;

		QGroupBox
		*gbConfig,
		*gbView;

		/*!
		 * \brief Initializes all graphic interface for this properties dialog.
		 *
		 * \param[in] dm A DotMatrix pointer to the object to be owned by this dialog.
		 */
		void init(DotMatrix *dm);
};
}
#endif // DOTMATRIXELEMENTPROPERTYDIALOG_H
