#include "datarepresentationbox.h"

core::DataRepresentationBox::DataRepresentationBox(QWidget *parent) :
	QGroupBox(parent)
{
//    Q_INIT_RESOURCE(core_media);
	init(vector<double>(1, 0), new DataRepresentation);
}

core::DataRepresentationBox::DataRepresentationBox(const vector<double> &inputdata, DataRepresentation *dr, QWidget *parent) :
	QGroupBox(parent)
{
//    Q_INIT_RESOURCE(core_media);
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
			rrw->setInputs(inputs);
			break;
		case DataRepresentation::Image:
			irw->setInputs(inputs);
			break;
		case DataRepresentation::DotMatrix:
			dmrw->setInputs(inputs);
			break;
		case DataRepresentation::Sound:
			break;
		case DataRepresentation::Text:
			break;
		case DataRepresentation::Chart:
			crw->setInputs(inputs);
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
			crw->setVisible(false);
			irw->setVisible(false);
			dmrw->setVisible(false);
			rrw->setVisible(true);

			repComboBox->setCurrentIndex(0);

			if(currentRepWidget != rrw){
				currentRepWidget = rrw;
			}
			break;
		case DataRepresentation::Image:
			crw->setVisible(false);
			rrw->setVisible(false);
			dmrw->setVisible(false);

			repComboBox->setCurrentIndex(1);

			irw->blockSignals(true);
			irw->setImageFormat(dataRepresentation->getImageFormat());
			irw->setSize(dataRepresentation->getSize());
			irw->blockSignals(false);

			irw->setVisible(true);

			if(currentRepWidget != irw){
				currentRepWidget = irw;
			}
			break;
		case DataRepresentation::DotMatrix:
		{
			crw->setVisible(false);
			rrw->setVisible(false);
			irw->setVisible(false);

			repComboBox->setCurrentIndex(2);

			dmrw->blockSignals(true);
			QSize size = dataRepresentation->getSize();
//			dmrw->getDotMatrixObject()->setMatrixSize(size);
			dmrw->setSize(size);
//			dmrw->setMatrixSize(size);
			dmrw->blockSignals(false);

			dmrw->setVisible(true);
			if(currentRepWidget != dmrw){
				currentRepWidget = dmrw;
			}
			break;
		}
		case DataRepresentation::Sound:
			break;
		case DataRepresentation::Text:
			break;
		case DataRepresentation::Chart:
			rrw->setVisible(false);
			irw->setVisible(false);
			dmrw->setVisible(false);

			repComboBox->setCurrentIndex(3);

//			crw->blockSignals(true);

			crw->setInputs(this->inputs);

//			crw->blockSignals(false);

			crw->setVisible(true);
			if(currentRepWidget != crw){
				currentRepWidget = crw;
			}
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
								  << tr("Nothing")
								  << tr("Image")
								  << tr("Dot matrix")
								  << tr("Chart")
								  //TODO: 25/4/16 init implement this representations before showing them
//											   << QString::fromLatin1("Salida de audio")
//											   << QString::fromLatin1("Texto")
											   /*<< QString::fromLatin1("Gráfica")*/);

	rrw = new RawRepresentationWidget(inputdata);
	rrw->setVisible(false);

	irw = new ImageRepresentationWidget(inputdata);
	Image *img = irw->getImageObject();
	img->setResizeRectVisible(false);
	img->getOpenAction()->setVisible(false);
	img->getCopyAction()->setVisible(false);
	img->getCutAction()->setVisible(false);
	img->getPasteAction()->setVisible(false);
	img->getRemoveAction()->setVisible(false);
	irw->setVisible(false);

	dmrw = new DotMatrixRepresentation(inputdata);
	DotMatrix *dm = dmrw->getDotMatrixObject();
	dm->setResizeRectVisible(false);
	dm->getOpenAction()->setVisible(false);
	dm->getSaveAction()->setVisible(false);
	dm->getCopyAction()->setVisible(false);
	dm->getCutAction()->setVisible(false);
	dm->getPasteAction()->setVisible(false);
	dm->getRemoveAction()->setVisible(false);
	dmrw->setVisible(false);

	crw = new ChartRepresentation();
	crw->setGeometry(0,0,100,100);
	crw->setVisible(false);

	mainLayout = new QVBoxLayout();
	mainLayout->setAlignment(Qt::AlignTop);
	mainLayout->addWidget(repType);
	mainLayout->addWidget(currentRepWidget = rrw);
	mainLayout->addWidget(irw);
	mainLayout->addWidget(dmrw);
	mainLayout->addWidget(crw);

	setDataRepresentation(dr);
	setInputs(inputdata);

	setLayout(mainLayout);

	connect(repType->getComboBox(), SIGNAL(currentIndexChanged(int)), SLOT(changeDataRepresentation(int)));
	connect(irw, SIGNAL(imageFormatChanged(QImage::Format)), SLOT(onImageFormatChanged(QImage::Format)));
	connect(irw, SIGNAL(sizeChanged(QSize)), SLOT(onSizeChanged(QSize)));
	connect(dmrw, SIGNAL(sizeChanged(QSize)), SLOT(onSizeChanged(QSize)));
}
