
QT += core gui widgets opengl xml

CONFIG += qt opengl shared_and_static

#CONFIG(release, debug|release):message("Staring RELEASE build for ec_base sources")
#CONFIG(debug, debug|release):message("Staring DEBUG build for ec_base sources")


TEMPLATE = lib

MOC_DIR = moc
UI_DIR = ui
OBJECTS_DIR = obj
RCC_DIR = res
DESTDIR = ..

DEFINES += ECFRAMEWORK_LIBRARY

#QMAKE_CXX += -std=c++11

SOURCES += \
	acosolver.cpp \
	ant.cpp

HEADERS += \
		ECFramework_global.h \
	acosolver.h \
	ant.h

win32:{
    CONFIG(release, debug|release):{
		TARGET = ec_base

		QMAKE_CXXFLAGS += /MD

		LIBS += -L$$DESTDIR -lcore \

	}else:{#DEBUG

		message("Building debug binaries for ec_base module");

		TARGET = ec_base_debug

		QMAKE_CXXFLAGS += /MDd
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
