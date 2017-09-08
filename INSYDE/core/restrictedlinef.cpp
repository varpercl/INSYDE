#include "restrictedlinef.h"

core::RestrictedLineF::RestrictedLineF() :
	QLineF()
{
//    Q_INIT_RESOURCE(core_media);
	lineConstrain = None;
}

core::RestrictedLineF::RestrictedLineF(const QPointF &p1, const QPointF &p2, Constrain lc)
//	QLineF(p1, p2)
{
//    Q_INIT_RESOURCE(core_media);
	lineConstrain = lc;
	setP1(p1);
	setP2(p2);
}

core::RestrictedLineF::RestrictedLineF(qreal x1, qreal y1, qreal x2, qreal y2, Constrain lc)
//	QLineF(x1, x2, y1, y2)
{
//    Q_INIT_RESOURCE(core_media);
	lineConstrain = lc;
	setP1(QPointF(x1, y1));
	setP2(QPointF(x2, y2));
}

core::RestrictedLineF::~RestrictedLineF()
{
	
}

void core::RestrictedLineF::setConstrain(RestrictedLineF::Constrain lc)
{
	lineConstrain = lc;
	switch(lineConstrain){
		case RestrictedLineF::HorizontalLeft:
		case RestrictedLineF::HorizontalRight:
		case RestrictedLineF::Horizontal:
			setP2(QPointF(p2().x(), p1().y()));
			break;
		case RestrictedLineF::VerticalUp:
		case RestrictedLineF::VerticalDown:
		case RestrictedLineF::Vertical:
			setP2(QPointF(p1().x(), p2().y()));
			break;
		case RestrictedLineF::Both:
		case RestrictedLineF::None:
			break;

	}
}

core::RestrictedLineF::Constrain core::RestrictedLineF::getConstrain() const
{
	return lineConstrain;
}

void core::RestrictedLineF::setP1(const QPointF &p1)
{
	switch(lineConstrain){
		case RestrictedLineF::HorizontalLeft:
			QLineF::setP1(p1);

			if(p2().x() <= p1.x()){
				setP2(QPointF(p2().x(), p1.y()));
			}else{
				setP2(p1);
			}

			break;
		case RestrictedLineF::HorizontalRight:
			QLineF::setP1(p1);

			if(p2().x() >= p1.x()){
				setP2(QPointF(p2().x(), p1.y()));
			}else{
				setP2(p1);
			}
			break;
		case RestrictedLineF::Horizontal:
			QLineF::setP1(p1);
			setP2(QPointF(p2().x(), p1.y()));
			break;

		case RestrictedLineF::VerticalUp:
			QLineF::setP1(p1);

			if(p2().y() <= p1.y()){
				setP2(QPointF(p1.x(), p2().y()));
			}else{
				setP2(p1);
			}
			break;
		case RestrictedLineF::VerticalDown:
			QLineF::setP1(p1);

			if(p2().y() >= p1.y()){
				setP2(QPointF(p1.x(), p2().y()));
			}else{
				setP2(p1);
			}
			break;
		case RestrictedLineF::Vertical:
			QLineF::setP1(p1);
			setP2(QPointF(p1.x(), p2().y()));
			break;
		case RestrictedLineF::None:
			QLineF::setP1(p1);
			break;
		case RestrictedLineF::Both:
		default:
			break;
	}
}

