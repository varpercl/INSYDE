#ifndef ANT_H
#define ANT_H

#include "ECFramework_global.h"

class ECFRAMEWORKSHARED_EXPORT Ant
{
	public:
		long int  *tour;
		char      *visited;
		long int  tour_length;

		explicit Ant();
};

#endif // ANT_H
