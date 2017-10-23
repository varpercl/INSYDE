#ifndef CHARTREPRESENTATION_H
#define CHARTREPRESENTATION_H

#include <QtCharts>

#include "definitions.h"
#include "datarepresentationwidget.h"
#include "labeledcombobox.h"

namespace core {

class CORE_LIB_IMPORT_EXPORT ChartRepresentation : public DataRepresentationWidget
{
	public:

		/*!
		 * \brief The ChartType enum
		 */
		enum ChartType
		{
			Line
//			Bars,
//			Pie
//			Area
		};

		/*!
		 * \brief ChartRepresentation
		 * \param parent
		 */
		explicit ChartRepresentation(QWidget *parent = 0);


	public slots:
		/*!
		 * \brief setInputs
		 * \param datainput
		 */
		void setInputs(const vector<double> &datainput);

		/*!
		 * \brief setChartType
		 * \param type
		 */
		void setChartType(ChartType type);

	private slots:
		/*!
		 * \brief onCurrentChartTypeChanged
		 * \param index
		 */
		void onCurrentChartTypeChanged(int index);


	private:
		Q_OBJECT
		Q_ENUM(ChartType)

		LabeledComboBox *cbChartType;
		QGroupBox *gbProperties;
		QChart *chart;
		QChartView *mainChartView;

//		QAreaSeries *areaSerie;
//		QPieSeries *pieSerie;
//		QBarSeries *barSerie;
		QLineSeries *lineSerie;

		QBarSet *bsInputs;

		QVBoxLayout *gbLayout;

		ChartType type;
		/*!
		 * \brief init
		 */
		void init(const vector<double> &datainput);

		void init();

};

}

#endif // CHARTREPRESENTATION_H
