#ifndef MLPTRAININGRESULT_H
#define MLPTRAININGRESULT_H

#include <vector>
#include <QtCore>

#include "share_ann_base_lib.h"
#include "globals.h"
#include "trainingresult.h"

using namespace std;

namespace ann_base{
/*!
 * \class
 *
 * \brief MLPTrainingResult contiene la data obtenida durante un ciclo de entrenamiento de una red neuronal cualquiera.
 *
 * Esta clase hace uso del esquema Modelo/Vista de Qt lo cual lo hace muy util para ser visualizado en tablas o para
 * ser graficado en tiempo real como lo hacen las ventanas de entrenamiento de las redes neuronales.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_BASE_LIB_IMPORT_EXPORT MLPTrainingResult : public TrainingResult
{
	public:

		explicit MLPTrainingResult();

		explicit MLPTrainingResult(long long epochs, double mse, double rmse, double ce, double time);

		MLPTrainingResult(const MLPTrainingResult &mlptr);

		~MLPTrainingResult();

		void setClasificationError(double ce);
		double getClasificationError() const;

		vector<double> getCEHistory() const;

		int getCESize() const;

		bool save(const QString &path);

		void clear();

		void appendCE(double ce);

		void appendRecord(double mse, double rmse, double ce);

		MLPTrainingResult &operator =(const MLPTrainingResult &mlptr);

		void setMSEVisible(bool hi);
		void setRMSEVisible(bool hi);
		void setCEVisible(bool hi);

	protected:

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


	private:
		Q_OBJECT

		int
		mseIndex,
		rmseIndex,
		ceIndex;

		bool visibleCE;

		//		QMutex mutex;
		QReadWriteLock locker;

		double CE;
		vector<double> ceHistory;

		void init();

		void updateColIndexes();
};
}

#endif // MLPTRAININGRESULT_H
