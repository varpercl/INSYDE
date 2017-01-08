#include "image.h"

core::Image::Image() :
	GraphicObject()
{
	init(new QImage());
}

core::Image::Image(QImage *img) :
	GraphicObject()
{
	init(img);
}

core::Image::Image(const QString &imgpath) :
    GraphicObject()
{
	init(imgpath);
}

core::Image::~Image()
{
}

void core::Image::setImage(const QString &path)
{
	*image = QImage(path);
	this->path = path;

	if(image->isNull()){
		setContainerRect(QRectF(0, 0, thumbnailSize.width(), thumbnailSize.height()));
	}else{
		setContainerRect(showOnlyThumbnail ? getThumbnail(this->image)->rect() : this->image->rect());
	}

	if(image->isNull()){
		getOpenAction()->setEnabled(false);
		getSaveAction()->setEnabled(false);
		copyImageAction->setEnabled(false);
	}else{
		getPropertiesAction()->setEnabled(true);
		getOpenAction()->setEnabled(true);
		getSaveAction()->setEnabled(true);
		copyImageAction->setEnabled(true);
	}

	emit imageChange(*image);
}

void core::Image::setImage(QImage *image)
{
	this->image = image;
	path = "";
	if(image->isNull()){
		setContainerRect(QRectF(0, 0, thumbnailSize.width(), thumbnailSize.height()));
	}else{
		setContainerRect(showOnlyThumbnail ? getThumbnail(this->image)->rect() : this->image->rect());
	}

	if(image->isNull()){
		getOpenAction()->setEnabled(false);
		getSaveAction()->setEnabled(false);
		copyImageAction->setEnabled(false);
	}else{
		getPropertiesAction()->setEnabled(true);
		getOpenAction()->setEnabled(true);
		getSaveAction()->setEnabled(true);
		copyImageAction->setEnabled(true);
	}

	emit imageChange(*(this->image));
}

QImage *core::Image::getImage() const
{
	return image;
}

void core::Image::setInputElement(GraphicObject *ge)
{
	switch(ge->type()){
		case GraphicObject::gotDotMatrix:{
			DotMatrix *dm = dynamic_cast<DotMatrix*>(ge);
			dm->setOutputElement(this);
			connect(dm, SIGNAL(statusChanged(QVector<int>)), SLOT(onDotMatrixStatusChanged(QVector<int>)));
			break;
		}
//		case GraphicMLPElement::GraphicMLPElementType:{
//			GraphicMLPElement *mlpe = dynamic_cast<GraphicMLPElement*>(ge);
//			mlpe->setOutputElement(this);
//			connect(mlpe, SIGNAL(outputChanged(QVector<double>)), SLOT(onMLPOutputChanged(QVector<double>)));
//			break;
//		}
	}
	inputElement = ge;
}

int core::Image::type() const
{
	return gotImage;
}

void core::Image::setSelectionRectVisible(bool rv)
{
	visibleSelRect = rv;
}

bool core::Image::getSelectionRectVisible() const
{
	return visibleSelRect;
}

void core::Image::setSelectionRect(const QRect &sr)
{
	selRect = sr;
	update();
}

QRect core::Image::getSelectionRect() const
{
	return selRect;
}

void core::Image::setSelectionRectColor(const QColor &color)
{
	rectColor = color;
}

QColor core::Image::getSelectionRectColor() const
{
	return rectColor;
}

QImage core::Image::getImageSelection() const
{
	return image->copy(selRect);
}

void core::Image::setImageSize(const QSize &size)
{
	*image = image->scaled(size);
}

QSize core::Image::getImageSize() const
{
	return image->size();
}

void core::Image::setImageWidth(int w)
{
	*image = image->scaledToWidth(w, Qt::SmoothTransformation);
}

int core::Image::getImageWidth() const
{
	return image->width();
}

void core::Image::setImageHeight(int h)
{
	*image = image->scaledToHeight(h, Qt::SmoothTransformation);
}

int core::Image::getImageHeight() const
{
	return image->height();
}

void core::Image::setEnableCopyImage(bool enable)
{
	copyImageAction->setVisible(enable);
}

bool core::Image::getEnableCopyImage() const
{
	return copyImageAction->isVisible();
}

void core::Image::setThumbnailSize(const QSize &size)
{
	thumbnailSize = size;
}

QSize core::Image::getThumbnailSize() const
{
	return thumbnailSize;
}

void core::Image::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	GraphicObject::mousePressEvent(event);

	if(visibleSelRect){
		updateSelRect(event->pos());
		update();
	}
}

