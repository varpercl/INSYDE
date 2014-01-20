/********************************************************************************
** Form generated from reading UI file 'imagerepresentationwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEREPRESENTATIONWIDGET_H
#define UI_IMAGEREPRESENTATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageRepresentationWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpinBox *sbWidth;
    QComboBox *cbImageFormat;
    QSpinBox *sbHeight;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *ImageRepresentationWidget)
    {
        if (ImageRepresentationWidget->objectName().isEmpty())
            ImageRepresentationWidget->setObjectName(QStringLiteral("ImageRepresentationWidget"));
        ImageRepresentationWidget->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ImageRepresentationWidget->sizePolicy().hasHeightForWidth());
        ImageRepresentationWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(ImageRepresentationWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(ImageRepresentationWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        sbWidth = new QSpinBox(groupBox_2);
        sbWidth->setObjectName(QStringLiteral("sbWidth"));
        sbWidth->setMinimum(1);
        sbWidth->setMaximum(999999);

        gridLayout->addWidget(sbWidth, 1, 1, 1, 1);

        cbImageFormat = new QComboBox(groupBox_2);
        cbImageFormat->setObjectName(QStringLiteral("cbImageFormat"));

        gridLayout->addWidget(cbImageFormat, 0, 1, 1, 1);

        sbHeight = new QSpinBox(groupBox_2);
        sbHeight->setObjectName(QStringLiteral("sbHeight"));
        sbHeight->setMinimum(1);
        sbHeight->setMaximum(999999);

        gridLayout->addWidget(sbHeight, 3, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 2, 1, 1);


        verticalLayout->addWidget(groupBox_2);


        retranslateUi(ImageRepresentationWidget);

        QMetaObject::connectSlotsByName(ImageRepresentationWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageRepresentationWidget)
    {
        ImageRepresentationWidget->setWindowTitle(QApplication::translate("ImageRepresentationWidget", "Form", 0));
        groupBox_2->setTitle(QApplication::translate("ImageRepresentationWidget", "Dimensiones", 0));
        label_2->setText(QApplication::translate("ImageRepresentationWidget", "Altura", 0));
        cbImageFormat->clear();
        cbImageFormat->insertItems(0, QStringList()
         << QApplication::translate("ImageRepresentationWidget", "RGB 8 bits", 0)
        );
        label_6->setText(QApplication::translate("ImageRepresentationWidget", "Formato", 0));
        label->setText(QApplication::translate("ImageRepresentationWidget", "Anchura", 0));
        label_3->setText(QApplication::translate("ImageRepresentationWidget", "pixeles", 0));
        label_4->setText(QApplication::translate("ImageRepresentationWidget", "pixeles", 0));
    } // retranslateUi

};

namespace Ui {
    class ImageRepresentationWidget: public Ui_ImageRepresentationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEREPRESENTATIONWIDGET_H
