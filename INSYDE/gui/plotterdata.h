#ifndef PLOTTERMODEL_H
#define PLOTTERMODEL_H

#include <QStandardItemModel>
#include <QFile>

#include <../examples/tools/TableModel.h>

/*!
 * \brief The PlotterData class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT PlotterData : public QStandardItemModel
{
	public:
		PlotterData();

		~PlotterData();

		void addPoint(int serie, double value);

		void addPoint(const QVector<double> &valSeries);

		void addSerie(const QVector<double> &data);

		bool loadFromCSV(const QString &filename);

		void setInterval(double interval);
		double getInterval() const;

	protected:


	private:
		Q_OBJECT

		double interval;
		int nSeries;

		void init(int nSeries = 1);
};

#endif // PLOTTERMODEL_H
