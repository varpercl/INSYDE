#include "actuador.h"

Actuator::Actuator(Agent *agent)
{
    setAgent(agent);
}

void Actuator::setAgent(Agent *agent)
{
    this->agent = agent;
}

Agent *Actuator::getAgent()
{
    return agent;
}

void Actuator::setShape(const QPainterPath &shape)
{
    this->shape = shape;
}

QPainterPath Actuator::getShape() const
{
    return shape;
}

void Actuator::secureStartTimer(int &id, int interval)
{
    if(!id){
        id = startTimer(interval);
    }else{
        qWarning("Este id parece estar ya asignado");
    }
}

void Actuator::secureKillTimer(int &id)
{
    if(id){
        killTimer(id);
        id = 0;
    }
}
