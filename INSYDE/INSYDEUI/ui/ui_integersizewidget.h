/********************************************************************************
** Form generated from reading UI file 'integersizewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTEGERSIZEWIDGET_H
#define UI_INTEGERSIZEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IntegerSizeWidget
{
public:
    QFormLayout *formLayout;
    QLabel *lblCaptionWidth;
    QHBoxLayout *horizontalLayout;
    QSpinBox *sbWidth;
    QLabel *lblWidthUnit;
    QSpacerItem *horizontalSpacer;
    QLabel *lblCaptionHeight;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *sbHeight;
    QLabel *lblHeightUnit;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *IntegerSizeWidget)
    {
        if (IntegerSizeWidget->objectName().isEmpty())
            IntegerSizeWidget->setObjectName(QStringLiteral("IntegerSizeWidget"));
        IntegerSizeWidget->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(IntegerSizeWidget->sizePolicy().hasHeightForWidth());
        IntegerSizeWidget->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(IntegerSizeWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        lblCaptionWidth = new QLabel(IntegerSizeWidget);
        lblCaptionWidth->setObjectName(QStringLiteral("lblCaptionWidth"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblCaptionWidth);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sbWidth = new QSpinBox(IntegerSizeWidget);
        sbWidth->setObjectName(QStringLiteral("sbWidth"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sbWidth->sizePolicy().hasHeightForWidth());
        sbWidth->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(sbWidth);

        lblWidthUnit = new QLabel(IntegerSizeWidget);
        lblWidthUnit->setObjectName(QStringLiteral("lblWidthUnit"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblWidthUnit->sizePolicy().hasHeightForWidth());
        lblWidthUnit->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(lblWidthUnit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        lblCaptionHeight = new QLabel(IntegerSizeWidget);
        lblCaptionHeight->setObjectName(QStringLiteral("lblCaptionHeight"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lblCaptionHeight);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        sbHeight = new QSpinBox(IntegerSizeWidget);
        sbHeight->setObjectName(QStringLiteral("sbHeight"));
        sizePolicy1.setHeightForWidth(sbHeight->sizePolicy().hasHeightForWidth());
        sbHeight->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(sbHeight);

        lblHeightUnit = new QLabel(IntegerSizeWidget);
        lblHeightUnit->setObjectName(QStringLiteral("lblHeightUnit"));
        sizePolicy2.setHeightForWidth(lblHeightUnit->sizePolicy().hasHeightForWidth());
        lblHeightUnit->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(lblHeightUnit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_2);


        retranslateUi(IntegerSizeWidget);

        QMetaObject::connectSlotsByName(IntegerSizeWidget);
    } // setupUi

    void retranslateUi(QWidget *IntegerSizeWidget)
    {
        IntegerSizeWidget->setWindowTitle(QApplication::translate("IntegerSizeWidget", "Form", 0));
        lblCaptionWidth->setText(QApplication::translate("IntegerSizeWidget", "Anchura", 0));
        lblWidthUnit->setText(QApplication::translate("IntegerSizeWidget", "TextLabel", 0));
        lblCaptionHeight->setText(QApplication::translate("IntegerSizeWidget", "Altura", 0));
        lblHeightUnit->setText(QApplication::translate("IntegerSizeWidget", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class IntegerSizeWidget: public Ui_IntegerSizeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTEGERSIZEWIDGET_H
