#include "connector.h"

Connector::Connector() :
	GraphicObject()
{
	init(0, 0);
}

Connector::Connector(GraphicObject *begin, GraphicObject *end) :
	GraphicObject()
{
	init(begin, end);
}

Connector::~Connector()
{

}

int Connector::type() const
{
	return gotConnector;
}

void Connector::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	(void)option;
	(void)widget;

//	GraphicObject::paint(painter, option, widget);
	QPen newPen;
	painter->save();

	newPen.setWidth(3);
	newPen.setBrush(Qt::green);

	painter->setPen(newPen);
	painter->drawPath(shape());

//	painter->drawLines(composedLine);

	painter->restore();

	painter->drawRect(boundingRect());
}

bool Connector::eventFilter(QObject *sender, QEvent *event)
{
//	qDebug () << event->type();
	if(event->type() == QEvent::MouseMove){
		QMouseEvent *hEvent = (QMouseEvent*)event;

		GraphicDetailedView *gdv = (GraphicDetailedView*)sender;

		QPointF pos = mapFromScene(gdv->mapToScene(hEvent->pos()));
		currentMousePos = pos;

//		qDebug() << currentMousePos << "<< currentMousePos";

		QRectF container = getContainerRect();

		if(pos.x() < 0 && pos.y() < 0){
			container.setTopLeft(pos);
			container.setBottomRight(QPointF(0, 0));
		}else if(pos.x() < 0 && pos.y() >= 0){
			container.setBottomLeft(pos);
			container.setTopRight(QPointF(0, 0));
		}else if(pos.x() >= 0 && pos.y() < 0){
			container.setTopRight(pos);
			container.setBottomLeft(QPointF(0, 0));
		}else if(pos.x() >= 0 && pos.y() >= 0){
			container.setBottomRight(pos);
			container.setTopLeft(QPointF(0, 0));
		}else{
			container= QRectF(0, 0, 0, 0);
		}

		setContainerRect(container);

		if(isBuildingConector){
			updateConectorLine(beginPoint, pos);
		}

		return true;
	}

	return GraphicObject::eventFilter(sender, event);
}

QRectF Connector::boundingRect() const
{
	return shapeForm.boundingRect();
}

QPainterPath Connector::shape() const
{
	QPainterPath path;
	path.addPolygon(shapeForm);
	return path;
}

QSizeF Connector::getSize() const
{
	return getContainerRect().size();
}

double Connector::getWidth() const
{
	return getContainerRect().width();
}

double Connector::getHeight() const
{
	return getContainerRect().height();
}

void Connector::setInputElement(GraphicObject *ge)
{
	(void)ge;
	//TODO: 05/24/16 setInputElement must be implemented
}

QString Connector::getXML() const
{
	//TODO: 05/19/16 getXML must be implemented
	return "";
}

void Connector::setBeginObject(GraphicObject *begin)
{
	if(!begin){
		isBuildingConector = false;
		return;
	}


	beginObject = begin;

//	beginPoint = mapFromItem(begin, begin->getCurrentPortPos());
	beginPoint = QPointF(0,0);
	isBuildingConector = true;
	setZValue(-1);
	setPos(mapToScene(mapFromItem(begin, begin->getCurrentPortPos())));

//	connect(begin, SIGNAL())
}

void Connector::setEndObject(GraphicObject *end)
{
	if(!end) return;

	endObject = end;

//	qDebug() << currentMousePos;
	//we use currentMousePos instead internal currentMousePos from "end" object due update mouse position problems
	//there are conflicts when moving mouse so using this currentMousePos ensures mouse pos is always updated

//	qDebug() << portRect;
	endPoint = mapFromItem(end, end->getCurrentPortPos(mapToItem(end, currentMousePos)));
	isBuildingConector = false;
//	qDebug() << portCenter;

	QRectF container = getContainerRect();


	if(currentMousePos.x() < 0 && currentMousePos.y() < 0){
		container.setTopLeft(endPoint );
	}else if(currentMousePos.x() < 0 && currentMousePos.y() >= 0){
		container.setBottomLeft(endPoint );
	}else if(currentMousePos.x() >= 0 && currentMousePos.y() < 0){
		container.setTopRight(endPoint );
	}else if(currentMousePos.x() >= 0 && currentMousePos.y() >= 0){
		container.setBottomRight(endPoint );
	}else{
		container= QRectF(0, 0, 0, 0);
	}

	setContainerRect(container);
}

