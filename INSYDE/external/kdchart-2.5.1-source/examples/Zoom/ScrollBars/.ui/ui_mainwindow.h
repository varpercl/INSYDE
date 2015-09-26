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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *spacerItem;
    QGridLayout *gridLayout1;
    QDoubleSpinBox *zoomFactorSB;
    QLabel *zoomingLB;
    QLabel *zoomFactorLB;
    QCheckBox *rubberBandZoomCB;
    QFrame *line_3;
    QCheckBox *adjustGridCB;
    QSplitter *splitter;
    QFrame *chartFrame;
    QScrollBar *hSBar;
    QScrollBar *vSBar;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(761, 722);
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
        spacerItem = new QSpacerItem(170, 521, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 1, 0, 1, 1);

        gridLayout1 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(0, 0, 0, 0);
#endif
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        zoomFactorSB = new QDoubleSpinBox(MainWindow);
        zoomFactorSB->setObjectName(QStringLiteral("zoomFactorSB"));
        zoomFactorSB->setMinimum(0.01);
        zoomFactorSB->setMaximum(40);
        zoomFactorSB->setSingleStep(0.1);
        zoomFactorSB->setValue(1);

        gridLayout1->addWidget(zoomFactorSB, 2, 1, 1, 1);

        zoomingLB = new QLabel(MainWindow);
        zoomingLB->setObjectName(QStringLiteral("zoomingLB"));

        gridLayout1->addWidget(zoomingLB, 0, 0, 1, 2);

        zoomFactorLB = new QLabel(MainWindow);
        zoomFactorLB->setObjectName(QStringLiteral("zoomFactorLB"));

        gridLayout1->addWidget(zoomFactorLB, 2, 0, 1, 1);

        rubberBandZoomCB = new QCheckBox(MainWindow);
        rubberBandZoomCB->setObjectName(QStringLiteral("rubberBandZoomCB"));

        gridLayout1->addWidget(rubberBandZoomCB, 4, 0, 1, 2);

        line_3 = new QFrame(MainWindow);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout1->addWidget(line_3, 1, 0, 1, 2);

        adjustGridCB = new QCheckBox(MainWindow);
        adjustGridCB->setObjectName(QStringLiteral("adjustGridCB"));
        adjustGridCB->setChecked(true);

        gridLayout1->addWidget(adjustGridCB, 3, 0, 1, 2);


        gridLayout->addLayout(gridLayout1, 0, 0, 1, 1);

        splitter = new QSplitter(MainWindow);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        chartFrame = new QFrame(splitter);
        chartFrame->setObjectName(QStringLiteral("chartFrame"));
        chartFrame->setMinimumSize(QSize(300, 400));
        chartFrame->setFrameShape(QFrame::StyledPanel);
        chartFrame->setFrameShadow(QFrame::Raised);
        splitter->addWidget(chartFrame);

        gridLayout->addWidget(splitter, 0, 1, 2, 1);

        hSBar = new QScrollBar(MainWindow);
        hSBar->setObjectName(QStringLiteral("hSBar"));
        hSBar->setMaximum(999);
        hSBar->setSingleStep(10);
        hSBar->setPageStep(100);
        hSBar->setValue(500);
        hSBar->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hSBar, 2, 1, 1, 1);

        vSBar = new QScrollBar(MainWindow);
        vSBar->setObjectName(QStringLiteral("vSBar"));
        vSBar->setMaximum(999);
        vSBar->setSingleStep(10);
        vSBar->setPageStep(100);
        vSBar->setValue(500);
        vSBar->setOrientation(Qt::Vertical);

        gridLayout->addWidget(vSBar, 0, 2, 2, 1);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Axes ", 0));
        zoomingLB->setText(QApplication::translate("MainWindow", "Zoom", 0));
        zoomFactorLB->setText(QApplication::translate("MainWindow", "Zoom Factor", 0));
        rubberBandZoomCB->setText(QApplication::translate("MainWindow", "Enabled Rubberband zooming", 0));
        adjustGridCB->setText(QApplication::translate("MainWindow", "auto-adjust the Grid", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
