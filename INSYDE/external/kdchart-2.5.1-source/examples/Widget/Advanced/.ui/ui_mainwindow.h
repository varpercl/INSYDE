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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *spacerItem;
    QLineEdit *lineAddDataset;
    QPushButton *btnAddDataset;
    QComboBox *typeSelector;
    QFrame *chartFrame;
    QLabel *typeLabel;
    QLabel *leadingLabel;
    QSpacerItem *spacerItem1;
    QSpinBox *leadingSelector;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(561, 512);
        gridLayout = new QGridLayout(MainWindow);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        spacerItem = new QSpacerItem(211, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 2, 0, 1, 1);

        lineAddDataset = new QLineEdit(MainWindow);
        lineAddDataset->setObjectName(QStringLiteral("lineAddDataset"));

        gridLayout->addWidget(lineAddDataset, 2, 1, 1, 4);

        btnAddDataset = new QPushButton(MainWindow);
        btnAddDataset->setObjectName(QStringLiteral("btnAddDataset"));

        gridLayout->addWidget(btnAddDataset, 2, 5, 1, 1);

        typeSelector = new QComboBox(MainWindow);
        typeSelector->setObjectName(QStringLiteral("typeSelector"));

        gridLayout->addWidget(typeSelector, 1, 4, 1, 2);

        chartFrame = new QFrame(MainWindow);
        chartFrame->setObjectName(QStringLiteral("chartFrame"));
        chartFrame->setFrameShape(QFrame::StyledPanel);
        chartFrame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(chartFrame, 0, 0, 1, 6);

        typeLabel = new QLabel(MainWindow);
        typeLabel->setObjectName(QStringLiteral("typeLabel"));

        gridLayout->addWidget(typeLabel, 1, 3, 1, 1);

        leadingLabel = new QLabel(MainWindow);
        leadingLabel->setObjectName(QStringLiteral("leadingLabel"));

        gridLayout->addWidget(leadingLabel, 1, 1, 1, 1);

        spacerItem1 = new QSpacerItem(181, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem1, 1, 0, 1, 1);

        leadingSelector = new QSpinBox(MainWindow);
        leadingSelector->setObjectName(QStringLiteral("leadingSelector"));

        gridLayout->addWidget(leadingSelector, 1, 2, 1, 1);

#ifndef QT_NO_SHORTCUT
        typeLabel->setBuddy(typeSelector);
#endif // QT_NO_SHORTCUT

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Advanced", 0));
        btnAddDataset->setText(QApplication::translate("MainWindow", "Add dataset", 0));
        typeSelector->clear();
        typeSelector->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Widget::Bar", 0)
         << QApplication::translate("MainWindow", "Widget::Line", 0)
         << QApplication::translate("MainWindow", "Widget::Pie", 0)
         << QApplication::translate("MainWindow", "Widget::Polar", 0)
        );
        typeLabel->setText(QApplication::translate("MainWindow", "Select type", 0));
        leadingLabel->setText(QApplication::translate("MainWindow", "Leading", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
