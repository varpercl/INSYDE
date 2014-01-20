#ifndef GRAPHICELEMENTDETAILEDWINDOW_H
#define GRAPHICELEMENTDETAILEDWINDOW_H

#include <QWidget>
#include <QToolBar>

namespace Ui {
class GraphicElementDetailedWindow;
}

class GraphicElementDetailedWindow : public QWidget
{
		Q_OBJECT
		
	public:
		explicit GraphicElementDetailedWindow(QWidget *parent = 0);
		~GraphicElementDetailedWindow();

		void setVisibleToolbar(bool vtb);
		
	protected:

		QToolBar *mainToolbar;

		void setToolbar(QToolBar *tb);
		QToolBar *getToolbar();

	private:
		Ui::GraphicElementDetailedWindow *ui;

		void initWindow();
};

#endif // GRAPHICELEMENTDETAILEDWINDOW_H
