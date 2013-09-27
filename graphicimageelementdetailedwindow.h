#ifndef GRAPHICIMAGEELEMENTDETAILEDWINDOW_H
#define GRAPHICIMAGEELEMENTDETAILEDWINDOW_H

#include <QGraphicsView>
#include <QVBoxLayout>
#include <QToolButton>
#include <QLineEdit>
#include <QContextMenuEvent>
#include <QFileDialog>
#include <QMenu>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>

//#include <QTextEdit>

#include <graphicelementdetailedwindow.h>

class GraphicImageElementDetailedWindow : public GraphicElementDetailedWindow
{
	public:
		explicit GraphicImageElementDetailedWindow(QImage *image, QWidget *parent = 0);

		QGraphicsView *getGraphicsView();

		void setImage(QImage *img);
		QImage *getImage();

		void setGraphicsPixmapItem(QGraphicsPixmapItem *pmitm);
		QGraphicsPixmapItem *getGraphicsPixmapItem();

	protected:

//		void contextMenuEvent(QContextMenuEvent *event);

	protected slots:
		void contextMenu(QPoint pos);
		void saveImage();
		void onZoomInClick();
		void onZoomOutClick();


	private:
		Q_OBJECT

		QGraphicsRectItem *rect;
		QGraphicsPixmapItem *itm;
		double zoom;
		QImage *img;
		QGraphicsView *gv;
		QLineEdit *tZoom;

		void initWindow(QImage *img);
};

#endif // GRAPHICIMAGEELEMENTDETAILEDWINDOW_H
