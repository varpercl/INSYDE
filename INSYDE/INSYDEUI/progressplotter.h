#ifndef PROGRESSPLOTTER_H
#define PROGRESSPLOTTER_H

#include <QtWidgets>

#include <KDChart/KDChart>

class ProgressPlotter : public QFrame
{
	public:
		explicit ProgressPlotter(QWidget *parent = 0);

		void setChart(KDChart::Chart *chart);
		KDChart::Chart *getChart() const;

		void addSerie();


	signals:

	public slots:

	private:

		Q_OBJECT

		QVector<QCheckBox*> series;
		QScrollArea *seriesBox;
		QVBoxLayout *mainLayout;
		KDChart::Chart *mainChart;

		void init();
};

#endif // PROGRESSPLOTTER_H
