
QT += core xml opengl

CONFIG += qt thread shared_and_static

#CONFIG(release, debug|release):message("Staring RELEASE build for ann_base sources") #will print
#CONFIG(debug, debug|release):message("Staring DEBUG build for ann_base sources") #no print


TEMPLATE = lib

DEFINES += EXPORT_ANN_BASE_LIB


MOC_DIR = moc
UI_DIR = ui
OBJECTS_DIR = obj
RCC_DIR = res
DESTDIR = ..

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
    kohonen.h

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
    kohonen.cpp

win32:contains(QMAKE_HOST.arch, x86_64):{
	message("Host is 64bit")

}
win32:{

#	QMAKE_LFLAGS += /MACHINE:X64

	CONFIG(release, debug|release):{#RELEASE
		message("Building release binaries for ann_base module");

		QMAKE_CXXFLAGS += /MD

		TARGET = ann_base

		contains(QMAKE_HOST.arch, x86): {

			LIBS += -L$$PWD/../external/tbb44_20160128oss_win_0/lib/ia32/vc14/ -ltbb \
					-L$$PWD/../external/kdchart-2.5.1-source-win/lib/x86/ -lkdchart2 \
		}

		contains(QMAKE_HOST.arch, x64): {

			LIBS += -L$$PWD/../external/tbb44_20160128oss_win_0/lib/intel64/vc14/ -ltbb \
					-L$$PWD/../external/kdchart-2.5.1-source-win/lib/x64/ -lkdchart2 \
		}

		LIBS += -L$$DESTDIR -lcore \
	}else{ #DEBUG
		message("Building debug binaries for ann_core module");

		QMAKE_CXXFLAGS += /MDd

		TARGET = ann_base_debug
		contains(QMAKE_HOST.arch, x86): {
			message("ann_base module platform is x86");

			LIBS += -L$$PWD/../external/tbb44_20160128oss_win_0/lib/ia32/vc14/ -ltbb_debug \
					-L$$PWD/../external/kdchart-2.5.1-source-win/lib/x86/ -lkdchartd2 \
		}
		contains(QMAKE_HOST.arch, x64): {
			message("ann_base module platform is x64");

			LIBS += -L$$PWD/../external/tbb44_20160128oss_win_0/lib/intel64/vc14/ -ltbb_debug \
					-L$$PWD/../external/kdchart-2.5.1-source-win/lib/x64/ -lkdchartd2 \
		}
		LIBS += -L$$DESTDIR -lcore_debug \

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
