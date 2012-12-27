#include "pheromonedepositor.h"

PheromoneDepositor::PheromoneDepositor(MovilAgent *agent): Actuator(agent)
{
    initPDep(20);
}

PheromoneDepositor::PheromoneDepositor(MovilAgent *agent, int intensity) : Actuator(agent)
{
    initPDep(intensity);
}

void PheromoneDepositor::initPDep(int intensity){
    lastPheromoneItem = NULL;
//    timerCheckDistance.start(500);
    gridSpace = 50;
    pheromoneDistance = 30;
    setSaturationValue(60);
    setIntensity(intensity);
//    setInitialPosition(getAgent()->pos());
    connect(&timerCheckDistance, SIGNAL(timeout()), SLOT(timerCheckDistanceEvent()));
}

void PheromoneDepositor::placePheromoneItem(int intensity)
{

    Agent *ag = getAgent();
    PheromoneItem *tmpPI;
    QList<QGraphicsItem*> items;
    int numItems;
//    QGraphicsObject *obj;
    int tmpX = roundedValue(ag->x(), gridSpace);
    int tmpY = roundedValue(ag->y(), gridSpace);
    bool putNewPheromone = true;

    items = ag->scene()->items(QPointF(tmpX, tmpY));
    numItems = items.count();
    for(int i = 0; i < numItems; i++){
        if((tmpPI = dynamic_cast<PheromoneItem*>(items[i]))){
            tmpPI->incrementPheromoneValue(pheromoneIntensity);
            if(lastPheromoneItem != NULL && tmpPI != lastPheromoneItem){
                tmpPI->addLastPheromone(lastPheromoneItem);
            }
            lastPheromoneItem = tmpPI;
            putNewPheromone = false;
            break;
        }else{
            putNewPheromone = true;
        }
    }
    if(putNewPheromone){
        PheromoneItem *pi = new PheromoneItem(intensity);
        pi->setPos(tmpX, tmpY);
        if(lastPheromoneItem != NULL){
            pi->addLastPheromone(lastPheromoneItem);
        }
        lastPheromoneItem = pi;
        ag->scene()->addItem(pi);
    }
}

//void PheromoneDepositor::placePheromoneItem(double angle)
//{
//    lastPheromoneItem = new PheromoneItem(getIntensity());
//    placePheromoneItem(lastPheromoneItem);
//}

double PheromoneDepositor::distanceToLastPheromone()
{
    return lastPheromoneItem ? distanceBetweenPoints(lastPheromoneItem->pos(), getAgent()->pos()) : NAN;
}

void PheromoneDepositor::placePheromoneItem(PheromoneItem *pi)
{
    Agent *ag = getAgent();
    PheromoneItem *tmpPI;
    QList<QGraphicsItem*> items;
    int numItems;
//    QGraphicsObject *obj;
    int tmpX = roundedValue(ag->x(), gridSpace),
            tmpY = roundedValue(ag->y(), gridSpace);
    bool putNewPheromone = true;

    items = ag->scene()->items(QPointF(tmpX, tmpY));
    numItems = items.count();
    for(int i = 0; i < numItems; i++){
        if((tmpPI = dynamic_cast<PheromoneItem*>(items[i]))){
            tmpPI->incrementPheromoneValue(pheromoneIntensity);
            if(lastPheromoneItem){
                tmpPI->addLastPheromone(lastPheromoneItem.data());
            }
            lastPheromoneItem = tmpPI;
            putNewPheromone = false;
            delete pi;
            break;
        }else{
            putNewPheromone = true;
        }
    }
    if(putNewPheromone){
        pi->setPos(tmpX, tmpY);
//        if(!lastPheromoneItem.isNull()){
            pi->addLastPheromone(lastPheromoneItem.data());
//        }
        ag->scene()->addItem(pi);
    }
}

//void PheromoneDepositor::setInitialPosition(const QPointF &pos)
//{
//    initialPosition = pos;
//}

//QPointF PheromoneDepositor::getInitialPos()
//{
//    return initialPosition;
//}

void PheromoneDepositor::setIntensity(int intensity)
{
    pheromoneIntensity = intensity;
}

int PheromoneDepositor::getIntensity()
{
    return pheromoneIntensity;
}

void PheromoneDepositor::setSaturationValue(int val)
{
    saturationValue = val;
}

int PheromoneDepositor::getSaturationValue()
{
    return saturationValue;
}

void PheromoneDepositor::startPlacePheromone()
{
    timerCheckDistance.start(500);
}

void PheromoneDepositor::stopPlacePheromone()
{
    timerCheckDistance.stop();
}

void PheromoneDepositor::timerCheckDistanceEvent()
{
    MovilAgent *ag = dynamic_cast<MovilAgent*>(getAgent());
//    PheromoneItem *pi;
    if(ag->isMoving()){
        if(lastPheromoneItem){
            if(distanceToLastPheromone() >= pheromoneDistance){
                placePheromoneItem(pheromoneIntensity);
            }
        }else{
            placePheromoneItem(pheromoneIntensity);
        }
    }
}

