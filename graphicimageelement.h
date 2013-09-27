#ifndef GRAPHICIMAGEELEMENT_H
#define GRAPHICIMAGEELEMENT_H

#include <graphiccursorelement.h>
#include <graphicimageelementdetailedwindow.h>
#include <graphicimageelementpropertydialog.h>
#include <dotmatrix.h>
#include <graphicelement.h>

class GraphicImageElement : public GraphicElement
{
	public:
		enum{GraphicImageElementType = UserType + 3};

		explicit GraphicImageElement(const QString &imgpath);

		~GraphicImageElement();

		/**
		 * @brief setImage
		 * @param path
		 */
		void setImage(const QString &path);

		/**
		 * @brief setImage
		 * @param image
		 */
		void setImage(QImage *image);

		/**
		 * @brief getImage
		 * @return
		 */
		QImage *getImage();

		void setInputElement(GraphicElement *ge);

		QMenu *getContextMenu(QMenu *menu);

		//Heredada
		int type() const;

	protected:

		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	protected slots:

		void onPropertyClick();

		void onOpenClick();

	signals:

		void imageChange(QImage img);

	private:
		Q_OBJECT

		QImage *image;
		QImage snapshot;

		/**
		 * @brief initGIE Metodo auxiliar para la inicializacion de los parametros
		 */
		void initGIE(const QString &path);
};

#endif // GRAPHICIMAGEELEMENT_H
