/********************************************************************************
** Form generated from reading UI file 'mlptrainingdialog.ui'
**
** Created: Wed 2. Jan 16:22:08 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MLPTRAININGDIALOG_H
#define UI_MLPTRAININGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

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
    QLabel *label_2;
    QLabel *label_3;
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
    QFrame *frame;
    QVBoxLayout *verticalLayout_5;
    QLabel *lblInputs;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *lblOutputs;
    QTableWidget *tblLayers;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_2;
    QLabel *label_10;
    QSpinBox *sbEpochs;
    QLabel *label_11;
    QDoubleSpinBox *sbMinError;
    QPushButton *btnRandomize;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_3;
    QLabel *label_12;
    QLabel *lblEpochs;
    QLabel *label_14;
    QLabel *lblMinError;
    QLabel *label_16;
    QLabel *lblTime;
    QHBoxLayout *buttonsLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnTrain;
    QPushButton *btnCancel;

    void setupUi(QDialog *MLPTrainingDialog)
    {
        if (MLPTrainingDialog->objectName().isEmpty())
            MLPTrainingDialog->setObjectName(QString::fromUtf8("MLPTrainingDialog"));
        MLPTrainingDialog->resize(691, 452);
        verticalLayout_4 = new QVBoxLayout(MLPTrainingDialog);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox = new QGroupBox(MLPTrainingDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        cbTrainingAlgorithm = new QComboBox(groupBox);
        cbTrainingAlgorithm->setObjectName(QString::fromUtf8("cbTrainingAlgorithm"));

        formLayout->setWidget(3, QFormLayout::FieldRole, cbTrainingAlgorithm);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cbTrasnferFunction = new QComboBox(groupBox);
        cbTrasnferFunction->setObjectName(QString::fromUtf8("cbTrasnferFunction"));

        horizontalLayout_2->addWidget(cbTrasnferFunction);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_2->addWidget(label_8);

        sbSlope = new QSpinBox(groupBox);
        sbSlope->setObjectName(QString::fromUtf8("sbSlope"));
        sbSlope->setMaximum(9999999);
        sbSlope->setValue(1);

        horizontalLayout_2->addWidget(sbSlope);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        sbLearningRate = new QDoubleSpinBox(groupBox);
        sbLearningRate->setObjectName(QString::fromUtf8("sbLearningRate"));
        sbLearningRate->setDecimals(4);
        sbLearningRate->setMaximum(1);
        sbLearningRate->setSingleStep(0.01);
        sbLearningRate->setValue(0.5);

        formLayout->setWidget(5, QFormLayout::FieldRole, sbLearningRate);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_9);

        btnEditTrainingSet = new QPushButton(groupBox);
        btnEditTrainingSet->setObjectName(QString::fromUtf8("btnEditTrainingSet"));

        formLayout->setWidget(6, QFormLayout::FieldRole, btnEditTrainingSet);

        frame = new QFrame(groupBox);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame);
        verticalLayout_5->setContentsMargins(3, 3, 3, 3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        lblInputs = new QLabel(frame);
        lblInputs->setObjectName(QString::fromUtf8("lblInputs"));

        verticalLayout_5->addWidget(lblInputs);


        formLayout->setWidget(0, QFormLayout::FieldRole, frame);

        frame_2 = new QFrame(groupBox);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_2);
        verticalLayout_6->setContentsMargins(3, 3, 3, 3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        lblOutputs = new QLabel(frame_2);
        lblOutputs->setObjectName(QString::fromUtf8("lblOutputs"));

        verticalLayout_6->addWidget(lblOutputs);


        formLayout->setWidget(1, QFormLayout::FieldRole, frame_2);

        tblLayers = new QTableWidget(groupBox);
        if (tblLayers->columnCount() < 2)
            tblLayers->setColumnCount(2);
        tblLayers->setObjectName(QString::fromUtf8("tblLayers"));
        tblLayers->setMaximumSize(QSize(150, 80));
        tblLayers->setEditTriggers(QAbstractItemView::NoEditTriggers);
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

        formLayout->setWidget(2, QFormLayout::FieldRole, tblLayers);


        verticalLayout->addLayout(formLayout);


        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(MLPTrainingDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(300, 0));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_10);

        sbEpochs = new QSpinBox(groupBox_2);
        sbEpochs->setObjectName(QString::fromUtf8("sbEpochs"));
        sbEpochs->setMinimum(1);
        sbEpochs->setMaximum(999999999);
        sbEpochs->setValue(500000);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, sbEpochs);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_11);

        sbMinError = new QDoubleSpinBox(groupBox_2);
        sbMinError->setObjectName(QString::fromUtf8("sbMinError"));
        sbMinError->setDecimals(6);
        sbMinError->setMaximum(999.99);
        sbMinError->setSingleStep(0.01);
        sbMinError->setValue(0.01);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, sbMinError);

        btnRandomize = new QPushButton(groupBox_2);
        btnRandomize->setObjectName(QString::fromUtf8("btnRandomize"));
        btnRandomize->setMinimumSize(QSize(100, 0));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, btnRandomize);


        verticalLayout_2->addLayout(formLayout_2);


        horizontalLayout_3->addWidget(groupBox_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        groupBox_3 = new QGroupBox(MLPTrainingDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_12);

        lblEpochs = new QLabel(groupBox_3);
        lblEpochs->setObjectName(QString::fromUtf8("lblEpochs"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lblEpochs);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_14);

        lblMinError = new QLabel(groupBox_3);
        lblMinError->setObjectName(QString::fromUtf8("lblMinError"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, lblMinError);

        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_16);

        lblTime = new QLabel(groupBox_3);
        lblTime->setObjectName(QString::fromUtf8("lblTime"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, lblTime);


        verticalLayout_3->addLayout(formLayout_3);


        verticalLayout_4->addWidget(groupBox_3);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setObjectName(QString::fromUtf8("buttonsLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonsLayout->addItem(horizontalSpacer);

        btnTrain = new QPushButton(MLPTrainingDialog);
        btnTrain->setObjectName(QString::fromUtf8("btnTrain"));
        btnTrain->setDefault(true);
        btnTrain->setFlat(false);

        buttonsLayout->addWidget(btnTrain);

        btnCancel = new QPushButton(MLPTrainingDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        buttonsLayout->addWidget(btnCancel);


        verticalLayout_4->addLayout(buttonsLayout);


        retranslateUi(MLPTrainingDialog);

        QMetaObject::connectSlotsByName(MLPTrainingDialog);
    } // setupUi

    void retranslateUi(QDialog *MLPTrainingDialog)
    {
        MLPTrainingDialog->setWindowTitle(QApplication::translate("MLPTrainingDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MLPTrainingDialog", "Propiedades", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MLPTrainingDialog", "Entradas", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MLPTrainingDialog", "Salidas", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MLPTrainingDialog", "Capas", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MLPTrainingDialog", "Algoritmo de entrenamiento", 0, QApplication::UnicodeUTF8));
        cbTrainingAlgorithm->clear();
        cbTrainingAlgorithm->insertItems(0, QStringList()
         << QApplication::translate("MLPTrainingDialog", "Backpropagation", 0, QApplication::UnicodeUTF8)
        );
        label_7->setText(QApplication::translate("MLPTrainingDialog", "Funcion de transferencia", 0, QApplication::UnicodeUTF8));
        cbTrasnferFunction->clear();
        cbTrasnferFunction->insertItems(0, QStringList()
         << QApplication::translate("MLPTrainingDialog", "Sigmoide", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MLPTrainingDialog", "Tangente", 0, QApplication::UnicodeUTF8)
        );
        label_8->setText(QApplication::translate("MLPTrainingDialog", "Pendiente", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MLPTrainingDialog", "Tasa de aprendizaje", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MLPTrainingDialog", "Conjunto de entrenamiento", 0, QApplication::UnicodeUTF8));
        btnEditTrainingSet->setText(QApplication::translate("MLPTrainingDialog", "Editar", 0, QApplication::UnicodeUTF8));
        lblInputs->setText(QApplication::translate("MLPTrainingDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        lblOutputs->setText(QApplication::translate("MLPTrainingDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MLPTrainingDialog", "Condici\303\263n de parada", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MLPTrainingDialog", "Epocas", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MLPTrainingDialog", "Error m\303\255nimo", 0, QApplication::UnicodeUTF8));
        btnRandomize->setText(QApplication::translate("MLPTrainingDialog", "Aleatorizar pesos", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MLPTrainingDialog", "Resultados", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MLPTrainingDialog", "Epocas totales", 0, QApplication::UnicodeUTF8));
        lblEpochs->setText(QString());
        label_14->setText(QApplication::translate("MLPTrainingDialog", "Error minimo", 0, QApplication::UnicodeUTF8));
        lblMinError->setText(QString());
        label_16->setText(QApplication::translate("MLPTrainingDialog", "Tiempo", 0, QApplication::UnicodeUTF8));
        lblTime->setText(QString());
        btnTrain->setText(QApplication::translate("MLPTrainingDialog", "Entrenar", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("MLPTrainingDialog", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MLPTrainingDialog: public Ui_MLPTrainingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MLPTRAININGDIALOG_H
