/********************************************************************************
** Form generated from reading UI file 'gssubwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GSSUBWIDGET_H
#define UI_GSSUBWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GSSubWidget
{
public:

    void setupUi(QWidget *GSSubWidget)
    {
        if (GSSubWidget->objectName().isEmpty())
            GSSubWidget->setObjectName(QStringLiteral("GSSubWidget"));
        GSSubWidget->resize(400, 300);

        retranslateUi(GSSubWidget);

        QMetaObject::connectSlotsByName(GSSubWidget);
    } // setupUi

    void retranslateUi(QWidget *GSSubWidget)
    {
        GSSubWidget->setWindowTitle(QApplication::translate("GSSubWidget", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class GSSubWidget: public Ui_GSSubWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GSSUBWIDGET_H
