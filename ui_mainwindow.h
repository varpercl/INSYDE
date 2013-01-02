/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 2. Jan 16:22:08 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QToolBox>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNativo;
    QAction *actionOpenGL;
    QAction *actionSalir;
    QAction *actionOpciones;
    QAction *actionProyecto;
    QAction *actionModelo;
    QAction *actionNuevo_proyecto;
    QAction *actionAbrir;
    QAction *action10_pixeles;
    QAction *action20;
    QAction *action50_pixeles;
    QAction *actionPersonalizar;
    QAction *actionDeshacer;
    QAction *actionRehacer;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QTabWidget *mainTab;
    QWidget *tab;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *mainSystemLayout;
    QMenuBar *menuBar;
    QMenu *menuHerramientas;
    QMenu *menuModo_grafico;
    QMenu *menuArchivo;
    QMenu *menuVentanas;
    QMenu *menuVista;
    QMenu *menuGrilla;
    QMenu *menuEdicion;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *ventanaObjetos;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QTreeWidget *twArbolObjetos;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSearchMode;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_5;
    QVBoxLayout *verticalLayout_5;
    QToolBox *mainToolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QToolButton *btnAddMatrix;
    QToolButton *btnAddImage;
    QToolButton *btnAddRegion;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_2;
    QToolButton *btnAddPerceptron;
    QToolButton *btnAddADALINE;
    QToolButton *btnAddHopfield;
    QToolButton *btnAddMultilayerPerceptron;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_3;
    QToolButton *btnAddAgent;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(784, 448);
        actionNativo = new QAction(MainWindow);
        actionNativo->setObjectName(QString::fromUtf8("actionNativo"));
        actionNativo->setCheckable(true);
        actionOpenGL = new QAction(MainWindow);
        actionOpenGL->setObjectName(QString::fromUtf8("actionOpenGL"));
        actionOpenGL->setCheckable(true);
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        actionOpciones = new QAction(MainWindow);
        actionOpciones->setObjectName(QString::fromUtf8("actionOpciones"));
        actionProyecto = new QAction(MainWindow);
        actionProyecto->setObjectName(QString::fromUtf8("actionProyecto"));
        actionProyecto->setCheckable(true);
        actionProyecto->setChecked(false);
        actionModelo = new QAction(MainWindow);
        actionModelo->setObjectName(QString::fromUtf8("actionModelo"));
        actionModelo->setCheckable(true);
        actionNuevo_proyecto = new QAction(MainWindow);
        actionNuevo_proyecto->setObjectName(QString::fromUtf8("actionNuevo_proyecto"));
        actionAbrir = new QAction(MainWindow);
        actionAbrir->setObjectName(QString::fromUtf8("actionAbrir"));
        action10_pixeles = new QAction(MainWindow);
        action10_pixeles->setObjectName(QString::fromUtf8("action10_pixeles"));
        action20 = new QAction(MainWindow);
        action20->setObjectName(QString::fromUtf8("action20"));
        action50_pixeles = new QAction(MainWindow);
        action50_pixeles->setObjectName(QString::fromUtf8("action50_pixeles"));
        actionPersonalizar = new QAction(MainWindow);
        actionPersonalizar->setObjectName(QString::fromUtf8("actionPersonalizar"));
        actionDeshacer = new QAction(MainWindow);
        actionDeshacer->setObjectName(QString::fromUtf8("actionDeshacer"));
        actionRehacer = new QAction(MainWindow);
        actionRehacer->setObjectName(QString::fromUtf8("actionRehacer"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        mainTab = new QTabWidget(centralWidget);
        mainTab->setObjectName(QString::fromUtf8("mainTab"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_6 = new QVBoxLayout(tab);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        mainSystemLayout = new QVBoxLayout();
        mainSystemLayout->setSpacing(6);
        mainSystemLayout->setObjectName(QString::fromUtf8("mainSystemLayout"));

        verticalLayout_6->addLayout(mainSystemLayout);

        mainTab->addTab(tab, QString());

        horizontalLayout_3->addWidget(mainTab);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 784, 21));
        menuHerramientas = new QMenu(menuBar);
        menuHerramientas->setObjectName(QString::fromUtf8("menuHerramientas"));
        menuModo_grafico = new QMenu(menuHerramientas);
        menuModo_grafico->setObjectName(QString::fromUtf8("menuModo_grafico"));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        menuVentanas = new QMenu(menuBar);
        menuVentanas->setObjectName(QString::fromUtf8("menuVentanas"));
        menuVista = new QMenu(menuBar);
        menuVista->setObjectName(QString::fromUtf8("menuVista"));
        menuGrilla = new QMenu(menuVista);
        menuGrilla->setObjectName(QString::fromUtf8("menuGrilla"));
        menuEdicion = new QMenu(menuBar);
        menuEdicion->setObjectName(QString::fromUtf8("menuEdicion"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        ventanaObjetos = new QDockWidget(MainWindow);
        ventanaObjetos->setObjectName(QString::fromUtf8("ventanaObjetos"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        twArbolObjetos = new QTreeWidget(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        twArbolObjetos->setHeaderItem(__qtreewidgetitem);
        twArbolObjetos->setObjectName(QString::fromUtf8("twArbolObjetos"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(twArbolObjetos->sizePolicy().hasHeightForWidth());
        twArbolObjetos->setSizePolicy(sizePolicy);
        twArbolObjetos->header()->setVisible(false);

        verticalLayout->addWidget(twArbolObjetos);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnSearchMode = new QPushButton(dockWidgetContents);
        btnSearchMode->setObjectName(QString::fromUtf8("btnSearchMode"));

        horizontalLayout->addWidget(btnSearchMode);

        pushButton_2 = new QPushButton(dockWidgetContents);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(dockWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        ventanaObjetos->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), ventanaObjetos);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        dockWidget_2->setFloating(false);
        dockWidget_2->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QString::fromUtf8("dockWidgetContents_5"));
        verticalLayout_5 = new QVBoxLayout(dockWidgetContents_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(2, 2, 2, 2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        mainToolBox = new QToolBox(dockWidgetContents_5);
        mainToolBox->setObjectName(QString::fromUtf8("mainToolBox"));
        mainToolBox->setMaximumSize(QSize(16777215, 16777215));
        mainToolBox->setFrameShape(QFrame::NoFrame);
        mainToolBox->setFrameShadow(QFrame::Plain);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 135, 108));
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        btnAddMatrix = new QToolButton(page);
        btnAddMatrix->setObjectName(QString::fromUtf8("btnAddMatrix"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/matriz.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddMatrix->setIcon(icon);
        btnAddMatrix->setIconSize(QSize(20, 20));
        btnAddMatrix->setCheckable(true);
        btnAddMatrix->setAutoExclusive(false);
        btnAddMatrix->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btnAddMatrix->setAutoRaise(true);

        verticalLayout_4->addWidget(btnAddMatrix);

        btnAddImage = new QToolButton(page);
        btnAddImage->setObjectName(QString::fromUtf8("btnAddImage"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagenes/manzana-verde-thumb7707762.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddImage->setIcon(icon1);
        btnAddImage->setIconSize(QSize(20, 20));
        btnAddImage->setCheckable(true);
        btnAddImage->setAutoExclusive(false);
        btnAddImage->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btnAddImage->setAutoRaise(true);

        verticalLayout_4->addWidget(btnAddImage);

        btnAddRegion = new QToolButton(page);
        btnAddRegion->setObjectName(QString::fromUtf8("btnAddRegion"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imagenes/conjuntos.gif"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddRegion->setIcon(icon2);
        btnAddRegion->setIconSize(QSize(20, 20));
        btnAddRegion->setCheckable(true);
        btnAddRegion->setAutoExclusive(false);
        btnAddRegion->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btnAddRegion->setAutoRaise(true);

        verticalLayout_4->addWidget(btnAddRegion);

        mainToolBox->addItem(page, QString::fromUtf8("General"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 156, 140));
        verticalLayout_2 = new QVBoxLayout(page_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btnAddPerceptron = new QToolButton(page_3);
        btnAddPerceptron->setObjectName(QString::fromUtf8("btnAddPerceptron"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imagenes/perceptron2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddPerceptron->setIcon(icon3);
        btnAddPerceptron->setIconSize(QSize(20, 20));
        btnAddPerceptron->setCheckable(false);
        btnAddPerceptron->setAutoExclusive(false);
        btnAddPerceptron->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btnAddPerceptron->setAutoRaise(true);

        verticalLayout_2->addWidget(btnAddPerceptron);

        btnAddADALINE = new QToolButton(page_3);
        btnAddADALINE->setObjectName(QString::fromUtf8("btnAddADALINE"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imagenes/adaline.gif"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddADALINE->setIcon(icon4);
        btnAddADALINE->setIconSize(QSize(20, 20));
        btnAddADALINE->setCheckable(true);
        btnAddADALINE->setAutoExclusive(false);
        btnAddADALINE->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btnAddADALINE->setAutoRaise(true);

        verticalLayout_2->addWidget(btnAddADALINE);

        btnAddHopfield = new QToolButton(page_3);
        btnAddHopfield->setObjectName(QString::fromUtf8("btnAddHopfield"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/imagenes/hopfield.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddHopfield->setIcon(icon5);
        btnAddHopfield->setIconSize(QSize(20, 20));
        btnAddHopfield->setCheckable(true);
        btnAddHopfield->setAutoExclusive(false);
        btnAddHopfield->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btnAddHopfield->setAutoRaise(true);

        verticalLayout_2->addWidget(btnAddHopfield);

        btnAddMultilayerPerceptron = new QToolButton(page_3);
        btnAddMultilayerPerceptron->setObjectName(QString::fromUtf8("btnAddMultilayerPerceptron"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/imagenes/artificial neural network.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddMultilayerPerceptron->setIcon(icon6);
        btnAddMultilayerPerceptron->setIconSize(QSize(20, 20));
        btnAddMultilayerPerceptron->setCheckable(true);
        btnAddMultilayerPerceptron->setAutoExclusive(false);
        btnAddMultilayerPerceptron->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btnAddMultilayerPerceptron->setAutoRaise(true);

        verticalLayout_2->addWidget(btnAddMultilayerPerceptron);

        mainToolBox->addItem(page_3, QString::fromUtf8("Redes neuronales artificiales"));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 145, 288));
        verticalLayout_3 = new QVBoxLayout(page_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        btnAddAgent = new QToolButton(page_4);
        btnAddAgent->setObjectName(QString::fromUtf8("btnAddAgent"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/imagenes/Agent_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddAgent->setIcon(icon7);
        btnAddAgent->setIconSize(QSize(20, 20));
        btnAddAgent->setCheckable(false);
        btnAddAgent->setAutoRepeat(false);
        btnAddAgent->setAutoExclusive(false);
        btnAddAgent->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btnAddAgent->setAutoRaise(true);

        verticalLayout_3->addWidget(btnAddAgent);

        mainToolBox->addItem(page_4, QString::fromUtf8("Sistemas multiagentes"));

        verticalLayout_5->addWidget(mainToolBox);

        dockWidget_2->setWidget(dockWidgetContents_5);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_2);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuEdicion->menuAction());
        menuBar->addAction(menuVista->menuAction());
        menuBar->addAction(menuHerramientas->menuAction());
        menuBar->addAction(menuVentanas->menuAction());
        menuHerramientas->addAction(menuModo_grafico->menuAction());
        menuHerramientas->addAction(actionOpciones);
        menuModo_grafico->addAction(actionNativo);
        menuModo_grafico->addAction(actionOpenGL);
        menuArchivo->addAction(actionNuevo_proyecto);
        menuArchivo->addAction(actionAbrir);
        menuArchivo->addAction(actionSalir);
        menuVentanas->addAction(actionProyecto);
        menuVentanas->addAction(actionModelo);
        menuVista->addAction(menuGrilla->menuAction());
        menuGrilla->addAction(action10_pixeles);
        menuGrilla->addAction(action20);
        menuGrilla->addAction(action50_pixeles);
        menuGrilla->addAction(actionPersonalizar);
        menuEdicion->addAction(actionDeshacer);
        menuEdicion->addAction(actionRehacer);

        retranslateUi(MainWindow);
        QObject::connect(actionSalir, SIGNAL(triggered()), MainWindow, SLOT(menuSalirClick()));
        QObject::connect(actionNativo, SIGNAL(triggered()), MainWindow, SLOT(menuNativoClick()));
        QObject::connect(actionOpenGL, SIGNAL(triggered()), MainWindow, SLOT(menuOpenGLClick()));
        QObject::connect(actionNuevo_proyecto, SIGNAL(triggered(bool)), MainWindow, SLOT(onNewProyectTriggered(bool)));

        mainTab->setCurrentIndex(0);
        mainToolBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNativo->setText(QApplication::translate("MainWindow", "Nativo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNativo->setToolTip(QApplication::translate("MainWindow", "Activa el modo grafico nativo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOpenGL->setText(QApplication::translate("MainWindow", "OpenGL", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpenGL->setToolTip(QApplication::translate("MainWindow", "Activa el modo grafico OpenGL para renderizacion avanzada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", 0, QApplication::UnicodeUTF8));
        actionSalir->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionOpciones->setText(QApplication::translate("MainWindow", "Opciones", 0, QApplication::UnicodeUTF8));
        actionProyecto->setText(QApplication::translate("MainWindow", "Proyecto", 0, QApplication::UnicodeUTF8));
        actionModelo->setText(QApplication::translate("MainWindow", "Objetos", 0, QApplication::UnicodeUTF8));
        actionNuevo_proyecto->setText(QApplication::translate("MainWindow", "Nuevo proyecto...", 0, QApplication::UnicodeUTF8));
        actionNuevo_proyecto->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionAbrir->setText(QApplication::translate("MainWindow", "Abrir...", 0, QApplication::UnicodeUTF8));
        actionAbrir->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        action10_pixeles->setText(QApplication::translate("MainWindow", "10 pixeles", 0, QApplication::UnicodeUTF8));
        action20->setText(QApplication::translate("MainWindow", "20 pixeles", 0, QApplication::UnicodeUTF8));
        action50_pixeles->setText(QApplication::translate("MainWindow", "50 pixeles", 0, QApplication::UnicodeUTF8));
        actionPersonalizar->setText(QApplication::translate("MainWindow", "Personalizar...", 0, QApplication::UnicodeUTF8));
        actionDeshacer->setText(QApplication::translate("MainWindow", "Deshacer", 0, QApplication::UnicodeUTF8));
        actionRehacer->setText(QApplication::translate("MainWindow", "Rehacer", 0, QApplication::UnicodeUTF8));
        mainTab->setTabText(mainTab->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0, QApplication::UnicodeUTF8));
        menuHerramientas->setTitle(QApplication::translate("MainWindow", "Herramientas", 0, QApplication::UnicodeUTF8));
        menuModo_grafico->setTitle(QApplication::translate("MainWindow", "Modo grafico", 0, QApplication::UnicodeUTF8));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0, QApplication::UnicodeUTF8));
        menuVentanas->setTitle(QApplication::translate("MainWindow", "Ventanas", 0, QApplication::UnicodeUTF8));
        menuVista->setTitle(QApplication::translate("MainWindow", "Vista", 0, QApplication::UnicodeUTF8));
        menuGrilla->setTitle(QApplication::translate("MainWindow", "Grilla", 0, QApplication::UnicodeUTF8));
        menuEdicion->setTitle(QApplication::translate("MainWindow", "Edici\303\263n", 0, QApplication::UnicodeUTF8));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "Principal", 0, QApplication::UnicodeUTF8));
        ventanaObjetos->setWindowTitle(QApplication::translate("MainWindow", "Explorador", 0, QApplication::UnicodeUTF8));
        btnSearchMode->setText(QApplication::translate("MainWindow", "Explorar", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        dockWidget_2->setWindowTitle(QApplication::translate("MainWindow", "Objetos", 0, QApplication::UnicodeUTF8));
        btnAddMatrix->setText(QApplication::translate("MainWindow", "Matriz de puntos", 0, QApplication::UnicodeUTF8));
        btnAddImage->setText(QApplication::translate("MainWindow", "Imagen", 0, QApplication::UnicodeUTF8));
        btnAddRegion->setText(QApplication::translate("MainWindow", "Regiones", 0, QApplication::UnicodeUTF8));
        mainToolBox->setItemText(mainToolBox->indexOf(page), QApplication::translate("MainWindow", "General", 0, QApplication::UnicodeUTF8));
        btnAddPerceptron->setText(QApplication::translate("MainWindow", "Perceptron simple", 0, QApplication::UnicodeUTF8));
        btnAddADALINE->setText(QApplication::translate("MainWindow", "Adaline", 0, QApplication::UnicodeUTF8));
        btnAddHopfield->setText(QApplication::translate("MainWindow", "Hopfield", 0, QApplication::UnicodeUTF8));
        btnAddMultilayerPerceptron->setText(QApplication::translate("MainWindow", "Perceptron multicapa", 0, QApplication::UnicodeUTF8));
        mainToolBox->setItemText(mainToolBox->indexOf(page_3), QApplication::translate("MainWindow", "Redes neuronales artificiales", 0, QApplication::UnicodeUTF8));
        btnAddAgent->setText(QApplication::translate("MainWindow", "Agente", 0, QApplication::UnicodeUTF8));
        mainToolBox->setItemText(mainToolBox->indexOf(page_4), QApplication::translate("MainWindow", "Sistemas multiagentes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
