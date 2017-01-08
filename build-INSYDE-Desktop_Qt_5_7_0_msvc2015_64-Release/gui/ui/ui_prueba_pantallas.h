/********************************************************************************
** Form generated from reading UI file 'prueba_pantallas.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PruebaPantalla
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *perceptronButton;
    QPushButton *ANNTrainingDialog;
    QPushButton *TrainingSetTableButton;
    QPushButton *WeightEditorDialogButton;
    QPushButton *TrainingSetDialogButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QPushButton *GraphicObjectPropertyDialogButton;
    QPushButton *DotMatrixRepresentationButton;
    QPushButton *DetailedWindowButton;
    QPushButton *BasicDialogButton;
    QPushButton *DataRepresentationBoxButton;
    QPushButton *LabeledComboBoxButton;
    QPushButton *LabeledIntegerSpinBoxButton;
    QPushButton *DoubleMinMaxWidgetButton;
    QPushButton *NormalizationWidgetButton;
    QPushButton *ZoomControlButton;
    QPushButton *SelectImageSegmentButton;
    QPushButton *IntegerSizeWidgetButton;
    QPushButton *BasicTableButton;
    QPushButton *DotMatrixPropertyDialogButton;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QPushButton *systemButton;
    QPushButton *mainWindowButton;
    QPushButton *NewMainWindowButton;
    QPushButton *selectProjectButton;
    QPushButton *newProjectButton;
    QPushButton *chooseProjectNameButton;
    QPushButton *SimulationControlButton;
    QGroupBox *groupBox_4;

    void setupUi(QWidget *PruebaPantalla)
    {
        if (PruebaPantalla->objectName().isEmpty())
            PruebaPantalla->setObjectName(QStringLiteral("PruebaPantalla"));
        PruebaPantalla->resize(883, 730);
        gridLayout = new QGridLayout(PruebaPantalla);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_2 = new QGroupBox(PruebaPantalla);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        perceptronButton = new QPushButton(groupBox_2);
        perceptronButton->setObjectName(QStringLiteral("perceptronButton"));

        gridLayout_2->addWidget(perceptronButton, 3, 0, 1, 1);

        ANNTrainingDialog = new QPushButton(groupBox_2);
        ANNTrainingDialog->setObjectName(QStringLiteral("ANNTrainingDialog"));

        gridLayout_2->addWidget(ANNTrainingDialog, 0, 0, 1, 1);

        TrainingSetTableButton = new QPushButton(groupBox_2);
        TrainingSetTableButton->setObjectName(QStringLiteral("TrainingSetTableButton"));

        gridLayout_2->addWidget(TrainingSetTableButton, 5, 0, 1, 1);

        WeightEditorDialogButton = new QPushButton(groupBox_2);
        WeightEditorDialogButton->setObjectName(QStringLiteral("WeightEditorDialogButton"));

        gridLayout_2->addWidget(WeightEditorDialogButton, 4, 0, 1, 1);

        TrainingSetDialogButton = new QPushButton(groupBox_2);
        TrainingSetDialogButton->setObjectName(QStringLiteral("TrainingSetDialogButton"));

        gridLayout_2->addWidget(TrainingSetDialogButton, 2, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 6, 1, 1, 1, Qt::AlignTop);

        groupBox = new QGroupBox(PruebaPantalla);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        GraphicObjectPropertyDialogButton = new QPushButton(groupBox);
        GraphicObjectPropertyDialogButton->setObjectName(QStringLiteral("GraphicObjectPropertyDialogButton"));

        gridLayout_4->addWidget(GraphicObjectPropertyDialogButton, 12, 0, 1, 1);

        DotMatrixRepresentationButton = new QPushButton(groupBox);
        DotMatrixRepresentationButton->setObjectName(QStringLiteral("DotMatrixRepresentationButton"));

        gridLayout_4->addWidget(DotMatrixRepresentationButton, 3, 0, 1, 1);

        DetailedWindowButton = new QPushButton(groupBox);
        DetailedWindowButton->setObjectName(QStringLiteral("DetailedWindowButton"));

        gridLayout_4->addWidget(DetailedWindowButton, 1, 0, 1, 1);

        BasicDialogButton = new QPushButton(groupBox);
        BasicDialogButton->setObjectName(QStringLiteral("BasicDialogButton"));

        gridLayout_4->addWidget(BasicDialogButton, 5, 0, 1, 1);

        DataRepresentationBoxButton = new QPushButton(groupBox);
        DataRepresentationBoxButton->setObjectName(QStringLiteral("DataRepresentationBoxButton"));

        gridLayout_4->addWidget(DataRepresentationBoxButton, 4, 0, 1, 1);

        LabeledComboBoxButton = new QPushButton(groupBox);
        LabeledComboBoxButton->setObjectName(QStringLiteral("LabeledComboBoxButton"));

        gridLayout_4->addWidget(LabeledComboBoxButton, 10, 0, 1, 1);

        LabeledIntegerSpinBoxButton = new QPushButton(groupBox);
        LabeledIntegerSpinBoxButton->setObjectName(QStringLiteral("LabeledIntegerSpinBoxButton"));

        gridLayout_4->addWidget(LabeledIntegerSpinBoxButton, 8, 0, 1, 1);

        DoubleMinMaxWidgetButton = new QPushButton(groupBox);
        DoubleMinMaxWidgetButton->setObjectName(QStringLiteral("DoubleMinMaxWidgetButton"));

        gridLayout_4->addWidget(DoubleMinMaxWidgetButton, 11, 0, 1, 1);

        NormalizationWidgetButton = new QPushButton(groupBox);
        NormalizationWidgetButton->setObjectName(QStringLiteral("NormalizationWidgetButton"));

        gridLayout_4->addWidget(NormalizationWidgetButton, 0, 0, 1, 1);

        ZoomControlButton = new QPushButton(groupBox);
        ZoomControlButton->setObjectName(QStringLiteral("ZoomControlButton"));

        gridLayout_4->addWidget(ZoomControlButton, 2, 0, 1, 1);

        SelectImageSegmentButton = new QPushButton(groupBox);
        SelectImageSegmentButton->setObjectName(QStringLiteral("SelectImageSegmentButton"));

        gridLayout_4->addWidget(SelectImageSegmentButton, 7, 0, 1, 1);

        IntegerSizeWidgetButton = new QPushButton(groupBox);
        IntegerSizeWidgetButton->setObjectName(QStringLiteral("IntegerSizeWidgetButton"));

        gridLayout_4->addWidget(IntegerSizeWidgetButton, 9, 0, 1, 1);

        BasicTableButton = new QPushButton(groupBox);
        BasicTableButton->setObjectName(QStringLiteral("BasicTableButton"));

        gridLayout_4->addWidget(BasicTableButton, 6, 0, 1, 1);

        DotMatrixPropertyDialogButton = new QPushButton(groupBox);
        DotMatrixPropertyDialogButton->setObjectName(QStringLiteral("DotMatrixPropertyDialogButton"));

        gridLayout_4->addWidget(DotMatrixPropertyDialogButton, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox, 6, 0, 1, 1, Qt::AlignTop);

        groupBox_3 = new QGroupBox(PruebaPantalla);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        systemButton = new QPushButton(groupBox_3);
        systemButton->setObjectName(QStringLiteral("systemButton"));

        gridLayout_3->addWidget(systemButton, 2, 0, 1, 1);

        mainWindowButton = new QPushButton(groupBox_3);
        mainWindowButton->setObjectName(QStringLiteral("mainWindowButton"));

        gridLayout_3->addWidget(mainWindowButton, 1, 0, 1, 1);

        NewMainWindowButton = new QPushButton(groupBox_3);
        NewMainWindowButton->setObjectName(QStringLiteral("NewMainWindowButton"));

        gridLayout_3->addWidget(NewMainWindowButton, 0, 0, 1, 1);

        selectProjectButton = new QPushButton(groupBox_3);
        selectProjectButton->setObjectName(QStringLiteral("selectProjectButton"));

        gridLayout_3->addWidget(selectProjectButton, 4, 0, 1, 1);

        newProjectButton = new QPushButton(groupBox_3);
        newProjectButton->setObjectName(QStringLiteral("newProjectButton"));

        gridLayout_3->addWidget(newProjectButton, 3, 0, 1, 1);

        chooseProjectNameButton = new QPushButton(groupBox_3);
        chooseProjectNameButton->setObjectName(QStringLiteral("chooseProjectNameButton"));

        gridLayout_3->addWidget(chooseProjectNameButton, 5, 0, 1, 1);

        SimulationControlButton = new QPushButton(groupBox_3);
        SimulationControlButton->setObjectName(QStringLiteral("SimulationControlButton"));

        gridLayout_3->addWidget(SimulationControlButton, 6, 0, 1, 1);


        gridLayout->addWidget(groupBox_3, 7, 0, 1, 1, Qt::AlignTop);

        groupBox_4 = new QGroupBox(PruebaPantalla);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));

        gridLayout->addWidget(groupBox_4, 7, 1, 1, 1);


        retranslateUi(PruebaPantalla);

        QMetaObject::connectSlotsByName(PruebaPantalla);
    } // setupUi

    void retranslateUi(QWidget *PruebaPantalla)
    {
        PruebaPantalla->setWindowTitle(QApplication::translate("PruebaPantalla", "Form", 0));
        groupBox_2->setTitle(QApplication::translate("PruebaPantalla", "ann_gui", 0));
        perceptronButton->setText(QApplication::translate("PruebaPantalla", "PerceptronPage", 0));
        ANNTrainingDialog->setText(QApplication::translate("PruebaPantalla", "ANNTrainingDialog", 0));
        TrainingSetTableButton->setText(QApplication::translate("PruebaPantalla", "TrainingSetTable", 0));
        WeightEditorDialogButton->setText(QApplication::translate("PruebaPantalla", "WeightEditorDialog", 0));
        TrainingSetDialogButton->setText(QApplication::translate("PruebaPantalla", "TrainingSetDialog", 0));
        groupBox->setTitle(QApplication::translate("PruebaPantalla", "core", 0));
        GraphicObjectPropertyDialogButton->setText(QApplication::translate("PruebaPantalla", "GraphicObjectPropertyDialog", 0));
        DotMatrixRepresentationButton->setText(QApplication::translate("PruebaPantalla", "DotMatrixRepresentation", 0));
        DetailedWindowButton->setText(QApplication::translate("PruebaPantalla", "DetailedWindow", 0));
        BasicDialogButton->setText(QApplication::translate("PruebaPantalla", "BasicDialog", 0));
        DataRepresentationBoxButton->setText(QApplication::translate("PruebaPantalla", "DataRepresentationBox", 0));
        LabeledComboBoxButton->setText(QApplication::translate("PruebaPantalla", "LabeledComboBox", 0));
        LabeledIntegerSpinBoxButton->setText(QApplication::translate("PruebaPantalla", "LabeledIntegerSpinBox", 0));
        DoubleMinMaxWidgetButton->setText(QApplication::translate("PruebaPantalla", "DoubleMinMaxWidget", 0));
        NormalizationWidgetButton->setText(QApplication::translate("PruebaPantalla", "NormalizationWidget", 0));
        ZoomControlButton->setText(QApplication::translate("PruebaPantalla", "ZoomControl", 0));
        SelectImageSegmentButton->setText(QApplication::translate("PruebaPantalla", "SelectImageSegment", 0));
        IntegerSizeWidgetButton->setText(QApplication::translate("PruebaPantalla", "IntegerSizeWidget", 0));
        BasicTableButton->setText(QApplication::translate("PruebaPantalla", "BasicTable", 0));
        DotMatrixPropertyDialogButton->setText(QApplication::translate("PruebaPantalla", "DotMatrixPropertyDialog", 0));
        groupBox_3->setTitle(QApplication::translate("PruebaPantalla", "gui", 0));
        systemButton->setText(QApplication::translate("PruebaPantalla", "System", 0));
        mainWindowButton->setText(QApplication::translate("PruebaPantalla", "Main Window", 0));
        NewMainWindowButton->setText(QApplication::translate("PruebaPantalla", "NewMainWindow", 0));
        selectProjectButton->setText(QApplication::translate("PruebaPantalla", "Select project", 0));
        newProjectButton->setText(QApplication::translate("PruebaPantalla", "New project", 0));
        chooseProjectNameButton->setText(QApplication::translate("PruebaPantalla", "Choose project name", 0));
        SimulationControlButton->setText(QApplication::translate("PruebaPantalla", "SimulationControl", 0));
        groupBox_4->setTitle(QApplication::translate("PruebaPantalla", "ec_gui", 0));
    } // retranslateUi

};

namespace Ui {
    class PruebaPantalla: public Ui_PruebaPantalla {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRUEBA_PANTALLAS_H
