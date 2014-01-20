/********************************************************************************
** Form generated from reading UI file 'mlptrainingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MLPTrainingDialog
{
public:
    QVBoxLayout *verticalLayout_4;
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
    QLabel *label_8;
    QSpinBox *sbSlope;
    QLabel *label_5;
    QDoubleSpinBox *sbLearningRate;
    QLabel *label_9;
    QPushButton *btnEditTrainingSet;
    QLabel *label_30;
    QPushButton *btnEditValidationTest;
    QPushButton *btnEditTestSet;
    QLabel *label_33;
    QCheckBox *chkSA;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_2;
    QLabel *label_10;
    QSpinBox *sbEpochs;
    QLabel *label_35;
    QDoubleSpinBox *sbThreshold;
    QLabel *label_17;
    QDoubleSpinBox *sbStartCondition;
    QLabel *label_21;
    QSpinBox *sbNChanges;
    QLabel *label_15;
    QDoubleSpinBox *sbMinTemperature;
    QLabel *label_32;
    QDoubleSpinBox *sbDecFactor;
    QLabel *label_18;
    QDoubleSpinBox *sbTo;
    QLabel *label_19;
    QDoubleSpinBox *sbMinNoise;
    QLabel *label_20;
    QDoubleSpinBox *sbMaxNoise;
    QPushButton *btnRandomize;
    QHBoxLayout *horizontalLayout;
    QLabel *label_28;
    QDoubleSpinBox *sbRndFrom;
    QLabel *label_29;
    QDoubleSpinBox *sbRndTo;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *cbStopCondition;
    QDoubleSpinBox *sbEMValue;
    QLabel *label_34;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_12;
    QLabel *lblEpochs;
    QLabel *label_16;
    QLabel *lblTime;
    QLabel *label_14;
    QLabel *lblMinError;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_31;
    QLabel *lblRMSE;
    QHBoxLayout *buttonsLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnMultipleTraining;
    QPushButton *btnTrain;
    QPushButton *btnCancel;

    void setupUi(QDialog *MLPTrainingDialog)
    {
        if (MLPTrainingDialog->objectName().isEmpty())
            MLPTrainingDialog->setObjectName(QStringLiteral("MLPTrainingDialog"));
        MLPTrainingDialog->resize(856, 578);
        verticalLayout_4 = new QVBoxLayout(MLPTrainingDialog);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox = new QGroupBox(MLPTrainingDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lblInputs = new QLabel(groupBox);
        lblInputs->setObjectName(QStringLiteral("lblInputs"));
        lblInputs->setFrameShape(QFrame::Box);
        lblInputs->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(0, QFormLayout::FieldRole, lblInputs);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        lblOutputs = new QLabel(groupBox);
        lblOutputs->setObjectName(QStringLiteral("lblOutputs"));
        lblOutputs->setFrameShape(QFrame::Box);
        lblOutputs->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(2, QFormLayout::FieldRole, lblOutputs);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
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

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        cbTrainingAlgorithm = new QComboBox(groupBox);
        cbTrainingAlgorithm->setObjectName(QStringLiteral("cbTrainingAlgorithm"));

        formLayout->setWidget(5, QFormLayout::FieldRole, cbTrainingAlgorithm);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cbTrasnferFunction = new QComboBox(groupBox);
        cbTrasnferFunction->setObjectName(QStringLiteral("cbTrasnferFunction"));

        horizontalLayout_2->addWidget(cbTrasnferFunction);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_2->addWidget(label_8);

        sbSlope = new QSpinBox(groupBox);
        sbSlope->setObjectName(QStringLiteral("sbSlope"));
        sbSlope->setMaximum(9999999);
        sbSlope->setValue(1);

        horizontalLayout_2->addWidget(sbSlope);


        formLayout->setLayout(7, QFormLayout::FieldRole, horizontalLayout_2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_5);

        sbLearningRate = new QDoubleSpinBox(groupBox);
        sbLearningRate->setObjectName(QStringLiteral("sbLearningRate"));
        sbLearningRate->setDecimals(4);
        sbLearningRate->setMaximum(1);
        sbLearningRate->setSingleStep(0.01);
        sbLearningRate->setValue(0.2);

        formLayout->setWidget(8, QFormLayout::FieldRole, sbLearningRate);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_9);

        btnEditTrainingSet = new QPushButton(groupBox);
        btnEditTrainingSet->setObjectName(QStringLiteral("btnEditTrainingSet"));

        formLayout->setWidget(9, QFormLayout::FieldRole, btnEditTrainingSet);

        label_30 = new QLabel(groupBox);
        label_30->setObjectName(QStringLiteral("label_30"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_30);

        btnEditValidationTest = new QPushButton(groupBox);
        btnEditValidationTest->setObjectName(QStringLiteral("btnEditValidationTest"));

        formLayout->setWidget(10, QFormLayout::FieldRole, btnEditValidationTest);

        btnEditTestSet = new QPushButton(groupBox);
        btnEditTestSet->setObjectName(QStringLiteral("btnEditTestSet"));

        formLayout->setWidget(11, QFormLayout::FieldRole, btnEditTestSet);

        label_33 = new QLabel(groupBox);
        label_33->setObjectName(QStringLiteral("label_33"));

        formLayout->setWidget(11, QFormLayout::LabelRole, label_33);

        chkSA = new QCheckBox(groupBox);
        chkSA->setObjectName(QStringLiteral("chkSA"));

        formLayout->setWidget(6, QFormLayout::FieldRole, chkSA);


        verticalLayout->addLayout(formLayout);


        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(MLPTrainingDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(300, 0));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_10);

        sbEpochs = new QSpinBox(groupBox_2);
        sbEpochs->setObjectName(QStringLiteral("sbEpochs"));
        sbEpochs->setMinimum(1);
        sbEpochs->setMaximum(999999999);
        sbEpochs->setValue(200000);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, sbEpochs);

        label_35 = new QLabel(groupBox_2);
        label_35->setObjectName(QStringLiteral("label_35"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_35);

        sbThreshold = new QDoubleSpinBox(groupBox_2);
        sbThreshold->setObjectName(QStringLiteral("sbThreshold"));
        sbThreshold->setDecimals(6);
        sbThreshold->setMinimum(-1);
        sbThreshold->setValue(0.5);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, sbThreshold);

        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_17);

        sbStartCondition = new QDoubleSpinBox(groupBox_2);
        sbStartCondition->setObjectName(QStringLiteral("sbStartCondition"));
        sbStartCondition->setDecimals(6);
        sbStartCondition->setSingleStep(0.01);
        sbStartCondition->setValue(0.075);

        formLayout_2->setWidget(6, QFormLayout::FieldRole, sbStartCondition);

        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QStringLiteral("label_21"));

        formLayout_2->setWidget(7, QFormLayout::LabelRole, label_21);

        sbNChanges = new QSpinBox(groupBox_2);
        sbNChanges->setObjectName(QStringLiteral("sbNChanges"));
        sbNChanges->setMinimum(0);
        sbNChanges->setMaximum(999999);
        sbNChanges->setValue(10);

        formLayout_2->setWidget(7, QFormLayout::FieldRole, sbNChanges);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout_2->setWidget(8, QFormLayout::LabelRole, label_15);

        sbMinTemperature = new QDoubleSpinBox(groupBox_2);
        sbMinTemperature->setObjectName(QStringLiteral("sbMinTemperature"));
        sbMinTemperature->setDecimals(6);
        sbMinTemperature->setSingleStep(0.01);
        sbMinTemperature->setValue(0.001);

        formLayout_2->setWidget(8, QFormLayout::FieldRole, sbMinTemperature);

        label_32 = new QLabel(groupBox_2);
        label_32->setObjectName(QStringLiteral("label_32"));

        formLayout_2->setWidget(9, QFormLayout::LabelRole, label_32);

        sbDecFactor = new QDoubleSpinBox(groupBox_2);
        sbDecFactor->setObjectName(QStringLiteral("sbDecFactor"));
        sbDecFactor->setDecimals(6);
        sbDecFactor->setMinimum(1e-06);
        sbDecFactor->setMaximum(1);
        sbDecFactor->setValue(0.8);

        formLayout_2->setWidget(9, QFormLayout::FieldRole, sbDecFactor);

        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QStringLiteral("label_18"));

        formLayout_2->setWidget(10, QFormLayout::LabelRole, label_18);

        sbTo = new QDoubleSpinBox(groupBox_2);
        sbTo->setObjectName(QStringLiteral("sbTo"));
        sbTo->setDecimals(6);
        sbTo->setMaximum(0.999999);
        sbTo->setSingleStep(0.08);
        sbTo->setValue(0.2);

        formLayout_2->setWidget(10, QFormLayout::FieldRole, sbTo);

        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QStringLiteral("label_19"));

        formLayout_2->setWidget(11, QFormLayout::LabelRole, label_19);

        sbMinNoise = new QDoubleSpinBox(groupBox_2);
        sbMinNoise->setObjectName(QStringLiteral("sbMinNoise"));
        sbMinNoise->setDecimals(6);
        sbMinNoise->setMinimum(-9999);
        sbMinNoise->setMaximum(9999);
        sbMinNoise->setSingleStep(0.01);
        sbMinNoise->setValue(-0.05);

        formLayout_2->setWidget(11, QFormLayout::FieldRole, sbMinNoise);

        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QStringLiteral("label_20"));

        formLayout_2->setWidget(12, QFormLayout::LabelRole, label_20);

        sbMaxNoise = new QDoubleSpinBox(groupBox_2);
        sbMaxNoise->setObjectName(QStringLiteral("sbMaxNoise"));
        sbMaxNoise->setDecimals(6);
        sbMaxNoise->setMinimum(-9999);
        sbMaxNoise->setMaximum(9999);
        sbMaxNoise->setSingleStep(0.01);
        sbMaxNoise->setValue(0.05);

        formLayout_2->setWidget(12, QFormLayout::FieldRole, sbMaxNoise);

        btnRandomize = new QPushButton(groupBox_2);
        btnRandomize->setObjectName(QStringLiteral("btnRandomize"));
        btnRandomize->setMinimumSize(QSize(100, 0));

        formLayout_2->setWidget(13, QFormLayout::LabelRole, btnRandomize);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_28 = new QLabel(groupBox_2);
        label_28->setObjectName(QStringLiteral("label_28"));

        horizontalLayout->addWidget(label_28);

        sbRndFrom = new QDoubleSpinBox(groupBox_2);
        sbRndFrom->setObjectName(QStringLiteral("sbRndFrom"));
        sbRndFrom->setDecimals(10);
        sbRndFrom->setMinimum(-9999);
        sbRndFrom->setMaximum(9999);
        sbRndFrom->setSingleStep(0.01);
        sbRndFrom->setValue(-0.001);

        horizontalLayout->addWidget(sbRndFrom);

        label_29 = new QLabel(groupBox_2);
        label_29->setObjectName(QStringLiteral("label_29"));

        horizontalLayout->addWidget(label_29);

        sbRndTo = new QDoubleSpinBox(groupBox_2);
        sbRndTo->setObjectName(QStringLiteral("sbRndTo"));
        sbRndTo->setDecimals(10);
        sbRndTo->setMinimum(-9999);
        sbRndTo->setMaximum(9999);
        sbRndTo->setSingleStep(0.01);
        sbRndTo->setValue(0.001);

        horizontalLayout->addWidget(sbRndTo);


        formLayout_2->setLayout(13, QFormLayout::FieldRole, horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        cbStopCondition = new QComboBox(groupBox_2);
        cbStopCondition->setObjectName(QStringLiteral("cbStopCondition"));

        horizontalLayout_5->addWidget(cbStopCondition);

        sbEMValue = new QDoubleSpinBox(groupBox_2);
        sbEMValue->setObjectName(QStringLiteral("sbEMValue"));
        sbEMValue->setDecimals(6);
        sbEMValue->setMaximum(999.99);
        sbEMValue->setSingleStep(0.01);
        sbEMValue->setValue(0.5);

        horizontalLayout_5->addWidget(sbEMValue);


        formLayout_2->setLayout(3, QFormLayout::FieldRole, horizontalLayout_5);

        label_34 = new QLabel(groupBox_2);
        label_34->setObjectName(QStringLiteral("label_34"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_34);


        verticalLayout_2->addLayout(formLayout_2);


        horizontalLayout_3->addWidget(groupBox_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        groupBox_3 = new QGroupBox(MLPTrainingDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 0, 0, 1, 1);

        lblEpochs = new QLabel(groupBox_3);
        lblEpochs->setObjectName(QStringLiteral("lblEpochs"));

        gridLayout->addWidget(lblEpochs, 0, 1, 1, 1);

        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout->addWidget(label_16, 3, 0, 1, 1);

        lblTime = new QLabel(groupBox_3);
        lblTime->setObjectName(QStringLiteral("lblTime"));

        gridLayout->addWidget(lblTime, 3, 1, 1, 1);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 1, 0, 1, 1);

        lblMinError = new QLabel(groupBox_3);
        lblMinError->setObjectName(QStringLiteral("lblMinError"));

        gridLayout->addWidget(lblMinError, 1, 1, 1, 1);

        label_22 = new QLabel(groupBox_3);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout->addWidget(label_22, 0, 2, 1, 1);

        label_23 = new QLabel(groupBox_3);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout->addWidget(label_23, 1, 2, 1, 1);

        label_24 = new QLabel(groupBox_3);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout->addWidget(label_24, 3, 2, 1, 1);

        label_25 = new QLabel(groupBox_3);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout->addWidget(label_25, 0, 3, 1, 1);

        label_26 = new QLabel(groupBox_3);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout->addWidget(label_26, 1, 3, 1, 1);

        label_27 = new QLabel(groupBox_3);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout->addWidget(label_27, 3, 3, 1, 1);

        label_31 = new QLabel(groupBox_3);
        label_31->setObjectName(QStringLiteral("label_31"));

        gridLayout->addWidget(label_31, 2, 0, 1, 1);

        lblRMSE = new QLabel(groupBox_3);
        lblRMSE->setObjectName(QStringLiteral("lblRMSE"));

        gridLayout->addWidget(lblRMSE, 2, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);


        verticalLayout_4->addWidget(groupBox_3);

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
        label_6->setText(QApplication::translate("MLPTrainingDialog", "Algoritmo de entrenamiento", 0));
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
        label_8->setText(QApplication::translate("MLPTrainingDialog", "Pendiente", 0));
        label_5->setText(QApplication::translate("MLPTrainingDialog", "Tasa de aprendizaje", 0));
        label_9->setText(QApplication::translate("MLPTrainingDialog", "Conjunto de entrenamiento", 0));
        btnEditTrainingSet->setText(QApplication::translate("MLPTrainingDialog", "Editar", 0));
        label_30->setText(QApplication::translate("MLPTrainingDialog", "Conjunto de validaci\303\263n", 0));
        btnEditValidationTest->setText(QApplication::translate("MLPTrainingDialog", "Editar", 0));
        btnEditTestSet->setText(QApplication::translate("MLPTrainingDialog", "Editar", 0));
        label_33->setText(QApplication::translate("MLPTrainingDialog", "Conjunto de prueba", 0));
        chkSA->setText(QApplication::translate("MLPTrainingDialog", "Simulated Annealing", 0));
        groupBox_2->setTitle(QApplication::translate("MLPTrainingDialog", "Condici\303\263n de parada", 0));
        label_10->setText(QApplication::translate("MLPTrainingDialog", "Epocas", 0));
        label_35->setText(QApplication::translate("MLPTrainingDialog", "Umbral", 0));
        label_17->setText(QApplication::translate("MLPTrainingDialog", "Condicion de inicio", 0));
        label_21->setText(QApplication::translate("MLPTrainingDialog", "N\302\260 cambios", 0));
        label_15->setText(QApplication::translate("MLPTrainingDialog", "T min", 0));
        label_32->setText(QApplication::translate("MLPTrainingDialog", "F. de decrecimiento de temp.", 0));
        label_18->setText(QApplication::translate("MLPTrainingDialog", "To", 0));
        label_19->setText(QApplication::translate("MLPTrainingDialog", "Valor inferior de ruido", 0));
        label_20->setText(QApplication::translate("MLPTrainingDialog", "Valor superior de ruido", 0));
        btnRandomize->setText(QApplication::translate("MLPTrainingDialog", "Aleatorizar pesos", 0));
        label_28->setText(QApplication::translate("MLPTrainingDialog", "Desde", 0));
        label_29->setText(QApplication::translate("MLPTrainingDialog", "hasta", 0));
        cbStopCondition->clear();
        cbStopCondition->insertItems(0, QStringList()
         << QApplication::translate("MLPTrainingDialog", "MSE minimo", 0)
         << QApplication::translate("MLPTrainingDialog", "RMSE minimo", 0)
         << QApplication::translate("MLPTrainingDialog", "CE minimo", 0)
        );
        label_34->setText(QApplication::translate("MLPTrainingDialog", "Condicion de parada", 0));
        groupBox_3->setTitle(QApplication::translate("MLPTrainingDialog", "Resultados", 0));
        label_12->setText(QApplication::translate("MLPTrainingDialog", "Epocas", 0));
        lblEpochs->setText(QString());
        label_16->setText(QApplication::translate("MLPTrainingDialog", "Tiempo", 0));
        lblTime->setText(QString());
        label_14->setText(QApplication::translate("MLPTrainingDialog", "ECM", 0));
        lblMinError->setText(QString());
        label_22->setText(QApplication::translate("MLPTrainingDialog", "T", 0));
        label_23->setText(QApplication::translate("MLPTrainingDialog", "N\302\260 cambios totales", 0));
        label_24->setText(QApplication::translate("MLPTrainingDialog", "TextLabel", 0));
        label_25->setText(QApplication::translate("MLPTrainingDialog", "TextLabel", 0));
        label_26->setText(QApplication::translate("MLPTrainingDialog", "TextLabel", 0));
        label_27->setText(QApplication::translate("MLPTrainingDialog", "TextLabel", 0));
        label_31->setText(QApplication::translate("MLPTrainingDialog", "RCECM", 0));
        lblRMSE->setText(QString());
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
