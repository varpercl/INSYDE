#include "graphicobject.h"

GraphicObject::GraphicObject() :
	QGraphicsObject()
{
	init(QRect(0,0,50,50), 1);
}


GraphicObject::GraphicObject(const QRectF &rect, int border) :
	QGraphicsObject()
{
	init(rect, border);
}

GraphicObject::~GraphicObject()
{

}

void GraphicObject::setContainerRect(const QRectF &rect)
{
	containerRect = rect;


	QPointF center = rect.center();

	double borderWidth = getBorder().widthF();

	topLeftResizeRect.setCoords(rect.top() - resizeRectSize, rect.left() - resizeRectSize, rect.top(), rect.left());

	topCenterResizeRect.setCoords(center.x() - (resizeRectSize / 2) - borderWidth, rect.top() - resizeRectSize, center.x() + (resizeRectSize / 2) + borderWidth, rect.top());

	topRightResizeRect.setCoords(rect.right(), rect.top() - resizeRectSize, rect.right() + resizeRectSize, rect.top());

	bottomLeftResizeRect.setCoords(rect.left() - resizeRectSize, rect.bottom(), rect.left(), rect.bottom() + resizeRectSize);

	bottomCenterResizeRect.setCoords(center.x() - (resizeRectSize / 2) - borderWidth / 2, rect.bottom(), center.x() + (resizeRectSize / 2) + borderWidth, rect.bottom() + resizeRectSize);

	bottomRightResizeRect.setCoords(rect.right(), rect.bottom(), rect.right() + resizeRectSize, rect.bottom() + resizeRectSize);

	leftCenterResizeRect.setCoords(rect.left() - resizeRectSize, center.y() - (resizeRectSize / 2) - borderWidth, rect.left(), center.y() + (resizeRectSize / 2) + borderWidth);

	rightCenterResizeRect.setCoords(rect.right(), center.y() - (resizeRectSize / 2) - borderWidth, rect.right() + resizeRectSize, center.y() + (resizeRectSize / 2) + borderWidth);

	update();
}

void GraphicObject::setContainerRect(const QRect &rect)
{
	setContainerRect(QRectF(rect));
}

QRectF GraphicObject::getContainerRect() const
{
	return containerRect;
}

void GraphicObject::setInputs(const vector<double> &vec)
{
	inputs = vec;
}

vector<double> GraphicObject::getInputs() const
{
	return inputs;
}

void GraphicObject::setInputsSize(int size)
{
	if(inputsSize != size){
		inputsSize = size;
		update(getContainerRect());

		emit inputsSizeChanged(size);
	}
}

int GraphicObject::getInputsSize() const
{
	return inputsSize;
}

void GraphicObject::setInputElement(GraphicObject *ge)
{
	inputElement = ge;
}

GraphicObject *GraphicObject::getInputElement() const
{
	return inputElement;
}

void GraphicObject::setOutputElement(GraphicObject *ge)
{
	outputElement = ge;
}

GraphicObject *GraphicObject::getOutputElement() const
{
	return outputElement;
}

int GraphicObject::type() const
{
	return gotGraphicObject;
}

QPen GraphicObject::getBorder() const
{
	return border;
}

void GraphicObject::setBorder(const QPen &pen)
{
	border = pen;
}

QRectF GraphicObject::boundingRect() const
{
	int border = this->border.width();

	if(resizeRectSize >= portSensitivity){
		return containerRect.adjusted(-(border + resizeRectSize), -(border + resizeRectSize), (border + resizeRectSize), (border + resizeRectSize));
	}else{
		return containerRect.adjusted(-(border + portSensitivity), -(border + portSensitivity), (border + portSensitivity), (border + portSensitivity));
	}
}

QAction *GraphicObject::getOpenAction() const
{
	return openAction;
}

QAction *GraphicObject::getSaveAction() const
{
	return saveAction;
}

QAction *GraphicObject::getRemoveAction() const
{
	return removeAction;
}

QAction *GraphicObject::getPropertiesAction() const
{
	return propertiesAction;
}

void GraphicObject::setObjectLocked(bool locked)
{
	setFlag(QGraphicsItem::ItemIsMovable, !locked);
	lockAction->blockSignals(true);
	lockAction->setChecked(locked);
	lockAction->blockSignals(false);
	objectLocked = locked;
}

bool GraphicObject::getObjectLocked() const
{
	return objectLocked;
}

void GraphicObject::setSimulation(Simulation *sim)
{
	simulation = sim;
}

Simulation *GraphicObject::getSimulation() const
{
	return simulation;
}

QAction *GraphicObject::getLockAction() const
{
	return lockAction;
}

