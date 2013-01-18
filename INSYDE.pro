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


debug:LIBS += -L"debug"
release:LIBS += -L"release"
LIBS += -lANNFramework
LIBS += -lINSYDECommon
LIBS += -lECGraphicInterface
LIBS += -lECFramework

INCLUDEPATH += INSYDECommon ECGraphicInterface


SOURCES += \
	visor.cpp \
	trainingsetdialog.cpp \
	statusanimation.cpp \
	selectprojectpage.cpp \
	samplesdialog.cpp \
	pruebapantallas.cpp \
	perceptronpage.cpp \
	perceptrondisplay.cpp \
	newprojectwizard.cpp \
	mlptrainingthread.cpp \
	mlptrainingdialog.cpp \
	mapa.cpp \
	mainwindow.cpp \
	main.cpp \
	graphicmlpelement.cpp \
	graphicelement.cpp \
	dotmatrix.cpp \
	chooseprojectnamepage.cpp \
	binaryoutputelement.cpp \
	adalinepage.cpp

HEADERS  += \
	visor.h \
	trainingsetdialog.h \
	statusanimation.h \
	selectprojectpage.h \
	samplesdialog.h \
	pruebapantallas.h \
	perceptronpage.h \
	perceptrondisplay.h \
	newprojectwizard.h \
	mlptrainingthread.h \
	mlptrainingdialog.h \
	mapa.h \
	mainwindow.h \
	letterdeclarations.h \
	InSyDeGui.h \
	InSyDeCore.h \
	graphicmlpelement.h \
	graphicelement.h \
	dotmatrix.h \
	chooseprojectnamepage.h \
	binaryoutputelement.h \
	adalinepage.h

FORMS    += mainwindow.ui \
	selectprojectpage.ui \
	chooseprojectnamepage.ui \
	trainingsetdialog.ui \
	prueba_pantallas.ui \
	perceptronpage.ui \
	newprojectwizard.ui \
	adalinepage.ui \
	mlptrainingdialog.ui \
	samplesdialog.ui \
	newprojectdialog.ui \

RESOURCES += \
	imagenes.qrc
