#ifndef GBGRAPHICREPRESENTATION_H
#define GBGRAPHICREPRESENTATION_H

#include <vector>

#include <QImage>
#include <QtWidgets>

#include "normalizationwidget.h"
#include "imagerepresentationwidget.h"
#include "../graphicimageelementdetailedwindow.h"

using namespace std;

namespace Ui {
	class gbGraphicRepresentation;
}

class DataRepresentationBox : public QGroupBox
{

	public:
		explicit DataRepresentationBox(const vector<double> &inputdata = vector<double>(), QWidget *parent = 0);
		~DataRepresentationBox();

		virtual void setDataInput(const vector<double> &inputs);
		vector<double> getDataInput() const;

		RepresentationWidget *getRepresentationWidget() const;

	private:
		Q_OBJECT

		ImageRepresentationWidget *irw;
		vector<double> inputs;
		Ui::gbGraphicRepresentation *ui;

		void initGR(const vector<double> &inputdata);
};

#endif // GBGRAPHICREPRESENTATION_H
