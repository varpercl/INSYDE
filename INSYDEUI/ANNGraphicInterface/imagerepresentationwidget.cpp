#include "imagerepresentationwidget.h"
#include "ui_imagerepresentationwidget.h"

ImageRepresentationWidget::ImageRepresentationWidget(const vector<double> &data, QWidget *parent) :
	RepresentationWidget(data, parent),
	ui(new Ui::ImageRepresentationWidget)
{
	initIRW(data);
}//ImageRepresentationWidget

ImageRepresentationWidget::~ImageRepresentationWidget()
{
	delete ui;
}//~ImageRepresentationWidget

void ImageRepresentationWidget::setDataInput(const vector<double> &datainput)
{
	RepresentationWidget::setDataInput(datainput);
	//	updateSB();
}

void ImageRepresentationWidget::updateRepresentation()
{
	giedw->setImage(imageFromData(isw->getWidth(), isw->getHeight(), getDataInput()));
}//updateRepresentation

void ImageRepresentationWidget::setIgnoreAlphaChannelCheckBox(QCheckBox *cb)
{
	ui->cbxIgnoreAlpha = cb;
}//setIgnoreAlphaChannelCheckBox

QCheckBox *ImageRepresentationWidget::getIgnoreAlphaChannelCheckBox() const
{
	return ui->cbxIgnoreAlpha;
}//getIgnoreAlphaChannelCheckBox

void ImageRepresentationWidget::setIntegerSizeWidget(IntegerSizeWidget *isw)
{
	this->isw = isw;
}//setIntegerSizeWidget

IntegerSizeWidget *ImageRepresentationWidget::getIntegerSizeWidget() const
{
	return isw;
}//getIntegerSizeWidget

void ImageRepresentationWidget::onSizeValueChanged(const QSize &size)
{
	giedw->setImage(imageFromData(size.width(), size.height(), getDataInput()));
}//onSizeValueChanged

void ImageRepresentationWidget::on_cbImageFormat_currentIndexChanged(int index)
{
	switch(index){
		case 0:
			imgFormat = QImage::Format_RGB888;
			break;
		default:
			imgFormat = QImage::Format_RGB888;
			break;
	}

}//on_cbImageFormat_currentIndexChanged

void ImageRepresentationWidget::initIRW(const vector<double> &data)
{
	ui->setupUi(this);

	ui->cbImageFormat->setCurrentIndex(0);
	imgFormat = QImage::Format_RGB888;

	pair<int, int> wh = getWidthHeight(data.size());
	isw = new IntegerSizeWidget(QSize(wh.first, wh.second),
								QPair<IntegerSizeWidget::UnitType, IntegerSizeWidget::UnitType>(IntegerSizeWidget::Pixels, IntegerSizeWidget::Pixels));
	ui->groupBox_2->layout()->addWidget(isw);

	imgRepresentation = QImage(isw->getWidth(), isw->getHeight(), imgFormat);

	giedw = new GraphicImageElementDetailedWindow(imgRepresentation, this);
	giedw->setBorderColor(qRgb(127, 127, 127));
	giedw->setImage(imgRepresentation);

//	ui->verticalLayout->setMargin(0);
	ui->verticalLayout->addWidget(giedw);

	//NOTE: temporalmente se ocultara debido a que el metodo alphaChannelChanged no ha sido implementado
	ui->cbxIgnoreAlpha->setVisible(false);

	//NOTE: debe ser llamado despues de inicializar giedw
	setDataInput(data);

	connect(isw, SIGNAL(sizeValueChanged(QSize)), SLOT(onSizeValueChanged(QSize)));
}//initIRW

QImage ImageRepresentationWidget::imageFromData(int w, int h, const vector<double> &data)
{
	QImage img(w, h, QImage::Format_RGB32);
	int inputsIndex;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			inputsIndex = w*i + j;
			if(inputsIndex < (int)data.size()){
				if(j < w && i < h){
					if(img.valid(j, i)){
//						img.setPixel(j, i, data[inputsIndex] > 0 ? qRgb(255, 255, 255): qRgb(0, 0, 0));
						img.setPixel(j, i, data[inputsIndex]);
					}
				}
			}else{
				if(img.valid(j, i)){
					img.setPixel(j, i, qRgb(255, 0, 0));
				}
			}
		}
	}

	return img;
}//imageFromData
