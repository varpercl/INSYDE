#include "progressplotter.h"

gui::ProgressPlotter::ProgressPlotter(QWidget *parent) :
	QFrame(parent)
{
}

//void gui::ProgressPlotter::setChart(KDChart::Chart *chart)
//{
//	mainChart = chart;
//}

//KDChart::Chart *gui::ProgressPlotter::getChart() const
//{
//	return mainChart;
//}

void gui::ProgressPlotter::init()
{
	mainLayout = new QVBoxLayout(this);

	//Se configura el plotter principal
//	mainChart = new KDChart::Chart();

//	mainLayout->addWidget(mainChart);

	//Se configura el cuadro de series
	seriesBox = new QScrollArea();

	mainLayout->addWidget(seriesBox);

	setLayout(mainLayout);
}
