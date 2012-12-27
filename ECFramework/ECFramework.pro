#-------------------------------------------------
#
# Project created by QtCreator 2012-07-24T13:19:26
#
#-------------------------------------------------

TARGET = ECFramework
TEMPLATE = lib

DEFINES += ECFRAMEWORK_LIBRARY

SOURCES += ecframework.cpp \
    acosolver.cpp \
    ant.cpp

HEADERS += ecframework.h\
        ECFramework_global.h \
    acosolver.h \
    ant.h

INCLUDEPATH += .

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE79380E0
    TARGET.CAPABILITY =
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = ECFramework.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
