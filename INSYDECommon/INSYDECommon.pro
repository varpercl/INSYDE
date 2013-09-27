#-------------------------------------------------
#
# Project created by QtCreator 2013-01-17T17:15:39
#
#-------------------------------------------------

QT       += gui

TARGET = INSYDECommon
TEMPLATE = lib

DEFINES += INSYDECOMMON_LIBRARY

#debug:EXTRA = debug
#release:EXTRA = release

#DESTDIR = ../$$EXTRA
#OBJECTS_DIR = $$EXTRA/obj
#MOC_DIR = $$EXTRA/moc
#RCC_DIR = $$EXTRA/rcc
#UI_DIR = $$EXTRA/ui

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

#DESTDIR = ..
#OBJECTS_DIR = obj
#MOC_DIR = moc
#RCC_DIR = rcc
#UI_DIR = ui

INCLUDEPATH += .

SOURCES += \
	vector2d.cpp \
	general.cpp

HEADERS +=\
		INSYDECommon_global.h \
	vector2d.h \
	insydefunctions.h

#unix:!symbian {
#    maemo5 {
#        target.path = /opt/usr/lib
#    } else {
#        target.path = /usr/lib
#    }
#    INSTALLS += target
#}
