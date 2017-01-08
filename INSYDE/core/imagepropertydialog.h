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
 * \class
 *
 * \brief The GraphicImageElementPropertyDialog class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT ImagePropertyDialog : public GraphicObjectPropertyDialog
{

	public:

		/*!
		 * \brief ImagePropertyDialog
		 * \param img
		 * \param parent
		 */
		explicit ImagePropertyDialog(Image *img, QWidget *parent = 0);

		~ImagePropertyDialog();

	private slots:

		/*!
		 * \brief onAcceptClicked
		 */
		void accept();

		/*!
		 * \brief onApplyClicked
		 */
		void onApplyClicked();

		/*!
		 * \brief onFilePathChanged
		 * \param path
		 */
		void onFilePathChanged(const QString &path);

	private:

		Q_OBJECT

		Image *img;

		QImage *image;

		FileEditLine *felPath;

		LabeledComboBox *lcbImageFormats;

		QVBoxLayout *mainLayout;

		void init(Image *img);

		void enableControls(bool b, const QImage &tempImage);
};
}
#endif // GRAPHICIMAGEELEMENTPROPERTYDIALOG_H
