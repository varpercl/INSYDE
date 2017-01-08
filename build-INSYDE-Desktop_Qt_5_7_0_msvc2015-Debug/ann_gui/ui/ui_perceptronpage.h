/********************************************************************************
** Form generated from reading UI file 'perceptronpage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERCEPTRONPAGE_H
#define UI_PERCEPTRONPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_PerceptronPage
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QFormLayout *formLayout_2;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *leName;
    QLabel *label;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *sbInputs;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *cbTransferFunction;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *cbLearningRule;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnEditWeights;
    QSpacerItem *horizontalSpacer;
    QFrame *line;
    QLabel *conjuntoDeEntranamientoLabel;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnEditTrainingSet;
    QSpacerItem *horizontalSpacer_2;
    QGraphicsView *gvPerceptronDisplay;

    void setupUi(QWizardPage *PerceptronPage)
    {
        if (PerceptronPage->objectName().isEmpty())
            PerceptronPage->setObjectName(QStringLiteral("PerceptronPage"));
        PerceptronPage->resize(650, 394);
        verticalLayout = new QVBoxLayout(PerceptronPage);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(PerceptronPage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout_2 = new QFormLayout(frame);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_18 = new QLabel(frame);
        label_18->setObjectName(QStringLiteral("label_18"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_18);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        leName = new QLineEdit(frame);
        leName->setObjectName(QStringLiteral("leName"));

        horizontalLayout_7->addWidget(leName);


        formLayout_2->setLayout(1, QFormLayout::FieldRole, horizontalLayout_7);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        sbInputs = new QSpinBox(frame);
        sbInputs->setObjectName(QStringLiteral("sbInputs"));
        sbInputs->setMinimum(1);
        sbInputs->setMaximum(10000);
        sbInputs->setValue(10);

        horizontalLayout_6->addWidget(sbInputs);


        formLayout_2->setLayout(2, QFormLayout::FieldRole, horizontalLayout_6);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        cbTransferFunction = new QComboBox(frame);
        cbTransferFunction->setObjectName(QStringLiteral("cbTransferFunction"));

        horizontalLayout_3->addWidget(cbTransferFunction);


        formLayout_2->setLayout(3, QFormLayout::FieldRole, horizontalLayout_3);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        cbLearningRule = new QComboBox(frame);
        cbLearningRule->setObjectName(QStringLiteral("cbLearningRule"));

        horizontalLayout_5->addWidget(cbLearningRule);


        formLayout_2->setLayout(4, QFormLayout::FieldRole, horizontalLayout_5);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnEditWeights = new QPushButton(frame);
        btnEditWeights->setObjectName(QStringLiteral("btnEditWeights"));

        horizontalLayout->addWidget(btnEditWeights);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        formLayout_2->setLayout(5, QFormLayout::FieldRole, horizontalLayout);

        line = new QFrame(frame);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        formLayout_2->setWidget(19, QFormLayout::LabelRole, line);

        conjuntoDeEntranamientoLabel = new QLabel(frame);
        conjuntoDeEntranamientoLabel->setObjectName(QStringLiteral("conjuntoDeEntranamientoLabel"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, conjuntoDeEntranamientoLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btnEditTrainingSet = new QPushButton(frame);
        btnEditTrainingSet->setObjectName(QStringLiteral("btnEditTrainingSet"));

        horizontalLayout_2->addWidget(btnEditTrainingSet);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        formLayout_2->setLayout(6, QFormLayout::FieldRole, horizontalLayout_2);


        verticalLayout->addWidget(frame);

        gvPerceptronDisplay = new QGraphicsView(PerceptronPage);
        gvPerceptronDisplay->setObjectName(QStringLiteral("gvPerceptronDisplay"));

        verticalLayout->addWidget(gvPerceptronDisplay);


        retranslateUi(PerceptronPage);

        QMetaObject::connectSlotsByName(PerceptronPage);
    } // setupUi

    void retranslateUi(QWizardPage *PerceptronPage)
    {
        PerceptronPage->setWindowTitle(QApplication::translate("PerceptronPage", "WizardPage", 0));
        label_18->setText(QApplication::translate("PerceptronPage", "Nombre", 0));
        leName->setText(QApplication::translate("PerceptronPage", "Perceptron", 0));
        leName->setPlaceholderText(QString());
        label->setText(QApplication::translate("PerceptronPage", "Numero de entradas", 0));
        label_3->setText(QApplication::translate("PerceptronPage", "Funci\303\263n de transferencia", 0));
        cbTransferFunction->clear();
        cbTransferFunction->insertItems(0, QStringList()
         << QApplication::translate("PerceptronPage", "Escalon unipolar", 0)
         << QApplication::translate("PerceptronPage", "Escalon bipolar", 0)
         << QApplication::translate("PerceptronPage", "Sigmoide", 0)
         << QApplication::translate("PerceptronPage", "Tangente hiperbolica", 0)
         << QApplication::translate("PerceptronPage", "Lineal", 0)
         << QApplication::translate("PerceptronPage", "Lineal limitada unipolar", 0)
         << QApplication::translate("PerceptronPage", "Lineal limitada bipolar", 0)
        );
        label_4->setText(QApplication::translate("PerceptronPage", "Regla de aprendizaje", 0));
        cbLearningRule->clear();
        cbLearningRule->insertItems(0, QStringList()
         << QApplication::translate("PerceptronPage", "Regla simple", 0)
         << QApplication::translate("PerceptronPage", "Regla delta", 0)
        );
        label_2->setText(QApplication::translate("PerceptronPage", "Pesos sinapticos", 0));
        btnEditWeights->setText(QApplication::translate("PerceptronPage", "Editar...", 0));
        conjuntoDeEntranamientoLabel->setText(QApplication::translate("PerceptronPage", "Conjunto de entrenamiento", 0));
        btnEditTrainingSet->setText(QApplication::translate("PerceptronPage", "Editar...", 0));
    } // retranslateUi

};

namespace Ui {
    class PerceptronPage: public Ui_PerceptronPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERCEPTRONPAGE_H
