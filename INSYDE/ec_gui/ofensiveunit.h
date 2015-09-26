#ifndef OFENSIVEUNIT_H
#define OFENSIVEUNIT_H

#include <QtCore>
#include <QtGui>
#include <qmath.h>

#include "unit.h"

class Unit;

/**
  @class OfensiveUnit
  @author Edixon Vargas
  @date 08-06-2012

  @code{OfensiveUnit} es un tipo de unidad que permite llevar a cabo ataques a enemigos o a puntos fijos establecidos
  por el usuario, es la base de otros tipos de unidades ofensivas mas especificas como MeleeUnit y ShootingUnit

  */
class OfensiveUnit : public Unit
{
		Q_OBJECT

		//Actuador de movimiento asignado a esta unidad
		MovingActuator *mov;
//        int attack;

		//Defensa actual de esta unidad
		int defense;
//        int attackVelocity;

		/**
		  Inicializa las variables miembro de la unidad actual con las propiedades iniciales indicadas por los parametros

		  @param attack Indica el poder de ataque de la unidad
		  @param defense Indica el blindaje que tendra una unidad
		  @param attackVelocity Indica la velocidad con la cual la unidad atacara al enemigo
		  */
		void initUnit(int attack, int defense, int attackVelocity);

	public:

		/**
		  Inicializa la unidad con las condiciones preestablecidas
		  */
		explicit OfensiveUnit();

		/**
		  Inicializa la unidad con las propiedades epecificas pasadas como parametros

		  @param tj Tipo de jugador que controla a esta unidad
		  @param cr Color del jugador que controla esta unidad
		  @param eq Equipo al cual pertenece el jugador que controla esta unidad
		  @param vitalidadMaxima Maxima vitalidad que tendra una unidad
		  @param vitalidad Vitalidad que tendra inicialmente la unidad
		  @param energiaMaxima Maxima energia que poseera una unidad
		  @param energy Energia actual que posee la unidad
		  @param alcanceVisual Alcance visual que tiene esta unidad
		  @param rapidez Rapidez que tiene esta unidad

		  @see PlayerType, PlayerColor, PlayerTeam
		  */
		explicit OfensiveUnit(PlayerType tj,
							  PlayerColor cr,
							  PlayerTeam eq,
							  int vitalidadMaxima,
							  int vitalidad,
							  int energiaMaxima,
							  int energy,
							  double alcanceVisual,
							  double rapidez);

		/**
		  Inicializa la unidad con las propiedades epecificas pasadas como parametros
		  @param attack Fuerza de ataque que tendra esta unidad
		  @param defense Defensa o blindaje que tendra la unidad
		  @param attackVelocity Velocidad de ataque
		  @param tj Tipo de jugador que controla a esta unidad
		  @param cr Color del jugador que controla esta unidad
		  @param eq Equipo al cual pertenece el jugador que controla esta unidad
		  @param vitalidadMaxima Maxima vitalidad que tendra una unidad
		  @param vitalidad Vitalidad que tendra inicialmente la unidad
		  @param energiaMaxima Maxima energia que poseera una unidad
		  @param energy Energia actual que posee la unidad
		  @param alcanceVisual Alcance visual que tiene esta unidad
		  @param rapidez Rapidez que tiene esta unidad

		  @see PlayerType, PlayerColor, PlayerTeam
		  */
		explicit OfensiveUnit(int attack,
							  int defense,
							  int attackVelocity,
							  PlayerType tj,
							  PlayerColor cr,
							  PlayerTeam eq,
							  int vitalidadMaxima,
							  int vitalidad,
							  int energiaMaxima,
							  int energy,
							  double alcanceVisual,
							  double rapidez);

//        void setAttack(int att);
//        int getAttack();

		/**
		  Establece la defensa que tendra esta unidad

		  @param defense Unidades de defensa que tendra esta unidad

		  @see getDefense
		  */
		void setDefense(int defense);

		/**
		  Devuelve el valor de la defensa que tendra esta unidad

		  @return int Valor de la defensa de esta unidad

		  @see getDefense
		  */
		int getDefense();

//        void setAttackVelocity(int av);
//        int getAttackVelocity();

//        virtual void attackTo(Building *bd) = 0;

		/**
		  Inicia el ataque a una unidad especifica

		  @param *ag Puntero a la unidad a la cual se quiere atacar
		  */
		virtual void attackTo(Unit *ag) = 0;

		/**
		  Inicia el ataque a un punto especifico. La unidad debe determinar si o no se puede
		  atacar dicho punto

		  @param &pt Punto al cual se quiere atacar

		  @see stopAttack
		  */
		virtual void attackTo(const QPointF &pt) = 0;

		/**
		  Detiene todos los ataques de la unidad.

		  @see stopAttack
		  */
		virtual void stopAttack() = 0;

		/**
		  Devuelve @code{true} si la unidad se encuentra atacando a un enemigo actualmente

		  */
		virtual bool isAttacking() = 0;

		/**
		  Inicia el modo de ataque, este modo de ataque indica que la unidad seguira los rastros de feromonas
		  hasta el origen y atacara a las unidades enemigas que consiga

		  */
		virtual void startAttackMode();

	protected slots:

		/**
		  Se dispara este evento cuando esta unidad ha muerto (su vitalidad llego a cero)
		  */
		virtual void unitHasKilled(Unit *un);

	protected:
//        QPainterPath shape() const;
//        QRectF boundingRect() const;
//        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // OFENSIVEUNIT_H
