#ifndef BNSUBWIDGET_H
#define BNSUBWIDGET_H

#include <QWidget>

namespace Ui {
class BNSubWidget;
}

/*!
 * \brief The BNSubWidget class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT BNSubWidget : public QWidget
{
		Q_OBJECT

	public:
		explicit BNSubWidget(double threshold, QWidget *parent = 0);
		~BNSubWidget();

		void setThreshold(double ts);
		double getThreshold();

	private:
		Ui::BNSubWidget *ui;

		void initBNSW(double threshold);
};

#endif // BNSUBWIDGET_H
