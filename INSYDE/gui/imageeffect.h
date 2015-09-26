#ifndef GRAPHICIMAGEEFFECTELEMENT_H
#define GRAPHICIMAGEEFFECTELEMENT_H

#include "../core/common.h"
#include "graphiccursorelement.h"
#include "../core/image.h"
#include "imageefectpropertydialog.h"
#include "../core/graphicobject.h"
#include "effect.h"
#include "blackwhiteeffect.h"

/*!
 * \brief The GraphicImageEffectElement class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT ImageEffect : public Cursor
{
	public:
		enum{GraphicImageEffectType = UserType + 4};

		explicit ImageEffect();
		explicit ImageEffect(GraphicObject *input);

		void setInputElement(GraphicObject *ge);

		void setOutputElement(GraphicObject *ge);

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
		void openClick();
		void onInputImageChanged(QImage img);

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

#endif // GRAPHICIMAGEEFFECTELEMENT_H
