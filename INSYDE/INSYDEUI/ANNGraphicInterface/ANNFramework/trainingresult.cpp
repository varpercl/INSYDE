#include "trainingresult.h"

TrainingResult::TrainingResult() :
	QAbstractTableModel()
{
	clear();
}

TrainingResult::TrainingResult(long long epochs, double mse, double rmse) :
	QAbstractTableModel()
{
	setEpochs(epochs);
	setMeanSquareError(mse);
	setRootMeanSquareError(rmse);
}

TrainingResult::~TrainingResult()
{
	mseHistory.clear();
	rmseHistory.clear();
}

int TrainingResult::rowCount(const QModelIndex &parent) const
{
	(void) parent;
	QMutex mutex;
	QMutexLocker locker(&mutex);
	return nRecords;
}

int TrainingResult::columnCount(const QModelIndex &parent) const
{
	(void)parent;
	return 4;
}

QVariant TrainingResult::data(const QModelIndex &index, int role) const
{
	//Rechaza en caso de que el indice no sea valido o el rol no sea para mostrar o editar
	if(!index.isValid() || !(role == Qt::DisplayRole || role == Qt::EditRole)){
		return QVariant();
	}

	int
			row = index.row(),
			col = index.column();

	if(row < rowCount() && row >= 0 && col >= 0 && col < columnCount()){
		if(col == 0 || col == 2){
			return row;
		}else if(col == 1){
			return mseHistory[row];
		}else if(col == 3){
			return rmseHistory[row];
		}else{
			return QVariant();
		}
	}else{
		return QVariant();
	}
}

QVariant TrainingResult::headerData(int section, Qt::Orientation orientation, int role) const
{
	//Rechaza en caso de que el indice no sea valido o el rol no sea para mostrar o editar
	if(role != Qt::DisplayRole && role != Qt::EditRole){
		return QVariant();
	}

	if(orientation == Qt::Horizontal){
		switch (section) {
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				return QVariant();
				break;
		}
	}
	return QVariant();
}

//bool TrainingResult::setData(const QModelIndex &index, const QVariant &value, int role)
//{
//	//TODO: implementar
//	(void)role;
//	int
//			row = index.row(),
//			col = index.column();

//	if(col > 2 || row > rowCount() - 1 || col == -1 || row == -1){
//		return false;
//	}else{
//		if(col == 0){
//			return false;
//		}else if(col == 1){
//			mseHistory[row] = value.toDouble();
//			emit dataChanged( index, index );
//		}else if(col == 2){
//			rmseHistory[row] = value.toDouble();
//			emit dataChanged( index, index );
//		}else{
//			return false;
//		}
//	}
//	return false;
//}

void TrainingResult::setEpochs(long long epochs)
{
	QMutex mutex;
	QMutexLocker locker(&mutex);
	this->epochs = epochs;
}

void TrainingResult::incEpochs(int inc)
{
	if(inc > 0){
		epochs+=inc;
	}
}

void TrainingResult::decEpochs(int dec)
{
	epochs += dec;
	if (epochs < 0) {
		epochs = 0;
	}
}

void TrainingResult::setRootMeanSquareError(double rmse)
{
	RMSE = rmse;
}

double TrainingResult::getRootMeanSquareError() const
{
	QMutex mutex;
	QMutexLocker locker(&mutex);
	return RMSE;
}

void TrainingResult::setMeanSquareError(double mse)
{
	QMutex mutex;
	QMutexLocker locker(&mutex);
	this->MSE = mse;
}

double TrainingResult::getMeanSquareError() const
{
	QMutex mutex;
	QMutexLocker locker(&mutex);
	return MSE;
}

int TrainingResult::getMSESize() const
{
	QMutex mutex;
	QMutexLocker locker(&mutex);
	return nRecords;
}

int TrainingResult::getRMSESize() const
{
	QMutex mutex;
	QMutexLocker locker(&mutex);
	return nRecords;
}

void TrainingResult::setTime(double time)
{
	QMutex mutex;
	QMutexLocker locker(&mutex);
	this->time = time;
}

double TrainingResult::getTime() const
{
	QMutex mutex;
	QMutexLocker locker(&mutex);
	return time;
}

bool TrainingResult::save(const QString &path)
{
	QFile output(path);

	if(output.open(QIODevice::ReadWrite)){

	}
	return true;
}

void TrainingResult::clear()
{
	beginResetModel();
	setEpochs(0);
	setMeanSquareError(-1);
	setRootMeanSquareError(-1);
	mseHistory.clear();
	rmseHistory.clear();
	nRecords = 0;
	endResetModel();
}

long long TrainingResult::getEpochs() const
{
//	QMutex mutex;
//	QMutexLocker locker(&mutex);
	return epochs;
}

vector<double> TrainingResult::getMSEHistory() const
{
	QMutex mutex;
	QMutexLocker locker(&mutex);
	return mseHistory;
}

vector<double> TrainingResult::getRMSEHistory() const
{
	QMutex mutex;
	QMutexLocker locker(&mutex);
	return rmseHistory;
}

void TrainingResult::appendMSE(double mse)
{

//	if(nRecords > 0)
	beginInsertRows(QModelIndex(), nRecords, nRecords);

	setMeanSquareError(mse);
	mseHistory.push_back(mse);
	rmseHistory.push_back(-1);
	nRecords++;
	epochs++;

//	if(nRecords > 1)
	endInsertRows();
}

void TrainingResult::appendRMSE(double rmse)
{

//	if(nRecords > 0)
	beginInsertRows(QModelIndex(), nRecords, nRecords);

	setRootMeanSquareError(rmse);
	rmseHistory.push_back(rmse);
	mseHistory.push_back(-1);
	nRecords++;
	epochs++;

//	if(nRecords > 1)
	endInsertRows();
}

void TrainingResult::appendRecord(double mse, double rmse)
{
	QMutex mutex;
	QMutexLocker locker(&mutex);

//	if(nRecords > 0)
	beginInsertRows(QModelIndex(), nRecords, nRecords);

	setMeanSquareError(mse);
	mseHistory.push_back(mse);
	setRootMeanSquareError(rmse);
	rmseHistory.push_back(rmse);
	nRecords++;
	epochs++;

//	if(nRecords > 1)
	endInsertRows();
}

void TrainingResult::setDataInterval(long interval)
{
	dataInterval = interval;
}

long TrainingResult::getDataInterval() const
{
	return dataInterval;
}
