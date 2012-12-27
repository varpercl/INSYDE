#include "sensordistancia.h"

VisionSensor::VisionSensor(Agent *agente) : Sensor(agente){
    iniciarSensor(agente, 80, 0, 360);
}

VisionSensor::VisionSensor(Agent *agente, double alcance) : Sensor(agente){
    iniciarSensor(agente, alcance, 0, 360);
}

VisionSensor::VisionSensor(Agent *agente, double alcance, double angulo) : Sensor(agente){
    iniciarSensor(agente, alcance, angulo/2, 360 - (angulo/2));
}

VisionSensor::VisionSensor(Agent *agente, double alcance, double anginf, double angsup) : Sensor(agente){
    iniciarSensor(agente, alcance, anginf, angsup);
}

void VisionSensor::iniciarSensor(Agent *agente, double alcance, double anginf, double angsup){
//    angulo = modf(((i*360/inc) + anguloAgente)/360, new double)*360;
    this->scope = alcance;
    infAngle = anginf;
    supAngle = angsup;
    setAgent(agente);
//    escena = agente->scene();
}

void VisionSensor::setVisionRange(double al){
    scope = al;
}

double VisionSensor::getVisionRange(){
    return scope;
}

void VisionSensor::setCoverAngle(double inf, double sup){
    infAngle = inf;
    supAngle = sup;
}

double VisionSensor::getAverageDistanceToAgents(){
    Agent *agente = getAgent();
    QList<QGraphicsItem*> items = agente->scene()->items(getCoverArea());
    double dist = 0;
    foreach(QGraphicsItem *item, items){
        if(item != agente){
            dist += hypot(agente->x()-item->x(), agente->y()-item->y());
        }
    }
    int nItems = items.count();
    dist /= (nItems > 1 ? nItems - 1 : 1);
    return dist;
}

double VisionSensor::getAverageManhattanDistanceToAgents(){
    Agent *agente = getAgent();
    QList<QGraphicsItem*> items = agente->scene()->items(getCoverArea());
//    QPointF dAg = agente->mapToScene(agente->pos());
    double dist = 0;
    foreach(QGraphicsItem *item, items){
        if(item != agente){
            dist += (agente->pos() - item->pos()).manhattanLength();
        }
    }
    int nItems = items.count();
    dist /= (nItems > 1 ? nItems - 1 : 1);
    return dist;
}

QList<DistanciaAgente*> VisionSensor::getDistanceToAgents(){
    Agent *agente = getAgent();
    QList<QGraphicsItem*> items = agente->scene()->items(getCoverArea());
    QList<DistanciaAgente*> listpda;
    DistanciaAgente *pda = new DistanciaAgente();

    foreach(QGraphicsItem *item, items){
        if(item != agente){
            pda->second = hypot(agente->x()-item->x(), agente->y()-item->y());
            pda->first = dynamic_cast<Agent*>(item);
            listpda.append(pda);
        }
    }
    return listpda;
}

//QList<DistanciaAgente*> VisionSensor::getDistanciaMinimaAgentes(){
//    QList<DistanciaAgente*> distItem;

//    return distItem;
//}

QList<DistanciaAgente*> VisionSensor::getManhattanDistanceToAgents(){
    Agent *agente = getAgent();
    QList<QGraphicsItem*> items = agente->scene()->items(getCoverArea());
    QList<DistanciaAgente*> listpda;
    DistanciaAgente *pda = new DistanciaAgente;

    foreach(QGraphicsItem *item, items){
        if(item != agente){
            pda->second = agente->pos().manhattanLength();
            pda->first = dynamic_cast<Agent*>(item);
            listpda.append(pda);
        }
    }
    return listpda;
}

double VisionSensor::getDistanceToAgent(Agent *ag){
    double distItem;
    Agent *agente = getAgent();
    distItem = hypot(agente->x() - ag->x(), agente->y() - ag->y());

    return distItem;
}

//double VisionSensor::getDistanciaMinimaAgente(Agent *ag){
//    Q_UNUSED(ag)
//    double distItem = 0;

//    return distItem;
//}

double VisionSensor::getManhattanDistanceToAgent(Agent *ag){
    double distItem;
    Agent *agente = getAgent();
    distItem = (agente->x() - ag->x()) + (agente->y() - ag->y());

    return distItem;
}

QList<Agent *> VisionSensor::getAgents()
{
    Agent *agente = getAgent();
    QList<QGraphicsItem*> items = agente->scene()->items(getCoverArea());
    QList<Agent*> agents;
    Agent* tmpAgent;
    int numItems = items.count();
    for(int i = 0; i < numItems; i++){
        if((tmpAgent = dynamic_cast<Agent*>(items[i]))){
            if(tmpAgent != agente){
                agents.append(tmpAgent);
            }
        }
    }
    return agents;
}

QPainterPath VisionSensor::getCoverArea(){
    Agent *agente = getAgent();
    double angulo = agente->rotation();
    QRectF rect(agente->x() - scope, agente->y() - scope, 2*scope, 2*scope);
    QPainterPath path(agente->pos());
    double difAng = (360 - supAngle + infAngle);
    if((difAng == 360 || difAng == 0) && infAngle != 0){
        path.addEllipse(rect);
    }else{
        path.arcTo(rect, supAngle-angulo, difAng);
        path.closeSubpath();
    }
    return path;
}
