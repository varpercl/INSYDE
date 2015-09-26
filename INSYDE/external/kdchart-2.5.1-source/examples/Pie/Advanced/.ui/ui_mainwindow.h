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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
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
    QHBoxLayout *hboxLayout;
    QLabel *zoomFactorLB;
    QDoubleSpinBox *startPositionSB;
    QSlider *startPositionSL;
    QFrame *line;
    QGroupBox *threeDGB;
    QHBoxLayout *hboxLayout1;
    QLabel *label_3;
    QSpinBox *threeDFactorSB;
    QFrame *line_2;
    QGroupBox *explodeGB;
    QGridLayout *gridLayout1;
    QSpinBox *explodeDatasetSB;
    QLabel *label_2;
    QLabel *label;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *spacerItem;
    QPushButton *explodeSubmitPB;
    QSpacerItem *spacerItem1;
    QDoubleSpinBox *explodeFactorSB;
    QCheckBox *animateExplosionCB;
    QSpacerItem *spacerItem2;
    QScrollBar *hSBar;
    QSplitter *splitter;
    QFrame *chartFrame;
    QScrollBar *vSBar;

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
        vboxLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        zoomFactorLB = new QLabel(MainWindow);
        zoomFactorLB->setObjectName(QStringLiteral("zoomFactorLB"));

        hboxLayout->addWidget(zoomFactorLB);

        startPositionSB = new QDoubleSpinBox(MainWindow);
        startPositionSB->setObjectName(QStringLiteral("startPositionSB"));
        startPositionSB->setMinimum(0);
        startPositionSB->setMaximum(360);
        startPositionSB->setSingleStep(1);
        startPositionSB->setValue(0);

        hboxLayout->addWidget(startPositionSB);


        vboxLayout->addLayout(hboxLayout);

        startPositionSL = new QSlider(MainWindow);
        startPositionSL->setObjectName(QStringLiteral("startPositionSL"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(startPositionSL->sizePolicy().hasHeightForWidth());
        startPositionSL->setSizePolicy(sizePolicy);
        startPositionSL->setMaximum(360);
        startPositionSL->setOrientation(Qt::Horizontal);

        vboxLayout->addWidget(startPositionSL);

        line = new QFrame(MainWindow);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line);

        threeDGB = new QGroupBox(MainWindow);
        threeDGB->setObjectName(QStringLiteral("threeDGB"));
        threeDGB->setCheckable(true);
        threeDGB->setChecked(false);
        hboxLayout1 = new QHBoxLayout(threeDGB);
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        label_3 = new QLabel(threeDGB);
        label_3->setObjectName(QStringLiteral("label_3"));

        hboxLayout1->addWidget(label_3);

        threeDFactorSB = new QSpinBox(threeDGB);
        threeDFactorSB->setObjectName(QStringLiteral("threeDFactorSB"));
        threeDFactorSB->setValue(20);

        hboxLayout1->addWidget(threeDFactorSB);


        vboxLayout->addWidget(threeDGB);

        line_2 = new QFrame(MainWindow);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line_2);

        explodeGB = new QGroupBox(MainWindow);
        explodeGB->setObjectName(QStringLiteral("explodeGB"));
        explodeGB->setCheckable(false);
        explodeGB->setChecked(false);
        gridLayout1 = new QGridLayout(explodeGB);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        explodeDatasetSB = new QSpinBox(explodeGB);
        explodeDatasetSB->setObjectName(QStringLiteral("explodeDatasetSB"));
        explodeDatasetSB->setMaximum(0);

        gridLayout1->addWidget(explodeDatasetSB, 0, 1, 1, 1);

        label_2 = new QLabel(explodeGB);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout1->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(explodeGB);
        label->setObjectName(QStringLiteral("label"));

        gridLayout1->addWidget(label, 0, 0, 1, 1);

        hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QStringLiteral("hboxLayout2"));
        spacerItem = new QSpacerItem(20, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem);

        explodeSubmitPB = new QPushButton(explodeGB);
        explodeSubmitPB->setObjectName(QStringLiteral("explodeSubmitPB"));

        hboxLayout2->addWidget(explodeSubmitPB);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem1);


        gridLayout1->addLayout(hboxLayout2, 2, 0, 1, 2);

        explodeFactorSB = new QDoubleSpinBox(explodeGB);
        explodeFactorSB->setObjectName(QStringLiteral("explodeFactorSB"));
        explodeFactorSB->setMaximum(1);
        explodeFactorSB->setSingleStep(0.05);

        gridLayout1->addWidget(explodeFactorSB, 1, 1, 1, 1);

        animateExplosionCB = new QCheckBox(explodeGB);
        animateExplosionCB->setObjectName(QStringLiteral("animateExplosionCB"));

        gridLayout1->addWidget(animateExplosionCB, 3, 0, 1, 1);


        vboxLayout->addWidget(explodeGB);

        spacerItem2 = new QSpacerItem(188, 311, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem2);


        gridLayout->addLayout(vboxLayout, 0, 0, 1, 1);

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

        vSBar = new QScrollBar(MainWindow);
        vSBar->setObjectName(QStringLiteral("vSBar"));
        vSBar->setMaximum(999);
        vSBar->setSingleStep(10);
        vSBar->setPageStep(100);
        vSBar->setValue(500);
        vSBar->setOrientation(Qt::Vertical);

        gridLayout->addWidget(vSBar, 0, 2, 1, 1);


        retranslateUi(MainWindow);
        QObject::connect(animateExplosionCB, SIGNAL(toggled(bool)), explodeDatasetSB, SLOT(setDisabled(bool)));
        QObject::connect(animateExplosionCB, SIGNAL(toggled(bool)), explodeFactorSB, SLOT(setDisabled(bool)));
        QObject::connect(animateExplosionCB, SIGNAL(toggled(bool)), explodeSubmitPB, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Pie Chart ", 0));
        zoomFactorLB->setText(QApplication::translate("MainWindow", "Start position", 0));
        threeDGB->setTitle(QApplication::translate("MainWindow", "3D", 0));
        label_3->setText(QApplication::translate("MainWindow", "Factor", 0));
        explodeGB->setTitle(QApplication::translate("MainWindow", "Explode", 0));
        label_2->setText(QApplication::translate("MainWindow", "Factor", 0));
        label->setText(QApplication::translate("MainWindow", "Dataset", 0));
        explodeSubmitPB->setText(QApplication::translate("MainWindow", "Submit", 0));
        animateExplosionCB->setText(QApplication::translate("MainWindow", "Animate", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
