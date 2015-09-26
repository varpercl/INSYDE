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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QFrame *line;
    QLabel *lineTypeLB;
    QComboBox *stockTypeCB;
    QFrame *line_2;
    QGroupBox *threeDProperties;
    QGridLayout *gridLayout;
    QLabel *label;
    QSlider *perspectiveAngle;
    QCheckBox *useShadowColors;
    QSlider *perspectiveDepth;
    QLabel *label_2;
    QGroupBox *colorGroup;
    QHBoxLayout *horizontalLayout;
    QPushButton *colorChooser;
    QSpacerItem *spacerItem;
    QSplitter *splitter;
    QFrame *chartFrame;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(585, 530);
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
        line = new QFrame(MainWindow);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line);

        lineTypeLB = new QLabel(MainWindow);
        lineTypeLB->setObjectName(QStringLiteral("lineTypeLB"));

        vboxLayout->addWidget(lineTypeLB);

        stockTypeCB = new QComboBox(MainWindow);
        stockTypeCB->setObjectName(QStringLiteral("stockTypeCB"));

        vboxLayout->addWidget(stockTypeCB);

        line_2 = new QFrame(MainWindow);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line_2);

        threeDProperties = new QGroupBox(MainWindow);
        threeDProperties->setObjectName(QStringLiteral("threeDProperties"));
        threeDProperties->setCheckable(true);
        threeDProperties->setChecked(false);
        gridLayout = new QGridLayout(threeDProperties);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(threeDProperties);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        perspectiveAngle = new QSlider(threeDProperties);
        perspectiveAngle->setObjectName(QStringLiteral("perspectiveAngle"));
        perspectiveAngle->setMaximum(360);
        perspectiveAngle->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(perspectiveAngle, 1, 0, 1, 1);

        useShadowColors = new QCheckBox(threeDProperties);
        useShadowColors->setObjectName(QStringLiteral("useShadowColors"));

        gridLayout->addWidget(useShadowColors, 4, 0, 1, 1);

        perspectiveDepth = new QSlider(threeDProperties);
        perspectiveDepth->setObjectName(QStringLiteral("perspectiveDepth"));
        perspectiveDepth->setMaximum(25);
        perspectiveDepth->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(perspectiveDepth, 3, 0, 1, 1);

        label_2 = new QLabel(threeDProperties);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);


        vboxLayout->addWidget(threeDProperties);

        colorGroup = new QGroupBox(MainWindow);
        colorGroup->setObjectName(QStringLiteral("colorGroup"));
        horizontalLayout = new QHBoxLayout(colorGroup);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        colorChooser = new QPushButton(colorGroup);
        colorChooser->setObjectName(QStringLiteral("colorChooser"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(colorChooser->sizePolicy().hasHeightForWidth());
        colorChooser->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(colorChooser);


        vboxLayout->addWidget(colorGroup);

        spacerItem = new QSpacerItem(193, 41, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);


        hboxLayout->addLayout(vboxLayout);

        splitter = new QSplitter(MainWindow);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        chartFrame = new QFrame(splitter);
        chartFrame->setObjectName(QStringLiteral("chartFrame"));
        chartFrame->setFrameShape(QFrame::StyledPanel);
        chartFrame->setFrameShadow(QFrame::Raised);
        splitter->addWidget(chartFrame);

        hboxLayout->addWidget(splitter);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Stock Chart ", 0));
        lineTypeLB->setText(QApplication::translate("MainWindow", "Stock Chart Type", 0));
        stockTypeCB->clear();
        stockTypeCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "High-Low-Close", 0)
         << QApplication::translate("MainWindow", "Open-High-Low-Close", 0)
         << QApplication::translate("MainWindow", "Candlestick", 0)
        );
        threeDProperties->setTitle(QApplication::translate("MainWindow", "3D", 0));
        label->setText(QApplication::translate("MainWindow", "Perspective Angle (0\302\260-360\302\260)", 0));
        useShadowColors->setText(QApplication::translate("MainWindow", "Use shadow colors", 0));
        label_2->setText(QApplication::translate("MainWindow", "Depth (0-25px)", 0));
        colorGroup->setTitle(QApplication::translate("MainWindow", "Colors", 0));
        colorChooser->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
