#include "image.h"

const QString Image::STR_IMAGE = "image";
const QString Image::STR_IMAGE_DATA = "imagedata";

const QString hola = "hola";

Image::Image() :
	GraphicObject()
{
	init(QImage());
}

Image::Image(const QImage &img) :
	GraphicObject()
{
	init(img);
}

Image::Image(const QString &imgpath) :
	GraphicObject()
{

	init(QImage(imgpath));
}

Image::~Image()
{
}

void Image::setImage(const QString &path)
{
	image = QImage(path);

	if(!image.isNull()){
		snapshot = this->image.scaled(50, 50);
	}else{
		snapshot = QImage();
	}

	setContainerRect(this->image.rect());

	emit imageChange(image);
}

void Image::setImage(const QImage &image)
{
	this->image = image;

	if(!image.isNull()){
		snapshot = this->image.scaled(50, 50);
	}else{
		snapshot = QImage();
	}

	setContainerRect(this->image.rect());

	emit imageChange(this->image);
}

QImage Image::getImage() const
{
	return image;
}

void Image::setInputElement(GraphicObject *ge)
{
	switch(ge->type()){
		case DotMatrix::DotMatrixObject:{
			DotMatrix *dm = dynamic_cast<DotMatrix*>(ge);
			dm->setOutputElement(this);
			connect(dm, SIGNAL(statusChanged(QVector<int>)), SLOT(onDotMatrixStatusChanged(QVector<int>)));
			break;
		}
		case GraphicMLPElement::GraphicMLPElementType:{
			GraphicMLPElement *mlpe = dynamic_cast<GraphicMLPElement*>(ge);
			mlpe->setOutputElement(this);
			connect(mlpe, SIGNAL(outputChanged(QVector<double>)), SLOT(onMLPOutputChanged(QVector<double>)));
			break;
		}
	}
	inputElement = ge;
}

int Image::type() const
{
	return ImageObjectType;
}

void Image::setSelectionRectVisible(bool rv)
{
	rectVisible = rv;
}

bool Image::getSelectionRectVisible() const
{
	return rectVisible;
}

void Image::setSelectionRect(const QRect &sr)
{
	rect = sr;
	update();
}

QRect Image::getSelectionRect() const
{
	return rect;
}

void Image::setSelectionRectColor(const QColor &color)
{
	rectColor = color;
}

QColor Image::getSelectionRectColor() const
{
	return rectColor;
}

QImage Image::getImageSelection() const
{
	return image.copy(rect);
}

void Image::setSize(const QSize &size)
{
	image = image.scaled(size);
}

QSize Image::getSize() const
{
	return image.size();
}

void Image::setWidth(int w)
{
	image = image.scaled(w, image.height());
}

int Image::getWidth() const
{
	return image.width();
}

void Image::setHeight(int h)
{
	image = image.scaled(image.width(), h);
}

int Image::getHeight() const
{
	return image.height();
}

void Image::setEnableCopyImage(bool enable)
{
	copyImageAction->setVisible(enable);
}

bool Image::getEnableCopyImage() const
{
	return copyImageAction->isVisible();
}

void Image::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	GraphicObject::mousePressEvent(event);
	mouseMoveEvent(event);
}

void Image::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	GraphicObject::mouseMoveEvent(event);

	if(event->buttons() & Qt::LeftButton){
		int
				imageW = image.width(),
				imageH = image.height();

		double
				mouseX = event->pos().x(),
				mouseY = event->pos().y(),
				rectW = rect.width(),
				rectH = rect.height(),
				midRectW = rectW / 2,
				midRectH = rectH / 2;

		//En primera instancia se verifica que el recuadro se encuentre en la region interna de la imagen
		if(mouseX <= imageW - midRectW &&
		   mouseX >= midRectW &&
		   mouseY <= imageH - midRectH &&
		   mouseY >= midRectH){

			rect.moveTopLeft(QPoint(mouseX - midRectW, mouseY - midRectH));

			//Se verifica si el puntero se encuentra en la esquina superior izquierda
		}else if(mouseX < midRectW && mouseY < midRectH){

			rect.moveTopLeft(QPoint(0, 0));

			//Se verifica si el puntero se encuentra en la esquina superior derecha
		}else if(mouseX > imageW - midRectW && mouseY < midRectH){

			rect.moveTopRight(QPoint(imageW, 0));

			//Se verifica si el puntero se encuentra en la esquina inferior izquierda
		}else if(mouseX < midRectW && mouseY > imageH - midRectH){

			rect.moveBottomLeft(QPoint(0, imageH));

			//Se verifica si el puntero se encuentra en la esquina inferior derecha
		}else if(mouseX > imageW - midRectW && mouseY > imageH - midRectH){

			rect.moveBottomRight(QPoint(imageW, imageH));

			//Se verifica si el puntero se encuentra en la banda derecha
		}else if(mouseX > imageW - midRectW){

			rect.moveTopLeft(QPoint(imageW - rectW, mouseY - midRectH));

			//Se verifica si el puntero se encuentra en la banda izquierda
		}else if(mouseX < midRectW){

			rect.moveTopLeft(QPoint(0, mouseY - midRectH));

			//Se verifica si el puntero se encuentra en la banda inferior
		}else if(mouseY > imageH - midRectH){

			rect.moveTopLeft(QPoint(mouseX - midRectW, imageH - rectW));

			//Se verifica si el puntero se encuentra en la banda superior
		}else if(mouseY < midRectH){

			rect.moveTopLeft(QPoint(mouseX - midRectW, 0));

		}
	}

	if(rect.contains(event->pos().toPoint())){
		mouseIsOverSelectionRect = true;
	}else{
		mouseIsOverSelectionRect = false;
	}

	update();
}

