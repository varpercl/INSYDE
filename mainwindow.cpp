#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    newProjectDialog(NULL),
    dlgAddAgents(0),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initGUI();
    conectarEventos();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::conectarEventos(){
    connect(sta, SIGNAL(run()), SLOT(runAnimation()));
    connect(sta, SIGNAL(pause()), SLOT(pauseAnimation()));
    connect(sta, SIGNAL(stop()), SLOT(stopAnimation()));
	connect(ui->btnAddAgent, SIGNAL(clicked()), SLOT(btnAddAgentClick()));
	connect(visor->scene(), SIGNAL(selectionChanged()), this, SLOT(showSelectedAgents()));
    connect(visor, SIGNAL(clicked(QMouseEvent*)), SLOT(onVisorClicked(QMouseEvent*)));
//    connect(map->scene(), SIGNAL(changed(QList<QRectF>)), SLOT(showNumberAgents()));
    connect(&updateStatusTimer, SIGNAL(timeout()), SLOT(updateWindowStatus()));
}

void MainWindow::initGUI(){

    setWindowState(Qt::WindowMaximized);
    setMinimumSize(600, 600);

    sta = new StatusAnimationControl(this);
    ui->mainToolBar->addWidget(sta);
//    ui->mainVerticalLayout->addWidget(sta);

    updateStatusTimer.start(1000);

    QActionGroup *grupoRenderer = new QActionGroup(this);
    grupoRenderer->addAction(ui->actionNativo);
    grupoRenderer->addAction(ui->actionOpenGL);

    visor = new Visor();
//    ui->mainSystemLayout->addWidget(visor, Qt::Vertical);
    visor->setVisible(false);
    visor->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    visor->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    visor->setDragMode(QGraphicsView::RubberBandDrag);

    visor->setSceneRect(-5000, -5000, 10000, 10000);

//    visor->scene();
//    map->setUpdatesEnabled();
//    map->update();
//    map->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);

//#define QT_NO_OPENGL
#ifndef QT_NO_OPENGL
    menuOpenGLClick();
    ui->actionOpenGL->setChecked(true);
#else
    menuNativoClick();
    ui->actionNativo->setChecked(true);
    ui->actionOpenGL->setEnabled(false);
#endif

    visor->setVisible(true);
    ui->mainSystemLayout->addWidget(visor, Qt::Vertical);

    ui->twArbolObjetos->setColumnCount(1);

    trAgentes = new QTreeWidgetItem(QStringList(QString("Agentes")));

//    trAgentes->setExpanded(true);
    trProyecto = new QTreeWidgetItem(QStringList(QString("Proyecto")));
//    trProyecto->setExpanded(true);
    trProyecto->addChild(trAgentes);
    ui->twArbolObjetos->addTopLevelItem(trProyecto);
}

void MainWindow::showSelectedAgents(){
    int nItems = visor->scene()->selectedItems().count();
    if(nItems > 0){
        ui->statusBar->showMessage("Agentes seleccionados: " + QString::number(nItems));
    }else{
        ui->statusBar->showMessage("");
    }
}

void MainWindow::updateWindowStatus()
{
    int nItems = visor->scene()->selectedItems().count();
    ui->statusBar->showMessage("Agentes seleccionados: " + QString::number(nItems) + " | Numero de objetos: " + QString::number(visor->scene()->items().count()));
}

void MainWindow::onVisorClicked(QMouseEvent *event)
{
    static int geCounter = 0;
    if(geCounter == 0){
        DotMatrix *dm = new DotMatrix(6, 15, 10);
        QGraphicsScene *sce = visor->scene();
        dm->setPos(visor->mapToScene(event->pos()));
        sce->addItem(dm);

		vector<int> lsizes;
		lsizes.push_back(100);
		lsizes.push_back(50);
		GraphicMLPElement *mlpe = new GraphicMLPElement(new MultilayerPerceptron(35, 26, lsizes, MultilayerPerceptron::Sigmoid));
        mlpe->setPos(visor->mapToScene(event->pos() + QPoint(200, 0)));
        sce->addItem(mlpe);
        geCounter++;
    }
}

