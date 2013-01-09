#include "pruebapantallas.h"
#include "ui_prueba_pantallas.h"
#include <letterdeclarations.h>

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
		DotMatrix *dm = new DotMatrix(5, 7, 5, DotMatrix::Unipolar);
		QGraphicsScene *sce = visor->scene();
		dm->setPos(visor->mapToScene(event->pos()));
		sce->addItem(dm);

		const int nPatterns = 26;
		vector<MultilayerPerceptronPattern*> ts(nPatterns);
		for(int i = 0; i < nPatterns; i++){
			ts[i] = new MultilayerPerceptronPattern(letters[i], 35, LetterTargets[i], 26);
		}
		vector<int> lsizes;
		lsizes.push_back(150);
//		lsizes.push_back(3);
		mlpe = new GraphicMLPElement(new MultilayerPerceptron(35, 26, lsizes, MultilayerPerceptron::Sigmoid));
		mlpe->setPos(visor->mapToScene(event->pos() + QPoint(100, 0)));
		mlpe->setTrainingSet(ts);
		mlpe->setInputElement(dm);
		sce->addItem(mlpe);

		BinaryOutputElement *bor = new BinaryOutputElement(26, BinaryOutputElement::Vertical, 0.5, BinaryOutputElement::GREATER_EQUAL_THAN);
		bor->setPos(visor->mapToScene(event->pos() + QPoint(300, 0)));
		bor->setInputElement(mlpe);
		sce->addItem(bor);
		geCounter++;
	}
}

void PruebaPantalla::on_pushButton_clicked()
{
	vector<int> sizes;
	sizes.push_back(5);
	MLPTrainingDialog *mlpTS = new MLPTrainingDialog(mlpe);

	mlpTS->show();
}
