#ifndef DOTMATRIXELEMENTDETAILEDWINDOW_H
#define DOTMATRIXELEMENTDETAILEDWINDOW_H

#include <QtGui>

#include "detailedwindow.h"
#include "dotmatrix.h"
#include "interfaces.h"

class DotMatrix;

/*!
 * \class
 *
 * \brief The DotMatrixElementDetailedWindow class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class DotMatrixDetailedWindow : public DetailedWindow, public Resizable
{
	public:

		/*!
		 * \brief DotMatrixDetailedWindow
		 * \param data
		 * \param parent
		 */
		DotMatrixDetailedWindow(const vector<double> &data = vector<double>(1), QWidget *parent = 0);

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
		void setSize(const QSize &size);

		/*!
		 * \brief getSize
		 * \return
		 */
		QSize getSize() const;

		/*!
		 * \brief setWidth
		 * \param w
		 */
		void setWidth(int w);

		/*!
		 * \brief getWidth
		 * \return
		 */
		int getWidth() const;

		/*!
		 * \brief setHeight
		 * \param h
		 */
		void setHeight(int h);

		/*!
		 * \brief getHeight
		 * \return
		 */
		int getHeight() const;

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

};

#endif // DOTMATRIXELEMENTDETAILEDWINDOW_H
