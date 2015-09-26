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
    QVBoxLayout *vboxLayout;
    QCheckBox *paintValuesCB;
    QFrame *line_3;
    QVBoxLayout *vboxLayout1;
    QLabel *lineTypeLB;
    QComboBox *lineTypeCB;
    QCheckBox *paintLinesCB;
    QFrame *line_2;
    QVBoxLayout *vboxLayout2;
    QLabel *markersLB;
    QCheckBox *paintMarkersCB;
    QLabel *markersStyleLB;
    QComboBox *markersStyleCB;
    QVBoxLayout *vboxLayout3;
    QLabel *markersSizeLB;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout4;
    QLabel *markersWidthLB;
    QLabel *markersHeightLB;
    QVBoxLayout *vboxLayout5;
    QSpinBox *markersWidthSB;
    QSpinBox *markersHeightSB;
    QSpacerItem *spacerItem;
    QSplitter *splitter;
    QFrame *chartFrame;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(692, 421);
        QIcon icon;
        icon.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        gridLayout = new QGridLayout(MainWindow);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
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

        paintLinesCB = new QCheckBox(MainWindow);
        paintLinesCB->setObjectName(QStringLiteral("paintLinesCB"));
        paintLinesCB->setChecked(false);

        vboxLayout1->addWidget(paintLinesCB);


        vboxLayout->addLayout(vboxLayout1);

        line_2 = new QFrame(MainWindow);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line_2);

        vboxLayout2 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout2->setSpacing(6);
#endif
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        vboxLayout2->setObjectName(QStringLiteral("vboxLayout2"));
        markersLB = new QLabel(MainWindow);
        markersLB->setObjectName(QStringLiteral("markersLB"));

        vboxLayout2->addWidget(markersLB);

        paintMarkersCB = new QCheckBox(MainWindow);
        paintMarkersCB->setObjectName(QStringLiteral("paintMarkersCB"));
        paintMarkersCB->setChecked(true);

        vboxLayout2->addWidget(paintMarkersCB);

        markersStyleLB = new QLabel(MainWindow);
        markersStyleLB->setObjectName(QStringLiteral("markersStyleLB"));

        vboxLayout2->addWidget(markersStyleLB);

        markersStyleCB = new QComboBox(MainWindow);
        markersStyleCB->setObjectName(QStringLiteral("markersStyleCB"));

        vboxLayout2->addWidget(markersStyleCB);


        vboxLayout->addLayout(vboxLayout2);

        vboxLayout3 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout3->setSpacing(6);
#endif
        vboxLayout3->setContentsMargins(0, 0, 0, 0);
        vboxLayout3->setObjectName(QStringLiteral("vboxLayout3"));
        markersSizeLB = new QLabel(MainWindow);
        markersSizeLB->setObjectName(QStringLiteral("markersSizeLB"));

        vboxLayout3->addWidget(markersSizeLB);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        vboxLayout4 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout4->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout4->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout4->setObjectName(QStringLiteral("vboxLayout4"));
        markersWidthLB = new QLabel(MainWindow);
        markersWidthLB->setObjectName(QStringLiteral("markersWidthLB"));

        vboxLayout4->addWidget(markersWidthLB);

        markersHeightLB = new QLabel(MainWindow);
        markersHeightLB->setObjectName(QStringLiteral("markersHeightLB"));

        vboxLayout4->addWidget(markersHeightLB);


        hboxLayout->addLayout(vboxLayout4);

        vboxLayout5 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout5->setSpacing(6);
#endif
        vboxLayout5->setContentsMargins(0, 0, 0, 0);
        vboxLayout5->setObjectName(QStringLiteral("vboxLayout5"));
        markersWidthSB = new QSpinBox(MainWindow);
        markersWidthSB->setObjectName(QStringLiteral("markersWidthSB"));
        markersWidthSB->setValue(10);

        vboxLayout5->addWidget(markersWidthSB);

        markersHeightSB = new QSpinBox(MainWindow);
        markersHeightSB->setObjectName(QStringLiteral("markersHeightSB"));
        markersHeightSB->setValue(10);

        vboxLayout5->addWidget(markersHeightSB);


        hboxLayout->addLayout(vboxLayout5);


        vboxLayout3->addLayout(hboxLayout);


        vboxLayout->addLayout(vboxLayout3);

        spacerItem = new QSpacerItem(159, 41, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);


        gridLayout->addLayout(vboxLayout, 0, 0, 1, 1);

        splitter = new QSplitter(MainWindow);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        chartFrame = new QFrame(splitter);
        chartFrame->setObjectName(QStringLiteral("chartFrame"));
        chartFrame->setMinimumSize(QSize(300, 400));
        chartFrame->setFrameShape(QFrame::StyledPanel);
        chartFrame->setFrameShadow(QFrame::Raised);
        splitter->addWidget(chartFrame);

        gridLayout->addWidget(splitter, 0, 1, 1, 1);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Line Chart ", 0));
        paintValuesCB->setText(QApplication::translate("MainWindow", "Display Data Values", 0));
        lineTypeLB->setText(QApplication::translate("MainWindow", "Line Chart Type", 0));
        lineTypeCB->clear();
        lineTypeCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Normal", 0)
         << QApplication::translate("MainWindow", "Stacked", 0)
         << QApplication::translate("MainWindow", "Percent", 0)
        );
        paintLinesCB->setText(QApplication::translate("MainWindow", "Paint Lines", 0));
        markersLB->setText(QApplication::translate("MainWindow", "Markers", 0));
        paintMarkersCB->setText(QApplication::translate("MainWindow", "Paint Markers", 0));
        markersStyleLB->setText(QApplication::translate("MainWindow", "Markers Style", 0));
        markersStyleCB->clear();
        markersStyleCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Circle", 0)
         << QApplication::translate("MainWindow", "Square", 0)
         << QApplication::translate("MainWindow", "Diamond", 0)
         << QApplication::translate("MainWindow", "1 Pixel", 0)
         << QApplication::translate("MainWindow", "4 Pixels", 0)
         << QApplication::translate("MainWindow", "Ring", 0)
         << QApplication::translate("MainWindow", "Cross", 0)
         << QApplication::translate("MainWindow", "Fast Cross", 0)
         << QApplication::translate("MainWindow", "CustomPainterPath", 0)
        );
        markersSizeLB->setText(QApplication::translate("MainWindow", "Markers Size", 0));
        markersWidthLB->setText(QApplication::translate("MainWindow", "Width", 0));
        markersHeightLB->setText(QApplication::translate("MainWindow", "Height", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
