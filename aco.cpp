#include "aco.h"
#include "ui_aco.h"

ACO::ACO(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ACO)
{
    ui->setupUi(this);
}

ACO::~ACO()
{
    delete ui;
}

void ACO::mousePressEvent(QMouseEvent *event)
{
    //Define el tamaño del vertice
    QRectF vertex(-5, -5, 10, 10);

    ui->graph->scene()->addEllipse(vertex);
}
