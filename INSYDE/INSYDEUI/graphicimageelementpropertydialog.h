#ifndef GRAPHICIMAGEELEMENTPROPERTYDIALOG_H
#define GRAPHICIMAGEELEMENTPROPERTYDIALOG_H

#include <QDialog>

#include "INSYDEUI_global.h"

namespace Ui {
class GraphicImageElementPropertyDialog;
}

class INSYDEUISHARED_EXPORT GraphicImageElementPropertyDialog : public QDialog
{
		Q_OBJECT
		
	public:
		explicit GraphicImageElementPropertyDialog(QWidget *parent = 0);
		~GraphicImageElementPropertyDialog();
		
	private:
		Ui::GraphicImageElementPropertyDialog *ui;
};

#endif // GRAPHICIMAGEELEMENTPROPERTYDIALOG_H
