#include "trainingset.h"
using namespace ann_base;

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
	init(vector<vector<double> >(1, vector<double>(mlp->getInputsSize(), 0)),
		 mlp->getInputsSize(),
		 vector<vector<double> >(1, vector<double>(mlp->getOutputsSize(), 0)),
		 mlp->getOutputsSize(),
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

		*this = *tsf.ts;
	}
}

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
		resizeVectorSet(normalizedInputs, inputsSize, 0);

		updateNormalizedInputs();

		emit inputsSizeChanged(is);
		emit inputsSizeChanged(ls, is);

		//TODO: se debe probar si es necesario emitir dataChanged
	}
}

int TrainingSet::getInputsSize() const
{
	return inputsSize;
}

void TrainingSet::setTargetsSize(int ts, double fill)
{
	int ls = getTargetsSize();

	//Si realmente cambio el tamaño del patron de salidas
	if(ls != ts){
		targetsSize = ts;
		resizeVectorSet(targets, targetsSize, fill);
		resizeVectorSet(normalizedTargets, targetsSize, fill);

		updateNormalizedTargets();

		emit targetsSizeChanged(ts);
		emit targetsSizeChanged(ls, ts);

		//TODO: se debe probar si es necesario emitir dataChanged
	}
}

int TrainingSet::getTargetsSize() const
{
	return targetsSize;
}

bool TrainingSet::insertPattern(int i)
{
	return insertPattern(vector<double> (getInputsSize(), 0), vector<double>(getTargetsSize(), 0), i);
}

bool TrainingSet::insertPattern(const vector<double> &inputs, const vector<double> &targets, int i)
{
	vector<vector<double> >::iterator it;

	vector<double>
			cinputs = inputs,
			ctargets = targets;

	if(cinputs.size() != (size_t)inputsSize){
		cinputs.resize(inputsSize, 0);
	}
	if(ctargets.size() != (size_t)targetsSize){
		ctargets.resize(targetsSize, 0);
	}

	beginInsertRows(QModelIndex(), i, i + 1);

	it = this->inputs.begin();
	this->inputs.insert(it + i, cinputs);
	normalizedInputs.insert(it + i, normalizedVector(cinputs, getInputsNormalization()));

	it = this->targets.begin();
	this->targets.insert(it + i, ctargets);
	normalizedTargets.insert(it + i, normalizedVector(ctargets, getTargetsNormalization()));

	endInsertRows();

	emit patternInserted(inputs, targets, i);

	emit dataChanged(QModelIndex(), QModelIndex());
	return true;
}

bool TrainingSet::insertPattern(const vector<int> &inputs, const vector<int> &targets, int i)
{
	vector<double>
			newInputs = vector<double>(inputs.begin(), inputs.end()),
			newTargets = vector<double>(targets.begin(), targets.end());
	return insertPattern(newInputs, newTargets, i);
}

bool TrainingSet::removePattern(int i)
{
	if(i >= 0 && i < patternCount){
		vector<vector<double> >::iterator
				inputPattern,
				targetPattern;

		beginRemoveRows(QModelIndex(), i, i);
		inputPattern = inputs.erase(inputs.begin() + i);

		normalizedInputs.erase(normalizedInputs.begin() + i);

		targetPattern = targets.erase(targets.begin() + i);

		normalizedTargets.erase(normalizedTargets.begin() + i);

		patternCount--;

		endRemoveRows();

		emit patternDeleted(*inputPattern, *targetPattern, i);

		emit dataChanged(QModelIndex(), QModelIndex());

		return true;
	}
	return false;
}

void TrainingSet::setInputs(const vector<vector<double> > &inputs, int size)
{

	//TODO: validar el correcto funcionamiento

	if(size <= 0) return;

	vector<vector<double> >
			li = this->inputs;

	this->inputs = inputs;

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
		emit inputsSizeChanged(li.size(), inputsSize);
	}

	updateNormalizedInputs();

	if(li != inputs){
		emit inputsChanged(inputs);
		emit inputsChanged(li, inputs);

		emit dataChanged(QModelIndex(), QModelIndex());
	}
}

void TrainingSet::setInputs(const vector<vector<int> > &inputs, int size)
{
	setInputs(math::toDouble(inputs), size);
}

void TrainingSet::setTargets(const vector<vector<double> > &targets, int size)
{
	//FIXME: validar el correcto funcionamiento

	if(size <= 0) return;

	vector<vector<double> >
			lt = this->targets;

	this->targets = targets;

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
		emit targetsSizeChanged(lt.size(), targetsSize);
	}

	updateNormalizedTargets();

	if(lt != targets){
		emit targetsChanged(targets);
		emit targetsChanged(lt, targets);

		emit dataChanged(QModelIndex(), QModelIndex());
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
	//FIXME: asignar la normalizacion
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

	emit dataChanged(index(patternCount - 1, 0), index(patternCount - 1, inputsSize + targetsSize - 1));
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

	emit dataChanged(QModelIndex(), QModelIndex());
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

	emit dataChanged(QModelIndex(), QModelIndex());
}

Normalization *TrainingSet::getTargetsNormalization() const
{
	return targetsNormalization;
}

ann_base::DataRepresentation *ann_base::TrainingSet::getInputsDataRepresentation() const
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
				setInput(row, col, dblValue);
				return true;
			}
		}else{
			if(targetsNormalization->getType() == Normalization::Nothing){
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
		if(section >= 0 && section < inputsSize + targetsSize){
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
	(void)parent;
	return removePattern(row);
}

bool TrainingSet::insertRow(int row, const QModelIndex &parent)
{
	(void)parent;
	insertPattern(row);
	return true;
}

void TrainingSet::onInputsNormalizationParamChanged(double val)
{
	(void) val;
	updateNormalizedInputs();

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::onInputsNormalizationTypeChanged(int val)
{
	(void) val;
	updateNormalizedInputs();

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::onTargetsNormalizationParamChanged(double val)
{
	(void) val;
	updateNormalizedInputs();

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TrainingSet::onTargetsNormalizationTypeChanged(int val)
{
	(void) val;
	updateNormalizedTargets();

	emit dataChanged(QModelIndex(), QModelIndex());
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
	double prevVal = inputs[pat][index];
	if(prevVal != value){
		inputs[pat][index] = value;

		updateNormalizedInputs();

		emit inputChanged(pat, index, value);
		emit inputChanged(pat, index, prevVal, value);

		emit dataChanged(QModelIndex(), QModelIndex());
	}
}

double TrainingSet::getInput(int pat, int index) const
{
	return inputs[pat][index];
}

void TrainingSet::setTarget(int pattern, int index, double value)
{
	double prevVal = targets[pattern][index];
	if(prevVal != value){
		targets[pattern][index] = value;

		updateNormalizedTargets();

		emit targetChanged(pattern, index, value);
		emit targetChanged(pattern, index, prevVal, value);

		emit dataChanged(QModelIndex(), QModelIndex());
	}
}

double TrainingSet::getTarget(int pat, int index) const
{
	return targets[pat][index];
}

void TrainingSet::setPattern(int index, const vector<double> &inputs, const vector<double> &targets)
{
	vector<double>
			prevInputs = this->inputs[index],
			prevTargets = this->targets[index];
	if(prevInputs != inputs || prevTargets != targets){
		this->inputs[index] = inputs;
		this->targets[index] = targets;

		emit patternChanged(index, inputs, targets);
		emit patternChanged(index, prevInputs, inputs, prevTargets, targets);

		emit dataChanged(QModelIndex(), QModelIndex());
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
	patternCount = cinputs.size();

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
