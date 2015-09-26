/********************************************************************************
** Form generated from reading UI file 'entrydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTRYDIALOG_H
#define UI_ENTRYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EntryDialog
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *label;
    QLineEdit *name;
    QHBoxLayout *hboxLayout1;
    QLabel *label_6;
    QLineEdit *legend;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QComboBox *type;
    QSpacerItem *spacerItem;
    QLabel *label_3;
    QDateTimeEdit *startDate;
    QLabel *label_5;
    QSpinBox *completion;
    QLabel *label_4;
    QDateTimeEdit *endDate;
    QCheckBox *readOnly;
    QLabel *dependsLabel;
    QComboBox *depends;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EntryDialog)
    {
        if (EntryDialog->objectName().isEmpty())
            EntryDialog->setObjectName(QStringLiteral("EntryDialog"));
        EntryDialog->resize(439, 171);
        vboxLayout = new QVBoxLayout(EntryDialog);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        label = new QLabel(EntryDialog);
        label->setObjectName(QStringLiteral("label"));

        hboxLayout->addWidget(label);

        name = new QLineEdit(EntryDialog);
        name->setObjectName(QStringLiteral("name"));

        hboxLayout->addWidget(name);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        label_6 = new QLabel(EntryDialog);
        label_6->setObjectName(QStringLiteral("label_6"));

        hboxLayout1->addWidget(label_6);

        legend = new QLineEdit(EntryDialog);
        legend->setObjectName(QStringLiteral("legend"));

        hboxLayout1->addWidget(legend);


        vboxLayout->addLayout(hboxLayout1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(EntryDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        type = new QComboBox(EntryDialog);
        type->setObjectName(QStringLiteral("type"));

        gridLayout->addWidget(type, 0, 1, 1, 1);

        spacerItem = new QSpacerItem(41, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 0, 2, 1, 1);

        label_3 = new QLabel(EntryDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        startDate = new QDateTimeEdit(EntryDialog);
        startDate->setObjectName(QStringLiteral("startDate"));
        startDate->setCalendarPopup(true);

        gridLayout->addWidget(startDate, 0, 4, 1, 1);

        label_5 = new QLabel(EntryDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        completion = new QSpinBox(EntryDialog);
        completion->setObjectName(QStringLiteral("completion"));
        completion->setMaximum(100);

        gridLayout->addWidget(completion, 1, 1, 1, 1);

        label_4 = new QLabel(EntryDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 3, 1, 1);

        endDate = new QDateTimeEdit(EntryDialog);
        endDate->setObjectName(QStringLiteral("endDate"));
        endDate->setCalendarPopup(true);

        gridLayout->addWidget(endDate, 1, 4, 1, 1);

        readOnly = new QCheckBox(EntryDialog);
        readOnly->setObjectName(QStringLiteral("readOnly"));

        gridLayout->addWidget(readOnly, 2, 0, 1, 2);

        dependsLabel = new QLabel(EntryDialog);
        dependsLabel->setObjectName(QStringLiteral("dependsLabel"));

        gridLayout->addWidget(dependsLabel, 2, 3, 1, 1);

        depends = new QComboBox(EntryDialog);
        depends->setObjectName(QStringLiteral("depends"));

        gridLayout->addWidget(depends, 2, 4, 1, 1);


        vboxLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(EntryDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);


        retranslateUi(EntryDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EntryDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EntryDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EntryDialog);
    } // setupUi

    void retranslateUi(QDialog *EntryDialog)
    {
        label->setText(QApplication::translate("EntryDialog", "Name:", 0));
        label_6->setText(QApplication::translate("EntryDialog", "Legend:", 0));
        label_2->setText(QApplication::translate("EntryDialog", "Type:", 0));
        label_3->setText(QApplication::translate("EntryDialog", "Start date:", 0));
        label_5->setText(QApplication::translate("EntryDialog", "Completion:", 0));
        completion->setSuffix(QApplication::translate("EntryDialog", "%", 0));
        label_4->setText(QApplication::translate("EntryDialog", "End date:", 0));
        readOnly->setText(QApplication::translate("EntryDialog", "Read Only", 0));
        dependsLabel->setText(QApplication::translate("EntryDialog", "Depends on:", 0));
        depends->clear();
        depends->insertItems(0, QStringList()
         << QApplication::translate("EntryDialog", "- None -", 0)
        );
        Q_UNUSED(EntryDialog);
    } // retranslateUi

};

namespace Ui {
    class EntryDialog: public Ui_EntryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTRYDIALOG_H
