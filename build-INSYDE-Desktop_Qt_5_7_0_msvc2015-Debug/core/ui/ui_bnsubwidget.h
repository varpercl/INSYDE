/********************************************************************************
** Form generated from reading UI file 'bnsubwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BNSUBWIDGET_H
#define UI_BNSUBWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BNSubWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QSlider *hsThreshold;

    void setupUi(QWidget *BNSubWidget)
    {
        if (BNSubWidget->objectName().isEmpty())
            BNSubWidget->setObjectName(QStringLiteral("BNSubWidget"));
        BNSubWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(BNSubWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(BNSubWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        hsThreshold = new QSlider(BNSubWidget);
        hsThreshold->setObjectName(QStringLiteral("hsThreshold"));
        hsThreshold->setMaximumSize(QSize(150, 16777215));
        hsThreshold->setMinimum(1);
        hsThreshold->setMaximum(100);
        hsThreshold->setOrientation(Qt::Horizontal);

        formLayout->setWidget(0, QFormLayout::FieldRole, hsThreshold);


        verticalLayout->addLayout(formLayout);


        retranslateUi(BNSubWidget);

        QMetaObject::connectSlotsByName(BNSubWidget);
    } // setupUi

    void retranslateUi(QWidget *BNSubWidget)
    {
        BNSubWidget->setWindowTitle(QApplication::translate("BNSubWidget", "Form", 0));
        label->setText(QApplication::translate("BNSubWidget", "Umbral", 0));
    } // retranslateUi

};

namespace Ui {
    class BNSubWidget: public Ui_BNSubWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BNSUBWIDGET_H
