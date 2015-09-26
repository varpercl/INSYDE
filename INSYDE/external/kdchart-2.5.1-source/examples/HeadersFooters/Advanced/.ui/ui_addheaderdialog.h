/********************************************************************************
** Form generated from reading UI file 'addheaderdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDHEADERDIALOG_H
#define UI_ADDHEADERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddHeaderDialog
{
public:
    QVBoxLayout *vboxLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *textED;
    QComboBox *positionCO;
    QLabel *label_3;
    QComboBox *typeCO;
    QLabel *label;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *AddHeaderDialog)
    {
        if (AddHeaderDialog->objectName().isEmpty())
            AddHeaderDialog->setObjectName(QStringLiteral("AddHeaderDialog"));
        AddHeaderDialog->resize(333, 142);
        vboxLayout = new QVBoxLayout(AddHeaderDialog);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        gridLayout = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(0, 0, 0, 0);
#endif
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(AddHeaderDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        textED = new QLineEdit(AddHeaderDialog);
        textED->setObjectName(QStringLiteral("textED"));

        gridLayout->addWidget(textED, 0, 1, 1, 1);

        positionCO = new QComboBox(AddHeaderDialog);
        positionCO->setObjectName(QStringLiteral("positionCO"));

        gridLayout->addWidget(positionCO, 1, 1, 1, 1);

        label_3 = new QLabel(AddHeaderDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        typeCO = new QComboBox(AddHeaderDialog);
        typeCO->setObjectName(QStringLiteral("typeCO"));

        gridLayout->addWidget(typeCO, 2, 1, 1, 1);

        label = new QLabel(AddHeaderDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        vboxLayout->addLayout(gridLayout);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(AddHeaderDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(AddHeaderDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);


        vboxLayout->addLayout(hboxLayout);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(positionCO);
        label_3->setBuddy(typeCO);
        label->setBuddy(textED);
#endif // QT_NO_SHORTCUT

        retranslateUi(AddHeaderDialog);
        QObject::connect(okButton, SIGNAL(clicked()), AddHeaderDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), AddHeaderDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddHeaderDialog);
    } // setupUi

    void retranslateUi(QDialog *AddHeaderDialog)
    {
        AddHeaderDialog->setWindowTitle(QApplication::translate("AddHeaderDialog", "Dialog", 0));
        label_2->setText(QApplication::translate("AddHeaderDialog", "&Position", 0));
        textED->setText(QString());
        label_3->setText(QApplication::translate("AddHeaderDialog", "T&ype", 0));
        typeCO->clear();
        typeCO->insertItems(0, QStringList()
         << QApplication::translate("AddHeaderDialog", "Header", 0)
         << QApplication::translate("AddHeaderDialog", "Footer", 0)
        );
        label->setText(QApplication::translate("AddHeaderDialog", "&Text", 0));
        okButton->setText(QApplication::translate("AddHeaderDialog", "&OK", 0));
        cancelButton->setText(QApplication::translate("AddHeaderDialog", "&Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class AddHeaderDialog: public Ui_AddHeaderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDHEADERDIALOG_H
