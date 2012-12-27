#ifndef REGLA_H
#define REGLA_H

#include <QtCore>

typedef void* Action;
typedef QMap<QString, void*> Parameters;

/**
  @class Rule
  @author Edixon Vargas
  @date 08-06-2012

  La clase @code{Rule} establece una regla para un agente o grupo de agentes especificos, esta clase es la base para
  generar un comportamiento en los agentes.

  */
class Rule
{
    private:
        Action (*ac)(Parameters par);
        bool cond;
        Parameters param;

    public:
        explicit Rule(bool condicion, Action (*accion)(Parameters));

        void ejecutarRegla();
};

#endif // REGLA_H
