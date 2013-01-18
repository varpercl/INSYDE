/********************************************************************************
** Form generated from reading UI file 'samplesdialog.ui'
**
** Created: Thu 17. Jan 19:30:36 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAMPLESDIALOG_H
#define UI_SAMPLESDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SamplesDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *sbNSamples;
    QCheckBox *cbAllSamples;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SamplesDialog)
    {
        if (SamplesDialog->objectName().isEmpty())
            SamplesDialog->setObjectName(QString::fromUtf8("SamplesDialog"));
        SamplesDialog->resize(240, 98);
        verticalLayout = new QVBoxLayout(SamplesDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(SamplesDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        sbNSamples = new QSpinBox(SamplesDialog);
        sbNSamples->setObjectName(QString::fromUtf8("sbNSamples"));

        formLayout->setWidget(0, QFormLayout::FieldRole, sbNSamples);


        verticalLayout->addLayout(formLayout);

        cbAllSamples = new QCheckBox(SamplesDialog);
        cbAllSamples->setObjectName(QString::fromUtf8("cbAllSamples"));
        cbAllSamples->setChecked(false);

        verticalLayout->addWidget(cbAllSamples);

        buttonBox = new QDialogButtonBox(SamplesDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SamplesDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SamplesDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SamplesDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SamplesDialog);
    } // setupUi

    void retranslateUi(QDialog *SamplesDialog)
    {
        SamplesDialog->setWindowTitle(QApplication::translate("SamplesDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SamplesDialog", "N\302\260 de muestras", 0, QApplication::UnicodeUTF8));
        cbAllSamples->setText(QApplication::translate("SamplesDialog", "Todas las muestras", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SamplesDialog: public Ui_SamplesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAMPLESDIALOG_H
