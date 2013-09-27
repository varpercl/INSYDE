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



INCLUDEPATH += . INSYDECommon ECGraphicInterface ANNFramework

DEFINES += WINDOW_WIDTH=13 \
WINDOW_HEIGH=31 \
WINDOW_STEP=1


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
LIBS += -lANNFramework \
	-lINSYDECommon \
	-lECGraphicInterface \
	-lECFramework

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
	mlptrainingdialog.cpp \
	mapa.cpp \
	mainwindow.cpp \
	main.cpp \
	graphicmlpelement.cpp \
	graphicelement.cpp \
	dotmatrix.cpp \
	chooseprojectnamepage.cpp \
	binaryoutputelement.cpp \
	adalinepage.cpp \
    addnewmlpdialog.cpp \
    adddotmatrixdialog.cpp \
    graphicimageelement.cpp \
    graphicimageelementpropertydialog.cpp \
    dotmatrixelementpropertydialog.cpp \
    graphicmlpelementpropertydialog.cpp \
    graphicelementdetailedwindow.cpp \
    graphicimageelementdetailedwindow.cpp \
    graphicimageeffectelement.cpp \
    graphicimageeffectelementpropertydialog.cpp \
    bnsubwidget.cpp \
    blackwhiteeffect.cpp \
    effect.cpp \
    grayscaleeffect.cpp \
    gssubwidget.cpp \
    graphiccursorelement.cpp

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
	mlptrainingdialog.h \
	mapa.h \
	mainwindow.h \
	letterdeclarations.h \
	graphicmlpelement.h \
	graphicelement.h \
	dotmatrix.h \
	chooseprojectnamepage.h \
	binaryoutputelement.h \
	adalinepage.h \
    addnewmlpdialog.h \
    adddotmatrixdialog.h \
    graphicimageelement.h \
    graphicimageelementpropertydialog.h \
    dotmatrixelementpropertydialog.h \
    graphicmlpelementpropertydialog.h \
    graphicelementdetailedwindow.h \
    graphicimageelementdetailedwindow.h \
    graphicimageeffectelement.h \
    graphicimageeffectelementpropertydialog.h \
    bnsubwidget.h \
    blackwhiteeffect.h \
    effect.h \
    grayscaleeffect.h \
    gssubwidget.h \
    graphiccursorelement.h

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
    addnewmlpdialog.ui \
    adddotmatrixdialog.ui \
    graphicimageelementpropertydialog.ui \
    dotmatrixelementpropertydialog.ui \
    graphicmlpelementpropertydialog.ui \
    graphicelementdetailedwindow.ui \
    graphicimageeffectelementpropertydialog.ui \
    bnsubwidget.ui \
    gssubwidget.ui

RESOURCES += \
	imagenes.qrc
