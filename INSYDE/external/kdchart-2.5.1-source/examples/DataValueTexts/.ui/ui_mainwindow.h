/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QGridLayout *gridLayout;
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
    QSplitter *splitter;
    QFrame *chartFrame;
    QSpacerItem *spacerItem;
    QCheckBox *paintValuesCB;
    QFrame *line_3;
    QHBoxLayout *hboxLayout;
    QLabel *barTypeLB;
    QFontComboBox *fontCombo;
    QLabel *barOrientationLB_4;
    QSpinBox *relativeSizeSB;
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
    QSpinBox *negPadHoriSB;
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

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(899, 698);
        QIcon icon;
        icon.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        gridLayout = new QGridLayout(MainWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(MainWindow);
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

        splitter = new QSplitter(MainWindow);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        chartFrame = new QFrame(splitter);
        chartFrame->setObjectName(QStringLiteral("chartFrame"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(chartFrame->sizePolicy().hasHeightForWidth());
        chartFrame->setSizePolicy(sizePolicy);
        chartFrame->setMinimumSize(QSize(300, 400));
        chartFrame->setFrameShape(QFrame::StyledPanel);
        chartFrame->setFrameShadow(QFrame::Raised);
        splitter->addWidget(chartFrame);

        gridLayout->addWidget(splitter, 0, 6, 18, 1);

        spacerItem = new QSpacerItem(54, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 1, 1, 1, 2);

        paintValuesCB = new QCheckBox(MainWindow);
        paintValuesCB->setObjectName(QStringLiteral("paintValuesCB"));

        gridLayout->addWidget(paintValuesCB, 2, 0, 1, 6);

        line_3 = new QFrame(MainWindow);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 3, 0, 1, 6);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        barTypeLB = new QLabel(MainWindow);
        barTypeLB->setObjectName(QStringLiteral("barTypeLB"));

        hboxLayout->addWidget(barTypeLB);

        fontCombo = new QFontComboBox(MainWindow);
        fontCombo->setObjectName(QStringLiteral("fontCombo"));

        hboxLayout->addWidget(fontCombo);


        gridLayout->addLayout(hboxLayout, 4, 0, 1, 6);

        barOrientationLB_4 = new QLabel(MainWindow);
        barOrientationLB_4->setObjectName(QStringLiteral("barOrientationLB_4"));

        gridLayout->addWidget(barOrientationLB_4, 5, 0, 1, 2);

        relativeSizeSB = new QSpinBox(MainWindow);
        relativeSizeSB->setObjectName(QStringLiteral("relativeSizeSB"));

        gridLayout->addWidget(relativeSizeSB, 5, 2, 1, 4);

        barOrientationLB_3 = new QLabel(MainWindow);
        barOrientationLB_3->setObjectName(QStringLiteral("barOrientationLB_3"));

        gridLayout->addWidget(barOrientationLB_3, 6, 0, 1, 2);

        minimumSizeSB = new QSpinBox(MainWindow);
        minimumSizeSB->setObjectName(QStringLiteral("minimumSizeSB"));

        gridLayout->addWidget(minimumSizeSB, 6, 2, 1, 4);

        barOrientationLB_2 = new QLabel(MainWindow);
        barOrientationLB_2->setObjectName(QStringLiteral("barOrientationLB_2"));

        gridLayout->addWidget(barOrientationLB_2, 7, 0, 1, 1);

        rotationSB = new QSpinBox(MainWindow);
        rotationSB->setObjectName(QStringLiteral("rotationSB"));
        rotationSB->setMinimum(-359);
        rotationSB->setMaximum(359);
        rotationSB->setSingleStep(15);

        gridLayout->addWidget(rotationSB, 7, 2, 1, 4);

        spacerItem1 = new QSpacerItem(54, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem1, 8, 1, 1, 2);

        barOrientationLB = new QLabel(MainWindow);
        barOrientationLB->setObjectName(QStringLiteral("barOrientationLB"));
        QFont font;
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        barOrientationLB->setFont(font);

        gridLayout->addWidget(barOrientationLB, 9, 0, 1, 2);

        posPosCombo = new QComboBox(MainWindow);
        posPosCombo->setObjectName(QStringLiteral("posPosCombo"));

        gridLayout->addWidget(posPosCombo, 9, 2, 1, 4);

        barOrientationLB_7 = new QLabel(MainWindow);
        barOrientationLB_7->setObjectName(QStringLiteral("barOrientationLB_7"));

        gridLayout->addWidget(barOrientationLB_7, 10, 0, 1, 2);

        posAlignCombo = new QComboBox(MainWindow);
        posAlignCombo->setObjectName(QStringLiteral("posAlignCombo"));

        gridLayout->addWidget(posAlignCombo, 10, 2, 1, 4);

        barOrientationLB_6 = new QLabel(MainWindow);
        barOrientationLB_6->setObjectName(QStringLiteral("barOrientationLB_6"));

        gridLayout->addWidget(barOrientationLB_6, 11, 0, 1, 2);

        barOrientationLB_9 = new QLabel(MainWindow);
        barOrientationLB_9->setObjectName(QStringLiteral("barOrientationLB_9"));

        gridLayout->addWidget(barOrientationLB_9, 11, 2, 1, 1);

        posPadHoriSB = new QSpinBox(MainWindow);
        posPadHoriSB->setObjectName(QStringLiteral("posPadHoriSB"));
        posPadHoriSB->setMinimum(-1000);
        posPadHoriSB->setMaximum(1000);
        posPadHoriSB->setSingleStep(100);

        gridLayout->addWidget(posPadHoriSB, 11, 3, 1, 1);

        barOrientationLB_10 = new QLabel(MainWindow);
        barOrientationLB_10->setObjectName(QStringLiteral("barOrientationLB_10"));

        gridLayout->addWidget(barOrientationLB_10, 11, 4, 1, 1);

        posPadVertSB = new QSpinBox(MainWindow);
        posPadVertSB->setObjectName(QStringLiteral("posPadVertSB"));
        posPadVertSB->setMinimum(-1000);
        posPadVertSB->setMaximum(1000);
        posPadVertSB->setSingleStep(100);

        gridLayout->addWidget(posPadVertSB, 11, 5, 1, 1);

        spacerItem2 = new QSpacerItem(54, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem2, 12, 0, 1, 2);

        barOrientationLB_5 = new QLabel(MainWindow);
        barOrientationLB_5->setObjectName(QStringLiteral("barOrientationLB_5"));
        QFont font1;
        font1.setItalic(true);
        barOrientationLB_5->setFont(font1);

        gridLayout->addWidget(barOrientationLB_5, 13, 0, 1, 2);

        negPosCombo = new QComboBox(MainWindow);
        negPosCombo->setObjectName(QStringLiteral("negPosCombo"));

        gridLayout->addWidget(negPosCombo, 13, 2, 1, 4);

        barOrientationLB_8 = new QLabel(MainWindow);
        barOrientationLB_8->setObjectName(QStringLiteral("barOrientationLB_8"));

        gridLayout->addWidget(barOrientationLB_8, 14, 0, 1, 2);

        negAlignCombo = new QComboBox(MainWindow);
        negAlignCombo->setObjectName(QStringLiteral("negAlignCombo"));

        gridLayout->addWidget(negAlignCombo, 14, 2, 1, 4);

        barOrientationLB_11 = new QLabel(MainWindow);
        barOrientationLB_11->setObjectName(QStringLiteral("barOrientationLB_11"));

        gridLayout->addWidget(barOrientationLB_11, 15, 0, 1, 2);

        barOrientationLB_12 = new QLabel(MainWindow);
        barOrientationLB_12->setObjectName(QStringLiteral("barOrientationLB_12"));

        gridLayout->addWidget(barOrientationLB_12, 15, 2, 1, 1);

        negPadHoriSB = new QSpinBox(MainWindow);
        negPadHoriSB->setObjectName(QStringLiteral("negPadHoriSB"));
        negPadHoriSB->setMinimum(-1000);
        negPadHoriSB->setMaximum(1000);
        negPadHoriSB->setSingleStep(100);

        gridLayout->addWidget(negPadHoriSB, 15, 3, 1, 1);

        barOrientationLB_13 = new QLabel(MainWindow);
        barOrientationLB_13->setObjectName(QStringLiteral("barOrientationLB_13"));

        gridLayout->addWidget(barOrientationLB_13, 15, 4, 1, 1);

        negPadVertSB = new QSpinBox(MainWindow);
        negPadVertSB->setObjectName(QStringLiteral("negPadVertSB"));
        negPadVertSB->setMinimum(-1000);
        negPadVertSB->setMaximum(1000);
        negPadVertSB->setSingleStep(100);

        gridLayout->addWidget(negPadVertSB, 15, 5, 1, 1);

        spacerItem3 = new QSpacerItem(52, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem3, 16, 1, 1, 2);

        gridLayout2 = new QGridLayout();
        gridLayout2->setObjectName(QStringLiteral("gridLayout2"));
        label_3 = new QLabel(MainWindow);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout2->addWidget(label_3, 0, 0, 1, 1);

        labelLE = new QLineEdit(MainWindow);
        labelLE->setObjectName(QStringLiteral("labelLE"));

        gridLayout2->addWidget(labelLE, 0, 1, 1, 1);

        label_4 = new QLabel(MainWindow);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout2->addWidget(label_4, 1, 0, 1, 1);

        prefixLE = new QLineEdit(MainWindow);
        prefixLE->setObjectName(QStringLiteral("prefixLE"));

        gridLayout2->addWidget(prefixLE, 1, 1, 1, 1);

        label_5 = new QLabel(MainWindow);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout2->addWidget(label_5, 2, 0, 1, 1);

        suffixLE = new QLineEdit(MainWindow);
        suffixLE->setObjectName(QStringLiteral("suffixLE"));

        gridLayout2->addWidget(suffixLE, 2, 1, 1, 1);


        gridLayout->addLayout(gridLayout2, 17, 0, 1, 6);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Setting up Data Value Texts", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Scope of settings", 0));
        label->setText(QApplication::translate("MainWindow", "dataset", 0));
        label_2->setText(QApplication::translate("MainWindow", "item", 0));
        scopeOneBarRB->setText(QApplication::translate("MainWindow", "One Bar", 0));
        scopeDatasetRB->setText(QApplication::translate("MainWindow", "A Series", 0));
        scopeCommonRB->setText(QApplication::translate("MainWindow", "Common", 0));
        paintValuesCB->setText(QApplication::translate("MainWindow", "Display Data Values", 0));
        barTypeLB->setText(QApplication::translate("MainWindow", "Font", 0));
        barOrientationLB_4->setText(QApplication::translate("MainWindow", "Relative Size", 0));
        barOrientationLB_3->setText(QApplication::translate("MainWindow", "Minimum Size", 0));
        barOrientationLB_2->setText(QApplication::translate("MainWindow", "Rotation", 0));
        barOrientationLB->setText(QApplication::translate("MainWindow", "Positive Pos.", 0));
        posPosCombo->clear();
        posPosCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "( Default Value )", 0)
         << QApplication::translate("MainWindow", "Center", 0)
         << QApplication::translate("MainWindow", "NorthEast", 0)
         << QApplication::translate("MainWindow", "North", 0)
         << QApplication::translate("MainWindow", "NorthWest", 0)
         << QApplication::translate("MainWindow", "West", 0)
         << QApplication::translate("MainWindow", "SouthWest", 0)
         << QApplication::translate("MainWindow", "South", 0)
         << QApplication::translate("MainWindow", "SouthEast", 0)
         << QApplication::translate("MainWindow", "East", 0)
        );
        barOrientationLB_7->setText(QApplication::translate("MainWindow", "Alignment", 0));
        posAlignCombo->clear();
        posAlignCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Center", 0)
         << QApplication::translate("MainWindow", "BottomLeft", 0)
         << QApplication::translate("MainWindow", "Bottom", 0)
         << QApplication::translate("MainWindow", "BottomRight", 0)
         << QApplication::translate("MainWindow", "Right", 0)
         << QApplication::translate("MainWindow", "TopRight", 0)
         << QApplication::translate("MainWindow", "Top", 0)
         << QApplication::translate("MainWindow", "TopLeft", 0)
         << QApplication::translate("MainWindow", "Left", 0)
        );
        barOrientationLB_6->setText(QApplication::translate("MainWindow", "Padding", 0));
        barOrientationLB_9->setText(QApplication::translate("MainWindow", "H.", 0));
        barOrientationLB_10->setText(QApplication::translate("MainWindow", "V.", 0));
        barOrientationLB_5->setText(QApplication::translate("MainWindow", "Negative Pos.", 0));
        negPosCombo->clear();
        negPosCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "( Default Value )", 0)
         << QApplication::translate("MainWindow", "Center", 0)
         << QApplication::translate("MainWindow", "NorthEast", 0)
         << QApplication::translate("MainWindow", "North", 0)
         << QApplication::translate("MainWindow", "NorthWest", 0)
         << QApplication::translate("MainWindow", "West", 0)
         << QApplication::translate("MainWindow", "SouthWest", 0)
         << QApplication::translate("MainWindow", "South", 0)
         << QApplication::translate("MainWindow", "SouthEast", 0)
         << QApplication::translate("MainWindow", "East", 0)
        );
        barOrientationLB_8->setText(QApplication::translate("MainWindow", "Alignment", 0));
        negAlignCombo->clear();
        negAlignCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Center", 0)
         << QApplication::translate("MainWindow", "BottomLeft", 0)
         << QApplication::translate("MainWindow", "Bottom", 0)
         << QApplication::translate("MainWindow", "BottomRight", 0)
         << QApplication::translate("MainWindow", "Right", 0)
         << QApplication::translate("MainWindow", "TopRight", 0)
         << QApplication::translate("MainWindow", "Top", 0)
         << QApplication::translate("MainWindow", "TopLeft", 0)
         << QApplication::translate("MainWindow", "Left", 0)
        );
        barOrientationLB_11->setText(QApplication::translate("MainWindow", "Padding", 0));
        barOrientationLB_12->setText(QApplication::translate("MainWindow", "H.", 0));
        barOrientationLB_13->setText(QApplication::translate("MainWindow", "V.", 0));
        label_3->setText(QApplication::translate("MainWindow", "Custom Label", 0));
        label_4->setText(QApplication::translate("MainWindow", "Prefix", 0));
        label_5->setText(QApplication::translate("MainWindow", "Suffix", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
