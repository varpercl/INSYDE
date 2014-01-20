#ifndef SELECTIMAGESEGMENTDIALOG_H
#define SELECTIMAGESEGMENTDIALOG_H

#include <QDialog>

#include "INSYDEUI_global.h"
#include "graphicimageelementdetailedwindow.h"

namespace Ui {
	class SelectImageSegmentDialog;
}

class INSYDEUISHARED_EXPORT SelectImageSegmentDialog : public QDialog
{

	public:
		explicit SelectImageSegmentDialog(const QImage &img, QWidget *parent = 0);
		~SelectImageSegmentDialog();

	private:
		Q_OBJECT

		GraphicImageElementDetailedWindow *giedw;
		Ui::SelectImageSegmentDialog *ui;

		void initSISD(const QImage &img);
};

#endif // SELECTIMAGESEGMENTDIALOG_H
