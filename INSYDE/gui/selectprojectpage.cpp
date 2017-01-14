#include "selectprojectpage.h"
#include "ui_selectprojectpage.h"

gui::SelectProjectPage::SelectProjectPage(QWidget *parent) :
	QWizardPage(parent),
	ui(new Ui::SelectProjectPage)
{
	initializePage();
}

gui::SelectProjectPage::~SelectProjectPage()
{
	delete ui;
}

int gui::SelectProjectPage::nextId() const
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
}//nextId

void gui::SelectProjectPage::setProjectType(int pt)
{
	proType = pt;
}

int gui::SelectProjectPage::projectType() const
{
	return proType;
}

void gui::SelectProjectPage::currentItemProjectChanged(QTreeWidgetItem *current, QTreeWidgetItem *last)
{
	Q_UNUSED(last);

	ui->lblDescription->setText(current->toolTip(0));
	if(current != NULL){
		ui->lblDescription->setText(current->toolTip(0));

		if(current->text(0).toLower() == "redes neuronales artificiales"){
			wizard()->button(QWizard::NextButton)->setEnabled(false);
		}else if(current->text(0).toLower() == "perceptron simple"){
			wizard()->button(QWizard::NextButton)->setEnabled(true);
			setField("projectType", PerceptronPageID);
		}else if(current->text(0).toLower() == "adaline"){
			wizard()->button(QWizard::NextButton)->setEnabled(true);
			setField("projectType", AdalinePageID);
		}else if(current->text(0).toLower() == "sistemas multiagentes"){
			wizard()->button(QWizard::NextButton)->setEnabled(false);
		}else if(current->text(0).toLower() == "lógica difusa"){
			wizard()->button(QWizard::NextButton)->setEnabled(false);
		}
	}
}//currentItemProjectChanged

void gui::SelectProjectPage::initializePage()
{
	ui->setupUi(this);

	registerField("projectType", this, "projectType");
	setTitle("Seleccione el tipo de proyecto que desea realizar");

	connectEvents();
}//initPage

void gui::SelectProjectPage::connectEvents()
{
	connect(ui->treeProjects, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)), SLOT(currentItemProjectChanged(QTreeWidgetItem*,QTreeWidgetItem*)));
}//connectEvents

void gui::SelectProjectPage::on_treeProjects_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
	if(item->text(column).toLower() == "perceptron simple"){

		wizard()->next();
	}
}//on_treeProjects_itemDoubleClicked
