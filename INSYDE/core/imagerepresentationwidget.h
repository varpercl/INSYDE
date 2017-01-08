#ifndef IMAGEREPRESENTATIONWIDGET_H
#define IMAGEREPRESENTATIONWIDGET_H

#include <QtWidgets>

#include "share_core_lib.h"
#include "common.h"
#include "imagedetailedwindow.h"
#include "labeledcombobox.h"
#include "datarepresentationwidget.h"
#include "integersizewidget.h"
#include "interfaces.h"

namespace Ui {
	class ImageRepresentationWidget;
}

class Image;
class ImageDetailedWindow;

namespace core{

/*!
 * \class
 *
 * \brief The ImageRepresentationWidget class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT ImageRepresentationWidget : public DataRepresentationWidget, public Resizable
{

	public:

		/*!
		 * \brief ImageRepresentationWidget
		 * \param data
		 * \param parent
		 */
		explicit ImageRepresentationWidget(const vector<double> &data, QWidget *parent = 0);

		~ImageRepresentationWidget();

		void setInputs(const vector<double> &datainput);

		/*!
		 * \brief setWidth
		 * \param w
		 */
		void setWidth(int w) override;

		/*!
		 * \brief getWidth
		 * \return
		 */
		int getWidth() const override;

		/*!
		 * \brief setHeight
		 * \param h
		 */
		void setHeight(int h) override;

		/*!
		 * \brief getHeight
		 * \return
		 */
		int getHeight() const override;

		/*!
		 * \brief setSize
		 * \param size
		 */
		void setSize(const QSize &size) override;

		/*!
		 * \brief getSize
		 * \return
		 */
		QSize getSize() const override;

		/*!
		 * \brief getImage
		 * \return
		 */
		QImage getImage() const;

		/*!
		 * \brief getImageFormat
		 * \return
		 */
		QImage::Format getImageFormat() const;

		/*!
		 * \brief setImageFormat
		 * \param value
		 */
		void setImageFormat(const QImage::Format &value);

		/*!
		 * \brief setImageObject
		 * \param img
		 */
		void setImageObject(Image *img);

		/*!
		 * \brief getImageObject
		 * \return
		 */
		Image *getImageObject() const;

	signals:

		/*!
		 * \brief imageFormatChanged
		 * \param format
		 */
		void imageFormatChanged(const QImage::Format &format);

	private slots:

		/*!
		 * \brief onSizeValueChanged
		 * \param size
		 */
		void onSizeValueChanged(const QSize &size);

		/*!
		 * \brief on_cbImageFormat_currentIndexChanged
		 * \param index
		 */
		void on_cbImageFormat_currentIndexChanged(int index);

		/*!
		 * \brief TrainingSetDialog::onIgnoreAlphaChannelToogled
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

		void init();

		/*!
		 * \brief imageFromData
		 * \param size
		 * \param data
		 * \return
		 */
		QImage imageFromData(const QSize &size, const vector<double> &data) const;

		/*!
		 * \brief imageFromData
		 * \param w
		 * \param h
		 * \param data
		 * \return
		 */
		QImage imageFromData(int w, int h, const vector<double> &data) const;
};
}
#endif // IMAGEREPRESENTATIONWIDGET_H
