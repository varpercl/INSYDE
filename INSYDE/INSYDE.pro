#-------------------------------------------------
#
# Project created by QtCreator 2012-02-26T21:37:49
#
#-------------------------------------------------


QT       += core gui opengl

CONFIG += #debug_and_release
#CONFIG += c++11

TARGET = INSYDE
TEMPLATE = app

#QMAKE_CXXFLAGS += -std=c++0x -ansi -U__STRICT_ANSI__
#QMAKE_CXXFLAGS += -std=c++0x -U__STRICT_ANSI__
#QMAKE_CXX += -fno-elide-constructors -Wunused-parameter
QMAKE_CXX += -std=c++11
QMAKE_CXX += -Wswitch

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

debug{

    DESTDIR = "debug"
    OBJECTS_DIR = "debug/obj"
    MOC_DIR = "debug/moc"
    RCC_DIR = "debug/rcc"

    LIBS += -L"debug"
}

release {

    DESTDIR = "release"
    OBJECTS_DIR = "release/obj"
    MOC_DIR = "release/moc"
    RCC_DIR = "release/rcc"

    LIBS += -L"release"
}

    UI_DIR = "ui"
#debug:OBJECTS_DIR = "debug/obj"
#release:OBJECTS_DIR = "release/obj"
#debug:MOC_DIR = "debug/moc"
#release:MOC_DIR = "release/moc"
#debug:RCC_DIR = "debug/rcc"
#release:RCC_DIR = "release/rcc"
#debug:UI_DIR = "debug/ui"
#release:UI_DIR = "release/ui"

#debug:LIBS += -L"debug"
#release:LIBS += -L"release"

unix {

#DEPENDPATH += /home/edixonvargas/Programacion/kdchart-2.5.1-source/include
#INCLUDEPATH += /home/edixonvargas/Programacion/kdchart-2.5.1-source/include

}

LIBS += \# -L/home/edixonvargas/Programacion/kdchart-2.5.1-source/lib \
#    -lkdchart \
#-ltesttools \
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

RESOURCES += \
    trainingsets.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../tbb42_20140416oss/lib/intel64/gcc4.4/release/ -ltbb
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../tbb42_20140416oss/lib/intel64/gcc4.4/debug/ -ltbb
else:unix: LIBS += -L$$PWD/../tbb42_20140416oss/lib/intel64/gcc4.4/ -ltbb

INCLUDEPATH += $$PWD/../tbb42_20140416oss/include
DEPENDPATH += $$PWD/../tbb42_20140416oss/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../kdchart-2.5.1-source/lib/release/ -lkdchart
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../kdchart-2.5.1-source/lib/debug/ -lkdchart
else:unix: LIBS += -L$$PWD/../kdchart-2.5.1-source/lib/ -lkdchart

INCLUDEPATH += $$PWD/../kdchart-2.5.1-source/include
DEPENDPATH += $$PWD/../kdchart-2.5.1-source/include
