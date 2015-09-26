#include "mlptrainingresultconcurrentvector.h"

MLPTrainingResult::MLPTrainingResult() :
	QAbstractTableModel()
{
	clear();
	setDataInterval(1);
}

MLPTrainingResult::MLPTrainingResult(long long epochs, double mse, double rmse, double ce, double time):
	QAbstractTableModel()
{
	setDataInterval(1);
	setEpochs(epochs);
	setMeanSquareError(mse);
	setRootMeanSquareError(rmse);
	setClasificationError(ce);
	setTime(time);
}

MLPTrainingResult::MLPTrainingResult(const MLPTrainingResult &mlptr) :
	QAbstractTableModel()
{
	setDataInterval(1);
	epochs = mlptr.epochs;
	time = mlptr.time;
	nRecords = mlptr.nRecords;
	MSE = mlptr.MSE;
	RMSE = mlptr.RMSE;
	CE = mlptr.CE;

	mseHistory = mlptr.mseHistory;
	rmseHistory = mlptr.rmseHistory;
	ceHistory = mlptr.ceHistory;
}

MLPTrainingResult::~MLPTrainingResult()
{
//	QMutex mutex;
//	QMutexLocker locker(&mutex);
	epochsHistory.clear();
	mseHistory.clear();
	rmseHistory.clear();
	ceHistory.clear();
}

int MLPTrainingResult::columnCount(const QModelIndex &parent) const
{
	(void) parent;
	return 6;
}

int MLPTrainingResult::rowCount(const QModelIndex &parent) const
{
	(void) parent;
//	QMutex mutex;
//	QMutexLocker locker(&mutex);
	return nRecords;
}

QVariant MLPTrainingResult::data(const QModelIndex &index, int role) const
{
//	QMutex mutex;
//	QMutexLocker locker(&mutex);

//	locker.lock();
	//Rechaza en caso de que el indice no sea valido o el rol no sea para mostrar o editar
	if(!index.isValid() || !(role == Qt::DisplayRole || role == Qt::EditRole)){
		return QVariant();
	}

	int
			row = index.row(),
			col = index.column();
	if(row < rowCount() && row >= 0 && col >= 0 && col < columnCount()){
		if(col == 0 || col == 2 || col == 4){
			return row;
		}else if(col == 1){
			return mseHistory[row];
		}else if(col == 3){
			return rmseHistory[row];
		}else if(col == 5){
			return ceHistory[row];
		}else{
			return QVariant();
		}
	}else{
		return QVariant();
	}
}

QVariant MLPTrainingResult::headerData(int section, Qt::Orientation orientation, int role) const
{
//	QMutex mutex;
//	QMutexLocker locker(&mutex);
	//Rechaza en caso de que el indice no sea valido o el rol no sea para mostrar o editar
	if(role != Qt::DisplayRole && role != Qt::EditRole){
		return QVariant();
	}

	if(orientation == Qt::Horizontal){
		switch (section) {
			case 0:
				return (MSE < 0 ? "MSE": "MSE: " + QString::number(MSE, 'g', 3));
				break;
			case 2:
				return (RMSE < 0 ? "RMSE": "RMSE: " + QString::number(RMSE, 'g', 3));
				break;
			case 4:
				return (CE < 0 ? "CE" : "CE: " + QString::number(CE, 'g', 3));
				break;
			default:
				return QVariant();
				break;
		}
	}else{
		return QVariant();
	}
}

//bool MLPTrainingResult::setData(const QModelIndex &index, const QVariant &value, int role)
//{
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
//		}else if(col == 3){
//			ceHistory[row] = value.toDouble();
//			emit dataChanged( index, index );
//		}else{
//			return false;
//		}
//	}
//}

void MLPTrainingResult::setClasificationError(double ce)
{

//	QMutex mutex;
//	QMutexLocker locker(&mutex);

	CE = ce;
//	mutex.unlock();
}

double MLPTrainingResult::getClasificationError() const
{
//	QMutex mutex;
//	QMutexLocker locker(&mutex);
	return CE;
}

concurrent_vector<double> MLPTrainingResult::getCEHistory() const
{
//	QMutex mutex;
//	QMutexLocker locker(&mutex);
	return ceHistory;
}

int MLPTrainingResult::getCESize() const
{
//	QMutex mutex;
//	QMutexLocker locker(&mutex);
	return nRecords;
}

