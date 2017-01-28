#include "agent.h"

ec_gui::Agent::Agent(){
    iniciarTodo(10);
}

ec_gui::Agent::Agent(double radio){
    iniciarTodo(radio);
}

void ec_gui::Agent::iniciarTodo(double radio){
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

void ec_gui::Agent::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
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

QRectF ec_gui::Agent::boundingRect() const{
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

QPainterPath ec_gui::Agent::shape() const{
    QPainterPath path(forma);
//    foreach(Actuador *actuador, actuadores){
//        path.addPath(actuador->getShape());
//    }
    return path;
}

QPainterPath ec_gui::Agent::radialShape() const
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

void ec_gui::Agent::setBorderWidth(int w)
{
    borderWidth = w;
}

int ec_gui::Agent::getBorderWidth() const
{
    return borderWidth;
}

void ec_gui::Agent::secureStartTimer(int &id, int interval)
{
    if(id == 0){
        id = startTimer(interval);
    }
}

void ec_gui::Agent::secureKillTimer(int &id)
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

void ec_gui::Agent::setRadius(double rad){
    radioAgente = rad;
}

void ec_gui::Agent::setAbstractFigureVisible(bool vis)
{
    figuraAbstractaVisible = vis;
}

bool ec_gui::Agent::getAbstractFigureVisible()
{
    return figuraAbstractaVisible;
}

void ec_gui::Agent::setActuatorsShapeVisible(bool vis)
{
    actuatorsShapeVisible = vis;
}

bool ec_gui::Agent::getActuatorsShapeVisible()
{
    return actuatorsShapeVisible;
}

void ec_gui::Agent::addSensor(QString nombre, Sensor *sensor){
    if(!sensores.contains(nombre))
        sensores.insert(nombre, sensor);
}

void ec_gui::Agent::deleteSensor(QString nombre)
{
    if(!sensores.contains(nombre)) return;
        sensores.remove(nombre);
}

ec_gui::Sensor *ec_gui::Agent::getSensor(QString nombre)
{
    if(sensores.contains(nombre))
        return sensores.value(nombre);
    else
        return NULL;
}

void ec_gui::Agent::setSensors(QMap<QString, Sensor *> sensores)
{
    this->sensores = sensores;
}

QMap<QString, ec_gui::Sensor*> &ec_gui::Agent::getSensors(){
    return sensores;
}

void ec_gui::Agent::addActuator(QString nombre, Actuator *actuador)
{
    if(!actuadores.contains(nombre))
        actuadores.insert(nombre, actuador);
    else
        qWarning() << "La clave: " << nombre << " ya existe";
}

void ec_gui::Agent::deleteActuator(QString nombre)
{
    if(actuadores.contains(nombre))
        actuadores.remove(nombre);
}

ec_gui::Actuator *ec_gui::Agent::getActuator(QString nombre)
{
    if(actuadores.contains(nombre))
        return actuadores.value(nombre);
    else return NULL;
}

void ec_gui::Agent::setActuators(QMap<QString, Actuator *> actuadores)
{
    this->actuadores = actuadores;
}

QMap<QString, ec_gui::Actuator *> &ec_gui::Agent::getActuators()
{
    return actuadores;
}

void ec_gui::Agent::setShape(const QPainterPath &fig)
{
    forma = fig;
}

void ec_gui::Agent::setName(QString nombre){
    Q_UNUSED(nombre);
}

QString ec_gui::Agent::getName(){
    return "";
}

void ec_gui::Agent::checkRules(){

}