//void MainWindow::closeEvent(QCloseEvent *event){
////    Q_UNUSED(event);
////    event->ignore();
//}

void MainWindow::menuSalirClick(){
    QMessageBox::StandardButton ret;

    ret = QMessageBox::warning(this, "Confirmación", "¿Esta seguro que desea salir del programa?", QMessageBox::Yes | QMessageBox::No);
    if(ret == QMessageBox::Yes){
        this->close();
    }
}

void MainWindow::menuNativoClick(){
    if(actualRender != Nativo){
        viewPortWidget = new QWidget();
        visor->setViewport(viewPortWidget);
        if(!glWidget)
            delete glWidget;
        actualRender = Nativo;
    }
}

void MainWindow::menuOpenGLClick(){
    if(actualRender != OpenGL){
        QGLFormat glFormat(QGL::SampleBuffers|
                           QGL::DoubleBuffer
                           );
        glFormat.setSampleBuffers(true);
        glWidget = new QGLWidget(glFormat);
        visor->setViewport(glWidget);
        if(!viewPortWidget)
            delete viewPortWidget;
        actualRender = OpenGL;
    }
}

void MainWindow::menuContextualListaObjetos(QPoint p){
    QMenu *cntxMenu = new QMenu();

    QAction *agregar = new QAction("Agregar", ui->twArbolObjetos);

    QMenu *mnuAgregar = new QMenu();
//    mnuAgregar->addAction("Agente", )
    agregar->setMenu(mnuAgregar);
    cntxMenu->addAction("Agregar", this, SLOT(borrarDisenio()));
    cntxMenu->exec(visor->mapToGlobal(p));
}

void MainWindow::btnAddAgentClick(){
    static int agentCont = 1;

    int ang;
    double posX;
    double posY;

    qsrand(QTime::currentTime().msec());
    ang = qrand() * 360 / 32768;
    posX = qrand() * 400 / 32768;
    posY = qrand() * 400 / 32768;

    dlgAddAgents = new AddAgentsDialog();
    if(dlgAddAgents->exec() == QDialog::Accepted){
        PlayerType pt = Human;
        PlayerColor pc = Blue;
        PlayerTeam ptm = None;
        int maxVitality = dlgAddAgents->ui->sbMaxVitality->value();
        int vitality = dlgAddAgents->ui->sbInitialVitality->value();
        int maxEnergy = dlgAddAgents->ui->sbMaxEnergy->value();
        int energy = dlgAddAgents->ui->sbInitialEnergy->value();
        int speed = dlgAddAgents->ui->sbSpeed->value();
        int visualScope = dlgAddAgents->ui->sbVisualScope->value();
        int numberUnits = dlgAddAgents->ui->sbNumOfUnits->value();

        switch(dlgAddAgents->ui->cmbController->currentIndex()){
            case 0: //Human
                pt = Human;
                break;
            case 1: //Computer
                pt = Computer;
                break;
        }

        switch(dlgAddAgents->ui->cmbColorList->currentIndex()){
            case 0: //Blue
                pc = Blue;
                break;
            case 1: //green
                pc = Green;
                break;
            case 2: //yellow
                pc = Yellow;
                break;
            case 3: //brown
                pc = Brown;
                break;
            case 4: //purple
                pc = Purple;
                break;
            case 5: //cyan
                pc = Cyan;
                break;
            case 6: //rojo
                pc = Red;
                break;
            case 7: //naranja
                pc = Orange;
                break;
        }

        switch(dlgAddAgents->ui->cmbColorList->currentIndex()){
            case 0:
                ptm = None;
                break;
            case 1:
                ptm = Team1;
                break;
            case 2:
                ptm = Team2;
                break;
            case 3:
                ptm = Team3;
                break;
            case 4:
                ptm = Team4;
                break;
        }

        int selectedIndex = dlgAddAgents->ui->cmbAgentType->currentIndex();

        int power = 0;
        int range = 0;

        if(selectedIndex == 1){
            power = dlgAddAgents->ui->sbPowerValue->value();
            range = dlgAddAgents->ui->sbRangeValue->value();
        }

        Unit *soldado = NULL;
        for(int i = 0; i < numberUnits; i++){
            switch(selectedIndex){
                case 0:
                    soldado = new Unit(pt, pc, ptm, maxVitality, vitality, maxEnergy, energy, visualScope, speed);
                    break;
                case 1:
                    soldado = new ShootingUnit(power, range, pt, pc, ptm, maxVitality, vitality, maxEnergy, energy, visualScope, speed);
                    break;
            }

            switch(sta->getCurrentStatus()){
                case Running:
                    break;
                case Paused:
                    break;
                case Stopped:
                    soldado->setFlag(QGraphicsItem::ItemIsMovable);
            }

            soldado->setVisibleVisionSensorArea(false);

            PlayerColor pc;
            for(int i = 0; i < 8; i++){
                pc = (PlayerColor)i;
                if(pc != soldado->getUnitColor()){
                    soldado->setDiplomacyTo(pc, Enemy);
                }
            }

            soldado->setPos(posX, posY);
            visor->scene()->addItem(soldado);

            QTreeWidgetItem *itm = new QTreeWidgetItem(trAgentes,  QStringList(QString("agente%1").arg(agentCont++)));
            itm->setFlags(itm->flags() |
                          Qt::ItemIsEditable
                          );
            trAgentes->addChild(itm);
        }
    }
    delete dlgAddAgents;
}

