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
		
	protected:

		QToolBar *mainToolbar;

		void setToolbar(QToolBar *tb);
		QToolBar *getToolbar();

		void setVisibleToolbar(bool vtb);

	private:
		Ui::GraphicElementDetailedWindow *ui;

		void initWindow();
};

#endif // GRAPHICELEMENTDETAILEDWINDOW_H
