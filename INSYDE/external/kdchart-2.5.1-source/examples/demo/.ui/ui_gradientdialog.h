/********************************************************************************
** Form generated from reading UI file 'gradientdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRADIENTDIALOG_H
#define UI_GRADIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GradientDialog
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *GradientType;
    QWidget *gradientDisplay;
    QGroupBox *gradientStopBox;
    QVBoxLayout *verticalLayout_2;
    QComboBox *stopSelector;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QDoubleSpinBox *stopPosition;
    QHBoxLayout *horizontalLayout;
    QPushButton *newStop;
    QPushButton *deleteStop;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GradientDialog)
    {
        if (GradientDialog->objectName().isEmpty())
            GradientDialog->setObjectName(QStringLiteral("GradientDialog"));
        GradientDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(GradientDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        GradientType = new QComboBox(GradientDialog);
        GradientType->setObjectName(QStringLiteral("GradientType"));

        verticalLayout->addWidget(GradientType);

        gradientDisplay = new QWidget(GradientDialog);
        gradientDisplay->setObjectName(QStringLiteral("gradientDisplay"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gradientDisplay->sizePolicy().hasHeightForWidth());
        gradientDisplay->setSizePolicy(sizePolicy);
        gradientDisplay->setMinimumSize(QSize(0, 50));
        gradientDisplay->setMaximumSize(QSize(16777215, 50));
        gradientDisplay->setAutoFillBackground(true);

        verticalLayout->addWidget(gradientDisplay);

        gradientStopBox = new QGroupBox(GradientDialog);
        gradientStopBox->setObjectName(QStringLiteral("gradientStopBox"));
        gradientStopBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayout_2 = new QVBoxLayout(gradientStopBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        stopSelector = new QComboBox(gradientStopBox);
        stopSelector->setObjectName(QStringLiteral("stopSelector"));

        verticalLayout_2->addWidget(stopSelector);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(gradientStopBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        stopPosition = new QDoubleSpinBox(gradientStopBox);
        stopPosition->setObjectName(QStringLiteral("stopPosition"));
        stopPosition->setWrapping(true);
        stopPosition->setAccelerated(true);
        stopPosition->setMinimum(-1e+09);
        stopPosition->setMaximum(1e+09);

        horizontalLayout_3->addWidget(stopPosition);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        newStop = new QPushButton(gradientStopBox);
        newStop->setObjectName(QStringLiteral("newStop"));

        horizontalLayout->addWidget(newStop);

        deleteStop = new QPushButton(gradientStopBox);
        deleteStop->setObjectName(QStringLiteral("deleteStop"));

        horizontalLayout->addWidget(deleteStop);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addWidget(gradientStopBox);

        buttonBox = new QDialogButtonBox(GradientDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(GradientDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), GradientDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GradientDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GradientDialog);
    } // setupUi

    void retranslateUi(QDialog *GradientDialog)
    {
        GradientDialog->setWindowTitle(QApplication::translate("GradientDialog", "Dialog", 0));
        gradientStopBox->setTitle(QApplication::translate("GradientDialog", "GradientStop", 0));
        label->setText(QApplication::translate("GradientDialog", "Position", 0));
        newStop->setText(QApplication::translate("GradientDialog", "New Stop", 0));
        deleteStop->setText(QApplication::translate("GradientDialog", "DeleteStop", 0));
    } // retranslateUi

};

namespace Ui {
    class GradientDialog: public Ui_GradientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADIENTDIALOG_H
