#include "trainingset.h"

namespace ann_base{

TrainingSet::TrainingSet() :
	QAbstractTableModel()
{
	vector<vector<double> > single_cell = vector<vector<double> >(1, vector<double> (1, 0));

	init(single_cell, 1, single_cell, 1, new DataRepresentation(), new DataRepresentation(), new Normalization(), new Normalization());
}

TrainingSet::TrainingSet(int inputsize, int targetsize, int n) :
	QAbstractTableModel()
{
	vector<vector<double> >
			inputs = vector<vector<double> >(n, vector<double> (inputsize, 0)),
			targets = vector<vector<double> >(n, vector<double> (targetsize, 0));

	init(inputs, inputsize, targets, targetsize, new DataRepresentation(), new DataRepresentation(), new Normalization(), new Normalization());
}

TrainingSet::TrainingSet(const vector<vector<double> > &inputs,
						 int is,
						 const vector<vector<double> > &targets,
						 int ts,
						 DataRepresentation *idr,
						 DataRepresentation *tdr) :
	QAbstractTableModel()
{
	init(inputs, is, targets, ts, idr, tdr, new Normalization(), new Normalization());
}

TrainingSet::TrainingSet(double **inputs,
						 unsigned int sinputs,
						 double **targets,
						 unsigned int stargets,
						 unsigned int spatterns,
						 DataRepresentation *idr,
						 DataRepresentation *tdr) :
	QAbstractTableModel()
{
	vector<vector<double> >
			tinputs(spatterns),
			ttargets(spatterns);

	for(unsigned int i = 0; i < spatterns; i++){
		tinputs[i] = vector<double>(inputs[i], inputs[i] + sinputs);
		ttargets[i] = vector<double>(targets[i], targets[i] + stargets);
	}
	init(tinputs, sinputs, ttargets, stargets, idr, tdr, new Normalization, new Normalization());
}

TrainingSet::TrainingSet(MultilayerPerceptron *mlp, DataRepresentation *idr, DataRepresentation *tdr) :
	QAbstractTableModel()
{
	init(vector<vector<double> >(1, vector<double>(mlp->getInputSize(), 0)),
		 mlp->getInputSize(),
		 vector<vector<double> >(1, vector<double>(mlp->getOutputSize(), 0)),
		 mlp->getOutputSize(),
		 idr,
		 tdr,
		 new Normalization(),
		 new Normalization());
}

TrainingSet::TrainingSet(const QString &path) :
	QAbstractTableModel()
{
	TrainingSetFile::TSFResult tsf = TrainingSetFile::fromFile(path);

	if(tsf.errnum == 0){

		*this = *(tsf.file->getTrainingSet());
	}
}

//TrainingSet::TrainingSet(const QString &table, const QSqlDatabase &database)
//{


//}

TrainingSet::TrainingSet(const TrainingSetFile &file) :
	QAbstractTableModel()
{
	*this = *file.getTrainingSet();
}

TrainingSet::TrainingSet(const TrainingSet &ts) :
	QAbstractTableModel()
{
	*this = ts;
}

TrainingSet::~TrainingSet()
{
}

void TrainingSet::setInputsSize(int is, double fill)
{
	int ls = getInputsSize();

	//Si realmente hubo un cambio en el tamaño de las entradas
	if(is != ls){
		inputsSize = is;
		resizeVectorSet(inputs, inputsSize, fill);

		updateNormalizedInputs();

		if(ls < is){
			beginInsertColumns(QModelIndex(), ls, is - 1);
			endInsertColumns();

		}else{
			beginRemoveColumns(QModelIndex(), is, ls - 1);
			endRemoveColumns();
		}

		emit inputsSizeChanged(is);
		emit inputsSizeChanged(ls, is);
	}
}

int TrainingSet::getInputsSize() const
{
	return inputsSize;
}

void TrainingSet::setTargetsSize(int ts, double fill)
{
	//TODO: 12/4/16 setTargetsSize havent tested yet
	int ls = getTargetsSize();

	//Si realmente cambio el tamaño del patron de salidas
	if(ls != ts){
		targetsSize = ts;
		resizeVectorSet(targets, targetsSize, fill);

		updateNormalizedTargets();

		if(ls < ts){
			beginInsertColumns(QModelIndex(), inputsSize + ls, inputsSize + ts - 1);
			endInsertColumns();

		}else{
			beginRemoveColumns(QModelIndex(), inputsSize + ts, inputsSize + ls - 1);
			endRemoveColumns();
		}

		emit targetsSizeChanged(ts);
		emit targetsSizeChanged(ls, ts);

//		emit headerDataChanged(Qt::Horizontal, inputsSize, inputsSize + targetsSize - 1);
//		emit dataChanged(QModelIndex(), QModelIndex());

//		emit headerDataChanged(Qt::Horizontal, inputsSize, inputsSize + targetsSize - 1);
//		emit dataChanged(createIndex(0, inputsSize), createIndex(patternCount - 1, inputsSize + targetsSize - 1));
	}
}

int TrainingSet::getTargetsSize() const
{
	return targetsSize;
}

bool TrainingSet::insertPattern(int i)
{
	return insertRows(i, 1);
}

bool TrainingSet::insertPattern(const vector<double> &inputs, const vector<double> &targets, int row)
{
	vector<vector<double> >::iterator it;

	vector<double>
			cinputs = inputs,
			ctargets = targets;

	//Resize inputs and targets if their sizes dont match
	if(cinputs.size() != (size_t)inputsSize){
		cinputs.resize(inputsSize, 0);
	}
	if(ctargets.size() != (size_t)targetsSize){
		ctargets.resize(targetsSize, 0);
	}

	beginInsertRows(QModelIndex(), row, row);

	it = this->inputs.begin();
	this->inputs.insert(it + row, cinputs);
	normalizedInputs.insert(it + row, normalizedVector(cinputs, getInputsNormalization()));

	it = this->targets.begin();
	this->targets.insert(it + row, ctargets);
	normalizedTargets.insert(it + row, normalizedVector(ctargets, getTargetsNormalization()));

	endInsertRows();

	emit patternInserted(inputs, targets, row);

	return true;
}

bool TrainingSet::insertPattern(const vector<int> &inputs, const vector<int> &targets, int row)
{
	vector<double>
			newInputs = vector<double>(inputs.begin(), inputs.end()),
			newTargets = vector<double>(targets.begin(), targets.end());
	return insertPattern(newInputs, newTargets, row);
}

bool TrainingSet::removePattern(int i)
{
	return removeRows(i, 1);
}

void TrainingSet::setInputs(const vector<vector<double> > &inputs, int size)
{
	//TODO: 12/4/16 setInputs validar el correcto funcionamiento

	if(size <= 0) return;

	vector<vector<double> >
			li = this->inputs;

	this->inputs = inputs;

	//FIXME: 12/4/16 setInputs havent validated updating targets if sizes are different
	if(this->inputs.size() != (size_t)patternCount){
		this->inputs.resize(patternCount);
		normalizedInputs.resize(patternCount);
	}

	if(inputsSize != size){

		for(size_t i = 0; i < this->inputs.size(); i++){
			this->inputs[i].resize(size);
		}

		inputsSize = size;
		resizeVectorSet(normalizedInputs, inputsSize, 0);

		emit inputsSizeChanged(inputsSize);
		emit inputsSizeChanged((int)li.size(), inputsSize);
	}

	updateNormalizedInputs();

	if(li != inputs){
		emit inputsChanged(inputs);
		emit inputsChanged(li, inputs);

		//NOTE: 12/4/16 setInputs first, test correct function of this method to correct this signal
		emit dataChanged(createIndex(0, 0), createIndex(patternCount - 1, inputsSize - 1));
	}
}

void TrainingSet::setInputs(const vector<vector<int> > &inputs, int size)
{
	setInputs(math::toDouble(inputs), size);
}

void TrainingSet::setTargets(const vector<vector<double> > &targets, int size)
{
	//TODO: 12/4/16 setTargets validar el correcto funcionamiento

	if(size <= 0) return;

	vector<vector<double> >
			lt = this->targets;

	this->targets = targets;

	//FIXME: 12/4/16 setTargets havent validated updating inputs if sizes are different
	if(this->targets.size() != (size_t)patternCount){
		this->targets.resize(patternCount);
		normalizedTargets.resize(patternCount);
	}

	if(targetsSize != size){

		for(size_t i = 0; i < this->targets.size(); i++){
			this->targets[i].resize(size);
		}

		targetsSize = size;
		resizeVectorSet(normalizedTargets, targetsSize, 0);

		emit targetsSizeChanged(targetsSize);
		emit targetsSizeChanged((int)lt.size(), targetsSize);
	}

	updateNormalizedTargets();

	if(lt != targets){
		emit targetsChanged(targets);
		emit targetsChanged(lt, targets);

		//NOTE: 12/4/16 setInputs first, test correct function of this method to correct this signal
		emit dataChanged(createIndex(0, inputsSize), createIndex(patternCount - 1, inputsSize + targetsSize - 1));
	}
}

void TrainingSet::setTargets(const vector<vector<int> > &targets, int size)
{
	setTargets(math::toDouble(targets), size);
}

vector<vector<double> > TrainingSet::getInputs() const
{
	return inputs;
}

vector<vector<double> > TrainingSet::getTargets() const
{
	return targets;
}

TrainingSet *TrainingSet::getNormalized(Normalization *in, Normalization *tn) const
{
	TrainingSet *ts = new TrainingSet(*this);
	ts->setInputsNormalization(in);
	ts->setTargetsNormalization(tn);
	return ts;
}

vector<vector<double> > ann_base::TrainingSet::getNormalizedInputs() const
{
	return normalizedInputs;
}

vector<vector<double> > ann_base::TrainingSet::getNormalizedTargets() const
{
	return normalizedTargets;
}

void ann_base::TrainingSet::addNoiseToInputs(double min, double max)
{
	size_t sPatterns = getPatternCount();
	vector<vector<double> > li = inputs;

	for(size_t i = 0; i < sPatterns; i++){
		inputs[i] = math::addNoise(inputs[i], min, max);
	}

	if(li != inputs){
		emit inputsChanged(inputs);
		emit inputsChanged(li, inputs);
	}
}

void ann_base::TrainingSet::addNoiseToInputs(double a)
{
	vector<vector<double> > li = inputs;
	addNoiseToInputs(-a, a);

	if(li != inputs){
		emit inputsChanged(inputs);
		emit inputsChanged(li, inputs);
	}
}

void ann_base::TrainingSet::addNoiseToTargets(double min, double max)
{
	size_t sPatterns = getPatternCount();
	vector<vector<double> > lt = targets;

	for(size_t i = 0; i < sPatterns; i++){
		targets[i] = math::addNoise(targets[i], min, max);
	}

	if(lt != targets){
		emit targetsChanged(targets);
		emit targetsChanged(lt, targets);
	}
}

void ann_base::TrainingSet::addNoiseToTargets(double a)
{
	vector<vector<double> > lt = targets;

	addNoiseToTargets(-a, a);

	if(lt != targets){
		emit targetsChanged(targets);
		emit targetsChanged(lt, targets);
	}
}

void ann_base::TrainingSet::addNoiseToAll(double min, double max)
{
	size_t sPatterns = getPatternCount();
	vector<vector<double> >
			li = inputs,
			lt = targets;

	for(size_t i = 0; i < sPatterns; i++){
		inputs[i] = math::addNoise(inputs[i], min, max);
		targets[i] = math::addNoise(targets[i], min, max);
	}

	if(li != inputs){
		emit inputsChanged(inputs);
		emit inputsChanged(li, inputs);
	}

	if(lt != targets){
		emit targetsChanged(targets);
		emit targetsChanged(lt, targets);
	}
}

void ann_base::TrainingSet::addNoiseToAll(double a)
{
	vector<vector<double> >
			li = inputs,
			lt = targets;

	addNoiseToAll(-a, a);

	if(li != inputs){
		emit inputsChanged(inputs);
		emit inputsChanged(li, inputs);
	}

	if(lt != targets){
		emit targetsChanged(targets);
		emit targetsChanged(lt, targets);
	}
}

void ann_base::TrainingSet::setPatternCount(int s)
{
	inputs.resize(s);
	normalizedInputs.resize(s);
	targets.resize(s);
	normalizedTargets.resize(s);
	patternCount = s;
}

int ann_base::TrainingSet::getPatternCount() const
{
	return patternCount;
}

TrainingSet &TrainingSet::operator=(const TrainingSet &ts)
{
	//FIXME: 12/4/16 operator= asignar la normalizacion
	setPatternCount(ts.getPatternCount());
	setInputs(ts.getInputs(), ts.getInputsSize());
	setTargets(ts.getTargets(), ts.getTargetsSize());

	setInputsDataRepresentation(ts.getInputsDataRepresentation());
	setTargetsDataRepresentation(ts.getInputsDataRepresentation());

	setInputsSize(ts.getInputsSize());
	setTargetsSize(ts.getTargetsSize());

	setInputsNormalization(ts.getInputsNormalization());
	setTargetsNormalization(ts.getTargetsNormalization());

	return *this;
}

bool ann_base::TrainingSet::operator==(const TrainingSet &ts)
{
	if(getInputs() == ts.getInputs() &&
	   getTargets() == ts.getTargets() &&
	   getInputsDataRepresentation() == ts.getInputsDataRepresentation() &&
	   getTargetsDataRepresentation() == ts.getTargetsDataRepresentation() &&
	   getInputsSize() == ts.getInputsSize() &&
	   getTargetsSize() == ts.getTargetsSize() &&
	   getPatternCount() == ts.getPatternCount() &&
	   getInputsNormalization() == ts.getInputsNormalization() &&
	   getTargetsNormalization() == ts.getTargetsNormalization()){

		return true;
	}
	return false;
}

bool ann_base::TrainingSet::operator!=(const TrainingSet &ts)
{
	if(getInputs() == ts.getInputs() &&
	   getTargets() == ts.getTargets() &&
	   getInputsDataRepresentation() == ts.getInputsDataRepresentation() &&
	   getTargetsDataRepresentation() == ts.getTargetsDataRepresentation() &&
	   getInputsSize() == ts.getInputsSize() &&
	   getTargetsSize() == ts.getTargetsSize() &&
	   getPatternCount() == ts.getPatternCount() &&
	   getInputsNormalization() == ts.getInputsNormalization() &&
	   getTargetsNormalization() == ts.getTargetsNormalization()){
		return false;
	}
	return true;
}

void ann_base::TrainingSet::appendPattern()
{
	appendPattern(vector<double>(getInputsSize(), 0), vector<double>(getTargetsSize(), 0));
}

void ann_base::TrainingSet::appendPattern(const vector<double> &inputs, const vector<double> &targets)
{
	vector<double>
			cinputs = inputs,
			ctargets = targets;

	if((int)cinputs.size() != getInputsSize()){
		cinputs.resize(getInputsSize(), 0);
	}

	if((int)ctargets.size() != getTargetsSize()){
		ctargets.resize(getTargetsSize(), 0);
	}

	beginInsertRows(QModelIndex(), patternCount, patternCount);

	this->inputs.push_back(cinputs);
	normalizedInputs.push_back(normalizedVector(cinputs, getInputsNormalization()));

	this->targets.push_back(ctargets);
	normalizedTargets.push_back(normalizedVector(ctargets, getTargetsNormalization()));
	patternCount++;

	endInsertRows();

	emit patternAppend(cinputs, ctargets);
}

void TrainingSet::appendInputs(double value, int count)
{
	int colIndex = inputsSize;

	beginInsertColumns(QModelIndex(), colIndex, colIndex + count - 1);

	for(int i = 0; i < patternCount; i++){
		for(int j = 0; j < count; j++){
			inputs[i].push_back(value);
		}
	}
	inputsSize+=count;

	updateNormalizedTargets();

	endInsertColumns();

	//FIXME: 12/4/15 insertColumns fix this signal
	emit columnInserted(inputsSize);
}

void TrainingSet::appendTarget(double value, int count)
{
	int colIndex = targetsSize + inputsSize;

	beginInsertColumns(QModelIndex(), colIndex, colIndex + count - 1);

	for(int i = 0; i < patternCount; i++){
		for(int j = 0; j < count; j++){
			targets[i].push_back(value);
		}
	}
	targetsSize+=count;

	updateNormalizedTargets();

	endInsertColumns();

	//FIXME: 12/4/15 insertColumns fix this signal
	emit columnInserted(inputsSize + targetsSize);
}

void TrainingSet::setInputsNormalization(Normalization *in)
{
	Normalization *ln = inputsNormalization;
	inputsNormalization = in;

	updateNormalizedInputs();

	if(ln != in){
		emit inputsNormalizationChanged(in);
		emit inputsNormalizationChanged(ln, in);

		connect(in, SIGNAL(amplitudeChanged(double)), SLOT(onInputsNormalizationParamChanged(double)));
		connect(in, SIGNAL(elongationChanged(double)), SLOT(onInputsNormalizationParamChanged(double)));
		connect(in, SIGNAL(thresholdChanged(double)), SLOT(onInputsNormalizationParamChanged(double)));
		connect(in, SIGNAL(maxValueChanged(double)), SLOT(onInputsNormalizationParamChanged(double)));
		connect(in, SIGNAL(minValueChanged(double)), SLOT(onInputsNormalizationParamChanged(double)));
		connect(in, SIGNAL(typeChanged(int)), SLOT(onInputsNormalizationTypeChanged(int)));
	}

	emit dataChanged(createIndex(0, 0), createIndex(patternCount - 1, inputsSize - 1));
}

Normalization *TrainingSet::getInputsNormalization() const
{
	return inputsNormalization;
}

void TrainingSet::setTargetsNormalization(Normalization *tn)
{
	Normalization *ln = targetsNormalization;
	targetsNormalization = tn;

	updateNormalizedTargets();

	if(ln != tn){
		emit targetsNormalizationChanged(tn);
		emit targetsNormalizationChanged(ln, tn);

		connect(tn, SIGNAL(amplitudeChanged(double)), SLOT(onTargetsNormalizationParamChanged(double)));
		connect(tn, SIGNAL(elongationChanged(double)), SLOT(onTargetsNormalizationParamChanged(double)));
		connect(tn, SIGNAL(thresholdChanged(double)), SLOT(onTargetsNormalizationParamChanged(double)));
		connect(tn, SIGNAL(maxValueChanged(double)), SLOT(onTargetsNormalizationParamChanged(double)));
		connect(tn, SIGNAL(minValueChanged(double)), SLOT(onTargetsNormalizationParamChanged(double)));
		connect(tn, SIGNAL(typeChanged(int)), SLOT(onTargetsNormalizationTypeChanged(int)));
	}

	emit dataChanged(createIndex(0, inputsSize), createIndex(patternCount - 1, inputsSize + targetsSize - 1));
}

Normalization *TrainingSet::getTargetsNormalization() const
{
	return targetsNormalization;
}

DataRepresentation *ann_base::TrainingSet::getInputsDataRepresentation() const
{
	return inputsDataRepresentation;
}

void TrainingSet::setInputsDataRepresentation(DataRepresentation *value)
{
	inputsDataRepresentation = value;
}

DataRepresentation *TrainingSet::getTargetsDataRepresentation() const
{
	return targetsDataRepresentation;
}

void TrainingSet::setTargetsDataRepresentation(DataRepresentation *value)
{
	targetsDataRepresentation = value;
}

bool TrainingSet::removeInput(int index)
{
	if(index < inputsSize && index >= 0){
		return removeColumns(index, 1);
	}

	return false;
}

bool TrainingSet::removeTarget(int index)
{
	if(index < targetsSize && index >= 0){
		return removeColumns(inputsSize + index, 1);
	}

	return false;
}

bool TrainingSet::removeColumn(int column, const QModelIndex &parent)
{
	return removeColumns(column, 1, parent);
}

bool TrainingSet::removeColumns(int column, int count, const QModelIndex &parent)
{
	(void) parent;

	//FIXME: 12/4/16 removeColumns should be validated count being in a correct range. An incorrect range could result unknow behavior

	vector<double>::iterator beginPointer;

	if(column >= 0 && column < (int)inputsSize){

		beginRemoveColumns(QModelIndex(), column, column + count - 1);

		for(int i = 0; i < patternCount; i++){
			beginPointer = inputs[i].begin();
			inputs[i].erase(beginPointer + column, beginPointer + column + count);
		}
		inputsSize -= count;

		updateNormalizedInputs();

		endRemoveColumns();

		return true;
	}else if(column < inputsSize + targetsSize){
		int index = column - inputsSize;

		beginRemoveColumns(QModelIndex(), column, column + count - 1);

		for(int i = 0; i < patternCount; i++){
			beginPointer = targets[i].begin();
			targets[i].erase(beginPointer + index, beginPointer + index + count);
		}
		targetsSize -= count;

		updateNormalizedTargets();

		endRemoveColumns();

		return true;
	}else{
		return false;
	}
	return false;
}

int TrainingSet::rowCount(const QModelIndex &parent) const
{
	(void)parent;
	return patternCount;
}

int TrainingSet::columnCount(const QModelIndex &parent) const
{
	(void)parent;
	return inputsSize + targetsSize;
}

bool TrainingSet::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if(!index.isValid() || !(role == Qt::DisplayRole || role == Qt::EditRole)){
		return false;
	}

