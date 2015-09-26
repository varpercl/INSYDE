#include "trainingsettable.h"

TrainingSetTable::TrainingSetTable(TrainingSet *ts, QWidget *parent) :
	BasicTable(parent),
	ts(0)
{
	init(ts);
}

void TrainingSetTable::setTrainingSet(TrainingSet *ts)
{
	if(this->ts == 0 || this->ts != ts){
		this->ts = ts;
		setModel(this->ts);

//		resizeColumnsToContents();
		setInputsVisible(inputsVisible);
		setTargetsVisible(targetsVisible);

		emit trainingSetChanged(ts);
	}
}

TrainingSet *TrainingSetTable::getTrainingSet() const
{
	return ts;
}

void TrainingSetTable::setPrecision(int precision)
{
	decimalPrecision = precision;
}

int TrainingSetTable::getPrecision() const
{
	return decimalPrecision;
}

void TrainingSetTable::setFormat(char format)
{
	this->format = format;
}

char TrainingSetTable::getFormat() const
{
	return format;
}

void TrainingSetTable::setInputsVisible(bool b)
{
	//TODO: verificar si se puede simplificar haciendo uso del objeto ts

	size_t sInputs = ts->getInputsSize();

	for(size_t i = 0; i < sInputs; i++){
		if(b){
			if(isColumnHidden(i)){
				showColumn(i);
			}
		}else{
			if(!isColumnHidden(i)){
				hideColumn(i);
			}
		}
	}
	inputsVisible = b;
}

bool TrainingSetTable::getInputsVisible() const
{
	return inputsVisible;
}

void TrainingSetTable::setTargetsVisible(bool b)
{
	//TODO: verificar si se puede simplificar haciendo uso del objeto ts

	size_t
			sInputs = ts->getInputsSize(),
			sTargets = ts->getTargetsSize();

	for(size_t i = sInputs; i < sInputs + sTargets; i++){
		setColumnHidden(i, !b);
	}
	targetsVisible = b;
}

bool TrainingSetTable::getTargetsVisible() const
{
	return targetsVisible;
}

void TrainingSetTable::init(TrainingSet *ts)
{
//	getCutAction()->setVisible(false);
	getCutAction()->setEnabled(false);

	setTrainingSet(ts);

	setInputsVisible(true);
	setTargetsVisible(true);
	setFormat('f');
	setPrecision(6);

	setAlternatingRowColors(true);

	verticalHeader()->setVisible(true);
	verticalHeader()->setCascadingSectionResizes(true);
	verticalHeader()->setHighlightSections(true);
	verticalHeader()->setSortIndicatorShown(false);
	verticalHeader()->setStretchLastSection(false);

	horizontalHeader()->setEditTriggers(QAbstractItemView::AllEditTriggers);

	selectRow(0);

}
