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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QGridLayout *gridLayout;
    QGroupBox *explodeGB;
    QVBoxLayout *vboxLayout;
    QCheckBox *circularGridCB;
    QCheckBox *sagittalGridCB;
    QGroupBox *explodeGB_3;
    QGridLayout *gridLayout1;
    QLabel *zoomFactorLB_2;
    QSlider *startPositionSL;
    QDoubleSpinBox *startPositionSB;
    QSpacerItem *spacerItem;
    QSplitter *splitter;
    QFrame *chartFrame;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(717, 691);
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
        explodeGB = new QGroupBox(MainWindow);
        explodeGB->setObjectName(QStringLiteral("explodeGB"));
        explodeGB->setCheckable(false);
        explodeGB->setChecked(false);
        vboxLayout = new QVBoxLayout(explodeGB);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        circularGridCB = new QCheckBox(explodeGB);
        circularGridCB->setObjectName(QStringLiteral("circularGridCB"));
        circularGridCB->setChecked(true);

        vboxLayout->addWidget(circularGridCB);

        sagittalGridCB = new QCheckBox(explodeGB);
        sagittalGridCB->setObjectName(QStringLiteral("sagittalGridCB"));
        sagittalGridCB->setChecked(true);

        vboxLayout->addWidget(sagittalGridCB);


        gridLayout->addWidget(explodeGB, 1, 0, 1, 1);

        explodeGB_3 = new QGroupBox(MainWindow);
        explodeGB_3->setObjectName(QStringLiteral("explodeGB_3"));
        explodeGB_3->setCheckable(false);
        explodeGB_3->setChecked(false);
        gridLayout1 = new QGridLayout(explodeGB_3);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        zoomFactorLB_2 = new QLabel(explodeGB_3);
        zoomFactorLB_2->setObjectName(QStringLiteral("zoomFactorLB_2"));

        gridLayout1->addWidget(zoomFactorLB_2, 0, 0, 1, 1);

        startPositionSL = new QSlider(explodeGB_3);
        startPositionSL->setObjectName(QStringLiteral("startPositionSL"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(startPositionSL->sizePolicy().hasHeightForWidth());
        startPositionSL->setSizePolicy(sizePolicy);
        startPositionSL->setMaximum(360);
        startPositionSL->setOrientation(Qt::Horizontal);

        gridLayout1->addWidget(startPositionSL, 1, 0, 1, 2);

        startPositionSB = new QDoubleSpinBox(explodeGB_3);
        startPositionSB->setObjectName(QStringLiteral("startPositionSB"));
        startPositionSB->setMinimum(0);
        startPositionSB->setMaximum(360);
        startPositionSB->setSingleStep(1);
        startPositionSB->setValue(0);

        gridLayout1->addWidget(startPositionSB, 0, 1, 1, 1);


        gridLayout->addWidget(explodeGB_3, 0, 0, 1, 1);

        spacerItem = new QSpacerItem(128, 221, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 3, 0, 1, 1);

        splitter = new QSplitter(MainWindow);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        chartFrame = new QFrame(splitter);
        chartFrame->setObjectName(QStringLiteral("chartFrame"));
        chartFrame->setMinimumSize(QSize(300, 400));
        chartFrame->setFrameShape(QFrame::StyledPanel);
        chartFrame->setFrameShadow(QFrame::Raised);
        splitter->addWidget(chartFrame);

        gridLayout->addWidget(splitter, 0, 1, 4, 1);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Polar Chart ", 0));
        explodeGB->setTitle(QApplication::translate("MainWindow", "Grid lines", 0));
        circularGridCB->setText(QApplication::translate("MainWindow", "Circular", 0));
        sagittalGridCB->setText(QApplication::translate("MainWindow", "Sagittal", 0));
        explodeGB_3->setTitle(QApplication::translate("MainWindow", "Coordinate plane", 0));
        zoomFactorLB_2->setText(QApplication::translate("MainWindow", "Start", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
