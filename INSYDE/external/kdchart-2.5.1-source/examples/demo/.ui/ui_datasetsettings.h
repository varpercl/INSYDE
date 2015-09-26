/********************************************************************************
** Form generated from reading UI file 'datasetsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATASETSETTINGS_H
#define UI_DATASETSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatasetSettings
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *datasetSelector;
    QGroupBox *Colors;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *Color;
    QRadioButton *radioButton_2;
    QRadioButton *textureBtn;
    QPushButton *colorDisplay;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QPushButton *outlineBtn;
    QSpacerItem *verticalSpacer;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *DatasetSettings)
    {
        if (DatasetSettings->objectName().isEmpty())
            DatasetSettings->setObjectName(QStringLiteral("DatasetSettings"));
        DatasetSettings->resize(400, 300);
        verticalLayout = new QVBoxLayout(DatasetSettings);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        datasetSelector = new QComboBox(DatasetSettings);
        datasetSelector->setObjectName(QStringLiteral("datasetSelector"));

        verticalLayout->addWidget(datasetSelector);

        Colors = new QGroupBox(DatasetSettings);
        Colors->setObjectName(QStringLiteral("Colors"));
        Colors->setAlignment(Qt::AlignCenter);
        verticalLayout_2 = new QVBoxLayout(Colors);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        Color = new QRadioButton(Colors);
        buttonGroup = new QButtonGroup(DatasetSettings);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(Color);
        Color->setObjectName(QStringLiteral("Color"));
        Color->setChecked(true);

        verticalLayout_3->addWidget(Color);

        radioButton_2 = new QRadioButton(Colors);
        buttonGroup->addButton(radioButton_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout_3->addWidget(radioButton_2);

        textureBtn = new QRadioButton(Colors);
        buttonGroup->addButton(textureBtn);
        textureBtn->setObjectName(QStringLiteral("textureBtn"));

        verticalLayout_3->addWidget(textureBtn);


        verticalLayout_2->addLayout(verticalLayout_3);

        colorDisplay = new QPushButton(Colors);
        colorDisplay->setObjectName(QStringLiteral("colorDisplay"));

        verticalLayout_2->addWidget(colorDisplay);


        verticalLayout->addWidget(Colors);

        groupBox = new QGroupBox(DatasetSettings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        outlineBtn = new QPushButton(groupBox);
        outlineBtn->setObjectName(QStringLiteral("outlineBtn"));

        verticalLayout_4->addWidget(outlineBtn);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(DatasetSettings);

        QMetaObject::connectSlotsByName(DatasetSettings);
    } // setupUi

    void retranslateUi(QWidget *DatasetSettings)
    {
        DatasetSettings->setWindowTitle(QApplication::translate("DatasetSettings", "Form", 0));
        Colors->setTitle(QApplication::translate("DatasetSettings", "Color", 0));
        Color->setText(QApplication::translate("DatasetSettings", "Color", 0));
        radioButton_2->setText(QApplication::translate("DatasetSettings", "Gradient", 0));
        textureBtn->setText(QApplication::translate("DatasetSettings", "Texture", 0));
        colorDisplay->setText(QString());
        groupBox->setTitle(QApplication::translate("DatasetSettings", "Outline", 0));
        outlineBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DatasetSettings: public Ui_DatasetSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATASETSETTINGS_H
