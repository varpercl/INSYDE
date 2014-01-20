/********************************************************************************
** Form generated from reading UI file 'graphicimageelementpropertydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICIMAGEELEMENTPROPERTYDIALOG_H
#define UI_GRAPHICIMAGEELEMENTPROPERTYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_GraphicImageElementPropertyDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GraphicImageElementPropertyDialog)
    {
        if (GraphicImageElementPropertyDialog->objectName().isEmpty())
            GraphicImageElementPropertyDialog->setObjectName(QStringLiteral("GraphicImageElementPropertyDialog"));
        GraphicImageElementPropertyDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(GraphicImageElementPropertyDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(GraphicImageElementPropertyDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), GraphicImageElementPropertyDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GraphicImageElementPropertyDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GraphicImageElementPropertyDialog);
    } // setupUi

    void retranslateUi(QDialog *GraphicImageElementPropertyDialog)
    {
        GraphicImageElementPropertyDialog->setWindowTitle(QApplication::translate("GraphicImageElementPropertyDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphicImageElementPropertyDialog: public Ui_GraphicImageElementPropertyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICIMAGEELEMENTPROPERTYDIALOG_H
