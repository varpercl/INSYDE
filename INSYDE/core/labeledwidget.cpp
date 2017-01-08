#include "labeledwidget.h"

core::LabeledWidget::LabeledWidget(const QString &str, const LabeledWidget::Position &pos, QWidget *parent) :
	QWidget(parent)
{
	init(str, pos);
}

core::LabeledWidget::~LabeledWidget()
{
	delete label;
}


void core::LabeledWidget::setLabelText(const QString &text)
{
	label->setText(text);
}

QString core::LabeledWidget::getLabelText() const
{
	return label->text();
}

void core::LabeledWidget::setLabelPosition(const LabeledWidget::Position &pos)
{
	if(labelPosition != pos){

		mainLayout->removeWidget(label);
		switch(pos){
			case LabeledWidget::Top:
				mainLayout->addWidget(label, 0, 1);
				break;
			case LabeledWidget::Bottom:
				mainLayout->addWidget(label, 2, 1);
				break;
			case LabeledWidget::Left:
				mainLayout->addWidget(label, 1, 1);
				break;
			case LabeledWidget::Right:
				mainLayout->addWidget(label, 1, 2);
				break;

		}
		labelPosition = pos;
	}
}

core::LabeledWidget::Position core::LabeledWidget::getLabelPosition() const
{
	return labelPosition;
}

void core::LabeledWidget::setLabel(QLabel *lbl)
{
	label = lbl;
}

QLabel *core::LabeledWidget::getLabel() const
{
	return label;
}

void core::LabeledWidget::setUnits(LabeledWidget::Units unit)
{
	units = unit;
}

core::LabeledWidget::Units core::LabeledWidget::getUnits() const
{
	return units;
}

void core::LabeledWidget::init(const QString &str, const Position &pos)
{
	label = new QLabel();
	label->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

	mainLayout = new QGridLayout();
	mainLayout->setMargin(0);
	mainLayout->addWidget(label, 1, 0);

	labelPosition = Left;

	setLabelPosition(pos);
	setLabelText(str);

	setLayout(mainLayout);
}
