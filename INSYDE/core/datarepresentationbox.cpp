#include "datarepresentationbox.h"

core::DataRepresentationBox::DataRepresentationBox(QWidget *parent) :
	QGroupBox(parent)
{
	init(vector<double>(1, 0), new DataRepresentation);
}

core::DataRepresentationBox::DataRepresentationBox(const vector<double> &inputdata, DataRepresentation *dr, QWidget *parent) :
	QGroupBox(parent)
{
	init(inputdata, dr);
}//GraphicRepresentation

core::DataRepresentationBox::~DataRepresentationBox()
{
	delete rrw;
	delete irw;
	delete dmrw;
}

void core::DataRepresentationBox::setInputs(const vector<double> &inputs)
{
	this->inputs = inputs;

	switch(dataRepresentation->getType()){
		case DataRepresentation::Raw:
			rrw->setInputs(this->inputs);
			break;
		case DataRepresentation::Image:
			irw->setInputs(this->inputs);
			break;
		case DataRepresentation::DotMatrix:
			dmrw->setInputs(this->inputs);
			break;
		case DataRepresentation::Sound:
			break;
		case DataRepresentation::Text:
			break;
		case DataRepresentation::Chart:
			break;

	}

}

vector<double> core::DataRepresentationBox::getInputs() const
{
	return inputs;
}

core::DataRepresentationWidget *core::DataRepresentationBox::getDataRepresentationWidget() const
{
	return currentRepWidget;
}

core::DataRepresentation *core::DataRepresentationBox::getDataRepresentation() const
{
	return dataRepresentation;
}

void core::DataRepresentationBox::setDataRepresentation(DataRepresentation *value)
{
	if(dataRepresentation != value){
		dataRepresentation = value;
		update();
	}
}

void core::DataRepresentationBox::update()
{
	QGroupBox::update();

	QComboBox *repComboBox = repType->getComboBox();
	switch(dataRepresentation->getType()){
		case DataRepresentation::Raw:
			if(currentRepWidget != rrw){
				irw->setVisible(false);
				dmrw->setVisible(false);
				rrw->setVisible(true);

				repComboBox->setCurrentIndex(0);

				currentRepWidget = rrw;
			}
			break;
		case DataRepresentation::Image:
			if(currentRepWidget != irw){
				rrw->setVisible(false);
				dmrw->setVisible(false);

				repComboBox->setCurrentIndex(1);

				irw->blockSignals(true);
				irw->setImageFormat(dataRepresentation->getImageFormat());
				irw->setSize(dataRepresentation->getSize());
				irw->blockSignals(false);

				irw->setVisible(true);

				currentRepWidget = irw;
			}
			break;
		case DataRepresentation::DotMatrix:
			if(currentRepWidget != dmrw){
				rrw->setVisible(false);
				irw->setVisible(false);
				dmrw->setVisible(true);

				repComboBox->setCurrentIndex(2);

				dmrw->blockSignals(true);
				dmrw->setSize(dataRepresentation->getSize());
				dmrw->blockSignals(false);

				currentRepWidget = dmrw;
			}
			break;
		case DataRepresentation::Sound:
			break;
		case DataRepresentation::Text:
			break;
		case DataRepresentation::Chart:
			break;
		default:
			break;
	}

}

void core::DataRepresentationBox::changeDataRepresentation(int index)
{
	switch(index){
		case DataRepresentation::Raw:
			dataRepresentation->setType(DataRepresentation::Raw);
			break;
		case DataRepresentation::Image:
			dataRepresentation->setType(DataRepresentation::Image);
			break;
		case DataRepresentation::DotMatrix:
			dataRepresentation->setType(DataRepresentation::DotMatrix);
			break;
		case DataRepresentation::Sound:
			dataRepresentation->setType(DataRepresentation::Sound);
			break;
		case DataRepresentation::Text:
			dataRepresentation->setType(DataRepresentation::Text);
			break;
		case DataRepresentation::Chart:
			dataRepresentation->setType(DataRepresentation::Chart);
			break;
		default:
			break;
	}

	update();
}

void core::DataRepresentationBox::onSizeChanged(const QSize &size)
{
	dataRepresentation->setSize(size);
//	dataRepresentation->setWidth(size.width());
//	dataRepresentation->setHeight(size.height());
}

void core::DataRepresentationBox::onImageFormatChanged(const QImage::Format &format)
{
	dataRepresentation->setImageFormat(format);
}

void core::DataRepresentationBox::init(const vector<double> &inputdata, DataRepresentation *dr)
{

	repType = new LabeledComboBox(QString::fromLatin1("Representación"),
											   QStringList()
											   << QString::fromLatin1("Sin representación")
											   << QString::fromLatin1("Imagen")
											   << QString::fromLatin1("Matriz de puntos")
								  //TODO: 25/4/16 init implement this representations before showing them
//											   << QString::fromLatin1("Salida de audio")
//											   << QString::fromLatin1("Texto")
											   /*<< QString::fromLatin1("Gráfica")*/);

	rrw = new RawRepresentationWidget(inputdata);
	rrw->setVisible(false);

	irw = new ImageRepresentationWidget(inputdata);
	Image *img = irw->getImageObject();
	img->getOpenAction()->setVisible(false);
	img->getCopyAction()->setVisible(false);
	img->getCutAction()->setVisible(false);
	img->getPasteAction()->setVisible(false);
	img->getRemoveAction()->setVisible(false);
	irw->setVisible(false);

	dmrw = new DotMatrixRepresentation(inputdata);
	DotMatrix *dm = dmrw->getDotMatrixObject();
	dm->getOpenAction()->setVisible(false);
	dm->getSaveAction()->setVisible(false);
	dm->getCopyAction()->setVisible(false);
	dm->getCutAction()->setVisible(false);
	dm->getPasteAction()->setVisible(false);
	dm->getRemoveAction()->setVisible(false);
	dmrw->setVisible(false);

	mainLayout = new QVBoxLayout();
	mainLayout->setAlignment(Qt::AlignTop);
	mainLayout->addWidget(repType);
	mainLayout->addWidget(currentRepWidget = rrw);
	mainLayout->addWidget(irw);
	mainLayout->addWidget(dmrw);

	setDataRepresentation(dr);
	setInputs(inputdata);

	setLayout(mainLayout);

	connect(repType->getComboBox(), SIGNAL(currentIndexChanged(int)), SLOT(changeDataRepresentation(int)));
	connect(irw, SIGNAL(imageFormatChanged(QImage::Format)), SLOT(onImageFormatChanged(QImage::Format)));
	connect(irw, SIGNAL(sizeChanged(QSize)), SLOT(onSizeChanged(QSize)));
	connect(dmrw, SIGNAL(sizeChanged(QSize)), SLOT(onSizeChanged(QSize)));
}
