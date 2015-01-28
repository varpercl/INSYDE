#ifndef TRAININGRESULT_H
#define TRAININGRESULT_H

#include <vector>

#include <QtCore>
#include <QFile>
#include <QString>
#include <QXmlStreamAttributes>
#include <QXmlStreamReader>
#include <QAbstractTableModel>

#include "ANNglobal.h"

using namespace std;

class ANNFRAMEWORK_EXPORT TrainingResult : public QAbstractTableModel
{
	public:

		explicit TrainingResult();

		explicit TrainingResult(long long epochs, double mse, double rmse);

		virtual ~TrainingResult();

//		QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
//		QModelIndex parent(const QModelIndex &child) const;
		int rowCount(const QModelIndex &parent = QModelIndex()) const;
		int columnCount(const QModelIndex &parent = QModelIndex()) const;

		QVariant data(const QModelIndex &index, int role) const;
//		bool setData(const QModelIndex &index, const QVariant &value, int role);

		QVariant headerData(int section, Qt::Orientation orientation, int role) const;

		/*!
		 * \brief setEpochs
		 * \param epochs
		 */
		virtual void setEpochs(long long epochs);

		long long getEpochs() const;

		void incEpochs(int inc = 1);

		void decEpochs(int dec = 1);

		virtual void setRootMeanSquareError(double rmse);
		double getRootMeanSquareError() const;

		virtual void setMeanSquareError(double mse);
		double getMeanSquareError() const;

		vector<double> getMSEHistory() const;

		int getMSESize() const;

		vector<double> getRMSEHistory() const;

		int getRMSESize() const;

		/*!
		 * \brief setTime Establece el tiempo de entrenamiento transcurrido para la epoca actual.
		 * \param time - Tiempo en segundos que han transcurrido
		 */
		virtual void setTime(double time);

		/*!
		 * \brief getTime Devuelve el tiempo de entrenamiento transcurrido para la epoca actual.
		 * \return Tiempo en segundos
		 */
		double getTime() const;

		virtual bool save(const QString &path);

		virtual void clear();

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

		void appendRecord(double mse, double rmse);

		void setDataInterval(long interval);
		long getDataInterval() const;

	protected:

//		QMutex mutex;

		long tries;
		long dataInterval;
		long long nRecords;
		long long epochs;
		vector<long long> epochsHistory;
		vector<double> mseHistory;
		vector<double> rmseHistory;
		vector<double> timeHistory;
		double time;
		double MSE;
		double RMSE;

	private:
		Q_OBJECT
};

#endif // TRAININGRESULT_H