void Image::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	GraphicObject::paint(painter, option, widget);

	painter->save();

	painter->drawImage(QPoint(0,0), image);
	if(mouseIsOverSelectionRect){
		painter->setOpacity(0.2);
	}else{
		painter->setOpacity(0.5);
	}
	painter->fillRect(rect, Qt::black);
	painter->drawRect(rect);

	painter->restore();
}

void Image::copyClick()
{
	clip = QApplication::clipboard();

	//NOTE: importante no llamar al destructor de data
	QMimeData *data = new QMimeData();
	data->setText(getXML());

	clip->setMimeData(data);

}


void Image::copyImageClick()
{
	//NOTE: This method could be totaly replaced by copyClick
	clip = QApplication::clipboard();

	clip->setImage(image);
}

void Image::cutClick()
{
	//TODO: implementar
}

void Image::pasteClick()
{
	//TODO: implementar
}

void Image::saveClick()
{
	//TODO: Image can be saved but you must write complete name (including extension), if not, it won't save.
	QString
			selectedFilter = "Portable Network Graphics (*.png)",
			path = QFileDialog::getSaveFileName(0,
												"Guardar imagen",
												"",
												"Imagen de mapa de bits (*.bmp) ;; Portable Network Graphics (*.png) ;; Imagen JPEG (*.jpg) ;; Imagen de intercambio grafico (*.gif)",
												&selectedFilter);

	QImage img = getImage();

	if(path != ""){
		img.save(path);
	}
}

void Image::propertyClick()
{
	ImagePropertyDialog *giepd = new ImagePropertyDialog();

	giepd->exec();
}

void Image::openClick()
{
	//TODO: implementar
//	QGraphicsWidget *gw = (QGraphicsWidget*)this->scene()->parent();
//	QWidget *qw = (QWidget*)gw->parent();

//	QTabWidget *tw = (QTabWidget*)qw->parentWidget()->parentWidget();

//	ImageDetailedWindow *giedw = new ImageDetailedWindow(image);
//	tw->addTab(giedw, "Imagen");
}

void Image::onChangeImageClick()
{
	QString path = QFileDialog::getOpenFileName(0,
												"Abrir archivo",
												"",
												"Mapa de bits (*.bmp);; Formato JPEG (*.jpg);; Portable Network Graphics (*.png);; Formato de Intercambio de Graficos (*.gif)");

	if(path != ""){
		this->setImage(QImage(path));
	}
}

QString Image::getXML() const
{
	QString output;
	QXmlStreamWriter xmlWriter(&output);

	QByteArray bytes;
	QBuffer buffer(&bytes);
	buffer.open(QIODevice::WriteOnly);
	image.save(&buffer, "PNG");

	xmlWriter.setAutoFormatting(true);
	xmlWriter.setAutoFormattingIndent(3);

	xmlWriter.writeStartElement(STR_IMAGE);

	//Escribe los datos de la imagen en base 64
	xmlWriter.writeEmptyElement(STR_IMAGE_DATA);
	xmlWriter.writeAttribute("base64", bytes.toBase64().data());

	xmlWriter.writeEndElement();

	return output;
}

void Image::init(const QImage &img)
{
	copyImageAction = new QAction(QIcon(), "Copiar imagen", this);
	contextMenu.insertAction(getCutAction(), copyImageAction);

	setImage(img);
	setSelectionRect(QRect());
	setSelectionRectColor(qRgb(0, 0, 0));
	setSelectionRectVisible(false);

	connect(copyImageAction, SIGNAL(triggered()), SLOT(copyImageClick()));
}
