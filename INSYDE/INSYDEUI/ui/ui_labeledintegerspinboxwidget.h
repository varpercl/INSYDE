/********************************************************************************
** Form generated from reading UI file 'labeledintegerspinboxwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABELEDINTEGERSPINBOXWIDGET_H
#define UI_LABELEDINTEGERSPINBOXWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LabeledIntegerSpinBoxWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *sbValue;

    void setupUi(QWidget *LabeledIntegerSpinBoxWidget)
    {
        if (LabeledIntegerSpinBoxWidget->objectName().isEmpty())
            LabeledIntegerSpinBoxWidget->setObjectName(QStringLiteral("LabeledIntegerSpinBoxWidget"));
        LabeledIntegerSpinBoxWidget->resize(255, 23);
        horizontalLayout = new QHBoxLayout(LabeledIntegerSpinBoxWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(LabeledIntegerSpinBoxWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        sbValue = new QSpinBox(LabeledIntegerSpinBoxWidget);
        sbValue->setObjectName(QStringLiteral("sbValue"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sbValue->sizePolicy().hasHeightForWidth());
        sbValue->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(sbValue);


        retranslateUi(LabeledIntegerSpinBoxWidget);

        QMetaObject::connectSlotsByName(LabeledIntegerSpinBoxWidget);
    } // setupUi

    void retranslateUi(QWidget *LabeledIntegerSpinBoxWidget)
    {
        LabeledIntegerSpinBoxWidget->setWindowTitle(QApplication::translate("LabeledIntegerSpinBoxWidget", "Form", 0));
        label->setText(QApplication::translate("LabeledIntegerSpinBoxWidget", "Valor", 0));
    } // retranslateUi

};

namespace Ui {
    class LabeledIntegerSpinBoxWidget: public Ui_LabeledIntegerSpinBoxWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELEDINTEGERSPINBOXWIDGET_H
