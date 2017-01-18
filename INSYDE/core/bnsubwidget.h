#ifndef BNSUBWIDGET_H
#define BNSUBWIDGET_H

#include <QWidget>

#include "share_core_lib.h"

namespace Ui {
class BNSubWidget;
}

namespace core{

/*!
 * \brief The BNSubWidget class encloses a widget with all necessary controls to handle a
 * black and white effect. This class is related to a BlackWhiteEffect object.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT BNSubWidget : public QWidget
{
		Q_OBJECT

	public:

		/*!
		 * \brief Creates a new BN widget which has an associated \p threshold.
		 *
		 * \param threshold The threshold to be assigned to the BlackWhiteEffect object.
		 * \param parent
		 */
		explicit BNSubWidget(double threshold, QWidget *parent = 0);

		~BNSubWidget();

		/*!
		 * \brief Establish a threshold to the BlackWhiteEffect object.
		 *
		 * \param ts The threshold to be assigned.
		 */
		void setThreshold(double ts);

		/*!
		 * \brief Obtains the current assigned threshold.
		 * \return A double value that represent the current threshold.
		 */
		double getThreshold();

	private:
		Ui::BNSubWidget *ui;

		/*!
		 * \brief Initialize all controlls of this dialog. Sets the dimentions and scales of them.
		 * \param threshold The threshold to be assigned to the BlackWhiteEffect object.
		 */
		void init(double threshold);
};
}
#endif // BNSUBWIDGET_H