void core::Image::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	GraphicObject::mouseMoveEvent(event);

	if(visibleSelRect){
		if(flags() & QGraphicsItem::ItemIsMovable) return;

		updateSelRect(event->pos());
		update();
	}
}

void core::Image::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
	GraphicObject::hoverMoveEvent(event);

	if(visibleSelRect){
		if(selRect.contains(event->pos().toPoint())){
			mouseIsOverSelectionRect = true;
		}else{
			mouseIsOverSelectionRect = false;
		}

		update();
	}
}

void core::Image::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	GraphicObject::paint(painter, option, widget);

    painter->save();

	if(image->isNull()){
		const int iconSize = 32;

		QRectF rect = getContainerRect();
		QPointF iconPoint = rect.center();

		painter->fillRect(rect, Qt::white);
		painter->drawPixmap(iconPoint.x() - (iconSize / 2), iconPoint.y() - (iconSize / 2), ICON_NOIMAGE.pixmap(iconSize, iconSize));
	}else{
		painter->drawImage(0, 0, showOnlyThumbnail ? *getThumbnail(image) : *image);

		if(visibleSelRect && selRect.width() > 0 && selRect.height() > 0){
			if(mouseIsOverSelectionRect){
				painter->setOpacity(0.2);
			}else{
				painter->setOpacity(0.5);
			}
			painter->fillRect(selRect, Qt::black);
			//		painter->drawRect(selRect);
		}
	}

    painter->restore();
}

void core::Image::copyClick()
{
	clip = QApplication::clipboard();

	//NOTE: importante no llamar al destructor de data
	QMimeData *data = new QMimeData();
	data->setText(getXML());

	clip->setMimeData(data);

}


void core::Image::copyImageClick()
{
	clip = QApplication::clipboard();

	clip->setImage(*image);
}

void core::Image::cutClick()
{
	//TODO: implementar
}

void core::Image::pasteClick()
{
	//TODO: implementar
}

void core::Image::saveClick()
{
	//TODO: Image can be saved but you must write complete name (including extension), if not, it won't save.
	QString
			selectedFilter = "Portable Network Graphics (*.png)",
			path = QFileDialog::getSaveFileName(0,
												"Guardar imagen",
												"",
												"Imagen de mapa de bits (*.bmp) ;; Portable Network Graphics (*.png) ;; Imagen JPEG (*.jpg) ;; Imagen de intercambio grafico (*.gif)",
												&selectedFilter);

	QImage *img = getImage();

	if(path != ""){
		img->save(path);
	}
}

void core::Image::propertyClick()
{
	ImagePropertyDialog *ipd = new ImagePropertyDialog(this);

	ipd->exec();
}

void core::Image::onChangeImageClick()
{
	QString path = QFileDialog::getOpenFileName(0,
												"Abrir archivo",
												"",
												"Mapa de bits (*.bmp);; Formato JPEG (*.jpg);; Portable Network Graphics (*.png);; Formato de Intercambio de Graficos (*.gif)");

	if(path != ""){
		this->setImage(path);
	}
}

QString core::Image::getXML() const
{
	QString output;
	QXmlStreamWriter xmlWriter(&output);

	QByteArray bytes;
	QBuffer buffer(&bytes);
	buffer.open(QIODevice::WriteOnly);
	image->save(&buffer, "PNG");

	xmlWriter.setAutoFormatting(true);
	xmlWriter.setAutoFormattingIndent(3);

	xmlWriter.writeStartElement(STR_IMAGE);

	//Escribe los datos de la imagen en base 64
	xmlWriter.writeEmptyElement(STR_IMAGE_DATA);
	xmlWriter.writeAttribute("base64", bytes.toBase64().data());

	xmlWriter.writeEndElement();

	return output;
}

void core::Image::setShowOnlyThumbnail(bool b)
{
	showOnlyThumbnail = b;
//	scene()->setSceneRect(showOnlyThumbnail ? getThumbnail(image).rect() : image.rect());
	setContainerRect(showOnlyThumbnail ? getThumbnail(image)->rect() : image->rect());
	update();
}

bool core::Image::getShowOnlyThumbnail() const
{
	return showOnlyThumbnail;
}


QString core::Image::getFilePath() const
{
	return path;
}

