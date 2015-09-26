
QT += xml

CONFIG += qt shared thread c++11

CONFIG(release, debug|release):message("Staring RELEASE build for ann_base sources") #will print
CONFIG(debug, debug|release):message("Staring DEBUG build for ann_base sources") #no print

TARGET = ann_base

TEMPLATE = lib

MOC_DIR = moc
UI_DIR = ui
OBJECTS_DIR = obj
RCC_DIR = res
DESTDIR = ..

DEFINES +=

HEADERS += \
trainingset.h \
simpleperceptron.h \
simplepattern.h \
adaline.h \
trainingsetfile.h \
    simpleperceptronfile.h \
    trainingresult.h \
    mlptrainingresult.h \
    mlppattern.h \
    mlp.h \
    satrainingsettings.h \
    artificialneuralnetwork.h \
    bptrainingsettings.h \
    hopfield.h \
    globals.h

SOURCES += \
	trainingset.cpp \
	simpleperceptron.cpp \
	simplepattern.cpp \
	adaline.cpp \
    trainingsetfile.cpp \
    simpleperceptronfile.cpp \
    trainingresult.cpp \
    mlptrainingresult.cpp \
    mlp.cpp \
    mlppattern.cpp \
    bptrainingsettings.cpp \
    ANNglobal.cpp \
    satrainingsettings.cpp \
    artificialneuralnetwork.cpp \
    hopfield.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../external/tbb42_20140416oss/lib/intel64/gcc4.4/release/ -ltbb
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../external/tbb42_20140416oss/lib/intel64/gcc4.4/debug/ -ltbb
else:unix: LIBS += -L$$PWD/../external/tbb42_20140416oss/lib/intel64/gcc4.4/ -ltbb

INCLUDEPATH += $$PWD/../external/tbb42_20140416oss/include
DEPENDPATH += $$PWD/../external/tbb42_20140416oss/include

