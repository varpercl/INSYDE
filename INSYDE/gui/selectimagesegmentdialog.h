#ifndef SELECTIMAGESEGMENTDIALOG_H
#define SELECTIMAGESEGMENTDIALOG_H

#include <QDialog>

#include "../core/common.h"
#include "../core/imagedetailedwindow.h"
#include "../core/integersizewidget.h"

namespace Ui {
	class SelectImageSegmentDialog;
}

class ImageDetailedWindow;

/*!
 * \brief Esta clase genera un cuadro de dialogo que permite al usuario seleccionar grafica e intuitivamente un
 * segmento de dimension ajustable de una imagen preseleccionada.
 * Este segmento puede ser utilizado en otras clases para su posterior procesamiento como por ejemplo el procesamiento
 * por barrido de una imagen completa en una red neuronal.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT SelectImageSegmentDialog : public QDialog
{

	public:
		explicit SelectImageSegmentDialog(const QImage &img, const QRect &selrect, QWidget *parent = 0);
		~SelectImageSegmentDialog();

		void setSelectionRect(const QRect &rect);
		QRect getSelectionRect() const;

		QImage getImageSegment() const;

		void setIntegerSizeWidget(IntegerSizeWidget *isw);
		IntegerSizeWidget *getIntegerSizeWidget() const;

	private:
		Q_OBJECT

		IntegerSizeWidget *isw;
		ImageDetailedWindow *giedw;
		Ui::SelectImageSegmentDialog *ui;

		void init(const QImage &img, const QRect &selrect);

	private slots:
		void onWidthChanged(int width);
		void onHeightChanged(int height);
};

#endif // SELECTIMAGESEGMENTDIALOG_H
