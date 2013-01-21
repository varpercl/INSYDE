#-------------------------------------------------
#
# Project created by QtCreator 2013-01-18T02:05:53
#
#-------------------------------------------------

TARGET = ANNGraphicInterface
TEMPLATE = lib

DEFINES += ANNGRAPHICINTERFACE_LIBRARY

debug{EXTRA = bindebug}
release{EXTRA = binrelease}
DESTDIR = ../$$EXTRA

SOURCES += anngraphicinterface.cpp

HEADERS += anngraphicinterface.h\
		ANNGraphicInterface_global.h

#unix:!symbian {
#    maemo5 {
#        target.path = /opt/usr/lib
#    } else {
#        target.path = /usr/lib
#    }
#    INSTALLS += target
#}
