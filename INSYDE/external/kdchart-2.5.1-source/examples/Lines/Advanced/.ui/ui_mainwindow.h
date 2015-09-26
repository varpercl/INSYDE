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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QCheckBox *paintValuesCB;
    QCheckBox *centerDataPointsCB;
    QFrame *line_3;
    QVBoxLayout *vboxLayout1;
    QLabel *lineTypeLB;
    QComboBox *lineTypeCB;
    QFrame *line;
    QHBoxLayout *hboxLayout1;
    QVBoxLayout *vboxLayout2;
    QLabel *threeDLabel;
    QCheckBox *threeDModeCB;
    QVBoxLayout *vboxLayout3;
    QLabel *depthLabel;
    QSpinBox *depthSB;
    QFrame *line_4;
    QVBoxLayout *vboxLayout4;
    QLabel *penLabel;
    QHBoxLayout *hboxLayout2;
    QCheckBox *highlightAreaCB;
    QSpinBox *highlightAreaSB;
    QFrame *line_2;
    QVBoxLayout *vboxLayout5;
    QLabel *threeDLB;
    QCheckBox *animateAreasCB;
    QHBoxLayout *hboxLayout3;
    QFrame *line_5;
    QVBoxLayout *vboxLayout6;
    QLabel *valueTrackerLB;
    QHBoxLayout *hboxLayout4;
    QCheckBox *trackAreasCB;
    QSpinBox *trackAreasSB;
    QFrame *line_6;
    QVBoxLayout *vboxLayout7;
    QLabel *reverseLB;
    QCheckBox *reverseHorizontalCB;
    QCheckBox *reverseVerticalCB;
    QSpacerItem *spacerItem;
    QSplitter *splitter;
    QFrame *chartFrame;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(692, 545);
        QIcon icon;
        icon.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        hboxLayout = new QHBoxLayout(MainWindow);
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        vboxLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        paintValuesCB = new QCheckBox(MainWindow);
        paintValuesCB->setObjectName(QStringLiteral("paintValuesCB"));

        vboxLayout->addWidget(paintValuesCB);

        centerDataPointsCB = new QCheckBox(MainWindow);
        centerDataPointsCB->setObjectName(QStringLiteral("centerDataPointsCB"));

        vboxLayout->addWidget(centerDataPointsCB);

        line_3 = new QFrame(MainWindow);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line_3);

        vboxLayout1 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        lineTypeLB = new QLabel(MainWindow);
        lineTypeLB->setObjectName(QStringLiteral("lineTypeLB"));

        vboxLayout1->addWidget(lineTypeLB);

        lineTypeCB = new QComboBox(MainWindow);
        lineTypeCB->setObjectName(QStringLiteral("lineTypeCB"));

        vboxLayout1->addWidget(lineTypeCB);


        vboxLayout->addLayout(vboxLayout1);

        line = new QFrame(MainWindow);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        vboxLayout2 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout2->setObjectName(QStringLiteral("vboxLayout2"));
        threeDLabel = new QLabel(MainWindow);
        threeDLabel->setObjectName(QStringLiteral("threeDLabel"));

        vboxLayout2->addWidget(threeDLabel);

        threeDModeCB = new QCheckBox(MainWindow);
        threeDModeCB->setObjectName(QStringLiteral("threeDModeCB"));

        vboxLayout2->addWidget(threeDModeCB);


        hboxLayout1->addLayout(vboxLayout2);

        vboxLayout3 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout3->setSpacing(6);
#endif
        vboxLayout3->setContentsMargins(0, 0, 0, 0);
        vboxLayout3->setObjectName(QStringLiteral("vboxLayout3"));
        depthLabel = new QLabel(MainWindow);
        depthLabel->setObjectName(QStringLiteral("depthLabel"));

        vboxLayout3->addWidget(depthLabel);

        depthSB = new QSpinBox(MainWindow);
        depthSB->setObjectName(QStringLiteral("depthSB"));
        depthSB->setMaximum(99);
        depthSB->setValue(20);

        vboxLayout3->addWidget(depthSB);


        hboxLayout1->addLayout(vboxLayout3);


        vboxLayout->addLayout(hboxLayout1);

        line_4 = new QFrame(MainWindow);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line_4);

        vboxLayout4 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout4->setSpacing(6);
#endif
        vboxLayout4->setContentsMargins(0, 0, 0, 0);
        vboxLayout4->setObjectName(QStringLiteral("vboxLayout4"));
        penLabel = new QLabel(MainWindow);
        penLabel->setObjectName(QStringLiteral("penLabel"));

        vboxLayout4->addWidget(penLabel);

        hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QStringLiteral("hboxLayout2"));
        highlightAreaCB = new QCheckBox(MainWindow);
        highlightAreaCB->setObjectName(QStringLiteral("highlightAreaCB"));

        hboxLayout2->addWidget(highlightAreaCB);

        highlightAreaSB = new QSpinBox(MainWindow);
        highlightAreaSB->setObjectName(QStringLiteral("highlightAreaSB"));
        highlightAreaSB->setMaximum(3);

        hboxLayout2->addWidget(highlightAreaSB);


        vboxLayout4->addLayout(hboxLayout2);


        vboxLayout->addLayout(vboxLayout4);

        line_2 = new QFrame(MainWindow);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line_2);

        vboxLayout5 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout5->setSpacing(6);
