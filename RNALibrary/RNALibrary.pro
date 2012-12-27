#-------------------------------------------------
#
# Project created by QtCreator 2012-04-07T16:45:40
#
#-------------------------------------------------

QT       += core gui

TARGET = RNALibrary
TEMPLATE = lib

#INCLUDEPATH +=

DEFINES += RNALIBRARY_LIBRARY

debug{EXTRA = debug}
release{EXTRA = release}
DESTDIR = ../$$EXTRA

HEADERS += \
	trainingset.h \
	simpleperceptron.h \
	simplepattern.h \
	neuralnetwork.h \
	itrainable.h \
	hopfieldnetwork.h \
	adaline.h \
	RNALibrary_global.h \
    multilayerperceptron.h \
    general.h

SOURCES += \
	trainingset.cpp \
	simpleperceptron.cpp \
	simplepattern.cpp \
	neuralnetwork.cpp \
	hopfieldnetwork.cpp \
	adaline.cpp \
    multilayerperceptron.cpp \
    general.cpp
