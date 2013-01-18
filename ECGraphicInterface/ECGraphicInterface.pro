#-------------------------------------------------
#
# Project created by QtCreator 2013-01-17T16:41:46
#
#-------------------------------------------------

QT       += opengl

TARGET = ECGraphicInterface
TEMPLATE = lib

DEFINES += ECGRAPHICINTERFACE_LIBRARY

debug{EXTRA = debug}
release{EXTRA = release}
DESTDIR = ../$$EXTRA

debug:LIBS += -L"../debug"
release:LIBS += -L"../release"
LIBS += -lINSYDECommon

INCLUDEPATH += .

SOURCES += \
	weapon.cpp \
	unidad.cpp \
	shootingweapon.cpp \
	shootingunit.cpp \
	sensordistancia.cpp \
	sensor.cpp \
	regla.cpp \
	pheromonesensor.cpp \
	pheromoneitem.cpp \
	pheromonedepositor.cpp \
	ofensiveunit.cpp \
	obstaculo.cpp \
	movilagent.cpp \
	meleeunit.cpp \
	defineruledialog.cpp \
	apuntador.cpp \
	agent.cpp \
	addagentsdialog.cpp \
	actuadormovimiento.cpp \
	actuador.cpp \
	ECFunctions.cpp

HEADERS +=\
		ECGraphicInterface_global.h \
	weapon.h \
	unidad.h \
	shootingweapon.h \
	shootingunit.h \
	sensordistancia.h \
	sensor.h \
	regla.h \
	pheromonesensor.h \
	pheromoneitem.h \
	pheromonedepositor.h \
	ofensiveunit.h \
	obstaculo.h \
	movilagent.h \
	meleeunit.h \
	ECGraphicInterface_global.h \
	defineruledialog.h \
	apuntador.h \
	agent.h \
	addagentsdialog.h \
	actuadormovimiento.h \
	actuador.h \
	ECFunctions.h

#unix:!symbian {
#    maemo5 {
#        target.path = /opt/usr/lib
#    } else {
#        target.path = /usr/lib
#    }
#    INSTALLS += target
#}

FORMS += \
	defineruledialog.ui \
	addagentsdialog.ui
