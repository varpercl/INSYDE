/********************************************************************************
** Form generated from reading UI file 'labeleddoublespinboxwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABELEDDOUBLESPINBOXWIDGET_H
#define UI_LABELEDDOUBLESPINBOXWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LabeledSpinBoxWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDoubleSpinBox *sbValue;

    void setupUi(QWidget *LabeledSpinBoxWidget)
    {
        if (LabeledSpinBoxWidget->objectName().isEmpty())
            LabeledSpinBoxWidget->setObjectName(QStringLiteral("LabeledSpinBoxWidget"));
        LabeledSpinBoxWidget->resize(423, 23);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LabeledSpinBoxWidget->sizePolicy().hasHeightForWidth());
        LabeledSpinBoxWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(LabeledSpinBoxWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(LabeledSpinBoxWidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        sbValue = new QDoubleSpinBox(LabeledSpinBoxWidget);
        sbValue->setObjectName(QStringLiteral("sbValue"));
        sizePolicy.setHeightForWidth(sbValue->sizePolicy().hasHeightForWidth());
        sbValue->setSizePolicy(sizePolicy);
        sbValue->setWrapping(false);
        sbValue->setButtonSymbols(QAbstractSpinBox::UpDownArrows);

        gridLayout->addWidget(sbValue, 0, 1, 1, 1);


        retranslateUi(LabeledSpinBoxWidget);

        QMetaObject::connectSlotsByName(LabeledSpinBoxWidget);
    } // setupUi

    void retranslateUi(QWidget *LabeledSpinBoxWidget)
    {
        LabeledSpinBoxWidget->setWindowTitle(QApplication::translate("LabeledSpinBoxWidget", "Form", 0));
        label->setText(QApplication::translate("LabeledSpinBoxWidget", "Valor", 0));
        sbValue->setPrefix(QString());
        sbValue->setSuffix(QString());
    } // retranslateUi

};

namespace Ui {
    class LabeledSpinBoxWidget: public Ui_LabeledSpinBoxWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELEDDOUBLESPINBOXWIDGET_H
