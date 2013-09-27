//#undef __STRICT_ANSI__
#if _MSC_VER == 1600
	#include <QApplication>
#else
	#include <QtGui/QApplication>
#endif
#include <mainwindow.h>
#include <pruebapantallas.h>

//#define BOOT_MAN

int main(int argc, char *argv[])
{
	Q_INIT_RESOURCE(imagenes);
//    QApplication::setGraphicsSystem("raster");
	QApplication a(argc, argv);
#ifndef BOOT_MAN
	MainWindow mw;
	mw.show();
#else
	PruebaPantalla p;
	p.show();
#endif

	return a.exec();
}
