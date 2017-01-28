#include "actuadormovimiento.h"

ec_gui::MovingActuator::MovingActuator(MovilAgent *agent){
    iniciarActuadorMovimiento(agent, 100, 0, 40);
}

ec_gui::MovingActuator::MovingActuator(MovilAgent *agent, double rapIni)
{
    iniciarActuadorMovimiento(agent, rapIni, 0, 40);
}

ec_gui::MovingActuator::MovingActuator(MovilAgent *agent, double rapIni, double angInicial)
{
    iniciarActuadorMovimiento(agent, rapIni, angInicial, 40);
}

ec_gui::MovingActuator::MovingActuator(MovilAgent *agent, double rapIni, double angInicial, double sensibilidad)
{
    iniciarActuadorMovimiento(agent, rapIni, angInicial, sensibilidad);
}

ec_gui::MovingActuator::~MovingActuator()
{
//    disconnect();
//    movimiento->disconnect();
//    delete movimiento;
    stop();
}

//void ActuadorMovimiento::setTolerancia(qreal tol)
//{
//    tolerancia = tol;
//}

//qreal ActuadorMovimiento::getTolerancia()
//{
//    return 0;
//}

void ec_gui::MovingActuator::setRapidez(double vel)
{
    rapidez = vel;
}

double ec_gui::MovingActuator::getRapidez()
{
    return rapidez;
}

//void ActuadorMovimiento::setVectorVelocidad(Vector2D vector)
//{
//    rapidez = vector.getModulo();
//    theta = vector.getAngle();
//    agente->setDireccionRads(theta);
//}

//Vector2D ActuadorMovimiento::getVectorVelocidad()
//{
//    return Vector2D(rapidez, theta);
//}

void ec_gui::MovingActuator::iniciarActuadorMovimiento(MovilAgent *ag, double rapInicial, double angInicial, double sensibilidad){
    movimiento = 0;
    countChanges = 0;

    setSensibilidad(sensibilidad);
    setRapidez(rapInicial);
    setDetectColitions(false);

    agent = ag;
    agent->setDirection(angInicial);
//    intentosMovimiento = 0;
//    setTolerancia(tol);
//    escena = agente->scene();

//    connect(movimiento, SIGNAL(updateCurrentValue(QVariant)), this, SLOT(cambioValor(QVariant)));

}

void ec_gui::MovingActuator::moverA(double x, double y){
    if(agent != NULL){
        Vector2D vel(agent->pos(), QPointF(x, y));
        double distancia = vel.getModulo();
        if(distancia != 0){
            double angulo = vel.getAngle();
            agent->setDirectionRads(angulo);

            int tiempo = 1000 * distancia / rapidez;
            movimiento = new QPropertyAnimation(agent, "pos");
//            movimiento->moveToThread(new QThread());
            movimiento->setStartValue(agent->pos());
            movimiento->setEndValue(QPointF(x, y));
            movimiento->setDuration(tiempo);
            movimiento->start(movimiento->DeleteWhenStopped);

            connect(movimiento, SIGNAL(finished()), this, SLOT(checkPointHasBeenReached()));
            connect(movimiento, SIGNAL(valueChanged(QVariant)), this, SLOT(posChanged(QVariant)));

            escena = agent->scene();
        }else{
            movimiento = NULL;
        }
    }
}

void ec_gui::MovingActuator::moverA(const QPointF &pt){
    moverA(pt.x(), pt.y());
}

void ec_gui::MovingActuator::moverA(const QQueue<QPointF> &posiciones){
    destinos = posiciones;
    moverA(destinos.first());
}

void ec_gui::MovingActuator::addPoint(double x, double y)
{
    addPoint(QPointF(x, y));
}

void ec_gui::MovingActuator::addPoint(const QPointF &pt)
{
    destinos.enqueue(pt);
    moverA(destinos.first());
}

QQueue<QPointF> ec_gui::MovingActuator::getPoints()
{
    return destinos;
}

void ec_gui::MovingActuator::clearPoints()
{
    if(!destinos.isEmpty()){
        destinos.clear();
        if(movimiento != NULL){
            stop();
        }
    }
}

//QPropertyAnimation *ActuadorMovimiento::getAnimator()
//{
//    return movimiento;
//}

void ec_gui::MovingActuator::setSensibilidad(double sens)
{
    sensibilidad = sens;
}

double ec_gui::MovingActuator::getSensibilidad()
{
    return sensibilidad;
}

