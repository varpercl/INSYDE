#include "graphicimageeffectelementpropertydialog.h"
#include "ui_graphicimageeffectelementpropertydialog.h"

GraphicImageEffectElementPropertyDialog::GraphicImageEffectElementPropertyDialog(GraphicImageEffectElement *giee, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::GraphicImageEffectElementPropertyDialog)
{
	ui->setupUi(this);

	initGIEEPD(giee);
}

GraphicImageEffectElementPropertyDialog::~GraphicImageEffectElementPropertyDialog()
{
	delete ui;
}

QVector<Effect *> GraphicImageEffectElementPropertyDialog::getEffectList()
{
	QVector<Effect*> effects;

	int sList = ui->lwEffects->count();
	for(int i = 0; i < sList; i++){
		if(ui->lwEffects->item(i)->checkState() == Qt::Checked){
			switch(i){
				case 0:{
//					GraphicImageElement *gie = ;
//					QImage *imageptr = ;
					effects.append(new BlackWhiteEffect(dynamic_cast<GraphicImageElement*>(giee->getInputElement())->getImage()/*, BlackWhiteEffect::Threshold, 0.5*/));
					break;
				}
				case 1:{
					effects.append(new GrayScaleEffect(((GraphicImageElement*)giee->getInputElement())->getImage()));
					break;
				}
				default:
					break;
			}
		}
	}
	return effects;
}

void GraphicImageEffectElementPropertyDialog::setGraphicImageEffectElement(GraphicImageEffectElement *giee)
{
	this->giee = giee;
}

GraphicImageEffectElement *GraphicImageEffectElementPropertyDialog::setGraphicImageEffectElement()
{
	return this->giee;
}

void GraphicImageEffectElementPropertyDialog::setBNEffectChecked(bool chk)
{
	ui->lwEffects->item(0)->setCheckState(chk? Qt::Checked : Qt::Unchecked);
}

bool GraphicImageEffectElementPropertyDialog::getBNEffectChecked()
{
	return ui->lwEffects->item(0)->checkState();
}

QWidget *GraphicImageEffectElementPropertyDialog::getSubWidget()
{
	return ui->hlDivision->itemAt(1)->widget();
}

void GraphicImageEffectElementPropertyDialog::on_lwEffects_currentRowChanged(int currentRow)
{
	updateConfigWidget(currentRow);
}

void GraphicImageEffectElementPropertyDialog::initGIEEPD(GraphicImageEffectElement *giee)
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

void GraphicImageEffectElementPropertyDialog::updateConfigWidget(int i)
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
