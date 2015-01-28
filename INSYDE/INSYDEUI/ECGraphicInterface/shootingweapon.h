#ifndef SHOOTINGWEAPON_H
#define SHOOTINGWEAPON_H

#ifndef _ISOC99_SOURCE
    #define _ISOC99_SOURCE
#endif

#ifdef WIN32
	#ifndef NAN
		static const unsigned long __nan[2] = {0xffffffff, 0x7fffffff};
		#define NAN (*(const float *) __nan)
	#endif
#endif

#include <QtCore>
#include <stdlib.h>
#include <math.h>

#include "actuador.h"
#include "shootingunit.h"
#include <signal.h>

//class Actuador;
class ShootingUnit;
class Unit;

//void signalController(int val);

/**
  @class ShootingWeapon
  @author Edixon Vargas
  @date 08-06-2012

  @code{ShootingWeapon} es un actuador especial que funciona como una arma de disparo, esta arma se puede considerar como un tipo
  de pistola.

  */
class ShootingWeapon : public Actuator
{
		Q_OBJECT

		//        QVector<void*> gcItems;

		//Indica cuantos pixeles avanzara el proyectil por unidad de tiempo
		int incProyectile;

		//Controla el tiempo en que se actualiza la posicion del proyectil
		int timerInterval;

		//Puntero a la unidad a la cual se va a atacar
		QPointer<Unit> unitToShoot;

		//Contiene el punto al cual se va a atacar
		QPointF pointToShoot;

		//poder de ataque actual de esta arma
		int power;

		//rango de ataque maximo de esta arma
		int range;

		//Frecuencia de ataque de esta arma
		double frequency;

		//Identificador del timer principal de este objeto
		int timerID;

		//ID del timer del recolector de basura que se ejecuta cada 10 segundos
		int timerGarbageCollectorID;

		//Velocidad del proyectil
		double proyectileVelocity;

		/**
		  Inicializa todas las variables miembro de esta arma en base a los parametros de potencia, rango
		  y frecuencia de ataque.

		  @param power Poder que tendra el ataque impartido por esta arma
		  @param range Rango maximo de alcance de esta arma
		  @param frecuency Frecuencia de ataque de esta arma
		  */
		void initSW(int power, int range, int frequency);

		/**
		  Actualiza la forma generada por esta arma, mantiene la posicion actual del proyectil y
		  el dibujo del mismo en el tiempo en que se llama
		  */
		void updateShape();

		/**
		  Calcula la distancia euclidea entre dos unidades @code{unit1} y @code{unit2}

		  @param *unit1 Puntero a la primera unidad
		  @param *unit2 Puntero a la segunda unidad

		  @return double Valor de la distancia actual entre las dos unidades
		  */
		double distanceBetweenUnits(Agent *unit1, Agent *unit2);

		/**
		  Calcula la distancia euclidea entre dos puntos @code{pt1} y @code{pt2}

		  @param &pt1 Primer punto de referencia
		  @param &pt2 Segundo punto de referencia

		  @return double La distancia euclidea entre ambos puntos pt1 y pt2
		  */
		double distanceBetweenPoints(const QPointF &pt1, const QPointF &pt2);

		/**
		  Determina si puede dispararle a una unidad enemiga, para determinar eso
		  se basa en la distancia, es decir, si se encuentra dentro del rango de ataque.

		  @param *un Puntero a la unidad que se quiere atacar

		  @return bool Devuelve true en caso de que pueda atacar a la unidad.
		  */
		bool canFire(Unit *un);

		/**
		  Determina si puede atacar un punto especifico, indicado por @code{pt}

		  @param &pt Punto al cual se iniciara un ataque.

		  @return bool Devuelve true si puede atacar a ese punto.
		  */
		bool canFire(QPointF pt);

		/**
		  Obtiene la distancia actual del proyectil hasta la unidad que se esta atacando.

		  @param *un Puntero a la unidad que se va a atacar

		  @return double Distancia actual del proyectil
		  */
		double getCurrentProyectileDistanceToTarget(Unit *un);

		/**
		  Esta funcion esta en evaluacion
		  */
		void activateGarbageCollector(int timems);

	public:

		/**
		  Crea una instancia de ShootingWeapon y se la asigna a @code{agent}

		  @param *agent Agente al que se le asignara el arma
		  */
		explicit ShootingWeapon(ShootingUnit *agent);

		/**
		  Crea una instancia de esta clase y se la asigna a una unidad @code{agent}. Ademas
		  le asigna otras propiedades necesarias.

		  @param *agent Unidad a la que se le asignara esta arma
		  @param power Potencia de fuego que tendra esta arma
		  @param frequency Frecuencia con la que disparara esta arma

		  */
		explicit ShootingWeapon(ShootingUnit *agent, int power, int range, int frequency);

		/**
		  Destructor de la clase
		  */
		~ShootingWeapon();

		/**
		  Asigna la potencia de fuego de esta arma convencional.

		  @param pow Potencia que se le asignara
		  */
		void setPower(int pow);

		/**
		  Obtiene el valor de la potencia actual de esta arma

		  @return int Potencia actual del arma de fuego
		  */
		int getPower();

		/**
		  Establece el rango de ataque de esta arma.

		  @param range Rango que se le asignara al arma actualmente

		  @see getRange
		  */
		void setRange(int range);

		/**
		  Devuelve el rango de ataque actual de esta arma

		  @return int El rango actual del arma.
		  */
		int getRange();

		/**
		  Establece la frecuencia de disparo de esta arma.

		  @param frequency Frecuencia de disparo que se le asignara

		  @see getFrequency
		  */
		void setFrequency(double frequency);

		/**
		  Devuelve la frecuencia de disparo actual de esta arma

		  @return double Frecuencia actual de disparo del arma
		  */
		double getFrequency();

		/**
		  Inicia el fuego contra la unidad indicada por @code{un}

		  @param *un Unidad a la cual se le disparara

		  @return bool Devuelve true en caso de que se lleve a cabo exitosamente el ataque
		  */
		bool startFire(Unit *un);

		/**
		  Inicia el fuego contra el punto indicado por @code{pt}

		  @param pt Punto al cual se le disparara

		  @return bool Devuelve true en caso de que se lleve a cabo exitosamente el ataque
		  */
		bool startFire(const QPointF &pt);

		/**
		  Detiene el ataque que se este llevando a cabo
		  */
		void stopFire();

		/**
		  Establece la velocidad actual del proyectil

		  @param vel Velocidad que se le asignara al proyectil

		  @see getProyectileVelocity
		  */
		void setProyectileVelocity(double vel);

		/**
		  Devuelve la velocidad actual del proyectil

		  @return double Velocidad actual del proyectil
		  */
		double getProyectileVelocity();

		/**
		  Este metodo es llamado cuando una unidad ha sido golpeada.

		  @param *au Puntero de la unidad que lo ha golpeado
		  @param *unitHitted Puntero a la unidad que ha sido golpeada

		  */
		void enemyHitted(OfensiveUnit *au, Unit *unitHitted);

	signals:

		/**
		  Se emite cuando la unidad a la que se esta disparando ha sido eliminada (asesinada)

		  @param *un Puntero a la unidad que ha sido asesinada
		  */
		void unitKilled(Unit *un);

	protected:

		//Heredado de QObject
		void timerEvent(QTimerEvent * event);
};

#endif // SHOOTINGWEAPON_H
