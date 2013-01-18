#ifndef UNIT_H
#define UNIT_H

#include <ECGraphicInterface_global.h>
#include <QtCore>
#include <QStyleOptionGraphicsItem>

//#include <shootingweapon.h>
#include <movilagent.h>
//#include <ofensiveunit.h>

class VisionSensor;
class ShootingWeapon;
//class OfensiveUnit;
//enum GraphicsItemChange;


/**
  @enum PlayerTeam Indica el equipo al cual pertenece el jugador propietario de esta unidad.


  */
enum PlayerTeam{
	None,
	Team1,
	Team2,
	Team3,
	Team4
};

/**
  */
enum PlayerType{
	Human,
	Computer
};

enum PlayerColor{
	Blue,
	Red,
	Cyan,
	Green,
	Yellow,
	Orange,
	Purple,
	Brown
};

enum Orders{
	DoNothing,
	AttackTo,
	Defend,
	Move,
	Follow
};

enum Diplomacy{
	Neutral,
	Alied,
	Enemy
};

enum Mode{
	Stand,
	Search,
	Flee,
	Attack
};

#define cant 50

//class QGraphicsItem;

/**
  @class Unit
  @author Edixon Vargas
  @date 08-06-2012

  Un objeto @code{Unit} es considerado un tipo de agente movil (@code{MovilAgent}) especial dentro de los juegos,
  en especial los juegos de estrategia, tiene propiedades especiales como vitalidad, energia y otras que se pueden
  manipular para crear un juego basico.

  */
class ECGRAPHICINTERFACESHARED_EXPORT Unit : public MovilAgent
{
		Q_OBJECT

		//Contador de eventos de movimiento
		int checkCounter;

		//Diplomacias de esta unidad con respecto a las demas
		QMap<PlayerColor, Diplomacy> diplomacias;

		//Utilizada internamente para dibujo de graficos
		bool canPaint;

		//Velocidad de esta unidad
		int velocity;

		//Angulo al cual apunta la unidad
		double theta;

		//Indica si la bara de salud y energia sera visible
		bool visibleHealthBar, visibleEnergyBar;

		//Rectangulo para dibujar la barra de salud y energia
		QRectF healthBar, energyBar;
//        bool useEnergy;

		//Energia actual y energia maxima
		double energy, maxEnergy;

		//Salud actual y salud maxima
		double health, maxHealth;

		//Color de esta unidad
		PlayerColor colorUnidad;
//        QColor color;                   //Define el color en formato rgb como se pintara la forma

		//Tipo de jugador que controla esta unidad
		PlayerType tipoJugador;

		//Equipo al que pertenece esta unidad
		PlayerTeam team;

		/**
		  Inicializa todas las variables miembro de esta unidad

		  @param tj Tipo de jugador que se le asignara a esta unidad
		  @param cr Color que se le asignara a esta unidad
		  @param eq Equipo al que pertenecera esta unidad
		  @param maxVitalidad Vitalidad maxima que tiene esta unidad
		  @param vitalidad Vitalidad actual de esta unidad
		  @param maxEnergy Energia maxima que poseera esta unidad
		  @param energy Energia actual que tendra esta unidad

		  */
		void iniciarUnidad(PlayerType tj,
						   PlayerColor cr,
						   PlayerTeam eq,
						   int maxVitalidad,
						   int vitalidad,
						   int maxEnergy,
						   int energy);

		/**
		  Genera una posicion aleatoria indicandole un rango de valores en X y Y

		  @param minValX Valor minimo que tendra X
		  @param maxValX Valor maximo que tendra X
		  @param minValY Valor minimo que tendra Y
		  @param maxValY Valor maximo que tendra Y
		  */
		QPointF generateRandomPosition(double minValX,
									   double maxValX,
									   double minValY,
									   double maxValY);

		/**
		  Genera posiciones aleatorias a partir de un radio y angulo establecido.

		  @param module Radio maximo que tendra el numero generado
		  @param minAngle Angulo minimo entre el cual se generara el angulo aleatorio
		  @param maxAngle Angulo maximo entre el cual se generara el angulo aleatorio
		  */
		QPointF generateRandomPosition(double module, double minAngle, double maxAngle);
		QPointF generateRandomPosition(double module, double range);

		void deleteUnit();
		QPointF generateNextValidPos();


	public:
		explicit Unit();