void Connector::propertyClick()
{
	//TODO: 14/5/16 propertyClick must be implemented
}

void Connector::init(GraphicObject *begin, GraphicObject *end)
{
	clearance = 10;

	beginObject = begin;
	endObject = end;

	isBuildingConector = false;

	getSaveAction()->setVisible(false);
	getOpenAction()->setVisible(false);
	getCopyAction()->setVisible(false);
	getCutAction()->setVisible(false);
	getPasteAction()->setVisible(false);

	setContainerRect(QRectF(0, 0, 0, 0));
	setObjectLocked(true);
}

void Connector::updateConectorLine(const QPointF &begin, const QPointF &end)
{

	const double MIN_LENGHT = 10;

//	QLineF line(begin, end);

	QList<QGraphicsItem*>
			collidingItemsEndOfLine,
			collidingItemsMiddleLine,
			fullList;

//	QGraphicsItem *closerItem;
//	QRectF closerItemRect;

//	QPointF
//			correctedEnd = end,
//			midPoint,
//			mappedMidPoint;

	if(composedLine.isEmpty()){

		Port p = beginObject->getCurrentPort(mapToItem(beginObject, begin));

		RestrictedLineF *firstLine = new RestrictedLineF(begin, end);

		switch(p){
			case GraphicObject::portBottom:
				firstLine->setConstrain(RestrictedLineF::VerticalDown);
				break;
			case GraphicObject::portTop:
				firstLine->setConstrain(RestrictedLineF::VerticalUp);
				break;
			case GraphicObject::portLeft:
				firstLine->setConstrain(RestrictedLineF::HorizontalLeft);
				break;
			case GraphicObject::portRight:
				firstLine->setConstrain(RestrictedLineF::HorizontalRight);
				break;
				
			case GraphicObject::portNone:
			default:
				firstLine->setConstrain(RestrictedLineF::None);
				break;
		}
		composedLine.push_back(firstLine);

		shapeForm.push_back(firstLine->p1());
		shapeForm.push_back(firstLine->p2());
	}

	QGraphicsScene *env = scene();

	QList<CollidingResult> colItems = collidingObjects(composedLine);

//	for(int i = 0; i < colItems.size(); i++){
//		colItems[i].line->setConstrain(RestrictedLineF::Both);
//	}

	RestrictedLineF
			temptativeLine,
			*curLine;
	for(auto i = composedLine.size()-1; i >= 0; i--){
		curLine = composedLine[i];
		temptativeLine = *curLine;
		if(i == composedLine.size() - 1){

			if(env){
				fullList = env->items(mapToScene(end));
				collidingItemsEndOfLine = removeIgnoredObjects(fullList);

				if(composedLine.size() > 1){
					fullList = env->items(mapToScene(composedLine[i - 1]->getCorrectedP2(end)));
					collidingItemsMiddleLine = removeIgnoredObjects(fullList);
				}

				if(collidingItemsEndOfLine.isEmpty() && collidingItemsMiddleLine.isEmpty()){
					if(composedLine.size() > 1){
						composedLine[i - 1]->setP2(end);
						curLine->setP1(composedLine[i - 1]->p2());
						shapeForm[i] = composedLine[i - 1]->p2();
					}


					//Set the point p2 to curLine (it will be corrected against restrictions)
					curLine->setP2(end);
					shapeForm[i + 1] = curLine->p2();

					//calculates the distance between corrected p2 of curLine and current end point
					if(math::distance(curLine->p2(), end) >= MIN_LENGHT &&
							!curLine->isNull() &&
							!(i = 1 && composedLine[0]->isNull())){

						RestrictedLineF::Constrain restriction;

						switch (curLine->getConstrain()) {
							case RestrictedLineF::HorizontalRight:
							case RestrictedLineF::HorizontalLeft:
							case RestrictedLineF::Horizontal:
								restriction = RestrictedLineF::Vertical;
								break;

							case RestrictedLineF::VerticalUp:
							case RestrictedLineF::VerticalDown:
							case RestrictedLineF::Vertical:
								restriction = RestrictedLineF::Horizontal;
								break;
							case RestrictedLineF::Both:
								if(fabs(curLine->p2().x() - end.x()) >= fabs(curLine->p2().y() - end.y())){
									restriction = RestrictedLineF::Horizontal;
								}else{
									restriction = RestrictedLineF::Vertical;
								}
								break;
							case RestrictedLineF::None:
							default:
								restriction = RestrictedLineF::None;
								break;
						}

						RestrictedLineF *newLine = new RestrictedLineF(curLine->p2(), end, restriction);

						composedLine.push_back(newLine);
						//use in case shapeForm be QPainterPath
//						shapeForm.lineTo(newLine->p2());

						//use in case shapeForm be QPolygonF
//						shapeForm[i + 1]
						shapeForm.push_back(newLine->p2());
					}
				}
			}
		}else if(i == composedLine.size() - 2){

		}

		if(curLine->length() < MIN_LENGHT && i != 0){
			composedLine.remove(i);
			shapeForm.remove(i+1);
		}else if(i == 1){
			if(composedLine[i - 1]->isNull()){
				composedLine.remove(i);
				shapeForm.remove(i+1);
			}
		}
	}

//	shapeForm = QPainterPath(begin);

////	shapeForm
//	for(auto i = 0; i < composedLine.size(); i++){
//		shapeForm.lineTo(composedLine[i]->p2());
//	}
//	//Only for debug process. Can be simplified
//	midPoint = QPointF(end.x(), 0);
//	mappedMidPoint = mapToScene(midPoint);

//	fullList = collidingItems(Qt::IntersectsItemShape);
//	itemListAt = removeIgnoredObjects(fullList);

//	if(fabs(line.dx()) >= fabs(line.dy())){
//		if(itemListAt.size() > 0){
//			if(midPoint.x() >= 0){
//				closerItem = closerItemPerif(midPoint, portLeft, itemListAt);

//				closerItemRect = mapFromItem(closerItem, closerItem->boundingRect()).boundingRect();

//				midPoint.setX(closerItemRect.left()/* - clearance*/);
//				correctedEnd.setX(closerItemRect.left());
//			}else{
//				closerItem = closerItemPerif(midPoint, portRight, itemListAt);

//				closerItemRect = mapFromItem(closerItem, closerItem->boundingRect()).boundingRect();

//				midPoint.setX(closerItemRect.right()/* + clearance*/);
//				correctedEnd.setX(closerItemRect.right());
//			}
//		}
////		composedLine.push_back(QLineF(begin, midPoint));
////		composedLine.push_back(QLineF(midPoint, correctedEnd));
//	}else{
//		if(itemListAt.size() > 0){
//			if(midPoint.y() >= 0){
//				closerItem = closerItemPerif(midPoint, portTop, itemListAt);

//				closerItemRect = mapFromItem(closerItem, closerItem->boundingRect()).boundingRect();

//				midPoint.setY(closerItemRect.top()/* - clearance*/);
//				correctedEnd.setY(closerItemRect.top());
//			}else{
//				closerItem = closerItemPerif(midPoint, portBottom, itemListAt);

//				closerItemRect = mapFromItem(closerItem, closerItem->boundingRect()).boundingRect();

//				midPoint.setY(closerItemRect.bottom()/* + clearance*/);
//				correctedEnd.setY(closerItemRect.bottom());
//			}
//		}
//	}

//	composedLine.clear();
//	composedLine.push_back(QLineF(begin, midPoint));
//	composedLine.push_back(QLineF(midPoint, correctedEnd));
}

