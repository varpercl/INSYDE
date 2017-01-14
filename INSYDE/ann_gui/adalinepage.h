#ifndef ADALINEPAGE_H
#define ADALINEPAGE_H

#include <QtGui>
#include <QtWidgets>

#include "share_ann_gui_lib.h"

namespace Ui{
	class AdalinePage;
}

namespace ann_gui
{

/*!
 * \class
 *
 * \brief The AdalinePage class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_GUI_LIB_IMPORT_EXPORT AdalinePage : public QWizardPage
{
	public:
		AdalinePage();

	protected:
		int nextId() const;

	private:
		Ui::AdalinePage *ui;
};
}
#endif // ADALINEPAGE_H
