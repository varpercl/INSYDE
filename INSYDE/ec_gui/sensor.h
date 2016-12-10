#ifndef SENSOR_H
#define SENSOR_H

#include <QtCore>
#include <QtGui>
#include <math.h>

#include "share_ec_gui.h"

class Agent;

/**
  @class Sensor
  @author Edixon Vargas
  @date 08-06-2012

  La clase @code{Sensor} es la base de todos los objetos que se pueden considerar un sensor, contiene todos
  los atributos y metodos necesarios para el funcionamiento basico en un entorno virtual.

  Un sensor alguna propiedad u objeto especial en un entorno, le asigna propiedades especiales que depende del tipo de sensor
  que se haya añadido.

  @see Actuator

  */
class EC_GUI_LIB_IMPORT_EXPORT Sensor : public QObject{

		Q_OBJECT

		//Puntero al agente al cual pertenece este sensor
		Agent *agent;

	public:

		/**
		  Construye un objeto sensor y lo asigna a @code{agent}

		  @param *agent Puntero al agente al cual se le asignara el sensor
		  */
		explicit Sensor(Agent *agent = 0);
//        virtual void setTiempoActualizacion(int mil);
//        virtual void getTiempoActualizacion();

		/**
		  Asigna este sensor a un agente @code{agent}.

		  @param *agent Puntero al agente que se va a asignar

		  @see getAgent
		  */
		void setAgent(Agent *agent);

		/**
		  Devuelve un puntero al agente propietario de este sensor.

		  @return Agent* Puntero al agente propietario.
		  */
		Agent *getAgent();

		/**
		  Devuelve la forma actual de este sensor, si tiene alguna. En caso
		  de no tenerla se devuelve @code{QPainterPath()}

		  @return QPainterPath Forma actual de este sensor
		  */
		virtual QPainterPath shape() const;
};

#endif // SENSOR_H
