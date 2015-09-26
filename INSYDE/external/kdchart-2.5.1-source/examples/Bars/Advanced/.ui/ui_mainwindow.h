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
#include <QtWidgets/QGridLayout>
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
    QGridLayout *gridLayout;
    QCheckBox *fixPlaneSizeCB;
    QSpacerItem *spacerItem;
    QFrame *line_5;
    QVBoxLayout *vboxLayout;
    QLabel *widthLB;
    QHBoxLayout *hboxLayout;
    QCheckBox *widthCB;
    QSpinBox *widthSB;
    QFrame *line_4;
    QVBoxLayout *vboxLayout1;
    QLabel *threeDLB;
    QCheckBox *paintThreeDBarsCB;
    QHBoxLayout *hboxLayout1;
    QCheckBox *threeDDepthCB;
    QSpinBox *depthSB;
    QFrame *line_2;
    QVBoxLayout *vboxLayout2;
    QLabel *penLabel;
    QHBoxLayout *hboxLayout2;
    QCheckBox *markColumnCB;
    QSpinBox *markColumnSB;
    QFrame *line;
    QVBoxLayout *vboxLayout3;
    QLabel *barTypeLB;
    QComboBox *barTypeCB;
    QLabel *barOrientationLB;
    QComboBox *barOrientationCB;
    QFrame *line_3;
    QCheckBox *paintValuesCB;
    QSplitter *splitter;
    QFrame *chartFrame;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(692, 424);
        QIcon icon;
        icon.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        gridLayout = new QGridLayout(MainWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        fixPlaneSizeCB = new QCheckBox(MainWindow);
        fixPlaneSizeCB->setObjectName(QStringLiteral("fixPlaneSizeCB"));

        gridLayout->addWidget(fixPlaneSizeCB, 10, 0, 1, 1);

        spacerItem = new QSpacerItem(171, 51, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 11, 0, 1, 1);

        line_5 = new QFrame(MainWindow);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 9, 0, 1, 1);

        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(6);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        widthLB = new QLabel(MainWindow);
        widthLB->setObjectName(QStringLiteral("widthLB"));

        vboxLayout->addWidget(widthLB);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        widthCB = new QCheckBox(MainWindow);
        widthCB->setObjectName(QStringLiteral("widthCB"));

        hboxLayout->addWidget(widthCB);

        widthSB = new QSpinBox(MainWindow);
        widthSB->setObjectName(QStringLiteral("widthSB"));

        hboxLayout->addWidget(widthSB);


        vboxLayout->addLayout(hboxLayout);


        gridLayout->addLayout(vboxLayout, 8, 0, 1, 1);

        line_4 = new QFrame(MainWindow);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 7, 0, 1, 1);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        threeDLB = new QLabel(MainWindow);
        threeDLB->setObjectName(QStringLiteral("threeDLB"));

        vboxLayout1->addWidget(threeDLB);

        paintThreeDBarsCB = new QCheckBox(MainWindow);
        paintThreeDBarsCB->setObjectName(QStringLiteral("paintThreeDBarsCB"));

        vboxLayout1->addWidget(paintThreeDBarsCB);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        threeDDepthCB = new QCheckBox(MainWindow);
        threeDDepthCB->setObjectName(QStringLiteral("threeDDepthCB"));

        hboxLayout1->addWidget(threeDDepthCB);

        depthSB = new QSpinBox(MainWindow);
        depthSB->setObjectName(QStringLiteral("depthSB"));
        depthSB->setValue(20);

        hboxLayout1->addWidget(depthSB);


        vboxLayout1->addLayout(hboxLayout1);


        gridLayout->addLayout(vboxLayout1, 6, 0, 1, 1);

        line_2 = new QFrame(MainWindow);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 5, 0, 1, 1);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setSpacing(6);
        vboxLayout2->setObjectName(QStringLiteral("vboxLayout2"));
        penLabel = new QLabel(MainWindow);
        penLabel->setObjectName(QStringLiteral("penLabel"));

        vboxLayout2->addWidget(penLabel);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QStringLiteral("hboxLayout2"));
        markColumnCB = new QCheckBox(MainWindow);
        markColumnCB->setObjectName(QStringLiteral("markColumnCB"));

        hboxLayout2->addWidget(markColumnCB);

        markColumnSB = new QSpinBox(MainWindow);
        markColumnSB->setObjectName(QStringLiteral("markColumnSB"));
        markColumnSB->setMaximum(3);

        hboxLayout2->addWidget(markColumnSB);


        vboxLayout2->addLayout(hboxLayout2);


        gridLayout->addLayout(vboxLayout2, 4, 0, 1, 1);

        line = new QFrame(MainWindow);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 1);

        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setSpacing(6);
        vboxLayout3->setObjectName(QStringLiteral("vboxLayout3"));
        barTypeLB = new QLabel(MainWindow);
        barTypeLB->setObjectName(QStringLiteral("barTypeLB"));

        vboxLayout3->addWidget(barTypeLB);

        barTypeCB = new QComboBox(MainWindow);
        barTypeCB->setObjectName(QStringLiteral("barTypeCB"));

        vboxLayout3->addWidget(barTypeCB);

        barOrientationLB = new QLabel(MainWindow);
        barOrientationLB->setObjectName(QStringLiteral("barOrientationLB"));

        vboxLayout3->addWidget(barOrientationLB);

        barOrientationCB = new QComboBox(MainWindow);
        barOrientationCB->setObjectName(QStringLiteral("barOrientationCB"));

        vboxLayout3->addWidget(barOrientationCB);


        gridLayout->addLayout(vboxLayout3, 2, 0, 1, 1);

        line_3 = new QFrame(MainWindow);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 1, 0, 1, 1);

        paintValuesCB = new QCheckBox(MainWindow);
        paintValuesCB->setObjectName(QStringLiteral("paintValuesCB"));

        gridLayout->addWidget(paintValuesCB, 0, 0, 1, 1);

        splitter = new QSplitter(MainWindow);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        chartFrame = new QFrame(splitter);
        chartFrame->setObjectName(QStringLiteral("chartFrame"));
        chartFrame->setMinimumSize(QSize(300, 400));
        chartFrame->setFrameShape(QFrame::StyledPanel);
        chartFrame->setFrameShadow(QFrame::Raised);
        splitter->addWidget(chartFrame);

        gridLayout->addWidget(splitter, 0, 1, 12, 1);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Bar Chart ", 0));
        fixPlaneSizeCB->setText(QApplication::translate("MainWindow", "Data / plane space relation fixed", 0));
        widthLB->setText(QApplication::translate("MainWindow", "Configure Width", 0));
        widthCB->setText(QApplication::translate("MainWindow", "Bars Width", 0));
        threeDLB->setText(QApplication::translate("MainWindow", "Paint ThreeD Bars", 0));
        paintThreeDBarsCB->setText(QApplication::translate("MainWindow", "ThreeD", 0));
        threeDDepthCB->setText(QApplication::translate("MainWindow", "Bars Depth", 0));
        penLabel->setText(QApplication::translate("MainWindow", "Pen Settings", 0));
        markColumnCB->setText(QApplication::translate("MainWindow", "Mark Column", 0));
        barTypeLB->setText(QApplication::translate("MainWindow", "Bar Chart Type", 0));
        barTypeCB->clear();
        barTypeCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Normal", 0)
         << QApplication::translate("MainWindow", "Stacked", 0)
         << QApplication::translate("MainWindow", "Percent", 0)
        );
        barOrientationLB->setText(QApplication::translate("MainWindow", "Bar Orientation", 0));
        barOrientationCB->clear();
        barOrientationCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Vertical", 0)
         << QApplication::translate("MainWindow", "Horizontal", 0)
        );
        paintValuesCB->setText(QApplication::translate("MainWindow", "Display Data Values", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
