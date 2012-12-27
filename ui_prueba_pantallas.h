/********************************************************************************
** Form generated from reading UI file 'prueba_pantallas.ui'
**
** Created: Sun 23. Dec 16:47:31 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRUEBA_PANTALLAS_H
#define UI_PRUEBA_PANTALLAS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PruebaPantalla
{
public:
    QGridLayout *gridLayout;
    QPushButton *acoButton;
    QPushButton *chooseProjectNameButton;
    QPushButton *selectProjectButton;
    QPushButton *trainingSetButton;
    QPushButton *perceptronButton;
    QPushButton *addAgentsButton;
    QPushButton *adalineButton;
    QPushButton *hopfieldButton;
    QPushButton *newProjectButton;
    QPushButton *mainWindowButton;
    QPushButton *systemButton;
    QPushButton *pushButton;

    void setupUi(QWidget *PruebaPantalla)
    {
        if (PruebaPantalla->objectName().isEmpty())
            PruebaPantalla->setObjectName(QString::fromUtf8("PruebaPantalla"));
        PruebaPantalla->resize(400, 300);
        gridLayout = new QGridLayout(PruebaPantalla);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        acoButton = new QPushButton(PruebaPantalla);
        acoButton->setObjectName(QString::fromUtf8("acoButton"));

        gridLayout->addWidget(acoButton, 0, 0, 1, 1);

        chooseProjectNameButton = new QPushButton(PruebaPantalla);
        chooseProjectNameButton->setObjectName(QString::fromUtf8("chooseProjectNameButton"));

        gridLayout->addWidget(chooseProjectNameButton, 3, 0, 1, 1);

        selectProjectButton = new QPushButton(PruebaPantalla);
        selectProjectButton->setObjectName(QString::fromUtf8("selectProjectButton"));

        gridLayout->addWidget(selectProjectButton, 4, 0, 1, 1);

        trainingSetButton = new QPushButton(PruebaPantalla);
        trainingSetButton->setObjectName(QString::fromUtf8("trainingSetButton"));

        gridLayout->addWidget(trainingSetButton, 5, 0, 1, 1);

        perceptronButton = new QPushButton(PruebaPantalla);
        perceptronButton->setObjectName(QString::fromUtf8("perceptronButton"));

        gridLayout->addWidget(perceptronButton, 6, 0, 1, 1);

        addAgentsButton = new QPushButton(PruebaPantalla);
        addAgentsButton->setObjectName(QString::fromUtf8("addAgentsButton"));

        gridLayout->addWidget(addAgentsButton, 1, 0, 1, 1);

        adalineButton = new QPushButton(PruebaPantalla);
        adalineButton->setObjectName(QString::fromUtf8("adalineButton"));

        gridLayout->addWidget(adalineButton, 0, 1, 1, 1);

        hopfieldButton = new QPushButton(PruebaPantalla);
        hopfieldButton->setObjectName(QString::fromUtf8("hopfieldButton"));

        gridLayout->addWidget(hopfieldButton, 1, 1, 1, 1);

        newProjectButton = new QPushButton(PruebaPantalla);
        newProjectButton->setObjectName(QString::fromUtf8("newProjectButton"));

        gridLayout->addWidget(newProjectButton, 3, 1, 1, 1);

        mainWindowButton = new QPushButton(PruebaPantalla);
        mainWindowButton->setObjectName(QString::fromUtf8("mainWindowButton"));

        gridLayout->addWidget(mainWindowButton, 4, 1, 1, 1);

        systemButton = new QPushButton(PruebaPantalla);
        systemButton->setObjectName(QString::fromUtf8("systemButton"));

        gridLayout->addWidget(systemButton, 5, 1, 1, 1);

        pushButton = new QPushButton(PruebaPantalla);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 6, 1, 1, 1);


        retranslateUi(PruebaPantalla);

        QMetaObject::connectSlotsByName(PruebaPantalla);
    } // setupUi

    void retranslateUi(QWidget *PruebaPantalla)
    {
        PruebaPantalla->setWindowTitle(QApplication::translate("PruebaPantalla", "Form", 0, QApplication::UnicodeUTF8));
        acoButton->setText(QApplication::translate("PruebaPantalla", "ACO", 0, QApplication::UnicodeUTF8));
        chooseProjectNameButton->setText(QApplication::translate("PruebaPantalla", "Choose project name", 0, QApplication::UnicodeUTF8));
        selectProjectButton->setText(QApplication::translate("PruebaPantalla", "Select project", 0, QApplication::UnicodeUTF8));
        trainingSetButton->setText(QApplication::translate("PruebaPantalla", "Training set", 0, QApplication::UnicodeUTF8));
        perceptronButton->setText(QApplication::translate("PruebaPantalla", "PerceptronPage", 0, QApplication::UnicodeUTF8));
        addAgentsButton->setText(QApplication::translate("PruebaPantalla", "Add agents", 0, QApplication::UnicodeUTF8));
        adalineButton->setText(QApplication::translate("PruebaPantalla", "ADALINE", 0, QApplication::UnicodeUTF8));
        hopfieldButton->setText(QApplication::translate("PruebaPantalla", "Hopfield", 0, QApplication::UnicodeUTF8));
        newProjectButton->setText(QApplication::translate("PruebaPantalla", "New project", 0, QApplication::UnicodeUTF8));
        mainWindowButton->setText(QApplication::translate("PruebaPantalla", "Main Window", 0, QApplication::UnicodeUTF8));
        systemButton->setText(QApplication::translate("PruebaPantalla", "System", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("PruebaPantalla", "MLPTrainingSet", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PruebaPantalla: public Ui_PruebaPantalla {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRUEBA_PANTALLAS_H
