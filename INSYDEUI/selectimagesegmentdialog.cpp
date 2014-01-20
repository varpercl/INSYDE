#include "selectimagesegmentdialog.h"
#include "ui_selectimagesegmentdialog.h"

SelectImageSegmentDialog::SelectImageSegmentDialog(const QImage &img, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SelectImageSegmentDialog)
{
	initSISD(img);
}

SelectImageSegmentDialog::~SelectImageSegmentDialog()
{
	delete ui;
}

void SelectImageSegmentDialog::initSISD(const QImage &img)
{
	ui->setupUi(this);

	giedw = new GraphicImageElementDetailedWindow(img);
	giedw->setBorderColor(qRgb(127, 127, 127));
	giedw->setBorderVisible(true);

	giedw->setSelectionRect(QRectF(0, 0, 20, 20));
	giedw->setSelectionRectVisible(true);

	ui->verticalLayout->insertWidget(0, giedw);
}
