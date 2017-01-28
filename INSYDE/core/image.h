#ifndef IMAGE_H
#define IMAGE_H

#include <QtWidgets>

#include "share_core_lib.h"
#include "common.h"
#include "graphiccursorelement.h"
#include "imagepropertydialog.h"
#include "dotmatrix.h"
#include "graphicobject.h"
#include "undo.h"

namespace core{

/*!
 * \brief The GraphicImageElement class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT Image : public GraphicObject
{
	public:

		/*!
		 * \brief Image
		 */
		explicit Image();

		/*!
		 * \brief Image
		 * \param img
		 */
		explicit Image(QImage *img);

		/*!
		 * \brief Image
		 * \param imgpath
		 */
		explicit Image(const QString &imgpath);

		~Image();

		/*!
		 * \brief setImage Sets a new image. This method doesn't change addres of image is pointing to, it only changes
		 * the content of current image, if you want to change image pointer call setImage(QImage*) instead.
		 *
		 * \param path
		 */
		void setImage(const QString &path);

		/*!
		 * \brief setImage
		 * \param image
		 */
		void setImage(QImage *image);

		/*!
		 * \brief getImage
		 * \return
		 */
		QImage *getImage() const;

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
		 * \brief setImageSize
		 * \param size
		 */
		void setImageSize(const QSize &size);

		/*!
		 * \brief getImageSize
		 * \return
		 */
		QSize getImageSize() const;

		/*!
		 * \brief setImageWidth
		 * \param w
		 */
		void setImageWidth(int w);

		/*!
		 * \brief getImageWidth
		 * \return
		 */
		int getImageWidth() const;

		/*!
		 * \brief setImageHeight
		 * \param h
		 */
		void setImageHeight(int h);

		/*!
		 * \brief getImageHeight
		 * \return
		 */
		int getImageHeight() const;

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

		/*!
		 * \brief setThumbnailSize
		 * \param size
		 */
		void setThumbnailSize(const QSize &size);

		/*!
		 * \brief getThumbnailSize
		 * \return
		 */
		QSize getThumbnailSize() const;

		/*!
		 * \brief setShowOnlyThumbnail Establish if a thumbnail is shown instead full image
		 * \param b
		 */
		void setShowOnlyThumbnail(bool b);

		/*!
		 * \brief getShowOnlyThumbnail
		 * \return
		 */
		bool getShowOnlyThumbnail() const;

		/*!
		 * \brief getPath Returns the current file path associated to this image if it has. To set a file path
		 * use setImage(QString) this method automatically change image and sets the file path
		 *
		 * \return
		 */
		QString getFilePath() const;

		QStringList getFormats() const;

	protected:

		/*!
		 * \brief mouseDoubleClickEvent
		 * \param event
		 */
		void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

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
		 * \brief hoverMoveEvent
		 * \param event
		 */
		void hoverMoveEvent(QGraphicsSceneHoverEvent *event);

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

		QImage
		*image,
		*thumbnail;

		const QString
		STR_IMAGE = "image",
		STR_IMAGE_DATA = "imagedata";

		QString path;

		QSize
		thumbnailSize;

		QClipboard *clip;

		QAction *copyImageAction;

		bool
		showOnlyThumbnail,
		mouseIsOverSelectionRect,
		visibleSelRect;

		QColor rectColor;

		QRect selRect;


		/*!
		 * \brief initGIE Metodo auxiliar para la inicializacion de los parametros
		 */
		void init(QImage *img);

		void init(const QString &path);

		QImage *getThumbnail(QImage *img);

		void updateSelRect(const QPointF &pos);

		void setup();

};
}
#endif // GRAPHICIMAGEELEMENT_H
