#include "graphicimageelement.h"

GraphicImageElement::GraphicImageElement(const QString &imgpath)
{
	initGIE(imgpath);
}

GraphicImageElement::~GraphicImageElement()
{
}

void GraphicImageElement::setImage(const QString &path)
{
	image = QImage(path);
	snapshot = image.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	setRectangle(snapshot.rect());

	emit imageChange(image);
}

void GraphicImageElement::setImage(const QImage &image)
{
	this->image = image;
	snapshot = this->image.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	setRectangle(snapshot.rect());

	emit imageChange(this->image);
}

QImage GraphicImageElement::getImage() const
{
	return image;
}

void GraphicImageElement::setInputElement(GraphicElement *ge)
{
	switch(ge->type()){
		case DotMatrix::DotMatrixType:{
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

QMenu *GraphicImageElement::getContextMenu(QMenu *menu)
{
	menu->addAction("Abrir", this, SLOT(onOpenClick()));
	menu->addAction("Cambiar imagen...", this, SLOT(onChangeImageClick()));
	menu->addAction("Borrar", this, SLOT(onDeleteClick()));
	menu->addAction("Propiedades", this, SLOT(onPropertyClick()));
	return menu;
}

int GraphicImageElement::type() const
{
	return GraphicImageElementType;
}

void GraphicImageElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	GraphicElement::paint(painter, option, widget);

	painter->drawImage(QPoint(0,0), snapshot);
}

void GraphicImageElement::onPropertyClick()
{
	GraphicImageElementPropertyDialog *giepd = new GraphicImageElementPropertyDialog();

	giepd->show();
}

void GraphicImageElement::onOpenClick()
{

	QGraphicsWidget *gw = (QGraphicsWidget*)this->scene()->parent();
	QWidget *qw = (QWidget*)gw->parent();

	QTabWidget *tw = (QTabWidget*)qw->parentWidget()->parentWidget();

	GraphicImageElementDetailedWindow *giedw = new GraphicImageElementDetailedWindow(image);
	tw->addTab(giedw, "Imagen");
//	giedw->show();

//	dynamic_cast<QGraphicsWidget*>(tab)->parentWidget();
	//	giedw->show();
}

void GraphicImageElement::onChangeImageClick()
{
	QString path = QFileDialog::getOpenFileName(0, "Abrir archivo", "", "Mapa de bits (*.bmp);; Formato JPEG (*.jpg);; Portable Network Graphics (*.png);; Formato de Intercambio de Graficos (*.gif)");

	if(path != ""){
		this->setImage(QImage(path));
//		GraphicImageElement *gie = new GraphicImageElement(path);
//		tmpInputElement = gie;
//		gie->setPos(visor->mapToScene(event->pos()));
//		sce->addItem(gie);
	}
}

void GraphicImageElement::initGIE(const QString &path)
{
	setImage(path);
}
