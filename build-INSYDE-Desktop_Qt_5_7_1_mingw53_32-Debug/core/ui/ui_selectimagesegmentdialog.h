/********************************************************************************
** Form generated from reading UI file 'selectimagesegmentdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTIMAGESEGMENTDIALOG_H
#define UI_SELECTIMAGESEGMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SelectImageSegmentDialog
{
public:
    QVBoxLayout *verticalLayout;
    QDialogButtonBox *dbbOkCancel;

    void setupUi(QDialog *SelectImageSegmentDialog)
    {
        if (SelectImageSegmentDialog->objectName().isEmpty())
            SelectImageSegmentDialog->setObjectName(QStringLiteral("SelectImageSegmentDialog"));
        SelectImageSegmentDialog->resize(500, 500);
        verticalLayout = new QVBoxLayout(SelectImageSegmentDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        dbbOkCancel = new QDialogButtonBox(SelectImageSegmentDialog);
        dbbOkCancel->setObjectName(QStringLiteral("dbbOkCancel"));
        dbbOkCancel->setOrientation(Qt::Horizontal);
        dbbOkCancel->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(dbbOkCancel);


        retranslateUi(SelectImageSegmentDialog);
        QObject::connect(dbbOkCancel, SIGNAL(accepted()), SelectImageSegmentDialog, SLOT(accept()));
        QObject::connect(dbbOkCancel, SIGNAL(rejected()), SelectImageSegmentDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SelectImageSegmentDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectImageSegmentDialog)
    {
        SelectImageSegmentDialog->setWindowTitle(QApplication::translate("SelectImageSegmentDialog", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SelectImageSegmentDialog: public Ui_SelectImageSegmentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTIMAGESEGMENTDIALOG_H
