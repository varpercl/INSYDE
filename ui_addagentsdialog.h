/********************************************************************************
** Form generated from reading UI file 'addagentsdialog.ui'
**
** Created: Sun 23. Dec 16:47:31 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDAGENTSDIALOG_H
#define UI_ADDAGENTSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AddAgentsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QSpinBox *sbNumOfUnits;
    QLabel *label_11;
    QGroupBox *gbUnit;
    QSpinBox *sbInitialEnergy;
    QLabel *label_8;
    QComboBox *cmbController;
    QSpinBox *sbMaxVitality;
    QLabel *label_10;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_6;
    QSpinBox *sbSpeed;
    QLabel *label_4;
    QComboBox *cmbTeam;
    QSpinBox *sbInitialVitality;
    QComboBox *cmbColorList;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_3;
    QSpinBox *sbVisualScope;
    QSpinBox *sbMaxEnergy;
    QComboBox *cmbAgentType;
    QGroupBox *gbShootingUnit;
    QLabel *label_12;
    QSpinBox *sbPowerValue;
    QLabel *label_13;
    QSpinBox *sbRangeValue;

    void setupUi(QDialog *AddAgentsDialog)
    {
        if (AddAgentsDialog->objectName().isEmpty())
            AddAgentsDialog->setObjectName(QString::fromUtf8("AddAgentsDialog"));
        AddAgentsDialog->resize(521, 296);
        AddAgentsDialog->setMinimumSize(QSize(521, 296));
        AddAgentsDialog->setModal(true);
        buttonBox = new QDialogButtonBox(AddAgentsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(350, 260, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_2 = new QLabel(AddAgentsDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 104, 21));
        sbNumOfUnits = new QSpinBox(AddAgentsDialog);
        sbNumOfUnits->setObjectName(QString::fromUtf8("sbNumOfUnits"));
        sbNumOfUnits->setGeometry(QRect(120, 40, 61, 22));
        sbNumOfUnits->setMinimum(1);
        sbNumOfUnits->setMaximum(1000);
        sbNumOfUnits->setValue(10);
        label_11 = new QLabel(AddAgentsDialog);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 10, 72, 21));
        gbUnit = new QGroupBox(AddAgentsDialog);
        gbUnit->setObjectName(QString::fromUtf8("gbUnit"));
        gbUnit->setGeometry(QRect(10, 70, 361, 181));
        sbInitialEnergy = new QSpinBox(gbUnit);
        sbInitialEnergy->setObjectName(QString::fromUtf8("sbInitialEnergy"));
        sbInitialEnergy->setGeometry(QRect(250, 120, 61, 22));
        sbInitialEnergy->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_8 = new QLabel(gbUnit);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(170, 120, 64, 21));
        cmbController = new QComboBox(gbUnit);
        cmbController->setObjectName(QString::fromUtf8("cmbController"));
        cmbController->setGeometry(QRect(90, 60, 131, 22));
        sbMaxVitality = new QSpinBox(gbUnit);
        sbMaxVitality->setObjectName(QString::fromUtf8("sbMaxVitality"));
        sbMaxVitality->setGeometry(QRect(100, 90, 61, 22));
        sbMaxVitality->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbMaxVitality->setMaximum(1000000);
        sbMaxVitality->setValue(200);
        label_10 = new QLabel(gbUnit);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(170, 150, 38, 21));
        label_5 = new QLabel(gbUnit);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 90, 79, 21));
        label_9 = new QLabel(gbUnit);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 150, 67, 21));
        label_6 = new QLabel(gbUnit);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(170, 90, 75, 21));
        sbSpeed = new QSpinBox(gbUnit);
        sbSpeed->setObjectName(QString::fromUtf8("sbSpeed"));
        sbSpeed->setGeometry(QRect(250, 150, 61, 22));
        sbSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbSpeed->setMaximum(10000);
        sbSpeed->setValue(70);
        label_4 = new QLabel(gbUnit);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 60, 57, 21));
        cmbTeam = new QComboBox(gbUnit);
        cmbTeam->setObjectName(QString::fromUtf8("cmbTeam"));
        cmbTeam->setGeometry(QRect(280, 30, 69, 22));
        sbInitialVitality = new QSpinBox(gbUnit);
        sbInitialVitality->setObjectName(QString::fromUtf8("sbInitialVitality"));
        sbInitialVitality->setGeometry(QRect(100, 120, 61, 22));
        sbInitialVitality->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbInitialVitality->setMaximum(1000000);
        sbInitialVitality->setValue(200);
        cmbColorList = new QComboBox(gbUnit);
        cmbColorList->setObjectName(QString::fromUtf8("cmbColorList"));
        cmbColorList->setGeometry(QRect(90, 30, 131, 22));
        label = new QLabel(gbUnit);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 75, 21));
        label_7 = new QLabel(gbUnit);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 120, 68, 21));
        label_3 = new QLabel(gbUnit);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 30, 32, 21));
        sbVisualScope = new QSpinBox(gbUnit);
        sbVisualScope->setObjectName(QString::fromUtf8("sbVisualScope"));
        sbVisualScope->setGeometry(QRect(100, 150, 61, 22));
        sbVisualScope->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbVisualScope->setMaximum(1000000);
        sbVisualScope->setValue(200);
        sbMaxEnergy = new QSpinBox(gbUnit);
        sbMaxEnergy->setObjectName(QString::fromUtf8("sbMaxEnergy"));
        sbMaxEnergy->setGeometry(QRect(250, 90, 61, 22));
        sbMaxEnergy->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbMaxEnergy->setMaximum(1000000);
        cmbAgentType = new QComboBox(AddAgentsDialog);
        cmbAgentType->setObjectName(QString::fromUtf8("cmbAgentType"));
        cmbAgentType->setGeometry(QRect(90, 10, 141, 22));
        gbShootingUnit = new QGroupBox(AddAgentsDialog);
        gbShootingUnit->setObjectName(QString::fromUtf8("gbShootingUnit"));
        gbShootingUnit->setGeometry(QRect(380, 70, 131, 80));
        label_12 = new QLabel(gbShootingUnit);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 20, 28, 21));
        sbPowerValue = new QSpinBox(gbShootingUnit);
        sbPowerValue->setObjectName(QString::fromUtf8("sbPowerValue"));
        sbPowerValue->setGeometry(QRect(50, 20, 71, 22));
        sbPowerValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbPowerValue->setMinimum(1);
        sbPowerValue->setMaximum(999999);
        sbPowerValue->setSingleStep(1);
        sbPowerValue->setValue(10);
        label_13 = new QLabel(gbShootingUnit);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 50, 31, 21));
        sbRangeValue = new QSpinBox(gbShootingUnit);
        sbRangeValue->setObjectName(QString::fromUtf8("sbRangeValue"));
        sbRangeValue->setGeometry(QRect(50, 50, 71, 22));
        sbRangeValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbRangeValue->setMinimum(1);
        sbRangeValue->setMaximum(999999);
        sbRangeValue->setValue(150);

        retranslateUi(AddAgentsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddAgentsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddAgentsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddAgentsDialog);
    } // setupUi

    void retranslateUi(QDialog *AddAgentsDialog)
    {
        AddAgentsDialog->setWindowTitle(QApplication::translate("AddAgentsDialog", "Agregar agentes", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddAgentsDialog", "Cantidad de agentes", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("AddAgentsDialog", "Tipo de agente", 0, QApplication::UnicodeUTF8));
        gbUnit->setTitle(QApplication::translate("AddAgentsDialog", "Unidad", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("AddAgentsDialog", "Energ\303\255a inicial", 0, QApplication::UnicodeUTF8));
        cmbController->clear();
        cmbController->insertItems(0, QStringList()
         << QApplication::translate("AddAgentsDialog", "Humano", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddAgentsDialog", "Computadora", 0, QApplication::UnicodeUTF8)
        );
        label_10->setText(QApplication::translate("AddAgentsDialog", "Rapidez", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AddAgentsDialog", "Vitalidad maxima", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("AddAgentsDialog", "Alcance visual", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AddAgentsDialog", "Energ\303\255a m\303\241xima", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AddAgentsDialog", "Controlador", 0, QApplication::UnicodeUTF8));
        cmbTeam->clear();
        cmbTeam->insertItems(0, QStringList()
         << QApplication::translate("AddAgentsDialog", "Ninguno", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddAgentsDialog", "Equipo 1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddAgentsDialog", "Equipo 2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddAgentsDialog", "Equipo 3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddAgentsDialog", "Equipo 4", 0, QApplication::UnicodeUTF8)
        );
        cmbColorList->clear();
        cmbColorList->insertItems(0, QStringList()
         << QApplication::translate("AddAgentsDialog", "Azul", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddAgentsDialog", "Verde", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddAgentsDialog", "Amarillo", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddAgentsDialog", "Marron", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddAgentsDialog", "Morado", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddAgentsDialog", "Cian", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddAgentsDialog", "Rojo", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddAgentsDialog", "Naranja", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("AddAgentsDialog", "Color de unidad", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("AddAgentsDialog", "Vitalidad inicial", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AddAgentsDialog", "Equipo", 0, QApplication::UnicodeUTF8));
        cmbAgentType->clear();
        cmbAgentType->insertItems(0, QStringList()
         << QApplication::translate("AddAgentsDialog", "Unidad", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddAgentsDialog", "Unidad de tiro", 0, QApplication::UnicodeUTF8)
        );
        gbShootingUnit->setTitle(QApplication::translate("AddAgentsDialog", "Unidad de tiro", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("AddAgentsDialog", "Poder", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("AddAgentsDialog", "Rango", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddAgentsDialog: public Ui_AddAgentsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDAGENTSDIALOG_H
