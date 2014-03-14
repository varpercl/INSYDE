/********************************************************************************
** Form generated from reading UI file 'graphicelementdetailedwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICELEMENTDETAILEDWINDOW_H
#define UI_GRAPHICELEMENTDETAILEDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphicElementDetailedWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *GraphicElementDetailedWindow)
    {
        if (GraphicElementDetailedWindow->objectName().isEmpty())
            GraphicElementDetailedWindow->setObjectName(QStringLiteral("GraphicElementDetailedWindow"));
        GraphicElementDetailedWindow->resize(394, 302);
        verticalLayout_2 = new QVBoxLayout(GraphicElementDetailedWindow);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(GraphicElementDetailedWindow);

        QMetaObject::connectSlotsByName(GraphicElementDetailedWindow);
    } // setupUi

    void retranslateUi(QWidget *GraphicElementDetailedWindow)
    {
        GraphicElementDetailedWindow->setWindowTitle(QApplication::translate("GraphicElementDetailedWindow", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphicElementDetailedWindow: public Ui_GraphicElementDetailedWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICELEMENTDETAILEDWINDOW_H
