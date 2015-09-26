
CONFIG += qt shared

CONFIG(release, debug|release):message("Staring RELEASE build for ec_base sources")
CONFIG(debug, debug|release):message("Staring DEBUG build for ec_base sources")

TARGET = ec_base

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