void MainWindow::btnDeleteAgentClick(){
    visor->deleteSelected();
}

void MainWindow::runAnimation()
{
    visor->setSimulationStatus(Running);
}

void MainWindow::pauseAnimation()
{
    visor->setSimulationStatus(Paused);
}

void MainWindow::stopAnimation()
{
    visor->setSimulationStatus(Stopped);
}

void MainWindow::addAgents()
{

}

void MainWindow::on_btnSearchMode_clicked()
{
    QList<QGraphicsItem*> items = visor->scene()->selectedItems();
//    QGraphicsObject *obj;
    Unit *unit;
    int itemCount = items.count();
    switch(visor->getSimulationStatus()){
        case Running:
            for(int i = 0; i < itemCount; i++){
                if((unit = dynamic_cast<Unit*>(dynamic_cast<QGraphicsObject*>(items[i])))){
                    if(unit->getPlayerType() == Computer){
                        unit->startSearchMode();
                    }
                }
            }
            break;
        case Paused:
        case Stopped:
            break;
    }

}
/*
  Este codigo esta dejado en caso de que se quiera reimplementar la libreria del asistente
  basado en arbol de decision.

void MainWindow::onNewProyectTriggered(bool val)
{
    Q_UNUSED(val)

    npd = new AssistantDialog(this);

    SelectProjectWidget *so = new SelectProjectWidget();
    so->setWindowTitle("Seleccione el proyecto");

    ChooseProjectNameWidget *st = new ChooseProjectNameWidget();
    st->setWindowTitle("Nombre y ubicación");

    StepWidget *steps = new StepWidget("choose-project", so, npd);
    MultiLeafNode<AbstractStepFrameWidget*> *root = steps->getRootStep();
    root->appendChild(st->windowTitle(), st);
    steps->setActiveStep("choose-project");

    npd->setSteps(steps);
    npd->exec();
}
*/

void MainWindow::onNewProyectTriggered(bool val)
{
//    Q_UNUSED(val)

    newProjectDialog = new NewProjectWizard();
    newProjectDialog->setWindowTitle("Nuevo Proyecto");
    newProjectDialog->exec();
}

//void MainWindow::on_pushButton_2_clicked()
//{
//    acoDialog = new ACO(this);

//    acoDialog->setAttribute(Qt::WA_DeleteOnClose);

//    acoDialog->exec();
//}

void MainWindow::on_mainToolBox_currentChanged(int index)
{
//    ui->btnAddAgent
    int sWidgets = ui->mainToolBox->count();

    for(int j = 0; j < sWidgets; j++){
        if(j != index){
            QList<QToolButton*> obj = ui->mainToolBox->widget(j)->findChildren<QToolButton*>();
            int sObj = obj.size();
            QToolButton *tb;
            for(int i = 0; i < sObj; i++){

                if((tb = dynamic_cast<QToolButton*>(obj[i]))){
                    tb->setChecked(false);
                }
            }
        }
    }

}
