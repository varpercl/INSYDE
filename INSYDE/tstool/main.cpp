
#include <QtCore>
#include <QtWidgets>

#include "../ann_gui/trainingsetdialog.h"

using namespace core;
using namespace ann_gui;

int main(int argc, char *argv[])
{
	Q_INIT_RESOURCE(core_media);
	Q_INIT_RESOURCE(ann_gui_media);

	QApplication a(argc, argv);

	TrainingSetDialog *tsd = new TrainingSetDialog();

	tsd->show();

	return a.exec();
}
