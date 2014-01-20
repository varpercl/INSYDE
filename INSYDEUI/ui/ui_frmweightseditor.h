/********************************************************************************
** Form generated from reading UI file 'frmweightseditor.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMWEIGHTSEDITOR_H
#define UI_FRMWEIGHTSEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmWeightsEditor
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *weightsTable;
    QDialogButtonBox *okCancelButtons;

    void setupUi(QWidget *frmWeightsEditor)
    {
        if (frmWeightsEditor->objectName().isEmpty())
            frmWeightsEditor->setObjectName(QStringLiteral("frmWeightsEditor"));
        frmWeightsEditor->resize(400, 300);
        verticalLayout = new QVBoxLayout(frmWeightsEditor);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        weightsTable = new QTableWidget(frmWeightsEditor);
        weightsTable->setObjectName(QStringLiteral("weightsTable"));

        verticalLayout->addWidget(weightsTable);

        okCancelButtons = new QDialogButtonBox(frmWeightsEditor);
        okCancelButtons->setObjectName(QStringLiteral("okCancelButtons"));
        okCancelButtons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(okCancelButtons);


        retranslateUi(frmWeightsEditor);

        QMetaObject::connectSlotsByName(frmWeightsEditor);
    } // setupUi

    void retranslateUi(QWidget *frmWeightsEditor)
    {
        frmWeightsEditor->setWindowTitle(QApplication::translate("frmWeightsEditor", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class frmWeightsEditor: public Ui_frmWeightsEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMWEIGHTSEDITOR_H
