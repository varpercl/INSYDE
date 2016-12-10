#include "newmainwindow.h"
static quintptr const& ptrDM = 0;

NewMainWindow::NewMainWindow() :
	BasicDialog()
{
	init();
}

NewMainWindow::~NewMainWindow()
{

}

void NewMainWindow::onCloseTabsToRight()
{
	while(currentTab != mainTab->count() - 1){
		mainTab->removeTab(currentTab + 1);
	}
}

void NewMainWindow::onCloseTabsToLeft()
{
	while(currentTab != 0){
		mainTab->removeTab(0);
		currentTab--;
	}
}

void NewMainWindow::onCloseOtherTabs()
{
	onCloseTabsToRight();
	onCloseTabsToLeft();
}

void NewMainWindow::onCloseAllTabs()
{
	mainTab->clear();
}

void NewMainWindow::on10pxTriggered()
{

}

void NewMainWindow::on20pxTriggered()
{

}

void NewMainWindow::on50pxTriggered()
{

}

void NewMainWindow::onCustomizeGrid()
{

}

void NewMainWindow::onNativeTriggered()
{

}

void NewMainWindow::onOpenGLTriggered()
{

}

void NewMainWindow::onAddAdalineClicked()
{
	uncheckToolButton();
}

void NewMainWindow::onAddAgentClicked()
{
	uncheckToolButton();
}

void NewMainWindow::onAddDotMatrixClicked()
{
	uncheckToolButton();
}

void NewMainWindow::onAddHopfieldClicked()
{
	uncheckToolButton();
}

void NewMainWindow::onAddImageClicked()
{
	uncheckToolButton();
}

void NewMainWindow::onAddMLPClicked()
{
	uncheckToolButton();
}

void NewMainWindow::onAddSimplePerceptronClicked()
{
	uncheckToolButton();
}

void NewMainWindow::onAddRegionClicked()
{
	uncheckToolButton();
}

void NewMainWindow::onAddEffectClicked()
{
	uncheckToolButton();
}

