#include "pruebapantallas.h"
#include "ui_prueba_pantallas.h"

PruebaPantalla::PruebaPantalla(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::PruebaPantalla)
{
	ui->setupUi(this);
}

PruebaPantalla::~PruebaPantalla()
{
	delete ui;
}

void PruebaPantalla::on_newProjectButton_clicked()
{
	NewProjectWizard *npw = new NewProjectWizard();
	//    npw->hide();
	npw->exec();
}

void PruebaPantalla::on_perceptronButton_clicked()
{
	PerceptronPage *pp = new PerceptronPage();
	pp->show();
}

void PruebaPantalla::on_systemButton_clicked()
{
	//    ui->mainSystemLayout->addWidget(visor, Qt::Vertical);
	visor = new View();
	visor->setVisible(false);
	visor->getGraphicsDetailedView()->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	visor->getGraphicsDetailedView()->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	visor->getGraphicsDetailedView()->setDragMode(QGraphicsView::RubberBandDrag);
	visor->getGraphicsDetailedView()->setSceneRect(-5000, -5000, 10000, 10000);
	visor->setVisible(true);
	connect(visor, SIGNAL(clicked(QMouseEvent*)), SLOT(onVisorClicked(QMouseEvent*)));
}

void PruebaPantalla::onVisorClicked(QMouseEvent *event)
{

	(void)event;
	//	static int geCounter = 0;
	//	if(geCounter == 0){
	//		DotMatrix *dm = new DotMatrix(5, 7, 5, DotMatrix::Unipolar);
	//		QGraphicsScene *sce = visor->scene();
	//		dm->setPos(visor->mapToScene(event->pos()));
	//		sce->addItem(dm);

	//		int nPatterns = 26;
	//		TrainingSet *ts = new TrainingSet(letters, 35, LetterTargets, 26, nPatterns);
	//////		vector<MultilayerPerceptronPattern*> patterns(nPatterns);
	////		for(int i = 0; i < nPatterns; i++){
	////			patterns[i] = new MultilayerPerceptronPattern(letters[i], 35, LetterTargets[i], 26);
	////		}
	//		vector<int> lsizes;
	//		lsizes.push_back(20);
	////		lsizes.push_back(3);

	//		mlpe = new GraphicMLPElement(new MultilayerPerceptron(35, 26, lsizes, MultilayerPerceptron::Sigmoid));
	//		mlpe->setPos(visor->mapToScene(event->pos() + QPoint(100, 0)));
	//		mlpe->setTrainingSet(ts);
	//		mlpe->setInputElement(dm);
	//		sce->addItem(mlpe);

	//		BinaryOutputElement *bor = new BinaryOutputElement(26, BinaryOutputElement::Vertical, 0.5, BinaryOutputElement::GREATER_EQUAL_THAN);
	//		bor->setPos(visor->mapToScene(event->pos() + QPoint(300, 0)));
	//		bor->setInputElement(mlpe);
	//		sce->addItem(bor);
	//		geCounter++;
	//	}
}

void PruebaPantalla::on_ANNTrainingDialog_clicked()
{

	vector<int> sizes;
//	sizes.push_back(200);
//	sizes.push_back(150);
	sizes.push_back(50);
	mlp = new MultilayerPerceptron(403, 36, sizes, MultilayerPerceptron::Sigmoid);

	ANNTrainingDialog *mlptd = new ANNTrainingDialog(mlp, new TrainingSet(mlp->getInputsSize(), mlp->getOutputsSize()));
//	mlptd->setEnableOpen(false);
//	mlptd->setEnableSave(false);
//	mlptd->setEnableNew(false);
//	mlptd->setEnableExport(false);
//	mlptd->setEnableImport(false);
//	mlptd->setEnableClipboardFramework(true);
//	mlptd->setEnableUnDoFramework(false);

//	MLPTrainingDialog *mlpTS = new MLPTrainingDialog(mlp, new TrainingSet(TrainingSetFile(":/samples/aprendizaje-de-letras-de-placas.tsf")));

//	mlptd->setWindowModality(Qt::NonModal);

	mlptd->show();
}

void PruebaPantalla::on_TrainingSetDialogButton_clicked()
{
	QString path = "/home/edixon/programacion/INSYDE/samples/aprendizaje-de-letras-de-placas.tsf";
	TrainingSetDialog *tsd1 = new TrainingSetDialog(new TrainingSet(path));
	tsd1->exec();
}

