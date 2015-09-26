/********************************************************************************
** Form generated from reading UI file 'axissettings.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AXISSETTINGS_H
#define UI_AXISSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AxisSettings
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *axisSelection;
    QGroupBox *axisBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *axisVisibility;
    QCheckBox *majorTicks;
    QCheckBox *minorTicks;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *AxisSettings)
    {
        if (AxisSettings->objectName().isEmpty())
            AxisSettings->setObjectName(QStringLiteral("AxisSettings"));
        AxisSettings->resize(400, 154);
        verticalLayout = new QVBoxLayout(AxisSettings);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        axisSelection = new QComboBox(AxisSettings);
        axisSelection->setObjectName(QStringLiteral("axisSelection"));

        verticalLayout->addWidget(axisSelection);

        axisBox = new QGroupBox(AxisSettings);
        axisBox->setObjectName(QStringLiteral("axisBox"));
        verticalLayout_2 = new QVBoxLayout(axisBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        axisVisibility = new QCheckBox(axisBox);
        axisVisibility->setObjectName(QStringLiteral("axisVisibility"));

        verticalLayout_2->addWidget(axisVisibility);

        majorTicks = new QCheckBox(axisBox);
        majorTicks->setObjectName(QStringLiteral("majorTicks"));
        majorTicks->setEnabled(false);

        verticalLayout_2->addWidget(majorTicks);

        minorTicks = new QCheckBox(axisBox);
        minorTicks->setObjectName(QStringLiteral("minorTicks"));
        minorTicks->setEnabled(false);

        verticalLayout_2->addWidget(minorTicks);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout->addWidget(axisBox);


        retranslateUi(AxisSettings);

        QMetaObject::connectSlotsByName(AxisSettings);
    } // setupUi

    void retranslateUi(QWidget *AxisSettings)
    {
        AxisSettings->setWindowTitle(QApplication::translate("AxisSettings", "Form", 0));
        axisBox->setTitle(QApplication::translate("AxisSettings", "Axis Settings", 0));
        axisVisibility->setText(QApplication::translate("AxisSettings", "Show Axis", 0));
        majorTicks->setText(QApplication::translate("AxisSettings", "Show Major Ticks", 0));
        minorTicks->setText(QApplication::translate("AxisSettings", "Show Minor Ticks", 0));
    } // retranslateUi

};

namespace Ui {
    class AxisSettings: public Ui_AxisSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AXISSETTINGS_H
