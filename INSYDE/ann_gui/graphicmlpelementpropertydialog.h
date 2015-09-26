#ifndef GRAPHICMLPELEMENTPROPERTYDIALOG_H
#define GRAPHICMLPELEMENTPROPERTYDIALOG_H

#include <QDialog>

#include "../core/common.h"

namespace Ui {
class GraphicMLPElementPropertyDialog;
}

/*!
 * \class
 *
 * \brief The GraphicMLPElementPropertyDialog class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class Q_DECL_EXPORT GraphicMLPElementPropertyDialog : public QDialog
{
		Q_OBJECT

	public:
		explicit GraphicMLPElementPropertyDialog(QWidget *parent = 0);
		~GraphicMLPElementPropertyDialog();

	private:
		Ui::GraphicMLPElementPropertyDialog *ui;
};

#endif // GRAPHICMLPELEMENTPROPERTYDIALOG_H
