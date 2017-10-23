#ifndef REPRESENTATIONWIDGET_H
#define REPRESENTATIONWIDGET_H

#include <QtWidgets>

#include <vector>

#include "share_core_lib.h"

using namespace std;

namespace core{

/*!
 * \brief The DataRepresentationWidget class contains a wide graphical representation of any data used commonly on
 * TrainingSetDialog or another kind of data consumer.
 *
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT DataRepresentationWidget : public QWidget
{
	public:

		/*!
		 * \brief Builds this widget with input \p datainput.
		 * \param datainput The data input to be graphically represented.
		 * \param parent[in] The parent widget.
		 */
		explicit DataRepresentationWidget(const vector<double> &datainput, QWidget *parent = 0);


		/*!
		 * \brief Gets a vector containing all input passed to this class.
		 * \return An std::vector containing all double values passed as input.
		 */
		vector<double> getInputs() const;

	public slots:
		/*!
		 * \brief Sets the current data input of this class.
		 * \param datainput A vector with the input data.
		 */
		virtual void setInputs(const vector<double> &datainput);

	signals:

		/*!
		 * \brief
		 * \param size The size to be set.
		 */
		void sizeChanged(const QSize &size);

	protected:

		vector<double> inputs;

	private:
		Q_OBJECT

		QVBoxLayout *mainLayout;


		/*!
		 * \brief Initialize all this graphic interface.
		 * \param inputs The inputs to be passed to this class.
		 */
		virtual void init(const vector<double> &inputs);
};
}
#endif // REPRESENTATIONWIDGET_H
