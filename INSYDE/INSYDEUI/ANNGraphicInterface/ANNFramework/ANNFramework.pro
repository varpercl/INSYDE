#-------------------------------------------------
#
# Project created by QtCreator 2012-04-07T16:45:40
#
#-------------------------------------------------

QT       += core xml

CONFIG += qt thread  #debug_and_release
CONFIG += c++11

TARGET = ANNFramework
TEMPLATE = lib

DEFINES += ANNFRAMEWORK_LIBRARY

debug:DESTDIR = "../../../debug"
release:DESTDIR = "../../../release"
debug:OBJECTS_DIR = "debug/obj"
release:OBJECTS_DIR = "release/obj"
debug:MOC_DIR = "debug/moc"
release:MOC_DIR = "release/moc"
debug:RCC_DIR = "debug/rcc"
release:RCC_DIR = "release/rcc"
debug:UI_DIR = "debug/ui"
release:UI_DIR = "release/ui"

HEADERS += \
	trainingset.h \
	simpleperceptron.h \
	simplepattern.h \
	hopfieldnetwork.h \
	adaline.h \
    trainingsetfile.h \
    simpleperceptronfile.h \
    normalization.h \
    trainingresult.h \
    mlptrainingresult.h \
    backpropagationtrainingsettings.h \
    mlppattern.h \
    mlp.h \
    itrainingset.h \
    ANNglobal.h \
    satrainingsettings.h

SOURCES += \
	trainingset.cpp \
	simpleperceptron.cpp \
	simplepattern.cpp \
	hopfieldnetwork.cpp \
	adaline.cpp \
    trainingsetfile.cpp \
    simpleperceptronfile.cpp \
    normalization.cpp \
    trainingresult.cpp \
    mlptrainingresult.cpp \
    mlp.cpp \
    mlppattern.cpp \
    bptrainingsettings.cpp \
    ANNglobal.cpp \
    itrainingset.cpp \
    satrainingsettings.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../tbb42_20140416oss/lib/intel64/gcc4.4/release/ -ltbb
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../tbb42_20140416oss/lib/intel64/gcc4.4/debug/ -ltbb
else:unix: LIBS += -L$$PWD/../../../../tbb42_20140416oss/lib/intel64/gcc4.4/ -ltbb

INCLUDEPATH += $$PWD/../../../../tbb42_20140416oss/include
DEPENDPATH += $$PWD/../../../../tbb42_20140416oss/include
