#-------------------------------------------------
#
# Project created by QtCreator 2012-07-24T13:19:26
#
#-------------------------------------------------


TARGET = ECFramework
TEMPLATE = lib

DEFINES += ECFRAMEWORK_LIBRARY

SOURCES += \
	acosolver.cpp \
	ant.cpp

HEADERS +=\
		ECFramework_global.h \
	acosolver.h \
	ant.h

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

INCLUDEPATH += .

#symbian {
#    MMP_RULES += EXPORTUNFROZEN
#    TARGET.UID3 = 0xE79380E0
#    TARGET.CAPABILITY =
#    TARGET.EPOCALLOWDLLDATA = 1
#    addFiles.sources = ECFramework.dll
#    addFiles.path = !:/sys/bin
#    DEPLOYMENT += addFiles
#}

#unix:!symbian {
#    maemo5 {
#        target.path = /opt/usr/lib
#    } else {
#        target.path = /usr/lib
#    }
#    INSTALLS += target
#}
