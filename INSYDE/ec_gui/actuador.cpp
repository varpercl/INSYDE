#include "actuador.h"

ec_gui::Actuator::Actuator(Agent *agent)
{
    setAgent(agent);
}

void ec_gui::Actuator::setAgent(Agent *agent)
{
    this->agent = agent;
}

ec_gui::Agent *ec_gui::Actuator::getAgent()
{
    return agent;
}

void ec_gui::Actuator::setShape(const QPainterPath &shape)
{
    this->shape = shape;
}

QPainterPath ec_gui::Actuator::getShape() const
{
    return shape;
}

void ec_gui::Actuator::secureStartTimer(int &id, int interval)
{
    if(!id){
        id = startTimer(interval);
    }else{
        qWarning("Este id parece estar ya asignado");
    }
}

void ec_gui::Actuator::secureKillTimer(int &id)
{
    if(id){
        killTimer(id);
        id = 0;
    }
}
