#include "pheromoneitem.h"

ec_gui::PheromoneItem::PheromoneItem()
{
    iniciarItemPheromona(20, 0);
}

ec_gui::PheromoneItem::PheromoneItem(int cantidad)
{
    iniciarItemPheromona(cantidad, 0);
}

ec_gui::PheromoneItem::PheromoneItem(int cantidad, double angle)
{
    iniciarItemPheromona(cantidad, angle);
}

void ec_gui::PheromoneItem::iniciarItemPheromona(int cantidad, double angle)
{
//    setFlags(ItemIsSelectable);
    setAcceptHoverEvents(true);
    setZValue(0.0000001);

    setSaturationValue(90);
    setPheromoneValue(cantidad);
    setEvaporationRate(1);
    setAngle(angle);
//    canPaint = true;
    circunferencia = QRectF(-3, -3, 6, 6);
    textRect = QRectF(circunferencia.x()-15, circunferencia.y()-20, 40, 20);
    tmrEvaporation.start(1000);

    connect(&tmrEvaporation, SIGNAL(timeout()), SLOT(evaporatePheromone()));
}

QRectF ec_gui::PheromoneItem::calculateTextRect(const QString &str, const QFont &font, const QRectF &referencia)
{
//    QFont font("arial", 7);
    QFontMetricsF txtMetrics(font);
    QRectF tmpRect = txtMetrics.boundingRect(str);
    return tmpRect.translated(-tmpRect.width()/2, referencia.y() - tmpRect.height());
}

void ec_gui::PheromoneItem::setPheromoneValue(int val)
{
    if(val <= saturationValue && val >= 0)
        pheromoneValue = val;
    else if(val < 0)
        pheromoneValue = 0;
    else
        pheromoneValue = saturationValue;
}

int ec_gui::PheromoneItem::getPheromoneValue()
{
    return pheromoneValue;
}

void ec_gui::PheromoneItem::setSaturationValue(int val)
{
    saturationValue = val;
}

int ec_gui::PheromoneItem::getSaturationValue()
{
    return saturationValue;
}

void ec_gui::PheromoneItem::incrementPheromoneValue(int val)
{
    if(pheromoneValue + val < saturationValue){
        pheromoneValue += val;
    }else{
        pheromoneValue = saturationValue;
    }
}

void ec_gui::PheromoneItem::decrementPheromoneValue(int val)
{
    if(pheromoneValue - val > 0){
        pheromoneValue -= val;
    }else{
        pheromoneValue = 0;
    }
}

void ec_gui::PheromoneItem::setAngle(double ang)
{
    angle = ang;
}

double ec_gui::PheromoneItem::getAngle()
{
    return angle;
}

void ec_gui::PheromoneItem::setEvaporationRate(int val)
{
    evaporationRate = val;
}

int ec_gui::PheromoneItem::getEvaporationRate()
{
    return evaporationRate;
}

void ec_gui::PheromoneItem::addLastPheromone(PheromoneItem *pi)
{
    if(pi){
//        if(lastPheromones.count() > 0){
            if(!lastPheromones.contains(pi)){
                lastPheromones.append(pi);
                connect(pi, SIGNAL(pheromoneDeleted(PheromoneItem*)), SLOT(pheromoneHasDeleted(PheromoneItem*)));
            }
//        }
    }
}

void ec_gui::PheromoneItem::deleteLastPheromone(PheromoneItem *pi)
{
    if(lastPheromones.count() > 0){
        if(lastPheromones.contains(pi)){
            lastPheromones.removeOne(pi);
        }
    }
}

QList<ec_gui::PheromoneItem *> ec_gui::PheromoneItem::getLastPheromones()
{
    return lastPheromones;
}

ec_gui::PheromoneItem *ec_gui::PheromoneItem::getMostIntenseNeighbour()
{
    int minVal = 9999999;
    int piCount = lastPheromones.count();
    int curMinVal;
    PheromoneItem *lastPI = NULL;
    for(int i = 0; i < piCount; i++){
        curMinVal = lastPheromones[i]->getPheromoneValue();
        if(curMinVal < minVal){
            lastPI = lastPheromones[i];
            minVal = curMinVal;
        }
    }
    return lastPI;
}

//bool PheromoneItem::operator==(const PheromoneItem &pi1)
//{
//    return (this == &pi1);
//}

void ec_gui::PheromoneItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);

    setZValue(9999999);
    update();
}

QPainterPath ec_gui::PheromoneItem::shape() const
{
    QPainterPath path;
    path.addEllipse(circunferencia);
    return path;
}

QRectF ec_gui::PheromoneItem::boundingRect() const
{
    QPainterPath path;
    path.addRect(circunferencia);
    path.addRect(textRect);
    return path.controlPointRect();
}

void ec_gui::PheromoneItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QColor color(0, 255, 0);

    if(option->state & (QStyle::State_Selected | QStyle::State_MouseOver)){
        color = color.darker(200);
    }

    if(option->state & (QStyle::State_MouseOver)){
//        QString string = "(" + QString::number(pheromoneValue) + ", " + QString::number(angle) + ")";


        QString string;
        QPointer<PheromoneItem> pi = getMostIntenseNeighbour();
        if(pi != NULL){
            string = "(" + QString::number(pheromoneValue) + ", " + QString::number(x()) + ", " + QString::number(y()) + ", " + QString::number(pi->x()) + ", " + QString::number(pi->y()) + ")";
        }else{
            string = "(" + QString::number(pheromoneValue)  + ", " + QString::number(x()) + ", " + QString::number(y()) + ", " + QString::number(0) + ", " + QString::number(0) + ")";
        }
        QFont font("arial", 7);
        textRect = calculateTextRect(string, font, circunferencia);
        painter->setFont(font);
        painter->save();
        painter->setPen(Qt::NoPen);
        painter->setBrush(QColor(100, 255, 100));
        painter->drawRect(textRect.adjusted(-2, -2, 2, 2));
        painter->restore();
        painter->drawText(textRect, string);
    }
    painter->save();
    painter->setBrush(color);
    painter->drawEllipse(circunferencia);
    painter->restore();
}

void ec_gui::PheromoneItem::evaporatePheromone()
{
    if(pheromoneValue - evaporationRate > 0){
        decrementPheromoneValue(evaporationRate);
        update();
    }else{
//        canPaint = false;
        QGraphicsScene *esc = scene();
        if(esc){
            esc->removeItem(this);
//            lastPheromones.clear();
        }
        emit pheromoneDeleted(this);
        disconnect();
        delete this;
    }
}

void ec_gui::PheromoneItem::pheromoneHasDeleted(PheromoneItem *pi)
{
    deleteLastPheromone(pi);
}

