#ifndef VISIONSENSOR_H
#define VISIONSENSOR_H

#include <QtCore>

#if QT_VERSION > 0x050000
#include <QtWidgets/QGraphicsScene>
#else
#include <QtGui>
#endif

#include "agent.h"
#include "sensor.h"

class Agent;
//class Sensor;

typedef QPair<Agent*, double> DistanciaAgente;

/**
  @class VisionSensor
  @author Edixon Vargas
  @date 08-06-2012

  La clase @code{VisionSensor} asigna propiedades de "vision" a un agente, permite detectar y contabilizar los objetos
  que se encuentran dentro de un rango especifico del sensor (dicho rango se puede cambiar), asimismo, permite calcular
  la distancia a los agentes, entre otras propiedades.

  @see MovingActuator

  */
class VisionSensor : public Sensor
{
		Q_OBJECT

//        QList<QGraphicsItem*> items;

		//Maxima distancia "visible" por el sensor
		double scope;

		/*
		 Indica el valor del angulo inferior del rango de vision del agente, un agente puede cubrir los 360 grados
		 o puede cubrir solamente angulo especifico
		 */
		double infAngle;

		/*
		  Similar al angulo inferior
		  */
		double supAngle;

		//Escena en la cual se encuentra el sensor
		QGraphicsScene *scene;

		//Area formada por el espacio cubierto por el rango visible del sensor
		QPainterPath *scopeArea;
//        Agent *agente;

		//Inicializa todas las variables miembro de este sensor
		void iniciarSensor(Agent *agente, double scope, double anginf, double angsup);

	public:

		/**
		  Crea una nueva instancia de este sensor de vision y lo asigna al agente @code{agente}

		  @param *agente Puntero al agente al cual se le asignara este sensor

		  */
		explicit VisionSensor(Agent *agente = 0);

		/**
		  Crea una nueva instancia de este sensor de vision y lo asigna al agente @code{agente}.
		  Ademas tambien le asigna un alcance maximo, por defecto el angulo cubierto es de 360 grados

		  @param *agente Puntero al agente al cual se le asignara este sensor
		  @param alcance Alcance visual maximo que tendra este sensor

		  */
		explicit VisionSensor(Agent *agente, double scope);

		/**
		  Crea una nueva instancia de este sensor de vision y lo asigna al agente @code{agente}.
		  Ademas tambien le asigna un alcance maximo, pero en este caso le asigna un angulo de cobertura.
		  El angulo cubierto va desde 360-(angulo/2) hasta angulo/2.

		  @param *agente Puntero al agente al cual se le asignara este sensor
		  @param alcance Alcance visual maximo que tendra este sensor
		  @param angulo Angulo que cubrira este sensor de vision

		  */
		explicit VisionSensor(Agent *agente, double scope, double angulo);

		/**
		  Crea una nueva instancia de este sensor de vision y lo asigna al agente @code{agente}.
		  Ademas tambien le asigna un alcance maximo, pero en este caso le asigna un angulo de cobertura.
		  El angulo puede ser asignado desde su punto inicial @code{anginf} hasta su punto final @code{angsup}.

		  @param *agente Puntero al agente al cual se le asignara este sensor
		  @param alcance Alcance visual maximo que tendra este sensor
		  @param anginf Angulo inferior desde donde comenzara la cobertura de este sensor
		  @param angsup Angulo superior hasta donde cubrira este sensor

		  */
		explicit VisionSensor(Agent *agente, double scope, double anginf, double angsup);

		/**
		  Establece el alcance de vision maximo que tendra este sensor.

		  @param al Alcance maximo que se le asignara

		  @see getAlcance
		  */
		void setVisionRange(double al);

		/**
		  Devuelve el valor del alcance visual de este sensor.

		  @return double Alcance visual actual de este sensor
		  */
		double getVisionRange();

		/**

		  */
		void setCoverAngle(double angulo);
		void setCoverAngle(double inf, double sup);
		double getAverageDistanceToAgents();
		double getAverageManhattanDistanceToAgents();

		QList<DistanciaAgente*> getDistanceToAgents();
		QList<DistanciaAgente*> getManhattanDistanceToAgents();

		double getDistanceToAgent(Agent *ag);
		double getManhattanDistanceToAgent(Agent *ag);

		QList<Agent*> getAgents();

//        void setAreaDeCovertura(QPainterPath *area);
		QPainterPath getCoverArea();
};

#endif // SENSORDISTANCIA_H
