#ifndef GRAPHICIMAGEELEMENTDETAILEDWINDOW_H
#define GRAPHICIMAGEELEMENTDETAILEDWINDOW_H

#include <QGraphicsView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QMenu>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>

#include <QContextMenuEvent>

#include "pixmapitem.h"
#include "INSYDEUI_global.h"
#include "../INSYDEUI/graphicelementdetailedwindow.h"

class INSYDEUISHARED_EXPORT GraphicImageElementDetailedWindow : public GraphicElementDetailedWindow
{
	public:
		explicit GraphicImageElementDetailedWindow(const QImage &image, QWidget *parent = 0);

		QGraphicsView *getGraphicsView();

		void setImage(const QImage &img);
		QImage getImage() const;

		void setGraphicsPixmapItem(PixmapItem *pmitm);
		QGraphicsPixmapItem *getGraphicsPixmapItem();

		void setBorderVisible(bool bv);
		bool getBorderVisible() const;

		void setBorderColor(const QColor &color);
		QColor getBorderColor() const;

		void setSelectionRectVisible(bool srv);
		bool getSelectionRectVisible() const;

		void setSelectionRectColor(const QColor &color);
		QColor getSelectionRectColor() const;

		void setSelectionRect(const QRectF &rect);
		QRectF getSelectionRect() const;

	protected slots:
		void contextMenu(QPoint pos);
		void saveImage();
		void onZoomInClick();
		void onZoomOutClick();

	private:
		Q_OBJECT

		//Representa el rectangulo que rebordeara la imagen
		QGraphicsRectItem *rect;
		PixmapItem *pmItm;
		double zoom;
		QImage img;
		QGraphicsView *gv;
		QLineEdit *tZoom;

		void initWindow(const QImage &img);
};

#endif // GRAPHICIMAGEELEMENTDETAILEDWINDOW_H
