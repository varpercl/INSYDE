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

void ImageRepresentationWidget::updateRepresentation()
{
	int
			h = imgRepresentation.height(),
			w = imgRepresentation.width();
	int inputsIndex;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			inputsIndex = w*i + j;
			if(inputsIndex < (int)dataInput.size()){
				if(j < w && i < h){
					imgRepresentation.setPixel(j, i, dataInput[inputsIndex] > 0 ? 0xffffffff: 0xff000000);
				}
			}else{
				imgRepresentation.setPixel(j, i, qRgb(127, 127, 127));
			}
		}
	}

	giedw->setImage(imgRepresentation);

}//updateRepresentation

void ImageRepresentationWidget::on_sbWidth_valueChanged(int arg1)
{
	imgRepresentation = imgRepresentation.copy(0, 0, arg1, ui->sbHeight->value());
	giedw->setImage(imgRepresentation);
}//on_sbWidth_valueChanged

void ImageRepresentationWidget::on_sbHeight_valueChanged(int arg1)
{
	imgRepresentation = imgRepresentation.copy(0, 0, ui->sbWidth->value(), arg1);
	giedw->setImage(imgRepresentation);
}//on_sbHeight_valueChanged

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

	imgRepresentation = QImage(ui->sbWidth->value(), ui->sbHeight->value(), imgFormat);

	giedw = new GraphicImageElementDetailedWindow(imgRepresentation, this);
	giedw->setBorderColor(qRgb(127, 127, 127));
	giedw->setImage(imgRepresentation);
	ui->verticalLayout->addWidget(giedw);

	//NOTE: debe ser llamado despues de inicializar giedw
	setDataInput(data);
}//initIRW