QPainterPath ec_gui::MovingActuator::getTrayectoria()
{
    if(agent != NULL){
        QPointF posAgente = agent->pos();
        path = QPainterPath(posAgente);
        foreach(QPointF i, destinos){
            path.lineTo(i);
            path.addEllipse(i, 5.0, 5.0);
            path.moveTo(i);
        }
        return path;
    }
    return QPainterPath();
}

void ec_gui::MovingActuator::checkPointHasBeenReached(){
    if(!destinos.isEmpty() && agent != NULL){
        if(agent->pos() == destinos.first()){
            destinos.dequeue();
        }
        if(destinos.empty()){
            stop();
            emit llegoADestinoFinal(agent->pos());
        }else{
            moverA(destinos.first());
        }
        emit checkPointReached(agent->pos());
    }else{
        stop();
    }
}

void ec_gui::MovingActuator::posChanged(QVariant valor)
{
//    signal(SIGSEGV, signalController);
    if(agent != NULL){
        emit positionChanged(agent->pos());
        if(avoidColitions){
            if(countChanges >= 0){

                if(escena == NULL){
                    return;
                }
                int inc = 8;

                double angulo;
                QList<QGraphicsItem*> items;
                //            QGraphicsItem *itm;
                PheromoneItem *pi;
                int itemsCount;


                QPointF posAgente = valor.toPointF();
                double anguloAgente =  agent->getDirection();
                QRectF cuadroAgente = agent->shape().controlPointRect();
                double ancho = Vector2D(cuadroAgente.topLeft(), cuadroAgente.center()).getModulo() * 2;
                QRectF formaRectAgente = QRectF(posAgente.x() - ancho/2, posAgente.y() - ancho/2, ancho, ancho);
                Vector2D pos((float)(sensibilidad + formaRectAgente.height()/2), (float)0);

                //    QGraphicsScene *escena = agente->scene();;
                double distMinima = 9999999;
                double distPuntoActual;
                QPointF nextPoint;
                QPointF posTrans;

                bool puedeMover = false;
                for(int i = 0; i < inc; i++){
                    path = QPainterPath(posAgente);
                    angulo = modf(((i*360/inc) + anguloAgente)/360, new double)*360;
                    pos.setAngleDeg(angulo);
                    path.arcMoveTo(formaRectAgente, angulo + 90);
                    path.arcTo(formaRectAgente, angulo + 90, 180);
                    path.arcTo(formaRectAgente.translated(pos.getX(), -pos.getY()), angulo - 90, 180);
                    path.closeSubpath();

                    items = escena->items(path);
                    itemsCount = items.count();
                    for(int j = 0; j < itemsCount; j++){
                        if((pi = dynamic_cast<PheromoneItem*>(items[j]))){
                            itemsCount--;
                        }
                    }

                    if(itemsCount > 1){ //Si hay colision
                        continue;
                    }else{
                        if(i == 0){
                            return;
                        }else{
                            if(!destinos.isEmpty()){
                                posTrans = QPointF(pos.getX(), -pos.getY());
                                distPuntoActual = Vector2D(posAgente + posTrans, destinos.first()).getModulo();
                                distMinima = (distPuntoActual < distMinima ? distPuntoActual : distMinima);
                                if(distMinima == distPuntoActual){
                                    nextPoint = posAgente + posTrans;
                                    puedeMover = true;
                                }
                            }
                        }
                    }
                }
                if(puedeMover){
                    moverA(nextPoint);
                }


                //    else{
                //        if(intentosMovimiento > 200){
                //            clearDestinos();
                //        }else{
                //            intentosMovimiento++;
                //        }
                //    }
                countChanges = 0;
            }else{
                countChanges++;
            }
        }
    }
}

void ec_gui::MovingActuator::stop()
{
    if(movimiento != NULL){
        movimiento->disconnect();
        movimiento->stop();
        delete movimiento;
        movimiento = NULL;
    }
}

void ec_gui::MovingActuator::run()
{
    if(!destinos.isEmpty()){
        moverA(destinos.first());
    }
}

bool ec_gui::MovingActuator::isMoving()
{
    return (movimiento ? true : false);
}

void ec_gui::MovingActuator::setDetectColitions(bool detect)
{
    avoidColitions = detect;
}

bool ec_gui::MovingActuator::getDetectColitions()
{
    return avoidColitions;
}

//void signalController(int val){
//    Q_UNUSED(val)
////    ActuadorMovimiento::agente = NULL;
//    qDebug() << "Null Pointer";
//}
