/********************************************************************************
** Form generated from reading UI file 'addlegenddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDLEGENDDIALOG_H
#define UI_ADDLEGENDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_AddLegendDialog
{
public:
    QGridLayout *gridLayout;
    QComboBox *styleCO;
    QLabel *styleLB;
    QCheckBox *showLinesCB;
    QLabel *label_2;
    QLineEdit *titleTextED;
    QLabel *label_3;
    QComboBox *orientationCO;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QComboBox *positionCO;
    QComboBox *alignmentCO;
    QLabel *label;
    QLabel *label_4;

    void setupUi(QDialog *AddLegendDialog)
    {
        if (AddLegendDialog->objectName().isEmpty())
            AddLegendDialog->setObjectName(QStringLiteral("AddLegendDialog"));
        AddLegendDialog->resize(355, 232);
        gridLayout = new QGridLayout(AddLegendDialog);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        styleCO = new QComboBox(AddLegendDialog);
        styleCO->setObjectName(QStringLiteral("styleCO"));

        gridLayout->addWidget(styleCO, 2, 1, 1, 1);

        styleLB = new QLabel(AddLegendDialog);
        styleLB->setObjectName(QStringLiteral("styleLB"));

        gridLayout->addWidget(styleLB, 2, 0, 1, 1);

        showLinesCB = new QCheckBox(AddLegendDialog);
        showLinesCB->setObjectName(QStringLiteral("showLinesCB"));

        gridLayout->addWidget(showLinesCB, 3, 0, 1, 1);

        label_2 = new QLabel(AddLegendDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        titleTextED = new QLineEdit(AddLegendDialog);
        titleTextED->setObjectName(QStringLiteral("titleTextED"));

        gridLayout->addWidget(titleTextED, 4, 1, 1, 1);

        label_3 = new QLabel(AddLegendDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        orientationCO = new QComboBox(AddLegendDialog);
        orientationCO->setObjectName(QStringLiteral("orientationCO"));

        gridLayout->addWidget(orientationCO, 5, 1, 1, 1);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(AddLegendDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(AddLegendDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);


        gridLayout->addLayout(hboxLayout, 6, 0, 1, 2);

        positionCO = new QComboBox(AddLegendDialog);
        positionCO->setObjectName(QStringLiteral("positionCO"));

        gridLayout->addWidget(positionCO, 0, 1, 1, 1);

        alignmentCO = new QComboBox(AddLegendDialog);
        alignmentCO->setObjectName(QStringLiteral("alignmentCO"));

        gridLayout->addWidget(alignmentCO, 1, 1, 1, 1);

        label = new QLabel(AddLegendDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(AddLegendDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);


        retranslateUi(AddLegendDialog);
        QObject::connect(okButton, SIGNAL(clicked()), AddLegendDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), AddLegendDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddLegendDialog);
    } // setupUi

    void retranslateUi(QDialog *AddLegendDialog)
    {
        AddLegendDialog->setWindowTitle(QApplication::translate("AddLegendDialog", "Dialog", 0));
        styleCO->clear();
        styleCO->insertItems(0, QStringList()
         << QApplication::translate("AddLegendDialog", "MarkersOnly", 0)
         << QApplication::translate("AddLegendDialog", "LinesOnly", 0)
         << QApplication::translate("AddLegendDialog", "MarkersAndLines", 0)
        );
        styleLB->setText(QApplication::translate("AddLegendDialog", "Style", 0));
        showLinesCB->setText(QApplication::translate("AddLegendDialog", "Show lines", 0));
        label_2->setText(QApplication::translate("AddLegendDialog", "Title Text", 0));
        label_3->setText(QApplication::translate("AddLegendDialog", "Orientation", 0));
        orientationCO->clear();
        orientationCO->insertItems(0, QStringList()
         << QApplication::translate("AddLegendDialog", "Vertical", 0)
         << QApplication::translate("AddLegendDialog", "Horizontal", 0)
        );
        okButton->setText(QApplication::translate("AddLegendDialog", "OK", 0));
        cancelButton->setText(QApplication::translate("AddLegendDialog", "Cancel", 0));
        label->setText(QApplication::translate("AddLegendDialog", "Position", 0));
        label_4->setText(QApplication::translate("AddLegendDialog", "Alignment", 0));
    } // retranslateUi

};

namespace Ui {
    class AddLegendDialog: public Ui_AddLegendDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDLEGENDDIALOG_H
