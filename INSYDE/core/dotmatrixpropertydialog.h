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
 * \brief The DotMatrixElementPropertyDialog class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT DotMatrixPropertyDialog : public GraphicObjectPropertyDialog
{

	public:

		/*!
		 * \brief DotMatrixPropertyDialog
		 * \param dm
		 * \param parent
		 */
		explicit DotMatrixPropertyDialog(DotMatrix *dm, QWidget *parent = 0);

		~DotMatrixPropertyDialog();

	public slots:

		/*!
		 * \brief onApplyClicked Throwed when user clicks apply button
		 */
		void onApplyClicked();

		void accept();

	private:
		Q_OBJECT

		DotMatrix *dm;

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
		 * \brief init
		 */
		void init(DotMatrix *dm);
};
}
#endif // DOTMATRIXELEMENTPROPERTYDIALOG_H
