#include "chartrepresentation.h"

using namespace core;

ChartRepresentation::ChartRepresentation(QWidget *parent) :
	DataRepresentationWidget(vector<double>(1), parent)
{
	init(vector<double>(1));
}

void ChartRepresentation::setInputs(const vector<double> &datainput)
{

	DataRepresentationWidget::setInputs(datainput);


	size_t sInputs = datainput.size();

	switch(type)
	{
		case core::ChartRepresentation::Line:
			if(lineSerie->count() != sInputs){
				lineSerie->clear();

				lineSerie->blockSignals(true);
				for(size_t i = 0; i < sInputs; i++)
				{
					lineSerie->append(QPointF(i, datainput[i]));
				}
				lineSerie->blockSignals(false);
			}
			else{
//				lineSerie->blockSignals(true);
				double val;
				for(size_t i = 0; i < sInputs; i++)
				{
					val = datainput[i];
					if(lineSerie->at(i).y() != val)
						lineSerie->replace(i, i, val);
//					lineSerie->replace(i, QPointF(i, datainput[i]));
				}
//				lineSerie->blockSignals(false);

			}

			if(sInputs > 0)
			{
				chart->axisY(lineSerie)->setMax(*max_element(datainput.begin(), datainput.end()));
				chart->axisY(lineSerie)->setMin(*min_element(datainput.begin(), datainput.end()));
				chart->axisX(lineSerie)->setMax(sInputs);
			}
			else
			{
				chart->axisY(lineSerie)->setMax(1);
				chart->axisX(lineSerie)->setMax(1);
			}
			break;
//		case core::ChartRepresentation::Bars:
////			if(barSerie->count() != sInputs){

//			barSerie->clear();
//			QBarSet *bs;
//				barSerie->blockSignals(true);
//				for(size_t i = 0; i < sInputs; i++)
//				{
//					bs = new QBarSet(QString::number(i));
//					bs->append(datainput[i]);
//					barSerie->append(bs);
//				}
//				barSerie->blockSignals(false);
////			}
////			else{
////				barSerie->blockSignals(true);
////				for(size_t i = 0; i < sInputs; i++)
////				{
//////					barSerie->replace(i, QPointF(i, datainput[i]));
////				}
////				barSerie->blockSignals(false);
////			}

//			if(sInputs > 0)
//			{
//				chart->axisY(barSerie)->setMax(*max_element(datainput.begin(), datainput.end()));
//				chart->axisY(barSerie)->setMin(*min_element(datainput.begin(), datainput.end()));
//				chart->axisX(barSerie)->setMax(sInputs);
//			}
//			else
//			{
//				chart->axisY(barSerie)->setMax(1);
//				chart->axisX(barSerie)->setMax(1);
//			}
//			break;
//		case core::ChartRepresentation::Pie:
////			if(pieSerie->count() != sInputs){
//				pieSerie->clear();

//				pieSerie->blockSignals(true);
//				for(size_t i = 0; i < sInputs; i++)
//				{
//					pieSerie->append(QString::number(i), datainput[i]);
//				}
//				pieSerie->blockSignals(false);
////			}
////			else{
////				pieSerie->blockSignals(true);
////				for(size_t i = 0; i < sInputs; i++)
////				{
////					pieSerie->replace(i, QPointF(i, datainput[i]));
////				}
////				pieSerie->blockSignals(false);
////			}

//			if(sInputs > 0)
//			{
//				chart->axisY(pieSerie)->setMax(*max_element(datainput.begin(), datainput.end()));
//				chart->axisY(barSerie)->setMin(*min_element(datainput.begin(), datainput.end()));
//				chart->axisX(barSerie)->setMax(sInputs);
//			}
//			else
//			{
//				chart->axisY(pieSerie)->setMax(1);
//				chart->axisX(pieSerie)->setMax(1);
//			}
//			break;
//		case core::ChartRepresentation::Area:
//			if(areaSerie->count() != sInputs){
//				areaSerie->clear();

//				areaSerie->blockSignals(true);
//				for(size_t i = 0; i < sInputs; i++)
//				{
//					areaSerie->append(QPointF(i, datainput[i]));
//				}
//				areaSerie->blockSignals(false);
//			}
//			else{
//				areaSerie->blockSignals(true);
//				for(size_t i = 0; i < sInputs; i++)
//				{
//					areaSerie->replace(i, QPointF(i, datainput[i]));
//				}
//				areaSerie->blockSignals(false);
//			}

//			if(sInputs > 0)
//			{
//				chart->axisY(areaSerie)->setMax(*max_element(datainput.begin(), datainput.end()));
//				chart->axisY(areaSerie)->setMin(*min_element(datainput.begin(), datainput.end()));
//				chart->axisX(areaSerie)->setMax(sInputs);
//			}
//			else
//			{
//				chart->axisY(areaSerie)->setMax(1);
//				chart->axisX(areaSerie)->setMax(1);
//			}
//			break;

	}
	chart->update();
	mainChartView->update();
}

