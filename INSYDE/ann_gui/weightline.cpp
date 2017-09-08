#include "perceptrondisplay.h"

ann_gui::WeightLine::WeightLine(const QLineF &line, SimplePerceptron *sp, int index, QGraphicsItem *parent) :
	QObject(), QGraphicsLineItem(line, parent)
{
//    Q_INIT_RESOURCE(ann_gui_media); //never call it inside a namespace, instead use a wrapper function

	init(sp, index);
}//WeightLine

ann_gui::WeightLine::WeightLine(const QLineF &line, double weight, double maxWeight, double minWeight, int lineWidth, SimplePerceptron *sp, int index, QGraphicsItem *parent) :
	QObject(), QGraphicsLineItem(line, parent)
{
//    Q_INIT_RESOURCE(ann_gui_media); //never call it inside a namespace, instead use a wrapper function

	init(sp, index, weight, maxWeight, minWeight, lineWidth);
}//WeightLine

ann_gui::WeightLine::~WeightLine()
{
}//WeightLine

void ann_gui::WeightLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	//TODO: evaluate if applicable
	QGraphicsLineItem::paint(painter,option,widget);
}//paint

void ann_gui::WeightLine::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	QGraphicsLineItem::hoverEnterEvent(event);

	setPen(QPen(QBrush(wlColor), lineWidth + 1));

}//hoverEnterEvent

void ann_gui::WeightLine::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	QGraphicsLineItem::hoverLeaveEvent(event);

	setPen(QPen(QBrush(wlColor), lineWidth));
}//hoverLeaveEvent

void ann_gui::WeightLine::mousePressEvent(QGraphicsSceneMouseEvent *event)
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

void ann_gui::WeightLine::focusOutEvent(QFocusEvent *event)
{
	QGraphicsLineItem::focusOutEvent(event);

}//focusOutEvent

void ann_gui::WeightLine::init(SimplePerceptron *sp, int index, double weight, double maxW, double minW, int lineWidth)
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

void ann_gui::WeightLine::setWeightValue(double w)
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

double ann_gui::WeightLine::getWeightValue() const
{
	return weight;
}//getWeightValue

void ann_gui::WeightLine::setMaxWeightValue(double wu)
{
	weightUpper = wu;
}//setWeightUpper

double ann_gui::WeightLine::getMaxWeightValue() const
{
	return weightUpper;
}//getWeightUpper

void ann_gui::WeightLine::setMinWeightValue(double wl)
{
	weightLower = wl;
}//setMinWeightValue

double ann_gui::WeightLine::getMinWeightValue() const
{
	return weightLower;
}//getMinWeightValue

void ann_gui::WeightLine::setLineWidht(int lw)
{
	lineWidth = lw;

	setPen(QPen(QBrush(wlColor), lineWidth));
//	update();
}//setLineWidht

int ann_gui::WeightLine::getLineWidth() const
{
	return lineWidth;
}//getLineWidth

void ann_gui::WeightLine::setAutomaticWeightLimits(bool aw)
{
	automaticWeightsLimit = aw;
}

bool ann_gui::WeightLine::getAutomaticWeightLimit() const
{
	return automaticWeightsLimit;
}

void ann_gui::WeightLine::setWeightIndex(int i)
{
	wi = i;
}

int ann_gui::WeightLine::getWeightIndex() const
{
	return wi;
}

QColor ann_gui::WeightLine::getWeightLineColor() const
{
	return wlColor;
}

void ann_gui::WeightLine::updateWeightColor()
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
