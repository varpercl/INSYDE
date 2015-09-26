#ifndef GRAPHICIMAGEELEMENTPROPERTYDIALOG_H
#define GRAPHICIMAGEELEMENTPROPERTYDIALOG_H

#include <QDialog>

#include "common.h"

/*!
 * \class
 *
 * \brief The GraphicImageElementPropertyDialog class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT ImagePropertyDialog : public QDialog
{

	public:
		explicit ImagePropertyDialog(QWidget *parent = 0);
		~ImagePropertyDialog();

	private:
		Q_OBJECT
};

#endif // GRAPHICIMAGEELEMENTPROPERTYDIALOG_H