QList<QGraphicsItem *> Connector::removeIgnoredObjects(const QList<QGraphicsItem *> &list) const
{
	GraphicObject *obj;
	QList<QGraphicsItem*> returnedList = list;

	for(auto i = 0; i < returnedList.size(); i++){
		obj = (GraphicObject*)returnedList[i];

		if(obj->type() == gotConnector || obj == beginObject){
			returnedList.removeOne(obj);
			i--;
		}
	}

	return returnedList;
}

QList<GraphicObject *> Connector::removeIgnoredObjects(const QList<GraphicObject *> &list) const
{
	GraphicObject *obj;
	QList<GraphicObject*> returnedList = list;

	for(auto i = 0; i < returnedList.size(); i++){
		obj = returnedList[i];

		if(obj->type() == gotConnector || obj == beginObject){
			returnedList.removeOne(obj);
			i--;
		}
	}

	return returnedList;
}

QGraphicsItem *Connector::closerItemPerif(const QPointF &pos, Port side, const QList<QGraphicsItem *> &list)
{
	double
			minDistance = INFINITY,
			curDist = 0;

	int choosenIndex = 0;

	QRectF rect;

	if(side == portNone || list.size() == 0) return 0;

	for(int i = 0; i < list.size(); i++){
		rect = list[i]->boundingRect();

		switch(side){
			case GraphicObject::portTop:
				curDist = fabs(pos.y() - rect.top());
				break;
			case GraphicObject::portBottom:
				curDist = fabs(pos.y() - rect.bottom());
				break;
			case GraphicObject::portLeft:
				curDist = fabs(pos.y() - rect.left());
				break;
			case GraphicObject::portRight:
				curDist = fabs(pos.y() - rect.right());
				break;
			case GraphicObject::portNone:
			default:
				break;
		}
		if(curDist < minDistance){
			minDistance = curDist;
			choosenIndex = i;
		}
	}

	return list[choosenIndex];
}

