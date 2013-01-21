/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 19. Jan 16:02:31 2013
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(784, 448);
        actionNativo = new QAction(MainWindow);
        actionNativo->setObjectName(QStringLiteral("actionNativo"));
        actionNativo->setCheckable(true);
        actionOpenGL = new QAction(MainWindow);
        actionOpenGL->setObjectName(QStringLiteral("actionOpenGL"));
        actionOpenGL->setCheckable(true);
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionOpciones = new QAction(MainWindow);
        actionOpciones->setObjectName(QStringLiteral("actionOpciones"));
        actionProyecto = new QAction(MainWindow);
        actionProyecto->setObjectName(QStringLiteral("actionProyecto"));
        actionProyecto->setCheckable(true);
        actionProyecto->setChecked(false);
        actionModelo = new QAction(MainWindow);
        actionModelo->setObjectName(QStringLiteral("actionModelo"));
        actionModelo->setCheckable(true);
        actionNuevo_proyecto = new QAction(MainWindow);
        actionNuevo_proyecto->setObjectName(QStringLiteral("actionNuevo_proyecto"));
        actionAbrir = new QAction(MainWindow);
        actionAbrir->setObjectName(QStringLiteral("actionAbrir"));
        action10_pixeles = new QAction(MainWindow);
        action10_pixeles->setObjectName(QStringLiteral("action10_pixeles"));
        action20 = new QAction(MainWindow);
        action20->setObjectName(QStringLiteral("action20"));
        action50_pixeles = new QAction(MainWindow);
        action50_pixeles->setObjectName(QStringLiteral("action50_pixeles"));
        actionPersonalizar = new QAction(MainWindow);
        actionPersonalizar->setObjectName(QStringLiteral("actionPersonalizar"));
        actionDeshacer = new QAction(MainWindow);
        actionDeshacer->setObjectName(QStringLiteral("actionDeshacer"));
        actionRehacer = new QAction(MainWindow);
        actionRehacer->setObjectName(QStringLiteral("actionRehacer"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        mainTab = new QTabWidget(centralWidget);
        mainTab->setObjectName(QStringLiteral("mainTab"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_6 = new QVBoxLayout(tab);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        mainSystemLayout = new QVBoxLayout();
        mainSystemLayout->setSpacing(6);
        mainSystemLayout->setObjectName(QStringLiteral("mainSystemLayout"));

        verticalLayout_6->addLayout(mainSystemLayout);

        mainTab->addTab(tab, QString());

        horizontalLayout_3->addWidget(mainTab);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 784, 21));
        menuHerramientas = new QMenu(menuBar);
        menuHerramientas->setObjectName(QStringLiteral("menuHerramientas"));
        menuModo_grafico = new QMenu(menuHerramientas);
        menuModo_grafico->setObjectName(QStringLiteral("menuModo_grafico"));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuVentanas = new QMenu(menuBar);
        menuVentanas->setObjectName(QStringLiteral("menuVentanas"));
        menuVista = new QMenu(menuBar);
        menuVista->setObjectName(QStringLiteral("menuVista"));
        menuGrilla = new QMenu(menuVista);
        menuGrilla->setObjectName(QStringLiteral("menuGrilla"));
        menuEdicion = new QMenu(menuBar);
        menuEdicion->setObjectName(QStringLiteral("menuEdicion"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        ventanaObjetos = new QDockWidget(MainWindow);
        ventanaObjetos->setObjectName(QStringLiteral("ventanaObjetos"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        twArbolObjetos = new QTreeWidget(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        twArbolObjetos->setHeaderItem(__qtreewidgetitem);
        twArbolObjetos->setObjectName(QStringLiteral("twArbolObjetos"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(twArbolObjetos->sizePolicy().hasHeightForWidth());
        twArbolObjetos->setSizePolicy(sizePolicy);
        twArbolObjetos->header()->setVisible(false);

        verticalLayout->addWidget(twArbolObjetos);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnSearchMode = new QPushButton(dockWidgetContents);
        btnSearchMode->setObjectName(QStringLiteral("btnSearchMode"));

        horizontalLayout->addWidget(btnSearchMode);

        pushButton_2 = new QPushButton(dockWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(dockWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        ventanaObjetos->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), ventanaObjetos);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QStringLiteral("dockWidget_2"));
        dockWidget_2->setFloating(false);
        dockWidget_2->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QStringLiteral("dockWidgetContents_5"));
        verticalLayout_5 = new QVBoxLayout(dockWidgetContents_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(2, 2, 2, 2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        mainToolBox = new QToolBox(dockWidgetContents_5);
        mainToolBox->setObjectName(QStringLiteral("mainToolBox"));
        mainToolBox->setMaximumSize(QSize(16777215, 16777215));
        mainToolBox->setFrameShape(QFrame::NoFrame);
        mainToolBox->setFrameShadow(QFrame::Plain);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 135, 108));
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        btnAddMatrix = new QToolButton(page);
        btnAddMatrix->setObjectName(QStringLiteral("btnAddMatrix"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/imagenes/matriz.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddMatrix->setIcon(icon);
        btnAddMatrix->setIconSize(QSize(20, 20));
        btnAddMatrix->setCheckable(true);
        btnAddMatrix->setAutoExclusive(false);
        btnAddMatrix->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btnAddMatrix->setAutoRaise(true);

        verticalLayout_4->addWidget(btnAddMatrix);

        btnAddImage = new QToolButton(page);
        btnAddImage->setObjectName(QStringLiteral("btnAddImage"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imagenes/manzana-verde-thumb7707762.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddImage->setIcon(icon1);
        btnAddImage->setIconSize(QSize(20, 20));
        btnAddImage->setCheckable(true);
        btnAddImage->setAutoExclusive(false);
        btnAddImage->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btnAddImage->setAutoRaise(true);

        verticalLayout_4->addWidget(btnAddImage);

        btnAddRegion = new QToolButton(page);
        btnAddRegion->setObjectName(QStringLiteral("btnAddRegion"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/imagenes/conjuntos.gif"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddRegion->setIcon(icon2);
        btnAddRegion->setIconSize(QSize(20, 20));
        btnAddRegion->setCheckable(true);
        btnAddRegion->setAutoExclusive(false);
        btnAddRegion->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btnAddRegion->setAutoRaise(true);

        verticalLayout_4->addWidget(btnAddRegion);

        mainToolBox->addItem(page, QStringLiteral("General"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 156, 140));
        verticalLayout_2 = new QVBoxLayout(page_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        btnAddPerceptron = new QToolButton(page_3);
        btnAddPerceptron->setObjectName(QStringLiteral("btnAddPerceptron"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/imagenes/perceptron2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddPerceptron->setIcon(icon3);
        btnAddPerceptron->setIconSize(QSize(20, 20));
        btnAddPerceptron->setCheckable(false);
        btnAddPerceptron->setAutoExclusive(false);
        btnAddPerceptron->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btnAddPerceptron->setAutoRaise(true);

        verticalLayout_2->addWidget(btnAddPerceptron);

        btnAddADALINE = new QToolButton(page_3);
        btnAddADALINE->setObjectName(QStringLiteral("btnAddADALINE"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/imagenes/adaline.gif"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddADALINE->setIcon(icon4);
        btnAddADALINE->setIconSize(QSize(20, 20));
        btnAddADALINE->setCheckable(true);
        btnAddADALINE->setAutoExclusive(false);
        btnAddADALINE->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btnAddADALINE->setAutoRaise(true);

        verticalLayout_2->addWidget(btnAddADALINE);

        btnAddHopfield = new QToolButton(page_3);
        btnAddHopfield->setObjectName(QStringLiteral("btnAddHopfield"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/imagenes/hopfield.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddHopfield->setIcon(icon5);
        btnAddHopfield->setIconSize(QSize(20, 20));
        btnAddHopfield->setCheckable(true);
        btnAddHopfield->setAutoExclusive(false);
        btnAddHopfield->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btnAddHopfield->setAutoRaise(true);

        verticalLayout_2->addWidget(btnAddHopfield);

        btnAddMultilayerPerceptron = new QToolButton(page_3);
        btnAddMultilayerPerceptron->setObjectName(QStringLiteral("btnAddMultilayerPerceptron"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/imagenes/artificial neural network.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddMultilayerPerceptron->setIcon(icon6);
        btnAddMultilayerPerceptron->setIconSize(QSize(20, 20));
        btnAddMultilayerPerceptron->setCheckable(true);
        btnAddMultilayerPerceptron->setAutoExclusive(false);
        btnAddMultilayerPerceptron->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btnAddMultilayerPerceptron->setAutoRaise(true);

        verticalLayout_2->addWidget(btnAddMultilayerPerceptron);

        mainToolBox->addItem(page_3, QStringLiteral("Redes neuronales artificiales"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        page_4->setGeometry(QRect(0, 0, 145, 288));
        verticalLayout_3 = new QVBoxLayout(page_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        btnAddAgent = new QToolButton(page_4);
        btnAddAgent->setObjectName(QStringLiteral("btnAddAgent"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/imagenes/Agent_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddAgent->setIcon(icon7);
        btnAddAgent->setIconSize(QSize(20, 20));
        btnAddAgent->setCheckable(false);
        btnAddAgent->setAutoRepeat(false);
        btnAddAgent->setAutoExclusive(false);
        btnAddAgent->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btnAddAgent->setAutoRaise(true);

        verticalLayout_3->addWidget(btnAddAgent);

        mainToolBox->addItem(page_4, QStringLiteral("Sistemas multiagentes"));

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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNativo->setText(QApplication::translate("MainWindow", "Nativo", 0));
#ifndef QT_NO_TOOLTIP
        actionNativo->setToolTip(QApplication::translate("MainWindow", "Activa el modo grafico nativo", 0));
#endif // QT_NO_TOOLTIP
        actionOpenGL->setText(QApplication::translate("MainWindow", "OpenGL", 0));
#ifndef QT_NO_TOOLTIP
        actionOpenGL->setToolTip(QApplication::translate("MainWindow", "Activa el modo grafico OpenGL para renderizacion avanzada", 0));
#endif // QT_NO_TOOLTIP
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", 0));
        actionSalir->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionOpciones->setText(QApplication::translate("MainWindow", "Opciones", 0));
        actionProyecto->setText(QApplication::translate("MainWindow", "Proyecto", 0));
        actionModelo->setText(QApplication::translate("MainWindow", "Objetos", 0));
        actionNuevo_proyecto->setText(QApplication::translate("MainWindow", "Nuevo proyecto...", 0));
        actionNuevo_proyecto->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionAbrir->setText(QApplication::translate("MainWindow", "Abrir...", 0));
        actionAbrir->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0));
        action10_pixeles->setText(QApplication::translate("MainWindow", "10 pixeles", 0));
        action20->setText(QApplication::translate("MainWindow", "20 pixeles", 0));
        action50_pixeles->setText(QApplication::translate("MainWindow", "50 pixeles", 0));
        actionPersonalizar->setText(QApplication::translate("MainWindow", "Personalizar...", 0));
        actionDeshacer->setText(QApplication::translate("MainWindow", "Deshacer", 0));
        actionRehacer->setText(QApplication::translate("MainWindow", "Rehacer", 0));
        mainTab->setTabText(mainTab->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0));
        menuHerramientas->setTitle(QApplication::translate("MainWindow", "Herramientas", 0));
        menuModo_grafico->setTitle(QApplication::translate("MainWindow", "Modo grafico", 0));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0));
        menuVentanas->setTitle(QApplication::translate("MainWindow", "Ventanas", 0));
        menuVista->setTitle(QApplication::translate("MainWindow", "Vista", 0));
        menuGrilla->setTitle(QApplication::translate("MainWindow", "Grilla", 0));
        menuEdicion->setTitle(QApplication::translate("MainWindow", "Edici\303\263n", 0));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "Principal", 0));
        ventanaObjetos->setWindowTitle(QApplication::translate("MainWindow", "Explorador", 0));
        btnSearchMode->setText(QApplication::translate("MainWindow", "Explorar", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
        dockWidget_2->setWindowTitle(QApplication::translate("MainWindow", "Objetos", 0));
        btnAddMatrix->setText(QApplication::translate("MainWindow", "Matriz de puntos", 0));
        btnAddImage->setText(QApplication::translate("MainWindow", "Imagen", 0));
        btnAddRegion->setText(QApplication::translate("MainWindow", "Regiones", 0));
        mainToolBox->setItemText(mainToolBox->indexOf(page), QApplication::translate("MainWindow", "General", 0));
        btnAddPerceptron->setText(QApplication::translate("MainWindow", "Perceptron simple", 0));
        btnAddADALINE->setText(QApplication::translate("MainWindow", "Adaline", 0));
        btnAddHopfield->setText(QApplication::translate("MainWindow", "Hopfield", 0));
        btnAddMultilayerPerceptron->setText(QApplication::translate("MainWindow", "Perceptron multicapa", 0));
        mainToolBox->setItemText(mainToolBox->indexOf(page_3), QApplication::translate("MainWindow", "Redes neuronales artificiales", 0));
        btnAddAgent->setText(QApplication::translate("MainWindow", "Agente", 0));
        mainToolBox->setItemText(mainToolBox->indexOf(page_4), QApplication::translate("MainWindow", "Sistemas multiagentes", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
