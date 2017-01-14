#include "pheromonedepositor.h"

ec_gui::PheromoneDepositor::PheromoneDepositor(MovilAgent *agent): Actuator(agent)
{
	initPDep(20);
}

ec_gui::PheromoneDepositor::PheromoneDepositor(MovilAgent *agent, int intensity) : Actuator(agent)
{
	initPDep(intensity);
}

void ec_gui::PheromoneDepositor::initPDep(int intensity){
	lastPheromoneItem = NULL;
//    timerCheckDistance.start(500);
	gridSpace = 50;
	pheromoneDistance = 30;
	setSaturationValue(60);
	setIntensity(intensity);
//    setInitialPosition(getAgent()->pos());
	connect(&timerCheckDistance, SIGNAL(timeout()), SLOT(timerCheckDistanceEvent()));
}

void ec_gui::PheromoneDepositor::placePheromoneItem(int intensity)
{

	Agent *ag = getAgent();
	PheromoneItem *tmpPI;
	QList<QGraphicsItem*> items;
	int numItems;
//    QGraphicsObject *obj;
	int tmpX = math::roundedMultiplo(ag->x(), gridSpace);
	int tmpY = math::roundedMultiplo(ag->y(), gridSpace);
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

double ec_gui::PheromoneDepositor::distanceToLastPheromone()
{
	return lastPheromoneItem ? math::distance(lastPheromoneItem->pos(), getAgent()->pos()) : NAN;
}

void ec_gui::PheromoneDepositor::placePheromoneItem(PheromoneItem *pi)
{
	Agent *ag = getAgent();
	PheromoneItem *tmpPI;
	QList<QGraphicsItem*> items;
	int numItems;
//    QGraphicsObject *obj;
	int tmpX = math::roundedMultiplo(ag->x(), gridSpace),
			tmpY = math::roundedMultiplo(ag->y(), gridSpace);
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

void ec_gui::PheromoneDepositor::setIntensity(int intensity)
{
	pheromoneIntensity = intensity;
}

int ec_gui::PheromoneDepositor::getIntensity()
{
	return pheromoneIntensity;
}

void ec_gui::PheromoneDepositor::setSaturationValue(int val)
{
	saturationValue = val;
}

int ec_gui::PheromoneDepositor::getSaturationValue()
{
	return saturationValue;
}

void ec_gui::PheromoneDepositor::startPlacePheromone()
{
	timerCheckDistance.start(500);
}

void ec_gui::PheromoneDepositor::stopPlacePheromone()
{
	timerCheckDistance.stop();
}

void ec_gui::PheromoneDepositor::timerCheckDistanceEvent()
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

