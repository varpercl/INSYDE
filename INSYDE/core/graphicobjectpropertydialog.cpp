#include "graphicobjectpropertydialog.h"

core::GraphicObjectPropertyDialog::GraphicObjectPropertyDialog(GraphicObject *obj, QWidget *parent) :
	BasicDialog(parent)

{
//    Q_INIT_RESOURCE(core_media);
	init(obj);
}

void core::GraphicObjectPropertyDialog::init(GraphicObject *obj)
{
	(void)obj;

	setModal(true);
	setFileMenuVisible(false);
	setEditMenuVisible(false);
	setViewMenuVisible(false);
	setToolsMenuVisible(false);
	setHelpMenuVisible(false);

	setEnableClipboardFramework(false);
	setEnableUnDoFramework(false);
	setEnableNew(false);
	setEnableOpen(false);
	setEnableSave(false);
	setEnableSaveAs(false);
	setEnablePreferences(false);
}
