#include "graphicobject.h"

core::GraphicObject::GraphicObject() :
	QGraphicsObject()
{
//    Q_INIT_RESOURCE(core_media);
	init(QRect(0,0,50,50), 1);
}

core::GraphicObject::GraphicObject(const QRectF &rect, int border) :
	QGraphicsObject()
{
//    Q_INIT_RESOURCE(core_media);
	init(rect, border);
}

core::GraphicObject::~GraphicObject()
{

}

void core::GraphicObject::setContainerRect(const QRectF &rect)
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

void core::GraphicObject::setContainerRect(const QRect &rect)
{
	setContainerRect(QRectF(rect));
}

QRectF core::GraphicObject::getContainerRect() const
{
	return containerRect;
}

void core::GraphicObject::setInputs(const vector<double> &vec)
{
	inputs = vec;
}

vector<double> core::GraphicObject::getInputs() const
{
	return inputs;
}

void core::GraphicObject::setInputsSize(int size)
{
	if(inputsSize != size){
		inputsSize = size;
		update(getContainerRect());

		emit inputsSizeChanged(size);
	}
}

int core::GraphicObject::getInputsSize() const
{
	return inputsSize;
}

void core::GraphicObject::setInputElement(GraphicObject *ge)
{
	inputElement = ge;
}

core::GraphicObject *core::GraphicObject::getInputElement() const
{
	return inputElement;
}

void core::GraphicObject::setOutputElement(GraphicObject *ge)
{
	outputElement = ge;
}

core::GraphicObject *core::GraphicObject::getOutputElement() const
{
	return outputElement;
}

int core::GraphicObject::type() const
{
	return gotGraphicObject;
}

QPen core::GraphicObject::getBorder() const
{
	return border;
}

void core::GraphicObject::setBorder(const QPen &pen)
{
	border = pen;
}

QRectF core::GraphicObject::boundingRect() const
{
    int border = this->border.width();

	if(resizeRectSize >= portSensitivity){
		return containerRect.adjusted(-(border + resizeRectSize), -(border + resizeRectSize), (border + resizeRectSize), (border + resizeRectSize));
	}else{
		return containerRect.adjusted(-(border + portSensitivity), -(border + portSensitivity), (border + portSensitivity), (border + portSensitivity));
	}
}

QAction *core::GraphicObject::getOpenAction() const
{
	return openAction;
}

QAction *core::GraphicObject::getSaveAction() const
{
	return saveAction;
}

QAction *core::GraphicObject::getRemoveAction() const
{
	return removeAction;
}

QAction *core::GraphicObject::getPropertiesAction() const
{
	return propertiesAction;
}

void core::GraphicObject::setObjectLocked(bool locked)
{
	setFlag(QGraphicsItem::ItemIsMovable, !locked);
	lockAction->blockSignals(true);
	lockAction->setChecked(locked);
	lockAction->blockSignals(false);
	objectLocked = locked;
}

bool core::GraphicObject::getObjectLocked() const
{
	return objectLocked;
}

void core::GraphicObject::setSimulation(Simulation *sim)
{
	simulation = sim;
}

core::Simulation *core::GraphicObject::getSimulation() const
{
	return simulation;
}

QAction *core::GraphicObject::getLockAction() const
{
	return lockAction;
}

core::GraphicObject::Port core::GraphicObject::getCurrentPort()
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

core::GraphicObject::Port core::GraphicObject::getCurrentPort(const QPoint &pos)
{
	return getCurrentPort(QPointF(pos));
}

core::GraphicObject::Port core::GraphicObject::getCurrentPort(const QPointF &pos)
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

QPointF core::GraphicObject::getCurrentPortPos()
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

QPointF core::GraphicObject::getCurrentPortPos(const QPointF &pos)
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

QPointF core::GraphicObject::getCurrentPortPos(const QPoint &pos)
{
	return getCurrentPortPos(QPointF(pos));
}

void core::GraphicObject::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
	contextMenu.exec(event->screenPos());
}

void core::GraphicObject::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
	if(e->buttons() & Qt::LeftButton && dragging){
		QGraphicsObject::mouseMoveEvent(e);
	}
}

void core::GraphicObject::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
	if(e->buttons() & Qt::LeftButton){
		if(containerRect.contains(e->pos()))
		{
			dragging = true;
		}
	}
}

void core::GraphicObject::mouseReleaseEvent(QGraphicsSceneMouseEvent */*e*/)
{
	dragging = false;
}

void core::GraphicObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

void core::GraphicObject::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
//	QGraphicsObject::hoverEnterEvent(event;
	currentMousePos = event->pos();

	update();
}

bool core::GraphicObject::nearPort(const QPointF &pos, GraphicObject::Port reference) const
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

void core::GraphicObject::removeClick()
{
	scene()->removeItem(this);

	simulation->remove(this);

	emit objectRemoved(this);
}

void core::GraphicObject::openOnWindowClick()
{
	emit openOnWindowRequest(this);
}

void core::GraphicObject::init(const QRectF &rect, int border)
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

bool core::GraphicObject::nearPort(Port reference) const
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


void core::GraphicObject::setSize(const QSizeF &size)
{
	containerRect.setSize(size);
	update();
}

QSizeF core::GraphicObject::getSize() const
{
	return containerRect.size();
}

void core::GraphicObject::setWidth(double w)
{
	containerRect.setWidth(w);
	update();
}

double core::GraphicObject::getWidth() const
{
	return containerRect.width();
}

void core::GraphicObject::setHeight(double h)
{
	containerRect.setHeight(h);
	update();
}

double core::GraphicObject::getHeight() const
{
	return containerRect.height();
}

void core::GraphicObject::setResizeRectSize(double size)
{
	resizeRectSize = size;
	update();
}

void core::GraphicObject::setPortSensitivity(double sensitivity)
{
	portSensitivity = sensitivity;
}
