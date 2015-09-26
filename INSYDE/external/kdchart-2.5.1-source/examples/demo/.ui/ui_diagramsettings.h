/********************************************************************************
** Form generated from reading UI file 'diagramsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIAGRAMSETTINGS_H
#define UI_DIAGRAMSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DiagramSettings
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *threeDSelector;
    QCheckBox *autoGradient;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *barHeightInput;
    QGroupBox *barAttributes;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *barWidthInput;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *visibleBtn;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *color;
    QRadioButton *gradient;
    QRadioButton *textureBtn;
    QPushButton *diagramBackground;
    QSpacerItem *verticalSpacer;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *DiagramSettings)
    {
        if (DiagramSettings->objectName().isEmpty())
            DiagramSettings->setObjectName(QStringLiteral("DiagramSettings"));
        DiagramSettings->resize(314, 357);
        verticalLayout = new QVBoxLayout(DiagramSettings);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(DiagramSettings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        threeDSelector = new QCheckBox(groupBox);
        threeDSelector->setObjectName(QStringLiteral("threeDSelector"));

        verticalLayout_2->addWidget(threeDSelector);

        autoGradient = new QCheckBox(groupBox);
        autoGradient->setObjectName(QStringLiteral("autoGradient"));

        verticalLayout_2->addWidget(autoGradient);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        barHeightInput = new QSpinBox(groupBox);
        barHeightInput->setObjectName(QStringLiteral("barHeightInput"));

        horizontalLayout_2->addWidget(barHeightInput);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(groupBox);

        barAttributes = new QGroupBox(DiagramSettings);
        barAttributes->setObjectName(QStringLiteral("barAttributes"));
        verticalLayout_3 = new QVBoxLayout(barAttributes);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(barAttributes);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        barWidthInput = new QSpinBox(barAttributes);
        barWidthInput->setObjectName(QStringLiteral("barWidthInput"));

        horizontalLayout_3->addWidget(barWidthInput);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(barAttributes);

        groupBox_3 = new QGroupBox(DiagramSettings);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        visibleBtn = new QCheckBox(groupBox_3);
        visibleBtn->setObjectName(QStringLiteral("visibleBtn"));

        verticalLayout_4->addWidget(visibleBtn);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        color = new QRadioButton(groupBox_3);
        buttonGroup = new QButtonGroup(DiagramSettings);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(color);
        color->setObjectName(QStringLiteral("color"));
        color->setChecked(true);

        verticalLayout_5->addWidget(color);

        gradient = new QRadioButton(groupBox_3);
        buttonGroup->addButton(gradient);
        gradient->setObjectName(QStringLiteral("gradient"));

        verticalLayout_5->addWidget(gradient);

        textureBtn = new QRadioButton(groupBox_3);
        buttonGroup->addButton(textureBtn);
        textureBtn->setObjectName(QStringLiteral("textureBtn"));

        verticalLayout_5->addWidget(textureBtn);


        verticalLayout_4->addLayout(verticalLayout_5);

        diagramBackground = new QPushButton(groupBox_3);
        diagramBackground->setObjectName(QStringLiteral("diagramBackground"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(diagramBackground->sizePolicy().hasHeightForWidth());
        diagramBackground->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(diagramBackground);


        verticalLayout->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(DiagramSettings);

        QMetaObject::connectSlotsByName(DiagramSettings);
    } // setupUi

    void retranslateUi(QWidget *DiagramSettings)
    {
        DiagramSettings->setWindowTitle(QApplication::translate("DiagramSettings", "Form", 0));
        groupBox->setTitle(QApplication::translate("DiagramSettings", "3D Settings", 0));
        threeDSelector->setText(QApplication::translate("DiagramSettings", "3D", 0));
        autoGradient->setText(QApplication::translate("DiagramSettings", "Auto Gradient", 0));
        label_3->setText(QApplication::translate("DiagramSettings", "3D Depth", 0));
        barAttributes->setTitle(QApplication::translate("DiagramSettings", "Bar Attributes", 0));
        label_2->setText(QApplication::translate("DiagramSettings", "Bar Width", 0));
        groupBox_3->setTitle(QApplication::translate("DiagramSettings", "Diagram Background", 0));
        visibleBtn->setText(QApplication::translate("DiagramSettings", "Visible", 0));
        color->setText(QApplication::translate("DiagramSettings", "Color", 0));
        gradient->setText(QApplication::translate("DiagramSettings", "Gradient", 0));
        textureBtn->setText(QApplication::translate("DiagramSettings", "Texture", 0));
        diagramBackground->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DiagramSettings: public Ui_DiagramSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAGRAMSETTINGS_H
