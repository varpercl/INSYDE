#ifndef ACTUADORMOVIMIENTO_H
#define ACTUADORMOVIMIENTO_H

#include <QtCore>

#include <math.h>
#include "actuador.h"
//#include <agent.h>
#include "../vector2d.h"
#include "movilagent.h"
#include "pheromoneitem.h"
//#include <signal.h>

class MovilAgent;

//void signalController(int val);

/**
  @class MovingActuator
  @author Edixon Vargas
  @date 08-06-2012

  La clase @code{MovingActuator} asigna propiedades basicas de movimiento a un agente, esta clase se usa en agentes
  moviles que se van a desplazar a lo largo de un escenario o ambiente.
  */
class MovingActuator : public Actuator
{
		Q_OBJECT

		QPainterPath path;
		//Indica si se quiere o no evitar las colisiones
		bool avoidColitions;

		/**
		  Esta variable se usa exclusivamente en el metodo @code {cambioValor()} para contabilizar cuantos
		  pasos se han realizado
		  */
		int countChanges;

//        int intentosMovimiento;
//        bool isDeviating;

		//Objeto QGraphicsScene al que pertenece este actuador
		QGraphicsScene *escena;

		/**
		  Esta variable indica la distancia a la cual el agente debe responder cuando se encuentra
		  cercano a un obstaculo
		  */
		double sensibilidad;

		//Puntero inteligente al agente al que pertenece este actuador
		QPointer<MovilAgent> agent;

		//Rapidez a la que se desplaza este agente
		double rapidez;

		//Angulo en el que se esta desplazando este agente
		double theta;

		//Lista de destinos (o puntos de referencia) por los cuales pasara el agente hasta su trayectoria final
		QQueue<QPointF> destinos;      //Indica los puntos de reunion que describen la trayectoria

		//Objeto que controlara el movimiento del agente
		QPropertyAnimation *movimiento;

		/**
		  Este procedimiento inicia todas las variables en sus condiciones predeterminadas o las indicadas por el
		  respectivo metodo que lo llame

		  Solo tiene un uso interno.

		  @param *ag Apuntador al agente al que pertenece
		  @param rapInicial Rapidez inicial del agente
		  @param angInicial Angulo inicial de desplazamiento
		  @param sensibilidad Sensibilidad inicial que tendra el agente para responder ante obstaculos proximos

		  @see ActuadorMovimiento::ActuadorMovimiento()
		  */
		void iniciarActuadorMovimiento(MovilAgent *ag, double rapInicial, double angInicial, double sensibilidad);

	public:

		/**
		  Crea un nuevo actuador de movimiento asignandole @code{agent} como su propietario

		  @param agent Puntero al agente que posee este actuador
		  */
		explicit MovingActuator(MovilAgent *agent = NULL);

		/**
		  Crea un nuevo actuador de movimiento asignandole @code{agent} como su propietario

		  @param agent Puntero al agente que posee este actuador
		  @param rapIni Rapidez inicial del agente
		  */
		explicit MovingActuator(MovilAgent *agent, double rapIni);

		/**
		  Crea un nuevo actuador de movimiento asignandole @code{agent} como su propietario

		  @param agent Puntero al agente que posee este actuador
		  @param rapIni Rapidez inicial del agente
		  @param angInicial Angulo inicial en el que se dirige el agente
		  */
		explicit MovingActuator(MovilAgent *agent, double rapIni, double angInicial);

		/**
		  Crea un nuevo actuador de movimiento asignandole @code{agent} como su propietario

		  @param agent Puntero al agente que posee este actuador
		  @param rapIni Rapidez inicial del agente
		  @param angInicial Angulo inicial en el que se dirige el agente
		  @param sensibilidad Sensibilidad inicial que tendra el agente para responder ante obstaculos proximos
		  */
		explicit MovingActuator(MovilAgent *agent, double rapIni, double angInicial, double sensibilidad);

		/**
		  Destructor del objeto
		  */
		~MovingActuator();

//        /**
//          Establece el margen de error que tiene la unidad para llegar a su proximo punto de llegada. Un margen
//          de error muy bajo puede causar problemas en el desplazamiento o que nunca detecte que ha llegado al destino.
//          Esto tambien dependera del tiempo de actualizacion, mientras mas alto el intervalo de actualizacion, la tolerancia
//          debera ser mayor tambien

//          @param qreal tol - Describe el margen de error de la unidad

//          @see getTolerancia()
//          */
//        void setTolerancia(qreal tol);

//        /**
//          Devuelve la tolerancia actual de la unidad

//          @return qreal - El valor de la tolerancia actual

//          @see setTolerancia()
//          */
//        qreal getTolerancia();

		/**
		  Establece la rapidez de desplazamiento (magnitud de la velocidad) de esta unidad expresado en pixeles por segundo

		  @param qreal vel - Velocidad a la que quiere que se desplace la unidad

		  @see getVelocidad()
		  @see setDireccion()
		  */
		void setRapidez(double vel);

		/**
		  Devuelve la rapidez de desplazamiento de esta unidad expresado en pixeles por segundo

		  @return qreal Velocidad a la que se desplaza la unidad

		  @see setVelocidad()
		  */
		double getRapidez();

		/**
		  Asigna un vector velocidad a esta unidad donde dicho vector posee la informacion sobre la rapidez
		  y la direccion

		  @param VectorR2 vector - Vector que contiene la informacion sobre la rapidez y el angulo

		  @see setVelocidad()
		  @see setDireccion()
		  */
//        void setVectorVelocidad(Vector2D vector);

		/**
		  Devuelve el vector de velocidad actual

		  @return VectorR2 - Vector en R2 de la velocidad actual del agente

		  @see setVectorVelocidad()
		  */
//        Vector2D getVectorVelocidad();

		/**
		  Da una orden al agente de moverse al punto indicado por las coordenadas @code {x} y @code{y}

		  @param x Coordenada x del punto de destino
		  @param y Coordenada y del punto de destino
		  */
		void moverA(double x, double y);

		/**
		  Da una orden al agente de moverse al punto indicado por el punto @code {pt}

		  @param &pt Punto al cual se quiere que el agente se mueva
		  */
		void moverA(const QPointF &pt);

		/**
		  Indica una lista de posiciones a donde se movera el agente

		  @param &posiciones Cola de posiciones las cuales seran recorridas en orden de establecimiento

		  */
		void moverA(const QQueue<QPointF> &posiciones);

		/**
		  Agrega el punto especificado por @code{x} y @code{y} a una lista de destinos (o puntos de reunion) por
		  donde pasara el agente hasta llegar al punto final.
		  Esta funcion tambien inicia el movimiento del agente si este se encuentra detenido

		  @param x Coordenada x al punto donde se quiere mover el agente
		  @param y Coordenada y al punto donde se quiere mover el agente
		  */
		void addPoint(double x, double y);

		/**
		  Agrega el punto especificado por @code{pt} a una lista de destinos (o puntos de reunion) por
		  donde pasara el agente hasta llegar al punto final.
		  Esta funcion tambien inicia el movimiento del agente si este se encuentra detenido

		  @param pt Punto al cual se quiere que se mueva el agente
		  */
		void addPoint(const QPointF &pt);

		/**
		  Obtiene una cola de los destinos asignados actualmente, si el agente no esta en movimiento
		  entonces se devuelve una lista vacia

		  @return QQueue<QPoint> Cola de puntos de reunion
		  */
		QQueue<QPointF> getPoints();

		/**
		  Borra todos los destinos que tiene actualmente el agente, tambien lo detiene en el acto.

		  @see addPoints
		  */
		void clearPoints();

		/**
		  Establece la distancia minima a la cual el agente debe responder cuando tiene obstaculos cercanos

		  @param sens Distancia que establece la sensibilidad
		  */
		void setSensibilidad(double sens);

		/**
		  Devuelve la distancia minima a la cual el agente debe responder cuando tiene obstaculos cercanos

		  @return double Distancia a la cual el agente responde
		  */
		double getSensibilidad();

		/**
		  Devuelve un objeto @code{QPainterPath} que contiene la trayectoria que va a seguir el agente, esta funcion
		  es ideal si quiere dibujar dicha trayectoria en el entorno.
		  */
		QPainterPath getTrayectoria();

		/**
		  Detiene el movimiento del agente

		  */
		void stop();

		/**
		  Inicia el movimiento del agente
		  */
		void run();

		/**
		  Devuelve @code{true} en caso de que el agente este actualmente en movimiento, @code{false} en caso contrario.

		  @return bool Estado de movimiento actual del agente
		  */
		bool isMoving();

		/**
		  Establece si o no se considerara la deteccion de colisiones.

		  @param detect True si desea que se detecten las colisiones
		  */
		void setDetectColitions(bool detect);

		/**
		  Devuelve el estado actual de la deteccion de colisiones, true en caso de que el agente este habilitado para
		  detectar colisiones

		  @return bool Devuelve true en caso de estar habilitado para detectar colisiones
		  */
		bool getDetectColitions();


	signals:
//        void updateCurrentValue(QVariant);

		/**
		  Este signal es lanzado una vez que el agente llego a su punto final.

		  @param &point Punto al cual llego el agente
		  */
		void llegoADestinoFinal(const QPointF &point);

		/**
		  Este evento se dispara cuando ha llegado a un punto de reunion

		  @param &point Punto al cual llego el agente
		  */
		void checkPointReached(const QPointF &point);

		/**
		  Se dispara cada vez que el agente cambia su posicion actual

		  @param &point Posicion actual
		  */
		void positionChanged(const QPointF &point);

	protected slots:
		/**
		  Se activa una vez que un agente llego a un punto de reunion
		  */
		void checkPointHasBeenReached();

		/**
		  Este evento se activa cada vez que la posicion actual ha cambiado

		  @param valor Valor actual que posee el agente
		  */
		void posChanged(QVariant valor);
};

#endif // ACTUADORMOVIMIENTO_H
