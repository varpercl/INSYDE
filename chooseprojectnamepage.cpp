#include "chooseprojectnamepage.h"
#include "ui_chooseprojectnamepage.h"

ChooseProjectNamePage::ChooseProjectNamePage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::ChooseProjectNamePage)
{
    ui->setupUi(this);
}

ChooseProjectNamePage::~ChooseProjectNamePage()
{
    delete ui;
}

int ChooseProjectNamePage::nextId() const
{
    return field("projectType").toInt();
//    treeWidget->selectedItems();
//    switch(treeWidget){
//        case 0:
//            break;
//        case 1:
//            return PerceptronPageID;
//            break;
//        case 2:
//            break;
//        case 3:
//            break;
//        case 4:
//            break;
//        case 5:
//            break;
//    }

//    return PerceptronPageID;
}

//void ChooseProjectNamePage::show()
//{
//    QWizardPage::show();
//    QTreeWidget *treeWidget = (QTreeWidget*)(field("projectType").data());

//    this->setWindowTitle(/*QString::number*/(treeWidget->currentItem()->text(0)));
//}
