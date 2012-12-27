/********************************************************************************
** Form generated from reading UI file 'aco.ui'
**
** Created: Sun 23. Dec 16:47:31 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACO_H
#define UI_ACO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ACO
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QGraphicsView *graph;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *nAnts;
    QLabel *label_2;
    QSpinBox *nIterations;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnCalculate;
    QPushButton *btnReset;
    QPushButton *btnExit;

    void setupUi(QDialog *ACO)
    {
        if (ACO->objectName().isEmpty())
            ACO->setObjectName(QString::fromUtf8("ACO"));
        ACO->resize(647, 422);
        verticalLayoutWidget = new QWidget(ACO);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 611, 401));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        graph = new QGraphicsView(verticalLayoutWidget);
        graph->setObjectName(QString::fromUtf8("graph"));

        horizontalLayout_3->addWidget(graph);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        nAnts = new QSpinBox(verticalLayoutWidget);
        nAnts->setObjectName(QString::fromUtf8("nAnts"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nAnts);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        nIterations = new QSpinBox(verticalLayoutWidget);
        nIterations->setObjectName(QString::fromUtf8("nIterations"));

        formLayout->setWidget(1, QFormLayout::FieldRole, nIterations);


        horizontalLayout_3->addLayout(formLayout);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnCalculate = new QPushButton(verticalLayoutWidget);
        btnCalculate->setObjectName(QString::fromUtf8("btnCalculate"));

        horizontalLayout_2->addWidget(btnCalculate);

        btnReset = new QPushButton(verticalLayoutWidget);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));

        horizontalLayout_2->addWidget(btnReset);

        btnExit = new QPushButton(verticalLayoutWidget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        horizontalLayout_2->addWidget(btnExit);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(ACO);

        QMetaObject::connectSlotsByName(ACO);
    } // setupUi

    void retranslateUi(QDialog *ACO)
    {
        ACO->setWindowTitle(QApplication::translate("ACO", "ACO", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ACO", "N\302\260 Hormigas", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ACO", "N\302\260 Iteraciones", 0, QApplication::UnicodeUTF8));
        btnCalculate->setText(QApplication::translate("ACO", "Calcular", 0, QApplication::UnicodeUTF8));
        btnReset->setText(QApplication::translate("ACO", "Resetear", 0, QApplication::UnicodeUTF8));
        btnExit->setText(QApplication::translate("ACO", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ACO: public Ui_ACO {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACO_H
