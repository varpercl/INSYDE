/********************************************************************************
** Form generated from reading UI file 'chooseprojectnamepage.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEPROJECTNAMEPAGE_H
#define UI_CHOOSEPROJECTNAMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseProjectNamePage
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QFrame *line;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_3;
    QLabel *label_23;
    QLabel *label_24;
    QLineEdit *lineEdit_4;
    QLabel *label_25;
    QLineEdit *lineEdit_5;
    QToolButton *toolButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ChooseProjectNamePage)
    {
        if (ChooseProjectNamePage->objectName().isEmpty())
            ChooseProjectNamePage->setObjectName(QStringLiteral("ChooseProjectNamePage"));
        ChooseProjectNamePage->resize(426, 374);
        verticalLayout_2 = new QVBoxLayout(ChooseProjectNamePage);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(ChooseProjectNamePage);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setScaledContents(false);

        verticalLayout_2->addWidget(label);

        line = new QFrame(ChooseProjectNamePage);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_3 = new QLineEdit(ChooseProjectNamePage);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        label_23 = new QLabel(ChooseProjectNamePage);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout->addWidget(label_23, 2, 0, 1, 1);

        label_24 = new QLabel(ChooseProjectNamePage);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout->addWidget(label_24, 4, 0, 1, 1);

        lineEdit_4 = new QLineEdit(ChooseProjectNamePage);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 4, 1, 1, 1);

        label_25 = new QLabel(ChooseProjectNamePage);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout->addWidget(label_25, 10, 0, 1, 1);

        lineEdit_5 = new QLineEdit(ChooseProjectNamePage);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 10, 1, 1, 1);

        toolButton = new QToolButton(ChooseProjectNamePage);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        gridLayout->addWidget(toolButton, 4, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 10, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        retranslateUi(ChooseProjectNamePage);

        QMetaObject::connectSlotsByName(ChooseProjectNamePage);
    } // setupUi

    void retranslateUi(QWidget *ChooseProjectNamePage)
    {
        ChooseProjectNamePage->setWindowTitle(QApplication::translate("ChooseProjectNamePage", "Form", 0));
        label->setText(QApplication::translate("ChooseProjectNamePage", "Nombre y ubicaci\303\263n", 0));
        label_23->setText(QApplication::translate("ChooseProjectNamePage", "Nombre", 0));
        label_24->setText(QApplication::translate("ChooseProjectNamePage", "Carpeta", 0));
        label_25->setText(QApplication::translate("ChooseProjectNamePage", "Ruta final", 0));
        toolButton->setText(QApplication::translate("ChooseProjectNamePage", "Explorar...", 0));
    } // retranslateUi

};

namespace Ui {
    class ChooseProjectNamePage: public Ui_ChooseProjectNamePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEPROJECTNAMEPAGE_H
