#include "graphicmlpelement.h"

GraphicMLPElement::GraphicMLPElement(MultilayerPerceptron *mlp)
{
	initMLP(mlp);
}

GraphicMLPElement::~GraphicMLPElement()
{

}

QMenu *GraphicMLPElement::getContextMenu(QMenu *cntxMenu)
{
	cntxMenu->addAction("Entrenar", this, SLOT(onTrainClick()));
	cntxMenu->addAction("Borrar", this, SLOT(onDeleteClick()));
	cntxMenu->addAction("Propiedades", this, SLOT(onPropertyClick()));

	return cntxMenu;
}

int GraphicMLPElement::type() const
{
	return GraphicMLPElementType;
}

void GraphicMLPElement::setInputElement(GraphicElement *ge)
{
	switch(ge->type()){
		case DotMatrix::DotMatrixType:
			DotMatrix *dm = dynamic_cast<DotMatrix*>(ge);
			dm->setOutputElement(this);
			connect(dm, SIGNAL(statusChanged(QVector<int>)), SLOT(onDotMatrixStatusChanged(QVector<int>)));
			break;
	}
}

GraphicElement *GraphicMLPElement::getInputElement()
{
	return inputElement;
}

void GraphicMLPElement::setOutputElement(GraphicElement *ge)
{
}

GraphicElement *GraphicMLPElement::getOutputElement()
{
	return outputElement;
}

void GraphicMLPElement::onTrainClick()
{
	MLPTrainingDialog *mlptd = new MLPTrainingDialog(mlp);
	mlptd->show();
}

void GraphicMLPElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	GraphicElement::paint(painter, option, widget);

	painter->drawImage(getRectangle().adjusted(5,5,-5,-5), QImage(":imagenes/perceptron multicapa.png"));
}

void GraphicMLPElement::onPropertyClick()
{
}

void GraphicMLPElement::initMLP(MultilayerPerceptron *mlp)
{
	this->mlp = mlp;
}

void GraphicMLPElement::onDotMatrixStatusChanged(QVector<int> outputs)
{
	vector<double> out = mlp->getOutput(outputs.toStdVector());
	emit outputChanged(QVector<double>::fromStdVector(out));
}
