
#include(../external/kdchart2.pri)
include(../external/tbb.pri)

QT += core widgets xml opengl charts

CONFIG += qt opengl

TEMPLATE = app

#DEFINES += \
##WINDOW_HEIGH=31 \
##WINDOW_WIDTH=13 \
##WINDOW_STEP=1

MOC_DIR = moc
UI_DIR = ui
OBJECTS_DIR = obj
RCC_DIR = res
DESTDIR = ..

SOURCES += \
    chooseprojectnamepage.cpp \
    main.cpp \
    mainwindow.cpp \
    newprojectwizard.cpp \
    plotterdata.cpp \
    progressplotter.cpp \
    selectprojectpage.cpp \
    pruebapantallas.cpp \
    view.cpp \
    simulationcontrol.cpp

HEADERS += \
    chooseprojectnamepage.h \
    mainwindow.h \
    newprojectwizard.h \
    plotterdata.h \
    progressplotter.h \
    selectprojectpage.h \
    pruebapantallas.h \
    icons.h \
    view.h \
    simulationcontrol.h

FORMS += \
    chooseprojectnamepage.ui \
    mainwindow.ui \
    newprojectdialog.ui \
    newprojectwizard.ui \
    selectprojectpage.ui \
    prueba_pantallas.ui

RESOURCES += \
    gui_media.qrc

win32:{
    CONFIG += windows c++11

    CONFIG(release, debug|release):{
		message("Building release binaries for gui module");

		QMAKE_CXXFLAGS += /MD

		TARGET = INSYDE

		LIBS += -L$$DESTDIR -lcore \
				-L$$DESTDIR -lann_base \
				-L$$DESTDIR -lann_gui\
				-L$$DESTDIR -lec_base \
				-L$$DESTDIR -lec_gui

	}else:{#DEBUG

		message("Building debug binaries for gui module");

		TARGET = INSYDE_debug

		QMAKE_CXXFLAGS += /MDd

		LIBS += -L$$DESTDIR -lcore_debug \
				-L$$DESTDIR -lann_base_debug \
				-L$$DESTDIR -lann_gui_debug \
				-L$$DESTDIR -lec_base_debug \
				-L$$DESTDIR -lec_gui_debug

    }
#   if x86_64
	contains(QMAKE_TARGET.arch, x86_64): {
		QMAKE_LFLAGS += /MACHINE:X64
	}

    message("Windows")
}

unix:CONFIG(release, debug|release){

    QMAKE_CXXFLAGS += -std=c++11 -O3

    TARGET = INSYDE

    LIBS += -L$$DESTDIR -lcore \
            -L$$DESTDIR -lann_base \
            -L$$DESTDIR -lann_gui
#            -L$$DESTDIR -lec_base \
#            -L$$DESTDIR -lec_gui

    message("Building $$TARGET binaries in release mode")

}

unix:CONFIG(debug, debug|release){

    QMAKE_CXXFLAGS += -std=c++11

    TARGET = INSYDE_debug

    LIBS += -L$$DESTDIR -lcore_debug \
            -L$$DESTDIR -lann_base_debug \
            -L$$DESTDIR -lann_gui_debug
#            -L$$DESTDIR -lec_base_debug \
#            -L$$DESTDIR -lec_gui_debug


    message("Building $$TARGET binaries in debug mode")

}