void NewMainWindow::onGDVMousePressed(QMouseEvent *event)
{
	(void)event;
	//Getting the button pointer to be used after in a switch statement
	QToolButton *btn = (QToolButton*)generalBG->checkedButton();

	GraphicDetailedView *gdv = systemView->getGraphicsDetailedView();

	Enviroment *env = (Enviroment*)gdv->scene();

	if(btn == btnAddDotMatrix){
		AddDotMatrixDialog *dmd = new AddDotMatrixDialog(25, 25);

		if(dmd->exec() == QDialog::Accepted){
			DotMatrix *dm = new DotMatrix(7, dmd->getRows(), dmd->getCols(), dmd->getDataType());
			dm->setInputsSize(dm->getCols() * dm->getRows());

			dm->setObjectLocked(true);
			dm->setPos(gdv->mapToScene(event->pos()));

			env->addItem(dm);
			simulation->add(dm);

			connect(dm, SIGNAL(openOnWindowRequest(GraphicObject*)), SLOT(onOpenOnNewWindowRequest(GraphicObject*)));
			connect(dm, SIGNAL(objectRemoved(GraphicObject*)), SLOT(onObjectRemoved(GraphicObject*)));
		}

		delete dmd;
	}else if(btn == btnAddADALINE){

		showUnderConstructionMessage();

	}else if(btn == btnAddAgent){

		showUnderConstructionMessage();

	}else if(btn == btnAddHopfield){

		showUnderConstructionMessage();

	}else if(btn == btnAddImage){
		QString path = QFileDialog::getOpenFileName(this,
													"Abrir archivo",
													DIR_SAMPLES,
													"All image formats (*.bmp *.png *.jpg *.gif);; Bitmap BMP (*.bmp);; Portable Network Graphic PNG (*.png);; JPEG image (*.jpg);; GIF image (*.gif)");

		Image *gie = new Image(path);

		gie->setPos(gdv->mapToScene(event->pos()));

		env->addItem(gie);
		simulation->add(gie);

		connect(gie, SIGNAL(openOnWindowRequest(GraphicObject*)), SLOT(onOpenOnNewWindowRequest(GraphicObject*)));
		connect(gie, SIGNAL(objectRemoved(GraphicObject*)), SLOT(onObjectRemoved(GraphicObject*)));

	}else if(btn == btnAddMLP){
		AddNewMLPDialog *mlpd = new AddNewMLPDialog();

		if(mlpd->exec() == QDialog::Accepted){
			MLPObject *mlpe = new MLPObject(new MultilayerPerceptron(
																mlpd->getInputSize(),
																mlpd->getOutputSize(),
																mlpd->getLayerSizes(),
																mlpd->getTransferFunction())
															);
			mlpe->setPos(gdv->mapToScene(event->pos()));

			env->addItem(mlpe);
			simulation->add(mlpe);

			connect(mlpe, SIGNAL(openOnWindowRequest(GraphicObject*)), SLOT(onOpenOnNewWindowRequest(GraphicObject*)));
			connect(mlpe, SIGNAL(objectRemoved(GraphicObject*)), SLOT(onObjectRemoved(GraphicObject*)));
		}
		delete mlpd;
	}else if(btn == btnAddSimplePerceptron){

		showUnderConstructionMessage();

	}else if(btn == btnAddRegion){

		showUnderConstructionMessage();

	}else if(btn == btnAddEffect){
//		ImageEffect *giee = new ImageEffect();

//		giee->setPos(gdv->mapToScene(event->pos()));
//		sce->addItem(giee);
//		simulation->add(giee);

//		connect(giee, SIGNAL(openOnWindowRequest(GraphicObject*)), SLOT(onOpenOnNewWindowRequest(GraphicObject*)));
//		connect(giee, SIGNAL(objectRemoved(GraphicObject*)), SLOT(onObjectRemoved(GraphicObject*)));

		showUnderConstructionMessage();
	}else{

		QPointF mappedPos = gdv->mapToScene(event->pos());
		QList<QGraphicsItem*> itemList = env->items(mappedPos);

//		GraphicObject *itemClicked;
		for(auto i = 0; i < itemList.count(); i++){
			if(itemList[i]->type() == GraphicObject::gotConnector){
				itemList.removeAt(i);
//				itemList.removeOne(connector);
			}
		}
		if(itemList.count() > 0){

			int mayorIndex = 0;
			qreal
					zVal = -999999999999999,
					itemZVal;

			for(auto i = 0; i < itemList.count(); i++){
				itemZVal = itemList[i]->zValue();
				if(itemZVal > zVal){
					zVal = itemZVal;
					mayorIndex = i;
				}
			}
			clickedObject = (GraphicObject*)itemList[mayorIndex];
		}else{
			clickedObject = 0;
		}

		if(clickedObject && !lookingForEndObject){
			if(clickedObject->getCurrentPort(clickedObject->mapFromScene(mappedPos)) != GraphicObject::portNone){
				beginObject = clickedObject;

				connector = new Connector();

				connector->setBeginObject(beginObject);

				gdv->installEventFilter(connector);

				env->addItem(connector);
				simulation->add(connector);

				clickedObject = 0;

				lookingForEndObject = true;
			}
		}else if(clickedObject && lookingForEndObject){
			if(clickedObject->getCurrentPort(clickedObject->mapFromScene(mappedPos)) != GraphicObject::portNone && clickedObject != beginObject){
				endObject = clickedObject;

				connector->setEndObject(endObject);

				gdv->removeEventFilter(connector);

				clickedObject = 0;

				lookingForEndObject = false;
			}
		}else if(!clickedObject && lookingForEndObject){
			env->removeItem(connector);
			simulation->remove(connector);

			connector->setBeginObject(nullptr);
			connector->setEndObject(nullptr);

			clickedObject = 0;

			lookingForEndObject = false;

//			delete connector;
		}


//		connector->setContainerRect(QRect(0, 0, 0, 0));

//		setMouseTracking(true);

	}


	uncheckToolButton();
}

void NewMainWindow::onOpenOnNewWindowRequest(GraphicObject *obj)
{
	if(isOpenWindow(obj)){
		mainTab->setCurrentIndex(getTabIndex(obj));
	}else{
		switch(obj->type()){
			case GraphicObject::gotImage:{
				Image *img = (Image*)obj;

				mainTab->setCurrentIndex(mainTab->addTab(new ImageDetailedWindow(img->getImage()), obj->objectName()));

				break;
			}
			case GraphicObject::gotDotMatrix:{
				DotMatrix *dm = (DotMatrix*)obj;

				DotMatrix *ddm = new DotMatrix(dm->getDotList(),
											   dm->getDotSize(),
											   dm->getRows(),
											   dm->getCols(),
											   dm->getDataType()
											   );
				ddm->setInputsSize(dm->getInputsSize());

				mainTab->setCurrentIndex(mainTab->addTab(new DotMatrixDetailedWindow(ddm), dm->objectName()));

				connect(dm, SIGNAL(inputsSizeChanged(int)), ddm, SLOT(setInputsSize(int)));
				connect(ddm, SIGNAL(inputsSizeChanged(int)), dm, SLOT(setInputsSize(int)));

				connect(dm, SIGNAL(matrixSizeChanged(QSize)), ddm, SLOT(setSize(QSize)));
				connect(ddm, SIGNAL(matrixSizeChanged(QSize)), dm, SLOT(setSize(QSize)));

				connect(dm, SIGNAL(dotSizeChanged(int)), ddm, SLOT(setDotSize(int)));
				connect(ddm, SIGNAL(dotSizeChanged(int)), dm, SLOT(setDotSize(int)));

				break;
			}
			case GraphicObject::gotMLP:{
				MLPObject *mlpe = (MLPObject*)obj;


				break;
			}
			case GraphicObject::gotImageEffect:{
				ImageEffect *ie = (ImageEffect*)obj;


				break;
			}
			default:
				break;
		}
	}
}

