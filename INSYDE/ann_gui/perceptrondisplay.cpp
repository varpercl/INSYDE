#include "perceptrondisplay.h"

PerceptronDisplay::PerceptronDisplay(SimplePerceptron *sp) :
	QGraphicsScene()
{
	init(sp);
}

PerceptronDisplay::~PerceptronDisplay()
{
	int sInputs = geiInputs.size();
	for(int i = 0; i < sInputs; i++){
		delete geiInputs[i];
		delete gliWeights[i];
	}
}

void PerceptronDisplay::setInputSize(int n)
{
	const int hInput = 6;
	const int wInput = 6;
	const int sep = 7;
	int hSum = 0;
	vector<double> w = sp->getWeightsVector();


	//Se elmina de la memoria los elementos que fueron creados previamente
	//y que no se usaran en caso de que se haga una redimension mas pequenia
	for(int i = 0; i < geiInputs.size(); i++){
		delete geiInputs[i];
		delete gliWeights[i];
	}

	geiInputs.resize(n);
	gliWeights.resize(n);

	sp->setInputSize(n);
	int dNucleo = 50;

	//Se realiza el posicionamiento del nucleo
	hSum = (n * (hInput + sep)) - sep;

	nucleo->setBrush(Qt::white);
	nucleo->setPos((n*10)+ 50, hSum/2 - dNucleo/2);
	nucleo->setRect(0, 0, dNucleo, dNucleo);
	nucleo->setZValue(geiInputs.size() + 1);

	for(int i = 0; i < n; i++){

		//Se inicia la configuracion y posicionamiento de los circulos que representan las entradas
		geiInputs[i] = new QGraphicsEllipseItem(QRect(0, 0, wInput, hInput));
		geiInputs[i]->setOpacity(1);
		geiInputs[i]->setBrush(QBrush(Qt::green));
		geiInputs[i]->setZValue(geiInputs.size() + i + 1);
		geiInputs[i]->setPos(geiInputs[i]->x() + 20, i * (geiInputs[i]->rect().height() + sep));
		addItem(geiInputs[i]);

		//Se ubican las lineas que unen las entradas con el nucleo y su representacion en escala de colores
		gliWeights[i] = new WeightLine(
							QLineF(geiInputs[i]->pos() + geiInputs[i]->rect().center(), nucleo->pos() + nucleo->rect().center()),
							w[i],
							100,
							-100,
							2,
							sp,
							i
							);
		gliWeights[i]->setAutomaticWeightLimits(true);
		gliWeights[i]->setZValue(i);
		connect(gliWeights[i], SIGNAL(weightValueChanged(int,double,double)), SLOT(onWeightValueChanged(int,double,double)));
		addItem(gliWeights[i]);
	}

}//setInputSize

int PerceptronDisplay::getInputSize()
{
	return geiInputs.size();
}//getInputSize

void PerceptronDisplay::setWeightsVector(vector<double> weights)
{
	sp->setWeights(weights);
	updateWeightLines(weights);
}//setWeightsVector

vector<double> PerceptronDisplay::getWeightsVector() const
{
	return sp->getWeightsVector();
}//getWeightsVector

void PerceptronDisplay::setPerceptron(SimplePerceptron *sp)
{
	this->sp = sp;
}//setPerceptron

SimplePerceptron* PerceptronDisplay::getPerceptron()
{
	return sp;
}//getPerceptron

void PerceptronDisplay::onWeightValueChanged(int index, double before, double after)
{
	(void)index;
	(void)before;
	(void)after;

	updateWeightLines(sp->getWeightsVector());
}//onWeightValueChanged

void PerceptronDisplay::init(SimplePerceptron *sp)
{
	this->sp = sp;
	nucleo = new Soma();
	setInputSize(this->sp->getInputSize());
	addItem(nucleo);

}//initPDisplay

void PerceptronDisplay::updateWeightLines(vector<double> weights)
{
	int wLines = weights.size();
	for(int i = 0; i < wLines; i++){
		gliWeights[i]->updateWeightColor();
	}

}//updateWeightLines

WeightEditProxy::WeightEditProxy(QGraphicsItem *parent) :
	QGraphicsProxyWidget(parent)
{
	init();
}//WeightEdit

