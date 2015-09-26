#ifndef TRAININGSETTABLE_H
#define TRAININGSETTABLE_H

#include <QtWidgets>

#include <typeinfo>

#include "../ann_base/trainingset.h"
#include "../core/basictable.h"

using namespace ann_base;

/*!
 * \class
 *
 * \brief The TrainingSetTable class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class Q_DECL_EXPORT TrainingSetTable : public BasicTable
{
	public:
		explicit TrainingSetTable(TrainingSet *ts, QWidget *parent = 0);

		void setTrainingSet(TrainingSet *ts);
		TrainingSet *getTrainingSet() const;

		void setPrecision(int precision);
		int getPrecision() const;

		void setFormat(char format);
		char getFormat() const;

		void setInputsVisible(bool b);
		bool getInputsVisible() const;

		void setTargetsVisible(bool b);
		bool getTargetsVisible() const;

	signals:

		void trainingSetChanged(const TrainingSet *ts);

	private:
		Q_OBJECT

		bool inputsVisible;
		bool targetsVisible;
		char format;
		int decimalPrecision;

		TrainingSet *ts;

		void init(TrainingSet *ts);

		/*!
		 * \brief setModel Se bloquea el acceso al metodo \code{setModel} ya que se reemplazo por \code{setTrainingSet}
		 * \param model
		 */
		void setModel(QAbstractItemModel *model){return QTableView::setModel(model);}

};

#endif // TRAININGSETTABLE_H
