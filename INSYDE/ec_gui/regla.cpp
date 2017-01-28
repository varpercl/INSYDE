#include "regla.h"

ec_gui::Rule::Rule(bool condicion, Action (*accion)(Parameters param))
{
    cond = condicion;
    ac = accion;
}

void ec_gui::Rule::ejecutarRegla()
{
    if(cond)
        ac(param);
}
