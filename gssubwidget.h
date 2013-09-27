#ifndef GSSUBWIDGET_H
#define GSSUBWIDGET_H

#include <QWidget>

namespace Ui {
class GSSubWidget;
}

class GSSubWidget : public QWidget
{
		Q_OBJECT
		
	public:
		explicit GSSubWidget(QWidget *parent = 0);
		~GSSubWidget();
		
	private:
		Ui::GSSubWidget *ui;
};

#endif // GSSUBWIDGET_H
