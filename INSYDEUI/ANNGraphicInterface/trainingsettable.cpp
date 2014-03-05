#include "trainingsettable.h"

TrainingSetTable::TrainingSetTable(TrainingSet *ts, QWidget *parent) :
	QTableWidget(parent),

	//NOTE: se debe inicializar ts para poder tener como compararlo con los
	//nuevos TrainingSets que se vayan a asignar (setTrainingSet())
	ts(new TrainingSet)
{
	initTST(ts);
}

void TrainingSetTable::setTrainingSet(TrainingSet *ts)
{
	//NOTE: se evito la validacion de contenido dado que hay ocasiones en las que se puede asignar un distinto puntero
	//aunque el contenido sea el mismo.
	//	if(*(this->ts) != *ts){
	if(this->ts != ts){
		this->ts->disconnect();
//		disconnect(this->ts, 0, 0, 0);

		this->ts = ts;

//		clear();
		setRowCount(0);

		//TODO: implementar señales que ignoren el valor anterior
		onInputSizeChanged(this->ts->getInputSize(), ts->getInputSize());
		onTargetSizeChanged(this->ts->getTargetSize(), ts->getTargetSize());
		int tsSize = ts->getPatternCount();
		vector<vector<double> >
				inputs = ts->getInputs(),
				targets = ts->getTargets();
		for(int i = 0; i < tsSize; i++){
			privateAppendPattern(inputs[i], targets[i]);
		}

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

void TrainingSetTable::initTST(TrainingSet *ts)
{
	setFormat('f');
	setPrecision(6);
	setAlternatingRowColors(true);
	setRowCount(0);
	setColumnCount(0);
	verticalHeader()->setVisible(true);
	verticalHeader()->setCascadingSectionResizes(true);
	verticalHeader()->setHighlightSections(true);
	verticalHeader()->setProperty("showSortIndicator", QVariant(false));
	verticalHeader()->setStretchLastSection(false);

	horizontalHeader()->setEditTriggers(QAbstractItemView::AllEditTriggers);

	selectRow(0);

	setTrainingSet(ts);

//	int sColumn = columnCount();
//	for(int i = 0; i < sColumn; i++){
//		horizontalHeaderItem(i)->setFlags(Qt::ItemIsEditable |
//										  Qt::ItemIsEnabled |
//										  Qt::ItemIsSelectable);
//	}
//	connectTSSignals();

	//	connect(this, SIGNAL(currentCellChanged(int,int,int,int)), SLOT(onCurrentCellChanged(int,int,int,int)));
	connect(this, SIGNAL(cellChanged(int,int)), SLOT(onCellChanged(int,int)));
}

void TrainingSetTable::updateHeaders()
{
	TrainingSet *tempTS = getTrainingSet();
	QStringList headers;
	int iSize = tempTS->getInputSize();
	//FIXME: corregir problema con getTargetSize que es llamado antes de que se haya establecido el tamaño del patron de salida
	//esto genera un numero extremadamente elevado que hace que el ciclo casi nunca termine
	int tSize = tempTS->getTargetSize();
	for(int i = 0; i < iSize; i++){
		headers.append("In " + QString::number(i+1));
	}
	for(int i = iSize; i < iSize + tSize; i++){
		headers.append("Out " + QString::number(i - iSize + 1));
	}
	setHorizontalHeaderLabels(headers);
}

void TrainingSetTable::connectTSSignals()
{
	connect(this->ts, SIGNAL(inputsChanged(vector<vector<double> >,vector<vector<double> >)), SLOT(onInputsChanged(vector<vector<double> >,vector<vector<double> >)));
	connect(this->ts, SIGNAL(targetsChanged(vector<vector<double> >,vector<vector<double> >)), SLOT(onTargetsChanged(vector<vector<double> >,vector<vector<double> >)));
	connect(this->ts, SIGNAL(inputSizeChanged(int,int)), SLOT(onInputSizeChanged(int, int)));
	connect(this->ts, SIGNAL(targetSizeChanged(int,int)), SLOT(onTargetSizeChanged(int, int)));

	connect(this->ts, SIGNAL(patternAdded(vector<double>,vector<double>)), SLOT(onPatternAdded(vector<double>,vector<double>)));
//	connect(this->ts, SIGNAL(patternAdded(vector<char>,vector<char>)), SLOT(onPatternAdded(vector<char>,vector<char>)));
//	connect(this->ts, SIGNAL(patternAdded(vector<short int>,vector<short int>)), SLOT(onPatternAdded(vector<short int>,vector<short int>)));
//	connect(this->ts, SIGNAL(patternAdded(vector<int>,vector<int>)), SLOT(onPatternAdded(vector<int>,vector<int>)));
//	connect(this->ts, SIGNAL(patternAdded(vector<long>,vector<long>)), SLOT(onPatternAdded(vector<long>,vector<long>)));
//	connect(this->ts, SIGNAL(patternAdded(vector<float>,vector<float>)), SLOT(onPatternAdded(vector<float>,vector<float>)));
//	connect(this->ts, SIGNAL(patternAdded(vector<long double>,vector<long double>)), SLOT(onPatternAdded(vector<long double>,vector<long double>)));
//	connect(this->ts, SIGNAL(patternAdded(vector<unsigned char>,vector<unsigned char>)), SLOT(onPatternAdded(vector<unsigned char>,vector<unsigned char>)));
//	connect(this->ts, SIGNAL(patternAdded(vector<unsigned short int>,vector<unsigned short int>)), SLOT(onPatternAdded(vector<unsigned short int>,vector<unsigned short int>)));
//	connect(this->ts, SIGNAL(patternAdded(vector<unsigned int>,vector<unsigned int>)), SLOT(onPatternAdded(vector<unsigned int>,vector<unsigned int>)));
//	connect(this->ts, SIGNAL(patternAdded(vector<unsigned long>,vector<unsigned long>)), SLOT(onPatternAdded(vector<unsigned long>,vector<unsigned long>)));
	connect(this->ts, SIGNAL(patternDeleted(vector<double>,vector<double>,int)), SLOT(onPatternDeleted(vector<double>,vector<double>,int)));
	connect(this->ts, SIGNAL(patternInserted(vector<double>,vector<double>,int)), SLOT(onPatternInserted(vector<double>,vector<double>,int)));
	connect(this->ts, SIGNAL(inputChanged(int,int,double)), SLOT(onInputChanged(int,int,double)));
	connect(this->ts, SIGNAL(targetChanged(int,int,double)), SLOT(onTargetChanged(int,int,double)));
	connect(this->ts, SIGNAL(patternChanged(int,vector<double>,vector<double>)), SLOT(onPatternChanged(int,vector<double>,vector<double>)));
}

void TrainingSetTable::onInputsChanged(const vector<vector<double> > &li, const vector<vector<double> > &ni)
{
	//	setColumnCount(ts->getTargetSize() + ts->getInputSize());

	size_t iCurSize = ni[0].size();
	if(li[0].size() != iCurSize){
		onInputSizeChanged(li[0].size(), iCurSize);
		updateHeaders();
	}
	size_t sPatterns = ni.size();

	blockSignals(true);
	for(size_t i = 0; i < sPatterns; i++){
		for(size_t j = 0; j < iCurSize; j++){
			QTableWidgetItem *itm = new QTableWidgetItem(QString::number(ni[i][j], format, decimalPrecision));
			itm->setTextAlignment(Qt::AlignRight);
			setItem(i, j, itm);
		}
	}
	blockSignals(false);
}

void TrainingSetTable::onTargetsChanged(const vector<vector<double> > &lt, const vector<vector<double> > &nt)
{
	size_t tCurSize = nt[0].size();

	//En caso de que las dimensiones no sean iguales se actualiza el tamaño de la tabla
	if(lt[0].size() != tCurSize){
		onInputSizeChanged(lt[0].size(), tCurSize);
	}
	size_t sPatterns = nt.size();

	blockSignals(true);
	for(size_t i = 0; i < sPatterns; i++){
		for(size_t j = 0; j < tCurSize; j++){
			QTableWidgetItem *itm = new QTableWidgetItem(QString::number(nt[i][j], format, decimalPrecision));
			itm->setTextAlignment(Qt::AlignRight);
			setItem(i, j, itm);
		}
	}
	blockSignals(false);
}

void TrainingSetTable::onInputSizeChanged(int ls, int ns)
{
	int nPatterns = ts->getPatternCount();
	blockSignals(true);
	if(ls < ns){
		for(int i = ls-1; i < ns; i++){
			insertColumn(i);
			for(int j = 0; j < nPatterns; j++){
				QTableWidgetItem *itm = new QTableWidgetItem(QString::number(0));
				itm->setTextAlignment(Qt::AlignRight);
				setItem(i, j, itm);
			}
		}
	}else if(ls > ns){
		for(int i = ls-1; i >= ns; i--){
			removeColumn(i);
		}
	}
	blockSignals(false);
	updateHeaders();
}

void TrainingSetTable::onTargetSizeChanged(int ls, int ns)
{
	//FIXME: se debe implementar el slot con un unico parametro si en realidad no se usara el parametro ls
	(void)ls;
	setColumnCount(ts->getInputSize() + ns);
	updateHeaders();
}

void TrainingSetTable::onPatternAdded(const vector<double> &inputs, const vector<double> &targets)
{
	privateAppendPattern(inputs, targets);
}

void TrainingSetTable::onPatternDeleted(const vector<double> &inputs, const vector<double> &targets, int index)
{
	(void)inputs;
	(void)targets;

	//NOTE: se debe validar el funcionamiento de este metodo
	removeRow(index);
	//	rootIndex().model()->removeRow(index);
}

void TrainingSetTable::onPatternInserted(const vector<double> &inputs, const vector<double> &targets, int index)
{
	//TODO: terminar de implementar este metodo
	(void)inputs;
	(void)targets;
	insertRow(index);
}

//void TrainingSetTable::setInputSize(int size, double fill)
//{
//	ts->setInputSize(size, fill);
//}

//int TrainingSetTable::getInputSize() const
//{
//	return ts->getInputSize();
//}

//void TrainingSetTable::setTargetSize(int ts, double fill)
//{
//	this->ts->setTargetSize(ts, fill);
//}

//int TrainingSetTable::getTargetSize() const
//{
//	return ts->getTargetSize();
//}

//void TrainingSetTable::insertPattern(const vector<double> &inputs, const vector<double> &targets, int index)
//{
//	ts->insertPattern(inputs, targets, index);
//}

//void TrainingSetTable::insertPattern(const vector<int> &inputs, const vector<int> &targets, int index)
//{
//	ts->insertPattern(inputs, targets, index);
//}

//void TrainingSetTable::deletePattern(int index)
//{
//	ts->deletePattern(index);
//}

//void TrainingSetTable::setInputs(const vector<vector<double> > &inputs)
//{
//	ts->setInputs(inputs);
//}

//void TrainingSetTable::setInputs(const vector<vector<int> > &inputs)
//{
//	ts->setInputs(inputs);
//}

//void TrainingSetTable::setTargets(const vector<vector<double> > &targets)
//{
//	ts->setTargets(targets);
//}

//void TrainingSetTable::setTargets(const vector<vector<int> > &targets)
//{
//	ts->setTargets(targets);
//}

//vector<vector<double> > TrainingSetTable::getInputs() const
//{
//	return ts->getInputs();
//}//getInputs

//vector<vector<double> > TrainingSetTable::getTargets() const
//{
//	return ts->getTargets();
//}//getTargets

//void TrainingSetTable::normalize(NormalizationType no)
//{
//	ts->normalize(no);
//}

//void TrainingSetTable::addNoiseToInputs(double min, double max)
//{
//	ts->addNoiseToInputs(min, max);
//}

//void TrainingSetTable::addNoiseToInputs(double a)
//{
//	ts->addNoiseToInputs(a);
//}

//void TrainingSetTable::addNoiseToTargets(double min, double max)
//{
//	ts->addNoiseToTargets(min, max);
//}

//void TrainingSetTable::addNoiseToTargets(double a)
//{
//	ts->addNoiseToTargets(a);
//}

//void TrainingSetTable::addNoiseToAll(double min, double max)
//{
//	ts->addNoiseToAll(min, max);
//}

//void TrainingSetTable::addNoiseToAll(double a)
//{
//	ts->addNoiseToAll(a);
//}

//void TrainingSetTable::appendPattern(const vector<double> &inputs, const vector<double> &targets)
//{
//	ts->appendPattern(inputs, targets);
//}

//void TrainingSetTable::appendPattern(const vector<int> &inputs, const vector<int> &targets)
//{
//	ts->appendPattern(inputs, targets);
//}

//void TrainingSetTable::setPatternCount(int s)
//{
//	ts->setPatternCount(s);
//}

//void TrainingSetTable::appendPattern(const vector<float> &inputs, const vector<float> &targets)
//{
//	ts->appendPattern(inputs, targets);
//}

//void TrainingSetTable::appendPattern(const vector<long double> &inputs, const vector<long double> &targets)
//{
//	ts->appendPattern(inputs, targets);
//}

//void TrainingSetTable::appendPattern(const vector<char> &inputs, const vector<char> &targets)
//{
//	ts->appendPattern(inputs, targets);
//}

//void TrainingSetTable::appendPattern(const vector<short> &inputs, const vector<short> &targets)
//{
//	ts->appendPattern(inputs, targets);
//}

//void TrainingSetTable::appendPattern(const vector<long> &inputs, const vector<long> &targets)
//{
//	ts->appendPattern(inputs, targets);
//}

//void TrainingSetTable::appendPattern(const vector<unsigned char> &inputs, const vector<unsigned char> &targets)
//{
//	ts->appendPattern(inputs, targets);
//}

//void TrainingSetTable::appendPattern(const vector<unsigned int> &inputs, const vector<unsigned int> &targets)
//{
//	ts->appendPattern(inputs, targets);
//}

//void TrainingSetTable::appendPattern(const vector<unsigned short> &inputs, const vector<unsigned short> &targets)
//{
//	ts->appendPattern(inputs, targets);
//}

//void TrainingSetTable::appendPattern(const vector<unsigned long> &inputs, const vector<unsigned long> &targets)
//{
//	ts->appendPattern(inputs, targets);
//}

void TrainingSetTable::onCellChanged(int row, int col)
{
	//NOTE: debido a que el valor de la entrada esta siendo modificada desde una celda
	//de la tabla, no se debe llamar nuevamente a onInputChanged o onTargetChanged
	//ya que habria una recursividad. En este caso se bloquean las señales del objeto
	//TrainingSet para evitar que se emita la señal inputChanged o targetChanged
	int iSize = ts->getInputSize();
	ts->blockSignals(true);
	if(col < iSize){
		ts->setInput(row, col, item(row, col)->text().toDouble());
	}else{
		ts->setTarget(row, col - iSize, item(row, col)->text().toDouble());
	}
	ts->blockSignals(false);
}

//void TrainingSetTable::onCurrentCellChanged(int currentRow, int currentCol, int previousRow, int previousCol)
//{
//	//	int nRows = patternTable->rowCount();
//	//	vector<vector<double> >
//	//			inputs/* = vector<vector<double> > (nRows, vector<double>(inputSize, 0))*/;

//	//	inputs.resize(nRows);
//	//	for(int i = 0; i < nRows; i++){
//	//		inputs[i].resize(inputSize);
//	//		for(int j = 0; j < inputSize; j++){
//	//			QTableWidgetItem *itm = patternTable->item(i,j);
//	//			if(itm){
//	//				inputs[i][j] = patternTable->item(i,j)->text().toDouble();
//	//			}else{
//	//				inputs[i][j] = 0;
//	//			}
//	//		}
//	//	}
//	//	return inputs;
////	vector<vector<double> >ts->getInputs();

////	if(currentRow != previousRow && currentRow != -1 && previousRow != -1){
////		ts->blockSignals(true);
////		ts->setInput(currentRow, currentCol, item(i,j)->text().toDouble());
////		ts->blockSignals(false);
////	}
//}

//int TrainingSetTable::getPatternCount() const
//{
//	return ts->getPatternCount();
//}

//void TrainingSetTable::setInput(int pat, int index, double value)
//{
//	ts->setInput(pat, index, value);
//}

//void TrainingSetTable::setTarget(int pattern, int index, double value)
//{
//	ts->setTarget(pattern, index, value);
//}

//double TrainingSetTable::getInput(int pat, int index) const
//{
//	return ts->getInput(pat, index);
//}

//double TrainingSetTable::getTarget(int pat, int index) const
//{
//	return ts->getTarget(pat, index);
//}

//void TrainingSetTable::setPattern(int index, const vector<double> &inputs, const vector<double> &targets)
//{
//	ts->setPattern(index, inputs, targets);
//}

//pair<vector<double>, vector<double> > TrainingSetTable::getPattern(int index) const
//{
//	return ts->getPattern(index);
//}

void TrainingSetTable::onInputChanged(int pat, int index, double value)
{
	QTableWidgetItem *itm = new QTableWidgetItem(QString::number(value));
	itm->setTextAlignment(Qt::AlignRight);
	setItem(pat, index, itm);
}

void TrainingSetTable::onTargetChanged(int pat, int index, double value)
{
	QTableWidgetItem *itm = new QTableWidgetItem(QString::number(value));
	itm->setTextAlignment(Qt::AlignRight);
	setItem(pat, index + ts->getInputSize(), itm);
}

void TrainingSetTable::onPatternChanged(int index, const vector<double> &inputs, const vector<double> &targets)
{
	QTableWidgetItem *itm;
	int iSize = ts->getInputSize();
	for(int col = 0; col < columnCount(); col++){
		if(col < iSize){
			itm = new QTableWidgetItem(QString::number(inputs[col]));
		}else{
			itm = new QTableWidgetItem(QString::number(targets[col - iSize]));
		}
		itm->setTextAlignment(Qt::AlignRight);
		setItem(index, col + ts->getInputSize(), itm);
	}
}

//TrainingSet TrainingSetTable::getNormalized(NormalizationType no) const
//{
//	return ts->getNormalized(no);
//}

//void TrainingSetTable::normalize(double minInputs, double maxInputs, double minTargets, double maxTargets)
//{
//	ts->normalize(minInputs, maxInputs, minTargets, maxTargets);
//}

//void TrainingSetTable::normalize(double *minInputs, double *maxInputs, double *minTargets, double *maxTargets)
//{
//	ts->normalize(minInputs, maxInputs, minTargets, maxTargets);
//}

//TrainingSet TrainingSetTable::getNormalized(double *minInputs, double *maxInputs, double *minTargets, double *maxTargets) const
//{
//	return ts->getNormalized(minInputs, maxInputs, minTargets, maxTargets);
//}

//TrainingSet TrainingSetTable::getNormalized(double minInputs, double maxInputs, double minTargets, double maxTargets) const
//{
//	return ts->getNormalized(minInputs, maxInputs, minTargets, maxTargets);
//}

//void TrainingSetTable::setNormalizationType(NormalizationType nt)
//{
//}
