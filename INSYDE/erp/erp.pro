#-------------------------------------------------
#
# Project created by QtCreator 2015-09-17T01:02:04
#
#-------------------------------------------------

QT       += widgets sql xml

QT       -= gui

TARGET = erp
TEMPLATE = lib

DEFINES += ERP_LIBRARY

SOURCES += erp.cpp

HEADERS += erp.h\
        erp_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
