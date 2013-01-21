/********************************************************************************
** Form generated from reading UI file 'perceptronpage.ui'
**
** Created: Sat 19. Jan 16:02:31 2013
**      by: Qt User Interface Compiler version 5.0.0
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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
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
    QLineEdit *leName;
    QLabel *label;
    QSpinBox *sbInputs;
    QLabel *label_3;
    QComboBox *cbTransferFunction;
    QLabel *label_4;
    QComboBox *cbLearningRule;
    QFrame *line;
    QLabel *conjuntoDeEntranamientoLabel;
    QPushButton *btnTrainingSet;
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

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_18);

        leName = new QLineEdit(frame);
        leName->setObjectName(QStringLiteral("leName"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, leName);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label);

        sbInputs = new QSpinBox(frame);
        sbInputs->setObjectName(QStringLiteral("sbInputs"));
        sbInputs->setMinimum(1);
        sbInputs->setMaximum(10000);
        sbInputs->setValue(10);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, sbInputs);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        cbTransferFunction = new QComboBox(frame);
        cbTransferFunction->setObjectName(QStringLiteral("cbTransferFunction"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, cbTransferFunction);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_4);

        cbLearningRule = new QComboBox(frame);
        cbLearningRule->setObjectName(QStringLiteral("cbLearningRule"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, cbLearningRule);

        line = new QFrame(frame);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        formLayout_2->setWidget(5, QFormLayout::SpanningRole, line);

        conjuntoDeEntranamientoLabel = new QLabel(frame);
        conjuntoDeEntranamientoLabel->setObjectName(QStringLiteral("conjuntoDeEntranamientoLabel"));

        formLayout_2->setWidget(7, QFormLayout::LabelRole, conjuntoDeEntranamientoLabel);

        btnTrainingSet = new QPushButton(frame);
        btnTrainingSet->setObjectName(QStringLiteral("btnTrainingSet"));

        formLayout_2->setWidget(7, QFormLayout::FieldRole, btnTrainingSet);


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
        conjuntoDeEntranamientoLabel->setText(QApplication::translate("PerceptronPage", "Conjunto de entrenamiento", 0));
        btnTrainingSet->setText(QApplication::translate("PerceptronPage", "Asignar", 0));
    } // retranslateUi

};

namespace Ui {
    class PerceptronPage: public Ui_PerceptronPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERCEPTRONPAGE_H
