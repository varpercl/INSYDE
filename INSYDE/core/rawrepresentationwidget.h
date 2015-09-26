#ifndef RAWREPRESENTATIONWIDGET_H
#define RAWREPRESENTATIONWIDGET_H

#include "datarepresentationwidget.h"

/*!
 * \class
 *
 * \brief The RawRepresentationWidget class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT RawRepresentationWidget :public DataRepresentationWidget
{
	public:
		RawRepresentationWidget(const vector<double> &data, QWidget *parent = 0);
		~RawRepresentationWidget();

		void update();

	private:

		void init(const vector<double> &inputs);
};

#endif // RAWREPRESENTATIONWIDGET_H
