#include "shootingweapon.h"


ShootingWeapon::ShootingWeapon(ShootingUnit *agent) : Actuator(agent)
{

	initSW(20, 100, 1);
}

ShootingWeapon::ShootingWeapon(ShootingUnit *agent, int power, int range, int frequency) : Actuator(static_cast<Agent*>(agent))
{
	initSW(power, range, frequency);
}

void ShootingWeapon::initSW(int power, int range, int frequency){
	timerID = 0;
	timerGarbageCollectorID = 0;
	unitToShoot = 0;
	timerInterval = 20;
	incProyectile = 0;
	setPower(power);
	setRange(range);
	setFrequency(frequency);
	setProyectileVelocity(1000);
}

ShootingWeapon::~ShootingWeapon()
{
	unitToShoot = NULL;
	secureKillTimer(timerID);
	secureKillTimer(timerGarbageCollectorID);
}

void ShootingWeapon::updateShape()
{
}

double ShootingWeapon::distanceBetweenUnits(Agent *unit1, Agent *unit2)
{
	if(unit1 && unit2){
		return hypot(unit1->x()-unit2->x(), unit1->y() - unit2->y());
	}else
		return NAN;
}

double ShootingWeapon::distanceBetweenPoints(const QPointF &pt1, const QPointF &pt2)
{
	return hypot(pt1.x() - pt2.x(), pt1.y() - pt2.y());
}

bool ShootingWeapon::canFire(Unit *un)
{
//    Agent *agent = getAgent();
	if(distanceBetweenUnits(getAgent(), un) <= range){
		return true;
	}
	return false;
}

bool ShootingWeapon::canFire(QPointF pt)
{
	if(distanceBetweenPoints(getAgent()->pos(), pt) <= range){
		return true;
	}
	return false;
}

//double ShootingWeapon::getCurrentProyectileDistanceToTarget(Unidad *un)
//{

//}

void ShootingWeapon::setPower(int pow)
{
	power = pow;
}

int ShootingWeapon::getPower()
{
	return power;
}

void ShootingWeapon::setRange(int range)
{
	this->range = range;
}

int ShootingWeapon::getRange()
{
	return range;
}

void ShootingWeapon::setFrequency(double frequency)
{
	this->frequency = frequency;
}

double ShootingWeapon::getFrequency()
{
	return frequency;
}

bool ShootingWeapon::startFire(Unit *un)
{
	if(canFire(un) && un != NULL){
		unitToShoot = un;
		//    int timerInterval = int(distanceBetweenUnits(agent, unitToShoot)/proyectileVelocity);
		secureStartTimer(timerID, timerInterval);
		return true;
	}
	return false;
}

bool ShootingWeapon::startFire(const QPointF &pt)
{
	if(canFire(pt))
	{
		pointToShoot = pt;
		//    int timerInterval = int(distanceBetweenUnits(agent, unitToShoot)/proyectileVelocity);
		secureStartTimer(timerID, timerInterval);
		return true;
	}
	return false;
}

void ShootingWeapon::stopFire()
{
	setShape(QPainterPath());
	unitToShoot = NULL;
	secureKillTimer(timerID);
//    su->update();
}

void ShootingWeapon::setProyectileVelocity(double vel)
{
	proyectileVelocity = vel;
}

double ShootingWeapon::getProyectileVelocity()
{
	return proyectileVelocity;
}

void ShootingWeapon::timerEvent(QTimerEvent *event)
{
	static int proyDistAnt = 999999;

	int eventID = event->timerId();
	if(eventID == timerID){
		QPainterPath path;
		ShootingUnit *su = static_cast<ShootingUnit*>(getAgent());
		if(unitToShoot != NULL && su){
			Vector2D line(su->pos(), unitToShoot->pos());
			line.setModulo(10);

			incProyectile += int(proyectileVelocity * double(timerInterval)/1000);
			QPointF startPoint = Vector2D(float(su->getRadius() + incProyectile), float(line.getAngle())).toPointF();

			double dist = distanceBetweenPoints(su->mapToScene(startPoint + line.toPointF()), unitToShoot->pos());

//            if(dist - proyDistAnt < 0){
			if((dist > unitToShoot->getRadius()) && (dist - proyDistAnt < 0)){
				path.moveTo(startPoint);
				path.lineTo(startPoint + line.toPointF());
				proyDistAnt = dist;
			}else{
				proyDistAnt = 999999;
				incProyectile = 0;
				secureKillTimer(timerID);

				//Decrementa la vitalidad
				unitToShoot->decrementHealth(getPower());

//                emit enemyHitted(su, unitToShoot);

			}
//            }else{
//                incProyectile = 0;
//                killTimer(timerID);
//                timerID = 0;
//                emit unitHitted(unitToShoot);
//            }
		}else{
			secureKillTimer(timerID);
		}
		setShape(path);
		su->update();
	}
//    else if(eventID == timerGarbageCollectorID){
//        foreach(void* item, gcItems){
//            delete item;
//        }
////        delete gcItems;
//        killTimer(timerGarbageCollectorID);
//        timerGarbageCollectorID = 0;
//    }
}

void ShootingWeapon::activateGarbageCollector(int timems)
{
	secureStartTimer(timerGarbageCollectorID, timems);
}

void ShootingWeapon::enemyHitted(OfensiveUnit *au, Unit *unitHitted)
{
	ShootingWeapon *primaryWeapon = dynamic_cast<ShootingWeapon*>(au->getActuator("primary_weapon"));
	unitHitted->decrementHealth(primaryWeapon->getPower());

	if(unitHitted->getHealth() == 0){


//        emit unitKilled(unitHitted);
//        if(unitHitted){
//            unitHitted->setEnabled(false);
//            unitHitted->setVisible(false);
//            au->scene()->removeItem(unitHitted);
//        }
//            if(unitToReach == unitHitted){
//                delete unitToReach;
//                unitToReach = NULL;
//            }
//            if(unitToFire == unitHitted){
//                delete unitToFire;
//                unitToFire = NULL;
//            }
//        delete unitHitted;     //Se debe corregir esto FUGA DE MEMORIA!!!!
	}
//    else{
//        if(pursuitTimerID == 0)
//            pursuitTimerID = startTimer(updatePursuitTime);
//    }
}
