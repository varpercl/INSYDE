#ifndef GRAPHICIMAGEELEMENTPROPERTYDIALOG_H
#define GRAPHICIMAGEELEMENTPROPERTYDIALOG_H

#include <QtCore>
#include <QtWidgets>

#include "share_core_lib.h"
#include "common.h"
#include "graphicobjectpropertydialog.h"
#include "image.h"
#include "fileeditline.h"
#include "labeledcombobox.h"


namespace core{

class Image;

/*!
 * \brief The ImagePropertyDialog class represents a property dialog of Image objects.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT ImagePropertyDialog : public GraphicObjectPropertyDialog
{

	public:

		/*!
		 * \brief Builds an empty dialog which has no referenced Image object.
		 * Basicly it shows a dialog with everything disabled.
		 *
		 * \param[in] parent The parent of this dialog.
		 */
		explicit ImagePropertyDialog(QWidget *parent = 0);

		/*!
		 * \brief Builds a dialog with a determined Image \p img object.
		 * \param[in] img The Image object to take in account by this dialog.
		 * \param[in] parent The parent of this dialog.
		 */
		explicit ImagePropertyDialog(Image *img, QWidget *parent = 0);

		~ImagePropertyDialog();

	private slots:

		void accept() override;
		void onApplyClicked() override;

		/*!
		 * \brief A response when the file path has changed. This
		 * will performs some validations to accept the referenced image file.
		 *
		 * \param path The path of the image.
		 */
		void onFilePathChanged(const QString &path);

	private:

		Q_OBJECT

		Image *img;

		QImage *image;

		FileEditLine *felPath;

		LabeledComboBox *lcbImageFormats;

		QVBoxLayout *mainLayout;

		/*!
		 * \brief Initializes a dialog with a referenced Image \p img object.
		 * \param[in] img The Image object.
		 */
		void init(Image *img);

		/*!
		 * \brief Enables or disables all the controls.
		 * Useful when loads an empty dialog.
		 *
		 * \param b True will enable all controls.
		 * \param tempImage The image to update the related controls.
		 */
		void enableControls(bool b, const QImage &tempImage);
};
}
#endif // GRAPHICIMAGEELEMENTPROPERTYDIALOG_H
