/********************************************************************************
** Form generated from reading UI file 'adddotmatrixdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDOTMATRIXDIALOG_H
#define UI_ADDDOTMATRIXDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddDotMatrixDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *sbRowSize;
    QLabel *label_2;
    QSpinBox *sbColSize;
    QLabel *label_3;
    QComboBox *cbDataType;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddDotMatrixDialog)
    {
        if (AddDotMatrixDialog->objectName().isEmpty())
            AddDotMatrixDialog->setObjectName(QStringLiteral("AddDotMatrixDialog"));
        AddDotMatrixDialog->resize(198, 123);
        verticalLayout = new QVBoxLayout(AddDotMatrixDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(AddDotMatrixDialog);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        sbRowSize = new QSpinBox(AddDotMatrixDialog);
        sbRowSize->setObjectName(QStringLiteral("sbRowSize"));
        sbRowSize->setMaximum(999);
        sbRowSize->setValue(5);

        formLayout->setWidget(0, QFormLayout::FieldRole, sbRowSize);

        label_2 = new QLabel(AddDotMatrixDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        sbColSize = new QSpinBox(AddDotMatrixDialog);
        sbColSize->setObjectName(QStringLiteral("sbColSize"));
        sbColSize->setMaximum(999);
        sbColSize->setValue(5);

        formLayout->setWidget(1, QFormLayout::FieldRole, sbColSize);

        label_3 = new QLabel(AddDotMatrixDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        cbDataType = new QComboBox(AddDotMatrixDialog);
        cbDataType->setObjectName(QStringLiteral("cbDataType"));

        formLayout->setWidget(2, QFormLayout::FieldRole, cbDataType);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(AddDotMatrixDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AddDotMatrixDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddDotMatrixDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddDotMatrixDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddDotMatrixDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDotMatrixDialog)
    {
        AddDotMatrixDialog->setWindowTitle(QApplication::translate("AddDotMatrixDialog", "Dialog", 0));
        label->setText(QApplication::translate("AddDotMatrixDialog", "Filas", 0));
        label_2->setText(QApplication::translate("AddDotMatrixDialog", "Columnas", 0));
        label_3->setText(QApplication::translate("AddDotMatrixDialog", "Tipo de datos", 0));
        cbDataType->clear();
        cbDataType->insertItems(0, QStringList()
         << QApplication::translate("AddDotMatrixDialog", "Unipolar", 0)
         << QApplication::translate("AddDotMatrixDialog", "Bipolar", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class AddDotMatrixDialog: public Ui_AddDotMatrixDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDOTMATRIXDIALOG_H
