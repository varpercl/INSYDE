include(../external/tbb.pri)

QT += gui core widgets opengl

CONFIG += qt shared_and_static

#CONFIG(release, debug|release):message("Staring RELEASE build for ec_gui sources") #will print
#CONFIG(debug, debug|release):message("Staring DEBUG build for ec_gui sources") #no print


TEMPLATE = lib

MOC_DIR = moc
UI_DIR = ui
OBJECTS_DIR = obj
RCC_DIR = res
DESTDIR = ..

DEFINES += EXPORT_EC_GUI_LIB

SOURCES += \
    actuador.cpp \
    actuadormovimiento.cpp \
    addagentsdialog.cpp \
    agent.cpp \
    defineruledialog.cpp \
    ECFunctions.cpp \
    meleeunit.cpp \
    movilagent.cpp \
    obstaculo.cpp \
    ofensiveunit.cpp \
    pheromonedepositor.cpp \
    pheromoneitem.cpp \
    pheromonesensor.cpp \
    regla.cpp \
    sensor.cpp \
    sensordistancia.cpp \
    shootingunit.cpp \
    shootingweapon.cpp \
    unit.cpp \
    weapon.cpp

HEADERS += \
    actuador.h \
    actuadormovimiento.h \
    addagentsdialog.h \
    agent.h \
    defineruledialog.h \
    ECFunctions.h \
    meleeunit.h \
    movilagent.h \
    obstaculo.h \
    ofensiveunit.h \
    pheromonedepositor.h \
    pheromoneitem.h \
    pheromonesensor.h \
    regla.h \
    sensor.h \
    sensordistancia.h \
    shootingunit.h \
    shootingweapon.h \
    unit.h \
    weapon.h \
    share_ec_gui.h

FORMS += \
    addagentsdialog.ui \
    defineruledialog.ui



win32:{
	CONFIG += windows c++11

    CONFIG(release, debug|release):{
		message("Building release binaries for ec_gui module");

		TARGET = ec_gui

		QMAKE_CXXFLAGS += /MD

		LIBS += -L$$DESTDIR -lcore

	}else:{#DEBUG

		message("Building debug binaries for ec_gui module");

		TARGET = ec_gui_debug

		QMAKE_CXXFLAGS += /MDd

		LIBS += -L$$DESTDIR -lcore_debug

    }
#   if x86_64
	contains(QMAKE_TARGET.arch, x86_64): {
		QMAKE_LFLAGS += /MACHINE:X64
	}
}

unix:CONFIG(release, debug|release){

    QMAKE_CXXFLAGS += -std=c++11 -O3

    TARGET = ec_gui

    LIBS += -L$$DESTDIR -lcore

    lib.path = $$PWD/../../custom_libs/insyde/$$TARGET/lib
    lib.files = $$OUT_PWD/../$$join(TARGET,,"lib").*

    includes.path = $$PWD/../../custom_libs/insyde/$$TARGET/include
    includes.files = $$PWD/*.h
    INSTALLS += lib includes

    message("Building $$TARGET binaries in release mode")
}

unix:CONFIG(debug, debug|release){

    QMAKE_CXXFLAGS += -std=c++11
    TARGET = ec_gui_debug

    LIBS += -L$$DESTDIR -lcore_debug

    message("Building $$TARGET binaries in debug mode")

}

