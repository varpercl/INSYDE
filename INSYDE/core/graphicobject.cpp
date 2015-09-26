#include "graphicobject.h"

GraphicObject::GraphicObject()
{
	init(QRect(0,0,50,50), 2);
}


GraphicObject::GraphicObject(const QRectF &rect, int border)
{
	init(rect, border);
}

GraphicObject::~GraphicObject()
{
//	delete inputElement;
//	delete outputElement;
}

void GraphicObject::setContainerRect(const QRectF &rect)
{
	rectangle = rect;
	update();
}

void GraphicObject::setContainerRect(const QRect &rect)
{
	rectangle = QRectF(rect);
	update();
}

QRectF GraphicObject::getContainerRect() const
{
	return rectangle;
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
	}
}

int GraphicObject::getInputsSize() const
{
	return inputsSize;
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
	return GraphicElementType;
}

QPen GraphicObject::getBorder() const
{
	return border;
}

void GraphicObject::setBorder(const QPen &pen)
{
	border = pen;
}

QPainterPath GraphicObject::shape() const
{
	QPainterPath path;
	path.addRect(boundingRect());
	return path;
}

QRectF GraphicObject::boundingRect() const
{
	int border = this->border.width();
	return rectangle.adjusted(-(border + sep), -(border + sep), (border + sep), (border + sep));
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

void GraphicObject::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
	contextMenu.exec(event->screenPos());
}

void GraphicObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	(void)widget;
	painter->save();

	painter->setPen(border);

	if(option->state & (QStyle::State_Selected | QStyle::State_MouseOver)) {
		painter->setBrush(QColor(240,240,240));
		painter->drawRect(boundingRect());
	}else{
		painter->drawRect(rectangle);
	}

	painter->restore();
}

void GraphicObject::removeClick()
{
	scene()->removeItem(this);
}

void GraphicObject::openClick()
{
	//TODO: implementar para que abra automaticamente este objeto en un nuevo QGraphicsView
}

void GraphicObject::init(const QRectF &rect, int border)
{
#if _MSC_VER == 1600 || __GNUC__
	setAcceptHoverEvents(true);
#else
	setAcceptsHoverEvents(true);
#endif
	setFlags(ItemIsMovable | ItemIsSelectable);

	//NOTE: se esta evaluando el uso de esta variable con su respectivo metodo
	//Determina el ancho del marco de este objeto.
	sep = 5;

	openAction = contextMenu.addAction(ICON_OPEN_WINDOWT, "Abrir en ventana", this, SLOT(openClick()));
	saveAction = contextMenu.addAction(ICON_SAVE, "Guardar...", this, SLOT(saveClick()));
	contextMenu.addSeparator();
	setCopyAction(contextMenu.addAction(ICON_COPY, "Copiar", this, SLOT(copyClick())));
	setCutAction(contextMenu.addAction(ICON_CUT, "Cortar", this, SLOT(cutClick())));
	setPasteAction(contextMenu.addAction(ICON_PASTE, "Pegar", this, SLOT(pasteClick())));
	contextMenu.addSeparator();
	removeAction = contextMenu.addAction(ICON_DELETE, "Eliminar", this, SLOT(removeClick()));
	propertiesAction = contextMenu.addAction(ICON_PROPERTIES, "Propiedades...", this, SLOT(propertyClick()));

	setBorder(QPen(Qt::black, border));
	setContainerRect(rect);
}
