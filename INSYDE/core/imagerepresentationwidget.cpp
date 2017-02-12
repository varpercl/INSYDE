#include "imagerepresentationwidget.h"

core::ImageRepresentationWidget::ImageRepresentationWidget(QWidget *parent) :
	DataRepresentationWidget(vector<double>(), parent)
{
	init();
}

core::ImageRepresentationWidget::ImageRepresentationWidget(const vector<double> &data, QWidget *parent) :
	DataRepresentationWidget(data, parent)
{
	init();
}

core::ImageRepresentationWidget::~ImageRepresentationWidget()
{

}

void core::ImageRepresentationWidget::setInputs(const vector<double> &datainput)
{
	DataRepresentationWidget::setInputs(datainput);

	if(updatesEnabled()){

		giedw->setImage(new QImage(imageFromData(isw->getWidth(), isw->getHeight(), getInputs())));
	}
}

void core::ImageRepresentationWidget::setWidth(int w)
{
	isw->setWidth(w);
	if(updatesEnabled()){
		giedw->setImage(new QImage(imageFromData(isw->getWidth(), isw->getHeight(), getInputs())));
	}

	emit sizeChanged(QSize(w, isw->getHeight()));
}

int core::ImageRepresentationWidget::getWidth() const
{
	return isw->getWidth();
}

void core::ImageRepresentationWidget::setHeight(int h)
{
	isw->setHeight(h);
	if(updatesEnabled()){
		giedw->setImage(new QImage(imageFromData(isw->getWidth(), isw->getHeight(), getInputs())));
	}

	emit sizeChanged(QSize(isw->getWidth(), h));
}

int core::ImageRepresentationWidget::getHeight() const
{
	return isw->getHeight();
}

void core::ImageRepresentationWidget::setSize(const QSize &size)
{
	isw->setSize(size);
	if(updatesEnabled()){
		giedw->setImage(new QImage(imageFromData(isw->getWidth(), isw->getHeight(), getInputs())));
	}

	emit sizeChanged(size);
}

QSize core::ImageRepresentationWidget::getSize() const
{
	return isw->getSize();
}

QImage core::ImageRepresentationWidget::getImage() const
{
	return imageFromData(isw->getSize(), getInputs());
}

void core::ImageRepresentationWidget::onSizeValueChanged(const QSize &size)
{
	(void) size;
	if(updatesEnabled()){
		giedw->setImage(new QImage(imageFromData(isw->getWidth(), isw->getHeight(), getInputs())));
	}

	emit sizeChanged(size);
}

void core::ImageRepresentationWidget::on_cbImageFormat_currentIndexChanged(int index)
{
	emit imageFormatChanged((QImage::Format)(index+1));
}

void core::ImageRepresentationWidget::onIgnoreAlphaChannelToogled(bool ac)
{
	(void) ac;
	//TODO: implementar
	//	QTableWidgetItem *itm;

	//	//	int nPat = getPatternCount();
	//	//	int sInputs = getInputSize();
	//	TrainingSet *tempTS = tstInputs->getTrainingSet();
	//	int nPat = tempTS->getPatternCount();
	//	int sInputs = tempTS->getInputsSize();
	//	for(int i = 0; i < nPat; i++){
	//		for(int j = 0; j < sInputs; j++){
	//			itm = new QTableWidgetItem(QString::number(tstInputs->item(i,j)->text().toInt() | 0xff000000));
	//			tstInputs->setItem(i, j, itm);
	//		}
	//	}
}

QImage::Format core::ImageRepresentationWidget::getImageFormat() const
{
	return imageFormat;
}

void core::ImageRepresentationWidget::setImageFormat(const QImage::Format &value)
{
	imageFormat = value;

	lcbImageFormat->getComboBox()->setCurrentIndex((int)(value) - 1);

	if(updatesEnabled()){
		giedw->setImage(new QImage(imageFromData(isw->getWidth(), isw->getHeight(), getInputs())));
	}

	emit imageFormatChanged(value);
}

//void core::ImageRepresentationWidget::setImageObject(Image *img)
//{
//	giedw->setImageObject(img);
//}

core::Image *core::ImageRepresentationWidget::getImageObject() const
{
	return giedw->getImageObject();
}

void core::ImageRepresentationWidget::init()
{

	cbxIgnoreAlpha = new QCheckBox();
	cbxIgnoreAlpha->setObjectName(QStringLiteral("cbxIgnoreAlpha"));

	horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    pair<int, int> wh = core::common::getWidthHeight((int)getInputs().size());
	isw = new IntegerSizeWidget(QSize(wh.first, wh.second),
								QPair<IntegerSizeWidget::Units, IntegerSizeWidget::Units>(IntegerSizeWidget::Pixels, IntegerSizeWidget::Pixels));
	isw->setMinimumSizeValues(0, 0);

	lcbImageFormat = new LabeledComboBox("Formato");

	frmLayout = new QHBoxLayout();
	frmLayout->addWidget(lcbImageFormat);
	frmLayout->addWidget(cbxIgnoreAlpha);
//	frmLayout->addItem(horizontalSpacer);

	gbVLayout = new QVBoxLayout();
	gbVLayout->addLayout(frmLayout);
	gbVLayout->addWidget(isw);

	gbDimentions = new QGroupBox(this);
	gbDimentions->setTitle("Propiedades");
	gbDimentions->setLayout(gbVLayout);


	lcbImageFormat->getComboBox()->addItems(QStringList()
								<< "Mono"
								<< "MonoLSB"
								<< "Indexed8"
								<< "RGB32"
								<< "ARGB32"
								<< "ARGB32 Premultiplied"
								<< "RGB16"
								<< "ARGB8565 Premultiplied"
								<< "RGB666"
								<< "ARGB6666 Premultiplied"
								<< "RGB555"
								<< "ARGB8555 Premultiplied"
								<< "RGB888"
								<< "RGB444"
								<< "ARGB4444 Premultiplied"
								<< "RGBX8888"
								<< "RGBA8888"
								<< "RGBA8888 Premultiplied");

	lcbImageFormat->getComboBox()->setCurrentIndex(4);
	imageFormat = (QImage::Format_ARGB32);
	emit imageFormatChanged(imageFormat);

	giedw = new ImageDetailedWindow(new QImage(isw->getWidth(), isw->getHeight(), imageFormat));
	giedw->setWindowTitle(QString::fromLatin1("Visualización"));
//	giedw->setBorderColor(qRgb(127, 127, 127));

	layout()->addWidget(gbDimentions);
	layout()->addWidget(giedw);

	//NOTE: temporalmente se ocultara debido a que el metodo alphaChannelChanged no ha sido implementado
	cbxIgnoreAlpha->setVisible(false);

	//NOTE: debe ser llamado despues de inicializar giedw
//	setInputs(data);

	connect(isw, SIGNAL(sizeChanged(QSize)), SLOT(onSizeValueChanged(QSize)));
	connect(cbxIgnoreAlpha, SIGNAL(toggled(bool)), SLOT(onIgnoreAlphaChannelToogled(bool)));
}

QImage core::ImageRepresentationWidget::imageFromData(const QSize &size, const vector<double> &data) const
{
	return imageFromData(size.width(), size.height(), data);
}

QImage core::ImageRepresentationWidget::imageFromData(int w, int h, const vector<double> &data) const
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
}