	int
			row = index.row(),
			col = index.column();

	double dblValue = value.toDouble();

	if(row < rowCount() && row >= 0 && col >= 0 && col < columnCount()){
		if(col < inputsSize){
			if(inputsNormalization->getType() == Normalization::Nothing){
				//dataChanged is emited inside setInput
				setInput(row, col, dblValue);

				return true;
			}
		}else{
			if(targetsNormalization->getType() == Normalization::Nothing){
				//dataChanged is emited inside setTarget
				setTarget(row, col - inputsSize, dblValue);

				return true;
			}
		}
	}
	return false;
}

QVariant TrainingSet::data(const QModelIndex &index, int role) const
{
	//Rechaza en caso de que el indice no sea valido o el rol no sea para mostrar o editar
	if(!index.isValid() || !(role == Qt::DisplayRole || role == Qt::EditRole)){
		return QVariant();
	}

	int
			row = index.row(),
			col = index.column();

	if(row < rowCount() && row >= 0 && col >= 0 && col < columnCount()){
		if(col < inputsSize){
			if(inputsNormalization->getType() != Normalization::Nothing){
				return normalizedInputs[row][col];
			}else{
				return inputs[row][col];
			}
		}else{
			if(targetsNormalization->getType() != Normalization::Nothing){
				return normalizedTargets[row][col - inputsSize];
			}else{
				return targets[row][col - inputsSize];
			}
		}
	}
	return QVariant();
}

