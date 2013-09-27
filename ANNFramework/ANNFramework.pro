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

#debug:EXTRA = debug
#release:EXTRA = release
#DESTDIR = ../$$EXTRA
#OBJECTS_DIR = $$EXTRA/obj
#MOC_DIR = $$EXTRA/moc
#RCC_DIR = $$EXTRA/rcc
#UI_DIR = $$EXTRA/ui

#debug:EXTRA = debug
#release:EXTRA = release

debug:DESTDIR = "../debug"
release:DESTDIR = "../release"
debug:OBJECTS_DIR = "debug/obj"
release:OBJECTS_DIR = "release/obj"
debug:MOC_DIR = "debug/moc"
release:MOC_DIR = "release/moc"
debug:RCC_DIR = "debug/rcc"
release:RCC_DIR = "release/rcc"
debug:UI_DIR = "debug/ui"
release:UI_DIR = "release/ui"

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
