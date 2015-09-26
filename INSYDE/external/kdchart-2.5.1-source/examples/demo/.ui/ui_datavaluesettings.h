/********************************************************************************
** Form generated from reading UI file 'datavaluesettings.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAVALUESETTINGS_H
#define UI_DATAVALUESETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataValueSettings
{
public:
    QGridLayout *gridLayout;
    QSpinBox *relativeSizeSB;
    QGroupBox *groupBox;
    QGridLayout *gridLayout1;
    QLabel *label;
    QLabel *label_2;
    QRadioButton *scopeOneBarRB;
    QSpinBox *scopeBarDatasetSB;
    QSpinBox *scopeBarItemSB;
    QRadioButton *scopeDatasetRB;
    QSpinBox *scopeDatasetSB;
    QRadioButton *scopeCommonRB;
    QSpacerItem *spacerItem;
    QCheckBox *paintValuesCB;
    QFrame *line_3;
    QHBoxLayout *hboxLayout;
    QLabel *barTypeLB;
    QFontComboBox *fontCombo;
    QLabel *barOrientationLB_4;
    QSpinBox *negPadHoriSB;
    QLabel *barOrientationLB_3;
    QSpinBox *minimumSizeSB;
    QLabel *barOrientationLB_2;
    QSpinBox *rotationSB;
    QSpacerItem *spacerItem1;
    QLabel *barOrientationLB;
    QComboBox *posPosCombo;
    QLabel *barOrientationLB_7;
    QComboBox *posAlignCombo;
    QLabel *barOrientationLB_6;
    QLabel *barOrientationLB_9;
    QSpinBox *posPadHoriSB;
    QLabel *barOrientationLB_10;
    QSpinBox *posPadVertSB;
    QSpacerItem *spacerItem2;
    QLabel *barOrientationLB_5;
    QComboBox *negPosCombo;
    QLabel *barOrientationLB_8;
    QComboBox *negAlignCombo;
    QLabel *barOrientationLB_11;
    QLabel *barOrientationLB_12;
    QLabel *barOrientationLB_13;
    QSpinBox *negPadVertSB;
    QSpacerItem *spacerItem3;
    QGridLayout *gridLayout2;
    QLabel *label_3;
    QLineEdit *labelLE;
    QLabel *label_4;
    QLineEdit *prefixLE;
    QLabel *label_5;
    QLineEdit *suffixLE;

    void setupUi(QWidget *DataValueSettings)
    {
        if (DataValueSettings->objectName().isEmpty())
            DataValueSettings->setObjectName(QStringLiteral("DataValueSettings"));
        DataValueSettings->resize(585, 698);
        QIcon icon;
        icon.addFile(QStringLiteral("../DataValueTexts"), QSize(), QIcon::Normal, QIcon::Off);
        DataValueSettings->setWindowIcon(icon);
        gridLayout = new QGridLayout(DataValueSettings);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        relativeSizeSB = new QSpinBox(DataValueSettings);
        relativeSizeSB->setObjectName(QStringLiteral("relativeSizeSB"));

        gridLayout->addWidget(relativeSizeSB, 5, 2, 1, 4);

        groupBox = new QGroupBox(DataValueSettings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout1 = new QGridLayout(groupBox);
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout1->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout1->addWidget(label_2, 0, 2, 1, 1);

        scopeOneBarRB = new QRadioButton(groupBox);
        scopeOneBarRB->setObjectName(QStringLiteral("scopeOneBarRB"));

        gridLayout1->addWidget(scopeOneBarRB, 1, 0, 1, 1);

        scopeBarDatasetSB = new QSpinBox(groupBox);
        scopeBarDatasetSB->setObjectName(QStringLiteral("scopeBarDatasetSB"));
        scopeBarDatasetSB->setMaximum(3);

        gridLayout1->addWidget(scopeBarDatasetSB, 1, 1, 1, 1);

        scopeBarItemSB = new QSpinBox(groupBox);
        scopeBarItemSB->setObjectName(QStringLiteral("scopeBarItemSB"));
        scopeBarItemSB->setMaximum(3);

        gridLayout1->addWidget(scopeBarItemSB, 1, 2, 1, 1);

        scopeDatasetRB = new QRadioButton(groupBox);
        scopeDatasetRB->setObjectName(QStringLiteral("scopeDatasetRB"));

        gridLayout1->addWidget(scopeDatasetRB, 2, 0, 1, 1);

        scopeDatasetSB = new QSpinBox(groupBox);
        scopeDatasetSB->setObjectName(QStringLiteral("scopeDatasetSB"));
        scopeDatasetSB->setMaximum(3);

        gridLayout1->addWidget(scopeDatasetSB, 2, 1, 1, 1);

        scopeCommonRB = new QRadioButton(groupBox);
        scopeCommonRB->setObjectName(QStringLiteral("scopeCommonRB"));

        gridLayout1->addWidget(scopeCommonRB, 3, 0, 1, 2);


        gridLayout->addWidget(groupBox, 0, 0, 1, 6);

        spacerItem = new QSpacerItem(54, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 1, 1, 1, 2);

        paintValuesCB = new QCheckBox(DataValueSettings);
        paintValuesCB->setObjectName(QStringLiteral("paintValuesCB"));

        gridLayout->addWidget(paintValuesCB, 2, 0, 1, 6);

        line_3 = new QFrame(DataValueSettings);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 3, 0, 1, 6);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        barTypeLB = new QLabel(DataValueSettings);
        barTypeLB->setObjectName(QStringLiteral("barTypeLB"));

        hboxLayout->addWidget(barTypeLB);

        fontCombo = new QFontComboBox(DataValueSettings);
        fontCombo->setObjectName(QStringLiteral("fontCombo"));

        hboxLayout->addWidget(fontCombo);


        gridLayout->addLayout(hboxLayout, 4, 0, 1, 6);

        barOrientationLB_4 = new QLabel(DataValueSettings);
        barOrientationLB_4->setObjectName(QStringLiteral("barOrientationLB_4"));

        gridLayout->addWidget(barOrientationLB_4, 5, 0, 1, 2);

        negPadHoriSB = new QSpinBox(DataValueSettings);
        negPadHoriSB->setObjectName(QStringLiteral("negPadHoriSB"));
        negPadHoriSB->setMinimum(-1000);
        negPadHoriSB->setMaximum(1000);
        negPadHoriSB->setSingleStep(100);

        gridLayout->addWidget(negPadHoriSB, 15, 3, 1, 1);

        barOrientationLB_3 = new QLabel(DataValueSettings);
        barOrientationLB_3->setObjectName(QStringLiteral("barOrientationLB_3"));

        gridLayout->addWidget(barOrientationLB_3, 6, 0, 1, 2);

        minimumSizeSB = new QSpinBox(DataValueSettings);
        minimumSizeSB->setObjectName(QStringLiteral("minimumSizeSB"));

        gridLayout->addWidget(minimumSizeSB, 6, 2, 1, 4);

        barOrientationLB_2 = new QLabel(DataValueSettings);
        barOrientationLB_2->setObjectName(QStringLiteral("barOrientationLB_2"));

        gridLayout->addWidget(barOrientationLB_2, 7, 0, 1, 1);

        rotationSB = new QSpinBox(DataValueSettings);
        rotationSB->setObjectName(QStringLiteral("rotationSB"));
        rotationSB->setMinimum(-359);
        rotationSB->setMaximum(359);
        rotationSB->setSingleStep(15);

        gridLayout->addWidget(rotationSB, 7, 2, 1, 4);

        spacerItem1 = new QSpacerItem(54, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem1, 8, 1, 1, 2);

        barOrientationLB = new QLabel(DataValueSettings);
        barOrientationLB->setObjectName(QStringLiteral("barOrientationLB"));
        QFont font;
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        barOrientationLB->setFont(font);

        gridLayout->addWidget(barOrientationLB, 9, 0, 1, 2);

        posPosCombo = new QComboBox(DataValueSettings);
        posPosCombo->setObjectName(QStringLiteral("posPosCombo"));

        gridLayout->addWidget(posPosCombo, 9, 2, 1, 4);

        barOrientationLB_7 = new QLabel(DataValueSettings);
        barOrientationLB_7->setObjectName(QStringLiteral("barOrientationLB_7"));

        gridLayout->addWidget(barOrientationLB_7, 10, 0, 1, 2);

        posAlignCombo = new QComboBox(DataValueSettings);
        posAlignCombo->setObjectName(QStringLiteral("posAlignCombo"));

        gridLayout->addWidget(posAlignCombo, 10, 2, 1, 4);

        barOrientationLB_6 = new QLabel(DataValueSettings);
        barOrientationLB_6->setObjectName(QStringLiteral("barOrientationLB_6"));

        gridLayout->addWidget(barOrientationLB_6, 11, 0, 1, 2);

        barOrientationLB_9 = new QLabel(DataValueSettings);
        barOrientationLB_9->setObjectName(QStringLiteral("barOrientationLB_9"));

        gridLayout->addWidget(barOrientationLB_9, 11, 2, 1, 1);

        posPadHoriSB = new QSpinBox(DataValueSettings);
        posPadHoriSB->setObjectName(QStringLiteral("posPadHoriSB"));
        posPadHoriSB->setMinimum(-1000);
        posPadHoriSB->setMaximum(1000);
        posPadHoriSB->setSingleStep(100);

        gridLayout->addWidget(posPadHoriSB, 11, 3, 1, 1);

        barOrientationLB_10 = new QLabel(DataValueSettings);
        barOrientationLB_10->setObjectName(QStringLiteral("barOrientationLB_10"));

        gridLayout->addWidget(barOrientationLB_10, 11, 4, 1, 1);

        posPadVertSB = new QSpinBox(DataValueSettings);
        posPadVertSB->setObjectName(QStringLiteral("posPadVertSB"));
        posPadVertSB->setMinimum(-1000);
        posPadVertSB->setMaximum(1000);
        posPadVertSB->setSingleStep(100);

        gridLayout->addWidget(posPadVertSB, 11, 5, 1, 1);

        spacerItem2 = new QSpacerItem(54, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem2, 12, 0, 1, 2);

        barOrientationLB_5 = new QLabel(DataValueSettings);
        barOrientationLB_5->setObjectName(QStringLiteral("barOrientationLB_5"));
        QFont font1;
        font1.setItalic(true);
        barOrientationLB_5->setFont(font1);

        gridLayout->addWidget(barOrientationLB_5, 13, 0, 1, 2);

        negPosCombo = new QComboBox(DataValueSettings);
        negPosCombo->setObjectName(QStringLiteral("negPosCombo"));

        gridLayout->addWidget(negPosCombo, 13, 2, 1, 4);

        barOrientationLB_8 = new QLabel(DataValueSettings);
        barOrientationLB_8->setObjectName(QStringLiteral("barOrientationLB_8"));

        gridLayout->addWidget(barOrientationLB_8, 14, 0, 1, 2);

        negAlignCombo = new QComboBox(DataValueSettings);
        negAlignCombo->setObjectName(QStringLiteral("negAlignCombo"));

        gridLayout->addWidget(negAlignCombo, 14, 2, 1, 4);

        barOrientationLB_11 = new QLabel(DataValueSettings);
        barOrientationLB_11->setObjectName(QStringLiteral("barOrientationLB_11"));

        gridLayout->addWidget(barOrientationLB_11, 15, 0, 1, 2);

        barOrientationLB_12 = new QLabel(DataValueSettings);
        barOrientationLB_12->setObjectName(QStringLiteral("barOrientationLB_12"));

        gridLayout->addWidget(barOrientationLB_12, 15, 2, 1, 1);

        barOrientationLB_13 = new QLabel(DataValueSettings);
        barOrientationLB_13->setObjectName(QStringLiteral("barOrientationLB_13"));

        gridLayout->addWidget(barOrientationLB_13, 15, 4, 1, 1);

        negPadVertSB = new QSpinBox(DataValueSettings);
        negPadVertSB->setObjectName(QStringLiteral("negPadVertSB"));
        negPadVertSB->setMinimum(-1000);
        negPadVertSB->setMaximum(1000);
        negPadVertSB->setSingleStep(100);

        gridLayout->addWidget(negPadVertSB, 15, 5, 1, 1);

        spacerItem3 = new QSpacerItem(52, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem3, 16, 1, 1, 2);

        gridLayout2 = new QGridLayout();
        gridLayout2->setObjectName(QStringLiteral("gridLayout2"));
        label_3 = new QLabel(DataValueSettings);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout2->addWidget(label_3, 0, 0, 1, 1);

        labelLE = new QLineEdit(DataValueSettings);
        labelLE->setObjectName(QStringLiteral("labelLE"));

        gridLayout2->addWidget(labelLE, 0, 1, 1, 1);

        label_4 = new QLabel(DataValueSettings);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout2->addWidget(label_4, 1, 0, 1, 1);

        prefixLE = new QLineEdit(DataValueSettings);
        prefixLE->setObjectName(QStringLiteral("prefixLE"));

        gridLayout2->addWidget(prefixLE, 1, 1, 1, 1);

        label_5 = new QLabel(DataValueSettings);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout2->addWidget(label_5, 2, 0, 1, 1);

        suffixLE = new QLineEdit(DataValueSettings);
        suffixLE->setObjectName(QStringLiteral("suffixLE"));

        gridLayout2->addWidget(suffixLE, 2, 1, 1, 1);


        gridLayout->addLayout(gridLayout2, 17, 0, 1, 6);


        retranslateUi(DataValueSettings);

        QMetaObject::connectSlotsByName(DataValueSettings);
    } // setupUi

    void retranslateUi(QWidget *DataValueSettings)
    {
        DataValueSettings->setWindowTitle(QApplication::translate("DataValueSettings", "Setting up Data Value Texts", 0));
        groupBox->setTitle(QApplication::translate("DataValueSettings", "Scope of settings", 0));
        label->setText(QApplication::translate("DataValueSettings", "dataset", 0));
        label_2->setText(QApplication::translate("DataValueSettings", "item", 0));
        scopeOneBarRB->setText(QApplication::translate("DataValueSettings", "One Bar", 0));
        scopeDatasetRB->setText(QApplication::translate("DataValueSettings", "A Series", 0));
        scopeCommonRB->setText(QApplication::translate("DataValueSettings", "Common", 0));
        paintValuesCB->setText(QApplication::translate("DataValueSettings", "Display Data Values", 0));
        barTypeLB->setText(QApplication::translate("DataValueSettings", "Font", 0));
        barOrientationLB_4->setText(QApplication::translate("DataValueSettings", "Relative Size", 0));
        barOrientationLB_3->setText(QApplication::translate("DataValueSettings", "Minimum Size", 0));
        barOrientationLB_2->setText(QApplication::translate("DataValueSettings", "Rotation", 0));
        barOrientationLB->setText(QApplication::translate("DataValueSettings", "Positive Position", 0));
        posPosCombo->clear();
        posPosCombo->insertItems(0, QStringList()
         << QApplication::translate("DataValueSettings", "( Default Value )", 0)
         << QApplication::translate("DataValueSettings", "Center", 0)
         << QApplication::translate("DataValueSettings", "NorthEast", 0)
         << QApplication::translate("DataValueSettings", "North", 0)
         << QApplication::translate("DataValueSettings", "NorthWest", 0)
         << QApplication::translate("DataValueSettings", "West", 0)
         << QApplication::translate("DataValueSettings", "SouthWest", 0)
         << QApplication::translate("DataValueSettings", "South", 0)
         << QApplication::translate("DataValueSettings", "SouthEast", 0)
         << QApplication::translate("DataValueSettings", "East", 0)
        );
        barOrientationLB_7->setText(QApplication::translate("DataValueSettings", "Alignment", 0));
        posAlignCombo->clear();
        posAlignCombo->insertItems(0, QStringList()
         << QApplication::translate("DataValueSettings", "Center", 0)
         << QApplication::translate("DataValueSettings", "BottomLeft", 0)
         << QApplication::translate("DataValueSettings", "Bottom", 0)
         << QApplication::translate("DataValueSettings", "BottomRight", 0)
         << QApplication::translate("DataValueSettings", "Right", 0)
         << QApplication::translate("DataValueSettings", "TopRight", 0)
         << QApplication::translate("DataValueSettings", "Top", 0)
         << QApplication::translate("DataValueSettings", "TopLeft", 0)
         << QApplication::translate("DataValueSettings", "Left", 0)
        );
        barOrientationLB_6->setText(QApplication::translate("DataValueSettings", "Padding", 0));
        barOrientationLB_9->setText(QApplication::translate("DataValueSettings", "H.", 0));
        barOrientationLB_10->setText(QApplication::translate("DataValueSettings", "V.", 0));
        barOrientationLB_5->setText(QApplication::translate("DataValueSettings", "Negative Position", 0));
        negPosCombo->clear();
        negPosCombo->insertItems(0, QStringList()
         << QApplication::translate("DataValueSettings", "( Default Value )", 0)
         << QApplication::translate("DataValueSettings", "Center", 0)
         << QApplication::translate("DataValueSettings", "NorthEast", 0)
         << QApplication::translate("DataValueSettings", "North", 0)
         << QApplication::translate("DataValueSettings", "NorthWest", 0)
         << QApplication::translate("DataValueSettings", "West", 0)
         << QApplication::translate("DataValueSettings", "SouthWest", 0)
         << QApplication::translate("DataValueSettings", "South", 0)
         << QApplication::translate("DataValueSettings", "SouthEast", 0)
         << QApplication::translate("DataValueSettings", "East", 0)
        );
        barOrientationLB_8->setText(QApplication::translate("DataValueSettings", "Alignment", 0));
        negAlignCombo->clear();
        negAlignCombo->insertItems(0, QStringList()
         << QApplication::translate("DataValueSettings", "Center", 0)
         << QApplication::translate("DataValueSettings", "BottomLeft", 0)
         << QApplication::translate("DataValueSettings", "Bottom", 0)
         << QApplication::translate("DataValueSettings", "BottomRight", 0)
         << QApplication::translate("DataValueSettings", "Right", 0)
         << QApplication::translate("DataValueSettings", "TopRight", 0)
         << QApplication::translate("DataValueSettings", "Top", 0)
         << QApplication::translate("DataValueSettings", "TopLeft", 0)
         << QApplication::translate("DataValueSettings", "Left", 0)
        );
        barOrientationLB_11->setText(QApplication::translate("DataValueSettings", "Padding", 0));
        barOrientationLB_12->setText(QApplication::translate("DataValueSettings", "H.", 0));
        barOrientationLB_13->setText(QApplication::translate("DataValueSettings", "V.", 0));
        label_3->setText(QApplication::translate("DataValueSettings", "Custom Label", 0));
        label_4->setText(QApplication::translate("DataValueSettings", "Prefix", 0));
        label_5->setText(QApplication::translate("DataValueSettings", "Suffix", 0));
    } // retranslateUi

};

namespace Ui {
    class DataValueSettings: public Ui_DataValueSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAVALUESETTINGS_H
