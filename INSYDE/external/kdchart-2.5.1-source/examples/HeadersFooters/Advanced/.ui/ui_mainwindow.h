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
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout1;
    QTreeWidget *headersTV;
    QHBoxLayout *hboxLayout;
    QPushButton *addHeaderPB;
    QPushButton *editHeaderPB;
    QPushButton *removeHeaderPB;
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
        groupBox = new QGroupBox(splitter2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        vboxLayout1 = new QVBoxLayout(groupBox);
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        headersTV = new QTreeWidget(groupBox);
        headersTV->setObjectName(QStringLiteral("headersTV"));

        vboxLayout1->addWidget(headersTV);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        addHeaderPB = new QPushButton(groupBox);
        addHeaderPB->setObjectName(QStringLiteral("addHeaderPB"));

        hboxLayout->addWidget(addHeaderPB);

        editHeaderPB = new QPushButton(groupBox);
        editHeaderPB->setObjectName(QStringLiteral("editHeaderPB"));

        hboxLayout->addWidget(editHeaderPB);

        removeHeaderPB = new QPushButton(groupBox);
        removeHeaderPB->setObjectName(QStringLiteral("removeHeaderPB"));

        hboxLayout->addWidget(removeHeaderPB);


        vboxLayout1->addLayout(hboxLayout);

        splitter2->addWidget(groupBox);
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "KD Chart 2 example: Headers and Footers", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Headers and Footers", 0));
        QTreeWidgetItem *___qtreewidgetitem = headersTV->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindow", "Position", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Type", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Text", 0));
        addHeaderPB->setText(QApplication::translate("MainWindow", "&Add...", 0));
        editHeaderPB->setText(QApplication::translate("MainWindow", "Edit...", 0));
        removeHeaderPB->setText(QApplication::translate("MainWindow", "&Remove", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
