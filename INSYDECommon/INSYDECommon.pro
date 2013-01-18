#-------------------------------------------------
#
# Project created by QtCreator 2013-01-17T17:15:39
#
#-------------------------------------------------

QT       -= gui

TARGET = INSYDECommon
TEMPLATE = lib

DEFINES += INSYDECOMMON_LIBRARY

debug{EXTRA = debug}
release{EXTRA = release}
DESTDIR = ../$$EXTRA

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