GraphicObject::Port GraphicObject::getCurrentPort()
{
	if(nearPort(portTop)){
		return portTop;
	}else if(nearPort(portBottom)){
		return portBottom;
	}else if(nearPort(portLeft)){
		return portLeft;
	}else if(nearPort(portRight)){
		return portRight;
	}else{
		return portNone;
	}
}

GraphicObject::Port GraphicObject::getCurrentPort(const QPoint &pos)
{
	return getCurrentPort(QPointF(pos));
}

GraphicObject::Port GraphicObject::getCurrentPort(const QPointF &pos)
{
	if(nearPort(pos, portTop)){
		return portTop;
	}else if(nearPort(pos, portBottom)){
		return portBottom;
	}else if(nearPort(pos, portLeft)){
		return portLeft;
	}else if(nearPort(pos, portRight)){
		return portRight;
	}else{
		return portNone;
	}
}

QPointF GraphicObject::getCurrentPortPos()
{
	QPointF center = containerRect.center();

	if(nearPort(portTop)){
		return QPointF(center.x(), containerRect.top());
	}else if(nearPort(portBottom)){
		return QPointF(center.x(), containerRect.bottom());
	}else if(nearPort(portLeft)){
		return QPointF(containerRect.left(), center.y());
	}else if(nearPort(portRight)){
		return QPointF(containerRect.right(), center.y());
	}else{
		return containerRect.center();
	}
}

QPointF GraphicObject::getCurrentPortPos(const QPointF &pos)
{
	QPointF center = containerRect.center();

	if(nearPort(pos, portTop)){
		return QPointF(center.x(), containerRect.top());
	}else if(nearPort(pos, portBottom)){
		return QPointF(center.x(), containerRect.bottom());
	}else if(nearPort(pos, portLeft)){
		return QPointF(containerRect.left(), center.y());
	}else if(nearPort(pos, portRight)){
		return QPointF(containerRect.right(), center.y());
	}else{
		return containerRect.center();
	}
}

QPointF GraphicObject::getCurrentPortPos(const QPoint &pos)
{
	return getCurrentPortPos(QPointF(pos));
}

void GraphicObject::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
	contextMenu.exec(event->screenPos());
}

void GraphicObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	(void)widget;
	painter->save();

	painter->setPen(border);

	painter->setBrush(QColor(240,240,240));

	if((option->state & (QStyle::State_Selected/* | QStyle::State_MouseOver*/)) && !objectLocked) {

		painter->drawRect(topLeftResizeRect);
		painter->drawRect(topCenterResizeRect);
		painter->drawRect(topRightResizeRect);

		painter->drawRect(bottomLeftResizeRect);
		painter->drawRect(bottomCenterResizeRect);
		painter->drawRect(bottomRightResizeRect);

		painter->drawRect(leftCenterResizeRect);
		painter->drawRect(rightCenterResizeRect);

		if(topLeftResizeRect.contains(currentMousePos)){
			painter->fillRect(topLeftResizeRect, Qt::black);
		}
		if(topCenterResizeRect.contains(currentMousePos)){
			painter->fillRect(topCenterResizeRect, Qt::black);
		}
		if(topRightResizeRect.contains(currentMousePos)){
			painter->fillRect(topRightResizeRect, Qt::black);
		}
		if(bottomLeftResizeRect.contains(currentMousePos)){
			painter->fillRect(bottomLeftResizeRect, Qt::black);
		}
		if(bottomCenterResizeRect.contains(currentMousePos)){
			painter->fillRect(bottomCenterResizeRect, Qt::black);
		}
		if(bottomRightResizeRect.contains(currentMousePos)){
			painter->fillRect(bottomRightResizeRect, Qt::black);
		}
		if(leftCenterResizeRect.contains(currentMousePos)){
			painter->fillRect(leftCenterResizeRect, Qt::black);
		}
		if(rightCenterResizeRect.contains(currentMousePos)){
			painter->fillRect(rightCenterResizeRect, Qt::black);
		}
	}else{
		if(nearPort(portTop)){
			painter->fillRect(topCenterResizeRect, Qt::black);
		}
		if(nearPort(portBottom)){
			painter->fillRect(bottomCenterResizeRect, Qt::black);
		}
		if(nearPort(portLeft)){
			painter->fillRect(leftCenterResizeRect, Qt::black);
		}
		if(nearPort(portRight)){
			painter->fillRect(rightCenterResizeRect, Qt::black);
		}
	}

	painter->drawRect(containerRect.adjusted(-border.widthF(), -border.widthF(), 0, 0));

	painter->restore();
}

void GraphicObject::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
//	QGraphicsObject::hoverEnterEvent(event;
	currentMousePos = event->pos();

	update();
}

