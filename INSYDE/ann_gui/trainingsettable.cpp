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

		updateColumnVisibility();

		connectTSSignals();

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
	//TODO: 12/4/15 setInputsVisible verificar si se puede simplificar haciendo uso del objeto

	inputsVisible = b;

	updateColumnVisibility();
}

bool TrainingSetTable::getInputsVisible() const
{
	return inputsVisible;
}

void TrainingSetTable::setTargetsVisible(bool b)
{
	//TODO: 12/4/15 setTargetsVisible verificar si se puede simplificar haciendo uso del objeto ts

	targetsVisible = b;

	updateColumnVisibility();
}

bool TrainingSetTable::getTargetsVisible() const
{
	return targetsVisible;
}

void TrainingSetTable::onInsertRightColumnTriggered()
{
	int index = horizontalHeader()->logicalIndexAt(horizontalHeader()->viewport()->mapFromGlobal(horizontalHeaderContextMenu->pos()));
	if(index == ts->getInputsSize() - 1){
		ts->appendInputs(0);
	}else{
		BasicTable::onInsertRightColumnTriggered();
	}
}

void TrainingSetTable::onColumnInserted(int column)
{
	(void)column;
	updateColumnVisibility();
}

void TrainingSetTable::onInputsSizeChanged(int lsize, int nsize)
{
	(void)lsize;
	(void)nsize;
	updateColumnVisibility();
}

void TrainingSetTable::onTargetsSizeChanged(int lsize, int nsize)
{
	(void)lsize;
	(void)nsize;
	updateColumnVisibility();
}

void TrainingSetTable::init(TrainingSet *ts)
{
//	getCutAction()->setVisible(false);
	getCutAction()->setEnabled(false);

	inputsVisible = true;
	targetsVisible = true;

	setTrainingSet(ts);

//	setInputsVisible(false);
//	setTargetsVisible(false);

	setFormat('f');
	setPrecision(6);

	setAlternatingRowColors(true);

	verticalHeader()->setVisible(true);
	verticalHeader()->setCascadingSectionResizes(true);
	verticalHeader()->setHighlightSections(true);
	verticalHeader()->setSortIndicatorShown(false);
	verticalHeader()->setStretchLastSection(false);

	horizontalHeader()->setEditTriggers(QAbstractItemView::AllEditTriggers);

	connectTSSignals();
}

void TrainingSetTable::updateColumnVisibility()
{
	//TODO: 12/4/15 setTargetsVisible verificar si se puede simplificar haciendo uso del objeto ts

	int
			inputsSize = ts->getInputsSize(),
			targetsSize = ts->getTargetsSize(),
			tsSize = inputsSize + targetsSize;

//	for(int i = 0; i < tsSize; i++){
//		setColumnHidden(i, false);
//	}

	for(int i = 0; i < tsSize; i++){
		if(i < inputsSize){
			setColumnHidden(i, !inputsVisible);
		}else{
			setColumnHidden(i, !targetsVisible);
		}
	}
}

void TrainingSetTable::connectTSSignals()
{
	connect(ts, SIGNAL(columnInserted(int)), SLOT(onColumnInserted(int)));
	connect(ts, SIGNAL(inputsSizeChanged(int,int)), SLOT(onInputsSizeChanged(int,int)));
	connect(ts, SIGNAL(targetsSizeChanged(int,int)), SLOT(onTargetsSizeChanged(int,int)));
}
