/********************************************************************************
** Form generated from reading UI file 'gbgraphicrepresentation.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GBGRAPHICREPRESENTATION_H
#define UI_GBGRAPHICREPRESENTATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_gbGraphicRepresentation
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QComboBox *comboBox;
    QLabel *label_5;

    void setupUi(QGroupBox *gbGraphicRepresentation)
    {
        if (gbGraphicRepresentation->objectName().isEmpty())
            gbGraphicRepresentation->setObjectName(QStringLiteral("gbGraphicRepresentation"));
        gbGraphicRepresentation->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gbGraphicRepresentation->sizePolicy().hasHeightForWidth());
        gbGraphicRepresentation->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(gbGraphicRepresentation);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        comboBox = new QComboBox(gbGraphicRepresentation);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox);

        label_5 = new QLabel(gbGraphicRepresentation);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);


        verticalLayout->addLayout(formLayout);


        retranslateUi(gbGraphicRepresentation);

        QMetaObject::connectSlotsByName(gbGraphicRepresentation);
    } // setupUi

    void retranslateUi(QGroupBox *gbGraphicRepresentation)
    {
        gbGraphicRepresentation->setWindowTitle(QApplication::translate("gbGraphicRepresentation", "GroupBox", 0));
        gbGraphicRepresentation->setTitle(QApplication::translate("gbGraphicRepresentation", "GroupBox", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("gbGraphicRepresentation", "Imagen", 0)
         << QApplication::translate("gbGraphicRepresentation", "Matriz de puntos", 0)
         << QApplication::translate("gbGraphicRepresentation", "Audio", 0)
         << QApplication::translate("gbGraphicRepresentation", "Grafica", 0)
        );
        label_5->setText(QApplication::translate("gbGraphicRepresentation", "Representar como", 0));
    } // retranslateUi

};

namespace Ui {
    class gbGraphicRepresentation: public Ui_gbGraphicRepresentation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GBGRAPHICREPRESENTATION_H
