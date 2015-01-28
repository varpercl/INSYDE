#ifndef GRAPHICIMAGEELEMENT_H
#define GRAPHICIMAGEELEMENT_H

#include <QGraphicsWidget>
#include <QFileDialog>

#include "INSYDEUI_global.h"
#include "graphiccursorelement.h"
#include "graphicimageelementdetailedwindow.h"
#include "graphicimageelementpropertydialog.h"
#include "dotmatrix.h"
#include "graphicelement.h"

class INSYDEUISHARED_EXPORT GraphicImageElement : public GraphicElement
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
		void setImage(const QImage &image);

		/**
		 * @brief getImage
		 * @return
		 */
		QImage getImage() const;

		void setInputElement(GraphicElement *ge);

		QMenu *getContextMenu(QMenu *menu);

		//Heredada
		int type() const;

	protected:

		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	protected slots:

		void onPropertyClick();

		void onOpenClick();

		void onChangeImageClick();

	signals:

		void imageChange(const QImage &img);

	private:
		Q_OBJECT

		QImage image;
		QImage snapshot;

		/**
		 * @brief initGIE Metodo auxiliar para la inicializacion de los parametros
		 */
		void initGIE(const QString &path);
};

#endif // GRAPHICIMAGEELEMENT_H
