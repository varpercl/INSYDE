#include "imageeffect.h"

core::ImageEffect::ImageEffect() :
	Cursor(0, 0, 0, 0)
{
}

core::ImageEffect::ImageEffect(GraphicObject *input) :
	Cursor(0, 0, 0, 0)
{
	init(input);
}

void core::ImageEffect::setInputElement(GraphicObject *ge)
{
	switch(ge->type()){
//		case DotMatrix::DotMatrixType:{
//			DotMatrix *dm = dynamic_cast<DotMatrix*>(ge);
//			dm->setOutputElement(this);
//			connect(dm, SIGNAL(statusChanged(QVector<int>)), SLOT(onDotMatrixStatusChanged(QVector<int>)));
//			break;
//		}
		case GraphicObject::gotImage:{
			Image *gie = dynamic_cast<Image*>(ge);
			gie->setOutputElement(this);
			connect(gie, SIGNAL(imageChange(QImage)), SLOT(onInputImageChanged(QImage)));
			onInputImageChanged(*gie->getImage());
			break;
		}
	}
	inputElement = ge;
}

void core::ImageEffect::setOutputElement(GraphicObject *ge)
{
	outputElement = ge;
}

int core::ImageEffect::type() const
{
	return gotImageEffect;
}

QMenu *core::ImageEffect::getContextMenu(QMenu *menu)
{
	menu->addAction("Abrir", this, SLOT(openOnWindowClick()));
	menu->addAction("Borrar", this, SLOT(removeClick()));
	menu->addAction("Propiedades", this, SLOT(propertyClick()));
	return menu;
}

QImage core::ImageEffect::getOutput()
{
	return modImage;
}

QImage core::ImageEffect::getImage()
{
	return modImage;
}

QImage core::ImageEffect::getWindow(int x, int y, int w, int h)
{
	return modImage.copy(x, y, w, h);
}

QImage core::ImageEffect::getWindow(const QRect &rect)
{
	return modImage.copy(rect);
}

void core::ImageEffect::setWindowWidth(int w)
{
	windowWidth = w;
}

int core::ImageEffect::getWindowWidth()
{
	return windowWidth;
}

int core::ImageEffect::getImageWidth()
{
	return modImage.width();
}

int core::ImageEffect::getImageHeight()
{
	return modImage.height();
}

void core::ImageEffect::setSampledImage(const QImage &img)
{
	minImage = img;
}

void core::ImageEffect::setSampledImage(const QString &path)
{
	minImage = QImage(path);
}

QImage core::ImageEffect::getSampledImage()
{
	return minImage;
}

QString core::ImageEffect::getXML() const
{
	//TODO:
	return "";
}

void core::ImageEffect::copyClick()
{

}

void core::ImageEffect::cutClick()
{

}

void core::ImageEffect::pasteClick()
{

}

void core::ImageEffect::saveClick()
{

}

void core::ImageEffect::propertyClick()
{
	ImageEffectPropertyDialog *gieepd = new ImageEffectPropertyDialog(this);
	if(gieepd->exec() == QDialog::Accepted){
		effects = gieepd->getEffectList();
		onInputImageChanged(*dynamic_cast<Image*>(getInputElement())->getImage());

		//Se aplican los efectos
//		applyEffects(&modImage);
		//Se actualiza la miniatura
//		updateImage();
	}
}

void core::ImageEffect::openOnWindowClick()
{
	QGraphicsWidget *gw = (QGraphicsWidget*)this->scene()->parent();
	QWidget *qw = (QWidget*)gw->parent();

	QTabWidget *tw = (QTabWidget*)qw->parentWidget()->parentWidget();

	ImageDetailedWindow *giedw = new ImageDetailedWindow(&modImage);
	tw->addTab(giedw, "Imagen");
}

void core::ImageEffect::onInputImageChanged(const QImage &img)
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

void core::ImageEffect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	GraphicObject::paint(painter, option, widget);

	painter->drawImage(0, 0, minImage);
}


void core::ImageEffect::init(GraphicObject *input)
{
	setInputElement(input);
}

void core::ImageEffect::updateImage()
{
	minImage = modImage.scaled(50, 50, Qt::KeepAspectRatio/*, Qt::SmoothTransformation*/);
	setContainerRect(minImage.rect());
	update();
}

void core::ImageEffect::applyEffects()
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
