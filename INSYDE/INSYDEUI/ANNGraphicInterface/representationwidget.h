#ifndef REPRESENTATIONWIDGET_H
#define REPRESENTATIONWIDGET_H

#include <QWidget>

#include <vector>

#include "../graphicimageelementdetailedwindow.h"

using namespace std;

class RepresentationWidget : public QWidget
{
	public:

		enum RepresentationType{
			Image,
			Matrix
		};

		explicit RepresentationWidget(const vector<double> &datainput, QWidget *parent = 0);

		void setDataInput(const vector<double> &datainput);
		vector<double> getDataInput() const;

		virtual void updateRepresentation() = 0;

		virtual RepresentationType getRepresentationType() const = 0;

	protected:

		vector<double> dataInput;
		GraphicImageElementDetailedWindow *giedw;

	private:
		Q_OBJECT

		void initRW(const vector<double> &dataInput);
};

#endif // REPRESENTATIONWIDGET_H
