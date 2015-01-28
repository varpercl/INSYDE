/********************************************************************************
** Form generated from reading UI file 'imagerepresentationwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEREPRESENTATIONWIDGET_H
#define UI_IMAGEREPRESENTATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageRepresentationWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QComboBox *cbImageFormat;
    QCheckBox *cbxIgnoreAlpha;
    QSpacerItem *horizontalSpacer;

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
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_6);

        cbImageFormat = new QComboBox(groupBox_2);
        cbImageFormat->setObjectName(QStringLiteral("cbImageFormat"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cbImageFormat->sizePolicy().hasHeightForWidth());
        cbImageFormat->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(cbImageFormat);

        cbxIgnoreAlpha = new QCheckBox(groupBox_2);
        cbxIgnoreAlpha->setObjectName(QStringLiteral("cbxIgnoreAlpha"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(cbxIgnoreAlpha->sizePolicy().hasHeightForWidth());
        cbxIgnoreAlpha->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(cbxIgnoreAlpha);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addWidget(groupBox_2);


        retranslateUi(ImageRepresentationWidget);

        QMetaObject::connectSlotsByName(ImageRepresentationWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageRepresentationWidget)
    {
        ImageRepresentationWidget->setWindowTitle(QApplication::translate("ImageRepresentationWidget", "Form", 0));
        groupBox_2->setTitle(QApplication::translate("ImageRepresentationWidget", "Dimensiones", 0));
        label_6->setText(QApplication::translate("ImageRepresentationWidget", "Formato", 0));
        cbImageFormat->clear();
        cbImageFormat->insertItems(0, QStringList()
         << QApplication::translate("ImageRepresentationWidget", "RGB 8 bits", 0)
        );
        cbxIgnoreAlpha->setText(QApplication::translate("ImageRepresentationWidget", "Ignorar canal alfa", 0));
    } // retranslateUi

};

namespace Ui {
    class ImageRepresentationWidget: public Ui_ImageRepresentationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEREPRESENTATIONWIDGET_H
