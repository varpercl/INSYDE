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
 * \brief The DotMatrixElementDetailedWindow class construct a detailed window specially designed to
 * show DotMatrix elements.
 * This detailed window has inside a DotMatrix object.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT DotMatrixDetailedWindow : public DetailedWindow, public IResizableF
{
	public:

		/*!
		 * \brief Builds a detailed window with \p data.
		 *
		 * \param data The data to be set to the DotMatrix element.
		 * \param[in] parent The parent widget.
		 */
		explicit DotMatrixDetailedWindow(const vector<double> &data = vector<double>(1), QWidget *parent = 0);

		/*!
		 * \brief Builds a detailed windows starting from a DotMatrix \p dm.
		 *
		 * \param[in] dm The DotMatrix element.
		 * \param[in] parent The parent of this window.
		 */
		explicit DotMatrixDetailedWindow(DotMatrix *dm, QWidget *parent =0);

		~DotMatrixDetailedWindow();

		/*!
		 * \brief Sets a new DotMatrix object.
		 *
		 * \note User is responsible for freeing hangling pointers.
		 *
		 * \param[in] dm The dot matrix object.
		 */
		void setDotMatrixObject(DotMatrix *dm);

		/*!
		 * \brief Gets the pointer to the current DotMatrix object.
		 * \return A pointer to a DotMatrix object.
		 */
		DotMatrix *getDotMatrixObject() const;

		/*!
		 * \brief Sets the size of the DotMatrix object. This is not the same as
		 * setting the matrix dimensions.
		 *
		 * \param size The new size.
		 */
		void setSize(const QSizeF &size) override;

		/*!
		 * \brief Gets the size of the DotMatrix object.
		 * \return The size of the object.
		 */
		QSizeF getSize() const override;

		/*!
		 * \brief Sets the width of this dot matrix object.
		 * \param w A double value indicating the new width.
		 */
		void setWidth(double w) override;

		/*!
		 * \brief Gets the current width of the DotMatrix object.
		 * \return The current width of this DotMatrix object.
		 */
		double getWidth() const override;

		/*!
		 * \brief Sets the new height of the DotMatrix object.
		 * \param h The new height.
		 */
		void setHeight(double h) override;

		/*!
		 * \brief Gets the current height of the DotMatrix object.
		 * \return A double that holds the current height.
		 */
		double getHeight() const override;

		/*!
		 * \brief Sets wether or not the DotMatrix element will be editable.
		 * \param edit If true the DotMatrix object will be editable.
		 */
		void setEnableEdit(bool edit);

		/*!
		 * \brief Returns the value of the "Editable" property.
		 * \return True if the DotMatrix is editable.
		 */
		bool getEnableEdit() const;

	protected slots:

		/*!
		 * \brief Save the status of the current windows.
		 *
		 */
		void save();

	private:
		Q_OBJECT

		DotMatrix *dm; /**< The DotMatrix object to be shown inside this detailed window */

		/*!
		 * \brief Initializes everything with the respective \p data information.
		 * \param data The data to be displayed.
		 */
		void init(const vector<double> &data);

		/*!
		 * \brief Initializes everything and the gui. But setupUI is specialized in gui.
		 * \param dm
		 */
		void init(DotMatrix *dm);

		/*!
		 * \brief Initializes all gui.
		 */
		void setupUI();

};
}
#endif // DOTMATRIXELEMENTDETAILEDWINDOW_H
