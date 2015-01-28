/********************************************************************************
** Form generated from reading UI file 'mlptrainingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MLPTRAININGDIALOG_H
#define UI_MLPTRAININGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MLPTrainingDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *lblInputs;
    QLabel *label_2;
    QLabel *lblOutputs;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *tblLayers;
    QVBoxLayout *verticalLayout_5;
    QToolButton *btnAddLayer;
    QToolButton *btnDeleteLayer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QComboBox *cbTrainingAlgorithm;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *cbTrasnferFunction;
    QLabel *label_9;
    QPushButton *btnEditTrainingSet;
    QLabel *label_30;
    QPushButton *btnEditValidationTest;
    QLabel *label_33;
    QPushButton *btnEditTestSet;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QComboBox *cbStopCondition;
    QDoubleSpinBox *sbEMValue;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnRandomize;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_7;
    QScrollArea *saOptimization;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_9;
    QCheckBox *chkSA;
    QGroupBox *gbPlotter;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_16;
    QLabel *lblTime;
    QHBoxLayout *buttonsLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnMultipleTraining;
    QPushButton *btnTrain;
    QPushButton *btnCancel;

    void setupUi(QDialog *MLPTrainingDialog)
    {
        if (MLPTrainingDialog->objectName().isEmpty())
            MLPTrainingDialog->setObjectName(QStringLiteral("MLPTrainingDialog"));
        MLPTrainingDialog->resize(982, 593);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MLPTrainingDialog->sizePolicy().hasHeightForWidth());
        MLPTrainingDialog->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(MLPTrainingDialog);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        scrollArea = new QScrollArea(MLPTrainingDialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 962, 543));
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lblInputs = new QLabel(groupBox);
        lblInputs->setObjectName(QStringLiteral("lblInputs"));
        sizePolicy1.setHeightForWidth(lblInputs->sizePolicy().hasHeightForWidth());
        lblInputs->setSizePolicy(sizePolicy1);
        lblInputs->setFrameShape(QFrame::Box);
        lblInputs->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(0, QFormLayout::FieldRole, lblInputs);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        lblOutputs = new QLabel(groupBox);
        lblOutputs->setObjectName(QStringLiteral("lblOutputs"));
        sizePolicy1.setHeightForWidth(lblOutputs->sizePolicy().hasHeightForWidth());
        lblOutputs->setSizePolicy(sizePolicy1);
        lblOutputs->setFrameShape(QFrame::Box);
        lblOutputs->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(2, QFormLayout::FieldRole, lblOutputs);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        tblLayers = new QTableWidget(groupBox);
        if (tblLayers->columnCount() < 2)
            tblLayers->setColumnCount(2);
        tblLayers->setObjectName(QStringLiteral("tblLayers"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tblLayers->sizePolicy().hasHeightForWidth());
        tblLayers->setSizePolicy(sizePolicy2);
        tblLayers->setMinimumSize(QSize(0, 150));
        tblLayers->setMaximumSize(QSize(16777215, 16777215));
        tblLayers->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
        tblLayers->setAlternatingRowColors(true);
        tblLayers->setRowCount(0);
        tblLayers->setColumnCount(2);
        tblLayers->verticalHeader()->setVisible(false);

        horizontalLayout_4->addWidget(tblLayers);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        btnAddLayer = new QToolButton(groupBox);
        btnAddLayer->setObjectName(QStringLiteral("btnAddLayer"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/imagenes/plus_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddLayer->setIcon(icon);

        verticalLayout_5->addWidget(btnAddLayer);

        btnDeleteLayer = new QToolButton(groupBox);
        btnDeleteLayer->setObjectName(QStringLiteral("btnDeleteLayer"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imagenes/minus_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDeleteLayer->setIcon(icon1);

        verticalLayout_5->addWidget(btnDeleteLayer);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_4);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        cbTrainingAlgorithm = new QComboBox(groupBox);
        cbTrainingAlgorithm->setObjectName(QStringLiteral("cbTrainingAlgorithm"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(cbTrainingAlgorithm->sizePolicy().hasHeightForWidth());
        cbTrainingAlgorithm->setSizePolicy(sizePolicy3);

        formLayout->setWidget(5, QFormLayout::FieldRole, cbTrainingAlgorithm);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        formLayout->setWidget(7, QFormLayout::LabelRole, label_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cbTrasnferFunction = new QComboBox(groupBox);
        cbTrasnferFunction->setObjectName(QStringLiteral("cbTrasnferFunction"));

        horizontalLayout_2->addWidget(cbTrasnferFunction);


        formLayout->setLayout(7, QFormLayout::FieldRole, horizontalLayout_2);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);

        formLayout->setWidget(8, QFormLayout::LabelRole, label_9);

        btnEditTrainingSet = new QPushButton(groupBox);
        btnEditTrainingSet->setObjectName(QStringLiteral("btnEditTrainingSet"));
        sizePolicy3.setHeightForWidth(btnEditTrainingSet->sizePolicy().hasHeightForWidth());
        btnEditTrainingSet->setSizePolicy(sizePolicy3);

        formLayout->setWidget(8, QFormLayout::FieldRole, btnEditTrainingSet);

        label_30 = new QLabel(groupBox);
        label_30->setObjectName(QStringLiteral("label_30"));
        sizePolicy1.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy1);

        formLayout->setWidget(9, QFormLayout::LabelRole, label_30);

        btnEditValidationTest = new QPushButton(groupBox);
        btnEditValidationTest->setObjectName(QStringLiteral("btnEditValidationTest"));
        sizePolicy3.setHeightForWidth(btnEditValidationTest->sizePolicy().hasHeightForWidth());
        btnEditValidationTest->setSizePolicy(sizePolicy3);

        formLayout->setWidget(9, QFormLayout::FieldRole, btnEditValidationTest);

        label_33 = new QLabel(groupBox);
        label_33->setObjectName(QStringLiteral("label_33"));
        sizePolicy1.setHeightForWidth(label_33->sizePolicy().hasHeightForWidth());
        label_33->setSizePolicy(sizePolicy1);

        formLayout->setWidget(10, QFormLayout::LabelRole, label_33);

        btnEditTestSet = new QPushButton(groupBox);
        btnEditTestSet->setObjectName(QStringLiteral("btnEditTestSet"));
        sizePolicy3.setHeightForWidth(btnEditTestSet->sizePolicy().hasHeightForWidth());
        btnEditTestSet->setSizePolicy(sizePolicy3);

        formLayout->setWidget(10, QFormLayout::FieldRole, btnEditTestSet);


        verticalLayout->addLayout(formLayout);


        horizontalLayout_3->addWidget(groupBox);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetMinimumSize);
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(300, 0));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cbStopCondition = new QComboBox(groupBox_2);
        cbStopCondition->setObjectName(QStringLiteral("cbStopCondition"));

        horizontalLayout->addWidget(cbStopCondition);

        sbEMValue = new QDoubleSpinBox(groupBox_2);
        sbEMValue->setObjectName(QStringLiteral("sbEMValue"));
        sbEMValue->setDecimals(6);
        sbEMValue->setMaximum(999.99);
        sbEMValue->setSingleStep(0.01);
        sbEMValue->setValue(5);

        horizontalLayout->addWidget(sbEMValue);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        btnRandomize = new QPushButton(groupBox_2);
        btnRandomize->setObjectName(QStringLiteral("btnRandomize"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btnRandomize->sizePolicy().hasHeightForWidth());
        btnRandomize->setSizePolicy(sizePolicy4);
        btnRandomize->setMinimumSize(QSize(0, 0));

        horizontalLayout_5->addWidget(btnRandomize);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_6->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_7 = new QVBoxLayout(groupBox_4);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        saOptimization = new QScrollArea(groupBox_4);
        saOptimization->setObjectName(QStringLiteral("saOptimization"));
        saOptimization->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 367, 313));
        verticalLayout_9 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        chkSA = new QCheckBox(scrollAreaWidgetContents);
        chkSA->setObjectName(QStringLiteral("chkSA"));

        verticalLayout_9->addWidget(chkSA);

        saOptimization->setWidget(scrollAreaWidgetContents);

        verticalLayout_7->addWidget(saOptimization);


        verticalLayout_6->addWidget(groupBox_4);


        horizontalLayout_3->addLayout(verticalLayout_6);


        verticalLayout_8->addLayout(horizontalLayout_3);

        gbPlotter = new QGroupBox(scrollAreaWidgetContents_2);
        gbPlotter->setObjectName(QStringLiteral("gbPlotter"));
        verticalLayout_3 = new QVBoxLayout(gbPlotter);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_16 = new QLabel(gbPlotter);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout->addWidget(label_16, 0, 0, 1, 1);

        lblTime = new QLabel(gbPlotter);
        lblTime->setObjectName(QStringLiteral("lblTime"));

        gridLayout->addWidget(lblTime, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);


        verticalLayout_8->addWidget(gbPlotter);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_4->addWidget(scrollArea);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setObjectName(QStringLiteral("buttonsLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonsLayout->addItem(horizontalSpacer);

        btnMultipleTraining = new QPushButton(MLPTrainingDialog);
        btnMultipleTraining->setObjectName(QStringLiteral("btnMultipleTraining"));

        buttonsLayout->addWidget(btnMultipleTraining);

        btnTrain = new QPushButton(MLPTrainingDialog);
        btnTrain->setObjectName(QStringLiteral("btnTrain"));
        btnTrain->setDefault(true);
        btnTrain->setFlat(false);

        buttonsLayout->addWidget(btnTrain);

        btnCancel = new QPushButton(MLPTrainingDialog);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        buttonsLayout->addWidget(btnCancel);


        verticalLayout_4->addLayout(buttonsLayout);


        retranslateUi(MLPTrainingDialog);

        QMetaObject::connectSlotsByName(MLPTrainingDialog);
    } // setupUi

    void retranslateUi(QDialog *MLPTrainingDialog)
    {
        MLPTrainingDialog->setWindowTitle(QApplication::translate("MLPTrainingDialog", "Entrenamiento", 0));
        groupBox->setTitle(QApplication::translate("MLPTrainingDialog", "Propiedades", 0));
        label->setText(QApplication::translate("MLPTrainingDialog", "Entradas", 0));
        lblInputs->setText(QApplication::translate("MLPTrainingDialog", "TextLabel", 0));
        label_2->setText(QApplication::translate("MLPTrainingDialog", "Salidas", 0));
        lblOutputs->setText(QApplication::translate("MLPTrainingDialog", "TextLabel", 0));
        label_3->setText(QApplication::translate("MLPTrainingDialog", "Capas", 0));
        btnAddLayer->setText(QApplication::translate("MLPTrainingDialog", "...", 0));
        btnDeleteLayer->setText(QApplication::translate("MLPTrainingDialog", "...", 0));
        label_6->setText(QApplication::translate("MLPTrainingDialog", "Algoritmo principal", 0));
        cbTrainingAlgorithm->clear();
        cbTrainingAlgorithm->insertItems(0, QStringList()
         << QApplication::translate("MLPTrainingDialog", "Backpropagation", 0)
        );
        label_7->setText(QApplication::translate("MLPTrainingDialog", "Funcion de transferencia", 0));
        cbTrasnferFunction->clear();
        cbTrasnferFunction->insertItems(0, QStringList()
         << QApplication::translate("MLPTrainingDialog", "Sigmoide", 0)
         << QApplication::translate("MLPTrainingDialog", "Tangente", 0)
        );
        label_9->setText(QApplication::translate("MLPTrainingDialog", "Conjunto de entrenamiento", 0));
        btnEditTrainingSet->setText(QApplication::translate("MLPTrainingDialog", "Editar", 0));
        label_30->setText(QApplication::translate("MLPTrainingDialog", "Conjunto de validaci\303\263n", 0));
        btnEditValidationTest->setText(QApplication::translate("MLPTrainingDialog", "Editar", 0));
        label_33->setText(QApplication::translate("MLPTrainingDialog", "Conjunto de prueba", 0));
        btnEditTestSet->setText(QApplication::translate("MLPTrainingDialog", "Editar", 0));
        groupBox_2->setTitle(QApplication::translate("MLPTrainingDialog", "Condici\303\263n de parada", 0));
        cbStopCondition->clear();
        cbStopCondition->insertItems(0, QStringList()
         << QApplication::translate("MLPTrainingDialog", "MSE minimo", 0)
         << QApplication::translate("MLPTrainingDialog", "RMSE minimo", 0)
         << QApplication::translate("MLPTrainingDialog", "CE minimo", 0)
        );
        btnRandomize->setText(QApplication::translate("MLPTrainingDialog", "Aleatorizar pesos", 0));
        groupBox_4->setTitle(QApplication::translate("MLPTrainingDialog", "Optimizaci\303\263n", 0));
        chkSA->setText(QApplication::translate("MLPTrainingDialog", "Simulated Annealing", 0));
        gbPlotter->setTitle(QApplication::translate("MLPTrainingDialog", "Resultados", 0));
        label_16->setText(QApplication::translate("MLPTrainingDialog", "Tiempo", 0));
        lblTime->setText(QString());
        btnMultipleTraining->setText(QApplication::translate("MLPTrainingDialog", "Multiples entrenamientos", 0));
        btnTrain->setText(QApplication::translate("MLPTrainingDialog", "Entrenar", 0));
        btnCancel->setText(QApplication::translate("MLPTrainingDialog", "Salir", 0));
    } // retranslateUi

};

namespace Ui {
    class MLPTrainingDialog: public Ui_MLPTrainingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MLPTRAININGDIALOG_H
