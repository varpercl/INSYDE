#include "selectimagesegmentdialog.h"
#include "ui_selectimagesegmentdialog.h"

core::SelectImageSegmentDialog::SelectImageSegmentDialog(const QImage &img, const QRect &selrect, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SelectImageSegmentDialog)
{
//    Q_INIT_RESOURCE(core_media);
	init(img, selrect);
}

core::SelectImageSegmentDialog::~SelectImageSegmentDialog()
{
	delete ui;
}

void core::SelectImageSegmentDialog::setSelectionRect(const QRect &rect)
{
	giedw->setSelectionRect(rect);
}

QRect core::SelectImageSegmentDialog::getSelectionRect() const
{
	return giedw->getSelectionRect();
}

QImage core::SelectImageSegmentDialog::getImageSegment() const
{
	return giedw->getImageSegment();
}

void core::SelectImageSegmentDialog::setIntegerSizeWidget(IntegerSizeWidget *isw)
{
	this->isw = isw;
}

core::IntegerSizeWidget *core::SelectImageSegmentDialog::getIntegerSizeWidget() const
{
	return isw;
}

void core::SelectImageSegmentDialog::init(const QImage &img, const QRect &selrect)
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

void core::SelectImageSegmentDialog::onWidthChanged(int width)
{
	QRect tmpRect = giedw->getSelectionRect();
	tmpRect.setWidth(width);
	giedw->setSelectionRect(tmpRect);
}

void core::SelectImageSegmentDialog::onHeightChanged(int height)
{
	QRect tmpRect = giedw->getSelectionRect();
	tmpRect.setHeight(height);
	giedw->setSelectionRect(tmpRect);
}
