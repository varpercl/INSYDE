
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

DEFINES += EXPORT_ANN_GUI_LIB

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

RESOURCES += ann_gui_media.qrc

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

unix:CONFIG(release, debug|release){

    QMAKE_CXXFLAGS += -std=c++11 -O3

    TARGET = ann_gui

    LIBS += -L$$DESTDIR -lcore \
            -L$$DESTDIR -lann_base

    lib.path = $$PWD/../../custom_libs/insyde/$$TARGET/lib
    lib.files = $$OUT_PWD/../$$join(TARGET,,"lib").*

    includes.path = $$PWD/../../custom_libs/insyde/$$TARGET/include
    includes.files = $$PWD/*.h
    INSTALLS += lib includes

    message("Building $$TARGET binaries in release mode")
}

unix:CONFIG(debug, debug|release){

    QMAKE_CXXFLAGS += -std=c++11

    TARGET = ann_gui_debug

    LIBS += -L$$DESTDIR -lcore_debug \
            -L$$DESTDIR -lann_base_debug

    message("Building $$TARGET binaries in debug mode")

}
