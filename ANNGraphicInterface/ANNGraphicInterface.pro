#-------------------------------------------------
#
# Project created by QtCreator 2013-01-18T02:05:53
#
#-------------------------------------------------

TARGET = ANNGraphicInterface
TEMPLATE = lib

DEFINES += ANNGRAPHICINTERFACE_LIBRARY

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
