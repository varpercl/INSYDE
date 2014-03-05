#-------------------------------------------------
#
# Project created by QtCreator 2013-01-17T17:15:39
#
#-------------------------------------------------

QT       += gui widgets

TARGET = INSYDEUI
TEMPLATE = lib

DEFINES += INSYDEUI_LIBRARY \
WINDOW_HEIGH=31 \
WINDOW_WIDTH=13 \
WINDOW_STEP=1

#debug:EXTRA = debug
#release:EXTRA = release

#DESTDIR = ../$$EXTRA
#OBJECTS_DIR = $$EXTRA/obj
#MOC_DIR = $$EXTRA/moc
#RCC_DIR = $$EXTRA/rcc
#UI_DIR = $$EXTRA/ui

debug:DESTDIR = "../debug"
release:DESTDIR = "../release"
debug:OBJECTS_DIR = "debug/obj"
release:OBJECTS_DIR = "release/obj"
debug:MOC_DIR = "debug/moc"
release:MOC_DIR = "release/moc"
debug:RCC_DIR = "debug/rcc"
release:RCC_DIR = "release/rcc"
#debug:UI_DIR = "debug/ui"
#release:UI_DIR = "release/ui"
UI_DIR = "ui"

#DESTDIR = ..
#OBJECTS_DIR = obj
#MOC_DIR = moc
#RCC_DIR = rcc
#UI_DIR = ui


debug:LIBS += -L"../debug"
release:LIBS += -L"../release"
LIBS += -lANNFramework \
-lECFramework

INCLUDEPATH +=

SOURCES += \
    visor.cpp \
    vector2d.cpp \
    statusanimation.cpp \
    selectprojectpage.cpp \
    newprojectwizard.cpp \
    mapa.cpp \
    gssubwidget.cpp \
    grayscaleeffect.cpp \
    graphicimageelementpropertydialog.cpp \
    graphicimageelementdetailedwindow.cpp \
    graphicimageelement.cpp \
    graphicimageeffectelementpropertydialog.cpp \
    graphicimageeffectelement.cpp \
    graphicelementdetailedwindow.cpp \
    graphicelement.cpp \
    graphiccursorelement.cpp \
    effect.cpp \
    dotmatrixelementpropertydialog.cpp \
    dotmatrix.cpp \
    chooseprojectnamepage.cpp \
    bnsubwidget.cpp \
    blackwhiteeffect.cpp \
    binaryoutputelement.cpp \
    adddotmatrixdialog.cpp \
    apuntador.cpp \
    ANNGraphicInterface/trainingsetdialog.cpp \
    ANNGraphicInterface/samplesdialog.cpp \
    ANNGraphicInterface/perceptronpage.cpp \
    ANNGraphicInterface/perceptrondisplay.cpp \
    ANNGraphicInterface/mlptrainingdialog.cpp \
    ANNGraphicInterface/graphicmlpelementpropertydialog.cpp \
    ANNGraphicInterface/graphicmlpelement.cpp \
    ANNGraphicInterface/anngraphicinterface.cpp \
    ANNGraphicInterface/addnewmlpdialog.cpp \
    ANNGraphicInterface/adalinepage.cpp \
    ANNGraphicInterface/frmweightseditor.cpp \
    ANNGraphicInterface/weightline.cpp \
    ECGraphicInterface/weapon.cpp \
    ECGraphicInterface/shootingweapon.cpp \
    ECGraphicInterface/shootingunit.cpp \
    ECGraphicInterface/sensordistancia.cpp \
    ECGraphicInterface/sensor.cpp \
    ECGraphicInterface/regla.cpp \
    ECGraphicInterface/pheromonesensor.cpp \
    ECGraphicInterface/pheromoneitem.cpp \
    ECGraphicInterface/pheromonedepositor.cpp \
    ECGraphicInterface/ofensiveunit.cpp \
    ECGraphicInterface/obstaculo.cpp \
    ECGraphicInterface/movilagent.cpp \
    ECGraphicInterface/meleeunit.cpp \
    ECGraphicInterface/ECFunctions.cpp \
    ECGraphicInterface/defineruledialog.cpp \
    ECGraphicInterface/agent.cpp \
    ECGraphicInterface/addagentsdialog.cpp \
    ECGraphicInterface/actuadormovimiento.cpp \
    ECGraphicInterface/actuador.cpp \
    ECGraphicInterface/unit.cpp \
    selectimagesegmentdialog.cpp \
    pixmapitem.cpp \
    ANNGraphicInterface/imagerepresentationwidget.cpp \
    ANNGraphicInterface/representationwidget.cpp \
    ANNGraphicInterface/datarepresentationbox.cpp \
    INSYDEUI_global.cpp \
    ANNGraphicInterface/normalizationwidget.cpp \
    minmaxvaluewidget.cpp \
    labeledspinboxwidget.cpp \
    ANNGraphicInterface/trainingsettable.cpp \
    integersizewidget.cpp

