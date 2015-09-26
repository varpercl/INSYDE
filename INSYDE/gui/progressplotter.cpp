#include "progressplotter.h"

ProgressPlotter::ProgressPlotter(QWidget *parent) :
	QFrame(parent)
{
}

void ProgressPlotter::setChart(KDChart::Chart *chart)
{
	mainChart = chart;
}

KDChart::Chart *ProgressPlotter::getChart() const
{
	return mainChart;
}

void ProgressPlotter::init()
{
	mainLayout = new QVBoxLayout(this);

	//Se configura el plotter principal
	mainChart = new KDChart::Chart();

	mainLayout->addWidget(mainChart);

	//Se configura el cuadro de series
	seriesBox = new QScrollArea();

	mainLayout->addWidget(seriesBox);

	setLayout(mainLayout);
}
