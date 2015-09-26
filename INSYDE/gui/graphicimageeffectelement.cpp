#include "imageeffect.h"

ImageEffect::ImageEffect() :
	Cursor(0, 0, 0, 0)
{
}

ImageEffect::ImageEffect(GraphicObject *input) :
	Cursor(0, 0, 0, 0)
{
	init(input);
}

void ImageEffect::setInputElement(GraphicObject *ge)
{
	switch(ge->type()){
//		case DotMatrix::DotMatrixType:{
//			DotMatrix *dm = dynamic_cast<DotMatrix*>(ge);
//			dm->setOutputElement(this);
//			connect(dm, SIGNAL(statusChanged(QVector<int>)), SLOT(onDotMatrixStatusChanged(QVector<int>)));
//			break;
//		}
		case Image::ImageObjectType:{
			Image *gie = dynamic_cast<Image*>(ge);
			gie->setOutputElement(this);
			connect(gie, SIGNAL(imageChange(QImage)), SLOT(onInputImageChanged(QImage)));
			onInputImageChanged(gie->getImage());
			break;
		}
	}
	inputElement = ge;
}

void ImageEffect::setOutputElement(GraphicObject *ge)
{
	outputElement = ge;
}

int ImageEffect::type() const
{
	return GraphicImageEffectType;
}

QMenu *ImageEffect::getContextMenu(QMenu *menu)
{
	menu->addAction("Abrir", this, SLOT(openClick()));
	menu->addAction("Borrar", this, SLOT(removeClick()));
	menu->addAction("Propiedades", this, SLOT(propertyClick()));
	return menu;
}

QImage ImageEffect::getOutput()
{
	return modImage;
}

QImage ImageEffect::getImage()
{
	return modImage;
}

QImage ImageEffect::getWindow(int x, int y, int w, int h)
{
	return modImage.copy(x, y, w, h);
}

QImage ImageEffect::getWindow(const QRect &rect)
{
	return modImage.copy(rect);
}

void ImageEffect::setWindowWidth(int w)
{
	windowWidth = w;
}

int ImageEffect::getWindowWidth()
{
	return windowWidth;
}

int ImageEffect::getImageWidth()
{
	return modImage.width();
}

int ImageEffect::getImageHeight()
{
	return modImage.height();
}

void ImageEffect::setSampledImage(const QImage &img)
{
	minImage = img;
}

void ImageEffect::setSampledImage(const QString &path)
{
	minImage = QImage(path);
}

QImage ImageEffect::getSampledImage()
{
	return minImage;
}

QString ImageEffect::getXML() const
{
	//TODO:
	return "";
}

void ImageEffect::copyClick()
{

}

void ImageEffect::cutClick()
{

}

void ImageEffect::pasteClick()
{

}

void ImageEffect::saveClick()
{

}

void ImageEffect::propertyClick()
{
	ImageEffectPropertyDialog *gieepd = new ImageEffectPropertyDialog(this);
	if(gieepd->exec() == QDialog::Accepted){
		effects = gieepd->getEffectList();
		onInputImageChanged(dynamic_cast<Image*>(getInputElement())->getImage());

		//Se aplican los efectos
//		applyEffects(&modImage);
		//Se actualiza la miniatura
//		updateImage();
	}
}

void ImageEffect::openClick()
{
	QGraphicsWidget *gw = (QGraphicsWidget*)this->scene()->parent();
	QWidget *qw = (QWidget*)gw->parent();

	QTabWidget *tw = (QTabWidget*)qw->parentWidget()->parentWidget();

	ImageDetailedWindow *giedw = new ImageDetailedWindow(modImage);
	tw->addTab(giedw, "Imagen");
}

void ImageEffect::onInputImageChanged(QImage img)
{
	modImage = img;

	int sEffects = effects.size();
	for(int i = 0; i < sEffects; i++){
		effects[i]->setImage(modImage);
	}
	//Se aplican los efectos
	applyEffects();
	//Se actualiza la miniatura
	updateImage();
}

void ImageEffect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	GraphicObject::paint(painter, option, widget);

	painter->drawImage(0, 0, minImage);
}


void ImageEffect::init(GraphicObject *input)
{
	setInputElement(input);
}

void ImageEffect::updateImage()
{
	minImage = modImage.scaled(50, 50, Qt::KeepAspectRatio/*, Qt::SmoothTransformation*/);
	setContainerRect(minImage.rect());
	update();
}

void ImageEffect::applyEffects()
{
//	QImage final = img;
	int sEffects = effects.size();
	for(int i = 0; i < sEffects; i++){
		switch(effects[i]->getType()){
			case BlackWhiteEffect::BNEffectType:
				modImage = dynamic_cast<BlackWhiteEffect*>(effects[i])->getImage();
//				modImage = modImage.convertToFormat(QImage::Format_Mono, Qt::MonoOnly);
				break;
			case GrayScaleEffect::GrayScaleType:

				break;
			case Effect::Nothing:
			default:
				break;
		}
	}
}
