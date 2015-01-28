#ifndef IMAGEREPRESENTATIONWIDGET_H
#define IMAGEREPRESENTATIONWIDGET_H

#include <QWidget>

#include "../INSYDEUI_global.h"
#include "representationwidget.h"
#include "../graphicimageelementdetailedwindow.h"
#include "../integersizewidget.h"

using namespace CommonFunctions;

namespace Ui {
	class ImageRepresentationWidget;
}

class ImageRepresentationWidget : public RepresentationWidget
{

	public:
		explicit ImageRepresentationWidget(const vector<double> &data, QWidget *parent = 0);
		~ImageRepresentationWidget();

		void setDataInput(const vector<double> &datainput);

		void updateRepresentation();

		void setIgnoreAlphaChannelCheckBox(QCheckBox *cb);
		QCheckBox *getIgnoreAlphaChannelCheckBox() const;

		void setIntegerSizeWidget(IntegerSizeWidget *isw);
		IntegerSizeWidget *getIntegerSizeWidget() const;

		RepresentationType getRepresentationType() const{
			return Image;
		}

	protected slots:
//		void on_sbWidth_valueChanged(int arg1);
//		void on_sbHeight_valueChanged(int arg1);

		void onSizeValueChanged(const QSize &size);
		void on_cbImageFormat_currentIndexChanged(int index);

	private:
		Q_OBJECT

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
		//        Format_RGBA8888_Premultiplied,
		QImage::Format imgFormat;

		IntegerSizeWidget *isw;
		QImage imgRepresentation;
		Ui::ImageRepresentationWidget *ui;

		void initIRW(const vector<double> &data);

		/*!
		 * \brief updateSB actualiza los SpinBox que indican la altura y la anchura
		 * de la representacion que se dara a los datos seleccionados
		 */
//		void updateSB();

		QImage imageFromData(int w, int h, const vector<double> &data);
};

#endif // IMAGEREPRESENTATIONWIDGET_H
