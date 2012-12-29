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
	//    TrainingSetDialog<PerceptronTrainingPattern*> *tsd = new TrainingSetDialog<PerceptronTrainingPattern*>(5);
	////    tsd->getPat
	//    tsd->show();
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
	static int geCounter = 0;
	if(geCounter == 0){
		DotMatrix *dm = new DotMatrix(6, 15, 10);
		QGraphicsScene *sce = visor->scene();
		dm->setPos(visor->mapToScene(event->pos()));
		sce->addItem(dm);

		vector<int> lsizes;
		lsizes.push_back(30);
//		lsizes.push_back(3);
		GraphicMLPElement *mlpe = new GraphicMLPElement(new MultilayerPerceptron(35, 26, lsizes, MultilayerPerceptron::Sigmoid));
		mlpe->setPos(visor->mapToScene(event->pos() + QPoint(100, 0)));
		sce->addItem(mlpe);

		BinaryOutputRepresentation *bor = new BinaryOutputRepresentation(3);
		bor->setPos(visor->mapToScene(event->pos() + QPoint(300, 0)));
		sce->addItem(bor);
		geCounter++;
	}
}

void PruebaPantalla::on_pushButton_clicked()
{
	vector<int> sizes;
	sizes.push_back(5);
	MLPTrainingDialog *mlpTS = new MLPTrainingDialog(new MultilayerPerceptron(10, 20, sizes, MultilayerPerceptron::Sigmoid));

	mlpTS->show();
}