bool GraphicObject::nearPort(const QPointF &pos, GraphicObject::Port reference) const
{
	QPointF center = containerRect.center();

	switch(reference){
		case GraphicObject::portTop:
			return math::distance(pos, QPointF(center.x(), containerRect.top())) <= portSensitivity/* && !containerRect.contains(pos)*/;
			break;
		case GraphicObject::portBottom:
			return math::distance(pos, QPointF(center.x(), containerRect.bottom())) <= portSensitivity/* && !containerRect.contains(pos)*/;
			break;
		case GraphicObject::portLeft:
			return math::distance(pos, QPointF(containerRect.left(), center.y())) <= portSensitivity/* && !containerRect.contains(pos)*/;
			break;
		case GraphicObject::portRight:
			return math::distance(pos, QPointF(containerRect.right(), center.y())) <= portSensitivity/* && !containerRect.contains(pos)*/;
			break;

		case GraphicObject::portNone:
		default:
			return false;
			break;
	}
}

void GraphicObject::removeClick()
{
	scene()->removeItem(this);

	simulation->remove(this);

	emit objectRemoved(this);
}

void GraphicObject::openOnWindowClick()
{
	emit openOnWindowRequest(this);
}

void GraphicObject::init(const QRectF &rect, int border)
{
	setAcceptHoverEvents(true);

	setFlags(ItemIsMovable | ItemIsSelectable);

	resizeRectSize = 6;

	portSensitivity = 15;

	openAction = contextMenu.addAction(ICON_OPEN_WINDOWT, "Abrir en ventana", this, SLOT(openOnWindowClick()));
	saveAction = contextMenu.addAction(ICON_SAVE, "Guardar...", this, SLOT(saveClick()));
	//TODO: 10/5/16 implement correct procedures to save any object
	saveAction->setEnabled(false);

	contextMenu.addSeparator();
	setCopyAction(contextMenu.addAction(ICON_COPY, "Copiar", this, SLOT(copyClick())));
	setCutAction(contextMenu.addAction(ICON_CUT, "Cortar", this, SLOT(cutClick())));
	setPasteAction(contextMenu.addAction(ICON_PASTE, "Pegar", this, SLOT(pasteClick())));

	//TODO: 10/5/16 implement correct clipboard handling
	getCopyAction()->setEnabled(false);
	getCutAction()->setEnabled(false);
	getPasteAction()->setEnabled(false);

	contextMenu.addSeparator();
	lockAction = contextMenu.addAction(ICON_PADLOCK, "Bloquear", this, SLOT(setObjectLocked(bool)));
	lockAction->setCheckable(true);
	contextMenu.addSeparator();
	removeAction = contextMenu.addAction(ICON_DELETE, "Eliminar", this, SLOT(removeClick()));
	propertiesAction = contextMenu.addAction(ICON_PROPERTIES, "Propiedades...", this, SLOT(propertyClick()));

	setObjectLocked(false);
	setBorder(QPen(Qt::black, border));
	setContainerRect(rect);
}

bool GraphicObject::nearPort(Port reference) const
{
	QPointF center = containerRect.center();

	switch(reference){
		case GraphicObject::portTop:
			return math::distance(currentMousePos, QPointF(center.x(), containerRect.top())) <= portSensitivity/* && !containerRect.contains(currentMousePos)*/;
			break;
		case GraphicObject::portBottom:
			return math::distance(currentMousePos, QPointF(center.x(), containerRect.bottom())) <= portSensitivity/* && !containerRect.contains(currentMousePos)*/;
			break;
		case GraphicObject::portLeft:
			return math::distance(currentMousePos, QPointF(containerRect.left(), center.y())) <= portSensitivity/* && !containerRect.contains(currentMousePos)*/;
			break;
		case GraphicObject::portRight:
			return math::distance(currentMousePos, QPointF(containerRect.right(), center.y())) <= portSensitivity/* && !containerRect.contains(currentMousePos)*/;
			break;

		case GraphicObject::portNone:
		default:
			return false;
			break;
	}

}


void GraphicObject::setSize(const QSizeF &size)
{
	containerRect.setSize(size);
	update();
}

QSizeF GraphicObject::getSize() const
{
	return containerRect.size();
}

void GraphicObject::setWidth(double w)
{
	containerRect.setWidth(w);
	update();
}

double GraphicObject::getWidth() const
{
	return containerRect.width();
}

void GraphicObject::setHeight(double h)
{
	containerRect.setHeight(h);
	update();
}

double GraphicObject::getHeight() const
{
	return containerRect.height();
}

void GraphicObject::setResizeRectSize(double size)
{
	resizeRectSize = size;
	update();
}

void GraphicObject::setPortSensitivity(double sensitivity)
{
	portSensitivity = sensitivity;
}
