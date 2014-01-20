#include "meleeunit.h"

MeleeUnit::MeleeUnit()
{
}

void MeleeUnit::initMU(){

}

void MeleeUnit::attackTo(Unit *ag)
{
    Q_UNUSED(ag)
}

void MeleeUnit::attackTo(const QPointF &pt)
{
    Q_UNUSED(pt)
}

QPainterPath MeleeUnit::shape() const
{
    QPainterPath shape = Unit::shape();
    return shape;
}

QRectF MeleeUnit::boundingRect()
{
    QRectF rect = Unit::boundingRect();
    return rect;
}

void MeleeUnit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Unit::paint(painter, option, widget);
}
