
#include <QtCore>
#include <QtWidgets>

#include "../ann_gui/anntrainingdialog.h"

using namespace core;
using namespace ann_gui;

int main(int argc, char *argv[])
{
	Q_INIT_RESOURCE(core_media);
	Q_INIT_RESOURCE(ann_gui_media);

	QApplication a(argc, argv);

	a.setOrganizationName("VARPER Technologies");
	a.setApplicationName("ISYDE ANN Tool");
	a.setOrganizationDomain("varper.com");


	ANNTrainingDialog *annd = new ANNTrainingDialog();
	annd->canSave(true);
	annd->canSaveAs(true);
	annd->canOpenFile(true);

	annd->showMaximized();

	return a.exec();
}
