/********************************************************************************
** Form generated from reading UI file 'normalizationwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NORMALIZATIONWIDGET_H
#define UI_NORMALIZATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NormalizationWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *cbNormalizationType;
    QLabel *label;

    void setupUi(QWidget *NormalizationWidget)
    {
        if (NormalizationWidget->objectName().isEmpty())
            NormalizationWidget->setObjectName(QStringLiteral("NormalizationWidget"));
        NormalizationWidget->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NormalizationWidget->sizePolicy().hasHeightForWidth());
        NormalizationWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(NormalizationWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(NormalizationWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cbNormalizationType = new QComboBox(groupBox);
        cbNormalizationType->setObjectName(QStringLiteral("cbNormalizationType"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cbNormalizationType->sizePolicy().hasHeightForWidth());
        cbNormalizationType->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(cbNormalizationType);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);


        verticalLayout->addWidget(groupBox);


        retranslateUi(NormalizationWidget);

        QMetaObject::connectSlotsByName(NormalizationWidget);
    } // setupUi

    void retranslateUi(QWidget *NormalizationWidget)
    {
        NormalizationWidget->setWindowTitle(QApplication::translate("NormalizationWidget", "Form", 0));
        groupBox->setTitle(QApplication::translate("NormalizationWidget", "Normalizaci\303\263n", 0));
        cbNormalizationType->clear();
        cbNormalizationType->insertItems(0, QStringList()
         << QApplication::translate("NormalizationWidget", "Ninguna", 0)
         << QApplication::translate("NormalizationWidget", "Bipolar umbral fijo", 0)
         << QApplication::translate("NormalizationWidget", "Bipolar umbral automatico", 0)
         << QApplication::translate("NormalizationWidget", "Unipolar umbral fijo", 0)
         << QApplication::translate("NormalizationWidget", "Unipolar umbral automatico", 0)
         << QApplication::translate("NormalizationWidget", "Lineal rango fijo", 0)
         << QApplication::translate("NormalizationWidget", "Lineal rango automatico", 0)
         << QApplication::translate("NormalizationWidget", "Tangente Hiperbolica", 0)
         << QApplication::translate("NormalizationWidget", "Sigmoide", 0)
         << QApplication::translate("NormalizationWidget", "Distancia media", 0)
        );
        label->setText(QApplication::translate("NormalizationWidget", "Tipo", 0));
    } // retranslateUi

};

namespace Ui {
    class NormalizationWidget: public Ui_NormalizationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NORMALIZATIONWIDGET_H