void core::RestrictedLineF::setP2(const QPointF &p2)
{
	switch(lineConstrain){
		case RestrictedLineF::HorizontalLeft:

			if(p2.x() <= p1().x()){
				QLineF::setP2(QPointF(p2.x(), p1().y()));
			}else{
				QLineF::setP2(p1());
			}

			break;
		case RestrictedLineF::HorizontalRight:
			if(p2.x() >= p1().x()){
				QLineF::setP2(QPointF(p2.x(), p1().y()));
			}else{
				QLineF::setP2(p1());
			}
			break;
		case RestrictedLineF::Horizontal:
			QLineF::setP2(QPointF(p2.x(), p1().y()));
			break;
		case RestrictedLineF::VerticalUp:
			if(p2.y() <= p1().y()){
				QLineF::setP2(QPointF(p1().x(), p2.y()));
			}else{
				QLineF::setP2(p1());
			}
			break;
		case RestrictedLineF::VerticalDown:
			if(p2.y() >= p1().y()){
				QLineF::setP2(QPointF(p1().x(), p2.y()));
			}else{
				QLineF::setP2(p1());
			}
			break;
		case RestrictedLineF::Vertical:
			QLineF::setP2(QPointF(p1().x(), p2.y()));
			break;
		case RestrictedLineF::None:
			QLineF::setP2(p2);
			break;
		case RestrictedLineF::Both:
		default:
			break;

	}
}

QPointF core::RestrictedLineF::getCorrectedP2(const QPointF &p2)
{
	switch(lineConstrain){
		case RestrictedLineF::HorizontalLeft:
			if(p2.x() <= p1().x()){
				return QPointF(p2.x(), p1().y());
			}else{
				return p1();
			}
		case RestrictedLineF::HorizontalRight:
			if(p2.x() >= p1().x()){
				return QPointF(p2.x(), p1().y());
			}else{
				return p1();
			}
		case RestrictedLineF::Horizontal:
			return QPointF(p2.x(), p1().y());
		case RestrictedLineF::VerticalUp:
			if(p2.y() <= p1().y()){
				return QPointF(p1().x(), p2.y());
			}else{
				return p1();
			}
		case RestrictedLineF::VerticalDown:
			if(p2.y() >= p1().y()){
				return QPointF(p1().x(), p2.y());
			}else{
				return p1();
			}
		case RestrictedLineF::Vertical:
			return QPointF(p1().x(), p2.y());
		case RestrictedLineF::Both:
			return this->p2();
		case RestrictedLineF::None:
		default:
			return p2;

	}
}

void core::RestrictedLineF::setPoints(const QPointF &p1, const QPointF &p2)
{
	switch(lineConstrain){
		case RestrictedLineF::HorizontalLeft:
			if(p2.x() <= p1.x()){
				QLineF::setPoints(p1, QPointF(p2.x(), p1.y()));
			}else{
				QLineF::setPoints(p1, p1);
			}
			break;
		case RestrictedLineF::HorizontalRight:
			if(p2.x() >= p1.x()){
				QLineF::setPoints(p1, QPointF(p2.x(), p1.y()));
			}else{
				QLineF::setPoints(p1, p1);
			}
			break;
		case RestrictedLineF::VerticalUp:
			if(p2.y() <= p1.y()){
				QLineF::setPoints(p1, QPointF(p1.x(), p2.y()));
			}else{
				QLineF::setPoints(p1, p1);
			}
			break;
		case RestrictedLineF::VerticalDown:
			if(p2.y() >= p1.y()){
				QLineF::setPoints(p1, QPointF(p1.x(), p2.y()));
			}else{
				QLineF::setPoints(p1, p1);
			}
			break;
		case RestrictedLineF::Horizontal:
			QLineF::setPoints(p1, QPointF(p2.x(), p1.y()));
			break;
		case RestrictedLineF::Vertical:
			QLineF::setPoints(p1, QPointF(p1.x(), p2.y()));
			break;
		case RestrictedLineF::None:
			QLineF::setPoints(p1, p2);
			break;
		case RestrictedLineF::Both:
		default:
			break;
	}
}

bool core::RestrictedLineF::isHorizontal() const
{
	qreal lineAngle = angle();
	if(lineAngle == 0 || lineAngle == 180){
		return true;
	}
	return false;
}

bool core::RestrictedLineF::isVertical() const
{
	qreal lineAngle = angle();
	if(lineAngle == 90 || lineAngle == 270){
		return true;
	}
	return false;
}

//RestrictedLineF &RestrictedLineF::operator=(const RestrictedLineF &rl)
//{

//}

