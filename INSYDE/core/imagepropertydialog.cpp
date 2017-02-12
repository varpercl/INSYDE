#include "imagepropertydialog.h"

core::ImagePropertyDialog::ImagePropertyDialog(QWidget *parent) :
	GraphicObjectPropertyDialog(nullptr, parent)
{
	init(nullptr);
}

core::ImagePropertyDialog::ImagePropertyDialog(Image *img, QWidget *parent) :
	GraphicObjectPropertyDialog(img, parent)
{
	init(img);
}

core::ImagePropertyDialog::~ImagePropertyDialog()
{
}

void core::ImagePropertyDialog::accept()
{
	onApplyClicked();
	close();
}

void core::ImagePropertyDialog::onApplyClicked()
{
	if(img->getFilePath() != felPath->getFilePath()){
		img->setImage(felPath->getFilePath());
	}

	QImage *tmpImage = img->getImage();
	switch(lcbImageFormats->getComboBox()->currentIndex()){
		case 0: // "Mono"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_Mono);
			break;
		case 1: // "MonoLSB"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_MonoLSB);
			break;
		case 2: // "Indexed8"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_Indexed8);
			break;
		case 3: // "RGB32"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_RGB32);
			break;
		case 4: // "ARGB32"<<
			*tmpImage = tmpImage->convertToFormat(QImage::Format_ARGB32);
			break;
		case 5: // "ARGB32 Premultiplied"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_ARGB32_Premultiplied);
			break;
		case 6: // "RGB16"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_RGB16);
			break;
		case 7: // "ARGB8565 Premultiplied"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_ARGB8565_Premultiplied);
			break;
		case 8: // "RGB666"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_RGB666);
			break;
		case 9: // "ARGB6666 Premultiplied"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_ARGB6666_Premultiplied);
			break;
		case 10: // "RGB555"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_RGB555);
			break;
		case 11: // "ARGB8555 Premultiplied"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_ARGB8555_Premultiplied);
			break;
		case 12: // "RGB888"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_RGB888);
			break;
		case 13: // "RGB444"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_RGB444);
			break;
		case 14: // "ARGB4444 Premultiplied"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_ARGB4444_Premultiplied);
			break;
		case 15: // "RGBX8888"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_RGBX8888);
			break;
		case 16: // "RGBA8888"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_RGBA8888);
			break;
		case 17: // "RGBA8888 Premultiplied"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_RGBA8888_Premultiplied);
			break;
		case 18: // "BGR30"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_BGR30);
			break;
		case 19: // "A2BGR30 Premultiplied"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_A2BGR30_Premultiplied);
			break;
		case 20: // "RGB30"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_RGB30);
			break;
		case 21: // "A2RGB30 Premultiplied"
			*tmpImage = tmpImage->convertToFormat(QImage::Format_A2RGB30_Premultiplied);
			break;
	}
	img->update();
}

void core::ImagePropertyDialog::onFilePathChanged(const QString &path)
{
	QImage tmpImage(path);

	if(tmpImage.isNull()){
		enableControls(false, tmpImage);
	}else{
		enableControls(true, tmpImage);
	}
}

void core::ImagePropertyDialog::init(Image *img)
{
	this->img = img;

	//Initialize FileEditLine
	felPath = new FileEditLine(img->getFilePath());

	//Initialize QVBoxLayout
	mainLayout = new QVBoxLayout();

	//LabeledComboBox
	lcbImageFormats = new LabeledComboBox("Formatos", img->getFormats());

	felPath->setFilters("All image formats (*.bmp *.png *.jpg *.gif);; Bitmap BMP (*.bmp);; Portable Network Graphic PNG (*.png);; JPEG image (*.jpg);; GIF image (*.gif)");
	felPath->setSelectedFilter("All image formats (*.bmp *.png *.jpg *.gif)");

	if(img->getImage()->isNull()){
		lcbImageFormats->getComboBox()->setCurrentIndex(0);
	}else{
		lcbImageFormats->getComboBox()->setCurrentIndex(img->getImage()->format()-1);
	}

	mainLayout->addWidget(felPath);
	mainLayout->addWidget(lcbImageFormats);

	getMainWindow()->centralWidget()->setLayout(mainLayout);

	if(img->getImage()->isNull()){
		enableControls(false, QImage());
	}

	connect(this, SIGNAL(accepted()), SLOT(accept()));
	connect(felPath->getLineEdit(), SIGNAL(textChanged(QString)), SLOT(onFilePathChanged(QString)));
}

void core::ImagePropertyDialog::enableControls(bool b, const QImage &tempImage)
{
	lcbImageFormats->setEnabled(b);
	if(tempImage.isNull()){
		lcbImageFormats->getComboBox()->setCurrentIndex(0);
	}else{
		lcbImageFormats->getComboBox()->setCurrentIndex(tempImage.format() - 1);
	}
}
