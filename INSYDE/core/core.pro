
QT += widgets xml

CONFIG += qt shared c++11

CONFIG(release, debug|release):message("Staring RELEASE build for core sources") #will print
CONFIG(debug, debug|release):message("Staring DEBUG build for core sources") #no print

TARGET = core

TEMPLATE = lib

MOC_DIR = moc
UI_DIR = ui
OBJECTS_DIR = obj
RCC_DIR = res
DESTDIR = ..

HEADERS += \
    common.h \
    labeledcombobox.h \
    integersizewidget.h \
    dotmatrix.h \
    labeleddoublespinbox.h \
    labeledintegerspinbox.h \
    labeledwidget.h \
    datarepresentationbox.h \
    datarepresentationwidget.h \
    dotmatrixrepresentation.h \
    imagerepresentationwidget.h \
    rawrepresentationwidget.h \
    dotmatrixdetailedwindow.h \
    dotmatrixpropertydialog.h \
    imagedetailedwindow.h \
    imagepropertydialog.h \
    image.h \
    basicdialog.h \
    zoomcontrol.h \
    interfaces.h \
    icons.h \
    graphicobject.h \
    basictable.h \
    datarepresentation.h \
    normalization.h \
    normalizationwidget.h \
    detailedwindow.h \
    basictree.h \
    doubleminmaxvaluewidget.h

SOURCES += \
    common.cpp \
    labeledcombobox.cpp \
    integersizewidget.cpp \
    dotmatrix.cpp \
    labeleddoublespinbox.cpp \
    labeledintegerspinbox.cpp \
    labeledwidget.cpp \
    datarepresentationbox.cpp \
    datarepresentationwidget.cpp \
    dotmatrixrepresentation.cpp \
    imagerepresentationwidget.cpp \
    rawrepresentationwidget.cpp \
    dotmatrixdetailedwindow.cpp \
    dotmatrixpropertydialog.cpp \
    imagepropertydialog.cpp \
    imagedetailedwindow.cpp \
    basicdialog.cpp \
    zoomcontrol.cpp \
    graphicobject.cpp \
    basictable.cpp \
    image.cpp \
    datarepresentation.cpp \
    normalization.cpp \
    normalizationwidget.cpp \
    detailedwindow.cpp \
    basictree.cpp \
    doubleminmaxvaluewidget.cpp

RESOURCES += \
    media.qrc

FORMS +=

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

