#include "agent.h"

Agent::Agent(){
    iniciarTodo(10);
}

Agent::Agent(double radio){
    iniciarTodo(radio);
}

void Agent::iniciarTodo(double radio){
    forma.addEllipse(QRectF(-radio, -radio, radio*2, radio*2));
    radioAgente = radio;
    setBorderWidth(2);
    setAbstractFigureVisible(true);
    setActuatorsShapeVisible(true);
    setFlags(ItemIsSelectable|
//             ItemClipsToShape|
//             ItemIsMovable|
             ItemIsFocusable);
    setCacheMode(NoCache);
    setColor(QColor(127, 127, 255));
}

void Agent::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(widget);

    if(figuraAbstractaVisible){
        QRadialGradient grad(-3, -3, radioAgente);
        if(option->state & QStyle::State_Selected){
            grad.setColorAt(1, color.lighter());
        }else{
            grad.setColorAt(1, color);
        }
        grad.setColorAt(0, Qt::white);

        painter->save();
        QPen penForma(Qt::black);
        penForma.setWidth(borderWidth);
        QBrush brush(grad);
        painter->setPen(penForma);
        painter->setBrush(brush);
        painter->drawPath(forma);

        if(actuatorsShapeVisible){
            foreach(Actuator *actuador, actuadores){
                painter->drawPath(actuador->getShape());
            }
        }

        painter->restore();
    }


//    painter->drawRect(boundingRect());
}

QRectF Agent::boundingRect() const{
    double medioBorde = borderWidth/2;
    QPainterPath path;
    path.addPath(forma);
    if(actuatorsShapeVisible){
        foreach(Actuator *actuador, actuadores){
            path.addPath(actuador->getShape());
        }
    }
    return path.controlPointRect().adjusted(-medioBorde, -medioBorde, medioBorde, medioBorde);
}

QPainterPath Agent::shape() const{
    QPainterPath path(forma);
//    foreach(Actuador *actuador, actuadores){
//        path.addPath(actuador->getShape());
//    }
    return path;
}

QPainterPath Agent::radialShape() const
{
    QPainterPath circulo;
    double radio = Vector2D(forma.controlPointRect().center(), forma.controlPointRect().topLeft()).getModulo();
    circulo.addEllipse(-radio, -radio, radio*2, radio*2);
    return circulo;
}

//void Agent::setUpdateInterval(int udi)
//{
//    updateInterval = udi;
//}

//int Agent::getUpdateInterval()
//{
//    return updateInterval;
//}

void Agent::setBorderWidth(int w)
{
    borderWidth = w;
}

int Agent::getBorderWidth() const
{
    return borderWidth;
}

void Agent::secureStartTimer(int &id, int interval)
{
    if(id == 0){
        id = startTimer(interval);
    }
}

void Agent::secureKillTimer(int &id)
{
    if(id != 0){
        killTimer(id);
        id = 0;
    }
}

//void Agent::setColor(QColor col)
//{
//    color = col;
//}

void Agent::setRadius(double rad){
    radioAgente = rad;
}

void Agent::setAbstractFigureVisible(bool vis)
{
    figuraAbstractaVisible = vis;
}

bool Agent::getAbstractFigureVisible()
{
    return figuraAbstractaVisible;
}

void Agent::setActuatorsShapeVisible(bool vis)
{
    actuatorsShapeVisible = vis;
}

bool Agent::getActuatorsShapeVisible()
{
    return actuatorsShapeVisible;
}

void Agent::addSensor(QString nombre, Sensor *sensor){
    if(!sensores.contains(nombre))
        sensores.insert(nombre, sensor);
}

void Agent::deleteSensor(QString nombre)
{
    if(!sensores.contains(nombre)) return;
        sensores.remove(nombre);
}

Sensor *Agent::getSensor(QString nombre)
{
    if(sensores.contains(nombre))
        return sensores.value(nombre);
    else
        return NULL;
}

void Agent::setSensors(QMap<QString, Sensor *> sensores)
{
    this->sensores = sensores;
}

QMap<QString, Sensor*> &Agent::getSensors(){
    return sensores;
}

void Agent::addActuator(QString nombre, Actuator *actuador)
{
    if(!actuadores.contains(nombre))
        actuadores.insert(nombre, actuador);
    else
        qWarning() << "La clave: " << nombre << " ya existe";
}

void Agent::deleteActuator(QString nombre)
{
    if(actuadores.contains(nombre))
        actuadores.remove(nombre);
}

Actuator *Agent::getActuator(QString nombre)
{
    if(actuadores.contains(nombre))
        return actuadores.value(nombre);
    else return NULL;
}

void Agent::setActuators(QMap<QString, Actuator *> actuadores)
{
    this->actuadores = actuadores;
}

QMap<QString, Actuator *> &Agent::getActuators()
{
    return actuadores;
}

void Agent::setShape(const QPainterPath &fig)
{
    forma = fig;
}

void Agent::setName(QString nombre){

}

QString Agent::getName(){
    return "";
}

void Agent::checkRules(){

}
