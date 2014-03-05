#ifndef SELECTIMAGESEGMENTDIALOG_H
#define SELECTIMAGESEGMENTDIALOG_H

#include <QDialog>

#include "INSYDEUI_global.h"
#include "graphicimageelementdetailedwindow.h"
#include "integersizewidget.h"

namespace Ui {
	class SelectImageSegmentDialog;
}

class INSYDEUISHARED_EXPORT SelectImageSegmentDialog : public QDialog
{

	public:
		explicit SelectImageSegmentDialog(const QImage &img, const QRect &selrect, QWidget *parent = 0);
		~SelectImageSegmentDialog();

		void setSelectionRect(const QRect &rect);
		QRect getSelectionRect() const;

		QImage getImageSegment() const;

		void setIntegerSizeWidget(IntegerSizeWidget *isw);
		IntegerSizeWidget *getIntegerSizeWidget() const;

	private:
		Q_OBJECT

		IntegerSizeWidget *isw;
		GraphicImageElementDetailedWindow *giedw;
		Ui::SelectImageSegmentDialog *ui;

		void initSISD(const QImage &img, const QRect &selrect);

	private slots:
		void onWidthChanged(int width);
		void onHeightChanged(int height);
};

#endif // SELECTIMAGESEGMENTDIALOG_H
