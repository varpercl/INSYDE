#include "binaryoutputelement.h"

BinaryOutputElement::BinaryOutputElement(int inputs, BinaryOutputElement::Align a, double threshold, BinaryOutputElement::ThresholdType tt)
{
	initBOR(inputs, a, threshold, tt);
}

void BinaryOutputElement::setInputSize(int inputs)
{
	if(aligment == Vertical){
		intRect = QRectF(5, 5, 9, inputs*7 + 2);
		setContainerRect(intRect.adjusted(-5, -5, 5, 5));
	}else{
		intRect = QRectF(5, 5, inputs*7 + 2, 9);
		setContainerRect(intRect.adjusted(-5, -5, 5, 5));
	}
	this->inputs.resize(inputs);
	update();
}


void BinaryOutputElement::setInputs(const QVector<double> &inputs)
{
	if(this->inputs.size() != inputs.size()){
		setInputSize(inputs.size());
	}
	this->inputs = inputs;
}

QVector<double> BinaryOutputElement::getInputs()
{
	return inputs;
}

QVector<bool> BinaryOutputElement::getBinaryInputs()
{
	int selIndex = 0;
	double selMayorValue = -999999999;
	double selMinorValue = 999999999;
	int sInputs = inputs.size();
	QVector<bool> output(sInputs);
	for(int i = 0; i < sInputs; i++){
		switch(tt){
			case LESS_THAN:
				output[i] = (inputs[i] < threshold ? true : false);
				break;
			case LESS_EQUAL_THAN:
				output[i] = (inputs[i] <= threshold ? true : false);
				break;
			case GREATER_THAN:
				output[i] = (inputs[i] > threshold ? true : false);
				break;
			case GREATER_EQUAL_THAN:
				output[i] = (inputs[i] >= threshold ? true : false);
				break;
			case GREATER_THAN_ALL:
				if(inputs[i] > selMayorValue){
					selIndex = i;
					selMayorValue = inputs[i];
				}
				output[i] = false;
				if(i == sInputs - 1){
					output[selIndex] = true;
				}
				break;
			case LESS_THAN_ALL:
				if(inputs[i] < selMinorValue){
					selIndex = i;
					selMinorValue = inputs[i];
				}
				output[i] = false;
				if(i == sInputs - 1){
					output[selIndex] = true;
				}
				break;
		}
	}
	return output;
}

void BinaryOutputElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	GraphicObject::paint(painter, option, widget);

	painter->save();
	painter->setBrush(Qt::white);
	painter->drawRect(intRect);

	QVector<bool> binrep = getBinaryInputs();
	int sInputs = binrep.size();
	for(int i = 0; i < sInputs; i++){
		painter->setBrush(binrep[i] ? Qt::black : Qt::white);
		if(aligment == Vertical){
			painter->drawRect(QRectF(intRect.x()+2, intRect.y() + (i*7) + 2, 5, 5));
		}else{
			painter->drawRect(QRectF(intRect.x() + (i*7) + 2, intRect.y() + 2, 5, 5));
		}
	}
	painter->restore();
}

void BinaryOutputElement::onInputChanged(QVector<double> input)
{
	setInputs(input);
}

void BinaryOutputElement::propertyClick()
{

}

void BinaryOutputElement::openOnWindowClick()
{
}

void BinaryOutputElement::initBOR(int inputs, Align a, double threshold, ThresholdType tt)
{
	intRect = boundingRect().adjusted(5, 5, -5, -5);
	setAligment(a);
	setInputSize(inputs);
	setThresholdType(tt);
	setThreshold(threshold);
}

void BinaryOutputElement::setAligment(BinaryOutputElement::Align a)
{
	aligment = a;
	update();
}

BinaryOutputElement::Align BinaryOutputElement::getAligment()
{
	return aligment;
}

void BinaryOutputElement::setThresholdType(BinaryOutputElement::ThresholdType tt)
{
	this->tt = tt;
	update();
}

void BinaryOutputElement::setThreshold(double threshold)
{
	this->threshold = threshold;
	update();
}

void BinaryOutputElement::setInputElement(GraphicObject *ge)
{
	switch(ge->type()){
		case GraphicObject::gotMLP:
			MLPObject *gmlpe = dynamic_cast<MLPObject*>(ge);
			gmlpe->setOutputElement(this);
			connect(gmlpe, SIGNAL(outputChanged(QVector<double>)), SLOT(onInputChanged(QVector<double>)));
			break;
	}
	inputElement = ge;
}

int BinaryOutputElement::type() const
{
	return BinaryOutputRepresentationType;
}
