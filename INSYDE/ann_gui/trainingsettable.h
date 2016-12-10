#ifndef TRAININGSETTABLE_H
#define TRAININGSETTABLE_H

#include <QtWidgets>

#include <typeinfo>

#include "share_ann_gui_lib.h"
#include "../ann_base/trainingset.h"
#include "../core/basictable.h"

using namespace ann_base;

/*!
 * \class
 *
 * \brief The TrainingSetTable class
 *
 * FIXME: This class SHOULD NOT USE directly a TrainingSet model, has been demostrated the better way to implement this
 * is making a class wrapper so the user be able to get several models from the same TrainingSet then each wrapper can
 * be shown in different views with different properties or settings without compromise integrity of the TrainingSet.
 *
 * One example, user wants to show in a TrainingSetTable only inputs and using another TrainingSetTable instance to show
 * only targets. This implies a method that stablish wether inputs or targets are visibles or not. But when user insert
 * any column, these are by default visible so user needs to create a method wich updates each collumn inserted and turns
 * it hidden. If there was a wrapper could be implemented a method (member of wrapper) stablishing what will be visible
 * and wath won't, so method \code{data} (from model wrapper) only deliver visible data user wants to show. This is more
 * effective than delivering all data.
 *
 * Wrapper can be useful too if user wants to show a training set in different data representations of the same TS.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_GUI_LIB_IMPORT_EXPORT TrainingSetTable : public BasicTable
{
	public:
		explicit TrainingSetTable(TrainingSet *ts, QWidget *parent = 0);

		/*!
		 * \brief setTrainingSet Assigns the respective training set to be shown by this table.
		 * \param ts
		 */
		void setTrainingSet(TrainingSet *ts);

		/*!
		 * \brief getTrainingSet Returns training set assigned to this table.
		 * \return
		 */
		TrainingSet *getTrainingSet() const;

		/*!
		 * \brief setPrecision Establish how much precision you need when you show and edit values.
		 * \param precision
		 */
		void setPrecision(int precision);

		/*!
		 * \brief getPrecision Returns the current precision asigned.
		 * \return
		 */
		int getPrecision() const;

		/*!
		 * \brief setFormat Sets the respective format you want to show the numeric data
		 * \param format
		 */
		void setFormat(char format);

		/*!
		 * \brief getFormat Returns the current format assigned
		 * \return
		 */
		char getFormat() const;

		/*!
		 * \brief setInputsVisible Establish if you want to show in one table the training set's inputs.
		 * \param b
		 */
		void setInputsVisible(bool b);

		/*!
		 * \brief getInputsVisible Return true if training set's inputs are shown.
		 * \return
		 */
		bool getInputsVisible() const;

		/*!
		 * \brief setTargetsVisible Establish if you want to show in one table the training set's targets.
		 * \param b
		 */
		void setTargetsVisible(bool b);

		/*!
		 * \brief getTargetsVisible Return true if training set's inputs are shown.
		 * \return
		 */
		bool getTargetsVisible() const;

	protected slots:

		/*!
		 * \brief onInsertRightColumnTriggered
		 * \reimp
		 */
		void onInsertRightColumnTriggered();

//		/*!
//		 * \brief onInsertLeftColumnTriggered
//		 * \reimp
//		 */
//		void onInsertLeftColumnTriggered();

//		/*!
//		 * \brief onInsertUpRowTriggered
//		 * \reimp
//		 */
//		void onInsertUpRowTriggered();

//		/*!
//		 * \brief onInsertDownRowTriggered
//		 * \reimp
//		 */
//		void onInsertDownRowTriggered();

	private slots:

		/*!
		 * \brief onColumnInserted Throwed when a column is inserted.
		 *
		 * FIXME: this slot is temporarily used to solve the problem mentioned above on the description of the class.
		 * Is called every time a column is inserted due each new column inserted is visible by default. This is messy
		 * because those inserted columns are shown by default too and need to be updated.
		 *
		 * \param column
		 */
		void onColumnInserted(int column);

		void onInputsSizeChanged(int lsize, int nsize);

		void onTargetsSizeChanged(int newSize, int nsize);

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

		void updateColumnVisibility();

		void connectTSSignals();
};

#endif // TRAININGSETTABLE_H
