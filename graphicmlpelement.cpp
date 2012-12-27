#include "graphicmlpelement.h"

GraphicMLPElement::GraphicMLPElement(MultilayerPerceptron *mlp)
{
	initMLP(mlp);
}

GraphicMLPElement::~GraphicMLPElement()
{
	//	delete cntxMenu;
}

QMenu *GraphicMLPElement::getContextMenu(QMenu *cntxMenu)
{
	cntxMenu->addAction("Entrenar", this, SLOT(onTrainClick()));
	cntxMenu->addAction("Borrar", this, SLOT(onDeleteClick()));
	cntxMenu->addAction("Propiedades", this, SLOT(onPropertyClick()));

	return cntxMenu;
}

//void GraphicMLPElement::showPropertyDialog()
//{
//}

void GraphicMLPElement::onTrainClick()
{
	//	QDialog *dlg = new QDialog();

	//	dlg->exec();


//	vector<MultilayerPerceptronPattern*> trainingSet;
//	trainingSet.push_back(new MultilayerPerceptronPattern(aLetter, 35, aLetterTarget, 26));

//	mlp->train(trainingSet, 10000, 0.01, 0.5);

    MLPTrainingDialog *mlptd = new MLPTrainingDialog(mlp);
    mlptd->show();
}

//void GraphicMLPElement::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//{
//	GraphicElement::mouseReleaseEvent(event);
//	if(event->button() == Qt::RightButton){

//		//        QAction *borrar = new QAction("Agregar", cntxMenu);
//		cntxMenu->addAction("Entrenar", this, SLOT(onTrainClick()));
////		cntxMenu->addAction("Propiedades", this, SLOT(onPropertyClick()));
//		cntxMenu->exec(parentWidget()->mapToParent(event->pos()).toPoint());
//		//    QMenu *mnuAgregar = new QMenu();
//		//    mnuAgregar->addAction("Agente", )
//		//        borrar->setMenu(mnuAgregar);

//		//    cntxMenu->addAction("Agregar", this, SLOT(borrarDisenio()));
//		//    cntxMenu->exec(map->mapToGlobal(p));
//	}
//}

void GraphicMLPElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	GraphicElement::paint(painter, option, widget);

	painter->drawImage(getRectangle().adjusted(5,5,-5,-5), QImage(":imagenes/perceptron multicapa.png"));
}

void GraphicMLPElement::initMLP(MultilayerPerceptron *mlp)
{
	this->mlp = mlp;
}
