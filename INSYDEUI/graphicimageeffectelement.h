#ifndef GRAPHICIMAGEEFFECTELEMENT_H
#define GRAPHICIMAGEEFFECTELEMENT_H

#include "INSYDEUI_global.h"
#include "graphiccursorelement.h"
#include "graphicimageelement.h"
#include "graphicimageeffectelementpropertydialog.h"
#include "graphicelement.h"
#include "effect.h"
#include "blackwhiteeffect.h"

//class GraphicImageElement;

class INSYDEUISHARED_EXPORT GraphicImageEffectElement : public GraphicCursorElement
{
	public:
		enum{GraphicImageEffectType = UserType + 4};

		explicit GraphicImageEffectElement();
		explicit GraphicImageEffectElement(GraphicElement *input);

		void setInputElement(GraphicElement *ge);

		void setOutputElement(GraphicElement *ge);

		int type() const;

		QMenu *getContextMenu(QMenu *menu);

		QImage getOutput();
		QImage getImage();

		QImage getWindow(int x, int y, int w, int h);
		QImage getWindow(const QRect &rect);

		void setWindowWidth(int w);
		int getWindowWidth();

		int getImageWidth();
		int getImageHeight();

		void setSampledImage(const QImage &img);
		void setSampledImage(const QString &path);

		QImage getSampledImage();

	protected slots:

		void onPropertyClick();
		void onOpenClick();
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

		void initGIEE(GraphicElement *input);
		void updateImage();
		void applyEffects();
};

#endif // GRAPHICIMAGEEFFECTELEMENT_H