void NewMainWindow::onObjectRemoved(GraphicObject *obj)
{
	for(int i = 0; i < mainTab->count(); i++){
		if(mainTab->tabText(i) == obj->objectName()){
			mainTab->removeTab(i);
			break;
		}
	}
}

void NewMainWindow::onTabCloseRequested(int index)
{
	mainTab->removeTab(index);
}

void NewMainWindow::onTabContextMenu(QPoint pos)
{
	currentTab = mainTab->tabBar()->tabAt(pos);
	menuTabs->exec(mainTab->tabBar()->mapToGlobal(pos));
}

void NewMainWindow::newClick()
{
	showUnderConstructionMessage();
}

void NewMainWindow::openClick()
{
	showUnderConstructionMessage();
}

void NewMainWindow::saveClick()
{
	showUnderConstructionMessage();
}

void NewMainWindow::saveAsClick()
{
	showUnderConstructionMessage();
}

void NewMainWindow::importClick()
{
	showUnderConstructionMessage();
}

void NewMainWindow::exportClick()
{
	showUnderConstructionMessage();
}

void NewMainWindow::undoClick()
{
	showUnderConstructionMessage();
}

void NewMainWindow::redoClick()
{
	showUnderConstructionMessage();
}

void NewMainWindow::copyClick()
{
	showUnderConstructionMessage();
}

void NewMainWindow::cutClick()
{
	showUnderConstructionMessage();
}

void NewMainWindow::pasteClick()
{
	showUnderConstructionMessage();
}

void NewMainWindow::preferencesClick()
{
	showUnderConstructionMessage();
}

void NewMainWindow::helpClick()
{
	showUnderConstructionMessage();
}

void NewMainWindow::aboutClick()
{
	showUnderConstructionMessage();
}

void NewMainWindow::init()
{
	setupUI();
}

