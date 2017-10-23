
#include(../external/kdchart2.pri)
include(../external/tbb.pri)

QT += gui core widgets xml opengl charts

CONFIG += qt opengl console

TEMPLATE = app

MOC_DIR = moc
UI_DIR = ui
OBJECTS_DIR = obj
RCC_DIR = res
DESTDIR = ..

SOURCES += \
    main.cpp

win32:{
    CONFIG += windows c++11

    CONFIG(release, debug|release):{
                message("Building release binaries for gui module");

                QMAKE_CXXFLAGS += /MD

                TARGET = anntool

                LIBS += -L$$DESTDIR -lcore \
                                -L$$DESTDIR -lann_base \
				-L$$DESTDIR -lann_gui \
				-L$$DESTDIR -lec_base \ #Necesary?
				-L$$DESTDIR -lec_gui	#Necesary?

        }else:{#DEBUG

                message("Building debug binaries for gui module");

                TARGET = anntool_debug

                QMAKE_CXXFLAGS += /MDd

                LIBS += -L$$DESTDIR -lcore_debug \
                                -L$$DESTDIR -lann_base_debug \
                                -L$$DESTDIR -lann_gui_debug \
				-L$$DESTDIR -lec_base_debug \	#Necesary?
				-L$$DESTDIR -lec_gui_debug	#Necesary?

    }
#   if x86_64
        contains(QMAKE_TARGET.arch, x86_64): {
                QMAKE_LFLAGS += /MACHINE:X64
        }
}

unix:CONFIG(release, debug|release){

    QMAKE_CXXFLAGS += -std=c++11 -O3

    TARGET = anntool

    LIBS += -L$$DESTDIR -lcore \
            -L$$DESTDIR -lann_base \
            -L$$DESTDIR -lann_gui
#            -L$$DESTDIR -lec_base \
#            -L$$DESTDIR -lec_gui

    message("Building $$TARGET binaries in release mode")

}

unix:CONFIG(debug, debug|release){

    QMAKE_CXXFLAGS += -std=c++11

    TARGET = anntool_debug

    LIBS += -L$$DESTDIR -lcore_debug \
            -L$$DESTDIR -lann_base_debug \
            -L$$DESTDIR -lann_gui_debug
#            -L$$DESTDIR -lec_base_debug \
#            -L$$DESTDIR -lec_gui_debug


    message("Building $$TARGET binaries in debug mode")

}

