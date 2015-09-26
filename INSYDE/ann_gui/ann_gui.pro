
QT += widgets opengl

CONFIG += qt shared c++11

CONFIG(release, debug|release):message("Staring RELEASE build for ann_gui sources") #will print
CONFIG(debug, debug|release):message("Staring DEBUG build for ann_gui sources") #no print

TARGET = ann_gui

TEMPLATE = lib

MOC_DIR = moc
UI_DIR = ui
OBJECTS_DIR = obj
RCC_DIR = res
DESTDIR = ..

DEFINES += \
WINDOW_HEIGH=31 \
WINDOW_WIDTH=13 \
WINDOW_STEP=1

SOURCES += \
    adalinepage.cpp \
    addnewmlpdialog.cpp \
    graphicmlpelement.cpp \
    graphicmlpelementpropertydialog.cpp \
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
    treeitem.cpp


HEADERS += \
    adalinepage.h \
    addnewmlpdialog.h \
    graphicmlpelement.h \
    graphicmlpelementpropertydialog.h \
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
    treeitem.h

RESOURCES +=

FORMS += \
    adalinepage.ui \
    addnewmlpdialog.ui \
    graphicmlpelementpropertydialog.ui \
    perceptronpage.ui \
    samplesdialog.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../external/kdchart-2.5.1-source/lib/release/ -lkdchart
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../external/kdchart-2.5.1-source/lib/debug/ -lkdchart
else:unix: LIBS += -L$$PWD/../external/kdchart-2.5.1-source/lib/ -lkdchart

INCLUDEPATH += $$PWD/../external/kdchart-2.5.1-source/include
DEPENDPATH += $$PWD/../external/kdchart-2.5.1-source/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../external/tbb42_20140416oss/lib/intel64/gcc4.4/release/ -ltbb
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../external/tbb42_20140416oss/lib/intel64/gcc4.4/debug/ -ltbb
else:unix: LIBS += -L$$PWD/../external/tbb42_20140416oss/lib/intel64/gcc4.4/ -ltbb

INCLUDEPATH += $$PWD/../external/tbb42_20140416oss/include
DEPENDPATH += $$PWD/../external/tbb42_20140416oss/include
