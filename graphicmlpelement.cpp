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
	cntxMenu->addAction("Agregar al conjunto de entrenamiento", this, SLOT(onAddToTrainingSet()));
	cntxMenu->addAction("Entrenar", this, SLOT(onTrainClick()));
	cntxMenu->addAction("Borrar", this, SLOT(onDeleteClick()));
	cntxMenu->addAction("Propiedades", this, SLOT(onPropertyClick()));

	return cntxMenu;
}

int GraphicMLPElement::type() const
{
	return GraphicMLPElementType;
}

void GraphicMLPElement::setTrainingSet(vector<MultilayerPerceptronPattern *> ts)
{
	this->ts = ts;
}

vector<MultilayerPerceptronPattern *> GraphicMLPElement::getTrainingSet()
{
	return ts;
}

void GraphicMLPElement::setMultilayerPerceptron(MultilayerPerceptron *mlp)
{
	this->mlp = mlp;
}

MultilayerPerceptron *GraphicMLPElement::getMultilayerPerceptron()
{
	return mlp;
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
	inputElement = ge;
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
	MLPTrainingDialog *mlptd = new MLPTrainingDialog(this);
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
//	inputs = outputs;
	vector<double> out = mlp->getOutput(outputs.toStdVector());
	emit outputChanged(QVector<double>::fromStdVector(out));
}

void GraphicMLPElement::onAddToTrainingSet()
{
	TrainingSetDialog *tsMLP = new TrainingSetDialog(ts);
	DotMatrix *dm = dynamic_cast<DotMatrix*>(inputElement);
	tsMLP->appendPattern(dm->getDotList(), QVector<int>(mlp->getOutputSize(), 0));
	if(tsMLP->exec() == QDialog::Accepted){
		int sPatterns = tsMLP->getPatternCount();
		vector<MultilayerPerceptronPattern*> ts(sPatterns);
		for(int i = 0; i < sPatterns; i++){
			vector<vector<double> > in = tsMLP->getInputs();
			vector<vector<double> > out = tsMLP->getTargets();
			ts[i] = new MultilayerPerceptronPattern(in[i], out[i]);
		}
		setTrainingSet(ts);
//		targets = tsMLP->getTargets();
//		inputs = tsMLP->getInputs();
	}
}
