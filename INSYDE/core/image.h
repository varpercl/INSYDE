#ifndef IMAGE_H
#define IMAGE_H

#include <QtWidgets>

#include "share_core_lib.h"
#include "common.h"
#include "cursor.h"
#include "imagepropertydialog.h"
#include "dotmatrix.h"
#include "graphicobject.h"
#include "undo.h"

namespace core{

/*!
 * \brief The Image class is a speciallized GraphicObject which is capable
 * to load and draw images from a local resource.
 *
 * TODO: Allow remote resources.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT Image : public GraphicObject
{
	public:

		/*!
		 * \brief An empty Image object.
		 */
		explicit Image();

		/*!
		 * \brief Builds an Image object with the associated \p img.
		 * \param img The associated image.
		 */
		explicit Image(QImage *img);

		/*!
		 * \brief Builds a Image object which will load the \p imgpath.
		 *
		 * TODO: must validate if \p imgpath is available.
		 *
		 * \param imgpath The path to be evaluated when load the image.
		 */
		explicit Image(const QString &imgpath);

		~Image();

		/*!
		 * \brief Sets a new image.
		 * \note This method doesn't change addres of image is pointing to, it only changes
		 * the content of current image, if you want to change image pointer call setImage(QImage*) instead.
		 *
		 * \param path
		 */
		void setImage(const QString &path);

		/*!
		 * \brief Sets a new QImage object \p image which will store the image information of any loaded resource.
		 *
		 * \note This method sets a new pointer. User is responsible to manage hangling pointers.
		 *
		 * \param[in] image The new image.
		 */
		void setImage(QImage *image);

		/*!
		 * \brief Returns the pointer to the current QImage object.
		 * \return A pointer to the current QImage.
		 */
		QImage *getImage() const;

		/*!
		 * \see GraphicObject::setInputElement
		 */
		void setInputElement(GraphicObject *ge);

		/*!
		 * \see GraphicObject::type
		 */
		int type() const;

		/*!
		 * \brief Establish if user wants the selection rectangle to be visible.
		 *
		 * \param rv If true the selection rectangle will be visible.
		 */
		void setSelectionRectVisible(bool rv);

		/*!
		 * \brief Returns the status of the visibility of the selection rectangle.
		 * \return A boolean which indicates the current status of the visibility of the selection rectangle.
		 */
		bool getSelectionRectVisible() const;

		/*!
		 * \brief Sets a new customized rectangle.
		 *
		 * FIXME: evaluate if this method is necessary.
		 * \param sr The new selection rectangle.
		 */
		void setSelectionRect(const QRect &sr);

		/*!
		 * \brief
		 *
		 * FIXME: evaluate if this method is necessary.
		 *
		 * \return
		 */
		QRect getSelectionRect() const;

		/*!
		 * \brief Sets the color property of the selection rectangle.
		 * \param color The new color of the selection rectangle.
		 */
		void setSelectionRectColor(const QColor &color);

		/*!
		 * \brief Gets the color of the selection rectangle.
		 * \return The color of the selection rectangle.
		 */
		QColor getSelectionRectColor() const;

		/*!
		 * \brief
		 * TODO: clarify the meaning of this function.
		 * \return
		 */
		QImage getImageSelection() const;

		/*!
		 * \brief Sets a new size to the current image.
		 * \note This will resize this image itself.
		 * \param size The new size of the image.
		 */
		void setImageSize(const QSize &size);

		/*!
		 * \brief Gets the size of the image.
		 * \return The size of the image.
		 */
		QSize getImageSize() const;

		/*!
		 * \brief Sets the width of the image.
		 *
		 * \note This will resize the image itself.
		 *
		 * \param w The new width.
		 */
		void setImageWidth(int w);

		/*!
		 * \brief Returns the width of the current image.
		 * \return The width of the current image in pixels.
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
