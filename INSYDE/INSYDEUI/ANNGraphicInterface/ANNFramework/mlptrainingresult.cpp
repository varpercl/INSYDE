#include "mlptrainingresult.h"

MLPTrainingResult::MLPTrainingResult() :
	TrainingResult()
{
	clear();
	setDataInterval(1);
}

MLPTrainingResult::MLPTrainingResult(long long epochs, double mse, double rmse, double ce, double time):
	TrainingResult(epochs, mse, rmse)
{
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
	return 6;
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
	//TODO: implementar
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
//	emit dataChanged(index(0, 0), index(nRecords-1, 5));

	return *this;
}


void MLPTrainingResult::appendCE(double ce)
{
	QMutex mutex;
	QMutexLocker locker(&mutex);

	//TODO: chequear el correcto funcionamiento de beginInserRows sobretodo cuando se esta graficando
	//segun documentacion deberia ser 	beginInsertRows(QModelIndex(), nRecords, nRecords + 1);
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

	//TODO: chequear el correcto funcionamiento de beginInserRows sobretodo cuando se esta graficando
	//NOTE: segun documentacion deberia ser 	beginInsertRows(QModelIndex(), nRecords, nRecords + 1);
	//NOTE: segun documentacion beginInserRows deberia usarse solo cuando se reimplementa insertRows
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