QList<Connector::CollidingResult> Connector::collidingObjects(const QVector<RestrictedLineF *> &lines) const
{
	QList<Connector::CollidingResult> result;

	CollidingResult intersectionResult;

	QList<QGraphicsItem*> items = removeIgnoredObjects(collidingItems(Qt::IntersectsItemShape));
//	QList<QGraphicsItem*> items = removeIgnoredObjects(scene()->items());

	QVector<RestrictedLineF*> rectLines;

	QLineF::IntersectType intersection;

	QPointF *intersectionPoint = new QPointF();

	for(int l = 0; l < lines.size(); l++){

		intersectionResult.line = lines[l];
		intersectionResult.lineIndex = l;

		for(int o = 0; o < items.size(); o++){

			intersectionResult.objects.push_back((GraphicObject*)items[o]);

			rectLines = convertRect(items[o]->boundingRect());

			for(int rLine = 0; rLine < 4; rLine++){
				intersection = lines[l]->intersect(*rectLines[rLine], intersectionPoint);
				if(intersection == QLineF::BoundedIntersection){
					intersectionResult.points.push_back(new QPointF(*intersectionPoint));
				}
			}
		}
		if(!intersectionResult.points.isEmpty()){
			result.push_back(intersectionResult);
		}
	}
	return result;
}

QVector<RestrictedLineF *> Connector::convertRect(const QRectF &rect) const
{
	QVector<RestrictedLineF*> result;
	RestrictedLineF
			*topLine,
			*bottomLine,
			*leftLine,
			*rightLine;

	topLine = new RestrictedLineF(rect.topLeft(), rect.topRight());
	bottomLine = new RestrictedLineF(rect.bottomLeft(), rect.bottomRight());

	if(topLine->angle() == 0){
		topLine->setConstrain(RestrictedLineF::HorizontalRight);
		bottomLine->setConstrain(RestrictedLineF::HorizontalRight);
	}else if(topLine->angle() == 180){
		topLine->setConstrain(RestrictedLineF::HorizontalLeft);
		bottomLine->setConstrain(RestrictedLineF::HorizontalLeft);
	}

	leftLine = new RestrictedLineF(rect.topLeft(), rect.bottomLeft());
	rightLine = new RestrictedLineF(rect.topRight(), rect.bottomRight());

	if(leftLine->angle() == 90){
		leftLine->setConstrain(RestrictedLineF::VerticalUp);
		rightLine->setConstrain(RestrictedLineF::VerticalUp);
	}else if(leftLine->angle() == 270){
		leftLine->setConstrain(RestrictedLineF::VerticalDown);
		rightLine->setConstrain(RestrictedLineF::VerticalDown);
	}

	result.push_back(topLine);
	result.push_back(rightLine);
	result.push_back(bottomLine);
	result.push_back(leftLine);

	return result;
}
