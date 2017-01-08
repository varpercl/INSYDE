#include "labeledcombobox.h"

core::LabeledComboBox::LabeledComboBox(const QString &lbl, const LabeledWidget::Position &pos, QWidget *parent) :
	LabeledWidget(lbl, pos, parent)
{
	init(QStringList());
}

core::LabeledComboBox::LabeledComboBox(const QString &lbl, const QStringList &list, const Position &pos, QWidget *parent) :
	LabeledWidget(lbl, pos, parent)
{
	init(list);
}

core::LabeledComboBox::~LabeledComboBox()
{
	delete comboBox;
}

void core::LabeledComboBox::setComboBox(QComboBox *cb)
{
	if(comboBox != cb){
		comboBox = cb;

        connectSignals();
	}
}

QComboBox *core::LabeledComboBox::getComboBox() const
{
	return comboBox;
}

void core::LabeledComboBox::init(const QStringList &list)
{
	comboBox = new QComboBox();
	comboBox->addItems(list);

	QGridLayout *gl = (QGridLayout *) layout();
	gl->addWidget(comboBox, 1, 1);

    connectSignals();
}

void core::LabeledComboBox::connectSignals()
{

}

