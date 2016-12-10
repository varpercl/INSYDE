#include "imageeffectpropertydialog.h"
#include "ui_graphicimageeffectelementpropertydialog.h"

ImageEffectPropertyDialog::ImageEffectPropertyDialog(ImageEffect *giee, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::GraphicImageEffectElementPropertyDialog)
{
	ui->setupUi(this);

	initGIEEPD(giee);
}

ImageEffectPropertyDialog::~ImageEffectPropertyDialog()
{
	delete ui;
}

QVector<Effect *> ImageEffectPropertyDialog::getEffectList()
{
	QVector<Effect*> effects;

	int sList = ui->lwEffects->count();
	for(int i = 0; i < sList; i++){
		if(ui->lwEffects->item(i)->checkState() == Qt::Checked){
			switch(i){
				case 0:{
//					GraphicImageElement *gie = ;
//					QImage *imageptr = ;
					effects.append(new BlackWhiteEffect(*dynamic_cast<Image*>(giee->getInputElement())->getImage()/*, BlackWhiteEffect::Threshold, 0.5*/));
					break;
				}
				case 1:{
					effects.append(new GrayScaleEffect(*((Image*)giee->getInputElement())->getImage()));
					break;
				}
				default:
					break;
			}
		}
	}
	return effects;
}

void ImageEffectPropertyDialog::setGraphicImageEffectElement(ImageEffect *giee)
{
	this->giee = giee;
}

ImageEffect *ImageEffectPropertyDialog::setGraphicImageEffectElement()
{
	return this->giee;
}

void ImageEffectPropertyDialog::setBNEffectChecked(bool chk)
{
	ui->lwEffects->item(0)->setCheckState(chk? Qt::Checked : Qt::Unchecked);
}

bool ImageEffectPropertyDialog::getBNEffectChecked()
{
	return ui->lwEffects->item(0)->checkState();
}

QWidget *ImageEffectPropertyDialog::getSubWidget()
{
	return ui->hlDivision->itemAt(1)->widget();
}

void ImageEffectPropertyDialog::on_lwEffects_currentRowChanged(int currentRow)
{
	updateConfigWidget(currentRow);
}

void ImageEffectPropertyDialog::initGIEEPD(ImageEffect *giee)
{
	QListWidgetItem* item;
	int sList = ui->lwEffects->count();
	for(int i = 0; i < sList; i++){
		item = ui->lwEffects->item(i);
		item->setFlags(item->flags() | Qt::ItemIsUserCheckable); // set checkable flag
		item->setCheckState(Qt::Unchecked); // AND initialize check state
	}

	setGraphicImageEffectElement(giee);
	bnsw = new BNSubWidget(0.5);
	gssw = new GSSubWidget();
//	ui->hlDivision->addWidget(bnsw);
	updateConfigWidget(0);
}

void ImageEffectPropertyDialog::updateConfigWidget(int i)
{
	ui->hlDivision->removeItem(ui->hlDivision->itemAt(1));
	switch(i){
		case 0:
			ui->hlDivision->addWidget(bnsw);
			break;
		case 1:
			ui->hlDivision->addWidget(gssw);
			break;
		default:
			break;
	}
}
