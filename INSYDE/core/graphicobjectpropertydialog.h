#ifndef PROPERTYDIALOG_H
#define PROPERTYDIALOG_H

#include <QtCore>
#include <QtWidgets>

#include "share_core_lib.h"
#include "basicdialog.h"
#include "graphicobject.h"

namespace core{

class CORE_LIB_IMPORT_EXPORT GraphicObjectPropertyDialog : public BasicDialog
{
	public:
		explicit GraphicObjectPropertyDialog(GraphicObject *obj, QWidget *parent = 0);


	private:
		Q_OBJECT

		QList<QWidget*> widgetList;

		void init(GraphicObject *obj);
};
}
#endif // PROPERTYDIALOG_H
