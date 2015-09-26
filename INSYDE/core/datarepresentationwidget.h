#ifndef REPRESENTATIONWIDGET_H
#define REPRESENTATIONWIDGET_H

#include <QtWidgets>

#include <vector>

using namespace std;

/*!
 * \class
 *
 * \brief The DataRepresentationWidget class contains a wide graphical representation of any data used commonly on
 * \code{TrainingSetDialog} or another kind of data consumer.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT DataRepresentationWidget : public QWidget
{
	public:

		/*!
		 * \brief DataRepresentationWidget
		 * \param datainput
		 * \param parent
		 */
		explicit DataRepresentationWidget(const vector<double> &datainput, QWidget *parent = 0);

		/*!
		 * \brief setInputs
		 * \param datainput
		 */
		virtual void setInputs(const vector<double> &datainput);

		/*!
		 * \brief getInputs
		 * \return
		 */
		vector<double> getInputs() const;

	private:
		Q_OBJECT

		QVBoxLayout *mainLayout;

		vector<double> inputs;

		/*!
		 * \brief init
		 * \param inputs
		 */
		virtual void init(const vector<double> &inputs);
};

#endif // REPRESENTATIONWIDGET_H
