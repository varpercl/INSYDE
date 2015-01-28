/********************************************************************************
** Form generated from reading UI file 'addnewmlpdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWMLPDIALOG_H
#define UI_ADDNEWMLPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addNewMLPDialog
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_3;
    QLabel *label_4;
    QSpinBox *sbInputSize;
    QLabel *label_10;
    QSpinBox *sbOutputSize;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_6;
    QTableWidget *tblLayers;
    QVBoxLayout *verticalLayout_7;
    QToolButton *btnAddLayer;
    QToolButton *btnDeleteLayer;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *cbTrasnferFunction;
    QLabel *label_14;
    QSpinBox *sbSlope;

    void setupUi(QDialog *addNewMLPDialog)
    {
        if (addNewMLPDialog->objectName().isEmpty())
            addNewMLPDialog->setObjectName(QStringLiteral("addNewMLPDialog"));
        addNewMLPDialog->resize(411, 300);
        buttonBox = new QDialogButtonBox(addNewMLPDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(240, 270, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(addNewMLPDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 391, 251));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_4);

        sbInputSize = new QSpinBox(groupBox);
        sbInputSize->setObjectName(QStringLiteral("sbInputSize"));
        sbInputSize->setMaximum(9999);
        sbInputSize->setValue(403);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, sbInputSize);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_10);

        sbOutputSize = new QSpinBox(groupBox);
        sbOutputSize->setObjectName(QStringLiteral("sbOutputSize"));
        sbOutputSize->setMaximum(9999);
        sbOutputSize->setValue(36);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, sbOutputSize);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_11);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        tblLayers = new QTableWidget(groupBox);
        if (tblLayers->columnCount() < 2)
            tblLayers->setColumnCount(2);
        tblLayers->setObjectName(QStringLiteral("tblLayers"));
        tblLayers->setMaximumSize(QSize(150, 16777215));
        tblLayers->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
        tblLayers->setAlternatingRowColors(true);
        tblLayers->setRowCount(0);
        tblLayers->setColumnCount(2);
        tblLayers->horizontalHeader()->setCascadingSectionResizes(false);
        tblLayers->horizontalHeader()->setDefaultSectionSize(74);
        tblLayers->horizontalHeader()->setMinimumSectionSize(27);
        tblLayers->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tblLayers->horizontalHeader()->setStretchLastSection(false);
        tblLayers->verticalHeader()->setVisible(false);
        tblLayers->verticalHeader()->setDefaultSectionSize(20);

        horizontalLayout_6->addWidget(tblLayers);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        btnAddLayer = new QToolButton(groupBox);
        btnAddLayer->setObjectName(QStringLiteral("btnAddLayer"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/imagenes/plus_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddLayer->setIcon(icon);

        verticalLayout_7->addWidget(btnAddLayer);

        btnDeleteLayer = new QToolButton(groupBox);
        btnDeleteLayer->setObjectName(QStringLiteral("btnDeleteLayer"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imagenes/minus_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDeleteLayer->setIcon(icon1);

        verticalLayout_7->addWidget(btnDeleteLayer);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);


        horizontalLayout_6->addLayout(verticalLayout_7);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        formLayout_3->setLayout(2, QFormLayout::FieldRole, horizontalLayout_6);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_13);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        cbTrasnferFunction = new QComboBox(groupBox);
        cbTrasnferFunction->setObjectName(QStringLiteral("cbTrasnferFunction"));

        horizontalLayout_3->addWidget(cbTrasnferFunction);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_3->addWidget(label_14);

        sbSlope = new QSpinBox(groupBox);
        sbSlope->setObjectName(QStringLiteral("sbSlope"));
        sbSlope->setMaximum(9999999);
        sbSlope->setValue(1);

        horizontalLayout_3->addWidget(sbSlope);


        formLayout_3->setLayout(3, QFormLayout::FieldRole, horizontalLayout_3);


        verticalLayout->addLayout(formLayout_3);


        retranslateUi(addNewMLPDialog);

        QMetaObject::connectSlotsByName(addNewMLPDialog);
    } // setupUi

    void retranslateUi(QDialog *addNewMLPDialog)
    {
        addNewMLPDialog->setWindowTitle(QApplication::translate("addNewMLPDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("addNewMLPDialog", "Basico", 0));
        label_4->setText(QApplication::translate("addNewMLPDialog", "Entradas", 0));
        label_10->setText(QApplication::translate("addNewMLPDialog", "Salidas", 0));
        label_11->setText(QApplication::translate("addNewMLPDialog", "Capas", 0));
        btnAddLayer->setText(QApplication::translate("addNewMLPDialog", "...", 0));
        btnDeleteLayer->setText(QApplication::translate("addNewMLPDialog", "...", 0));
        label_13->setText(QApplication::translate("addNewMLPDialog", "Funcion de transferencia", 0));
        cbTrasnferFunction->clear();
        cbTrasnferFunction->insertItems(0, QStringList()
         << QApplication::translate("addNewMLPDialog", "Sigmoide", 0)
         << QApplication::translate("addNewMLPDialog", "Tangente", 0)
        );
        label_14->setText(QApplication::translate("addNewMLPDialog", "Pendiente", 0));
    } // retranslateUi

};

namespace Ui {
    class addNewMLPDialog: public Ui_addNewMLPDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWMLPDIALOG_H
