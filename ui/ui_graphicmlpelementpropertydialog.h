/********************************************************************************
** Form generated from reading UI file 'graphicmlpelementpropertydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICMLPELEMENTPROPERTYDIALOG_H
#define UI_GRAPHICMLPELEMENTPROPERTYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_GraphicMLPElementPropertyDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GraphicMLPElementPropertyDialog)
    {
        if (GraphicMLPElementPropertyDialog->objectName().isEmpty())
            GraphicMLPElementPropertyDialog->setObjectName(QStringLiteral("GraphicMLPElementPropertyDialog"));
        GraphicMLPElementPropertyDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(GraphicMLPElementPropertyDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(GraphicMLPElementPropertyDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), GraphicMLPElementPropertyDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GraphicMLPElementPropertyDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GraphicMLPElementPropertyDialog);
    } // setupUi

    void retranslateUi(QDialog *GraphicMLPElementPropertyDialog)
    {
        GraphicMLPElementPropertyDialog->setWindowTitle(QApplication::translate("GraphicMLPElementPropertyDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphicMLPElementPropertyDialog: public Ui_GraphicMLPElementPropertyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICMLPELEMENTPROPERTYDIALOG_H
