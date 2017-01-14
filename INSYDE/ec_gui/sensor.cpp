#include "sensor.h"

ec_gui::Sensor::Sensor(Agent *agent) : QObject(){
    setAgent(agent);
}

void ec_gui::Sensor::setAgent(Agent *agent)
{
    this->agent = agent;
}

ec_gui::Agent *ec_gui::Sensor::getAgent()
{
    return this->agent;
}

QPainterPath ec_gui::Sensor::shape() const
{
    return QPainterPath();
}



//virtual void Sensor::setTiempoActualizacion(int mil){
//    temporizador.setInterval(mil);
//}

//virtual void Sensor::getTiempoActualizacion(){
//    return temporizador.interval();
//}
