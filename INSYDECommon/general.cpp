#include "insydefunctions.h"

using namespace CommonFunctions;


double CommonFunctions::distanceBetweenPoints(const QPointF &pt1, const QPointF &pt2)
{
	return hypot(pt1.x() - pt2.x(), pt1.y() - pt2.y());
}

double CommonFunctions::trunkedValue(double val, double divisor){
	double integer;
	modf(val/divisor, &integer);
	return integer*divisor;
}

double CommonFunctions::roundedValue(double val, double divisor){
	return round(val/divisor)*divisor;
}
