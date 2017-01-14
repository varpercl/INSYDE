#ifndef DOTMATRIXELEMENTDETAILEDWINDOW_H
#define DOTMATRIXELEMENTDETAILEDWINDOW_H

#include <QtGui>
#include <QtWidgets>

#include "share_core_lib.h"
#include "detailedwindow.h"
#include "dotmatrix.h"
#include "undo.h"

namespace core{

class DotMatrix;

/*!
 * \class
 *
 * \brief The DotMatrixElementDetailedWindow class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT DotMatrixDetailedWindow : public DetailedWindow, public IResizableF
{
	public:

		/*!
		 * \brief DotMatrixDetailedWindow
		 * \param data
		 * \param parent
		 */
		explicit DotMatrixDetailedWindow(const vector<double> &data = vector<double>(1), QWidget *parent = 0);

		/*!
		 * \brief DotMatrixDetailedWindow
		 * \param dm
		 * \param parent
		 */
		explicit DotMatrixDetailedWindow(DotMatrix *dm, QWidget *parent =0);

		~DotMatrixDetailedWindow();

		/*!
		 * \brief setDotMatrixObject
		 * \param dm
		 */
		void setDotMatrixObject(DotMatrix *dm);

		/*!
		 * \brief getDotMatrixObject
		 * \return
		 */
		DotMatrix *getDotMatrixObject() const;

		/*!
		 * \brief setSize
		 * \param size
		 */
		void setSize(const QSizeF &size) override;

		/*!
		 * \brief getSize
		 * \return
		 */
		QSizeF getSize() const override;

		/*!
		 * \brief setWidth
		 * \param w
		 */
		void setWidth(double w) override;

		/*!
		 * \brief getWidth
		 * \return
		 */
		double getWidth() const override;

		/*!
		 * \brief setHeight
		 * \param h
		 */
		void setHeight(double h) override;

		/*!
		 * \brief getHeight
		 * \return
		 */
		double getHeight() const override;

		/*!
		 * \brief setEnableEdit
		 * \param edit
		 */
		void setEnableEdit(bool edit);

		/*!
		 * \brief getEnableEdit
		 * \return
		 */
		bool getEnableEdit() const;

	protected slots:

		/*!
		 * \brief save
		 */
		void save();

	private:
		Q_OBJECT

		DotMatrix *dm;

		/*!
		 * \brief init
		 * \param data
		 */
		void init(const vector<double> &data);

		/*!
		 * \brief init
		 * \param dm
		 */
		void init(DotMatrix *dm);

		void setupUI();

};
}
#endif // DOTMATRIXELEMENTDETAILEDWINDOW_H
