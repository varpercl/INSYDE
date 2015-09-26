#ifndef SHOOTINGUNIT_H
#define SHOOTINGUNIT_H

#include <QtCore>

#include "../core/common.h"
#include "ofensiveunit.h"
#include "shootingweapon.h"
#include "pheromonedepositor.h"
#include "ECFunctions.h"

using namespace ECFunctions;

enum PlayerTeam;
enum PlayerColor;
enum PlayerType;
enum Orders;

class ShootingWeapon;
class OfensiveUnit;
class Unit;

/**
  @class ShootingUnit
  @author Edixon Vargas
  @date 08-06-2012

  @code{ShootingUnit} es un tipo de unidad que permite llevar a cabo ataques a distancia a agentes enemigos o puntos
  establecidos por el usuario, es la base de otros tipos de unidades.

  */
class Q_DECL_EXPORT ShootingUnit : public OfensiveUnit
{
		Q_OBJECT

		//Contiene una lista actualizada de los items de feromonas que ha conseguido en el camino
		QList<PheromoneItem*> pheromoneList;

		//Apunta a la direccion del proximo item de feromona para seguir su rastro
		QPointer<PheromoneItem> nextPI;

		//Indica si se colocaran feromonas (pendiente de revisar)
		bool pheromonePlacing;

		//Apuntador al actuador que deposita feromonas
		PheromoneDepositor *pheromoneDepositor;

		//Temporizador que verifica todo el estatus de la unidad
		QTimer timerCheck;

		//Se utiliza para actualizar la posicion de la unidad que esta siguiendo actualmente.
		QTimer timerReach;

		//Este timer controla el tiempo de disparo de la unidad
		QTimer timerAttack;

		//Indica si la unidad esta atacando actualmente
		bool attacking;

//        int attackFrequencyTimerID;

		//Apunta a la unidad que se quiere alcanzar
		QPointer<Unit> unitToReach;

		//Apunta a la unidad a la que le quiere disparar
		QPointer<Unit> unitToFire;

//        int reachUnitTimerID;
		int reachUnitTimerInterval;

		//Apuntador al arma que esta usando actualmente
		ShootingWeapon *weapon;

		/**
		  Inicializa todas las variables miembro de esta unidad y le asiga un poder de ataque y un rango

		  @param power Poder de ataque de esta unidad
		  @param range Rango maximo de ataque de esta unidad
		  */
		void initSU(int power, int range);

		/**
		  Se utiliza este metodo para indicarle a esta unidad que debera alcanzar a otra unidad dada por el
		  puntero @code{un}.

		  @param *un Puntero a la unidad que se quiere alcanzar.

		  */
		void reach(Orders order, Unit *un);

		/**
		  Se utiliza para indicarle a esta unidad que alcance un punto especifico dado por @code{pt}

		  @param &pt Punto al cual se quiere llegar.
		  */
		void reach(Orders order, const QPointF &pt);

		/**
		  Se ejecuta este metodo una vez que una unidad ha sido alcanzada.

		  @param order Indica una orden que ejecutara una vez que haya alcanzado la unidad
		  @param *un Puntero que indica la unidad que ha sido alcanzada

		  */
		void unitHasReached(Orders order, Unit *un);

		/**
		  Se ejecuta una vez que una unidad ha alcanzado un punto indicado por @code{pt}

		  @param &pt Punto al cual ha llegado la unidad
		  */
		void pointHasReached(const QPointF &pt);

		/**
		  Calcula la vitalidad total de todas las unidades indicadas por @code {units}

		  @param units Lista de unidades a las cuales se les calculara la vitalidad actual

		  */
		double calculateTotalHealth(const QList<Unit*> &units);

		/**
		  Devuelve un puntero a la unidad mas debil de una lista de unidades indicadas por units

		  @param units Lista de unidades a evaluar
		  */
		Unit *getWeakestUnit(const QList<Unit*> &units);

		/**
		  Devuelve un puntero a la unidad mas proxima indicada por la lista @code{units}

		  @param units Lista de unidades a evaluar
		  */
		Unit *getNearestUnit(const QList<Unit*> &units);

		/**
		  Devuelve un puntero a la unidad mas conveniente para atacar entre una lista @code{enemies} de unidades

		  @param enemies Lista de enemigos a evaluar
		  */
		Unit *getBetterUnitToAttack(const QList<Unit*> &enemies);

	public:

		/**
		  Construye una unidad de tiro con algunos parametros preestablecidos.
		  */
		explicit ShootingUnit();

		/**
		  Construye una unidad de tiro con una potencia @code{power} y un rango de ataque @code{range}

		  @param power Potencia de ataque que tendra la unidad
		  @param range Rango de ataque que tendra la unidad
		  */
		explicit ShootingUnit(int power, int range);

