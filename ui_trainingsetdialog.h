/********************************************************************************
** Form generated from reading UI file 'trainingsetdialog.ui'
**
** Created: Sat 19. Jan 16:02:31 2013
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAININGSETDIALOG_H
#define UI_TRAININGSETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TrainingSetDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addPatternButton;
    QPushButton *delPatternButton;
    QTableWidget *patternTable;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TrainingSetDialog)
    {
        if (TrainingSetDialog->objectName().isEmpty())
            TrainingSetDialog->setObjectName(QStringLiteral("TrainingSetDialog"));
        TrainingSetDialog->resize(630, 409);
        verticalLayout = new QVBoxLayout(TrainingSetDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

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
        patternTable->verticalHeader()->setVisible(true);
        patternTable->verticalHeader()->setCascadingSectionResizes(true);
        patternTable->verticalHeader()->setHighlightSections(true);
        patternTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        patternTable->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(patternTable);

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
        addPatternButton->setText(QString());
        delPatternButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TrainingSetDialog: public Ui_TrainingSetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAININGSETDIALOG_H
