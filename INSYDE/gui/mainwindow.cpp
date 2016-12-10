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
	connect(ui->mainTab, SIGNAL(tabCloseRequested(int)), SLOT(onCloseTab(int)));
}

void MainWindow::initGUI()
{
	setWindowState(Qt::WindowMaximized);
	setMinimumSize(600, 600);

	sta = new SimulationControl(this);
	ui->mainToolBar->addWidget(sta);
	//    ui->mainVerticalLayout->addWidget(sta);

	updateStatusTimer.start(1000);

	QActionGroup *grupoRenderer = new QActionGroup(this);
	grupoRenderer->addAction(ui->actionNativo);
	grupoRenderer->addAction(ui->actionOpenGL);

	view = new View();

	visor = view->getGraphicsDetailedView();

	//    ui->mainSystemLayout->addWidget(visor, Qt::Vertical);

	visor->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	visor->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	visor->setDragMode(QGraphicsView::RubberBandDrag);

	visor->setSceneRect(-5000, -5000, 10000, 10000);

	//    visor->scene();
	//    map->setUpdatesEnabled();
	//    map->update();
	//    map->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);

	menuNativoClick();
	ui->actionNativo->setChecked(true);
//	#define QT_NO_OPENGL
#ifndef QT_NO_OPENGL
//	menuOpenGLClick();
//	ui->actionOpenGL->setChecked(true);
#else
//	menuNativoClick();
//	ui->actionNativo->setChecked(true);
	ui->actionOpenGL->setEnabled(false);
#endif

	ui->mainSystemLayout->addWidget(view, Qt::Vertical);

	ui->twArbolObjetos->setColumnCount(1);

	trAgentes = new QTreeWidgetItem(QStringList(QString("Agentes")));

	//    trAgentes->setExpanded(true);
	trProyecto = new QTreeWidgetItem(QStringList(QString("Proyecto")));
	//    trProyecto->setExpanded(true);
	trProyecto->addChild(trAgentes);
	ui->twArbolObjetos->addTopLevelItem(trProyecto);

	ui->mainTab->setTabsClosable(true);
	ui->mainTab->setUsesScrollButtons(true);

	toolList.append(ui->btnAddADALINE);
	toolList.append(ui->btnAddAgent);
	toolList.append(ui->btnAddDotMatrix);
	toolList.append(ui->btnAddHopfield);
	toolList.append(ui->btnAddImage);
	toolList.append(ui->btnAddMLP);
	toolList.append(ui->btnAddPerceptron);
	toolList.append(ui->btnAddRegion);
	toolList.append(ui->btnEffect);
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

void MainWindow::uncheckAllBut(QToolButton *control)
{
	int sTools = toolList.size();
	for(int i = 0; i < sTools; i++){
		if(control != toolList[i]){
			toolList[i]->setChecked(false);
		}
	}
}

void MainWindow::uncheckAllTools()
{
	int sTools = toolList.size();
	for(int i = 0; i < sTools; i++){
		toolList[i]->setChecked(false);
	}
}

void MainWindow::setEnabledAllTools(bool en)
{
	int sTools = toolList.size();
	for(int i = 0; i < sTools; i++){
		toolList[i]->setEnabled(en);
	}
}

void MainWindow::onCloseTab(int index)
{
//	setEnabledAllTools(false);
	ui->mainTab->removeTab(index);
}

void MainWindow::onVisorClicked(QMouseEvent *event)
{
	QGraphicsScene *sce = visor->scene();


	foreach(QToolButton *btn, toolList){
		if(btn->isChecked()){
			if(visor->itemAt(event->pos()) == NULL){
				if(btn == ui->btnAddADALINE){

				}else if(btn == ui->btnAddAgent){

				}else if(btn == ui->btnAddDotMatrix){
					AddDotMatrixDialog *dmd = new AddDotMatrixDialog(25, 25);

					if(dmd->exec() == QDialog::Accepted){
						DotMatrix *dm = new DotMatrix(7, dmd->getRows(), dmd->getCols(), dmd->getDataType());

						QGraphicsScene *sce = visor->scene();
						dm->setPos(visor->mapToScene(event->pos()));
						sce->addItem(dm);
					}

					delete dmd;
				}else if(btn == ui->btnAddHopfield){

				}else if(btn == ui->btnAddImage){
					QString path = QFileDialog::getOpenFileName(this,
																"Abrir archivo",
																"/home/edixon/programacion/INSYDE/INSYDEUI/imagenes/",
																"Todas las imagenes (*.png *.jpg *.gif *.bmp);; Mapa de bits (*.bmp);; Formato JPEG (*.jpg);; Portable Network Graphics (*.png);; Formato de Intercambio de Graficos (*.gif)");

					if(path != ""){
						Image *gie = new Image(path);
						tmpInputElement = gie;
						gie->setPos(visor->mapToScene(event->pos()));
						sce->addItem(gie);
					}
				}else if(btn == ui->btnAddMLP){
					AddNewMLPDialog *mlpd = new AddNewMLPDialog();

					if(mlpd->exec() == QDialog::Accepted){
						MLPObject *mlpe = new MLPObject(new MultilayerPerceptron(
																			mlpd->getInputSize(),
																			mlpd->getOutputSize(),
																			mlpd->getLayerSizes(),
																			mlpd->getTransferFunction())
																		);
						mlpe->setPos(visor->mapToScene(event->pos()));

						//Configuracion temporal de la conexion

						mlpe->setInputElement(giee);

						//Fin de configuracion

						sce->addItem(mlpe);
					}
					delete mlpd;
				}else if(btn == ui->btnAddPerceptron){

				}else if(btn == ui->btnAddRegion){

				}else if(btn == ui->btnEffect){
					giee = new ImageEffect();
					giee->setInputElement(tmpInputElement);

					giee->setPos(visor->mapToScene(event->pos()));
					sce->addItem(giee);
				}
			}
		}
	}

	uncheckAllTools();
}

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
	ui->actionOpenGL->setChecked(false);
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
	ui->actionNativo->setChecked(false);
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

	//    int ang;
	double posX;
	double posY;

	qsrand(QTime::currentTime().msec());
	//    ang = qrand() * 360 / 32768;
	posX = qrand() * 400 / 32768;
	posY = qrand() * 400 / 32768;

	dlgAddAgents = new AddAgentsDialog();
	if(dlgAddAgents->exec() == QDialog::Accepted){
		PlayerType pt = Human;
		PlayerColor pc = Blue;
		PlayerTeam ptm = PlayerTeam::None;
		int maxVitality = dlgAddAgents->getMaxVitality();
		int vitality = dlgAddAgents->getInitialVitality();
		int maxEnergy = dlgAddAgents->getMaxEnergy();
		int energy = dlgAddAgents->getInitialEnergy();
		int speed = dlgAddAgents->getSpeed();
		int visualScope = dlgAddAgents->getVisualScope();
		int numberUnits = dlgAddAgents->getNumOfUnits();

		switch(dlgAddAgents->getCurrentController()){
			case 0: //Human
				pt = Human;
				break;
			case 1: //Computer
				pt = Computer;
				break;
		}

		switch(dlgAddAgents->getCurrentColor()){
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

		switch(dlgAddAgents->getCurrentColor()){
			case 0:
				ptm = PlayerTeam::None;
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

		int selectedIndex = dlgAddAgents->getCurrentAgentType();

		int power = 0;
		int range = 0;

		if(selectedIndex == 1){
			power = dlgAddAgents->getPowerValue();
			range = dlgAddAgents->getRangeValue();
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
	view->getGraphicsDetailedView()->removeSelected();
}

void MainWindow::runAnimation()
{
//	view->getGraphicsDetailedView()->setSimulationStatus(Running);
}

void MainWindow::pauseAnimation()
{
//	view->getGraphicsDetailedView()->setSimulationStatus(Paused);
}

void MainWindow::stopAnimation()
{
//	view->getGraphicsDetailedView()->setSimulationStatus(Stopped);
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
	switch(view->getSimulationStatus()){
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

void MainWindow::onNewProyectTriggered(bool val)
{
	Q_UNUSED(val)

	newProjectDialog = new NewProjectWizard();
	newProjectDialog->setWindowTitle("Nuevo Proyecto");
	newProjectDialog->exec();
}

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

void MainWindow::on_btnAddDotMatrix_clicked(bool checked)
{
	Q_UNUSED(checked);

	uncheckAllBut(ui->btnAddDotMatrix);
}

void MainWindow::on_btnAddImage_clicked(bool checked)
{
	Q_UNUSED(checked);

	uncheckAllBut(ui->btnAddImage);
}

void MainWindow::on_btnAddRegion_clicked(bool checked)
{
	Q_UNUSED(checked);

	uncheckAllBut(ui->btnAddRegion);
}

void MainWindow::on_btnAddADALINE_clicked(bool checked)
{
	Q_UNUSED(checked);

	uncheckAllBut(ui->btnAddADALINE);
}

void MainWindow::on_btnAddHopfield_clicked(bool checked)
{
	Q_UNUSED(checked);

	uncheckAllBut(ui->btnAddHopfield);
}

void MainWindow::on_btnAddMLP_clicked(bool checked)
{
	Q_UNUSED(checked);

	uncheckAllBut(ui->btnAddMLP);
}

void MainWindow::on_btnAddPerceptron_clicked(bool checked)
{
	Q_UNUSED(checked);

	uncheckAllBut(ui->btnAddPerceptron);
}

void MainWindow::on_btnAddAgent_clicked(bool checked)
{
	Q_UNUSED(checked);

	uncheckAllBut(ui->btnAddAgent);
}

void MainWindow::on_btnEffect_clicked(bool checked)
{
	Q_UNUSED(checked);

	uncheckAllBut(ui->btnEffect);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
	double zoom = double(value)/100;
	visor->setTransform(QTransform::fromScale(zoom, zoom));
	//	visor->scale();
}

