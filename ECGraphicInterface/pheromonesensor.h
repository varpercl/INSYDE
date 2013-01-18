#ifndef PHEROMONESENSOR_H
#define PHEROMONESENSOR_H

#include <ECGraphicInterface_global.h>
#include <sensor.h>

/**
  @class PheromoneSensor
  @author Edixon Vargas
  @date 08-06-2012

  La clase @code{PheromoneSensor} es un tipo especial de sensor que detecta feromonas en el ambiente.
  Se usa por lo general cuando hay agentes en el ambiente que depositan feromonas.

  */
class ECGRAPHICINTERFACESHARED_EXPORT PheromoneSensor : public Sensor
{
	public:
		explicit PheromoneSensor();
};

#endif // PHEROMONESENSOR_H
