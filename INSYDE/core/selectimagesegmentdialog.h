#ifndef SELECTIMAGESEGMENTDIALOG_H
#define SELECTIMAGESEGMENTDIALOG_H

#include <QDialog>

#include "share_core_lib.h"
#include "../core/common.h"
#include "../core/imagedetailedwindow.h"
#include "../core/integersizewidget.h"

namespace Ui {
	class SelectImageSegmentDialog;
}

class ImageDetailedWindow;

namespace core{

/*!
 * \brief The SelectImageSegmentDialog class involves dialog which allows users to select a
 * rectangle of any loaded image. This image segment can be retrieved after.
 *
 * This is useful when need to add a image segment to a training set or another set of inputs.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT SelectImageSegmentDialog : public QDialog
{

	public:

		/*!
		 * \brief Creates a dialog with a loaded image \p img, and a predefined
		 * selection rectangle \p selrect.
		 *
		 * \param img The image to be loaded.
		 * \param selrect The selection rectangle.
		 * \param[in] parent The parent of this dialog.
		 */
		explicit SelectImageSegmentDialog(const QImage &img, const QRect &selrect, QWidget *parent = 0);

		~SelectImageSegmentDialog();

		/*!
		 * \brief Sets the current selection rectangle.
		 * \param rect The new rectangle.
		 */
		void setSelectionRect(const QRect &rect);

		/*!
		 * \brief Gets the current selection rectangle.
		 * \return A QRect which represents the current selection rectangle.
		 */
		QRect getSelectionRect() const;

		/*!
		 * \brief Gets the current image selected segment.
		 * \return The current image segment.
		 */
		QImage getImageSegment() const;

		/*!
		 * \brief Sets a new IntegerSizeWidget. This is useful when users
		 * want to set it's own control.
		 *
		 * \note User is responsible for managin hangling pointers.
		 *
		 * \param isw The new IntegetSizeWidget.
		 */
		void setIntegerSizeWidget(IntegerSizeWidget *isw);

		/*!
		 * \brief Gets the current IntegerSizeWidget pointer.
		 * \return The pointer to the current IntegerSizeWidget.
		 */
		IntegerSizeWidget *getIntegerSizeWidget() const;

	private:
		Q_OBJECT

		IntegerSizeWidget *isw;
		ImageDetailedWindow *giedw;
		Ui::SelectImageSegmentDialog *ui;

		/*!
		 * \brief Initializes all controls.
		 * \param img The image to be loaded.
		 * \param selrect The selection rectangle.
		 */
		void init(const QImage &img, const QRect &selrect);

	private slots:

		/*!
		 * \brief Performs updates when the width has changed.
		 * \param width The new width.
		 */
		void onWidthChanged(int width);

		/*!
		 * \brief Performs updates when the height has changed.
		 * \param height The new height.
		 */
		void onHeightChanged(int height);
};
}
#endif // SELECTIMAGESEGMENTDIALOG_H
