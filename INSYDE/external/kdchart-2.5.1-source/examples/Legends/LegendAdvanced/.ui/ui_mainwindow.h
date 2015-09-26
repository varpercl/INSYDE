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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *vboxLayout;
    QSplitter *splitter;
    QSplitter *splitter2;
    QGroupBox *groupBox_2;
    QVBoxLayout *vboxLayout1;
    QTreeWidget *legendsTV;
    QHBoxLayout *hboxLayout;
    QPushButton *addLegendPB;
    QPushButton *editLegendPB;
    QPushButton *removeLegendPB;
    QFrame *chartFrame;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(885, 597);
        vboxLayout = new QVBoxLayout(MainWindow);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        splitter = new QSplitter(MainWindow);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter2 = new QSplitter(splitter);
        splitter2->setObjectName(QStringLiteral("splitter2"));
        splitter2->setOrientation(Qt::Vertical);
        groupBox_2 = new QGroupBox(splitter2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        vboxLayout1 = new QVBoxLayout(groupBox_2);
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        legendsTV = new QTreeWidget(groupBox_2);
        legendsTV->setObjectName(QStringLiteral("legendsTV"));

        vboxLayout1->addWidget(legendsTV);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        addLegendPB = new QPushButton(groupBox_2);
        addLegendPB->setObjectName(QStringLiteral("addLegendPB"));

        hboxLayout->addWidget(addLegendPB);

        editLegendPB = new QPushButton(groupBox_2);
        editLegendPB->setObjectName(QStringLiteral("editLegendPB"));

        hboxLayout->addWidget(editLegendPB);

        removeLegendPB = new QPushButton(groupBox_2);
        removeLegendPB->setObjectName(QStringLiteral("removeLegendPB"));

        hboxLayout->addWidget(removeLegendPB);


        vboxLayout1->addLayout(hboxLayout);

        splitter2->addWidget(groupBox_2);
        splitter->addWidget(splitter2);
        chartFrame = new QFrame(splitter);
        chartFrame->setObjectName(QStringLiteral("chartFrame"));
        chartFrame->setFrameShape(QFrame::StyledPanel);
        chartFrame->setFrameShadow(QFrame::Raised);
        splitter->addWidget(chartFrame);

        vboxLayout->addWidget(splitter);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "KD Chart 2 example: Legends", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Legends", 0));
        QTreeWidgetItem *___qtreewidgetitem = legendsTV->headerItem();
        ___qtreewidgetitem->setText(5, QApplication::translate("MainWindow", "Style", 0));
        ___qtreewidgetitem->setText(4, QApplication::translate("MainWindow", "Alignment", 0));
        ___qtreewidgetitem->setText(3, QApplication::translate("MainWindow", "Orientation", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindow", "Title", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Show Lines", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Position", 0));
        addLegendPB->setText(QApplication::translate("MainWindow", "A&dd...", 0));
        editLegendPB->setText(QApplication::translate("MainWindow", "Edit...", 0));
        removeLegendPB->setText(QApplication::translate("MainWindow", "R&emove", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
