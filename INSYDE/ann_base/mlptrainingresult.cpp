#include "mlptrainingresult.h"
using namespace ann_base;

MLPTrainingResult::MLPTrainingResult() :
	TrainingResult()
{
	init();
}

MLPTrainingResult::MLPTrainingResult(long long epochs, double mse, double rmse, double ce, double time):
	TrainingResult(epochs, mse, rmse)
{
	visibleCE = true;
	setDataInterval(1);
	setClasificationError(ce);
	setTime(time);
}

MLPTrainingResult::MLPTrainingResult(const MLPTrainingResult &mlptr) :
	TrainingResult(mlptr.getEpochs(), mlptr.getMeanSquareError(), mlptr.getRootMeanSquareError())
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
	QMutex mutex;
	QMutexLocker locker(&mutex);
	mseHistory.clear();
	rmseHistory.clear();
	ceHistory.clear();
}

int MLPTrainingResult::columnCount(const QModelIndex &parent) const
{
	(void) parent;
	int
			mseFactor = visibleMSE ? 1 : 0,
			rmseFactor = visibleRMSE ? 1 : 0,
			ceFactor = visibleCE ? 1 : 0;
	return 2*(mseFactor + rmseFactor + ceFactor);
}

QVariant MLPTrainingResult::data(const QModelIndex &index, int role) const
{
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
		}else if(col == mseIndex+1 && visibleMSE){
			return mseHistory[row];
		}else if(col == (rmseIndex*2) + 1 && visibleRMSE){
			return rmseHistory[row];
		}else if(col == (ceIndex*2) + 1 && visibleCE){
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
	//Rechaza en caso de que el indice no sea valido o el rol no sea para mostrar o editar
	if(role != Qt::DisplayRole && role != Qt::EditRole){
		return QVariant();
	}

	if(orientation == Qt::Horizontal){
		if(section == mseIndex && visibleMSE){
			return (MSE < 0 ? "MSE": "MSE: " + QString::number(MSE, 'G', 3));
		}else if(section == rmseIndex*2 && visibleRMSE){
			return (RMSE < 0 ? "RMSE": "RMSE: " + QString::number(RMSE, 'G', 3));
		}else if(section == ceIndex*2 && visibleCE){
			return (CE < 0 ? "CE" : "CE: " + QString::number(CE, 'G', 3));
		}
	}

	return QVariant();
}

void MLPTrainingResult::init()
{
	clear();
	setDataInterval(1);
}

void MLPTrainingResult::updateColIndexes()
{
	int tempIndex = 0;
	if(visibleMSE){
		mseIndex = tempIndex++;
	}else{
		mseIndex = -1;
	}

	if(visibleRMSE){
		rmseIndex = tempIndex++;
	}else{
		rmseIndex = -1;
	}

	if(visibleCE){
		ceIndex = tempIndex;
	}else{
		ceIndex = -1;
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
	CE = ce;
}

double MLPTrainingResult::getClasificationError() const
{
	return CE;
}

vector<double> MLPTrainingResult::getCEHistory() const
{
	return ceHistory;
}

int MLPTrainingResult::getCESize() const
{
	return nRecords;
}

bool MLPTrainingResult::save(const QString &path)
{
	//TODO: 23/08/15 save must be implement
	(void)path;

	return true;
}

void MLPTrainingResult::clear()
{
	QMutex mutex;
	QMutexLocker locker(&mutex);

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
	QMutex mutex;
	QMutexLocker locker(&mutex);

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

	return *this;
}

void MLPTrainingResult::setMSEVisible(bool hi)
{
	visibleMSE = hi;
	updateColIndexes();
}

void MLPTrainingResult::setRMSEVisible(bool hi)
{
	visibleRMSE = hi;
	updateColIndexes();
}

void MLPTrainingResult::setCEVisible(bool hi)
{
	visibleCE = hi;
	updateColIndexes();
}


void MLPTrainingResult::appendCE(double ce)
{
	QMutex mutex;
	QMutexLocker locker(&mutex);

	beginInsertRows(QModelIndex(), nRecords, nRecords);

	setClasificationError(ce);
	ceHistory.push_back(ce);
	mseHistory.push_back(-1);
	rmseHistory.push_back(-1);
	nRecords++;
	epochs++;

	endInsertRows();
}


void MLPTrainingResult::appendRecord(double mse, double rmse, double ce)
{
	QMutex mutex;
	QMutexLocker locker(&mutex);

	beginInsertRows(QModelIndex(), nRecords, nRecords);

	setRootMeanSquareError(rmse);
	rmseHistory.push_back(rmse);

	setMeanSquareError(mse);
	mseHistory.push_back(mse);

	setClasificationError(ce);
	ceHistory.push_back(ce);

	epochs++;
	epochsHistory.push_back(epochs);

	nRecords++;

	endInsertRows();
}
