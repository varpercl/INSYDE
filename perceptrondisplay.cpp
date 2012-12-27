#include "perceptrondisplay.h"

PerceptronDetailedDisplay::PerceptronDetailedDisplay(SimplePerceptron *sp) :
    QGraphicsScene()
{
    initPDisplay(sp);
}

PerceptronDetailedDisplay::~PerceptronDetailedDisplay()
{
    int sInputs = piInputs.size();
    for(int i = 0; i < sInputs; i++){
        delete piInputs[i];
        delete gliWeights[i];
    }
}

void PerceptronDetailedDisplay::setInputSize(int n)
{
    const int sep = 7;
    int hSum = 0;
    for(int i = 0; i < piInputs.size(); i++){
        delete piInputs[i];
        delete gliWeights[i];
    }

    //    piInputs.clear();
        piInputs.resize(n);
    //    gliWeights.clear();
        gliWeights.resize(n);

    for(int i = 0; i < n; i++){
        piInputs[i] = new PerceptronInput();
        piInputs[i]->setPos(piInputs[i]->x(), i * (piInputs[i]->size().height() + sep));
//        piInputs[i]->setZValue(9999999);
        hSum += piInputs[i]->geometry().height() + sep;

        addItem(piInputs[i]);
    }
    hSum -= sep;

    int dNucleo = 50;

    nucleo->setBrush(Qt::white);
    nucleo->setPos((n*10)+ 50, hSum/2 - dNucleo/2);
    nucleo->setRect(0, 0, dNucleo, dNucleo);

    for(int i = 0; i < n; i++){
        gliWeights[i] = new QGraphicsLineItem();
        gliWeights[i]->setZValue(-9999999);
        gliWeights[i]->setLine(QLineF(piInputs[i]->getNodeCenter(), nucleo->pos() + QPointF(nucleo->rect().width() / 2, nucleo->rect().height()/2)));
        addItem(gliWeights[i]);
    }
    sp->setNumberInputs(n);
}

int PerceptronDetailedDisplay::getInputSize()
{
    return piInputs.size();
}

void PerceptronDetailedDisplay::setPerceptron(SimplePerceptron *sp)
{
    this->sp = sp;
    initPDisplay(sp);
}

SimplePerceptron* PerceptronDetailedDisplay::getPerceptron()
{
    return sp;
}

void PerceptronDetailedDisplay::initPDisplay(SimplePerceptron *sp)
{
    this->sp = sp;
    nucleo = new Soma();
    setInputSize(sp->getInputSize());
    addItem(nucleo);
}

PerceptronInput::PerceptronInput() :
    QGraphicsProxyWidget(0, 0)
{
    initPI();
}

void PerceptronInput::setNodePosition(PerceptronInput::NodePosition np)
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

}

PerceptronInput::NodePosition PerceptronInput::getNodePosition()
{
    return nodePosition;
}

QPointF PerceptronInput::getNodeCenter() const
{

    return mapToScene(QPointF(nodeRect.left() + nodeRect.width()/2, nodeRect.top() + nodeRect.height()/2));
}

void PerceptronInput::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsProxyWidget::paint(painter, option, widget);

//    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawEllipse(nodeRect);

}

//QRectF PerceptronInput::boundingRect() const
//{
//    return QGraphicsWidget::boundingRect();
//}

//QPainterPath PerceptronInput::shape() const
//{
//    return QGraphicsWidget::shape();
//}

void PerceptronInput::initPI()
{
    nodeDiameter = 5;

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
}

Soma::Soma(QGraphicsItem *parent, QGraphicsScene *scene):
    QGraphicsEllipseItem(parent, scene)
{
}

Soma::Soma(const QRectF &rect, QGraphicsItem *parent, QGraphicsScene *scene):
    QGraphicsEllipseItem(rect, parent, scene)
{
}

Soma::Soma(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent, QGraphicsScene *scene):
    QGraphicsEllipseItem(x, y, width, height, parent, scene)
{
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
