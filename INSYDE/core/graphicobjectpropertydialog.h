#ifndef PROPERTYDIALOG_H
#define PROPERTYDIALOG_H

#include <QtCore>
#include <QtWidgets>

#include "share_core_lib.h"
#include "basicdialog.h"
#include "graphicobject.h"

namespace core{
/*!
 * \brief The PropertiesDialog class represents a properties dialog.
 * This is open when user clicks on "Properties" actions on the contextual menu.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 *
 * \date
 */
class CORE_LIB_IMPORT_EXPORT PropertiesDialog : public BasicDialog
{
	public:

		/*!
		 * \brief Builds a basic dialog associated to a \p obj.
		 * \param[in] obj The caller object.
		 * \param[in] parent The parent of this dialog.
		 */
		explicit PropertiesDialog(GraphicObject *obj, QWidget *parent = 0);


	private:
		Q_OBJECT

		QList<QWidget*> widgetList;

		/*!
		 * \brief Initializes all graphic interface associated to this \p obj.
		 * \param obj The associated caller object.
		 */
		void init(GraphicObject *obj);
};
}
#endif // PROPERTYDIALOG_H
