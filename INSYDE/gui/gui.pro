
message("Compiling gui sources")

QT += widgets xml opengl

CONFIG += qt c++11

TEMPLATE = app

TARGET = INSYDE

DEFINES += \
WINDOW_HEIGH=31 \
WINDOW_WIDTH=13 \
WINDOW_STEP=1

MOC_DIR = moc
UI_DIR = ui
OBJECTS_DIR = obj
RCC_DIR = res
DESTDIR = ..

SOURCES += \
    apuntador.cpp \
    binaryoutputelement.cpp \
    blackwhiteeffect.cpp \
    bnsubwidget.cpp \
    chooseprojectnamepage.cpp \
    effect.cpp \
    graphiccursorelement.cpp \
    graphicimageeffectelement.cpp \
    graphicimageeffectelementpropertydialog.cpp \
    grayscaleeffect.cpp \
    gssubwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    mapa.cpp \
    newprojectwizard.cpp \
    plotterdata.cpp \
    progressplotter.cpp \
    selectimagesegmentdialog.cpp \
    selectprojectpage.cpp \
    statusanimation.cpp \
    vector2d.cpp \
    visor.cpp \
    adddotmatrixdialog.cpp \
    pruebapantallas.cpp

HEADERS += \
    apuntador.h \
    binaryoutputelement.h \
    blackwhiteeffect.h \
    bnsubwidget.h \
    chooseprojectnamepage.h \
    effect.h \
    graphiccursorelement.h \
    grayscaleeffect.h \
    gssubwidget.h \
    mainwindow.h \
    mapa.h \
    newprojectwizard.h \
    plotterdata.h \
    progressplotter.h \
    selectimagesegmentdialog.h \
    selectprojectpage.h \
    statusanimation.h \
    vector2d.h \
    visor.h \
    adddotmatrixdialog.h \
    imageefectpropertydialog.h \
    imageeffect.h \
    pruebapantallas.h

FORMS += \
    adddotmatrixdialog.ui \
    bnsubwidget.ui \
    chooseprojectnamepage.ui \
    graphicimageeffectelementpropertydialog.ui \
    gssubwidget.ui \
    mainwindow.ui \
    newprojectdialog.ui \
    newprojectwizard.ui \
    selectimagesegmentdialog.ui \
    selectprojectpage.ui \
    prueba_pantallas.ui

RESOURCES += \
    various.qrc

LIBS += \
-L.. -lcore \
-L.. -lann_base \
-L.. -lec_gui \
-L.. -lann_gui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../external/tbb42_20140416oss/lib/intel64/gcc4.4/release/ -ltbb
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../external/tbb42_20140416oss/lib/intel64/gcc4.4/debug/ -ltbb
else:unix: LIBS += -L$$PWD/../external/tbb42_20140416oss/lib/intel64/gcc4.4/ -ltbb

INCLUDEPATH += $$PWD/../external/tbb42_20140416oss/include
DEPENDPATH += $$PWD/../external/tbb42_20140416oss/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../external/kdchart-2.5.1-source/lib/release/ -lkdchart
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../external/kdchart-2.5.1-source/lib/debug/ -lkdchart
else:unix: LIBS += -L$$PWD/../external/kdchart-2.5.1-source/lib/ -lkdchart

INCLUDEPATH += $$PWD/../external/kdchart-2.5.1-source/include
DEPENDPATH += $$PWD/../external/kdchart-2.5.1-source/include

DISTFILES +=
