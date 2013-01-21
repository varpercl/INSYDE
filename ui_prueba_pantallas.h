/********************************************************************************
** Form generated from reading UI file 'prueba_pantallas.ui'
**
** Created: Sat 19. Jan 16:02:31 2013
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRUEBA_PANTALLAS_H
#define UI_PRUEBA_PANTALLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

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
            PruebaPantalla->setObjectName(QStringLiteral("PruebaPantalla"));
        PruebaPantalla->resize(400, 300);
        gridLayout = new QGridLayout(PruebaPantalla);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        acoButton = new QPushButton(PruebaPantalla);
        acoButton->setObjectName(QStringLiteral("acoButton"));

        gridLayout->addWidget(acoButton, 0, 0, 1, 1);

        chooseProjectNameButton = new QPushButton(PruebaPantalla);
        chooseProjectNameButton->setObjectName(QStringLiteral("chooseProjectNameButton"));

        gridLayout->addWidget(chooseProjectNameButton, 3, 0, 1, 1);

        selectProjectButton = new QPushButton(PruebaPantalla);
        selectProjectButton->setObjectName(QStringLiteral("selectProjectButton"));

        gridLayout->addWidget(selectProjectButton, 4, 0, 1, 1);

        trainingSetButton = new QPushButton(PruebaPantalla);
        trainingSetButton->setObjectName(QStringLiteral("trainingSetButton"));

        gridLayout->addWidget(trainingSetButton, 5, 0, 1, 1);

        perceptronButton = new QPushButton(PruebaPantalla);
        perceptronButton->setObjectName(QStringLiteral("perceptronButton"));

        gridLayout->addWidget(perceptronButton, 6, 0, 1, 1);

        addAgentsButton = new QPushButton(PruebaPantalla);
        addAgentsButton->setObjectName(QStringLiteral("addAgentsButton"));

        gridLayout->addWidget(addAgentsButton, 1, 0, 1, 1);

        adalineButton = new QPushButton(PruebaPantalla);
        adalineButton->setObjectName(QStringLiteral("adalineButton"));

        gridLayout->addWidget(adalineButton, 0, 1, 1, 1);

        hopfieldButton = new QPushButton(PruebaPantalla);
        hopfieldButton->setObjectName(QStringLiteral("hopfieldButton"));

        gridLayout->addWidget(hopfieldButton, 1, 1, 1, 1);

        newProjectButton = new QPushButton(PruebaPantalla);
        newProjectButton->setObjectName(QStringLiteral("newProjectButton"));

        gridLayout->addWidget(newProjectButton, 3, 1, 1, 1);

        mainWindowButton = new QPushButton(PruebaPantalla);
        mainWindowButton->setObjectName(QStringLiteral("mainWindowButton"));

        gridLayout->addWidget(mainWindowButton, 4, 1, 1, 1);

        systemButton = new QPushButton(PruebaPantalla);
        systemButton->setObjectName(QStringLiteral("systemButton"));

        gridLayout->addWidget(systemButton, 5, 1, 1, 1);

        pushButton = new QPushButton(PruebaPantalla);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 6, 1, 1, 1);


        retranslateUi(PruebaPantalla);

        QMetaObject::connectSlotsByName(PruebaPantalla);
    } // setupUi

    void retranslateUi(QWidget *PruebaPantalla)
    {
        PruebaPantalla->setWindowTitle(QApplication::translate("PruebaPantalla", "Form", 0));
        acoButton->setText(QApplication::translate("PruebaPantalla", "ACO", 0));
        chooseProjectNameButton->setText(QApplication::translate("PruebaPantalla", "Choose project name", 0));
        selectProjectButton->setText(QApplication::translate("PruebaPantalla", "Select project", 0));
        trainingSetButton->setText(QApplication::translate("PruebaPantalla", "Training set", 0));
        perceptronButton->setText(QApplication::translate("PruebaPantalla", "PerceptronPage", 0));
        addAgentsButton->setText(QApplication::translate("PruebaPantalla", "Add agents", 0));
        adalineButton->setText(QApplication::translate("PruebaPantalla", "ADALINE", 0));
        hopfieldButton->setText(QApplication::translate("PruebaPantalla", "Hopfield", 0));
        newProjectButton->setText(QApplication::translate("PruebaPantalla", "New project", 0));
        mainWindowButton->setText(QApplication::translate("PruebaPantalla", "Main Window", 0));
        systemButton->setText(QApplication::translate("PruebaPantalla", "System", 0));
        pushButton->setText(QApplication::translate("PruebaPantalla", "MLPTrainingSet", 0));
    } // retranslateUi

};

namespace Ui {
    class PruebaPantalla: public Ui_PruebaPantalla {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRUEBA_PANTALLAS_H
