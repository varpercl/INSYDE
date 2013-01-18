#include "ECFunctions.h"

double ECFunctions::distanceBetweenUnits(const Agent &agent1, const Agent &agent2)
{
	return hypot(agent1.x()-agent2.x(), agent1.y() - agent2.y());
}