QVariant TrainingSet::headerData(int section, Qt::Orientation orientation, int role) const
{
	if(role != Qt::DisplayRole){
		return QVariant();
	}

	if(orientation == Qt::Horizontal){
		if(/*section >= 0 &&*/ section < inputsSize + targetsSize){
			if(section < inputsSize){
				return "in[" + QString::number(section) + "]";
			}else{
				return "out[" + QString::number(section - inputsSize) + "]";
			}
		}
	}else{
		if(section >= 0 && section < patternCount){
			return "p[" + QString::number(section) + "]";
		}
	}
	return QVariant();
}

Qt::ItemFlags TrainingSet::flags(const QModelIndex &index) const
{
	//Rechaza en caso de que el indice no sea valido o el rol no sea para mostrar o editar
	if(!index.isValid()){
		return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
	}

	int
			row = index.row(),
			col = index.column();

	if(row < rowCount() && row >= 0 && col >= 0 && col < columnCount()){
		if(col < inputsSize){
			if(inputsNormalization->getType() == Normalization::Nothing){
				return Qt::ItemIsEnabled |Qt::ItemIsSelectable | Qt::ItemIsEditable;
			}
		}else{
			if(targetsNormalization->getType() == Normalization::Nothing){
				return Qt::ItemIsEnabled |Qt::ItemIsSelectable | Qt::ItemIsEditable;
			}
		}
	}
	return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

bool TrainingSet::removeRow(int row, const QModelIndex &parent)
{
	return removeRows(row, 1, parent);
}

bool TrainingSet::removeRows(int row, int count, const QModelIndex &parent)
{
	(void) parent;

	//FIXME: 12/4/16 removeRows validate if count is between a correct range
	if(row >= 0 && row < patternCount){
		vector<vector<double> >::iterator
				inputPattern,
				targetPattern;

		beginRemoveRows(QModelIndex(), row, row + count - 1);

		inputPattern = inputs.erase(inputs.begin() + row, inputs.begin() + row + count);
		normalizedInputs.erase(normalizedInputs.begin() + row, normalizedInputs.begin() + row + count);

		targetPattern = targets.erase(targets.begin() + row, targets.begin() + row + count);
		normalizedTargets.erase(normalizedTargets.begin() + row, normalizedTargets.begin() + row + count);

		patternCount-= count;

		endRemoveRows();

		//FIXME: 12/4/16 removeRows this signal should be fixed
		emit patternDeleted(*inputPattern, *targetPattern, row);

		return true;
	}
	return false;
}

bool TrainingSet::insertRow(int row, const QModelIndex &parent)
{
	return insertRows(row, 1, parent);
}

bool TrainingSet::insertRows(int row, int count, const QModelIndex &parent)
{
	(void)parent;

	beginInsertRows(QModelIndex(), row, row + count - 1);

	if(row < patternCount){
		inputs.insert(inputs.begin() + row, count, vector<double>(inputsSize, 0));
		targets.insert(targets.begin() + row, count, vector<double>(targetsSize, 0));
	}else{
		for(int i = 0; i < count; i++){
			inputs.push_back(vector<double>(inputsSize, 0));
			targets.push_back(vector<double>(targetsSize, 0));
		}
	}

	patternCount += count;

	updateNormalizedInputs();
	updateNormalizedTargets();

	endInsertRows();

	return true;
}

bool TrainingSet::insertColumn(int column, const QModelIndex &parent)
{
	return insertColumns(column, 1, parent);
}

bool TrainingSet::insertColumns(int column, int count, const QModelIndex &parent)
{
	(void) parent;

	if(column >= 0 && column < inputsSize){

		beginInsertColumns(QModelIndex(), column, column + count - 1);

		for(int i = 0; i < patternCount; i++){
			inputs[i].insert(inputs[i].begin() + column, count, 0);
		}
		inputsSize+=count;

		updateNormalizedInputs();

		endInsertColumns();

		//FIXME: 12/4/15 insertColumns fix this signal
		emit columnInserted(column);

		return true;
	}else if(column < inputsSize + targetsSize){
		int index = column - inputsSize;

		beginInsertColumns(QModelIndex(), column, column + count - 1);

		for(int i = 0; i < patternCount; i++){
			targets[i].insert(targets[i].begin() + index, count, 0);
		}
		targetsSize+=count;

		updateNormalizedTargets();

		endInsertColumns();

		//FIXME: 12/4/15 insertColumns fix this signal
		emit columnInserted(column);

		return true;
	}else{
		int colIndex = targetsSize + inputsSize;

		beginInsertColumns(QModelIndex(), colIndex, colIndex + count - 1);

		for(int i = 0; i < patternCount; i++){
			for(int j = 0; j < count; j++){
				targets[i].push_back(0);
			}
		}
		targetsSize+=count;

		updateNormalizedTargets();

		endInsertColumns();

		//FIXME: 12/4/15 insertColumns fix this signal
		emit columnInserted(column);

		return true;
	}
	return false;
}

void TrainingSet::onInputsNormalizationParamChanged(double val)
{
	(void) val;
	updateNormalizedInputs();

	emit dataChanged(createIndex(0, 0), createIndex(patternCount - 1, inputsSize - 1));
}

void TrainingSet::onInputsNormalizationTypeChanged(int val)
{
	(void) val;
	updateNormalizedInputs();

	emit dataChanged(createIndex(0, 0), createIndex(patternCount - 1, inputsSize - 1));
}

void TrainingSet::onTargetsNormalizationParamChanged(double val)
{
	(void) val;
	updateNormalizedTargets();

	emit dataChanged(createIndex(0, inputsSize), createIndex(patternCount - 1, inputsSize + targetsSize - 1));
}

void TrainingSet::onTargetsNormalizationTypeChanged(int val)
{
	(void) val;
	updateNormalizedTargets();

	emit dataChanged(createIndex(0, inputsSize), createIndex(patternCount - 1, inputsSize + targetsSize - 1));
}

void TrainingSet::updateNormalizedTargets()
{
	if(!targetsNormalization) return;

	switch (targetsNormalization->getType()) {
		case Normalization::Tanh:
			normalizedTargets = math::normalizeTanh(targets, targetsNormalization->getAmplitude(), targetsNormalization->getElongation());
			break;
		case Normalization::Sigmoid:
			normalizedTargets = math::normalizeSigmoid(targets, targetsNormalization->getAmplitude(), targetsNormalization->getElongation());
			break;
		case Normalization::Nothing:
		case Normalization::BipolarFixedThreshold:
		case Normalization::BipolarAutoThreshold:
		case Normalization::UnipolarFixedThreshold:
		case Normalization::UnipolarAutoThreshold:
		case Normalization::LinearFixedRange:
		case Normalization::LinearAutoRange:
		case Normalization::MeanDistance:
		default:
			normalizedTargets = targets;
			break;
	}
}

void TrainingSet::updateNormalizedInputs()
{
	if(!inputsNormalization) return;

	switch(inputsNormalization->getType()){
		case Normalization::Nothing:
			normalizedInputs = inputs;
			break;
		case Normalization::BipolarFixedThreshold:
			normalizedInputs = math::normalizeBipolarFixedThreshold(inputs, inputsNormalization->getThreshold());
			break;
		case Normalization::BipolarAutoThreshold:{
			double
					thre = inputsNormalization->getThreshold();
			normalizedInputs = math::normalizeBipolarAutoThreshold(inputs, &thre);

			inputsNormalization->setThreshold(thre);
			break;
		}
		case Normalization::UnipolarFixedThreshold:
			normalizedInputs = math::normalizeUnipolarFixedThreshold(inputs, inputsNormalization->getThreshold());
			break;
		case Normalization::UnipolarAutoThreshold:{
			double
					thre = inputsNormalization->getThreshold();
			normalizedInputs = math::normalizeUnipolarAutoThreshold(inputs, &thre);

			inputsNormalization->setThreshold(thre);
			break;
		}
		case Normalization::LinearFixedRange:
			normalizedInputs = math::normalizeLinearFixedRange(inputs, inputsNormalization->getMinValue(), inputsNormalization->getMaxValue());
			break;
		case Normalization::LinearAutoRange:{
			double
					min = inputsNormalization->getMinValue(),
					max = inputsNormalization->getMaxValue();
			normalizedInputs = math::normalizeLinearAutoRange(inputs, &min, &max);

			inputsNormalization->setMinValue(min);
			inputsNormalization->setMaxValue(max);

			break;
		}
		case Normalization::Tanh:
			normalizedInputs = math::normalizeTanh(inputs, inputsNormalization->getAmplitude(), inputsNormalization->getElongation());
			break;
		case Normalization::Sigmoid:
			normalizedInputs = math::normalizeSigmoid(inputs, inputsNormalization->getAmplitude(), inputsNormalization->getElongation());
			break;
		case Normalization::MeanDistance:
			normalizedInputs = math::normalizeMeanDistance(inputs);
			break;
	}
}

void TrainingSet::setInput(int pat, int index, double value)
{
	//NOTE: 12/4/16 setInput havent tested yet
	double prevVal = inputs[pat][index];
	if(prevVal != value){
		inputs[pat][index] = value;

		updateNormalizedInputs();

		emit inputChanged(pat, index, value);
		emit inputChanged(pat, index, prevVal, value);

		emit dataChanged(createIndex(pat, index), createIndex(pat, index));
	}
}

double TrainingSet::getInput(int pat, int index) const
{
	return inputs[pat][index];
}

void TrainingSet::setTarget(int pattern, int index, double value)
{
	//TODO: 12/4/16 setTarget havent tested yet
	double prevVal = targets[pattern][index];
	if(prevVal != value){
		targets[pattern][index] = value;

		updateNormalizedTargets();

		emit targetChanged(pattern, index, value);
		emit targetChanged(pattern, index, prevVal, value);

		emit dataChanged(createIndex(pattern, inputsSize + index), createIndex(pattern, inputsSize + index));
	}
}

double TrainingSet::getTarget(int pat, int index) const
{
	return targets[pat][index];
}

void TrainingSet::setPattern(int index, const vector<double> &inputs, const vector<double> &targets)
{
	//TODO: 12/4/16 setPattern havent tested yet
	vector<double>
			prevInputs = this->inputs[index],
			prevTargets = this->targets[index];
	if(prevInputs != inputs || prevTargets != targets){
		this->inputs[index] = inputs;
		this->targets[index] = targets;

		emit patternChanged(index, inputs, targets);
		emit patternChanged(index, prevInputs, inputs, prevTargets, targets);

		emit dataChanged(createIndex(index, 0), createIndex(index, inputsSize + targetsSize - 1));
	}
}

pair<vector<double>, vector<double> > TrainingSet::getPattern(int index) const
{
	return pair<vector<double>, vector<double> >(inputs[index], targets[index]);
}

void TrainingSet::init(const vector<vector<double> > &inputs,
					   int is,
					   const vector<vector<double> > &targets,
					   int ts,
					   DataRepresentation *idr,
					   DataRepresentation *tdr,
					   Normalization *in,
					   Normalization *tn)
{
	inputsNormalization = targetsNormalization = 0;

	vector<vector<double> >
			cinputs = inputs,
			ctargets = targets;
	if(cinputs.size() >= ctargets.size()){
		ctargets.resize(cinputs.size());
	}else{
		cinputs.resize(ctargets.size());
	}

	inputsSize = is;
	targetsSize = ts;
	patternCount = (int)cinputs.size();

	setInputsDataRepresentation(idr);
	setTargetsDataRepresentation(tdr);

	setInputs(cinputs, is);
	setTargets(ctargets, ts);

	setInputsNormalization(in);
	setTargetsNormalization(tn);

}

void TrainingSet::resizeVectorSet(vector<vector<double> > &vec, int s, double fill)
{
	size_t sInputs = vec.size();

	for(size_t i = 0; i < sInputs; i++){
		vec[i].resize(s, fill);
	}
}

vector<double> TrainingSet::normalizedVector(const vector<double> &vec, Normalization *nor)
{
	double tmp1, tmp2;
	switch(nor->getType()){
		case Normalization::BipolarFixedThreshold:
			return math::normalizeBipolarFixedThreshold(vec, nor->getThreshold());
		case Normalization::BipolarAutoThreshold:
			return math::normalizeBipolarAutoThreshold(vec, &tmp1);
		case Normalization::UnipolarFixedThreshold:
			return math::normalizeUnipolarFixedThreshold(vec, nor->getThreshold());
		case Normalization::UnipolarAutoThreshold:
			return math::normalizeUnipolarAutoThreshold(vec, &tmp1);
		case Normalization::LinearFixedRange:
			return math::normalizeLinearFixedRange(vec, nor->getMinValue(), nor->getMaxValue());
		case Normalization::LinearAutoRange:
			return math::normalizeLinearAutoRange(vec, &tmp1, &tmp2);
		case Normalization::Tanh:
			return math::normalizeTanh(vec);
		case Normalization::Sigmoid:
			return math::normalizeSigmoid(vec);
		case Normalization::MeanDistance:
			return math::normalizeMeanDistance(vec);
		case Normalization::Nothing:
		default:
			return vec;
	}
}


}


