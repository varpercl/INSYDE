
#include(../external/kdchart2.pri)
include(../external/tbb.pri)

QT += core xml opengl sql charts

CONFIG += qt thread shared precompile_header

TEMPLATE = lib

DEFINES += EXPORT_ANN_BASE_LIB

MOC_DIR = moc
UI_DIR = ui
OBJECTS_DIR = obj
RCC_DIR = res
DESTDIR = ..

PRECOMPILED_HEADER += \
    trainingset.h \
    mlp.h \
simpleperceptron.h \
adaline.h \
trainingsetfile.h

HEADERS += \
trainingset.h \
simpleperceptron.h \
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
globals.h \
    perceptrontrainingpattern.h \
    share_ann_base_lib.h \
    adalinetrainingpattern.h \
    simpleinputpattern.h \
    kohonen.h \
    settings.h \
    documentation.h \
    annfile.h \
    trainingsetsql.h

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
satrainingsettings.cpp \
artificialneuralnetwork.cpp \
hopfield.cpp \
    perceptrontrainingpattern.cpp \
    adalinetrainingpattern.cpp \
    kohonen.cpp \
    settings.cpp \
    annfile.cpp \
    trainingsetsql.cpp

win32:{

	CONFIG += windows c++11

	CONFIG(release, debug|release):{#RELEASE
		message("Building release binaries for ann_base module");

		QMAKE_CXXFLAGS += /MD

		TARGET = ann_base

		LIBS += -L$$DESTDIR -lcore

	}else:{ #DEBUG
		message("Building debug binaries for ann_core module");

		QMAKE_CXXFLAGS += /MDd

		TARGET = ann_base_debug

                LIBS += -L$$DESTDIR -lcore_debug
	}

#   if x86_64
	contains(QMAKE_TARGET.arch, x86_64): {
		QMAKE_LFLAGS += /MACHINE:X64
	}

#    LIBS += -L"C:\Program Files\MySQL\MySQL Server 5.7\lib" -llibmysql
#    LIBS += -L"C:\Program Files (x86)\MySQL\MySQL Connector C++ 1.1.9\lib\opt" -llibmysqlcppconn
#    LIBS += -L"C:\Program Files (x86)\MySQL\MySQL Connector C++ 1.1.9\lib\opt" -lmysqlcppconn
    LIBS += -L"C:\Program Files (x86)\MySQL\MySQL Connector C 6.1\lib" -llibmysql
#    LIBS += -L"C:\Program Files (x86)\MySQL\MySQL Connector C 6.1\lib" -lmysql


}

unix:CONFIG(release, debug|release){

    QMAKE_CXXFLAGS += -std=c++11 -O3

    TARGET = ann_base

    LIBS += -L$$DESTDIR -lcore

    lib.path = $$PWD/../../custom_libs/insyde/$$TARGET/lib
    lib.files = $$OUT_PWD/../$$join(TARGET,,"lib").*

    includes.path = $$PWD/../../custom_libs/insyde/$$TARGET/include
    includes.files = $$PWD/*.h
    INSTALLS += lib includes

    message("Preparing $$TARGET binaries in release mode")
}

unix:CONFIG(debug, debug|release){

    QMAKE_CXXFLAGS += -std=c++11

    TARGET = ann_base_debug

    LIBS += -L$$DESTDIR -lcore_debug

    message("Preparing $$TARGET binaries in debug mode")

}
