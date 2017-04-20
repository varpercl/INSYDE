
#include(../external/kdchart2.pri)
include(../external/tbb.pri)
include(../external/opencv.pri)

QT += core xml opengl multimedia multimediawidgets

CONFIG += qt thread shared

TEMPLATE = lib

DEFINES += EXPORT_CV_GUI_LIB

MOC_DIR = moc
UI_DIR = ui
OBJECTS_DIR = obj
RCC_DIR = res
DESTDIR = ..

HEADERS += \
facerecognizer.h \
    share_cv_gui_lib.h \
    documentation.h \
    facerecognizerpropertydialog.h

SOURCES += \
facerecognizer.cpp \
    facerecognizerpropertydialog.cpp

win32:{

	CONFIG += windows c++11

	CONFIG(release, debug|release):{#RELEASE
		message("Building release binaries for cv_gui module");

#		QMAKE_CXXFLAGS += /MD

		TARGET = cv_gui

		LIBS += -L$$DESTDIR -lcore

	}else:{ #DEBUG
		message("Building debug binaries for cv_gui module");

#		QMAKE_CXXFLAGS += /MDd

		TARGET = cv_gui_debug

		LIBS += -L$$DESTDIR -lcore_debug \
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

	LIBS += -L$$PWD/../external/tbb42_20140416oss_lin/bin/intel64/gcc4.4/ -ltbb \
		-L$$PWD/../external/tbb42_20140416oss_lin/lib/intel64/gcc4.4/ -ltbb \
		-L$$PWD/../external/kdchart-2.5.1-source-linux/lib/release/ -lkdchart

	lib.path = $$PWD/../../custom_libs/insyde/$$TARGET/lib
	lib.files = $$OUT_PWD/../$$join(TARGET,,"lib").*

	includes.path = $$PWD/../../custom_libs/insyde/$$TARGET/include
	includes.files = $$PWD/*.h
	INSTALLS += lib includes
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
