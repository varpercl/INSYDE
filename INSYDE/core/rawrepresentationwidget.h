#ifndef RAWREPRESENTATIONWIDGET_H
#define RAWREPRESENTATIONWIDGET_H

#include "share_core_lib.h"
#include "datarepresentationwidget.h"

namespace core{

/*!
 * \brief The RawRepresentationWidget class represents a widget which can be user friendly for
 * raw data (binary or numerical data).
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT RawRepresentationWidget : public DataRepresentationWidget
{
	public:

		/*!
		 * \brief Construct a RawRepresentationWidget from any \p data passed.
		 * \param data The data to be passed by the user.
		 * \param parent The parent of this widget.
		 */
		explicit RawRepresentationWidget(const vector<double> &data, QWidget *parent = 0);

		~RawRepresentationWidget();

		/*!
		 * \brief Updates the widget which will draw the current data.
		 */
		void update();

	private:
		Q_OBJECT
		/*!
		 * \brief Initialize all attributes of this class.
		 * \param inputs The inputs to be represented by this widget.
		 */
		void init(const vector<double> &inputs);
};
}
#endif // RAWREPRESENTATIONWIDGET_H
