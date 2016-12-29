
#message("Compiling gui sources")

QT += core gui widgets xml opengl

CONFIG += qt opengl

TEMPLATE = app

TARGET = INSYDE

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
    binaryoutputelement.cpp \
    chooseprojectnamepage.cpp \
    main.cpp \
    mainwindow.cpp \
    newprojectwizard.cpp \
    plotterdata.cpp \
    progressplotter.cpp \
    selectprojectpage.cpp \
    pruebapantallas.cpp \
    newmainwindow.cpp \
    view.cpp \
    simulationcontrol.cpp

HEADERS += \
    binaryoutputelement.h \
    chooseprojectnamepage.h \
    mainwindow.h \
    newprojectwizard.h \
    plotterdata.h \
    progressplotter.h \
    selectprojectpage.h \
    pruebapantallas.h \
    newmainwindow.h \
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

#LIBS += \
#-L$$DESTDIR -lcore \
#-L$$DESTDIR -lann_base \
#-L$$DESTDIR -lann_gui\
#-L$$DESTDIR -lec_base \
#-L$$DESTDIR -lec_gui \

win32:{
#	QMAKE_LFLAGS += /MACHINE:X64

    CONFIG(release, debug|release):{
#message("release")
		LIBS += -L$$PWD/../external/tbb44_20160128oss_win_0/lib/intel64/vc14/ -ltbb \
				-L$$PWD/../external/kdchart-2.5.1-source-win/lib/ -lkdchart2 \
				-L$$DESTDIR -lcore \
				-L$$DESTDIR -lann_base \
				-L$$DESTDIR -lann_gui\
				-L$$DESTDIR -lec_base \
				-L$$DESTDIR -lec_gui \
	}else{
		LIBS += -L$$PWD/../external/tbb44_20160128oss_win_0/lib/intel64/vc14/ -ltbb_debug \
				-L$$PWD/../external/kdchart-2.5.1-source-win/lib/x86/ -lkdchartd2 \
				-L$$DESTDIR -lcore_debug \
				-L$$DESTDIR -lann_base_debug \
				-L$$DESTDIR -lann_gui_debug \
				-L$$DESTDIR -lec_base_debug \
				-L$$DESTDIR -lec_gui_debug \
    }

    INCLUDEPATH += $$PWD/../external/kdchart-2.5.1-source-win/include
    DEPENDPATH += $$PWD/../external/kdchart-2.5.1-source-win/include

    INCLUDEPATH += $$PWD/../external/tbb44_20160128oss_win_0/include
    DEPENDPATH += $$PWD/../external/tbb44_20160128oss_win_0/include
}

unix:{

    QMAKE_CXX += -std=c++11

    CONFIG(release, debug|release):{
	QMAKE_CXX += -O3
	LIBS += -L$$PWD/../external/tbb42_20140416oss_lin/bin/intel64/gcc4.4/ -ltbb \
		-L$$PWD/../external/tbb42_20140416oss_lin/lib/intel64/gcc4.4/ -ltbb \
		-L$$PWD/../external/kdchart-2.5.1-source-linux/lib/release/ -lkdchart
    }else{
	LIBS += -L$$PWD/../external/tbb42_20140416oss_lin/bin/intel64/gcc4.4/ -ltbb_debug \
		-L$$PWD/../external/tbb42_20140416oss_lin/lib/intel64/gcc4.4/ -ltbb_debug \
		-L$$PWD/../external/kdchart-2.5.1-source-linux/lib/debug/ -lkdchart
    }

    INCLUDEPATH += $$PWD/../external/kdchart-2.5.1-source-linux/include
    DEPENDPATH += $$PWD/../external/kdchart-2.5.1-source-linux/include


    INCLUDEPATH += $$PWD/../external/tbb42_20140416oss_lin/include
    DEPENDPATH += $$PWD/../external/tbb42_20140416oss_lin/include
}
