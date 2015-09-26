
QT += opengl

CONFIG += qt shared

CONFIG(release, debug|release):message("Staring RELEASE build for ec_gui sources") #will print
CONFIG(debug, debug|release):message("Staring DEBUG build for ec_gui sources") #no print

TARGET = ec_gui

TEMPLATE = lib

MOC_DIR = moc
UI_DIR = ui
OBJECTS_DIR = obj
RCC_DIR = res
DESTDIR = ..

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
    weapon.h

FORMS += \
    addagentsdialog.ui \
    defineruledialog.ui


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../external/tbb42_20140416oss/lib/intel64/gcc4.4/release/ -ltbb
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../external/tbb42_20140416oss/lib/intel64/gcc4.4/debug/ -ltbb
else:unix: LIBS += -L$$PWD/../external/tbb42_20140416oss/lib/intel64/gcc4.4/ -ltbb

INCLUDEPATH += $$PWD/../external/tbb42_20140416oss/include
DEPENDPATH += $$PWD/../external/tbb42_20140416oss/include

