#include "perceptrondisplay.h"

WeightLine::WeightLine(const QLineF &line, SimplePerceptron *sp, int index, QGraphicsItem *parent) :
	QObject(), QGraphicsLineItem(line, parent)
{
	initWL(sp, index);
}//WeightLine

WeightLine::WeightLine(const QLineF &line, double weight, double maxWeight, double minWeight, int lineWidth, SimplePerceptron *sp, int index, QGraphicsItem *parent) :
	QObject(), QGraphicsLineItem(line, parent)
{
	initWL(sp, index, weight, maxWeight, minWeight, lineWidth);
}//WeightLine

WeightLine::~WeightLine()
{
}//WeightLine

void WeightLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QGraphicsLineItem::paint(painter,option,widget);
}//paint

void WeightLine::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	QGraphicsLineItem::hoverEnterEvent(event);

	setPen(QPen(QBrush(wlColor), lineWidth + 1));

}//hoverEnterEvent

void WeightLine::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	QGraphicsLineItem::hoverLeaveEvent(event);

	setPen(QPen(QBrush(wlColor), lineWidth));
}//hoverLeaveEvent

void WeightLine::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsLineItem::mousePressEvent(event);

	QInputDialog *id = new QInputDialog();
	id->setWindowTitle("Inserte nuevo valor");
	id->setLabelText("Valor");
	id->setInputMode(QInputDialog::DoubleInput);
	id->setDoubleMinimum(-999999);
	id->setDoubleMaximum(999999);
	id->setDoubleDecimals(6);
	id->setDoubleValue(getWeightValue());

	if(id->exec() == QInputDialog::Accepted){
		setWeightValue(id->doubleValue());
	}

	delete id;
}//mousePressEvent

void WeightLine::focusOutEvent(QFocusEvent *event)
{
	QGraphicsLineItem::focusOutEvent(event);

}//focusOutEvent

void WeightLine::initWL(SimplePerceptron *sp, int index, double weight, double maxW, double minW, int lineWidth)
{
	this->sp = sp;

	setAcceptHoverEvents(true);
	setFlags(ItemIsFocusable);

	setWeightIndex(index);
	setMaxWeightValue(maxW);
	setMinWeightValue(minW);
	setWeightValue(weight);
	setLineWidht(lineWidth);

}//initWL

void WeightLine::setWeightValue(double w)
{
	//Set weight value for this WeightLine
	//respecting limits
	if(w <= weightUpper && w >= weightLower){
		weight = w;
	}else if(w > weightUpper){
		weight = weightUpper;
	}else{
		weight = weightLower;
	}
	double before = getWeightValue();
	sp->setWeight(getWeightIndex(), w);

	updateWeightColor();

	emit weightValueChanged(getWeightIndex(), before, getWeightValue());
}//setWeightValue

double WeightLine::getWeightValue() const
{
	return weight;
}//getWeightValue

void WeightLine::setMaxWeightValue(double wu)
{
	weightUpper = wu;
}//setWeightUpper

double WeightLine::getMaxWeightValue() const
{
	return weightUpper;
}//getWeightUpper

void WeightLine::setMinWeightValue(double wl)
{
	weightLower = wl;
}//setMinWeightValue

double WeightLine::getMinWeightValue() const
{
	return weightLower;
}//getMinWeightValue

void WeightLine::setLineWidht(int lw)
{
	lineWidth = lw;

	setPen(QPen(QBrush(wlColor), lineWidth));
//	update();
}//setLineWidht

int WeightLine::getLineWidth() const
{
	return lineWidth;
}//getLineWidth

void WeightLine::setAutomaticWeightLimits(bool aw)
{
	automaticWeightsLimit = aw;
}

bool WeightLine::getAutomaticWeightLimit() const
{
	return automaticWeightsLimit;
}

void WeightLine::setWeightIndex(int i)
{
	wi = i;
}

int WeightLine::getWeightIndex() const
{
	return wi;
}

QColor WeightLine::getWeightLineColor() const
{
	return wlColor;
}

void WeightLine::updateWeightColor()
{
	double nValue;
	if(automaticWeightsLimit){
		vector<double> weights = sp->getWeightsVector();
		double
				maxW = *max_element(weights.begin(), weights.end()),
				minW = *min_element(weights.begin(), weights.end());
		nValue = fabs((weight - minW)/(maxW - minW));
	}else{
		nValue = fabs((weight - weightLower)/(weightUpper - weightLower));
	}
	int
			rComponent = nValue <= 0.5 ? 255 : 512 * (1 - nValue),
			gComponent = nValue <= 0.5 ? 512 * nValue : 255;

	wlColor = qRgb(rComponent, gComponent, 0);

	setPen(QPen(QBrush(wlColor), lineWidth));
}
