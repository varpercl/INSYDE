#ifndef GRAPHICIMAGEELEMENT_H
#define GRAPHICIMAGEELEMENT_H

#include <QGraphicsWidget>
#include <QFileDialog>

#include "common.h"
#include "../gui/graphiccursorelement.h"
#include "imagepropertydialog.h"
#include "dotmatrix.h"
#include "graphicobject.h"
#include "interfaces.h"

/*!
 * \class
 *
 * \brief The GraphicImageElement class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class Q_DECL_EXPORT Image : public GraphicObject, public Resizable
{
	public:
		enum{ImageObjectType = UserType + 3};

		/*!
		 * \brief Image
		 */
		explicit Image();

		/*!
		 * \brief Image
		 * \param img
		 */
		explicit Image(const QImage &img);

		/*!
		 * \brief Image
		 * \param imgpath
		 */
		explicit Image(const QString &imgpath);

		~Image();

		/*!
		 * \brief setImage
		 * \param path
		 */
		void setImage(const QString &path);

		/*!
		 * \brief setImage
		 * \param image
		 */
		void setImage(const QImage &image);

		/*!
		 * \brief getImage
		 * \return
		 */
		QImage getImage() const;

		/*!
		 * \brief setInputElement
		 * \param ge
		 */
		void setInputElement(GraphicObject *ge);

		/*!
		 * \brief type
		 * \return
		 */
		int type() const;

		/*!
		 * \brief setSelectionRectVisible
		 * \param rv
		 */
		void setSelectionRectVisible(bool rv);

		/*!
		 * \brief getSelectionRectVisible
		 * \return
		 */
		bool getSelectionRectVisible() const;

		/*!
		 * \brief setSelectionRect
		 * \param sr
		 */
		void setSelectionRect(const QRect &sr);

		/*!
		 * \brief getSelectionRect
		 * \return
		 */
		QRect getSelectionRect() const;

		/*!
		 * \brief setSelectionRectColor
		 * \param color
		 */
		void setSelectionRectColor(const QColor &color);

		/*!
		 * \brief getSelectionRectColor
		 * \return
		 */
		QColor getSelectionRectColor() const;

		/*!
		 * \brief getImageSelection
		 * \return
		 */
		QImage getImageSelection() const;

		/*!
		 * \brief setSize
		 * \param size
		 */
		void setSize(const QSize &size);

		/*!
		 * \brief getSize
		 * \return
		 */
		QSize getSize() const;

		/*!
		 * \brief setWidth
		 * \param w
		 */
		void setWidth(int w);

		/*!
		 * \brief getWidth
		 * \return
		 */
		int getWidth() const;

		/*!
		 * \brief setHeight
		 * \param h
		 */
		void setHeight(int h);

		/*!
		 * \brief getHeight
		 * \return
		 */
		int getHeight() const;

		/*!
		 * \brief setEnableCopyImage
		 * \param enable
		 */
		void setEnableCopyImage(bool enable);

		/*!
		 * \brief getEnableCopyImage
		 * \return
		 */
		bool getEnableCopyImage() const;

	protected:

		/*!
		 * \brief mousePressEvent
		 * \param event
		 */
		void mousePressEvent(QGraphicsSceneMouseEvent *event);

		/*!
		 * \brief mouseMoveEvent
		 * \param event
		 */
		void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

		/*!
		 * \brief paint
		 * \param painter
		 * \param option
		 * \param widget
		 */
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	protected slots:

		/*!
		 * \brief copyClick
		 *
		 * \reimp
		 */
		void copyClick();

		/*!
		 * \brief copyImageClick
		 */
		void copyImageClick();

		/*!
		 * \brief cutClick
		 */
		void cutClick();

		/*!
		 * \brief pasteClick
		 */
		void pasteClick();

		/*!
		 * \brief saveClick
		 */
		void saveClick();

		/*!
		 * \brief propertyClick
		 */
		void propertyClick();

		/*!
		 * \brief openClick
		 */
		void openClick();

		/*!
		 * \brief onChangeImageClick
		 */
		void onChangeImageClick();

		/*!
		 * \brief getXML returns XML format wich contains image label translated to base64. Its useful to exchange with
		 * other kind of data consumer
		 *
		 * \return A QString with XML format
		 *
		 * \reimp
		 */
		QString getXML() const;

	signals:

		void imageChange(const QImage &img);

	private:
		Q_OBJECT

		static const QString STR_IMAGE;
		static const QString STR_IMAGE_DATA;

		QClipboard *clip;

		QAction *copyImageAction;

		bool mouseIsOverSelectionRect;
		QColor rectColor;
		bool rectVisible;
		QRect rect;

		QImage image;
		QImage snapshot;

		/*!
		 * \brief initGIE Metodo auxiliar para la inicializacion de los parametros
		 */
		void init(const QImage &img);

};

#endif // GRAPHICIMAGEELEMENT_H
