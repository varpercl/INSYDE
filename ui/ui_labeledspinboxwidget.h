/********************************************************************************
** Form generated from reading UI file 'labeledspinboxwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABELEDSPINBOXWIDGET_H
#define UI_LABELEDSPINBOXWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LabeledSpinBoxWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *sbValue;

    void setupUi(QWidget *LabeledSpinBoxWidget)
    {
        if (LabeledSpinBoxWidget->objectName().isEmpty())
            LabeledSpinBoxWidget->setObjectName(QStringLiteral("LabeledSpinBoxWidget"));
        LabeledSpinBoxWidget->resize(400, 300);
        horizontalLayout = new QHBoxLayout(LabeledSpinBoxWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(LabeledSpinBoxWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        sbValue = new QDoubleSpinBox(LabeledSpinBoxWidget);
        sbValue->setObjectName(QStringLiteral("sbValue"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sbValue->sizePolicy().hasHeightForWidth());
        sbValue->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(sbValue);


        retranslateUi(LabeledSpinBoxWidget);

        QMetaObject::connectSlotsByName(LabeledSpinBoxWidget);
    } // setupUi

    void retranslateUi(QWidget *LabeledSpinBoxWidget)
    {
        LabeledSpinBoxWidget->setWindowTitle(QApplication::translate("LabeledSpinBoxWidget", "Form", 0));
        label->setText(QApplication::translate("LabeledSpinBoxWidget", "Valor", 0));
    } // retranslateUi

};

namespace Ui {
    class LabeledSpinBoxWidget: public Ui_LabeledSpinBoxWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELEDSPINBOXWIDGET_H
