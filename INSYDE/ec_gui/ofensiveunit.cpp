#include "ofensiveunit.h"

ec_gui::OfensiveUnit::OfensiveUnit() : Unit(Human, Blue, None, 100, 100, 0, 0, 100, 70)
{
    initUnit(10, 1, 1);
}

ec_gui::OfensiveUnit::OfensiveUnit(PlayerType tj,
                           PlayerColor cr,
                           PlayerTeam eq,
                           int vitalidadMaxima,
                           int vitalidad,
                           int energiaMaxima,
                           int energy,
                           double alcanceVisual,
                           double rapidez) : Unit(tj, cr, eq, vitalidadMaxima, vitalidad, energiaMaxima, energy, alcanceVisual, rapidez)
{
    initUnit(10, 1, 1);
}

ec_gui::OfensiveUnit::OfensiveUnit(int attack, int defense, int attackVelocity, PlayerType tj,
                           PlayerColor cr,
                           PlayerTeam eq,
                           int vitalidadMaxima,
                           int vitalidad,
                           int energiaMaxima,
                           int energy,
                           double alcanceVisual,
                           double rapidez) : Unit(tj, cr, eq, vitalidadMaxima, vitalidad, energiaMaxima, energy, alcanceVisual, rapidez)
{
    initUnit(attack, defense, attackVelocity);
}

void ec_gui::OfensiveUnit::initUnit(int attack, int defense, int attackVelocity){
    Q_UNUSED(attack)
    Q_UNUSED(attackVelocity)

//    setMode(Stand);
//    setAttack(attack);
    setDefense(defense);
    //    setAttackVelocity(attackVelocity);

    mov = dynamic_cast<MovingActuator*>(getActuator("movement"));
    connect(mov, SIGNAL(checkPointReached(QPointF)), SLOT(checkPointReached(QPointF)));
//    connect(mov, SIGNAL(positionChanged(QPointF)), SLOT(checkAll(QPointF)));
}

//void OfensiveUnit::setAttack(int att)
//{
//    attack = att;
//}

//int OfensiveUnit::getAttack()
//{
//    return attack;
//}

void ec_gui::OfensiveUnit::setDefense(int defense)
{
    this->defense = defense;
}

int ec_gui::OfensiveUnit::getDefense()
{
    return defense;
}

void ec_gui::OfensiveUnit::startAttackMode()
{
}

void ec_gui::OfensiveUnit::unitHasKilled(Unit *un)
{
    Q_UNUSED(un)
}

//void OfensiveUnit::setAttackVelocity(int av)
//{
//    attackVelocity = av;
//}

//int OfensiveUnit::getAttackVelocity()
//{
//    return attackVelocity;
//}

//QPainterPath OfensiveUnit::shape() const
//{
//    QPainterPath ppU = Unidad::shape();

//    return ppU;
//}

//QRectF OfensiveUnit::boundingRect() const
//{
//    QRectF recUnit = Unidad::boundingRect();

//    return recUnit;
//}

//void OfensiveUnit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    Unidad::paint(painter, option, widget);


//}
