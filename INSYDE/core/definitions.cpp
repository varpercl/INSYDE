#include "definitions.h"

void initCoreResources()
{
    Q_INIT_RESOURCE(core_media); //At least in linux, never call this inside user namespace, instead use a wrapper function
}
