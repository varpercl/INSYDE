#ifndef GRAPHICIMAGEEFFECTELEMENTPROPERTYDIALOG_H
#define GRAPHICIMAGEEFFECTELEMENTPROPERTYDIALOG_H

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#else
#include <QtGui>
#endif

#include "share_core_lib.h"
#include "../core/common.h"
#include "../core/effect.h"
#include "../core/blackwhiteeffect.h"
#include "../core/grayscaleeffect.h"
#include "imageeffect.h"
#include "bnsubwidget.h"
#include "gssubwidget.h"

namespace Ui {
class GraphicImageEffectElementPropertyDialog;
}

namespace core{

class ImageEffect;

/*!
 * \brief The ImageEffectPropertyDialog class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT ImageEffectPropertyDialog : public QDialog
{
		Q_OBJECT

	public:

		/*!
		 * \brief ImageEffectPropertyDialog
		 * \param parent
		 */
		explicit ImageEffectPropertyDialog(QWidget *parent = 0);

		/*!
		 * \brief ImageEffectPropertyDialog
		 * \param giee
		 * \param parent
		 */
		explicit ImageEffectPropertyDialog(ImageEffect *giee, QWidget *parent = 0);
		~ImageEffectPropertyDialog();

		QVector<Effect*> getEffectList();

		void setGraphicImageEffectElement(ImageEffect *giee);
		ImageEffect* setGraphicImageEffectElement();

		void setBNEffectChecked(bool chk);
		bool getBNEffectChecked();

		QWidget *getSubWidget();

	private slots:
		void on_lwEffects_currentRowChanged(int currentRow);

	private:
		Ui::GraphicImageEffectElementPropertyDialog *ui;

		GSSubWidget *gssw;
		BNSubWidget *bnsw;
		ImageEffect *giee;

		void initGIEEPD(ImageEffect *giee);

		void updateConfigWidget(int i);
};
}
#endif // GRAPHICIMAGEEFFECTELEMENTPROPERTYDIALOG_H
