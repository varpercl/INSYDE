/********************************************************************************
** Form generated from reading UI file 'diagramtypedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIAGRAMTYPEDIALOG_H
#define UI_DIAGRAMTYPEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DiagramTypeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *typeSelector;
    QLabel *label_2;
    QComboBox *subtypeSelector;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *DiagramTypeDialog)
    {
        if (DiagramTypeDialog->objectName().isEmpty())
            DiagramTypeDialog->setObjectName(QStringLiteral("DiagramTypeDialog"));
        DiagramTypeDialog->resize(400, 98);
        verticalLayout = new QVBoxLayout(DiagramTypeDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(DiagramTypeDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        typeSelector = new QComboBox(DiagramTypeDialog);
        typeSelector->setObjectName(QStringLiteral("typeSelector"));

        verticalLayout->addWidget(typeSelector);

        label_2 = new QLabel(DiagramTypeDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        subtypeSelector = new QComboBox(DiagramTypeDialog);
        subtypeSelector->setObjectName(QStringLiteral("subtypeSelector"));

        verticalLayout->addWidget(subtypeSelector);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(DiagramTypeDialog);

        QMetaObject::connectSlotsByName(DiagramTypeDialog);
    } // setupUi

    void retranslateUi(QDialog *DiagramTypeDialog)
    {
        DiagramTypeDialog->setWindowTitle(QApplication::translate("DiagramTypeDialog", "Dialog", 0));
        label->setText(QApplication::translate("DiagramTypeDialog", "Diagram type", 0));
        label_2->setText(QApplication::translate("DiagramTypeDialog", "Diagram subtype", 0));
    } // retranslateUi

};

namespace Ui {
    class DiagramTypeDialog: public Ui_DiagramTypeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAGRAMTYPEDIALOG_H
