/********************************************************************************
** Form generated from reading UI file 'dotmatrixelementpropertydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOTMATRIXELEMENTPROPERTYDIALOG_H
#define UI_DOTMATRIXELEMENTPROPERTYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DotMatrixElementPropertyDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DotMatrixElementPropertyDialog)
    {
        if (DotMatrixElementPropertyDialog->objectName().isEmpty())
            DotMatrixElementPropertyDialog->setObjectName(QStringLiteral("DotMatrixElementPropertyDialog"));
        DotMatrixElementPropertyDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(DotMatrixElementPropertyDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DotMatrixElementPropertyDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DotMatrixElementPropertyDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DotMatrixElementPropertyDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DotMatrixElementPropertyDialog);
    } // setupUi

    void retranslateUi(QDialog *DotMatrixElementPropertyDialog)
    {
        DotMatrixElementPropertyDialog->setWindowTitle(QApplication::translate("DotMatrixElementPropertyDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class DotMatrixElementPropertyDialog: public Ui_DotMatrixElementPropertyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOTMATRIXELEMENTPROPERTYDIALOG_H
