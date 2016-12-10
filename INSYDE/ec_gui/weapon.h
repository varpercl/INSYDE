#ifndef WEAPON_H
#define WEAPON_H

#include "share_ec_gui.h"
#include "ofensiveunit.h"

/**
  @class Weapon
  @author Edixon Vargas
  @date 08-06-2012

  La clase @code{Weapon} es un tipo especial de actuador que le da propiedades a los agentes para poder atacar a otras unidades.
  Los agentes del tipo ShootingUnit u otros ofensivos deben tener este tipo de actuador.

  */
class EC_GUI_LIB_IMPORT_EXPORT Weapon : public Actuator
{
	public:
		explicit Weapon(OfensiveUnit *unit = 0);
};

#endif // WEAPON_H
