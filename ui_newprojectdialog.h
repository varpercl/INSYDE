/********************************************************************************
** Form generated from reading UI file 'newprojectdialog.ui'
**
** Created: Sat 19. Jan 16:02:31 2013
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROJECTDIALOG_H
#define UI_NEWPROJECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWizard>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_Wizard
{
public:
    QWizardPage *selectProjectPage;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QFrame *line;
    QTreeWidget *treeProjects;
    QTextEdit *lblDescription;
    QWizardPage *chooseProjectNamePage;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QFrame *line_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_3;
    QLabel *label_23;
    QLabel *label_24;
    QLineEdit *lineEdit_4;
    QLabel *label_25;
    QLineEdit *lineEdit_5;
    QToolButton *toolButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QWizardPage *newPerceptronPage;
    QHBoxLayout *horizontalLayout_7;
    QFrame *frame;
    QFormLayout *formLayout_4;
    QLabel *label_14;
    QSpinBox *spinBox_2;
    QLabel *label_15;
    QComboBox *comboBox_4;
    QLabel *label_16;
    QComboBox *comboBox_5;
    QLabel *label_17;
    QComboBox *comboBox_6;
    QFrame *line_5;
    QLabel *conjuntoDeEntranamientoLabel_2;
    QPushButton *pushButton_2;
    QLabel *label_18;
    QLineEdit *lineEdit;
    QFrame *line_6;
    QWizardPage *newAdalinePage;
    QHBoxLayout *horizontalLayout_8;
    QFrame *frame_2;
    QFormLayout *formLayout_5;
    QLabel *label_19;
    QLineEdit *lineEdit_2;
    QLabel *label_20;
    QSpinBox *spinBox_3;
    QLabel *label_21;
    QComboBox *comboBox_7;
    QLabel *label_22;
    QComboBox *comboBox_8;
    QFrame *line_7;
    QLabel *conjuntoDeEntranamientoLabel_3;
    QPushButton *pushButton_3;
    QFrame *line_8;

    void setupUi(QWizard *Wizard)
    {
        if (Wizard->objectName().isEmpty())
            Wizard->setObjectName(QStringLiteral("Wizard"));
        Wizard->resize(585, 452);
        Wizard->setTitleFormat(Qt::RichText);
        Wizard->setSubTitleFormat(Qt::RichText);
        selectProjectPage = new QWizardPage();
        selectProjectPage->setObjectName(QStringLiteral("selectProjectPage"));
        verticalLayout = new QVBoxLayout(selectProjectPage);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(selectProjectPage);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setTextFormat(Qt::AutoText);

        verticalLayout->addWidget(label_3);

        line = new QFrame(selectProjectPage);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        treeProjects = new QTreeWidget(selectProjectPage);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeProjects->setHeaderItem(__qtreewidgetitem);
        QIcon icon;
        icon.addFile(QStringLiteral(":/imagenes/artificial neural network.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imagenes/perceptron2.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/imagenes/adaline.gif"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/imagenes/perceptron multicapa.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/imagenes/hopfield.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/imagenes/sistema multiagente.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/imagenes/fuzzy logic.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeProjects);
        __qtreewidgetitem1->setIcon(0, icon);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem1);
        __qtreewidgetitem2->setIcon(0, icon1);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem1);
        __qtreewidgetitem3->setIcon(0, icon2);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(__qtreewidgetitem1);
        __qtreewidgetitem4->setIcon(0, icon3);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem1);
        __qtreewidgetitem5->setIcon(0, icon4);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(treeProjects);
        __qtreewidgetitem6->setIcon(0, icon5);
        new QTreeWidgetItem(__qtreewidgetitem6);
        new QTreeWidgetItem(__qtreewidgetitem6);
        QTreeWidgetItem *__qtreewidgetitem7 = new QTreeWidgetItem(treeProjects);
        __qtreewidgetitem7->setIcon(0, icon6);
        new QTreeWidgetItem(__qtreewidgetitem7);
        treeProjects->setObjectName(QStringLiteral("treeProjects"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeProjects->sizePolicy().hasHeightForWidth());
        treeProjects->setSizePolicy(sizePolicy1);
        treeProjects->setMinimumSize(QSize(200, 0));
        treeProjects->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeProjects->setProperty("showDropIndicator", QVariant(true));
        treeProjects->setIconSize(QSize(20, 20));
        treeProjects->setRootIsDecorated(true);
        treeProjects->setAnimated(true);
        treeProjects->header()->setVisible(false);

        verticalLayout->addWidget(treeProjects);

        lblDescription = new QTextEdit(selectProjectPage);
        lblDescription->setObjectName(QStringLiteral("lblDescription"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblDescription->sizePolicy().hasHeightForWidth());
        lblDescription->setSizePolicy(sizePolicy2);
        lblDescription->setMinimumSize(QSize(0, 0));
        lblDescription->setMaximumSize(QSize(16777215, 100));
        lblDescription->setFrameShape(QFrame::Panel);
        lblDescription->setFrameShadow(QFrame::Sunken);
        lblDescription->setReadOnly(true);
        lblDescription->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(lblDescription);

        Wizard->addPage(selectProjectPage);
        chooseProjectNamePage = new QWizardPage();
        chooseProjectNamePage->setObjectName(QStringLiteral("chooseProjectNamePage"));
        verticalLayout_2 = new QVBoxLayout(chooseProjectNamePage);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(chooseProjectNamePage);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setScaledContents(false);

        verticalLayout_2->addWidget(label);

        line_2 = new QFrame(chooseProjectNamePage);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_3 = new QLineEdit(chooseProjectNamePage);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        label_23 = new QLabel(chooseProjectNamePage);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout->addWidget(label_23, 2, 0, 1, 1);

        label_24 = new QLabel(chooseProjectNamePage);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout->addWidget(label_24, 4, 0, 1, 1);

        lineEdit_4 = new QLineEdit(chooseProjectNamePage);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 4, 1, 1, 1);

        label_25 = new QLabel(chooseProjectNamePage);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout->addWidget(label_25, 10, 0, 1, 1);

        lineEdit_5 = new QLineEdit(chooseProjectNamePage);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 10, 1, 1, 1);

        toolButton = new QToolButton(chooseProjectNamePage);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        gridLayout->addWidget(toolButton, 4, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 10, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        Wizard->addPage(chooseProjectNamePage);
        newPerceptronPage = new QWizardPage();
        newPerceptronPage->setObjectName(QStringLiteral("newPerceptronPage"));
        horizontalLayout_7 = new QHBoxLayout(newPerceptronPage);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        frame = new QFrame(newPerceptronPage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout_4 = new QFormLayout(frame);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_14 = new QLabel(frame);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_14);

        spinBox_2 = new QSpinBox(frame);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(10000);
        spinBox_2->setValue(2);

        formLayout_4->setWidget(3, QFormLayout::FieldRole, spinBox_2);

        label_15 = new QLabel(frame);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout_4->setWidget(4, QFormLayout::LabelRole, label_15);

        comboBox_4 = new QComboBox(frame);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        formLayout_4->setWidget(4, QFormLayout::FieldRole, comboBox_4);

        label_16 = new QLabel(frame);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout_4->setWidget(5, QFormLayout::LabelRole, label_16);

        comboBox_5 = new QComboBox(frame);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));

        formLayout_4->setWidget(5, QFormLayout::FieldRole, comboBox_5);

        label_17 = new QLabel(frame);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout_4->setWidget(6, QFormLayout::LabelRole, label_17);

        comboBox_6 = new QComboBox(frame);
        comboBox_6->setObjectName(QStringLiteral("comboBox_6"));

        formLayout_4->setWidget(6, QFormLayout::FieldRole, comboBox_6);

        line_5 = new QFrame(frame);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        formLayout_4->setWidget(8, QFormLayout::SpanningRole, line_5);

        conjuntoDeEntranamientoLabel_2 = new QLabel(frame);
        conjuntoDeEntranamientoLabel_2->setObjectName(QStringLiteral("conjuntoDeEntranamientoLabel_2"));

        formLayout_4->setWidget(9, QFormLayout::LabelRole, conjuntoDeEntranamientoLabel_2);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        formLayout_4->setWidget(9, QFormLayout::FieldRole, pushButton_2);

        label_18 = new QLabel(frame);
        label_18->setObjectName(QStringLiteral("label_18"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_18);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, lineEdit);


        horizontalLayout_7->addWidget(frame);

        line_6 = new QFrame(newPerceptronPage);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_7->addWidget(line_6);

        Wizard->addPage(newPerceptronPage);
        newAdalinePage = new QWizardPage();
        newAdalinePage->setObjectName(QStringLiteral("newAdalinePage"));
        horizontalLayout_8 = new QHBoxLayout(newAdalinePage);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        frame_2 = new QFrame(newAdalinePage);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        formLayout_5 = new QFormLayout(frame_2);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        formLayout_5->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_19 = new QLabel(frame_2);
        label_19->setObjectName(QStringLiteral("label_19"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_19);

        lineEdit_2 = new QLineEdit(frame_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_20 = new QLabel(frame_2);
        label_20->setObjectName(QStringLiteral("label_20"));

        formLayout_5->setWidget(3, QFormLayout::LabelRole, label_20);

        spinBox_3 = new QSpinBox(frame_2);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMinimum(1);
        spinBox_3->setMaximum(10000);
        spinBox_3->setValue(2);

        formLayout_5->setWidget(3, QFormLayout::FieldRole, spinBox_3);

        label_21 = new QLabel(frame_2);
        label_21->setObjectName(QStringLiteral("label_21"));

        formLayout_5->setWidget(4, QFormLayout::LabelRole, label_21);

        comboBox_7 = new QComboBox(frame_2);
        comboBox_7->setObjectName(QStringLiteral("comboBox_7"));

        formLayout_5->setWidget(4, QFormLayout::FieldRole, comboBox_7);

        label_22 = new QLabel(frame_2);
        label_22->setObjectName(QStringLiteral("label_22"));

        formLayout_5->setWidget(5, QFormLayout::LabelRole, label_22);

        comboBox_8 = new QComboBox(frame_2);
        comboBox_8->setObjectName(QStringLiteral("comboBox_8"));

        formLayout_5->setWidget(5, QFormLayout::FieldRole, comboBox_8);

        line_7 = new QFrame(frame_2);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        formLayout_5->setWidget(7, QFormLayout::SpanningRole, line_7);

        conjuntoDeEntranamientoLabel_3 = new QLabel(frame_2);
        conjuntoDeEntranamientoLabel_3->setObjectName(QStringLiteral("conjuntoDeEntranamientoLabel_3"));

        formLayout_5->setWidget(8, QFormLayout::LabelRole, conjuntoDeEntranamientoLabel_3);

        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        formLayout_5->setWidget(8, QFormLayout::FieldRole, pushButton_3);


        horizontalLayout_8->addWidget(frame_2);

        line_8 = new QFrame(newAdalinePage);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        horizontalLayout_8->addWidget(line_8);

        Wizard->addPage(newAdalinePage);

        retranslateUi(Wizard);

        QMetaObject::connectSlotsByName(Wizard);
    } // setupUi

    void retranslateUi(QWizard *Wizard)
    {
        Wizard->setWindowTitle(QApplication::translate("Wizard", "Wizard", 0));
        label_3->setText(QApplication::translate("Wizard", "Seleccione un proyecto:", 0));

        const bool __sortingEnabled = treeProjects->isSortingEnabled();
        treeProjects->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem = treeProjects->topLevelItem(0);
        ___qtreewidgetitem->setText(0, QApplication::translate("Wizard", "Redes neuronales artificiales", 0));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem->setToolTip(0, QApplication::translate("Wizard", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Crea un proyecto con redes neuronales para emular el proceso de aprendizaje humano, las redes neuronales son un paradigma de la Inteligencia Artificial y permite agregar &quot;inteligencia&quot; a un sistema, puede crear su proyecto de redes neuronales y a\303\261adirlos a otros proyectos si lo desea. Asimismo puede crear sus propios modelos de redes neuronales para llevar a cabo pruebas y generar conclusiones.</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem1 = ___qtreewidgetitem->child(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("Wizard", "Perceptron Simple", "simple-perceptron"));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem1->setToolTip(0, QApplication::translate("Wizard", "Crea un proyecto con uno o mas perceptr\303\263nes simples como elementos principales. El perceptr\303\263n es la unidad mas elemental, con el muchas redes neuronales trabajan ya que su modelo es muy aproximado al de una neurona real.", 0));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem->child(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("Wizard", "ADALINE", "adaline"));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem2->setToolTip(0, QApplication::translate("Wizard", "Crea un proyecto con uno o mas ADALINEs como elementos principales. Un ADALINE es un tipo especial de perceptr\303\263n que funciona de forma adaptativa y tiene una regla de entrenamiento totalmente distinta, idealmente utilizado para evitar la dependencia lineal.", 0));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem->child(2);
        ___qtreewidgetitem3->setText(0, QApplication::translate("Wizard", "Perceptr\303\263n multicapa", "multilayer-perceptron"));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem3->setToolTip(0, QApplication::translate("Wizard", "Crea un proyecto con una o mas redes del tipo Perceptron Multicapa que consiste en una serie de capas de perceptrones que se organizan en capa de entrada, capa(s) oculta(s) y capa de salida. El n\303\272mero de capas y el n\303\272mero de perceptrones por capa puede ser modificado dependiendo las necesidades.", 0));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem->child(3);
        ___qtreewidgetitem4->setText(0, QApplication::translate("Wizard", "Hopfield", "hopfield"));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem4->setToolTip(0, QApplication::translate("Wizard", "Crea un proyecto con una o mas Redes de Hopfield que basicamente son redes de perceptrones auto-asociados y que estan conectados bidireccionalmente unos con otros, esta cualidad junto con su algoritmo de entrenamiento permite que esta red se auto-organice y aprenda diferentes patrones.", 0));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem5 = treeProjects->topLevelItem(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("Wizard", "Sistemas multiagentes", 0));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem5->setToolTip(0, QApplication::translate("Wizard", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Crea un proyecto que le permite insertar cualquier cantidad de agentes personalizables y con caracteristicas que pueden ser a\303\261adidas, como actuadores, sensores, motores de inferencia, redes neuronales entre otras. Los sistemas multiagentes pueden ser dinamicos y llevar a cabo simulaciones de movimiento, ideales para emular el comportamiento de seres vivios, insectos sociales, entre otros. </span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(0, QApplication::translate("Wizard", "Sistema b\303\241sico", "multiagent-basic-system"));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem6->setToolTip(0, QApplication::translate("Wizard", "Crea un proyecto de un sistema multi-agente b\303\241sico, puede contener multiples agentes interactuando entre s\303\255 dependiendo de las reglas o motor de respuestas, los actuadores y sensores que tengan.", 0));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem5->child(1);
        ___qtreewidgetitem7->setText(0, QApplication::translate("Wizard", "Sistemas de insectos sociales", "sociable-insects"));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem7->setToolTip(0, QApplication::translate("Wizard", "Crea un proyecto especial multiagente donde cada agente tiene propiedades de insectos sociales b\303\241sicos, como abejas, horm\303\255gas, entre otros. El tipo de insectos se puede cambiar dependiendo de la necesidad.", 0));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem8 = treeProjects->topLevelItem(2);
        ___qtreewidgetitem8->setText(0, QApplication::translate("Wizard", "L\303\263gica difusa", 0));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem8->setToolTip(0, QApplication::translate("Wizard", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Crea un proyecto de logica difusa que le permite trabajar con sistemas que tienen variables con algun grado de pertenencia o borrosidad, es decir, datos que son imprecisos y que pueden venir del lenguaje natural humano. Este proyecto tambien puede ser incluido dentro de otros proyectos para generar sistemas mas complejos aun.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem8->child(0);
        ___qtreewidgetitem9->setText(0, QApplication::translate("Wizard", "Sistema b\303\241sico", "fuzzy-logic-basic-system"));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem9->setToolTip(0, QApplication::translate("Wizard", "Crea un proyecto de l\303\263gica difusa b\303\241sico, se pueden configurar las reglas, hipotesis (condiciones), conclusiones y las funciones de membres\303\255a que corresponden a cada variable.", 0));
#endif // QT_NO_TOOLTIP
        treeProjects->setSortingEnabled(__sortingEnabled);

        label->setText(QApplication::translate("Wizard", "Nombre y ubicaci\303\263n", 0));
        label_23->setText(QApplication::translate("Wizard", "Nombre", 0));
        label_24->setText(QApplication::translate("Wizard", "Carpeta", 0));
        label_25->setText(QApplication::translate("Wizard", "Ruta final", 0));
        toolButton->setText(QApplication::translate("Wizard", "Explorar...", 0));
        label_14->setText(QApplication::translate("Wizard", "Numero de entradas", 0));
        label_15->setText(QApplication::translate("Wizard", "Tipo de salida", 0));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("Wizard", "Unipolar", 0)
         << QApplication::translate("Wizard", "Bipolar", 0)
        );
        label_16->setText(QApplication::translate("Wizard", "Funci\303\263n de activaci\303\263n", 0));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("Wizard", "Escalon unipolar", 0)
         << QApplication::translate("Wizard", "Escalon bipolar", 0)
         << QApplication::translate("Wizard", "Sigmoide", 0)
         << QApplication::translate("Wizard", "Tangente hiperbolica", 0)
         << QApplication::translate("Wizard", "Lineal limitada unipolar", 0)
         << QApplication::translate("Wizard", "Lineal limitada bipolar", 0)
        );
        label_17->setText(QApplication::translate("Wizard", "Regla de aprendizaje", 0));
        comboBox_6->clear();
        comboBox_6->insertItems(0, QStringList()
         << QApplication::translate("Wizard", "Regla simple", 0)
         << QApplication::translate("Wizard", "Regla delta", 0)
        );
        conjuntoDeEntranamientoLabel_2->setText(QApplication::translate("Wizard", "Conjunto de entranamiento", 0));
        pushButton_2->setText(QApplication::translate("Wizard", "Asignar", 0));
        label_18->setText(QApplication::translate("Wizard", "Nombre", 0));
        lineEdit->setText(QApplication::translate("Wizard", "perceptron", 0));
        lineEdit->setPlaceholderText(QString());
        label_19->setText(QApplication::translate("Wizard", "Nombre", 0));
        lineEdit_2->setText(QApplication::translate("Wizard", "adaline", 0));
        lineEdit_2->setPlaceholderText(QString());
        label_20->setText(QApplication::translate("Wizard", "Numero de entradas", 0));
        label_21->setText(QApplication::translate("Wizard", "Funci\303\263n de transferencia", 0));
        comboBox_7->clear();
        comboBox_7->insertItems(0, QStringList()
         << QApplication::translate("Wizard", "Lineal", 0)
         << QApplication::translate("Wizard", "Sigmoide", 0)
         << QApplication::translate("Wizard", "Tangente hiperbolica", 0)
         << QApplication::translate("Wizard", "Lineal limitada unipolar", 0)
         << QApplication::translate("Wizard", "Lineal limitada bipolar", 0)
        );
        label_22->setText(QApplication::translate("Wizard", "Actualizaci\303\263n de pesos", 0));
        comboBox_8->clear();
        comboBox_8->insertItems(0, QStringList()
         << QApplication::translate("Wizard", "Sincrona", 0)
         << QApplication::translate("Wizard", "Asincrona", 0)
        );
        conjuntoDeEntranamientoLabel_3->setText(QApplication::translate("Wizard", "Conjunto de entranamiento", 0));
        pushButton_3->setText(QApplication::translate("Wizard", "Asignar", 0));
    } // retranslateUi

};

namespace Ui {
    class Wizard: public Ui_Wizard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECTDIALOG_H
