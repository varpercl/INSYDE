/********************************************************************************
** Form generated from reading UI file 'defineruledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFINERULEDIALOG_H
#define UI_DEFINERULEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DefineRuleDialog
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QListView *listView;

    void setupUi(QDialog *DefineRuleDialog)
    {
        if (DefineRuleDialog->objectName().isEmpty())
            DefineRuleDialog->setObjectName(QStringLiteral("DefineRuleDialog"));
        DefineRuleDialog->resize(689, 330);
        pushButton = new QPushButton(DefineRuleDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(600, 10, 75, 23));
        pushButton_2 = new QPushButton(DefineRuleDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(600, 130, 75, 23));
        pushButton_3 = new QPushButton(DefineRuleDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(600, 40, 75, 23));
        pushButton_4 = new QPushButton(DefineRuleDialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(600, 70, 75, 23));
        pushButton_5 = new QPushButton(DefineRuleDialog);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(600, 100, 75, 23));
        listView = new QListView(DefineRuleDialog);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(10, 10, 581, 192));

        retranslateUi(DefineRuleDialog);

        QMetaObject::connectSlotsByName(DefineRuleDialog);
    } // setupUi

    void retranslateUi(QDialog *DefineRuleDialog)
    {
        DefineRuleDialog->setWindowTitle(QApplication::translate("DefineRuleDialog", "Dialog", 0));
        pushButton->setText(QApplication::translate("DefineRuleDialog", "Nueva Regla", 0));
        pushButton_2->setText(QApplication::translate("DefineRuleDialog", "Eliminar", 0));
        pushButton_3->setText(QApplication::translate("DefineRuleDialog", "Editar", 0));
        pushButton_4->setText(QApplication::translate("DefineRuleDialog", "Subir", 0));
        pushButton_5->setText(QApplication::translate("DefineRuleDialog", "Bajar", 0));
    } // retranslateUi

};

namespace Ui {
    class DefineRuleDialog: public Ui_DefineRuleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFINERULEDIALOG_H
