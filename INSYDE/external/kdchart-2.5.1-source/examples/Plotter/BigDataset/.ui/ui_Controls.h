/********************************************************************************
** Form generated from reading UI file 'Controls.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLS_H
#define UI_CONTROLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Controls
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QRadioButton *sineRadio;
    QRadioButton *triangleRadio;
    QRadioButton *squareRadio;
    QRadioButton *noiseRadio;
    QRadioButton *oneDivSineRadio;
    QRadioButton *sineOneDivRadio;
    QSpacerItem *verticalSpacer;
    QPushButton *runButton;
    QSpacerItem *verticalSpacer_3;
    QPushButton *add1kButton;
    QPushButton *add10kButton;
    QPushButton *add100kButton;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Controls)
    {
        if (Controls->objectName().isEmpty())
            Controls->setObjectName(QStringLiteral("Controls"));
        Controls->resize(150, 393);
        verticalLayout = new QVBoxLayout(Controls);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(Controls);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        sineRadio = new QRadioButton(Controls);
        sineRadio->setObjectName(QStringLiteral("sineRadio"));
        sineRadio->setChecked(true);

        verticalLayout->addWidget(sineRadio);

        triangleRadio = new QRadioButton(Controls);
        triangleRadio->setObjectName(QStringLiteral("triangleRadio"));

        verticalLayout->addWidget(triangleRadio);

        squareRadio = new QRadioButton(Controls);
        squareRadio->setObjectName(QStringLiteral("squareRadio"));

        verticalLayout->addWidget(squareRadio);

        noiseRadio = new QRadioButton(Controls);
        noiseRadio->setObjectName(QStringLiteral("noiseRadio"));

        verticalLayout->addWidget(noiseRadio);

        oneDivSineRadio = new QRadioButton(Controls);
        oneDivSineRadio->setObjectName(QStringLiteral("oneDivSineRadio"));

        verticalLayout->addWidget(oneDivSineRadio);

        sineOneDivRadio = new QRadioButton(Controls);
        sineOneDivRadio->setObjectName(QStringLiteral("sineOneDivRadio"));

        verticalLayout->addWidget(sineOneDivRadio);

        verticalSpacer = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        runButton = new QPushButton(Controls);
        runButton->setObjectName(QStringLiteral("runButton"));
        runButton->setCheckable(true);
        runButton->setChecked(false);

        verticalLayout->addWidget(runButton);

        verticalSpacer_3 = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        add1kButton = new QPushButton(Controls);
        add1kButton->setObjectName(QStringLiteral("add1kButton"));

        verticalLayout->addWidget(add1kButton);

        add10kButton = new QPushButton(Controls);
        add10kButton->setObjectName(QStringLiteral("add10kButton"));

        verticalLayout->addWidget(add10kButton);

        add100kButton = new QPushButton(Controls);
        add100kButton->setObjectName(QStringLiteral("add100kButton"));

        verticalLayout->addWidget(add100kButton);

        verticalSpacer_2 = new QSpacerItem(20, 37, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(Controls);

        QMetaObject::connectSlotsByName(Controls);
    } // setupUi

    void retranslateUi(QWidget *Controls)
    {
        Controls->setWindowTitle(QApplication::translate("Controls", "Form", 0));
        label->setText(QApplication::translate("Controls", "Function", 0));
        sineRadio->setText(QApplication::translate("Controls", "Sine", 0));
        triangleRadio->setText(QApplication::translate("Controls", "Triangle", 0));
        squareRadio->setText(QApplication::translate("Controls", "Square", 0));
        noiseRadio->setText(QApplication::translate("Controls", "Noise", 0));
        oneDivSineRadio->setText(QApplication::translate("Controls", "1 / sin(x)", 0));
        sineOneDivRadio->setText(QApplication::translate("Controls", "sin(1 / x)", 0));
        runButton->setText(QApplication::translate("Controls", "Run", 0));
        add1kButton->setText(QApplication::translate("Controls", "Add 1000 points", 0));
        add10kButton->setText(QApplication::translate("Controls", "Add 10k points", 0));
        add100kButton->setText(QApplication::translate("Controls", "Add 100k points", 0));
    } // retranslateUi

};

namespace Ui {
    class Controls: public Ui_Controls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLS_H
