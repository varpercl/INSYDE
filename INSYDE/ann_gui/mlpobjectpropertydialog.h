#ifndef GRAPHICMLPELEMENTPROPERTYDIALOG_H
#define GRAPHICMLPELEMENTPROPERTYDIALOG_H

#include <QDialog>

#include "share_ann_gui_lib.h"
#include "../core/common.h"

namespace Ui {
class GraphicMLPElementPropertyDialog;
}

namespace ann_gui
{

/*!
 * \class
 *
 * \brief The GraphicMLPElementPropertyDialog class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_GUI_LIB_IMPORT_EXPORT MLPObjectPropertyDialog : public QDialog
{

	public:
		explicit MLPObjectPropertyDialog(QWidget *parent = 0);
		~MLPObjectPropertyDialog();

	private:

	Q_OBJECT
	Ui::GraphicMLPElementPropertyDialog *ui;
};
}
#endif // GRAPHICMLPELEMENTPROPERTYDIALOG_H