void WeightEditProxy::setNodePosition(WeightEditProxy::NodePosition np)
{
	switch(nodePosition = np){
		case Left:
			nodeRect = QRectF(leValue->x() - nodeDiameter - 3, (leValue->y() + leValue->height())/2 - (nodeDiameter/2), nodeDiameter, nodeDiameter);
			wg->setGeometry(0,0, leValue->width()+nodeDiameter+4, leValue->height());
			break;
		case Right:
			nodeRect = QRectF(leValue->x() + leValue->width() + 3, (leValue->y() + leValue->height())/2 - (nodeDiameter/2), nodeDiameter, nodeDiameter);
			wg->setGeometry(0,0, leValue->width()+nodeDiameter+4, leValue->height());
			break;
		case Top:
			nodeRect = QRectF((leValue->x() + leValue->width())/2 - nodeDiameter/2, leValue->y() - nodeDiameter - 3, nodeDiameter, nodeDiameter);
			wg->setGeometry(0,0, leValue->width(), leValue->height()+nodeDiameter+4);
			break;
		case Bottom:
			nodeRect = QRectF((leValue->x() + leValue->width())/2 - nodeDiameter/2, leValue->y() + leValue->height() + 3, nodeDiameter, nodeDiameter);
			wg->setGeometry(0,0, leValue->width(), leValue->height()+nodeDiameter+4);
			break;
	}

}//setNodePosition

WeightEditProxy::NodePosition WeightEditProxy::getNodePosition()
{
	return nodePosition;
}//getNodePosition

QPointF WeightEditProxy::getNodeCenter() const
{
	return mapToScene(QPointF(nodeRect.left() + nodeRect.width()/2, nodeRect.top() + nodeRect.height()/2));
}//getNodeCenter

void WeightEditProxy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QGraphicsProxyWidget::paint(painter, option, widget);

}//paint

void WeightEditProxy::init()
{
	nodeDiameter = 6;

	//    setMinimumWidth(40);
	//    setGeometry(QRectF(0,0, 40, 100));

	wg = new QWidget();

	QPalette pal;
	pal.setColor(QPalette::Background, Qt::transparent);
	setPalette(pal);

	leValue = new QLineEdit(wg);
	leValue->setValidator(new QDoubleValidator(DBL_MAX, DBL_MIN, 3));
	leValue->setGeometry(0,0,40,20);
	setNodePosition(Right);

	setWidget(wg);
	//    setVisible(false);
}//initWE

Soma::Soma(QGraphicsItem *parent, QGraphicsScene *scene):
	QGraphicsEllipseItem(parent)
{
	Q_UNUSED(scene);
}//Soma

Soma::Soma(const QRectF &rect, QGraphicsItem *parent, QGraphicsScene *scene):
	QGraphicsEllipseItem(rect, parent)
{
	Q_UNUSED(scene);
}

Soma::Soma(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent, QGraphicsScene *scene):
	QGraphicsEllipseItem(x, y, width, height, parent)
{
	Q_UNUSED(scene);
}

QPointF Soma::getCenter() const
{
	return mapToScene(QPointF(rect().left() + rect().width()/2, rect().top() + rect().height()/2));
}

void Soma::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawLine(rect().left() + rect().width()/2, rect().top() + rect().height()/2, rect().left() + rect().width()/2, rect().top() + rect().height() + 30);
	painter->drawPixmap(rect().left() + rect().width()/2 + 5, rect().top() + rect().height() + 20, 15, 22, QPixmap(":/imagenes/theta.png"));
	painter->drawLine(rect().left() + rect().width()/2, rect().top() + rect().height()/2, rect().left() + rect().width() + 20, rect().top() + rect().height()/2);

	QRectF stepRect = rect().adjusted(rect().left() + rect().width() + 20, 10, rect().left() + rect().width() + 0, -10);
	painter->drawRect(stepRect);
	painter->drawLine(stepRect.left() + 10, stepRect.top() + stepRect.height() - 10, stepRect.left() + stepRect.width()/2, stepRect.top() + stepRect.height() - 10);
	painter->drawLine(stepRect.left() + stepRect.width()/2, stepRect.top() + stepRect.height() - 10, stepRect.left() + stepRect.width()/2, stepRect.top() + 10);
	painter->drawLine(stepRect.left() + stepRect.width()/2, stepRect.top() + 10, stepRect.left() + stepRect.width() - 10, stepRect.top() + 10);

	painter->drawLine(stepRect.left() + stepRect.width(), stepRect.top() + stepRect.height()/2, stepRect.left() + stepRect.width() + 20, stepRect.top() + stepRect.height()/2);

	painter->drawPixmap(stepRect.left() + stepRect.width() + 10, stepRect.top() + stepRect.height()/2 - 20, QPixmap(":/imagenes/salida.png"));

	//    painter->drawRect(boundingRect());
	QGraphicsEllipseItem::paint(painter, option, widget);

	painter->drawPixmap(15,14, 15, 22, QPixmap(":/imagenes/suma.png"));

}

QRectF Soma::boundingRect() const
{
	QPainterPath path;
	path.addRect(QGraphicsEllipseItem::boundingRect());
	path.addRect(rect().adjusted(rect().left() + rect().width() + 20, 0, rect().left() + rect().width() + 20, 0));
	path.addRect(15,15, 15, 22);
	path.lineTo(rect().left() + rect().width() + 95, rect().top() + rect().height()/2 + 70);
	return path.controlPointRect();
}

