#include "pruebapantallas.h"
#include "ui_prueba_pantallas.h"

PruebaPantalla::PruebaPantalla(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::PruebaPantalla)
{
	ui->setupUi(this);

	visor = new Visor();
	connect(visor, SIGNAL(clicked(QMouseEvent*)), SLOT(onVisorClicked(QMouseEvent*)));
}

//PruebaPantalla::PruebaPantalla(const PruebaPantalla &pp)
//{
//	//TODO: implementar
//	(void)pp;
//}

PruebaPantalla::~PruebaPantalla()
{
    delete ui;
}

void PruebaPantalla::onTrainingFinished()
{
	btnTrain->setText("Iniciar");
}

void PruebaPantalla::onTrainingClicked()
{
	if(!mlp->isTraining()){
		TrainingSet *ts = new TrainingSet("://TrainingSets/pruebas/aprendizaje-de-letras-de-placas.tsf");
		BackpropagationSettings bpts(20000, 0.5, 0.002, 0, 0.5, StopCondition::RMSE);

		mlp->startTraining(ts, &bpts);
		btnTrain->setText("Entrenando");

        delete ts;
	}
}

void PruebaPantalla::on_newProjectButton_clicked()
{
	NewProjectWizard *npw = new NewProjectWizard();
	//    npw->hide();
	npw->exec();
}

void PruebaPantalla::on_mainWindowButton_clicked()
{
	MainWindow *w = new MainWindow();
	w->show();
}

void PruebaPantalla::on_perceptronButton_clicked()
{
	PerceptronPage *pp = new PerceptronPage();
	pp->show();
}

void PruebaPantalla::on_trainingSetButton_clicked()
{
	//	TrainingSetDialog *tsd = new TrainingSetDialog(10, 10);
	//	tsd->exec();

	TrainingSetDialog *tsd1 = new TrainingSetDialog(new TrainingSet(403, 36));
	tsd1->exec();

	//	TrainingSetDialog *tsd2 = new TrainingSetDialog()
}

void PruebaPantalla::on_systemButton_clicked()
{
	//    ui->mainSystemLayout->addWidget(visor, Qt::Vertical);
	visor->setVisible(false);
	visor->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	visor->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	visor->setDragMode(QGraphicsView::RubberBandDrag);
	visor->setSceneRect(-5000, -5000, 10000, 10000);
	visor->setVisible(true);
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

void PruebaPantalla::on_pushButton_clicked()
{
	vector<int> sizes;
	sizes.push_back(5);
	mlp = new MultilayerPerceptron(10, 10, sizes, MultilayerPerceptron::Sigmoid);

	MLPTrainingDialog *mlpTS = new MLPTrainingDialog(mlp, new TrainingSet(mlp->getInputSize(), mlp->getOutputSize()));

	mlpTS->exec();
}

void PruebaPantalla::on_pushButton_2_clicked()
{
	GraphicImageEffectElementPropertyDialog *gieepd = new GraphicImageEffectElementPropertyDialog(new GraphicImageEffectElement());

	gieepd->show();
}

void PruebaPantalla::on_pushButton_3_clicked()
{
	//	QMessageBox msgBox;
	QImage imageFile;
	//	QString file = QFileDialog::getOpenFileName(this, "Abrir archivo", "C:\\Users\\Edixon Vargas\\Google Drive\\Programacion\\C++\\Qt\\INSYDE\\INSYDEUI\\imagenes\\png", "Portable Network Graphic (*.png);; Bitmap (*.bmp);; JPEG Image (*.jpg);; (*.gif)");
	//	imageFile = QImage(file);
	imageFile = QImage("C:\\Users\\Edixon Vargas\\Google Drive\\Programacion\\C++\\Qt\\INSYDE\\INSYDEUI\\imagenes\\png\\Microphone Hot.png");

	sisd = new SelectImageSegmentDialog(imageFile, QRect(0, 0, 20, 20));

	sisd->exec();
}

void PruebaPantalla::on_pushButton_4_clicked()
{
	vector<int> capas;
	capas.push_back(200);
	mlp = new MultilayerPerceptron(403, 36, capas);

	QDialog *test = new QDialog();
	btnTrain = new QPushButton("Iniciar", test);

	connect(btnTrain, SIGNAL(clicked()), SLOT(onTrainingClicked()));
	connect(mlp, SIGNAL(trainingFinished()), SLOT(onTrainingFinished()));

	test->exec();

    delete test;
}