void NewMainWindow::setupUI()
{
	clickedObject = NULL;
	beginObject = NULL;
	endObject = NULL;

	lastChecked = false;
	lookingForEndObject = false;

	QMainWindow *mw = getMainWindow();

	//Initialize QMenu
	menuGrid = new QMenu("Grilla");
	menuGraphics = new QMenu(QString::fromLatin1("Graficos"));
	menuTabs = new QMenu(QString::fromLatin1("Pestañas"));

	//Initialize QTabWidgets
	mainTab = new QTabWidget();

	//Initialize QWidgets
	systemWidget = new QWidget();
	generalTBWidget = new QWidget();
	annTBWidget = new QWidget();
	ecTBWidget = new QWidget();

	//Initialize QVBoxLayouts
	vlyGeneralToolBox = new QVBoxLayout();
	vlyANNToolBox = new QVBoxLayout();
	vlyECToolBox = new QVBoxLayout();

	//Initialize View
	systemView = new View();

	//Initialize QDockWidget
	dwToolBox = new QDockWidget("Objetos");

	//Initialize QToolBox
	mainToolBox = new QToolBox();

	//Initialize QToolButtons
	btnAddADALINE = new QToolButton();
	btnAddAgent = new QToolButton();
	btnAddDotMatrix = new QToolButton();
	btnAddHopfield = new QToolButton();
	btnAddImage = new QToolButton();
	btnAddMLP = new QToolButton();
	btnAddSimplePerceptron = new QToolButton();
	btnAddRegion = new QToolButton();
	btnAddEffect = new QToolButton();

	//Initialize QActionGroup
	gridGroup = new QActionGroup(menuGrid);
	graphicsGroup = new QActionGroup(menuGraphics);

	//Initialize QButtonGroup
	generalBG = new QButtonGroup();

	//Initialize Simulation
	simulation = new Simulation();

	currentTab = 0;

	actionCloseTabsToRight = menuTabs->addAction("Cerrar ventanas a la derecha", this, SLOT(onCloseTabsToRight()));
	actionCloseTabsToLeft = menuTabs->addAction("Cerrar ventanas a la izquierda", this, SLOT(onCloseTabsToLeft()));
	actionCloseOtherTabs = menuTabs->addAction("Cerrar las demas ventanas", this, SLOT(onCloseOtherTabs()));
	actionCloseAllTabs = menuTabs->addAction("Cerrar todas las ventanas", this, SLOT(onCloseAllTabs()));

	menuGrid->setIcon(ICON_DOTMATRIX);

	action10px = menuGrid->addAction("10 px", this, SLOT(on10pxTriggered()));
	action10px->setCheckable(true);
	action10px->setChecked(true);

	action20px = menuGrid->addAction("20 px", this, SLOT(on20pxTriggered()));
	action20px->setCheckable(true);

	action50px = menuGrid->addAction("50 px", this, SLOT(on50pxTriggered()));
	action50px->setCheckable(true);

	menuGrid->addSeparator();

	actionCustomize = menuGrid->addAction("Personalizar...", this, SLOT(onCustomizeGrid()));

	gridGroup->addAction(action10px);
	gridGroup->addAction(action20px);
	gridGroup->addAction(action50px);

	actionNative = menuGraphics->addAction("Nativos", this, SLOT(onNativeTriggered()));
	actionNative->setCheckable(true);
	actionNative->setChecked(true);

	actionOpenGL = menuGraphics->addAction("OpenGL", this, SLOT(onOpenGLTriggered()));
	actionOpenGL->setCheckable(true);

	graphicsGroup->addAction(actionNative);
	graphicsGroup->addAction(actionOpenGL);

	getViewMenu()->addAction(menuGrid->menuAction());
	getViewMenu()->addAction(menuGraphics->menuAction());

	btnAddDotMatrix->setText("Matriz de puntos");
	btnAddDotMatrix->setIcon(ICON_DOTMATRIX);
	btnAddDotMatrix->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	btnAddDotMatrix->setAutoRaise(true);
	btnAddDotMatrix->setCheckable(true);

	btnAddImage->setText("Imagen");
	btnAddImage->setIcon(ICON_IMAGE);
	btnAddImage->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	btnAddImage->setAutoRaise(true);
	btnAddImage->setCheckable(true);

	btnAddEffect->setText("Efecto");
	btnAddEffect->setIcon(ICON_EFFECT);
	btnAddEffect->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	btnAddEffect->setAutoRaise(true);
	btnAddEffect->setCheckable(true);

	btnAddRegion->setText(QString::fromLatin1("Región"));
	btnAddRegion->setIcon(ICON_SETS);
	btnAddRegion->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	btnAddRegion->setAutoRaise(true);
	btnAddRegion->setCheckable(true);

	btnAddSimplePerceptron->setText(QString::fromLatin1("Perceptrón simple"));
	btnAddSimplePerceptron->setIcon(ICON_SIMPLEPERCEPTRON);
	btnAddSimplePerceptron->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	btnAddSimplePerceptron->setAutoRaise(true);
	btnAddSimplePerceptron->setCheckable(true);

	btnAddADALINE->setText("Adaline");
	btnAddADALINE->setIcon(ICON_ADALINE);
	btnAddADALINE->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	btnAddADALINE->setAutoRaise(true);
	btnAddADALINE->setCheckable(true);

	btnAddMLP->setText(QString::fromLatin1("Perceptrón multicapa"));
	btnAddMLP->setIcon(ICON_MLP);
	btnAddMLP->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	btnAddMLP->setAutoRaise(true);
	btnAddMLP->setCheckable(true);

	btnAddHopfield->setText("Hopfield");
	btnAddHopfield->setIcon(ICON_HOPFIELD);
	btnAddHopfield->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	btnAddHopfield->setAutoRaise(true);
	btnAddHopfield->setCheckable(true);

	btnAddAgent->setText("Agente");
	btnAddAgent->setIcon(ICON_AGENT);
	btnAddAgent->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	btnAddAgent->setAutoRaise(true);
	btnAddAgent->setCheckable(true);

	generalBG->addButton(btnAddDotMatrix);
	generalBG->addButton(btnAddImage);
	generalBG->addButton(btnAddEffect);
	generalBG->addButton(btnAddRegion);
	generalBG->addButton(btnAddSimplePerceptron);
	generalBG->addButton(btnAddADALINE);
	generalBG->addButton(btnAddMLP);
	generalBG->addButton(btnAddHopfield);
	generalBG->addButton(btnAddAgent);

	vlyGeneralToolBox->addWidget(btnAddDotMatrix);
	vlyGeneralToolBox->addWidget(btnAddImage);
	vlyGeneralToolBox->addWidget(btnAddEffect);
	vlyGeneralToolBox->addWidget(btnAddRegion);
	vlyGeneralToolBox->addStretch(1);

	vlyANNToolBox->addWidget(btnAddSimplePerceptron);
	vlyANNToolBox->addWidget(btnAddADALINE);
	vlyANNToolBox->addWidget(btnAddMLP);
	vlyANNToolBox->addWidget(btnAddHopfield);
	vlyANNToolBox->addStretch(1);

	vlyECToolBox->addWidget(btnAddAgent);
	vlyECToolBox->addStretch(1);

	generalTBWidget->children();
	generalTBWidget->setLayout(vlyGeneralToolBox);
	annTBWidget->setLayout(vlyANNToolBox);
	ecTBWidget->setLayout(vlyECToolBox);

	mainToolBox->addItem(generalTBWidget, "General");
	mainToolBox->addItem(annTBWidget, "Redes neuronales");
	mainToolBox->addItem(ecTBWidget, QString::fromLatin1("Computación emergente"));

	dwToolBox->setFeatures(QDockWidget::NoDockWidgetFeatures | QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	dwToolBox->setWidget(mainToolBox);

	systemView->getGraphicsDetailedView()->setDragMode(QGraphicsView::RubberBandDrag);

	mainTab->tabBar()->setContextMenuPolicy(Qt::CustomContextMenu);
	mainTab->setTabsClosable(true);
	mainTab->addTab(systemView, "Principal");

	mw->addDockWidget(Qt::RightDockWidgetArea, dwToolBox);

	mw->setCentralWidget(mainTab);

	setAcceptButtonVisible(false);
	setApplyButtonVisible(false);
	setRejectButtonVisible(false);
	setHelpButtonVisible(false);

	setWindowFlags(Qt::Window);
	setWindowState(Qt::WindowMaximized);

//	connect(mainTab, SIGNAL(customContextMenuRequested(QPoint)), SLOT(onTabContextMenu(QPoint)));
	connect(mainTab->tabBar(), SIGNAL(customContextMenuRequested(QPoint)), SLOT(onTabContextMenu(QPoint)));
	connect(mainTab, SIGNAL(tabCloseRequested(int)), SLOT(onTabCloseRequested(int)));
	connect(btnAddADALINE, SIGNAL(clicked()), SLOT(onAddAdalineClicked()));
	connect(btnAddAgent, SIGNAL(clicked()), SLOT(onAddAgentClicked()));
	connect(btnAddDotMatrix, SIGNAL(clicked()), SLOT(onAddDotMatrixClicked()));
	connect(btnAddHopfield, SIGNAL(clicked()), SLOT(onAddHopfieldClicked()));
	connect(btnAddImage, SIGNAL(clicked()), SLOT(onAddImageClicked()));
	connect(btnAddMLP, SIGNAL(clicked()), SLOT(onAddMLPClicked()));
	connect(btnAddSimplePerceptron, SIGNAL(clicked()), SLOT(onAddSimplePerceptronClicked()));
	connect(btnAddRegion, SIGNAL(clicked()), SLOT(onAddRegionClicked()));
	connect(btnAddEffect, SIGNAL(clicked()), SLOT(onAddEffectClicked()));
	connect(systemView->getGraphicsDetailedView(), SIGNAL(mousePressed(QMouseEvent*)), SLOT(onGDVMousePressed(QMouseEvent*)));
}

void NewMainWindow::uncheckToolButton()
{
	QToolButton *btn = (QToolButton *)generalBG->checkedButton();

	if(btn){
		if(lastChecked && lastToolChoosed == btn){
			generalBG->setExclusive(false);
			btn->setChecked(false);
			generalBG->setExclusive(true);
		}
		lastChecked = btn->isChecked();
		lastToolChoosed = btn;
	}
}

bool NewMainWindow::isOpenWindow(GraphicObject *obj)
{
	for(auto i = 0; i < mainTab->count(); i++){
		if(mainTab->tabText(i) == obj->objectName()){
			return true;
		}
	}
	return false;
}

int NewMainWindow::getTabIndex(GraphicObject *obj)
{
	for(auto i = 0; i < mainTab->count(); i++){
		if(mainTab->tabText(i) == obj->objectName()){
			return i;
		}
	}

	return -1;
}

void NewMainWindow::showUnderConstructionMessage()
{
	underConstruction.setWindowTitle("En desarrollo");
	underConstruction.setIcon(QMessageBox::Information);
	underConstruction.setText(QString::fromLatin1("Esta función no esta disponible en esta versión. \n\r Actualmente se encuentra en desarrollo"));
	underConstruction.exec();
}
