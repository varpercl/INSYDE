
#include <QtCore>

#include "mainwindow.h"
#include "pruebapantallas.h"

#define TESTS

int main(int argc, char *argv[])
{
	//    Q_INIT_RESOURCE(trainingsets);
	//    Q_INIT_RESOURCE(imagenes);
	//    Q_INIT_RESOURCE(images);
	//    QApplication::setGraphicsSystem("raster");
	QApplication a(argc, argv);

#ifdef TESTS

	PruebaPantalla *pp = new PruebaPantalla();

	pp->show();

#else

	MainWindow mw;
	mw.show();

#endif
	return a.exec();
}
