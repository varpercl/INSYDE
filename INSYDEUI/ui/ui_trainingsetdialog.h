/********************************************************************************
** Form generated from reading UI file 'trainingsetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAININGSETDIALOG_H
#define UI_TRAININGSETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TrainingSetDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton;
    QPushButton *addPatternButton;
    QPushButton *delPatternButton;
    QTableWidget *patternTable;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QFrame *line;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_4;
    QSpinBox *sbWidth;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QSpinBox *sbHeight;
    QGraphicsView *gvRepresentation;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QFrame *line_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QComboBox *comboBox_2;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_7;
    QSpinBox *sbWidth_2;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QSpinBox *sbHeight_2;
    QGraphicsView *gvOutputRepresentation;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TrainingSetDialog)
    {
        if (TrainingSetDialog->objectName().isEmpty())
            TrainingSetDialog->setObjectName(QStringLiteral("TrainingSetDialog"));
        TrainingSetDialog->resize(630, 548);
        verticalLayout = new QVBoxLayout(TrainingSetDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton = new QToolButton(TrainingSetDialog);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        toolButton->setAutoRaise(false);

        horizontalLayout->addWidget(toolButton);

        addPatternButton = new QPushButton(TrainingSetDialog);
        addPatternButton->setObjectName(QStringLiteral("addPatternButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/imagenes/plus_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        addPatternButton->setIcon(icon);

        horizontalLayout->addWidget(addPatternButton);

        delPatternButton = new QPushButton(TrainingSetDialog);
        delPatternButton->setObjectName(QStringLiteral("delPatternButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imagenes/minus_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        delPatternButton->setIcon(icon1);

        horizontalLayout->addWidget(delPatternButton);


        verticalLayout->addLayout(horizontalLayout);

        patternTable = new QTableWidget(TrainingSetDialog);
        patternTable->setObjectName(QStringLiteral("patternTable"));
        patternTable->setAlternatingRowColors(true);
        patternTable->setRowCount(0);
        patternTable->setColumnCount(0);
        patternTable->verticalHeader()->setVisible(false);
        patternTable->verticalHeader()->setCascadingSectionResizes(true);
        patternTable->verticalHeader()->setHighlightSections(true);
        patternTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        patternTable->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(patternTable);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_5 = new QLabel(TrainingSetDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_5);

        line = new QFrame(TrainingSetDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        groupBox = new QGroupBox(TrainingSetDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_2->addWidget(comboBox);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(TrainingSetDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 2, 1, 1);

        sbWidth = new QSpinBox(groupBox_2);
        sbWidth->setObjectName(QStringLiteral("sbWidth"));
        sbWidth->setMinimum(1);
        sbWidth->setMaximum(999999);

        gridLayout->addWidget(sbWidth, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        sbHeight = new QSpinBox(groupBox_2);
        sbHeight->setObjectName(QStringLiteral("sbHeight"));
        sbHeight->setMinimum(1);
        sbHeight->setMaximum(999999);

        gridLayout->addWidget(sbHeight, 2, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox_2);

        gvRepresentation = new QGraphicsView(TrainingSetDialog);
        gvRepresentation->setObjectName(QStringLiteral("gvRepresentation"));

        verticalLayout_3->addWidget(gvRepresentation);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_6 = new QLabel(TrainingSetDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_6);

        line_2 = new QFrame(TrainingSetDialog);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_2);

        groupBox_3 = new QGroupBox(TrainingSetDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        comboBox_2 = new QComboBox(groupBox_3);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        verticalLayout_5->addWidget(comboBox_2);


        verticalLayout_4->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(TrainingSetDialog);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 3, 1, 1, 1);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 2, 2, 1, 1);

        sbWidth_2 = new QSpinBox(groupBox_4);
        sbWidth_2->setObjectName(QStringLiteral("sbWidth_2"));
        sbWidth_2->setMinimum(1);
        sbWidth_2->setMaximum(999999);

        gridLayout_3->addWidget(sbWidth_2, 0, 1, 1, 1);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 2, 0, 1, 1);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_3->addWidget(label_9, 0, 0, 1, 1);

        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 0, 2, 1, 1);

        sbHeight_2 = new QSpinBox(groupBox_4);
        sbHeight_2->setObjectName(QStringLiteral("sbHeight_2"));
        sbHeight_2->setMinimum(1);
        sbHeight_2->setMaximum(999999);

        gridLayout_3->addWidget(sbHeight_2, 2, 1, 1, 1);


        verticalLayout_4->addWidget(groupBox_4);

        gvOutputRepresentation = new QGraphicsView(TrainingSetDialog);
        gvOutputRepresentation->setObjectName(QStringLiteral("gvOutputRepresentation"));

        verticalLayout_4->addWidget(gvOutputRepresentation);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout_2);

        buttonBox = new QDialogButtonBox(TrainingSetDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TrainingSetDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TrainingSetDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TrainingSetDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TrainingSetDialog);
    } // setupUi

    void retranslateUi(QDialog *TrainingSetDialog)
    {
        TrainingSetDialog->setWindowTitle(QApplication::translate("TrainingSetDialog", "Dialog", 0));
        toolButton->setText(QApplication::translate("TrainingSetDialog", "...", 0));
        addPatternButton->setText(QString());
        delPatternButton->setText(QString());
        label_5->setText(QApplication::translate("TrainingSetDialog", "Entradas", 0));
        groupBox->setTitle(QApplication::translate("TrainingSetDialog", "Representacion", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("TrainingSetDialog", "Imagen", 0)
         << QApplication::translate("TrainingSetDialog", "Matriz de puntos", 0)
        );
        groupBox_2->setTitle(QApplication::translate("TrainingSetDialog", "Dimensiones", 0));
        label_4->setText(QApplication::translate("TrainingSetDialog", "pixeles", 0));
        label_2->setText(QApplication::translate("TrainingSetDialog", "Altura", 0));
        label->setText(QApplication::translate("TrainingSetDialog", "Anchura", 0));
        label_3->setText(QApplication::translate("TrainingSetDialog", "pixeles", 0));
        label_6->setText(QApplication::translate("TrainingSetDialog", "Salidas", 0));
        groupBox_3->setTitle(QApplication::translate("TrainingSetDialog", "Representacion", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("TrainingSetDialog", "Imagen", 0)
         << QApplication::translate("TrainingSetDialog", "Matriz de puntos", 0)
        );
        groupBox_4->setTitle(QApplication::translate("TrainingSetDialog", "Dimensiones", 0));
        label_7->setText(QApplication::translate("TrainingSetDialog", "pixeles", 0));
        label_8->setText(QApplication::translate("TrainingSetDialog", "Altura", 0));
        label_9->setText(QApplication::translate("TrainingSetDialog", "Anchura", 0));
        label_10->setText(QApplication::translate("TrainingSetDialog", "pixeles", 0));
    } // retranslateUi

};

namespace Ui {
    class TrainingSetDialog: public Ui_TrainingSetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAININGSETDIALOG_H
