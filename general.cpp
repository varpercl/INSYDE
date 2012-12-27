#include <insydefunctions.h>

using namespace INSYDEFunctions;

double INSYDEFunctions::distanceBetweenUnits(const Agent &agent1, const Agent &agent2)
{
    return hypot(agent1.x()-agent2.x(), agent1.y() - agent2.y());
}

double INSYDEFunctions::distanceBetweenPoints(const QPointF &pt1, const QPointF &pt2)
{
    return hypot(pt1.x() - pt2.x(), pt1.y() - pt2.y());
}

double INSYDEFunctions::trunkedValue(double val, double divisor){
    double integer;
    modf(val/divisor, &integer);
    return integer*divisor;
}

double INSYDEFunctions::roundedValue(double val, double divisor){
    return round(val/divisor)*divisor;
}
