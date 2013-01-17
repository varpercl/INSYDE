/********************************************************************************
** Form generated from reading UI file 'defineruledialog.ui'
**
** Created: Mon 14. Jan 16:23:14 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFINERULEDIALOG_H
#define UI_DEFINERULEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QPushButton>

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
            DefineRuleDialog->setObjectName(QString::fromUtf8("DefineRuleDialog"));
        DefineRuleDialog->resize(689, 330);
        pushButton = new QPushButton(DefineRuleDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(600, 10, 75, 23));
        pushButton_2 = new QPushButton(DefineRuleDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(600, 130, 75, 23));
        pushButton_3 = new QPushButton(DefineRuleDialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(600, 40, 75, 23));
        pushButton_4 = new QPushButton(DefineRuleDialog);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(600, 70, 75, 23));
        pushButton_5 = new QPushButton(DefineRuleDialog);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(600, 100, 75, 23));
        listView = new QListView(DefineRuleDialog);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 10, 581, 192));

        retranslateUi(DefineRuleDialog);

        QMetaObject::connectSlotsByName(DefineRuleDialog);
    } // setupUi

    void retranslateUi(QDialog *DefineRuleDialog)
    {
        DefineRuleDialog->setWindowTitle(QApplication::translate("DefineRuleDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("DefineRuleDialog", "Nueva Regla", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("DefineRuleDialog", "Eliminar", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("DefineRuleDialog", "Editar", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("DefineRuleDialog", "Subir", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("DefineRuleDialog", "Bajar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DefineRuleDialog: public Ui_DefineRuleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFINERULEDIALOG_H
