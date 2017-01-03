
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

DEFINES += \
EXPORT_EC_GUI_LIB

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



win32&!win-g++{
#	QMAKE_LFLAGS += /MACHINE:X64

    CONFIG(release, debug|release):{
		TARGET = ec_gui

		LIBS += -L$$PWD/../external/tbb44_20160128oss_win_0/lib/intel64/vc14/ -ltbb \
				-L$$PWD/../external/kdchart-2.5.1-source-win/lib/ -lkdchart2 \
				-L$$DESTDIR -lcore \
	}else
	{#DEBUG

		message("Building debug binaries for ec_gui module");

		TARGET = ec_gui_debug

		QMAKE_CXXFLAGS += /MDd

#       if x86
		contains(QMAKE_TARGET.arch, x86): {
			message("ec_gui module platform is x86");

			LIBS += -L$$PWD/../external/tbb44_20160128oss_win_0/lib/ia32/vc14/ -ltbb_debug \
					-L$$PWD/../external/kdchart-2.5.1-source-win/lib/x86/ -lkdchartd2 \
					-L$$DESTDIR -lcore_debug \
		}

#       if x64
		contains(QMAKE_TARGET.arch, x86_64): {

			message("ec_gui module platform is x86_64");

			QMAKE_LFLAGS += /MACHINE:X64

			LIBS += -L$$PWD/../external/tbb44_20160128oss_win_0/lib/intel64/vc14/ -ltbb_debug \
					-L$$PWD/../external/kdchart-2.5.1-source-win/lib/x64/ -lkdchartd2 \
					-L$$DESTDIR -lcore_debug \
		}


    }

    INCLUDEPATH += $$PWD/../external/kdchart-2.5.1-source-win/include
    DEPENDPATH += $$PWD/../external/kdchart-2.5.1-source-win/include

    INCLUDEPATH += $$PWD/../external/tbb44_20160128oss_win_0/include
    DEPENDPATH += $$PWD/../external/tbb44_20160128oss_win_0/include
}

unix:{

    QMAKE_CXX += -std=c++11

    CONFIG(release, debug|release):{
	QMAKE_CXX += -O3
	LIBS += -L$$PWD/../external/tbb42_20140416oss_lin/bin/intel64/gcc4.4/ -ltbb \
		-L$$PWD/../external/tbb42_20140416oss_lin/lib/intel64/gcc4.4/ -ltbb \
		-L$$PWD/../external/kdchart-2.5.1-source-linux/lib/release/ -lkdchart

	lib.path = $$PWD/../../custom_libs/insyde/$$TARGET/lib
	lib.files = $$OUT_PWD/../$$join(TARGET,,"lib").*

	includes.path = $$PWD/../../custom_libs/insyde/$$TARGET/include
	includes.files = $$PWD/*.h
	INSTALLS += lib includes
    }else{
	LIBS += -L$$PWD/../external/tbb42_20140416oss_lin/bin/intel64/gcc4.4/ -ltbb_debug \
		-L$$PWD/../external/tbb42_20140416oss_lin/lib/intel64/gcc4.4/ -ltbb_debug \
		-L$$PWD/../external/kdchart-2.5.1-source-linux/lib/debug/ -lkdchart
    }

    INCLUDEPATH += $$PWD/../external/kdchart-2.5.1-source-linux/include
    DEPENDPATH += $$PWD/../external/kdchart-2.5.1-source-linux/include


    INCLUDEPATH += $$PWD/../external/tbb42_20140416oss_lin/include
    DEPENDPATH += $$PWD/../external/tbb42_20140416oss_lin/include
}