void ChartRepresentation::setChartType(ChartRepresentation::ChartType type)
{
	this->type = type;
	switch (type)
	{

//		case core::ChartRepresentation::Bars:
//			lineSerie->setVisible(false);
////			areaSerie->setVisible(false);
//			pieSerie->setVisible(false);

////			chart->removeAllSeries();
////			chart->addSeries(barSerie);
//			barSerie->setVisible(true);
//			break;
//		case core::ChartRepresentation::Pie:
//			lineSerie->setVisible(false);
////			areaSerie->setVisible(false);
//			barSerie->setVisible(false);

////			chart->removeAllSeries();
////			chart->addSeries(pieSerie);
//			pieSerie->setVisible(true);
//			break;
////		case core::ChartRepresentation::Area:
////			lineSerie->setVisible(false);
////			barSerie->setVisible(false);
////			pieSerie->setVisible(false);

//////			chart->removeAllSeries();
//////			chart->addSeries(areaSerie);
////			areaSerie->setVisible(true);
////			break;

		case core::ChartRepresentation::Line:
		default:
//			areaSerie->setVisible(false);
//			barSerie->setVisible(false);
//			pieSerie->setVisible(false);

//			chart->removeAllSeries();

//			chart->addSeries(lineSerie);
			lineSerie->setVisible(true);
			break;
	}
}

void ChartRepresentation::onCurrentChartTypeChanged(int index)
{
	setChartType((ChartType) index);
}

void ChartRepresentation::init(const vector<double> &datainput)
{
	gbLayout = new QVBoxLayout();

	cbChartType = new LabeledComboBox(tr("Chart type"));

	gbProperties = new QGroupBox(tr("Properties"));

	chart = new QChart();

//	barSerie = new QBarSeries();
//	pieSerie = new QPieSeries();
//	areaSerie = new QAreaSeries();
	lineSerie = new QLineSeries();

	mainChartView = new QChartView();

	lineSerie->setName(tr("Pattern"));

	setChartType(Line);

//	bsInputs = new QBarSet(tr("Patterns"));
//	barSerie->append(bsInputs);

//	chart->addSeries(barSerie);

	chart->addSeries(lineSerie);
	chart->createDefaultAxes();

	((QValueAxis*)chart->axisX(lineSerie))->setLabelFormat("%d");

	mainChartView->setRenderHint(QPainter::Antialiasing);
//	mainChartView->setGeometry(0, 0, 100, 100);
	mainChartView->setChart(chart);

	cbChartType->getComboBox()->addItems(QStringList()
										 << tr("Line")
//										 << tr("Bars")
//										 << tr("Pie")
										 /*<< tr("Area")*/);
	gbLayout->addWidget(cbChartType);
	gbProperties->setLayout(gbLayout);

	layout()->addWidget(gbProperties);
	layout()->addWidget(mainChartView);

//	setInputs(datainput);

	connect(cbChartType->getComboBox(), SIGNAL(currentIndexChanged(int)), SLOT(onCurrentChartTypeChanged(int)));
//	setLayout(vlayout);
}


void ChartRepresentation::init()
{
	init(vector<double>(1));
}
