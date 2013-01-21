/********************************************************************************
** Form generated from reading UI file 'newprojectwizard.ui'
**
** Created: Sat 19. Jan 16:02:31 2013
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROJECTWIZARD_H
#define UI_NEWPROJECTWIZARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWizard>

QT_BEGIN_NAMESPACE

class Ui_NewProjectWizard
{
public:

    void setupUi(QWizard *NewProjectWizard)
    {
        if (NewProjectWizard->objectName().isEmpty())
            NewProjectWizard->setObjectName(QStringLiteral("NewProjectWizard"));
        NewProjectWizard->resize(720, 450);
        NewProjectWizard->setModal(true);
        NewProjectWizard->setTitleFormat(Qt::RichText);
        NewProjectWizard->setSubTitleFormat(Qt::RichText);

        retranslateUi(NewProjectWizard);

        QMetaObject::connectSlotsByName(NewProjectWizard);
    } // setupUi

    void retranslateUi(QWizard *NewProjectWizard)
    {
        NewProjectWizard->setWindowTitle(QApplication::translate("NewProjectWizard", "Nuevo proyecto", 0));
    } // retranslateUi

};

namespace Ui {
    class NewProjectWizard: public Ui_NewProjectWizard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECTWIZARD_H
