#include "extendedlineedit.h"

core::ExtendedLineEdit::ExtendedLineEdit() : LabeledWidget()
{
	init("");
}

core::ExtendedLineEdit::ExtendedLineEdit(const QString &label, const QString &text, QWidget *parent) :
	LabeledWidget(label)
{
	init(text);
}

core::ExtendedLineEdit::ExtendedLineEdit(const core::ExtendedLineEdit &cpy)
{
	this->setLabelText(cpy.getLabelText());
	this->setText(cpy.getText());
}

void core::ExtendedLineEdit::setText(const QString &text)
{
	txt->setText(text);
}

QString core::ExtendedLineEdit::getText() const
{
	return txt->text();
}

QLineEdit *core::ExtendedLineEdit::getLineEdit() const
{
	return txt;
}

void core::ExtendedLineEdit::init(const QString &txt)
{
	this->txt = new QLineEdit(txt);

	setCentralWidget(this->txt);
//	setLabelText(label);

}