HEADERS += INSYDEUI_global.h \
    visor.h \
    vector2d.h \
    statusanimation.h \
    selectprojectpage.h \
    newprojectwizard.h \
    mapa.h \
    gssubwidget.h \
    grayscaleeffect.h \
    graphicimageelementpropertydialog.h \
    graphicimageelementdetailedwindow.h \
    graphicimageelement.h \
    graphicimageeffectelementpropertydialog.h \
    graphicimageeffectelement.h \
    graphicelementdetailedwindow.h \
    graphicelement.h \
    graphiccursorelement.h \
    effect.h \
    dotmatrixelementpropertydialog.h \
    dotmatrix.h \
    chooseprojectnamepage.h \
    bnsubwidget.h \
    blackwhiteeffect.h \
    binaryoutputelement.h \
    adddotmatrixdialog.h \
    apuntador.h \
    ANNGraphicInterface/trainingsetdialog.h \
    ANNGraphicInterface/samplesdialog.h \
    ANNGraphicInterface/perceptronpage.h \
    ANNGraphicInterface/perceptrondisplay.h \
    ANNGraphicInterface/mlptrainingdialog.h \
    ANNGraphicInterface/graphicmlpelementpropertydialog.h \
    ANNGraphicInterface/graphicmlpelement.h \
    ANNGraphicInterface/anngraphicinterface.h \
    ANNGraphicInterface/addnewmlpdialog.h \
    ANNGraphicInterface/adalinepage.h \
    ANNGraphicInterface/frmweightseditor.h \
    ECGraphicInterface/weapon.h \
    ECGraphicInterface/shootingweapon.h \
    ECGraphicInterface/shootingunit.h \
    ECGraphicInterface/sensordistancia.h \
    ECGraphicInterface/sensor.h \
    ECGraphicInterface/regla.h \
    ECGraphicInterface/pheromonesensor.h \
    ECGraphicInterface/pheromoneitem.h \
    ECGraphicInterface/pheromonedepositor.h \
    ECGraphicInterface/ofensiveunit.h \
    ECGraphicInterface/obstaculo.h \
    ECGraphicInterface/movilagent.h \
    ECGraphicInterface/meleeunit.h \
    ECGraphicInterface/ECFunctions.h \
    ECGraphicInterface/defineruledialog.h \
    ECGraphicInterface/agent.h \
    ECGraphicInterface/addagentsdialog.h \
    ECGraphicInterface/actuadormovimiento.h \
    ECGraphicInterface/actuador.h \
    ECGraphicInterface/unit.h \
    ANNGraphicInterface/weightline.h \
    selectimagesegmentdialog.h \
    pixmapitem.h \
    ANNGraphicInterface/imagerepresentationwidget.h \
    ANNGraphicInterface/representationwidget.h \
    ANNGraphicInterface/datarepresentationbox.h \
    ANNGraphicInterface/normalizationwidget.h \
    minmaxvaluewidget.h \
    labeledspinboxwidget.h \
    ANNGraphicInterface/trainingsettable.h \
    integersizewidget.h

#unix:!symbian {
#    maemo5 {
#        target.path = /opt/usr/lib
#    } else {
#        target.path = /usr/lib
#    }
#    INSTALLS += target
#}

FORMS += \
    newprojectwizard.ui \
    selectprojectpage.ui \
    gssubwidget.ui \
    graphicimageelementpropertydialog.ui \
    graphicimageeffectelementpropertydialog.ui \
    graphicelementdetailedwindow.ui \
    dotmatrixelementpropertydialog.ui \
    chooseprojectnamepage.ui \
    bnsubwidget.ui \
    adddotmatrixdialog.ui \
    ANNGraphicInterface/trainingsetdialog.ui \
    ANNGraphicInterface/samplesdialog.ui \
    ANNGraphicInterface/perceptronpage.ui \
    ANNGraphicInterface/mlptrainingdialog.ui \
    ANNGraphicInterface/graphicmlpelementpropertydialog.ui \
    ANNGraphicInterface/addnewmlpdialog.ui \
    ANNGraphicInterface/adalinepage.ui \
    ANNGraphicInterface/frmweightseditor.ui \
    ANNGraphicInterface/gbgraphicrepresentation.ui \
    ECGraphicInterface/defineruledialog.ui \
    ECGraphicInterface/addagentsdialog.ui \
    selectimagesegmentdialog.ui \
    ANNGraphicInterface/imagerepresentationwidget.ui \
    ANNGraphicInterface/normalizationwidget.ui \
    minmaxvaluewidget.ui \
    labeledspinboxwidget.ui \
    integersizewidget.ui

RESOURCES += \
    imagenes.qrc \
    ANNGraphicInterface/images.qrc
