
include(../external/kdchart2.pri)
include(../external/tbb.pri)

QT += core widgets opengl gui

CONFIG += qt shared

TEMPLATE = lib

MOC_DIR = moc
UI_DIR = ui
OBJECTS_DIR = obj
RCC_DIR = res
DESTDIR = ..

DEFINES += EXPORT_ANN_GUI_LIB \

SOURCES += \
    adalinepage.cpp \
    addnewmlpdialog.cpp \
    perceptrondisplay.cpp \
    perceptronpage.cpp \
    samplesdialog.cpp \
    simulatedannealingwidget.cpp \
    trainingsetdialog.cpp \
    trainingsettable.cpp \
    weightline.cpp \
    weighteditordialog.cpp \
    anntrainingdialog.cpp \
    annmodelwrapper.cpp \
    tsmodelwrapper.cpp \
    annview.cpp \
    annmodeltree.cpp \
    mlpobject.cpp \
    mlpobjectpropertydialog.cpp


HEADERS += \
    adalinepage.h \
    addnewmlpdialog.h \
    perceptrondisplay.h \
    perceptronpage.h \
    samplesdialog.h \
    simulatedannealingwidget.h \
    trainingsetdialog.h \
    trainingsettable.h \
    weightline.h \
    weighteditordialog.h \
    anntrainingdialog.h \
    annmodelwrapper.h \
    share_ann_gui_lib.h \
    tsmodelwrapper.h \
    annview.h \
    annmodeltree.h \
    definitions.h \
    mlpobject.h \
    mlpobjectpropertydialog.h

RESOURCES += \
    ann_gui_media.qrc

FORMS += \
    adalinepage.ui \
    addnewmlpdialog.ui \
    graphicmlpelementpropertydialog.ui \
    perceptronpage.ui \
    samplesdialog.ui



win32:{
	CONFIG += windows c++11

	CONFIG(release, debug|release):{#RELEASE
		message("Building release binaries for ann_gui module")

		TARGET = ann_gui

		QMAKE_CXXFLAGS += /MD

		LIBS += -L$$DESTDIR -lcore \
				-L$$DESTDIR -lann_base

	}else:{
		message("Building debug binaries for ann_gui module");

		TARGET = ann_gui_debug

		QMAKE_CXXFLAGS += /MDd

		LIBS += -L$$DESTDIR -lcore_debug \
                        -L$$DESTDIR -lann_base_debug

    }

#   if x86_64
	contains(QMAKE_TARGET.arch, x86_64): {
		QMAKE_LFLAGS += /MACHINE:X64
	}
}

unix:{

    QMAKE_CXX += -std=c++11

#    LIBS += -L$$PWD/../external/tbb42_20140416oss_lin/bin/intel64/gcc4.4/ -ltbb \
#            -L$$PWD/../external/tbb42_20140416oss_lin/lib/intel64/gcc4.4/ -ltbb \
#            -L$$PWD/../external/kdchart-2.5.1-source-linux/lib/release/ -lkdchart

    CONFIG(release, debug|release):{
	QMAKE_CXX += -O3

        TARGET = ann_gui

        LIBS += -L$$DESTDIR -lcore \
                -L$$DESTDIR -lann_base
#	LIBS += -L$$PWD/../external/tbb42_20140416oss_lin/bin/intel64/gcc4.4/ -ltbb \
#		-L$$PWD/../external/tbb42_20140416oss_lin/lib/intel64/gcc4.4/ -ltbb \
#		-L$$PWD/../external/kdchart-2.5.1-source-linux/lib/release/ -lkdchart

	lib.path = $$PWD/../../custom_libs/insyde/$$TARGET/lib
	lib.files = $$OUT_PWD/../$$join(TARGET,,"lib").*

	includes.path = $$PWD/../../custom_libs/insyde/$$TARGET/include
	includes.files = $$PWD/*.h
	INSTALLS += lib includes
    }
    else:
    {
        TARGET = ann_gui_debug

        LIBS += -L$$DESTDIR -lcore_debug \
                -L$$DESTDIR -lann_base_debug

#	LIBS += -L$$PWD/../external/tbb42_20140416oss_lin/bin/intel64/gcc4.4/ -ltbb_debug \
#		-L$$PWD/../external/tbb42_20140416oss_lin/lib/intel64/gcc4.4/ -ltbb_debug \
#		-L$$PWD/../external/kdchart-2.5.1-source-linux/lib/debug/ -lkdchart
    }

    INCLUDEPATH += $$PWD/../external/kdchart-2.5.1-source-linux/include
    DEPENDPATH += $$PWD/../external/kdchart-2.5.1-source-linux/include

    INCLUDEPATH += $$PWD/../external/tbb42_20140416oss_lin/include
    DEPENDPATH += $$PWD/../external/tbb42_20140416oss_lin/include
}
