#include "selectprojectpage.h"
#include "ui_selectprojectpage.h"

SelectProjectPage::SelectProjectPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::SelectProjectPage)
{
    ui->setupUi(this);

    initWidget();
}

SelectProjectPage::~SelectProjectPage()
{
    delete ui;
}

int SelectProjectPage::nextId() const
{
//    switch(ui->treeProjects->rootIndex().row()){
//        case 0:     //Redes neuronales
//        case 1:     //Perceptron simple
//        case 2:     //Sistemas multiagentes
//        case 3:     //Logica difusa
//        default:
//            break;
//    }
    return ChooseProjectNameID;
}

void SelectProjectPage::currentItemProjectChanged(QTreeWidgetItem *current, QTreeWidgetItem *last)
{
    Q_UNUSED(last);

    ui->lblDescription->setText(current->toolTip(0));
    if(current != NULL){
        ui->lblDescription->setText(current->toolTip(0));
//        setTitle(current->text(0));
        if(current->text(0).toLower() == "perceptron simple"){
            setField("projectType", PerceptronPageID);
        }else if(current->text(0).toLower() == "adaline"){
            setField("projectType", AdalinePageID);
        }
    }
}

void SelectProjectPage::initWidget()
{
    registerField("projectType*", ui->treeProjects, 0, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)));
    setTitle("Seleccione el tipo de proyecto que desea realizar");
}

void SelectProjectPage::connectEvents()
{
    connect(ui->treeProjects, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)), SLOT(currentItemProjectChanged(QTreeWidgetItem*,QTreeWidgetItem*)));
}
