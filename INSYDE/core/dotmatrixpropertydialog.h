#ifndef DOTMATRIXELEMENTPROPERTYDIALOG_H
#define DOTMATRIXELEMENTPROPERTYDIALOG_H

#include <QtWidgets>

/*!
 * \class
 *
 * \brief The DotMatrixElementPropertyDialog class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT DotMatrixPropertyDialog : public QDialog
{

	public:
		/*!
		 * \brief DotMatrixPropertyDialog
		 * \param parent
		 */
		explicit DotMatrixPropertyDialog(QWidget *parent = 0);

		~DotMatrixPropertyDialog();

	private:
		Q_OBJECT

		/*!
		 * \brief init
		 */
		void init();
};

#endif // DOTMATRIXELEMENTPROPERTYDIALOG_H
