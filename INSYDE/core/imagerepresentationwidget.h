#ifndef IMAGEREPRESENTATIONWIDGET_H
#define IMAGEREPRESENTATIONWIDGET_H

#include <QtWidgets>

#include "share_core_lib.h"
#include "common.h"
#include "imagedetailedwindow.h"
#include "labeledcombobox.h"
#include "datarepresentationwidget.h"
#include "integersizewidget.h"
#include "undo.h"

namespace Ui {
	class ImageRepresentationWidget;
}

class Image;
class ImageDetailedWindow;

namespace core{

/*!
 * \brief The ImageRepresentationWidget class involves a specialized data representation.
 * This shows all the properties to friendly handle numeric data.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT ImageRepresentationWidget : public DataRepresentationWidget, public IResizable
{

	public:

		/*!
		 * \brief Creates an empty widget with no data associated.
		 * \param[in] parent The parent of this widget.
		 */
		explicit ImageRepresentationWidget(QWidget *parent = 0);

		/*!
		 * \brief Builds a widget with a specific \p data.
		 * \param data The data to represent.
		 * \param[in] parent The parent of this widget.
		 */
		explicit ImageRepresentationWidget(const vector<double> &data, QWidget *parent = 0);

		~ImageRepresentationWidget();

		/*!
		 * \brief Establish the inputs to this representation.
		 * \param datainput The data inputs.
		 */
		void setInputs(const vector<double> &datainput);

		/*!
		 * \brief Establish the width of the shown image.
		 * \param w The width to set.
		 */
		void setWidth(int w) override;

		/*!
		 * \brief Gets the current width of the shown image.
		 * \return An integer value which is the width of the shown image.
		 */
		int getWidth() const override;

		/*!
		 * \brief Establish the height of the shown image.
		 * \param h The height value.
		 */
		void setHeight(int h) override;

		/*!
		 * \brief Returns the height of the current image.
		 * \return An integer which is the height.
		 */
		int getHeight() const override;

		/*!
		 * \brief Sets the size of the shown image.
		 * \param size The new size to be set.
		 */
		void setSize(const QSize &size) override;

		/*!
		 * \brief Returns the size of the shown image.
		 * \return A QSize object which is the size of the image.
		 */
		QSize getSize() const override;

		/*!
		 * \brief Gets the resulting image from the data input.
		 * \return A QImage resulting from the data.
		 */
		QImage getImage() const;

		/*!
		 * \brief Gets the format of the resulting image.
		 * \return The format of the image.
		 */
		QImage::Format getImageFormat() const;

		/*!
		 * \brief Sets the format of the resulting image.
		 * \param value
		 */
		void setImageFormat(const QImage::Format &value);

		/*!
		 * \brief setImageObject
		 *
		 * TODO: evaluate if can set a new Image object.
		 * \param img
		 */
//		void setImageObject(Image *img);

		/*!
		 * \brief Returns a pointer to the Image object.
		 * \return A Image object pointer.
		 */
		Image *getImageObject() const;

	signals:

		/*!
		 * \brief This signal is thrown when the format of the image has changed.
		 * \param format The new format.
		 */
		void imageFormatChanged(const QImage::Format &format);

	private slots:

		/*!
		 * \brief Adjust the image when some size value has changed.
		 * \param size The new size.
		 */
		void onSizeValueChanged(const QSize &size);

		/*!
		 * \brief Performs updates on the resulting image based on the current selected format.
		 * \param index The index of the format combo box.
		 */
		void on_cbImageFormat_currentIndexChanged(int index);

		/*!
		 * \brief Updates the resulting image when user doesn't want to take in
		 * account the alpha channel.
		 *
		 * FIXME: se debe corregir este metodo para que inhiba el canal alfa sin que
		 * se pierdan los datos y luego se puedan volver a recuperar
		 */
		void onIgnoreAlphaChannelToogled(bool ac);

	private:
		Q_OBJECT

		QGroupBox *gbDimentions;

		QVBoxLayout *gbVLayout;

		QHBoxLayout *frmLayout;

		QLabel *label_6;
		LabeledComboBox *lcbImageFormat;
		QCheckBox *cbxIgnoreAlpha;
		QSpacerItem *horizontalSpacer;

		//		Format_Invalid,
		//        Format_Mono,
		//        Format_MonoLSB,
		//        Format_Indexed8,
		//        Format_RGB32,
		//        Format_ARGB32,
		//        Format_ARGB32_Premultiplied,
		//        Format_RGB16,
		//        Format_ARGB8565_Premultiplied,
		//        Format_RGB666,
		//        Format_ARGB6666_Premultiplied,
		//        Format_RGB555,
		//        Format_ARGB8555_Premultiplied,
		//        Format_RGB888,
		//        Format_RGB444,
		//        Format_ARGB4444_Premultiplied,
		//        Format_RGBX8888,
		//        Format_RGBA8888,
		//        Format_RGBA8888_Premultiplied
		QImage::Format imageFormat;

		IntegerSizeWidget *isw;
		ImageDetailedWindow *giedw;

		/*!
		 * \brief Initializes all graphic interface.
		 */
		void init();

		/*!
		 * \brief Converts a set of \p data to a QImage object.
		 * \param size The size of the image.
		 * \note If the total size is larger than \p data size then the rest of the pixels will be set to black.
		 *
		 * \param data The data to be converted.
		 * \return A QImage resulting from the conversion of the \p data.
		 */
		QImage imageFromData(const QSize &size, const vector<double> &data) const;

		/*!
		 * \overload
		 */
		QImage imageFromData(int w, int h, const vector<double> &data) const;
};
}
#endif // IMAGEREPRESENTATIONWIDGET_H