#endif
        vboxLayout5->setContentsMargins(0, 0, 0, 0);
        vboxLayout5->setObjectName(QStringLiteral("vboxLayout5"));
        threeDLB = new QLabel(MainWindow);
        threeDLB->setObjectName(QStringLiteral("threeDLB"));

        vboxLayout5->addWidget(threeDLB);

        animateAreasCB = new QCheckBox(MainWindow);
        animateAreasCB->setObjectName(QStringLiteral("animateAreasCB"));

        vboxLayout5->addWidget(animateAreasCB);

        hboxLayout3 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout3->setSpacing(6);
#endif
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        hboxLayout3->setObjectName(QStringLiteral("hboxLayout3"));

        vboxLayout5->addLayout(hboxLayout3);


        vboxLayout->addLayout(vboxLayout5);

        line_5 = new QFrame(MainWindow);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line_5);

        vboxLayout6 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout6->setSpacing(6);
#endif
        vboxLayout6->setContentsMargins(0, 0, 0, 0);
        vboxLayout6->setObjectName(QStringLiteral("vboxLayout6"));
        valueTrackerLB = new QLabel(MainWindow);
        valueTrackerLB->setObjectName(QStringLiteral("valueTrackerLB"));

        vboxLayout6->addWidget(valueTrackerLB);

        hboxLayout4 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout4->setSpacing(6);
#endif
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        hboxLayout4->setObjectName(QStringLiteral("hboxLayout4"));
        trackAreasCB = new QCheckBox(MainWindow);
        trackAreasCB->setObjectName(QStringLiteral("trackAreasCB"));

        hboxLayout4->addWidget(trackAreasCB);

        trackAreasSB = new QSpinBox(MainWindow);
        trackAreasSB->setObjectName(QStringLiteral("trackAreasSB"));
        trackAreasSB->setMaximum(3);

        hboxLayout4->addWidget(trackAreasSB);


        vboxLayout6->addLayout(hboxLayout4);


        vboxLayout->addLayout(vboxLayout6);

        line_6 = new QFrame(MainWindow);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line_6);

        vboxLayout7 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout7->setSpacing(6);
#endif
        vboxLayout7->setContentsMargins(0, 0, 0, 0);
        vboxLayout7->setObjectName(QStringLiteral("vboxLayout7"));
        reverseLB = new QLabel(MainWindow);
        reverseLB->setObjectName(QStringLiteral("reverseLB"));

        vboxLayout7->addWidget(reverseLB);

        reverseHorizontalCB = new QCheckBox(MainWindow);
        reverseHorizontalCB->setObjectName(QStringLiteral("reverseHorizontalCB"));

        vboxLayout7->addWidget(reverseHorizontalCB);

        reverseVerticalCB = new QCheckBox(MainWindow);
        reverseVerticalCB->setObjectName(QStringLiteral("reverseVerticalCB"));

        vboxLayout7->addWidget(reverseVerticalCB);


        vboxLayout->addLayout(vboxLayout7);

        spacerItem = new QSpacerItem(193, 41, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);


        hboxLayout->addLayout(vboxLayout);

        splitter = new QSplitter(MainWindow);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        chartFrame = new QFrame(splitter);
        chartFrame->setObjectName(QStringLiteral("chartFrame"));
        chartFrame->setMinimumSize(QSize(300, 400));
        chartFrame->setFrameShape(QFrame::StyledPanel);
        chartFrame->setFrameShadow(QFrame::Raised);
        splitter->addWidget(chartFrame);

        hboxLayout->addWidget(splitter);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Line Chart ", 0));
        paintValuesCB->setText(QApplication::translate("MainWindow", "Display Data Values", 0));
        centerDataPointsCB->setText(QApplication::translate("MainWindow", "Center Data Points", 0));
        lineTypeLB->setText(QApplication::translate("MainWindow", "Line Chart Type", 0));
        lineTypeCB->clear();
        lineTypeCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Normal", 0)
         << QApplication::translate("MainWindow", "Stacked", 0)
         << QApplication::translate("MainWindow", "Percent", 0)
        );
        threeDLabel->setText(QApplication::translate("MainWindow", "ThreeD Mode", 0));
        threeDModeCB->setText(QApplication::translate("MainWindow", "ThreeD Mode", 0));
        depthLabel->setText(QApplication::translate("MainWindow", "ThreeD Mode", 0));
        penLabel->setText(QApplication::translate("MainWindow", "Show Areas", 0));
        highlightAreaCB->setText(QApplication::translate("MainWindow", "Highlight Area", 0));
        threeDLB->setText(QApplication::translate("MainWindow", "Animate", 0));
        animateAreasCB->setText(QApplication::translate("MainWindow", "Highlight", 0));
        valueTrackerLB->setText(QApplication::translate("MainWindow", "Value tracker", 0));
        trackAreasCB->setText(QApplication::translate("MainWindow", "Enable value tracker", 0));
        reverseLB->setText(QApplication::translate("MainWindow", "Reverse Axis", 0));
        reverseHorizontalCB->setText(QApplication::translate("MainWindow", "Reverse abscissa axis", 0));
        reverseVerticalCB->setText(QApplication::translate("MainWindow", "Reverse ordinate axis", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
