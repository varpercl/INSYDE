
#include <QtCore>
#include <QtWidgets>

#include "mainwindow.h"
#include "pruebapantallas.h"
#include "../ann_base/mlp.h"
#include "../ann_gui/anntrainingdialog.h"

#define TESTS

using namespace gui;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Q_INIT_RESOURCE(gui_media);
//    Q_INIT_RESOURCE(core_media);
//    Q_INIT_RESOURCE(ann_gui_media);


#ifdef TESTS

	PruebaPantalla *pp = new PruebaPantalla();

	pp->show();

#else

	NewMainWindow mw;
	mw.show();

#endif
	return a.exec();
}
