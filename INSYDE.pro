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
#    QMAKE_CXXFLAGS += -std=gnu++0x -U__STRICT_ANSI__

#debug:DEPENDPATH += TBAssistant
#release:DEPENDPATH += TBAssistant
#DEPENDPATH += . TBAssistant

#debug:INCLUDEPATH += TBAssistant
#release:INCLUDEPATH += TBAssistant
#INCLUDEPATH += TBAssistant

#debug:LIBS += -L"debug"
#release:LIBS += -L"release"
#LIBS += -lTBAssistant

#INCLUDEPATH +=

debug:LIBS += -L"debug"
release:LIBS += -L"release"
LIBS += -lRNALibrary

SOURCES += main.cpp\
		mainwindow.cpp \
	obstaculo.cpp \
	apuntador.cpp \
	sensor.cpp \
	actuador.cpp \
	sensordistancia.cpp \
	unidad.cpp \
	actuadormovimiento.cpp \
	visor.cpp \
	mapa.cpp \
	regla.cpp \
	vector2d.cpp \
	statusanimation.cpp \
	defineruledialog.cpp \
	agent.cpp \
	movilagent.cpp \
	addagentsdialog.cpp \
	pheromonesensor.cpp \
	pheromonedepositor.cpp \
	pheromoneitem.cpp \
	ofensiveunit.cpp \
	meleeunit.cpp \
	shootingweapon.cpp \
	shootingunit.cpp \
	weapon.cpp \
	general.cpp \
	newprojectwizard.cpp \
	aco.cpp \
	selectprojectpage.cpp \
	chooseprojectnamepage.cpp \
	pruebapantallas.cpp \
	perceptronpage.cpp \
	perceptrondisplay.cpp \
	adalinepage.cpp \
	trainingsetdialog.cpp \
    graphicelement.cpp \
    dotmatrix.cpp \
    graphicmlpelement.cpp \
    mlptrainingdialog.cpp \
    mlptrainingthread.cpp \
    binaryoutputrepresentation.cpp

HEADERS  += mainwindow.h \
	obstaculo.h \
	apuntador.h \
	sensor.h \
	actuador.h \
	sensordistancia.h \
	unidad.h \
	actuadormovimiento.h \
	visor.h \
	mapa.h \
	regla.h \
	vector2d.h \
	statusanimation.h \
	defineruledialog.h \
	agent.h \
	movilagent.h \
	addagentsdialog.h \
	pheromonesensor.h \
	pheromonedepositor.h \
	pheromoneitem.h \
	ofensiveunit.h \
	meleeunit.h \
	shootingweapon.h \
	shootingunit.h \
	weapon.h \
	InSyDeCore.h \
	InSyDeGui.h \
	newprojectwizard.h \
	aco.h \
	selectprojectpage.h \
	chooseprojectnamepage.h \
	pruebapantallas.h \
	perceptronpage.h \
	perceptrondisplay.h \
	adalinepage.h \
	trainingsetdialog.h \
    graphicelement.h \
    dotmatrix.h \
    graphicmlpelement.h \
    insydefunctions.h \
    letterdeclarations.h \
    mlptrainingdialog.h \
    mlptrainingthread.h \
    binaryoutputrepresentation.h

FORMS    += mainwindow.ui \
	defineruledialog.ui \
	addagentsdialog.ui \
	aco.ui \
	selectprojectpage.ui \
	chooseprojectnamepage.ui \
	trainingsetdialog.ui \
	prueba_pantallas.ui \
	perceptronpage.ui \
	newprojectwizard.ui \
	adalinepage.ui \
    mlptrainingdialog.ui

RESOURCES += \
	imagenes.qrc
