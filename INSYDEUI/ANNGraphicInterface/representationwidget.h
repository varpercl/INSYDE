#ifndef REPRESENTATIONWIDGET_H
#define REPRESENTATIONWIDGET_H

#include <QWidget>

#include <vector>

using namespace std;

class RepresentationWidget : public QWidget
{
	public:
		explicit RepresentationWidget(const vector<double> &datainput, QWidget *parent = 0);

		void setDataInput(const vector<double> &datainput);
		vector<double> getDataInput() const;

		virtual void updateRepresentation() = 0;

	protected:

		vector<double> dataInput;

	private:
		Q_OBJECT

		void initRW(const vector<double> &dataInput);
};

#endif // REPRESENTATIONWIDGET_H
