#include "labeledwidget.h"

LabeledWidget::LabeledWidget(const QString &str, const LabeledWidget::Position &pos, QWidget *parent) :
	QWidget(parent)
{
	init(str, pos);
}

LabeledWidget::~LabeledWidget()
{
	delete label;
}


void LabeledWidget::setLabelText(const QString &text)
{
	label->setText(text);
}

QString LabeledWidget::getLabelText() const
{
	return label->text();
}

void LabeledWidget::setLabelPosition(const LabeledWidget::Position &pos)
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

LabeledWidget::Position LabeledWidget::getLabelPosition() const
{
	return labelPosition;
}

void LabeledWidget::setLabel(QLabel *lbl)
{
	label = lbl;
}

QLabel *LabeledWidget::getLabel() const
{
	return label;
}

void LabeledWidget::init(const QString &str, const Position &pos)
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
