#include "graphicimageeffectelement.h"

GraphicImageEffectElement::GraphicImageEffectElement() :
	GraphicCursorElement(0, 0, 0, 0)
{
}

GraphicImageEffectElement::GraphicImageEffectElement(GraphicElement *input) :
	GraphicCursorElement(0, 0, 0, 0)
{
	initGIEE(input);
}

void GraphicImageEffectElement::setInputElement(GraphicElement *ge)
{
	switch(ge->type()){
//		case DotMatrix::DotMatrixType:{
//			DotMatrix *dm = dynamic_cast<DotMatrix*>(ge);
//			dm->setOutputElement(this);
//			connect(dm, SIGNAL(statusChanged(QVector<int>)), SLOT(onDotMatrixStatusChanged(QVector<int>)));
//			break;
//		}
		case GraphicImageElement::GraphicImageElementType:{
			GraphicImageElement *gie = dynamic_cast<GraphicImageElement*>(ge);
			gie->setOutputElement(this);
			connect(gie, SIGNAL(imageChange(QImage)), SLOT(onInputImageChanged(QImage)));
			onInputImageChanged(gie->getImage());
			break;
		}
	}
	inputElement = ge;
}

void GraphicImageEffectElement::setOutputElement(GraphicElement *ge)
{
	outputElement = ge;
}

int GraphicImageEffectElement::type() const
{
	return GraphicImageEffectType;
}

QMenu *GraphicImageEffectElement::getContextMenu(QMenu *menu)
{
	menu->addAction("Abrir", this, SLOT(onOpenClick()));
	menu->addAction("Borrar", this, SLOT(onDeleteClick()));
	menu->addAction("Propiedades", this, SLOT(onPropertyClick()));
	return menu;
}

QImage GraphicImageEffectElement::getOutput()
{
	return modImage;
}

QImage GraphicImageEffectElement::getImage()
{
	return modImage;
}

QImage GraphicImageEffectElement::getWindow(int x, int y, int w, int h)
{
	return modImage.copy(x, y, w, h);
}

QImage GraphicImageEffectElement::getWindow(const QRect &rect)
{
	return modImage.copy(rect);
}

void GraphicImageEffectElement::setWindowWidth(int w)
{
	windowWidth = w;
}

int GraphicImageEffectElement::getWindowWidth()
{
	return windowWidth;
}

int GraphicImageEffectElement::getImageWidth()
{
	return modImage.width();
}

int GraphicImageEffectElement::getImageHeight()
{
	return modImage.height();
}

void GraphicImageEffectElement::setSampledImage(const QImage &img)
{
	minImage = img;
}

void GraphicImageEffectElement::setSampledImage(const QString &path)
{
	minImage = QImage(path);
}

QImage GraphicImageEffectElement::getSampledImage()
{
	return minImage;
}

void GraphicImageEffectElement::onPropertyClick()
{
	GraphicImageEffectElementPropertyDialog *gieepd = new GraphicImageEffectElementPropertyDialog(this);
	if(gieepd->exec() == QDialog::Accepted){
		effects = gieepd->getEffectList();
		onInputImageChanged(dynamic_cast<GraphicImageElement*>(getInputElement())->getImage());

		//Se aplican los efectos
//		applyEffects(&modImage);
		//Se actualiza la miniatura
//		updateImage();
	}
}

void GraphicImageEffectElement::onOpenClick()
{
	QGraphicsWidget *gw = (QGraphicsWidget*)this->scene()->parent();
	QWidget *qw = (QWidget*)gw->parent();

	QTabWidget *tw = (QTabWidget*)qw->parentWidget()->parentWidget();

	GraphicImageElementDetailedWindow *giedw = new GraphicImageElementDetailedWindow(modImage);
	tw->addTab(giedw, "Imagen");
}

void GraphicImageEffectElement::onInputImageChanged(QImage img)
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

void GraphicImageEffectElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	GraphicElement::paint(painter, option, widget);

	painter->drawImage(0, 0, minImage);
}


void GraphicImageEffectElement::initGIEE(GraphicElement *input)
{
	setInputElement(input);
}

void GraphicImageEffectElement::updateImage()
{
	minImage = modImage.scaled(50, 50, Qt::KeepAspectRatio/*, Qt::SmoothTransformation*/);
	setRectangle(minImage.rect());
	update();
}

void GraphicImageEffectElement::applyEffects()
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
