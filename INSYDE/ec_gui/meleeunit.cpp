#include "meleeunit.h"

ec_gui::MeleeUnit::MeleeUnit()
{
}

void ec_gui::MeleeUnit::initMU(){

}

void ec_gui::MeleeUnit::attackTo(Unit *ag)
{
    Q_UNUSED(ag)
}

void ec_gui::MeleeUnit::attackTo(const QPointF &pt)
{
    Q_UNUSED(pt)
}

QPainterPath ec_gui::MeleeUnit::shape() const
{
    QPainterPath shape = Unit::shape();
    return shape;
}

QRectF ec_gui::MeleeUnit::boundingRect()
{
    QRectF rect = Unit::boundingRect();
    return rect;
}

void ec_gui::MeleeUnit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Unit::paint(painter, option, widget);
}
