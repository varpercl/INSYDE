#ifndef TRAININGSETTABLE_H
#define TRAININGSETTABLE_H

#include <QtWidgets>

#include <typeinfo>

#include "ANNFramework/trainingsetinterface.h"
#include "ANNFramework/trainingset.h"

class TrainingSetTable : public QTableWidget/*, public ITrainingSet*/
{
	public:
		explicit TrainingSetTable(TrainingSet *ts, QWidget *parent = 0);

		void setTrainingSet(TrainingSet *ts);
		TrainingSet *getTrainingSet() const;

		void setPrecision(int precision);
		int getPrecision() const;

		void setFormat(char format);
		char getFormat() const;

	signals:
		void trainingSetChanged(const TrainingSet *ts);

	public slots:

	private:
		Q_OBJECT

		char format;
		int decimalPrecision;

		TrainingSet *ts;

		void initTST(TrainingSet *ts);

		void updateHeaders();

		void connectTSSignals();

		template<typename T> void privateAppendPattern(const vector<T> &input, const vector<T> &target)
		{
			setRowCount(rowCount() + 1);

			int
					inputSize = ts->getInputSize(),
					targetSize = ts->getTargetSize();
			int nRows = rowCount();

			QTableWidgetItem *itm;
//			string type;
			blockSignals(true);
			for(int i = 0; i < inputSize; i++){
//				type = typeid(input[i]).name();
				itm = new QTableWidgetItem(QString::number(input[i], format, decimalPrecision));
				itm->setTextAlignment(Qt::AlignRight);
				setItem(nRows-1, i, itm);
			}
			for(int j = inputSize; j <  inputSize + targetSize; j++){
//				type = typeid(target[j]).name();
				itm = new QTableWidgetItem(QString::number(target[j - inputSize], format, decimalPrecision));
				itm->setTextAlignment(Qt::AlignRight);
				setItem(nRows-1, j, itm);
			}
			blockSignals(false);
		}

	private slots:

		/*!
		 * NOTE: estos metodos (slots) estan dispuestos para la actualizacion del
		 * estado de la tabla. Por ningun motivo se debe llamar dentro de estos metodos algun otro metodo
		 * que venga directamente de esta clase y que modifique el estado de la variable \code{ts} que
		 * contiene el TrainingSet correspondiente a esta tabla. Esto traeria como consecuencia que se
		 * incurriera en un lazo recurrente que haria que la aplicacion colapsara.
		 *
		 * La clase \code{TrainingSet} a fin de mejorar la funcionalidad dispone de señales que se disparan
		 * cada vez que se hace una modificacion sobre la misma.
		 *
		 * En esta clase se decidio conectar cada señal al slot correspondiente, de modo tal que estos son llamados
		 * cuando el estado del conjunto de entrenamiento es modificado. Esto trae como ventaja, que si algun
		 * objeto apunta al mismo conjunto de entrenamiento al que apunta la variable \code{ts} y este llegara a
		 * modificar el estado del mismo, se disparara una señal que automaticamente actualizara la tabla
		 * correspondiente, incluso si esta no tiene foco alguno.
		 */
		void onInputsChanged(const vector<vector<double> > &li, const vector<vector<double> > &ni);
		void onTargetsChanged(const vector<vector<double> > &lt, const vector<vector<double> > &nt);
		void onInputSizeChanged(int ls, int ns);
		void onTargetSizeChanged(int ls, int ns);

		void onPatternAdded(const vector<double> &inputs, const vector<double> &targets);

		void onPatternDeleted(const vector<double> &inputs, const vector<double> &targets, int index);
		void onPatternInserted(const vector<double> &inputs, const vector<double> &targets, int index);

		void onInputChanged(int pat, int index, double value);
		void onTargetChanged(int pat, int index, double value);
		void onPatternChanged(int index, const vector<double> &inputs, const vector<double> &targets);

		void onCellChanged(int row, int col);

};

#endif // TRAININGSETTABLE_H