QStringList core::Image::getFormats() const
{
	return QStringList() <<
							"Mono" <<
							"MonoLSB" <<
							"Indexed8" <<
							"RGB32" <<
							"ARGB32" <<
							"ARGB32 Premultiplied" <<
							"RGB16" <<
							"ARGB8565 Premultiplied" <<
							"RGB666" <<
							"ARGB6666 Premultiplied" <<
							"RGB555" <<
							"ARGB8555 Premultiplied" <<
							"RGB888" <<
							"RGB444" <<
							"ARGB4444 Premultiplied" <<
							"RGBX8888" <<
							"RGBA8888" <<
							"RGBA8888 Premultiplied" <<
							"BGR30" <<
							"A2BGR30 Premultiplied" <<
							"RGB30" <<
							"A2RGB30 Premultiplied";

}

void core::Image::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
	(void)event;
	if(image->isNull()){
		propertyClick();
	}
}

void core::Image::init(QImage *img)
{
	image = img;

	setup();

	setImage(img);
}

void core::Image::init(const QString &path)
{
	image = new QImage(path);

	setup();

	setImage(path);
}

QImage *core::Image::getThumbnail(QImage *img)
{
	int
			imgWidth = img->width(),
			imgHeight = img->height(),
			maxImgWidth = thumbnailSize.width(),
			maxImgHeight = thumbnailSize.height();

	if(imgWidth > maxImgWidth || imgHeight > maxImgHeight){

		if(imgWidth >= imgHeight){
			*thumbnail = image->scaled(maxImgWidth, imgHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
		}else{
			*thumbnail = image->scaled(imgWidth, maxImgHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
		}

		return thumbnail;
	}else{
		return image;
	}
}

void core::Image::updateSelRect(const QPointF &pos)
{
	QImage *thumb = showOnlyThumbnail ? getThumbnail(image) : image;
	int
			imageW = thumb->width(),
			imageH = thumb->height();

	double
			mouseX = pos.x(),
			mouseY = pos.y(),
			rectW = selRect.width(),
			rectH = selRect.height(),
			midRectW = rectW / 2,
			midRectH = rectH / 2;

	//En primera instancia se verifica que el recuadro se encuentre en la region interna de la imagen
	if(mouseX <= imageW - midRectW &&
	   mouseX >= midRectW &&
	   mouseY <= imageH - midRectH &&
	   mouseY >= midRectH){

		selRect.moveCenter(pos.toPoint());
//		selRect.moveTopLeft(QPoint(mouseX - midRectW, mouseY - midRectH));

		//Se verifica si el puntero se encuentra en la esquina superior izquierda
	}else if(mouseX < midRectW && mouseY < midRectH){

		selRect.moveTopLeft(QPoint(0, 0));

		//Se verifica si el puntero se encuentra en la esquina superior derecha
	}else if(mouseX > imageW - midRectW && mouseY < midRectH){

		selRect.moveTopRight(QPoint(imageW-2, 0));

		//Se verifica si el puntero se encuentra en la esquina inferior izquierda
	}else if(mouseX < midRectW && mouseY > imageH - midRectH){

		selRect.moveBottomLeft(QPoint(1, imageH-2));

		//Se verifica si el puntero se encuentra en la esquina inferior derecha
	}else if(mouseX > imageW - midRectW && mouseY > imageH - midRectH){

		selRect.moveBottomRight(QPoint(imageW-2, imageH-2));

		//Se verifica si el puntero se encuentra en la banda derecha
	}else if(mouseX > imageW - midRectW){

		selRect.moveTopLeft(QPoint(imageW - rectW-1, mouseY - midRectH-1));

		//Se verifica si el puntero se encuentra en la banda izquierda
	}else if(mouseX < midRectW){

		selRect.moveTopLeft(QPoint(0, mouseY - midRectH-1));

		//Se verifica si el puntero se encuentra en la banda inferior
	}else if(mouseY > imageH - midRectH){

		selRect.moveTopLeft(QPoint(mouseX - midRectW-1, imageH - rectW-1));

		//Se verifica si el puntero se encuentra en la banda superior
	}else if(mouseY < midRectH){

		selRect.moveTopLeft(QPoint(mouseX - midRectW-1, 0));

	}
}

void core::Image::setup()
{
	thumbnail = new QImage();

	copyImageAction = new QAction(QIcon(), "Copiar imagen", this);
	contextMenu.insertAction(getCutAction(), copyImageAction);

	thumbnailSize = QSize(100, 100);

	showOnlyThumbnail = true;

	setSelectionRect(QRect(0, 0, 15, 15));
	setSelectionRectColor(qRgb(0, 0, 0));
	setSelectionRectVisible(false);

	connect(copyImageAction, SIGNAL(triggered()), SLOT(copyImageClick()));
}
