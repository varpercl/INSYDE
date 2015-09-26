#ifndef MLPTRAININGRESULTCONCURRENTVECTOR_H
#define MLPTRAININGRESULTCONCURRENTVECTOR_H

#include <vector>
#include <QtCore>

#include "ANNFramework_global.h"

#include <tbb/concurrent_vector.h>

using namespace tbb;

class ANNFRAMEWORK_EXPORT MLPTrainingResult : public QAbstractTableModel
{
	public:

		explicit MLPTrainingResult();

		explicit MLPTrainingResult(long long epochs, double mse, double rmse, double ce, double time);

		MLPTrainingResult(const MLPTrainingResult &mlptr);

		~MLPTrainingResult();

		int rowCount(const QModelIndex &parent = QModelIndex()) const;
		int columnCount(const QModelIndex &parent = QModelIndex()) const;

		/*!
		 * \brief data Devuelve el valor del historial de cada parametro almacenado en esta clase
		 *
		 * Esta funcion es thread-safe. Esto es asi porque por lo general no se tiene un acceso transparente
		 * desde el hilo en el que se esta haciendo la llamada como para colocar alguna exclusion mutua
		 * fuera del metodo. La funcion lee los valores almacenados, los cuales pueden ser modificados
		 * simultaneamente por el hilo que esta llevando a cabo el entrenamiento de la red neuronal al cual pertenece este objeto.
		 *
		 * \param index El indice del objeto de datos que se quiere leer
		 * \param role El rol que tendra el elemento
		 * \return Devuelve el valor correspondiente al indice \code{index}, en caso de ser un indice invalido
		 * devolvera un valor invalido.
		 */
		QVariant data(const QModelIndex &index, int role) const;

//		bool insertRow(int row, const QModelIndex &parent);
//		bool setData(const QModelIndex &index, const QVariant &value, int role);

		/*!
		 * \brief headerData
		 * \param section
		 * \param orientation
		 * \param role
		 * \return
		 */
		QVariant headerData(int section, Qt::Orientation orientation, int role) const;

		void setClasificationError(double ce);
		double getClasificationError() const;

		concurrent_vector<double> getCEHistory() const;

		int getCESize() const;

		bool save(const QString &path);

		void clear();

		void appendCE(double ce);

		void appendRecord(double mse, double rmse, double ce);

		MLPTrainingResult &operator =(const MLPTrainingResult &mlptr);

		void setDataInterval(long interval);
		long getDataInterval() const;

		/*!
		 * \brief appendMSE Agrega el ultimo valor MSE a la historia.
		 *
		 * Hay que tener especial cuidado con esta funcion ya que solo agrega el valor al registro
		 * de MSEs, sin embargo, para mantener el mismo numero de registros agrega el valor -1 al
		 * ultimo registro RMSE.
		 * \param mse
		 */
		void appendMSE(double mse);

		/*!
		 * \brief appendRMSE Agrega el ultimo valor RMSE a la historia.
		 *
		 * Hay que tener especial cuidado con esta funcion ya que solo agrega el valor al registro
		 * de RMSEs, sin embargo, para mantener el mismo numero de registros agrega el valor -1 al
		 * ultimo registro MSE.
		 *
		 * \param rmse
		 */
		void appendRMSE(double rmse);

		virtual void setTime(double time);
		double getTime() const;

		virtual void setRootMeanSquareError(double rmse);
		double getRootMeanSquareError() const;

		virtual void setMeanSquareError(double mse);
		double getMeanSquareError() const;

		/*!
		 * \brief setEpochs
		 * \param epochs
		 */
		virtual void setEpochs(long long epochs);

		long long getEpochs() const;

		int getMSESize() const;

		concurrent_vector<double> getMSEHistory() const;
	private:
		Q_OBJECT

//		QMutex mutex;
		QReadWriteLock locker;

		double CE;
		long tries;
		long dataInterval;
		long long nRecords;
		long long epochs;
		concurrent_vector<double> ceHistory;
		concurrent_vector<long long> epochsHistory;
		concurrent_vector<double> mseHistory;
		concurrent_vector<double> rmseHistory;
		concurrent_vector<double> timeHistory;
		double time;
		double MSE;
		double RMSE;
};

#endif // MLPTRAININGRESULTCONCURRENTVECTOR_H
