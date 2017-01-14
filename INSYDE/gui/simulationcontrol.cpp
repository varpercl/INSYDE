#include "simulationcontrol.h"

gui::SimulationControl::SimulationControl(QWidget *parent) : QFrame(parent)
{
    iniciarStatusAnimation();
}

void gui::SimulationControl::iniciarStatusAnimation()
{
    status = Stopped;
    normalPlayIcon = QIcon(":/imagenes/png/Play Normal.png");
    disabledPlayIcon = QIcon(":/imagenes/png/Play Disabled.png");

    normalPauseIcon = QIcon(":/imagenes/png/Pause Normal.png");
    disabledPauseIcon = QIcon(":/imagenes/png/Pause Disabled.png");

    normalStopIcon = QIcon(":/imagenes/png/Stop Normal Red.png");
    disabledStopIcon = QIcon(":/imagenes/png/Stop Disabled.png");

    playPauseButton = new QPushButton();
    playPauseButton->setIcon(normalPlayIcon);

    stopButton = new QPushButton();
    stopButton->setIcon(disabledStopIcon);

    design = new QHBoxLayout(this);
    design->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    design->addWidget(playPauseButton);
    design->addWidget(stopButton);

    connect(playPauseButton, SIGNAL(clicked()), this, SLOT(playPauseClick()));
    connect(stopButton,SIGNAL(clicked()), this, SLOT(stopClick()));
}

void gui::SimulationControl::playPauseClick()
{
    Status past = status;
    switch(status){
        case Stopped:
        case Paused:
            playPauseButton->setIcon(normalPauseIcon);
            status = Running;
            emit run();
            break;
        case Running:
            playPauseButton->setIcon(normalPlayIcon);
            status = Paused;
            emit pause();
            break;
    }
    emit statusChanged(status, past);
    stopButton->setIcon(normalStopIcon);
}

void gui::SimulationControl::stopClick()
{
    Status past = status;
    status = Stopped;
    emit stop();
    emit statusChanged(status, past);
    stopButton->setIcon(disabledStopIcon);
    playPauseButton->setIcon(normalPlayIcon);
}

gui::Status gui::SimulationControl::getCurrentStatus()
{
    return status;
}

