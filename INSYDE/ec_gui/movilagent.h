#ifndef MOVILAGENT_H
#define MOVILAGENT_H

#include <QtCore>
#include <QtGui>

#include "share_ec_gui.h"
#include "agent.h"
#include "sensordistancia.h"
#include "actuadormovimiento.h"

namespace ec_gui
{

class MovingActuator;
//class SensorDistancia;

/**
  @class MovilAgent
  @author Edixon Vargas
  @date 08-06-2012

  Un @code{MovilAgent} es un agente que posee un actuador de movimiento @code{MovingActuator}, obtiene propiedades
  de desplazamiento a lo largo del mapa, indicandole los puntos a donde queremos que el se dirija o si queremos que
  tenga un movimiento continuo.

  */
class EC_GUI_LIB_IMPORT_EXPORT MovilAgent : public Agent
{
		/*
		  Indica si se quiere visualizar el trayecto dentro del recuadro del objeto, esta variable es para uso
		  interno unicamente
		*/
		bool includeJourney;

		//Indica el angulo actual en radianes al que apunta agente movil
		double theta;

		//Contiene la forma actual de este agente
		QPainterPath forma;

		//Visibilidad del area del sensor de vision
		bool visibleVisionSensorArea;

		//Actuador de movimiento asignado actualmente a este agente
		MovingActuator *movingActuator;

		//Sensor de vision actualmente asignado a este agente
		VisionSensor *visionSensor;

		//Describe si queremos que la trayectoria sea visible
		bool visibleJourney;

		/**
		  Inicializa todas las variables miembros de este agente para su puesta en funcionamiento

		  @param rapidez Indica la rapidez del agente, si no se mueve asigne cero (0)
		  @param alcance Indica el alcance visual que tendra este agente
		  */
		void iniciarAgenteMovil(double rapidez, double alcance);

		/**
		  Devuelve una region que cubre todo la parte visible de este agente.

		  @note Nota: esta funcion esta en prueba
		  */
		QRegion getRegion();

	public:

		/**
		  Constuctor de la clase, inicializa un agente y todas sus variables miembro a valores predeterminados.
		  */
		explicit MovilAgent();

		/**
		  Crea un nuevo objeto @code{MovilAgent} con los parametros especificos de velocidad y alcance.

		  @param rapidez Rapidez actual del agente
		  @param alcance Alcance visual del agente
		  */
		explicit MovilAgent(double rapidez, double alcance);

		/**
		  Asigna la visibilidad del sensor de vision,

		  @note: Nota: este metodo deberia ser miembro de la clase VisionSensor (Modificacion a futuro)

		  @param b Visibilidad del area que cubre el sensor de vision

		  @see getVisibleVisionSensorArea
		  */
		inline void setVisibleVisionSensorArea(bool b){visibleVisionSensorArea = b;}

		/**
		  Devuelve el estado de la visibilidad del sensor de vision actualmente asignado a este agente

		  @return bool Estado de la visibilidad

		  @see setVisibleVisionSensorArea
		  */
		inline bool getVisibleVisionSensorArea() const {return visibleVisionSensorArea;}

		/**
		  Establece si o no se desea ver la trayectoria por la cual se movera la unidad

		  @param bool vis - True si quiere que se vea la trayectoria.

		  @see getVisibleJourney()
		  */
		inline void setVisibleJourney(bool b){visibleJourney = b;}

		/**
		  Devuelve la visibilidad actual de la trayectoria de la unidad

		  @return bool - La visibilida de la trayectoria de la unidad (true si es visible)

		  @see setVisibleJourney()
		  */
		inline bool getVisibleJourney() const {return visibleJourney;}

		/**
		  Establece la direccion a la que se dirigira la unidad

		  @param qreal dir - Angulo expresado en grados en sentido contrario a las agujas del reloj

		  @see setDireccionRads()
		  */
		void setDirection(double dir);

