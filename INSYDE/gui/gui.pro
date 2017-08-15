
include(../external/kdchart2.pri)
include(../external/tbb.pri)

QT += core widgets xml opengl

CONFIG += qt opengl

TEMPLATE = app

DEFINES += \
#WINDOW_HEIGH=31 \
#WINDOW_WIDTH=13 \
#WINDOW_STEP=1

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
}

unix:{

    QMAKE_CXX += -std=c++11

    CONFIG(release, debug|release):{
	QMAKE_CXX += -O3

        TARGET = INSYDE

        LIBS += -L$$DESTDIR -lcore \
                -L$$DESTDIR -lann_base \
                -L$$DESTDIR -lann_gui\
                -L$$DESTDIR -lec_base \
                -L$$DESTDIR -lec_gui

#	LIBS += -L$$PWD/../external/tbb42_20140416oss_lin/bin/intel64/gcc4.4/ -ltbb \
#		-L$$PWD/../external/tbb42_20140416oss_lin/lib/intel64/gcc4.4/ -ltbb \
#		-L$$PWD/../external/kdchart-2.5.1-source-linux/lib/release/ -lkdchart
    }
    else:
    {
        TARGET = INSYDE_debug

        LIBS += -L$$DESTDIR -lcore_debug \
                -L$$DESTDIR -lann_base_debug \
                -L$$DESTDIR -lann_gui_debug \
                -L$$DESTDIR -lec_base_debug \
                -L$$DESTDIR -lec_gui_debug

#	LIBS += -L$$PWD/../external/tbb42_20140416oss_lin/bin/intel64/gcc4.4/ -ltbb_debug \
#		-L$$PWD/../external/tbb42_20140416oss_lin/lib/intel64/gcc4.4/ -ltbb_debug \
#		-L$$PWD/../external/kdchart-2.5.1-source-linux/lib/debug/ -lkdchart
    }

    INCLUDEPATH += $$PWD/../external/kdchart-2.5.1-source-linux/include
    DEPENDPATH += $$PWD/../external/kdchart-2.5.1-source-linux/include


    INCLUDEPATH += $$PWD/../external/tbb42_20140416oss_lin/include
    DEPENDPATH += $$PWD/../external/tbb42_20140416oss_lin/include
}
