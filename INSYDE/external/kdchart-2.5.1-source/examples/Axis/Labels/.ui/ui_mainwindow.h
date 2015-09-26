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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QGridLayout *gridLayout;
    QScrollBar *vSBar;
    QScrollBar *hSBar;
    QSplitter *splitter;
    QFrame *chartFrame;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(720, 680);
        gridLayout = new QGridLayout(MainWindow);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        vSBar = new QScrollBar(MainWindow);
        vSBar->setObjectName(QStringLiteral("vSBar"));
        vSBar->setMaximum(999);
        vSBar->setSingleStep(10);
        vSBar->setPageStep(100);
        vSBar->setValue(500);
        vSBar->setOrientation(Qt::Vertical);

        gridLayout->addWidget(vSBar, 0, 2, 1, 1);

        hSBar = new QScrollBar(MainWindow);
        hSBar->setObjectName(QStringLiteral("hSBar"));
        hSBar->setMaximum(999);
        hSBar->setSingleStep(10);
        hSBar->setPageStep(100);
        hSBar->setValue(500);
        hSBar->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hSBar, 1, 1, 1, 1);

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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Axes ", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
