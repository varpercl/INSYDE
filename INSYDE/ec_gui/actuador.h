#ifndef ACTUADOR_H
#define ACTUADOR_H

#include <QtCore>

#include "share_ec_gui.h"
#include "agent.h"

/*!
 * \brief The ec_gui namespace enclose a lot of classes to handle graphic interpretation of
 * emerging computing algorithm, this namespace is almost totally dependent from ec_base
 * which means the core functionalities of this namespace.
 */
namespace ec_gui
{

class Agent;

/**
  @class Actuator
  @author Edixon Vargas
  @date 08-06-2012

  La clase @code{Actuator} es la base de todos los objetos que se pueden considerar un actuador, contiene todos
  los atributos y metodos necesarios para el funcionamiento basico en un entorno virtual.

  Un actuador realizara una accion en un agente, le asigna propiedades especiales que depende del tipo de actuador
  que se haya añadido.

  @see Sensor

  */
class EC_GUI_LIB_IMPORT_EXPORT Actuator : public QObject
{
		Q_OBJECT

		//Referencia al agente al cual pertenece este actuador
		Agent *agent;

		//Forma actual de este actuador (si tiene alguna)
		QPainterPath shape;

	public:
		/**
		  Construye un nuevo actuador indicandole como parametro el agente al cual pertenecera.
		  Aunque se puede crear un actuador sin un agente vinculado, esta practica no es recomendada.

		  @paragraph *agente Indica el agente al cual se le asignara este actuador
		  */
		explicit Actuator(Agent *agent = NULL);

		/**
		  Asigna manualmente el agente al cual pertenecera este actuador, inicialmente el constructor
		  asigna un agente automaticamente a menos que el parametro @code {agent} que se le haya pasado sea nulo

		  @param *agente Apuntador al agente al cual pertence este actuador

		  @see getAgent()
		  */
		void setAgent(Agent *agent);

		/**
		  Devuelve un puntero al agente al cual pertenece este actuador. En caso de que no este asignado a ningun
		  agente devolvera NULL

		  @return Agent* Puntero al agente al cual pertenece
		  */
		Agent *getAgent();

		/**
		  Algunos actuadores tienen alguna forma que modifica el dibujo del agente que lo referencia
		  Se puede personalizar esta forma usando esta funcion y estableciendo la forma personalizada

		  @param &shape Forma que se asignara

		  @see getShape
		  */
		void setShape(const QPainterPath &shape);

		/**
		  Devuelve la forma actual de este actuador si tiene alguna, en caso de que no posea ninguna solo devolvera
		  @code {QPainterPath()}
		  */
		virtual QPainterPath getShape() const;

	protected:

		/**
		  Arranque seguro del timer de este objeto. Se utiliza para validar si se ha inicializado
		  este timer con el @code{id} especifico

		  @param &id ID del timer que se quiere iniciar, si ID es 0 se inicializa el timer, en caso contrario no se hace
		  y se arroja un Warning

		  @see secureKillTimer
		  */
		virtual void secureStartTimer(int &id, int interval);

		/**
		  Destruye de manera segura un timer previamente inicializado con un @code {id}

		  @param &id ID del timer que se quiere destruir

		  @see secureStartTimer
		  */
		virtual void secureKillTimer(int &id);
};
}
#endif // ACTUADOR_H
