/********************************************************************************
** Form generated from reading UI file 'selectprojectpage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTPROJECTPAGE_H
#define UI_SELECTPROJECTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectProjectPage
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *principalLayout;
    QTreeWidget *treeProjects;
    QLabel *lblDescription;

    void setupUi(QWidget *SelectProjectPage)
    {
        if (SelectProjectPage->objectName().isEmpty())
            SelectProjectPage->setObjectName(QStringLiteral("SelectProjectPage"));
        SelectProjectPage->resize(551, 429);
        verticalLayout = new QVBoxLayout(SelectProjectPage);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        principalLayout = new QVBoxLayout();
        principalLayout->setObjectName(QStringLiteral("principalLayout"));
        treeProjects = new QTreeWidget(SelectProjectPage);
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
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeProjects->sizePolicy().hasHeightForWidth());
        treeProjects->setSizePolicy(sizePolicy);
        treeProjects->setMinimumSize(QSize(200, 0));
        treeProjects->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeProjects->setProperty("showDropIndicator", QVariant(true));
        treeProjects->setIconSize(QSize(20, 20));
        treeProjects->setRootIsDecorated(true);
        treeProjects->setAnimated(true);
        treeProjects->header()->setVisible(false);

        principalLayout->addWidget(treeProjects);

        lblDescription = new QLabel(SelectProjectPage);
        lblDescription->setObjectName(QStringLiteral("lblDescription"));
        lblDescription->setMinimumSize(QSize(0, 120));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        lblDescription->setPalette(palette);
        lblDescription->setAutoFillBackground(true);
        lblDescription->setFrameShape(QFrame::StyledPanel);
        lblDescription->setFrameShadow(QFrame::Raised);
        lblDescription->setLineWidth(1);
        lblDescription->setWordWrap(true);
        lblDescription->setMargin(0);

        principalLayout->addWidget(lblDescription);


        verticalLayout->addLayout(principalLayout);


        retranslateUi(SelectProjectPage);
        QObject::connect(treeProjects, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)), SelectProjectPage, SLOT(currentItemProjectChanged(QTreeWidgetItem*,QTreeWidgetItem*)));

        QMetaObject::connectSlotsByName(SelectProjectPage);
    } // setupUi

    void retranslateUi(QWidget *SelectProjectPage)
    {
        SelectProjectPage->setWindowTitle(QApplication::translate("SelectProjectPage", "Form", 0));

        const bool __sortingEnabled = treeProjects->isSortingEnabled();
        treeProjects->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem = treeProjects->topLevelItem(0);
        ___qtreewidgetitem->setText(0, QApplication::translate("SelectProjectPage", "Redes neuronales artificiales", 0));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem->setToolTip(0, QApplication::translate("SelectProjectPage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Crea un proyecto con redes neuronales para emular el proceso de aprendizaje humano, las redes neuronales son un paradigma de la Inteligencia Artificial y permite agregar &quot;inteligencia&quot; a un sistema, puede crear su proyecto de redes neuronales y a\303\261adirlos a otros proyectos si lo desea. Asimismo puede crear sus propios modelos de redes neuronales para llevar a cabo pruebas y generar conclusiones.</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem1 = ___qtreewidgetitem->child(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("SelectProjectPage", "Perceptron simple", "simple-perceptron"));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem1->setToolTip(0, QApplication::translate("SelectProjectPage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Crea un proyecto con uno o mas perceptr\303\263nes simples como elementos principales. El perceptr\303\263n es la unidad mas elemental, con el muchas redes neuronales trabajan ya que su modelo es muy aproximado al de una neurona real.</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem->child(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("SelectProjectPage", "ADALINE", "adaline"));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem2->setToolTip(0, QApplication::translate("SelectProjectPage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Crea un proyecto con uno o mas ADALINEs como elementos principales. Un ADALINE es un tipo especial de perceptr\303\263n que funciona de forma adaptativa y tiene una regla de entrenamiento totalmente distinta, idealmente utilizado para evitar la dependencia lineal.</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem->child(2);
        ___qtreewidgetitem3->setText(0, QApplication::translate("SelectProjectPage", "Perceptr\303\263n multicapa", "multilayer-perceptron"));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem3->setToolTip(0, QApplication::translate("SelectProjectPage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Crea un proyecto con una o mas redes del tipo Perceptron Multicapa que consiste en una serie de capas de perceptrones que se organizan en capa de entrada, capa(s) oculta(s) y capa de salida. El n\303\272mero de capas y el n\303\272mero de perceptrones por capa puede ser modificado dependiendo las necesidades.</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem->child(3);
        ___qtreewidgetitem4->setText(0, QApplication::translate("SelectProjectPage", "Hopfield", "hopfield"));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem4->setToolTip(0, QApplication::translate("SelectProjectPage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Crea un proyecto con una o mas Redes de Hopfield que basicamente son redes de perceptrones auto-asociados y que estan conectados bidireccionalmente unos con otros, esta cualidad junto con su algoritmo de entrenamiento permite que esta red se auto-organice y aprenda diferentes patrones.</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem5 = treeProjects->topLevelItem(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("SelectProjectPage", "Sistemas multiagentes", 0));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem5->setToolTip(0, QApplication::translate("SelectProjectPage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Crea un proyecto que le permite insertar cualquier cantidad de agentes personalizables y con caracteristicas que pueden ser a\303\261adidas, como actuadores, sensores, motores de inferencia, redes neuronales entre otras. Los sistemas multiagentes pueden ser dinamicos y llevar a cabo simulaciones de movimiento, ideales para emular el comportamiento de seres vivios, insectos sociales, entre otros. </span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(0, QApplication::translate("SelectProjectPage", "Sistema b\303\241sico", "multiagent-basic-system"));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem6->setToolTip(0, QApplication::translate("SelectProjectPage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Crea un proyecto de un sistema multi-agente b\303\241sico, puede contener multiples agentes interactuando entre s\303\255 dependiendo de las reglas o motor de respuestas, los actuadores y sensores que tengan.</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem5->child(1);
        ___qtreewidgetitem7->setText(0, QApplication::translate("SelectProjectPage", "Sistemas de insectos sociales", "sociable-insects"));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem7->setToolTip(0, QApplication::translate("SelectProjectPage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Crea un proyecto especial multiagente donde cada agente tiene propiedades de insectos sociales b\303\241sicos, como abejas, horm\303\255gas, entre otros. El tipo de insectos se puede cambiar dependiendo de la necesidad.</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem8 = treeProjects->topLevelItem(2);
        ___qtreewidgetitem8->setText(0, QApplication::translate("SelectProjectPage", "L\303\263gica difusa", 0));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem8->setToolTip(0, QApplication::translate("SelectProjectPage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Crea un proyecto de logica difusa que le permite trabajar con sistemas que tienen variables con algun grado de pertenencia o borrosidad, es decir, datos que son imprecisos y que pueden venir del lenguaje natural humano. Este proyecto tambien puede ser incluido dentro de otros proyectos para generar sistemas mas complejos aun.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem8->child(0);
        ___qtreewidgetitem9->setText(0, QApplication::translate("SelectProjectPage", "Sistema b\303\241sico", "fuzzy-logic-basic-system"));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem9->setToolTip(0, QApplication::translate("SelectProjectPage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Crea un proyecto de l\303\263gica difusa b\303\241sico, se pueden configurar las reglas, hipotesis (condiciones), conclusiones y las funciones de membres\303\255a que corresponden a cada variable.</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        treeProjects->setSortingEnabled(__sortingEnabled);

        lblDescription->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SelectProjectPage: public Ui_SelectProjectPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTPROJECTPAGE_H