bool MLPTrainingResult::save(const QString &path)
{
	//TODO: implementar
	(void)path;

	return true;
}

void MLPTrainingResult::clear()
{
//	QMutex mutex;
//	QMutexLocker locker(&mutex);

	beginResetModel();

	epochs = 0;
	nRecords = 0;
	MSE = -1;
	RMSE = -1;
	CE = -1;
	epochsHistory.clear();
	mseHistory.clear();
	rmseHistory.clear();
	ceHistory.clear();

	endResetModel();
}

MLPTrainingResult &MLPTrainingResult::operator =(const MLPTrainingResult &mlptr)
{
//	QMutex mutex;
//	QMutexLocker locker(&mutex);

	epochs = mlptr.epochs;
	time = mlptr.time;
	nRecords = mlptr.nRecords;
	MSE = mlptr.MSE;
	RMSE = mlptr.RMSE;
	CE = mlptr.CE;

	mseHistory = mlptr.mseHistory;
	rmseHistory = mlptr.rmseHistory;
	ceHistory = mlptr.ceHistory;

	beginResetModel();
	endResetModel();
//	emit dataChanged(index(0, 0), index(nRecords-1, 5));

	return *this;
}


void MLPTrainingResult::appendCE(double ce)
{
//	QMutex mutex;
//	QMutexLocker locker(&mutex);

	if(nRecords > 0)
	beginInsertRows(QModelIndex(), nRecords, nRecords);

	setClasificationError(ce);
	ceHistory.push_back(ce);
	mseHistory.push_back(-1);
	rmseHistory.push_back(-1);
	nRecords++;
	epochs++;

	if(nRecords > 1)
	endInsertRows();
}


void MLPTrainingResult::appendRecord(double mse, double rmse, double ce)
{
//	QMutex mutex;
//	QMutexLocker locker(&mutex);

//	if(tries >= dataInterval/* || epochs == 0*/){

	if(nRecords > 0){
		beginInsertRows(QModelIndex(), nRecords, nRecords);
	}

	setRootMeanSquareError(rmse);
	//		rmseHistory.reserve(rmseHistory.capacity() + sizeof(double));
	rmseHistory.push_back(rmse);

	setMeanSquareError(mse);
	//		mseHistory.reserve(mseHistory.capacity() + sizeof(double));
	mseHistory.push_back(mse);

	setClasificationError(ce);
	//		ceHistory.reserve(ceHistory.capacity() + sizeof(double));
	ceHistory.push_back(ce);

	//		epochsHistory.reserve(epochsHistory.capacity() + sizeof(long long));
	epochsHistory.push_back(epochs);

	nRecords++;
	epochs++;

	if(nRecords > 1){
		endInsertRows();
	}

//		tries = 0;
//	}else{
//		tries++;
//	}
	//	beginResetModel();
	//	endResetModel();

	//	beginInsertRows(QModelIndex(), nRecords, nRecords);

}

void MLPTrainingResult::setRootMeanSquareError(double rmse)
{
	RMSE = rmse;
}

double MLPTrainingResult::getRootMeanSquareError() const
{
//	QMutex mutex;
//	QMutexLocker locker(&mutex);
	return RMSE;
}

void MLPTrainingResult::setMeanSquareError(double mse)
{
//	QMutex mutex;
//	QMutexLocker locker(&mutex);
	this->MSE = mse;
}

double MLPTrainingResult::getMeanSquareError() const
{
//	QMutex mutex;
//	QMutexLocker locker(&mutex);
	return MSE;
}

void MLPTrainingResult::setTime(double time)
{
//	QMutex mutex;
//	QMutexLocker locker(&mutex);
	this->time = time;
}

void MLPTrainingResult::setEpochs(long long epochs)
{
//	QMutex mutex;
//	QMutexLocker locker(&mutex);
	this->epochs = epochs;
}

void MLPTrainingResult::setDataInterval(long interval)
{
	dataInterval = interval;
}

int MLPTrainingResult::getMSESize() const
{
//	QMutex mutex;
//	QMutexLocker locker(&mutex);
	return nRecords;
}

concurrent_vector<double> MLPTrainingResult::getMSEHistory() const
{
//	QMutex mutex;
//	QMutexLocker locker(&mutex);
	return mseHistory;
}

long long MLPTrainingResult::getEpochs() const
{
//	QMutex mutex;
//	QMutexLocker locker(&mutex);
	return epochs;
}
