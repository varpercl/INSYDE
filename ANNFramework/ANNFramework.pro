#-------------------------------------------------
#
# Project created by QtCreator 2012-04-07T16:45:40
#
#-------------------------------------------------

#QT       += core gui

TARGET = ANNFramework
TEMPLATE = lib

#INCLUDEPATH +=

DEFINES += ANNFRAMEWORK_LIBRARY

debug{EXTRA = bindebug}
release{EXTRA = binrelease}
DESTDIR = ../$$EXTRA

INCLUDEPATH += .

HEADERS += \
	trainingset.h \
	simpleperceptron.h \
	simplepattern.h \
	neuralnetwork.h \
	itrainable.h \
	hopfieldnetwork.h \
	adaline.h \
	multilayerperceptron.h \
	ANNFramework_global.h

SOURCES += \
	trainingset.cpp \
	simpleperceptron.cpp \
	simplepattern.cpp \
	neuralnetwork.cpp \
	hopfieldnetwork.cpp \
	adaline.cpp \
	multilayerperceptron.cpp \
	ANNFramework_global.cpp
