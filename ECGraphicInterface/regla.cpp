#include "regla.h"

Rule::Rule(bool condicion, Action (*accion)(Parameters param))
{
    cond = condicion;
    ac = accion;
}

void Rule::ejecutarRegla()
{
    if(cond)
        ac(param);
}
