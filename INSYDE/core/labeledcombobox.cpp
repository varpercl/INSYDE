#include "labeledcombobox.h"

LabeledComboBox::LabeledComboBox(const QString &lbl, const LabeledWidget::Position &pos, QWidget *parent) :
	LabeledWidget(lbl, pos, parent)
{
	init(QStringList());
}

LabeledComboBox::LabeledComboBox(const QString &lbl, const QStringList &list, const Position &pos, QWidget *parent) :
	LabeledWidget(lbl, pos, parent)
{
	init(list);
}

LabeledComboBox::~LabeledComboBox()
{
	delete comboBox;
}

void LabeledComboBox::setComboBox(QComboBox *cb)
{
	if(comboBox != cb){
		comboBox = cb;

		connectCBSignals();
	}
}

QComboBox *LabeledComboBox::getComboBox() const
{
	return comboBox;
}

void LabeledComboBox::init(const QStringList &list)
{
	comboBox = new QComboBox();
	comboBox->addItems(list);

	QGridLayout *gl = (QGridLayout *) layout();
	gl->addWidget(comboBox, 1, 1);

	connectCBSignals();
}

void LabeledComboBox::connectCBSignals()
{

}

