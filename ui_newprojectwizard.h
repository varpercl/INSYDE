/********************************************************************************
** Form generated from reading UI file 'newprojectwizard.ui'
**
** Created: Thu 17. Jan 19:30:36 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROJECTWIZARD_H
#define UI_NEWPROJECTWIZARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWizard>

QT_BEGIN_NAMESPACE

class Ui_NewProjectWizard
{
public:

    void setupUi(QWizard *NewProjectWizard)
    {
        if (NewProjectWizard->objectName().isEmpty())
            NewProjectWizard->setObjectName(QString::fromUtf8("NewProjectWizard"));
        NewProjectWizard->resize(720, 450);
        NewProjectWizard->setModal(true);
        NewProjectWizard->setTitleFormat(Qt::RichText);
        NewProjectWizard->setSubTitleFormat(Qt::RichText);

        retranslateUi(NewProjectWizard);

        QMetaObject::connectSlotsByName(NewProjectWizard);
    } // setupUi

    void retranslateUi(QWizard *NewProjectWizard)
    {
        NewProjectWizard->setWindowTitle(QApplication::translate("NewProjectWizard", "Nuevo proyecto", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewProjectWizard: public Ui_NewProjectWizard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECTWIZARD_H