		/**
		  Obtiene la direccion actual en grados

		  @return qreal - Direccion actual

		  @see setDireccion()
		  @see setDireccionRads()
		  */
		double getDirection();
		/**
		  Establece la direccion a la que se dirigira la unidad

		  @param qreal dir - Angulo expresado en radianes en sentido contrario a las agujas del reloj

		  @see setDireccion()
		  */
		void setDirectionRads(double dir);

		/**
		  Obtiene el angulo en radianes actual

		  @return qreal - Angulo actual en radianes
		  @see setDireccionRads()
		  @see setDireccion()
		  */
		double getDirectionRads();

		/**
		  Asigna la rapidez de este agente

		  @note Nota: esta funcion deberia ser miembro de MovingActuator (Cambiar a futuro)

		  @param rapidez Rapidez que se le asignara a este agente

		  @see getSpeed
		  */
		void setSpeed(double rapidez);

		/**
		  Obtiene la rapidez actual del agente movil

		  @return double Rapidez actual del agente

		  @see setSpeed
		  */
		double getSpeed();

		/**
		  Mapeada de MovingActuator, vease documentacion para mas informacion.

		  @note Nota: este metodo debe ser miembro de MovingActuator (Cambiar a futuro)
		  */
		virtual void addPoint(double x, double y);

		/**
		  Mapeada de MovingActuator, vease documentacion para mas informacion.

		  @note Nota: este metodo debe ser miembro de MovingActuator (Cambiar a futuro)
		  */
		virtual void addPoint(const QPointF &pt);

		/**
		   Mapeada de MovingActuator, vease documentacion para mas informacion.
		  */
		void clearPoints();

		/**
		  Obtiene el radio maximo actual de este agente, el radio es correspondiente a la
		  forma devuelta por @code{getRadialShape()}

		  @return double Radio actual de la forma de este agente

		  @see getRadialShape
		  */
		double getRadius();

		/**
		  Establece el rango de vision actual de este agente.
		  El rango de vision indica a que distancia el agente comenzara a ver los demas agentes
		  que se encuentran en el entorno, esto es muy utilizado en caso de que se quiera simular
		  agentes con campo de vision.

		  @param range Distancia visual que se le asignara al agente

		  @see getVisualRange
		  */
		void setVisualRange(double range);

		/**
		  Devuelve el rango de vision actual de este agente.

		  @return double Rango visual de este agente

		  @see setVisualRange
		  */
		double getVisualRange();

		/**
		  Detiene este agente si esta corriendo la simulacion actualmente.
		  */
		void stop();

		/**
		  Inicia la simulacion de este agente particular.
		  */
		void run();

		/**
		  Esta funcion es mapeada de MovingActuator, vease la documentacion para mayor informacion

		  @note Nota: esta funcion es miembro de MovinActuator (se movera a futuro)
		  */
		virtual void moverA(double x, double y);

		/**
		  Esta funcion es mapeada de MovingActuator, vease la documentacion para mayor informacion

		  @note Nota: esta funcion es miembro de MovinActuator (se movera a futuro)
		  */
		virtual void moverA(QPointF pt);

		/**
		  Esta funcion es mapeada de MovingActuator, vease la documentacion para mayor informacion

		  @note Nota: esta funcion es miembro de MovinActuator (se movera a futuro)
		  */
		virtual void moverA(QQueue<QPointF> posiciones);


		/**
		  Esta funcion es mapeada de MovingActuator, vease la documentacion para mayor informacion

		  @note Nota: esta funcion es miembro de MovinActuator (se movera a futuro)
		  */
		virtual bool isMoving();

	protected:
//        void mousePressEvent(QGraphicsSceneMouseEvent *event);
//        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

		/*
		  Funciones heredadas de la clase padre QGraphicsView. Vease su documentacion para mayor informacion
		  */
		QRectF boundingRect() const;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};
}
#endif // MOVILAGENT_H
