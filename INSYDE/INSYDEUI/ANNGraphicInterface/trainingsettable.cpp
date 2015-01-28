#include "trainingsettable.h"

TrainingSetTable::TrainingSetTable(TrainingSet *ts, QWidget *parent) :
	QTableView(parent),
	ts(0)
{
	init(ts);
}

void TrainingSetTable::setTrainingSet(TrainingSet *ts)
{
	if(this->ts == 0 || this->ts != ts){
		this->ts = ts;
		setModel(this->ts);

		setInputsVisible(inputsVisible);
		setTargetsVisible(targetsVisible);
		connectSignals();

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
	targetsVisible = b;
}

bool TrainingSetTable::getTargetsVisible() const
{
	return targetsVisible;
}

void TrainingSetTable::init(TrainingSet *ts)
{
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

void TrainingSetTable::updateHeaders()
{

	//TODO: validar si es necesario este metodo
//	TrainingSet *tempTS = getTrainingSet();
//	QStringList headers;
//	int iSize = tempTS->getInputsSize();
//	//FIXME: corregir problema con getTargetSize que es llamado antes de que se haya establecido el tamaño del patron de salida
//	//esto genera un numero extremadamente elevado que hace que el ciclo casi nunca termine
//	int tSize = tempTS->getTargetsSize();
//	for(int i = 0; i < iSize; i++){
//		headers.append("In " + QString::number(i+1));
//	}
//	for(int i = iSize; i < iSize + tSize; i++){
//		headers.append("Out " + QString::number(i - iSize + 1));
//	}
//	setHorizontalHeaderLabels(headers);
}

void TrainingSetTable::connectSignals()
{
	//TODO: verificar cual de estas es en realidad necesaria
//	connect(this->ts, SIGNAL(inputsChanged(vector<vector<double> >, vector<vector<double> >)), SLOT(onInputsChanged(vector<vector<double> >,vector<vector<double> >)));
//	connect(this->ts, SIGNAL(targetsChanged(vector<vector<double> >,vector<vector<double> >)), SLOT(onTargetsChanged(vector<vector<double> >,vector<vector<double> >)));
//	connect(this->ts, SIGNAL(inputSizeChanged(int,int)), SLOT(onInputSizeChanged(int, int)));
//	connect(this->ts, SIGNAL(targetSizeChanged(int,int)), SLOT(onTargetSizeChanged(int, int)));
//	connect(this->ts, SIGNAL(patternAdded(vector<double>,vector<double>)), SLOT(onPatternAdded(vector<double>,vector<double>)));
//	connect(this->ts, SIGNAL(patternDeleted(vector<double>,vector<double>,int)), SLOT(onPatternDeleted(vector<double>,vector<double>,int)));
//	connect(this->ts, SIGNAL(patternInserted(vector<double>,vector<double>,int)), SLOT(onPatternInserted(vector<double>,vector<double>,int)));
//	connect(this->ts, SIGNAL(inputChanged(int,int,double)), SLOT(onInputChanged(int,int,double)));
//	connect(this->ts, SIGNAL(targetChanged(int,int,double)), SLOT(onTargetChanged(int,int,double)));
//	connect(this->ts, SIGNAL(patternChanged(int,vector<double>,vector<double>)), SLOT(onPatternChanged(int,vector<double>,vector<double>)));
}

//void TrainingSetTable::onInputsChanged(const vector<vector<double> > &li, const vector<vector<double> > &ni)
//{
//	//	setColumnCount(ts->getTargetSize() + ts->getInputSize());

//	size_t iCurSize = ni[0].size();
//	if(li[0].size() != iCurSize){
//		onInputSizeChanged(li[0].size(), iCurSize);
//	}
//	size_t sPatterns = ni.size();

//	blockSignals(true);
//	for(size_t i = 0; i < sPatterns; i++){
//		for(size_t j = 0; j < iCurSize; j++){
//			QTableWidgetItem *itm = new QTableWidgetItem(QString::number(ni[i][j], format, decimalPrecision));
//			itm->setTextAlignment(Qt::AlignRight);
//			setItem(i, j, itm);
//		}
//	}
//	blockSignals(false);
//}

//void TrainingSetTable::onTargetsChanged(const vector<vector<double> > &lt, const vector<vector<double> > &nt)
//{
//	size_t tCurSize = nt[0].size();
//	size_t iCurSize = ts->getInputsSize();
//	//En caso de que las dimensiones no sean iguales se actualiza el tamaño de la tabla
//	if(lt[0].size() != tCurSize){
//		onTargetSizeChanged(lt[0].size(), tCurSize);
//	}
//	size_t sPatterns = nt.size();

//	blockSignals(true);
//	for(size_t i = 0; i < sPatterns; i++){
//		for(size_t j = iCurSize; j < iCurSize + tCurSize; j++){
//			QTableWidgetItem *itm = new QTableWidgetItem(QString::number(nt[i][j-iCurSize], format, decimalPrecision));
//			itm->setTextAlignment(Qt::AlignRight);
//			setItem(i, j, itm);
//		}
//	}
//	blockSignals(false);
//}

//void TrainingSetTable::onInputSizeChanged(int ls, int ns)
//{
//	int nPatterns = ts->getPatternCount();
//	blockSignals(true);
//	if(ls < ns){
//		for(int i = ls-1; i < ns; i++){
//			insertColumn(i);
//			for(int j = 0; j < nPatterns; j++){
//				QTableWidgetItem *itm = new QTableWidgetItem(QString::number(0));
//				itm->setTextAlignment(Qt::AlignRight);
//				setItem(i, j, itm);
//			}
//		}
//	}else if(ls > ns){
//		for(int i = ls-1; i >= ns; i--){
//			removeColumn(i);
//		}
//	}
//	blockSignals(false);
//	updateHeaders();
//}

//void TrainingSetTable::onTargetSizeChanged(int ls, int ns)
//{
//	//FIXME: se debe implementar el slot con un unico parametro si en realidad no se usara el parametro ls
//	(void)ls;
//	setColumnCount(ts->getInputsSize() + ns);
//	updateHeaders();
//}

//void TrainingSetTable::onPatternAdded(const vector<double> &inputs, const vector<double> &targets)
//{
//	privateAppendPattern(inputs, targets);
//}

//void TrainingSetTable::onPatternDeleted(const vector<double> &inputs, const vector<double> &targets, int index)
//{
//	(void)inputs;
//	(void)targets;

//	//NOTE: se debe validar el funcionamiento de este metodo
//	removeRow(index);
//	//	rootIndex().model()->removeRow(index);
//}

//void TrainingSetTable::onPatternInserted(const vector<double> &inputs, const vector<double> &targets, int index)
//{
//	//TODO: terminar de implementar este metodo
//	(void)inputs;
//	(void)targets;
//	insertRow(index);
//}

//void TrainingSetTable::onCellChanged(int row, int col)
//{
//	//NOTE: debido a que el valor de la entrada esta siendo modificada desde una celda
//	//de la tabla, no se debe llamar nuevamente a onInputChanged o onTargetChanged
//	//ya que habria una recursividad. En este caso se bloquean las señales del objeto
//	//TrainingSet para evitar que se emita la señal inputChanged o targetChanged
//	int iSize = ts->getInputsSize();
//	ts->blockSignals(true);
//	if(col < iSize-1){
//		ts->setInput(row, col, item(row, col)->text().toDouble());
//	}else{
//		ts->setTarget(row, col - iSize, item(row, col)->text().toDouble());
//	}
//	ts->blockSignals(false);
//}

//void TrainingSetTable::onInputChanged(int pat, int index, double value)
//{
//	QTableWidgetItem *itm = new QTableWidgetItem(QString::number(value));
//	itm->setTextAlignment(Qt::AlignRight);
//	setItem(pat, index, itm);
//}

//void TrainingSetTable::onTargetChanged(int pat, int index, double value)
//{
//	QTableWidgetItem *itm = new QTableWidgetItem(QString::number(value));
//	itm->setTextAlignment(Qt::AlignRight);
//	setItem(pat, index + ts->getInputsSize(), itm);
//}

//void TrainingSetTable::onPatternChanged(int index, const vector<double> &inputs, const vector<double> &targets)
//{
//	QTableWidgetItem *itm;
//	int iSize = ts->getInputsSize();
//	for(int col = 0; col < columnCount(); col++){
//		if(col < iSize){
//			itm = new QTableWidgetItem(QString::number(inputs[col]));
//		}else{
//			itm = new QTableWidgetItem(QString::number(targets[col - iSize]));
//		}
//		itm->setTextAlignment(Qt::AlignRight);
//		setItem(index, col + ts->getInputsSize(), itm);
//	}
//}
