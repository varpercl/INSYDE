#ifndef GSSUBWIDGET_H
#define GSSUBWIDGET_H

#include <QWidget>

namespace Ui {
class GSSubWidget;
}

/*!
 * \brief The GSSubWidget class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT GSSubWidget : public QWidget
{
		Q_OBJECT

	public:
		explicit GSSubWidget(QWidget *parent = 0);
		~GSSubWidget();

	private:
		Ui::GSSubWidget *ui;
};

#endif // GSSUBWIDGET_H
