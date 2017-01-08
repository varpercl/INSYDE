/********************************************************************************
** Form generated from reading UI file 'graphicimageeffectelementpropertydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICIMAGEEFFECTELEMENTPROPERTYDIALOG_H
#define UI_GRAPHICIMAGEEFFECTELEMENTPROPERTYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GraphicImageEffectElementPropertyDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *hlDivision;
    QListWidget *lwEffects;
    QDialogButtonBox *btnOkCancel;

    void setupUi(QDialog *GraphicImageEffectElementPropertyDialog)
    {
        if (GraphicImageEffectElementPropertyDialog->objectName().isEmpty())
            GraphicImageEffectElementPropertyDialog->setObjectName(QStringLiteral("GraphicImageEffectElementPropertyDialog"));
        GraphicImageEffectElementPropertyDialog->resize(614, 368);
        verticalLayout = new QVBoxLayout(GraphicImageEffectElementPropertyDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        hlDivision = new QHBoxLayout();
        hlDivision->setObjectName(QStringLiteral("hlDivision"));
        lwEffects = new QListWidget(GraphicImageEffectElementPropertyDialog);
        new QListWidgetItem(lwEffects);
        new QListWidgetItem(lwEffects);
        lwEffects->setObjectName(QStringLiteral("lwEffects"));
        lwEffects->setMaximumSize(QSize(250, 16777215));
        lwEffects->setEditTriggers(QAbstractItemView::NoEditTriggers);

        hlDivision->addWidget(lwEffects);


        verticalLayout->addLayout(hlDivision);

        btnOkCancel = new QDialogButtonBox(GraphicImageEffectElementPropertyDialog);
        btnOkCancel->setObjectName(QStringLiteral("btnOkCancel"));
        btnOkCancel->setOrientation(Qt::Horizontal);
        btnOkCancel->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(btnOkCancel);


        retranslateUi(GraphicImageEffectElementPropertyDialog);
        QObject::connect(btnOkCancel, SIGNAL(accepted()), GraphicImageEffectElementPropertyDialog, SLOT(accept()));
        QObject::connect(btnOkCancel, SIGNAL(rejected()), GraphicImageEffectElementPropertyDialog, SLOT(reject()));

        lwEffects->setCurrentRow(0);


        QMetaObject::connectSlotsByName(GraphicImageEffectElementPropertyDialog);
    } // setupUi

    void retranslateUi(QDialog *GraphicImageEffectElementPropertyDialog)
    {
        GraphicImageEffectElementPropertyDialog->setWindowTitle(QApplication::translate("GraphicImageEffectElementPropertyDialog", "Dialog", Q_NULLPTR));

        const bool __sortingEnabled = lwEffects->isSortingEnabled();
        lwEffects->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = lwEffects->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("GraphicImageEffectElementPropertyDialog", "Blanco y negro", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = lwEffects->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("GraphicImageEffectElementPropertyDialog", "Escala de grises", Q_NULLPTR));
        lwEffects->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class GraphicImageEffectElementPropertyDialog: public Ui_GraphicImageEffectElementPropertyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICIMAGEEFFECTELEMENTPROPERTYDIALOG_H
