#ifndef GSSUBWIDGET_H
#define GSSUBWIDGET_H

#include <QWidget>

#include "share_core_lib.h"

namespace Ui {
class GSSubWidget;
}

namespace core{

/*!
 * \brief The GSSubWidget class is a speciallized widget which makes
 * the user available to set GrayScaleEffect properties.
 *
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT GSSubWidget : public QWidget
{
		Q_OBJECT

	public:

		/*!
		 * \brief Builds an empty parameters widget.
		 * \param[in] parent The parent of this widget.
		 */
		explicit GSSubWidget(QWidget *parent = 0);
		~GSSubWidget();

	private:
		Ui::GSSubWidget *ui;
};
}
#endif // GSSUBWIDGET_H
