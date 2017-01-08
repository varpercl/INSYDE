#include "imageeffectpropertydialog.h"
#include "ui_graphicimageeffectelementpropertydialog.h"

core::ImageEffectPropertyDialog::ImageEffectPropertyDialog(QWidget *parent) :
	QDialog(parent)
{

}

core::ImageEffectPropertyDialog::ImageEffectPropertyDialog(ImageEffect *giee, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::GraphicImageEffectElementPropertyDialog)
{
	ui->setupUi(this);

	initGIEEPD(giee);
}

core::ImageEffectPropertyDialog::~ImageEffectPropertyDialog()
{
	delete ui;
}

QVector<core::Effect *> core::ImageEffectPropertyDialog::getEffectList()
{
    QVector<core::Effect*> effects;

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

void core::ImageEffectPropertyDialog::setGraphicImageEffectElement(ImageEffect *giee)
{
	this->giee = giee;
}

core::ImageEffect *core::ImageEffectPropertyDialog::setGraphicImageEffectElement()
{
	return this->giee;
}

void core::ImageEffectPropertyDialog::setBNEffectChecked(bool chk)
{
	ui->lwEffects->item(0)->setCheckState(chk? Qt::Checked : Qt::Unchecked);
}

bool core::ImageEffectPropertyDialog::getBNEffectChecked()
{
	return ui->lwEffects->item(0)->checkState();
}

QWidget *core::ImageEffectPropertyDialog::getSubWidget()
{
	return ui->hlDivision->itemAt(1)->widget();
}

void core::ImageEffectPropertyDialog::on_lwEffects_currentRowChanged(int currentRow)
{
	updateConfigWidget(currentRow);
}

void core::ImageEffectPropertyDialog::initGIEEPD(ImageEffect *giee)
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

void core::ImageEffectPropertyDialog::updateConfigWidget(int i)
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
