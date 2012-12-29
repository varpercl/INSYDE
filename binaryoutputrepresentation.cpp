#include "binaryoutputrepresentation.h"

BinaryOutputRepresentation::BinaryOutputRepresentation(int inputs):
	GraphicElement()
{
	initBOR(inputs);
}

void BinaryOutputRepresentation::setInputSize(int inputs)
{
	nInputs = inputs;
}

void BinaryOutputRepresentation::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	GraphicElement::paint(painter, option, widget);

	painter->save();
	painter->drawRect(boundingRect().adjusted(5, 5, -5, -5));
	painter->setBrush(Qt::red);
	for(int i = 0; i < nInputs; i++){
		painter->drawRect(QRectF(6, (i*6)+1, 5, 5));
	}
	painter->restore();
}

void BinaryOutputRepresentation::initBOR(int inputs)
{
	setInputSize(inputs);
}
