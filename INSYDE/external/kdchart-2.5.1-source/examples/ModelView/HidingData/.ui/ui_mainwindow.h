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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *spacerItem;
    QCheckBox *showDataset3CB;
    QCheckBox *showDataset2CB;
    QCheckBox *showDataset1CB;
    QSplitter *splitter;
    QFrame *chartFrame;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(692, 408);
        gridLayout = new QGridLayout(MainWindow);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        spacerItem = new QSpacerItem(159, 291, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 3, 0, 1, 1);

        showDataset3CB = new QCheckBox(MainWindow);
        showDataset3CB->setObjectName(QStringLiteral("showDataset3CB"));
        showDataset3CB->setChecked(true);

        gridLayout->addWidget(showDataset3CB, 2, 0, 1, 1);

        showDataset2CB = new QCheckBox(MainWindow);
        showDataset2CB->setObjectName(QStringLiteral("showDataset2CB"));
        showDataset2CB->setChecked(true);

        gridLayout->addWidget(showDataset2CB, 1, 0, 1, 1);

        showDataset1CB = new QCheckBox(MainWindow);
        showDataset1CB->setObjectName(QStringLiteral("showDataset1CB"));
        showDataset1CB->setChecked(true);

        gridLayout->addWidget(showDataset1CB, 0, 0, 1, 1);

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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Hiding data without removing them from the model", 0));
        showDataset3CB->setText(QApplication::translate("MainWindow", "Display 3rd dataset", 0));
        showDataset2CB->setText(QApplication::translate("MainWindow", "Display 2nd dataset", 0));
        showDataset1CB->setText(QApplication::translate("MainWindow", "Display 1st dataset", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
