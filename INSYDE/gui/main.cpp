
#include <QtCore>
#include <QtWidgets>

#include "newmainwindow.h"
#include "pruebapantallas.h"
#include "../ann_base/mlp.h"
#include "../ann_gui/anntrainingdialog.h"

//#define TESTS

//QPointer<PruebaPantalla> profscr;


int main(int argc, char *argv[])
{
	Q_INIT_RESOURCE(gui_media);

	QApplication a(argc, argv);

#ifdef TESTS

	PruebaPantalla *pp = new PruebaPantalla();

	pp->show();

#else

	NewMainWindow mw;
	mw.show();

#endif
	return a.exec();
}
