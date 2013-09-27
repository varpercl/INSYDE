#ifndef DOTMATRIXELEMENTPROPERTYDIALOG_H
#define DOTMATRIXELEMENTPROPERTYDIALOG_H

#include <QDialog>

namespace Ui {
class DotMatrixElementPropertyDialog;
}

class DotMatrixElementPropertyDialog : public QDialog
{
		Q_OBJECT
		
	public:
		explicit DotMatrixElementPropertyDialog(QWidget *parent = 0);
		~DotMatrixElementPropertyDialog();
		
	private:
		Ui::DotMatrixElementPropertyDialog *ui;
};

#endif // DOTMATRIXELEMENTPROPERTYDIALOG_H
