/********************************************************************************
** Form generated from reading UI file 'minmaxvaluewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINMAXVALUEWIDGET_H
#define UI_MINMAXVALUEWIDGET_H

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

class Ui_MinMaxValueWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QDoubleSpinBox *sbMin;
    QLabel *label_3;
    QDoubleSpinBox *sbMax;

    void setupUi(QWidget *MinMaxValueWidget)
    {
        if (MinMaxValueWidget->objectName().isEmpty())
            MinMaxValueWidget->setObjectName(QStringLiteral("MinMaxValueWidget"));
        MinMaxValueWidget->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MinMaxValueWidget->sizePolicy().hasHeightForWidth());
        MinMaxValueWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(MinMaxValueWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(MinMaxValueWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_2);

        sbMin = new QDoubleSpinBox(MinMaxValueWidget);
        sbMin->setObjectName(QStringLiteral("sbMin"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sbMin->sizePolicy().hasHeightForWidth());
        sbMin->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(sbMin);

        label_3 = new QLabel(MinMaxValueWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_3);

        sbMax = new QDoubleSpinBox(MinMaxValueWidget);
        sbMax->setObjectName(QStringLiteral("sbMax"));
        sizePolicy2.setHeightForWidth(sbMax->sizePolicy().hasHeightForWidth());
        sbMax->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(sbMax);


        retranslateUi(MinMaxValueWidget);

        QMetaObject::connectSlotsByName(MinMaxValueWidget);
    } // setupUi

    void retranslateUi(QWidget *MinMaxValueWidget)
    {
        MinMaxValueWidget->setWindowTitle(QApplication::translate("MinMaxValueWidget", "Form", 0));
        label_2->setText(QApplication::translate("MinMaxValueWidget", "M\303\255nimo", 0));
        label_3->setText(QApplication::translate("MinMaxValueWidget", "M\303\241ximo", 0));
    } // retranslateUi

};

namespace Ui {
    class MinMaxValueWidget: public Ui_MinMaxValueWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINMAXVALUEWIDGET_H
