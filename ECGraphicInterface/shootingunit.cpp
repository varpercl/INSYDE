#include "shootingunit.h"

ShootingUnit::ShootingUnit() : OfensiveUnit(Human, Blue, None, 100, 100, 0, 0, 100, 70)
{
	initSU(10, 90);

}

ShootingUnit::ShootingUnit(int power, int range) : OfensiveUnit(Human, Blue, None, 100, 100, 0, 0, 100, 70)
{
	initSU(power, range);
}

ShootingUnit::ShootingUnit(PlayerType tj,
						   PlayerColor cr,
						   PlayerTeam eq,
						   int vitalidadMaxima,
						   int vitalidad,
						   int energiaMaxima,
						   int energy,
						   double alcanceVisual,
						   double rapidez) : OfensiveUnit(tj, cr, eq, vitalidadMaxima, vitalidad, energiaMaxima, energy, alcanceVisual, rapidez)
{
	initSU(10, 90);
}

ShootingUnit::ShootingUnit(int power,
						   int range,
						   PlayerType tj,
						   PlayerColor cr,
						   PlayerTeam eq,
						   int vitalidadMaxima,
						   int vitalidad,
						   int energiaMaxima,
						   int energy,
						   double alcanceVisual,
						   double rapidez) : OfensiveUnit(tj, cr, eq, vitalidadMaxima, vitalidad, energiaMaxima, energy, alcanceVisual, rapidez)
{
	initSU(power, range);
}

ShootingUnit::~ShootingUnit(){
	QMap<QString, Actuator*> actuadores = getActuators();

	foreach(Actuator *act, actuadores){
		delete act;
	}
	  actuadores.clear();
	unitToReach = NULL;
	unitToFire = NULL;
}

void ShootingUnit::initSU(int power, int range){
//    reachUnitTimerID = 0;
	reachUnitTimerInterval = 200;
//    attackFrequencyTimerID = 0;
//    updateUnitTimerID = 0;
	attacking = false;
	timerCheck.start(500);
//    secureStartTimer(updateUnitTimerID, updateUnitInterval = 200);
	weapon = new ShootingWeapon(this, power, range, 1);
	addActuator("primary_weapon", weapon);

	if(getPlayerType() != Human){
		pheromoneDepositor = new PheromoneDepositor(this, 20);

		addActuator("pheromone_depositor", pheromoneDepositor);
	}

	connect(&timerAttack, SIGNAL(timeout()), SLOT(attackTimerEvent()));
	connect(&timerReach,SIGNAL(timeout()), SLOT(timerReachEvent()));
	connect(&timerCheck, SIGNAL(timeout()), SLOT(checkAll()));
	connect(this, SIGNAL(enemySighted(QList<Unit*>, QList<Unit*>)), SLOT(enemyHasSighted(QList<Unit*>, QList<Unit*>)));
	connect(this, SIGNAL(pheromoneDetected(QList<PheromoneItem*>)), SLOT(pheromoneHasBeenDetected(QList<PheromoneItem*>)));
//    connect(this, SIGNAL(pointReached(QPointF)), SLOT(pointHasReached(QPointF)));
//    connect(this, SIGNAL(unitReached(Orders, Unit*)), SLOT(unitHasReached(Orders, Unit*)));
//    connect(weapon, SIGNAL(unitHitted(Unit*)), SLOT(enemyHitted(Unit*)));


//    QList<QGraphicsItem*> items = scene()->items();
//    Unit *un;
//    int itemsCount = items.count();
//    for(int i = 0; i < itemsCount; i++){
//        if(un = dynamic_cast<Unit*>(dynamic_cast<QGraphicsObject*>(items[i]))){

//            connect(weapon, SIGNAL(unitKilled(Unit*)), SLOT(enemyHasKilled(Unit*)));
//        }
//    }
}

void ShootingUnit::attackTo(Unit *ag)
{
//    unitToReach = ag;
//    if(ag){
//        connect(ag, SIGNAL(hitted(ShootingWeapon*)), SLOT(enemyHitted(ShootingWeapon*)));
	if(canAttack(ag) && !(attacking && unitToFire == ag)){
		clearPoints();
		lastOrders = AttackTo;
		reach(lastOrders, ag);
		attacking = true;
//        if(isInRange(ag)){
//            weapon->startFire(ag);
//        }
		connect(ag, SIGNAL(dead(Unit*)),SLOT(enemyHasKilled(Unit*)));
	}
//    }
}

void ShootingUnit::attackTo(const QPointF &pt)
{
//    if(timerID == 0){
//        timerID = startTimer(200);

	lastOrders = AttackTo;
	reach(lastOrders, pt);
//    }
}

bool ShootingUnit::isInRange(Unit *ag)
{
	int len = (int)hypot(this->x() - ag->x(), this->y() - ag->y());
	return (len < weapon->getRange() ? true : false);
}

bool ShootingUnit::isInRange(const QPointF &pt)
{
	int len = (int)hypot(this->x() - pt.x(), this->y() - pt.y());
	return (len < weapon->getRange() ? true : false);
}

bool ShootingUnit::canAttack(Unit *un)
{
	return (getDiplomacyTo(un->getUnitColor()) == Enemy && un->getColor() != getColor() ? true : false);
}

bool ShootingUnit::canAttack(const QPointF &pt)
{
	Q_UNUSED(pt);

	return true;
}

void ShootingUnit::addPoint(double x, double y)
{
	if(attacking){
		stopAttack();
	}
	OfensiveUnit::addPoint(x, y);
}

void ShootingUnit::addPoint(const QPointF &pt)
{
	if(attacking){
		stopAttack();
	}
	OfensiveUnit::addPoint(pt);
}

bool ShootingUnit::isAttacking()
{
	return attacking;
}

void ShootingUnit::setPheromonePlacing(bool act)
{
	pheromonePlacing = act;
}

bool ShootingUnit::getPheromonePlacing()
{
	return pheromonePlacing;
}

bool ShootingUnit::canPlacePheromone()
{
	if(getPlayerType() == Computer){
		return true;
	}else{
		return false;
	}
}

void ShootingUnit::setHealth(int vitalidad)
{
	stopAttack();
	OfensiveUnit::setHealth(vitalidad);
}

void ShootingUnit::decrementHealth(int decrement)
{
	stopAttack();
	OfensiveUnit::decrementHealth(decrement);
}

void ShootingUnit::startFleeMode()
{
	stopAttack();
	pheromoneDepositor->startPlacePheromone();
	OfensiveUnit::startFleeMode();
}

void ShootingUnit::startAttackMode()
{
	clearPoints();
	PheromoneItem *maxPI = getMaxPheromone(pheromoneList);
	PheromoneItem *next = NULL;

	clearPoints();
	addPoint(maxPI->pos());
	if((next = maxPI->getMostIntenseNeighbour())){
		nextPI = next;
	}
	currentMode = Attack;
}

PheromoneItem *ShootingUnit::getMaxPheromone(const QList<PheromoneItem *> &list)
{
	int pherCount = list.count();
	int maxPheromone = 0;
	PheromoneItem *pi;
	QPointer<PheromoneItem> maxPi;
	int pheromoneValue;
	for(int i = 0; i < pherCount; i++){
		pi = list[i];
		pheromoneValue = pi->getPheromoneValue();
		if(pheromoneValue > maxPheromone){
			maxPi = pi;
			maxPheromone = pheromoneValue;
		}
	}
	return maxPi;
}

void ShootingUnit::reach(Orders order, Unit *un){
	if(un){
		if(!isInRange(un)){
			moverA(un->pos());
			unitToReach = un;
			timerReach.start(reachUnitTimerInterval);
//            secureStartTimer(reachUnitTimerID, reachUnitTimerInterval);
		}else{
			stop();
			timerReach.stop();
//            secureKillTimer(reachUnitTimerID);
			unitHasReached(order, un);
		}
	}
}

void ShootingUnit::reach(Orders order, const QPointF &pt){
	Q_UNUSED(order)
	if(!isInRange(pt)){
		moverA(pt);
	}else{
		stop();
//        killTimer(timerID);
//        timerID = 0;
		pointHasReached(pt);
	}
}

void ShootingUnit::timerReachEvent(){
	reach(lastOrders, unitToReach);
}

void ShootingUnit::enemyHasSighted(QList<Unit*> aliedList, QList<Unit *> enemies)
{
	QPointer<Unit> unitToAttack;

	double totalEnemyHealth = calculateTotalHealth(enemies);
	double totalAliesHealth = calculateTotalHealth(aliedList);

	switch(currentMode){
		case Flee:
			break;
		case Attack:
		case Search:
			/*
			 Esta condición se pueden variar para realizar pruebas,
			 determina ¿Qué unidad atacara?, una opción es que cuando
			 tenga un grupo de unidades enemigas cerca que ataque al
			 más débil (getWeakestUnit) o ataque al más próximo (getNearesUnit)
			 se utiliza el más próximo porque es el mas adecuado ya que a veces
			 las unidades mas débiles se encuentran detrás del frente enemigo
			 por lo cual tienen que acercarse mucho para atacarlas y entonces
			 en ese proceso les hacen mucho daño.

			 Se pudiera hacer una combinación de ambas condiciones, es decir,
			 que ataque la unidad que este más cerca pero que también sea el más débil.
			*/

//            if((unitToAttack = getWeakestUnit(enemies))){
			if((unitToAttack = getNearestUnit(enemies))){
				if(totalEnemyHealth <= totalAliesHealth){
					attackTo(unitToAttack);
				}else{
					startFleeMode();
				}
			}
			break;
		case Stand:
			break;
	}

}

void ShootingUnit::enemyHasKilled(Unit *unit)
{
	Q_UNUSED(unit);
	stopAttack();

	switch(currentMode){
		case Flee:
			break;
		case Attack:
		case Search:
			startSearchMode();
			break;
		case Stand:
			break;
	}
	QList<QGraphicsItem*> items = scene()->items();
	int itemsCount = items.count();
	Unit *unidad;
	int contEnemies = 0;
	for(int i = 0; i < itemsCount; i++){
		if((unidad = dynamic_cast<Unit*>(items[i]))){
			if(isEnemy(unidad)){
				contEnemies++;
			}
		}
	}
	if(contEnemies == 0){
		if(currentMode != Search){
			startSearchMode();
		}
		PheromoneItem *pi;
		for(int i = 0; i < itemsCount; i++){
			if((pi = dynamic_cast<PheromoneItem*>(items[i]))){
				scene()->removeItem(pi);
				delete pi;
			}
		}
	}
}

void ShootingUnit::checkPointReached(const QPointF &point)
{
	QPointF tmpPos;
	PheromoneItem *next = NULL;
	switch(currentMode){
		case Stand:
			break;
		case Attack:
			if(nextPI){
				tmpPos = nextPI->pos();
				if(tmpPos == QPointF(0,0)){
					startSearchMode();
					break;
				}
				clearPoints();
				if(tmpPos != pos()){
					addPoint(tmpPos);
				}else{
					startSearchMode();
				}
				if((next = nextPI->getMostIntenseNeighbour())){
					nextPI = next;
				}
			}else{
				startSearchMode();
			}
			break;
		case Flee:
			OfensiveUnit::checkPointReached(point);
			pheromoneDepositor->stopPlacePheromone();
			startSearchMode();
			break;
		case Search:
			OfensiveUnit::checkPointReached(point);
			break;
	}

}

void ShootingUnit::checkAll()
{
	OfensiveUnit::checkAll(pos());
}

void ShootingUnit::pheromoneHasBeenDetected(QList<PheromoneItem *> pheromoneList)
{
	switch(currentMode){
		case Attack:
			break;
		case Flee:
			break;
		case Search:
			this->pheromoneList = pheromoneList;
			startAttackMode();
			break;
		case Stand:
			break;
	}
}

void ShootingUnit::pointHasReached(const QPointF &pt)
{
	weapon->startFire(pt);
}

double ShootingUnit::calculateTotalHealth(const QList<Unit *> &units)
{
	int unitCount = units.count();
	double acumHealth = 0;
	for(int i = 0; i < unitCount; i++){
		acumHealth += units[i]->getHealth();
	}
	return acumHealth;
}

Unit *ShootingUnit::getWeakestUnit(const QList<Unit *> &units)
{
	int numUnits = units.count();
	int minHealth = 99999999;
	Unit *unitToReturn = NULL;
	int unHealth;
	for(int i = 0; i < numUnits; i++){
		unHealth = units[i]->getHealth();
		if(unHealth < minHealth){
			unitToReturn = units[i];
			minHealth = unHealth;
		}
	}
	return unitToReturn;
}

Unit *ShootingUnit::getNearestUnit(const QList<Unit *> &units)
{
	int numUnits = units.count();
	int minDist= 99999999;
	Unit *unitToReturn = NULL;
	double currDist;
	for(int i = 0; i < numUnits; i++){
		currDist = distanceBetweenUnits(*this, *units[i]);
		if(currDist < minDist){
			unitToReturn = units[i];
			minDist = currDist;
		}
	}
	return unitToReturn;
}

Unit *ShootingUnit::getBetterUnitToAttack(const QList<Unit *> &enemies)
{
	Q_UNUSED(enemies);

//    int numUnits = units.count();
//    int minHealth = 99999999;
//    Unit *unitToReturn;
//    for(int i = 0; i < numUnits; i++){
//        if(units[i]->getHealth() < minHealth && ){
//            unitToReturn = units[i];
//        }
//    }
//    return unitToReturn;
	return NULL;
}

void ShootingUnit::unitHasReached(Orders order, Unit *un)
{
	switch(order){
		case DoNothing:
		case AttackTo:
			unitToFire = un;
			weapon->startFire(un);
//            secureStartTimer(attackFrequencyTimerID, (1 / weapon->getFrequency()) * 1000);
			timerAttack.start((1 / weapon->getFrequency()) * 1000);
			break;
		case Defend:
		case Move:
		case Follow:
			break;
	}
}

void ShootingUnit::stopAttack(){
	weapon->stopFire();
	timerAttack.stop();
	timerReach.stop();
//    secureKillTimer(reachUnitTimerID);
//    unitToReach = NULL;
//    unitToFire = NULL;
	lastOrders = DoNothing;
	attacking = false;
	update();
}

void ShootingUnit::attackTimerEvent(){
	if(unitToFire && unitToFire->getHealth() != 0){
		if(!isInRange(unitToFire)){
			reach(lastOrders, unitToFire);
		}else{
			weapon->startFire(unitToFire);
		}
	}else{
		stopAttack();
	}
}
