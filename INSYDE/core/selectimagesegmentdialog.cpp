#include "selectimagesegmentdialog.h"
#include "ui_selectimagesegmentdialog.h"

SelectImageSegmentDialog::SelectImageSegmentDialog(const QImage &img, const QRect &selrect, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SelectImageSegmentDialog)
{
	init(img, selrect);
}

SelectImageSegmentDialog::~SelectImageSegmentDialog()
{
	delete ui;
}

void SelectImageSegmentDialog::setSelectionRect(const QRect &rect)
{
	giedw->setSelectionRect(rect);
}

QRect SelectImageSegmentDialog::getSelectionRect() const
{
	return giedw->getSelectionRect();
}

QImage SelectImageSegmentDialog::getImageSegment() const
{
	return giedw->getImageSegment();
}

void SelectImageSegmentDialog::setIntegerSizeWidget(IntegerSizeWidget *isw)
{
	this->isw = isw;
}

IntegerSizeWidget *SelectImageSegmentDialog::getIntegerSizeWidget() const
{
	return isw;
}

void SelectImageSegmentDialog::init(const QImage &img, const QRect &selrect)
{
	ui->setupUi(this);

	giedw = new ImageDetailedWindow(new QImage(img));
//	giedw->setBorderColor(qRgb(127, 127, 127));
//	giedw->setBorderVisible(true);

	giedw->setSelectionRect(selrect);
	giedw->setSelectionRectVisible(true);

	ui->verticalLayout->insertWidget(0, giedw);

	isw = new IntegerSizeWidget(selrect.size(),
								QPair<IntegerSizeWidget::Units, IntegerSizeWidget::Units>(IntegerSizeWidget::Pixels, IntegerSizeWidget::Pixels));

	ui->verticalLayout->insertWidget(1, isw);

	connect(isw, SIGNAL(widthChanged(int)), SLOT(onWidthChanged(int)));
	connect(isw, SIGNAL(heightChanged(int)), SLOT(onHeightChanged(int)));
}

void SelectImageSegmentDialog::onWidthChanged(int width)
{
	QRect tmpRect = giedw->getSelectionRect();
	tmpRect.setWidth(width);
	giedw->setSelectionRect(tmpRect);
}

void SelectImageSegmentDialog::onHeightChanged(int height)
{
	QRect tmpRect = giedw->getSelectionRect();
	tmpRect.setHeight(height);
	giedw->setSelectionRect(tmpRect);
}