		explicit Unit(PlayerType tj,
						PlayerColor cr,
						PlayerTeam eq,
						int vitalidadMaxima,
						int vitalidad,
						int energiaMaxima,
						int energy);

		explicit Unit(PlayerType tj,
						PlayerColor cr,
						PlayerTeam eq,
						int vitalidadMaxima,
						int vitalidad,
						int energiaMaxima,
						int energy,
						double alcanceVisual,
						double rapidez);

		void setHealthBarPos(const QPointF &pos);
		QPointF getHealthBarPos();

		void setEnergyBarPos(const QPointF &pos);
		QPointF getEnergyBarPos();

		void setEnergyBarWidth(double val);
		double getEnergyBarWidth();

		void setEnergyBarHeitght(double val);
		double getEnergyBarHeight();

		void setHealthBarWidth(double val);
		double getHealthBarWidth();

		void setHealthBarHeight(double val);
		double getHealthBarHeight();

		void setVisibleEnergyBar(bool b){visibleEnergyBar = b;}
		bool getVisibleEnergyBar() const;

		void setVisibleHealthBar(bool b);
		bool getVisibleHealthBar() const;

//        inline void hasEnergy(bool b){useEnergy = true;}
		inline bool useEnergy() const{return maxEnergy > 0;}

		void setEnergy(int val);
		int getEnergy();

		void setMaxEnergy(int valmax);
		int getMaxEnergy();

		void setUnitColor(PlayerColor col);
		PlayerColor getUnitColor();
		void setPlayerType(PlayerType tipo);
		PlayerType getPlayerType();
		void setEquipo(PlayerTeam equipo);
		PlayerTeam getEquipo();

		virtual void setHealth(int vitalidad);
		int getHealth();

		void incrementHealth(int increment);
		virtual void decrementHealth(int decrement);

		void setMaxHealth(int vitalidad);
		int getMaxHealth();

		bool isEnemy(Unit *un);

		void setDiplomacies(const QMap<PlayerColor, Diplomacy> &dip);
		QMap<PlayerColor, Diplomacy> getDiplomacies() const;

		void setDiplomacyTo(const PlayerColor &pc, const Diplomacy &dip);
		Diplomacy getDiplomacyTo(const PlayerColor &pc);

		virtual void setMode(Mode mod);
		virtual Mode getMode();

		virtual void startSearchMode();
		virtual void startFleeMode();

//        double promedio(double *valores, int cont){
//            double suma=0;
//            for(int i = 0; i < cont; i++){
//                suma += valores[i];
//            }
//            return suma/cont;
		//        }

	signals:
//        void hitted(OfensiveUnit *un, ShootingWeapon *sw);

		/**
		  Se envia esta señal una vez que el(los) enemigo(s) ha viso avistado

		  @param units Lista de enemigos vistos por esta unidad
		  */
		void enemySighted(QList<Unit*> units);

		/**
		  Se dispara una vez que se han visto enemigos en el entorno,
		  se envia una lista de aliados y una lista de unidades enemigas.

		  @param alies Lista de aliados avistados en el entorno
		  */
		void enemySighted(QList<Unit*> alies, QList<Unit *> units);
		void dead(Unit *unidad);

		/**
		  Se envia esta señal una vez ha sido detectado algun item de feromonas.
		  Se suministra una lista con todos los items detectados en el entorno que estan
		  dentro del radio de vision del agente.

		  @param pheromoneList Lista de feromonas detectadas
		  */
		void pheromoneDetected(QList<PheromoneItem*> pheromoneList);
//        void positionChanged(QPointF pt);

	protected:
		Mode currentMode;
		Orders lastOrders;
//        int updateUnitTimerID;
//        int updateUnitInterval;

		//Metodos heredados de QGaphicsView
		void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
		QRectF boundingRect() const;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
//        void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
//        void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
//        void itemChange()
//        QVariant itemChange(GraphicsItemChange change, const QVariant &value);
//        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
//        void mousePressEvent(QGraphicsSceneMouseEvent *event);
//        QPainterPath shape() const;

	protected slots:
//        void evaluarPosiblesColisiones();
//        virtual void lastCheckPointReached(QPointF point);

		/**
		  Valida si alcanco el centro del mapa.
		  */
		virtual void checkPointReached(QPointF point);

		/**
		  Verifica la existencia de elementos en el mapa como feromonas, agentes, entre otros.

		  @param pt Punto en el que se encuentra actualmente
		  */
		void checkAll(QPointF pt);
};

#endif // UNIDAD_H
