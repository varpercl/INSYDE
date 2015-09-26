/********************************************************************************
** Form generated from reading UI file 'KDChartDatasetSelector.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KDCHARTDATASETSELECTOR_H
#define UI_KDCHARTDATASETSELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatasetSelector
{
public:
    QHBoxLayout *hboxLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCheckBox *cbReverseColumns;
    QLabel *label_5;
    QSpinBox *sbStartColumn;
    QLabel *label_2;
    QSpinBox *sbColumnCount;
    QLabel *label;
    QLabel *label_6;
    QSpinBox *sbStartRow;
    QLabel *label_4;
    QCheckBox *cbReverseRows;
    QLabel *label_3;
    QSpinBox *sbRowCount;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *DatasetSelector)
    {
        if (DatasetSelector->objectName().isEmpty())
            DatasetSelector->setObjectName(QStringLiteral("DatasetSelector"));
        DatasetSelector->resize(728, 344);
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(3), static_cast<QSizePolicy::Policy>(3));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DatasetSelector->sizePolicy().hasHeightForWidth());
        DatasetSelector->setSizePolicy(sizePolicy);
        DatasetSelector->setMinimumSize(QSize(0, 0));
        hboxLayout = new QHBoxLayout(DatasetSelector);
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        groupBox = new QGroupBox(DatasetSelector);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setCheckable(true);
        groupBox->setChecked(false);
        gridLayout = new QGridLayout(groupBox);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        cbReverseColumns = new QCheckBox(groupBox);
        cbReverseColumns->setObjectName(QStringLiteral("cbReverseColumns"));

        gridLayout->addWidget(cbReverseColumns, 3, 1, 1, 3);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        sbStartColumn = new QSpinBox(groupBox);
        sbStartColumn->setObjectName(QStringLiteral("sbStartColumn"));

        gridLayout->addWidget(sbStartColumn, 2, 3, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 2, 2, 1, 1);

        sbColumnCount = new QSpinBox(groupBox);
        sbColumnCount->setObjectName(QStringLiteral("sbColumnCount"));

        gridLayout->addWidget(sbColumnCount, 2, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        sbStartRow = new QSpinBox(groupBox);
        sbStartRow->setObjectName(QStringLiteral("sbStartRow"));

        gridLayout->addWidget(sbStartRow, 0, 3, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        cbReverseRows = new QCheckBox(groupBox);
        cbReverseRows->setObjectName(QStringLiteral("cbReverseRows"));

        gridLayout->addWidget(cbReverseRows, 1, 1, 1, 3);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        sbRowCount = new QSpinBox(groupBox);
        sbRowCount->setObjectName(QStringLiteral("sbRowCount"));

        gridLayout->addWidget(sbRowCount, 0, 1, 1, 1);

        spacerItem = new QSpacerItem(169, 31, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 4, 2, 1, 1);


        hboxLayout->addWidget(groupBox);


        retranslateUi(DatasetSelector);

        QMetaObject::connectSlotsByName(DatasetSelector);
    } // setupUi

    void retranslateUi(QWidget *DatasetSelector)
    {
        DatasetSelector->setWindowTitle(QApplication::translate("DatasetSelector", "Data Selector", 0));
        groupBox->setTitle(QApplication::translate("DatasetSelector", "Only display a subset of the model in the chart:", 0));
        cbReverseColumns->setText(QApplication::translate("DatasetSelector", "in reverse order.", 0));
        label_5->setText(QApplication::translate("DatasetSelector", "...", 0));
        label_2->setText(QApplication::translate("DatasetSelector", "columns starting at column", 0));
        label->setText(QApplication::translate("DatasetSelector", "Display", 0));
        label_6->setText(QApplication::translate("DatasetSelector", "...", 0));
        label_4->setText(QApplication::translate("DatasetSelector", "rows starting at row", 0));
        cbReverseRows->setText(QApplication::translate("DatasetSelector", "in reverse order.", 0));
        label_3->setText(QApplication::translate("DatasetSelector", "Display", 0));
    } // retranslateUi

};

namespace Ui {
    class DatasetSelector: public Ui_DatasetSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KDCHARTDATASETSELECTOR_H
