#include "labeledwidget.h"

core::LabeledWidget::LabeledWidget(const QString &labelText, const Position &pos, QWidget *parent) :
	QWidget(parent)
{
//    Q_INIT_RESOURCE(core_media);
	init(labelText, pos);
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

void core::LabeledWidget::setLabelPosition(const Position &pos)
{
	if(labelPosition != pos){

		mainLayout->removeWidget(label);
		switch(pos){
			case Position::Top:
				mainLayout->addWidget(label, 0, 1);
				break;
			case Position::Bottom:
				mainLayout->addWidget(label, 2, 1);
				break;
			case Position::Left:
				mainLayout->addWidget(label, 1, 1);
				break;
			case Position::Right:
				mainLayout->addWidget(label, 1, 2);
				break;

		}
		labelPosition = pos;
	}
}

Position core::LabeledWidget::getLabelPosition() const
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

void core::LabeledWidget::setUnits(Units unit)
{
	units = unit;
}

Units core::LabeledWidget::getUnits() const
{
	return units;
}

QLayout *core::LabeledWidget::getLayout() const
{
	return mainLayout;
}

void core::LabeledWidget::setCentralWidget(QWidget *w)
{
	mainLayout->addWidget(w, 1, 1);
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