		/**
		  Construye una unidad con todos los parametros necesarios para iniciar una ronda o partida.

		  @param tj Tipo de jugador que controlara esta unidad
		  @param cr Color que tendra esta unidad
		  @param eq Equipo al que pertenecera esta unidad
		  @param vitalidadMaxima Maxima vitalidad a asignar
		  @param vitalidad Vitalidad inicial que tendra
		  @param energiaMaxima Energia maxima a asignar a esta unidad
		  @param energia Energia inicial que tendra esta unidad
		  @param alcanceVisual Alcance visual que esta unidad tendra inicialmente
		  @param rapidez Rapidez con la que se movera esta unidad
		  */
		explicit ShootingUnit(PlayerType tj,
							  PlayerColor cr,
							  PlayerTeam eq,
							  int vitalidadMaxima,
							  int vitalidad,
							  int energiaMaxima,
							  int energy,
							  double alcanceVisual,
							  double rapidez);

		/**
		  Construye una unidad con todos los parametros necesarios para iniciar una ronda o partida.

		  @param power Potencia de fuego inicial que tendra esta unidad
		  @param range Rango de ataque que tendra inicialmente
		  @param tj Tipo de jugador que controlara esta unidad
		  @param cr Color que tendra esta unidad
		  @param eq Equipo al que pertenecera esta unidad
		  @param vitalidadMaxima Maxima vitalidad a asignar
		  @param vitalidad Vitalidad inicial que tendra
		  @param energiaMaxima Energia maxima a asignar a esta unidad
		  @param energia Energia inicial que tendra esta unidad
		  @param alcanceVisual Alcance visual que esta unidad tendra inicialmente
		  @param rapidez Rapidez con la que se movera esta unidad
		  */
		explicit ShootingUnit(int power,
							  int range,
							  PlayerType tj,
							  PlayerColor cr,
							  PlayerTeam eq,
							  int vitalidadMaxima,
							  int vitalidad,
							  int energiaMaxima,
							  int energy,
							  double alcanceVisual,
							  double rapidez);

		/**
		  Destructor de la clase
		  */
		~ShootingUnit();

		/**
		  Inicia un ataque sobre una unidad indicada por el puntero @code{ag}

		  @param *ag Puntero a la unidad a la cual se quiere atacar
		  */
		void attackTo(Unit *ag);

		/**
		  Ataca un punto fijo si se le indica mediante @code{pt}

		  @param &pt Punto al cual quiero que ataque esta unidad.
		  */
		void attackTo(const QPointF &pt);

		/**
		  Detiene el ataque actual
		  */
		void stopAttack();

		/**
		  Determina si una unidad enemiga esta en el rango de ataque de esta unidad.

		  @param ag Puntero a la unidad enemiga que se quiere atacar

		  @return bool Devuelve true si la unidad esta en el rango de ataque
		  */
		bool isInRange(Unit *ag);

		/**
		  Determina si un punto esta dentro del rango de ataque.

		  @param &pt Punto al cual se quiere atacar

		  @return bool Devuelve true si el punto esta en el rango de ataque
		  */
		bool isInRange(const QPointF &pt);

		/**
		  Devuelve true si la unidad indicada por @code{un} puede ser atacada.
		  Para determinar esto se basa la condicion de que la diplomacia sea
		  enemiga y que el color sea distinto, por supuesto.

		  @param *un Puntero a la unidad que se quiere atacar.

		  @return bool Devuelve true en caso de que pueda atacar a la unidad.
		  */
		bool canAttack(Unit *un);

		/**
		  Devuelve true si el punto indicado por @code{pt} puede ser atacado.
		  (aun no esta implementado)

		  @param *un Puntero a la unidad que se quiere atacar.

		  @return bool Devuelve true en caso de que pueda atacar a la unidad.
		  */
		bool canAttack(const QPointF &pt);

//        void moverA(double x, double y);
//        void moverA(QPointF pt);
//        void moverA(QQueue<QPointF> posiciones);

		/**
		  Agrega un punto de reunion a la lista de puntos de esta unidad. El punto esta indicado por @code{x} y @code{y}.

		  @param x Coordenada X del punto que se agregara
		  @param y Coordenada Y del punto que se agregara
		  */
		void addPoint(double x, double y);

		/**
		  Agrega un punto de reunion @code {pt} a la lista de puntos actuales de esta unidad.
		  */
		void addPoint(const QPointF &pt);

		/**
		  Determina si la unidad esta actualmente atacando a un enemigo
		  @return bool Devuelve true si se encuentra atacando a un enemigo
		  */
		bool isAttacking();

