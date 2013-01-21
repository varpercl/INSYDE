/********************************************************************************
** Form generated from reading UI file 'samplesdialog.ui'
**
** Created: Sat 19. Jan 16:02:31 2013
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAMPLESDIALOG_H
#define UI_SAMPLESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

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
            SamplesDialog->setObjectName(QStringLiteral("SamplesDialog"));
        SamplesDialog->resize(240, 98);
        verticalLayout = new QVBoxLayout(SamplesDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(SamplesDialog);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        sbNSamples = new QSpinBox(SamplesDialog);
        sbNSamples->setObjectName(QStringLiteral("sbNSamples"));

        formLayout->setWidget(0, QFormLayout::FieldRole, sbNSamples);


        verticalLayout->addLayout(formLayout);

        cbAllSamples = new QCheckBox(SamplesDialog);
        cbAllSamples->setObjectName(QStringLiteral("cbAllSamples"));
        cbAllSamples->setChecked(false);

        verticalLayout->addWidget(cbAllSamples);

        buttonBox = new QDialogButtonBox(SamplesDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
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
        SamplesDialog->setWindowTitle(QApplication::translate("SamplesDialog", "Dialog", 0));
        label->setText(QApplication::translate("SamplesDialog", "N\302\260 de muestras", 0));
        cbAllSamples->setText(QApplication::translate("SamplesDialog", "Todas las muestras", 0));
    } // retranslateUi

};

namespace Ui {
    class SamplesDialog: public Ui_SamplesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAMPLESDIALOG_H
