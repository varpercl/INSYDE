#ifndef GRAPHICMLPELEMENTPROPERTYDIALOG_H
#define GRAPHICMLPELEMENTPROPERTYDIALOG_H

#include <QDialog>

#include "../INSYDEUI_global.h"

namespace Ui {
class GraphicMLPElementPropertyDialog;
}

class INSYDEUISHARED_EXPORT GraphicMLPElementPropertyDialog : public QDialog
{
		Q_OBJECT
		
	public:
		explicit GraphicMLPElementPropertyDialog(QWidget *parent = 0);
		~GraphicMLPElementPropertyDialog();
		
	private:
		Ui::GraphicMLPElementPropertyDialog *ui;
};

#endif // GRAPHICMLPELEMENTPROPERTYDIALOG_H
