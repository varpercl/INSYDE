#include "sensor.h"

Sensor::Sensor(Agent *agent) : QObject(){
    setAgent(agent);
}

void Sensor::setAgent(Agent *agent)
{
    this->agent = agent;
}

Agent *Sensor::getAgent()
{
    return this->agent;
}

QPainterPath Sensor::shape() const
{
    return QPainterPath();
}



//virtual void Sensor::setTiempoActualizacion(int mil){
//    temporizador.setInterval(mil);
//}

//virtual void Sensor::getTiempoActualizacion(){
//    return temporizador.interval();
//}