		/**
		  Establece si esta unidad depositara feromonas

		  @param act Indica mediante un valor booleano si esta unidad depositara feromonas.

		  @see getPheromonePlacing
		  @see canPlacePheromone
		  */
		void setPheromonePlacing(bool act);

		/**
		  Devuelve el estatus actual de la deposicion de feromonas.

		  @return bool Devuelve true si esta depositando feromonas actualmente.
		  */
		bool getPheromonePlacing();

		/**
		  Determina si puede o no depositar feromonas. En este caso se valida si el jugador es controlado por la
		  computadora

		  @return bool Devuelve true si puede depositar feromonas.
		  */
		bool canPlacePheromone();

		/**
		  Establece la vitalidad actual de esta unidad.

		  @param vitalidad Valor de vitalidad que se le asignara a esta unidad.

		  @see getHealth
		  @see decrementHealth
		  @see incrementHealth
		  */
		void setHealth(int vitalidad);

		/**
		  Decrementa la vitalidad @code{decrement} veces.

		  @param decrement Decremento que se hara a la vitalidad actual.

		  @see setHealth
		  @see incrementHealth
		  */
		void decrementHealth(int decrement);

//        void startSearchMode();

		/**
		  Inicia el modo de huida en esta unidad. Cuando se activa el modo de huida, las unidades
		  se dirigen al centro del mapa y comienzan a depositar feromonas en el camino.

		  */
		void startFleeMode();

		/**
		  Inicia el modo de ataque. En el modo de ataque las unidades comienzan a seguir el rastro
		  de feromonas hasta la posicion inicial donde se comenzo a depositar dicho rastro. Cuando
		  consiguen una unidad enemiga comienzan a dispararle.

		  */
		void startAttackMode();

		/**
		  Devuelve un puntero a un item de feromona a partir de una lista @code{list} presentada.

		  @param list Lista de elementos de cual se extraera el que tenga el maximo valor.

		  @return PheromoneItem* Puntero al item de feromona que tenga mayor intensidad.
		  */
		PheromoneItem *getMaxPheromone(const QList<PheromoneItem*> &list);

	protected:
//        virtual void secureStartTimer(int &id, int interval);
//        virtual void secureKillTimer(int &id);
//        QRectF boundingRect() const;
//        QPainterPath shape() const;
//        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
//        void timerEvent(QTimerEvent * event);

	signals:
//        void pointReached(QPointF pt);
//        void unitReached(Orders lastorder, Unit *un);
//        void killed(Unit *reference);

	protected slots:

		/**
		  Se dispara este evento periodicamente una vez que se le ha indicado a una unidad que ataque a otra.
		  Esto lo hace para repetir el disparo hasta que la unidad haya sido eliminada. En caso de que no este al
		  alcance la seguira y en caso de que este en el rango de ataque le comenzara a disparar.
		  */
		void attackTimerEvent();

		/**
		  Este evento se dispara periodicamente para actualizar la posicion a donde se dirigira el agente cuando
		  se dispone a alcanzar a una unidad.
		  */
		void timerReachEvent();

		/**
		  Se dispara este slot cuando una unidad enemiga ha sido vista. El metodo provee una lista
		  con las unidades enemigas y una lista con las unidades aliadas.

		  @param aliedList Lista de aliados
		  @param enemies Lista de enemigos avistados
		  */
		void enemyHasSighted(QList<Unit*> aliedList, QList<Unit *> enemies);
//        void enemyHasSighted(QList<Unit *> enemies);

		/**
		  Se dispara este evento cuando la unidad a la cual se esta atacando ha sido eliminada.

		  @param *unit Puntero a la unidad que se estaba atacando
		  */
		void enemyHasKilled(Unit *unit);

		/**
		  Este slot es activado cuando un punto de llegada ha sido alcanzado.

		  @param &point Punto de llegada donde se encuentra el agente actualmente.
		  */
		void checkPointReached(const QPointF &point);

		/**
		  Actualiza el estado de la unidad, verifica si hay unidades enemigas, feromonas o aliados en el rango
		  de la unidad.
		  */
		void checkAll();

		/**
		  Se dispara este evento una vez que la unidad ha detectado un item de feromona, asimismo entrega
		  una lista con los apuntadores a todos los items que consiguio en el camino.

		  @param pheromoneList Lista de feromonas encontradas en el entorno.
		  */
		void pheromoneHasBeenDetected(QList<PheromoneItem *> pheromoneList);

//        void unitHasKilled(Unit *reference);
//        void pointHasReached(QPointF pt);
//        void unitHasReached(Orders order, Unit *un);
//        void enemyHitted(Unit *unitHitted);
};

#endif // SHOOTINGUNIT_H
