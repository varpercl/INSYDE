#-------------------------------------------------
#
# Project created by QtCreator 2012-02-26T21:37:49
#
#-------------------------------------------------


QT       += core gui opengl
#CONFIG += qt
TARGET = INSYDE
TEMPLATE = app

#QMAKE_CXXFLAGS += -std=c++0x -ansi -U__STRICT_ANSI__
#QMAKE_CXXFLAGS += -std=c++0x -U__STRICT_ANSI__
#QMAKE_CXX += -fno-elide-constructors -Wunused-parameter
QMAKE_CXX += -std=c++11

QMAKE_CFLAGS


INCLUDEPATH +=


#debug:EXTRA = debug
#release:EXTRA = release

#DESTDIR = $$EXTRA
#OBJECTS_DIR = $$EXTRA/obj
#MOC_DIR = $$EXTRA/moc
#RCC_DIR = $$EXTRA/rcc
#UI_DIR = $$EXTRA/ui

#debug:DESTDIR = "debug"
#release:DESTDIR = "release"
debug:OBJECTS_DIR = "debug/obj"
release:OBJECTS_DIR = "release/obj"
debug:MOC_DIR = "debug/moc"
release:MOC_DIR = "release/moc"
debug:RCC_DIR = "debug/rcc"
release:RCC_DIR = "release/rcc"
debug:UI_DIR = "debug/ui"
release:UI_DIR = "release/ui"

debug:LIBS += -L"debug"
release:LIBS += -L"release"
LIBS +=	 \
    -lINSYDEUI \
    -lANNFramework \
    -lECFramework

SOURCES += pruebapantallas.cpp \
	mainwindow.cpp \
	main.cpp

HEADERS  += pruebapantallas.h \
	mainwindow.h

FORMS    += mainwindow.ui \
	prueba_pantallas.ui \

RESOURCES +=
