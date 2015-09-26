#ifndef TRAININGRESULT_H
#define TRAININGRESULT_H

#include <vector>

#include <QtCore>
#include <QFile>
#include <QString>
#include <QXmlStreamAttributes>
#include <QXmlStreamReader>
#include <QAbstractTableModel>

#include "globals.h"

using namespace std;

namespace ann_base{
/*!
 * \class
 *
 * \brief TrainingResult es una clase base para resultados de entrenamiento de redes neuronales. Almacena informacion
 * basica sobre los resultados de las redes neuronales durante su etapa de entrenamiento.
 *
 * \author Edixon Vargas
 * \date 03/02/2015
 */
class Q_DECL_EXPORT TrainingResult : public QAbstractTableModel
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

		/*!
		 * \brief getMSESize Return the number of MSE records
		 * \return
		 */
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

		/*!
		 * \brief appendRecord
		 * \param mse
		 * \param rmse
		 */
		void appendRecord(double mse, double rmse);

		/*!
		 * \brief setDataInterval
		 * \param interval
		 */
		void setDataInterval(long interval);

		/*!
		 * \brief getDataInterval
		 * \return
		 */
		long getDataInterval() const;

		virtual void setMSEVisible(bool hi);

		/*!
		 * \brief setRMSEVisible Establish if RMSE will be returned when is demanded on \code{data()} method. It is
		 * useful if you dont want to show this data serie over a chart, for example.
		 * \param hi True if you want to show.
		 */
		virtual void setRMSEVisible(bool hi);

		/*!
		 * \brief isEmpty Return true if training result has not data to save.
		 * \return a boolean that indicates wether training result is empty or not
		 */
		bool isEmpty() const;

	protected:

		bool
		visibleMSE,
		visibleRMSE;

		long
		tries,
		dataInterval;

		unsigned long long
		nRecords,
		epochs;

		vector<long long> epochsHistory;

		vector<double>
		mseHistory,
		rmseHistory,
		timeHistory;

		double
		time,
		MSE,
		RMSE;

	private:
		Q_OBJECT

		void init();
};
}

#endif // TRAININGRESULT_H
