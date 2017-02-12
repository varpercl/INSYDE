#ifndef GRAPHICIMAGEEFFECTELEMENT_H
#define GRAPHICIMAGEEFFECTELEMENT_H

#include "share_core_lib.h"
#include "../core/common.h"
#include "../core/image.h"
#include "../core/imagedetailedwindow.h"
#include "../core/graphicobject.h"
#include "../core/cursor.h"
#include "../core/effect.h"
#include "../core/blackwhiteeffect.h"
#include "imageeffectpropertydialog.h"

namespace core{

/*!
 * \brief The ImageEffect class
 *
 * TODO: evaluate what is happening with this class and why is a derived from cursor.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT ImageEffect : public Cursor
{
	public:

		/*!
		 * \brief ImageEffect
		 */
		explicit ImageEffect();

		/*!
		 * \brief ImageEffect
		 * \param input
		 */
		explicit ImageEffect(GraphicObject *input);

		/*!
		 * \brief setInputElement
		 * \param ge
		 */
		void setInputElement(GraphicObject *ge);

		/*!
		 * \brief setOutputElement
		 * \param ge
		 */
		void setOutputElement(GraphicObject *ge);

		/*!
		 * \brief type
		 * \return
		 */
		int type() const;

		QMenu *getContextMenu(QMenu *menu);

		/*!
		 * \brief getOutput
		 * \return
		 */
		QImage getOutput();

		/*!
		 * \brief getImage
		 * \return
		 *
		 * TODO: diferenciar con getOutput
		 */
		QImage getImage();

		/*!
		 * \brief getWindow
		 * \param x
		 * \param y
		 * \param w
		 * \param h
		 * \return
		 */
		QImage getWindow(int x, int y, int w, int h);

		/*!
		 * \brief getWindow
		 * \param rect
		 * \return
		 */
		QImage getWindow(const QRect &rect);

		/*!
		 * \brief setWindowWidth
		 * \param w
		 */
		void setWindowWidth(int w);

		/*!
		 * \brief getWindowWidth
		 * \return
		 */
		int getWindowWidth();

		/*!
		 * \brief getImageWidth
		 * \return
		 */
		int getImageWidth();

		/*!
		 * \brief getImageHeight
		 * \return
		 */
		int getImageHeight();

		/*!
		 * \brief setSampledImage
		 * \param img
		 */
		void setSampledImage(const QImage &img);

		/*!
		 * \brief setSampledImage
		 * \param path
		 */
		void setSampledImage(const QString &path);

		/*!
		 * \brief getSampledImage
		 * \return
		 */
		QImage getSampledImage();

		/*!
		 * \brief getXML
		 * \return
		 */
		QString getXML() const;

	protected slots:

		void copyClick();
		void cutClick();
		void pasteClick();

		void saveClick();
		void propertyClick();
		void openOnWindowClick();
		void onInputImageChanged(const QImage &img);

	protected:

		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	private:

		Q_OBJECT

		enum Effects{
			BlackWhite,
			GrayScale
		};

		int windowWidth;

		QVector<Effect*> effects;
		QImage modImage, minImage;

		void init(GraphicObject *input);
		void updateImage();
		void applyEffects();

};
}
#endif // GRAPHICIMAGEEFFECTELEMENT_H
