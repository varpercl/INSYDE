#ifndef NEWPROJECTWIZARD_H
#define NEWPROJECTWIZARD_H

#include <InSyDeGui.h>

namespace Ui{
    class NewProjectWizard;
}

class NewProjectWizard : public QWizard
{
        Q_OBJECT

    public:
        /**
          Crea un nuevo asistente para la creacion de proyectos de distintos tipos

          @param QWidget *parent Indica el widget que contendra este asistente, por lo general es la ventana principal quien sera el padre.
          */
        explicit NewProjectWizard(QWidget *parent = 0);

    signals:

    public slots:

};

#endif // NEWPROJECTWIZARD_H