void PruebaPantalla::on_DataRepresentationBoxButton_clicked()
{
	QString openDir = QFileDialog::getOpenFileName(this, //widget
												  "Abrir conjunto de entrenamiento", //caption
												  "/home/edixon/programacion/INSYDE//samples/TrainingSets", //dir
												  "Conjunto de entrenamiento (*.tsf)", //filter
												  new QString("Conjunto de entrenamiento (*.tsf)"));

	if(openDir == "") return;

	TrainingSet *ts = new TrainingSet(openDir);

	DataRepresentationBox *drb = new DataRepresentationBox(ts->getInputs()[0], ts->getInputsDataRepresentation());

	drb->show();
}
void PruebaPantalla::on_LabeledIntegerSpinBoxButton_clicked()
{
	LabeledIntegerSpinBox *isb = new LabeledIntegerSpinBox("Valor", 0, LabeledWidget::Right);

//	isb->setLabelPosition(LabeledIntegerSpinBox::Top);

	isb->show();
}

void PruebaPantalla::on_IntegerSizeWidgetButton_clicked()
{
	IntegerSizeWidget *isw = new IntegerSizeWidget();

	isw->setLabelAlignment(Qt::AlignRight);
	isw->show();
}

void PruebaPantalla::on_SelectImageSegmentButton_clicked()
{
	//	QMessageBox msgBox;
	QImage imageFile;
	//	QString file = QFileDialog::getOpenFileName(this, "Abrir archivo", "C:\\Users\\Edixon Vargas\\Google Drive\\Programacion\\C++\\Qt\\INSYDE\\INSYDEUI\\imagenes\\png", "Portable Network Graphic (*.png);; Bitmap (*.bmp);; JPEG Image (*.jpg);; (*.gif)");
	//	imageFile = QImage(file);
	imageFile = QImage("C:\\Users\\Edixon Vargas\\Google Drive\\Programacion\\C++\\Qt\\INSYDE\\INSYDEUI\\imagenes\\png\\Microphone Hot.png");

	sisd = new SelectImageSegmentDialog(imageFile, QRect(0, 0, 20, 20));

	sisd->exec();
}

void PruebaPantalla::on_LabeledComboBoxButton_clicked()
{
	LabeledComboBox *lcb = new LabeledComboBox("Lista",
											   QStringList()
											   << "Item1"
											   << "Item2"
											   << "Item3"
											   << "Item4"
											   << "Item5"
											   << "Item6");

	lcb->setLabelPosition(LabeledWidget::Top);
	lcb->show();
}

void PruebaPantalla::on_BasicDialogButton_clicked()
{
	BasicDialog *bd = new BasicDialog();

	bd->exec();
}

void PruebaPantalla::on_DotMatrixRepresentationButton_clicked()
{
	QString openDir = QFileDialog::getOpenFileName(this, //widget
												  "Abrir conjunto de entrenamiento", //caption
												  "/home/edixon/programacion/INSYDE//samples/TrainingSets", //dir
												  "Conjunto de entrenamiento (*.tsf)", //filter
												  new QString("Conjunto de entrenamiento (*.tsf)"));

	if(openDir == "") return;

	TrainingSet *ts = new TrainingSet(openDir);

    core::DotMatrixRepresentation *dmr = new core::DotMatrixRepresentation(ts->getInputs()[0]);

	dmr->show();
}

void PruebaPantalla::on_ZoomControlButton_clicked()
{
	ZoomControl *zc = new ZoomControl();

	zc->show();
}

void PruebaPantalla::on_DetailedWindowButton_clicked()
{
	DetailedWindow *dw = new DetailedWindow();

//	dw->setEnableZooming(false);
	dw->show();
}

void PruebaPantalla::on_NormalizationWidgetButton_clicked()
{
	NormalizationWidget *nw = new NormalizationWidget();

	nw->show();
}

void PruebaPantalla::on_WeightEditorDialogButton_clicked()
{
	vector<int> sizes;
	sizes.push_back(10);
	sizes.push_back(20);
	sizes.push_back(30);
	mlp = new MultilayerPerceptron(403, 36, sizes, MultilayerPerceptron::Sigmoid);

	WeightEditorDialog *wed = new WeightEditorDialog(mlp);

	wed->exec();
}
void PruebaPantalla::on_DoubleMinMaxWidgetButton_clicked()
{
	DoubleMinMaxWidget *dmmw = new DoubleMinMaxWidget(-2, 2);

	dmmw->setAligment(Qt::Vertical);
	dmmw->setAligment(Qt::Horizontal);

	dmmw->show();
}


void PruebaPantalla::on_NewMainWindowButton_clicked()
{
	MainWindow *mainWindow = new MainWindow;

	mainWindow->show();
}

void PruebaPantalla::on_GraphicObjectPropertyDialogButton_clicked()
{
	DotMatrix *dm = new DotMatrix(10, 10, DotMatrix::Unipolar);

	GraphicObjectPropertyDialog *gopd = new GraphicObjectPropertyDialog(dm);

	gopd->show();
}
