
QT += core widgets opengl gui

CONFIG += qt shared_and_static

#CONFIG(release, debug|release):message("Staring RELEASE build for ann_gui sources") #will print
#CONFIG(debug, debug|release):message("Staring DEBUG build for ann_gui sources") #no print


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

#	QMAKE_LFLAGS += /MACHINE:X64

    CONFIG(release, debug|release):{
		LIBS += -L$$PWD/../external/tbb44_20160128oss_win_0/bin/intel64/vc12/ -ltbb \
				-L$$PWD/../external/tbb44_20160128oss_win_0/lib/intel64/vc12/ -ltbb \
				-L$$PWD/../external/kdchart-2.5.1-source-win/lib/ -lkdchart2 \
				-L$$DESTDIR -lcore \
				-L$$DESTDIR -lann_base

		TARGET = ann_gui

	}else
	{

		LIBS += -L$$PWD/../external/tbb44_20160128oss_win_0/bin/intel64/vc12/ -ltbb_debug \
				-L$$PWD/../external/tbb44_20160128oss_win_0/lib/intel64/vc12/ -ltbb_debug \
				-L$$PWD/../external/kdchart-2.5.1-source-win/lib/ -lkdchartd2 \
				-L$$DESTDIR -lcore_debug \
				-L$$DESTDIR -lann_base_debug

		TARGET = ann_gui_debug

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
