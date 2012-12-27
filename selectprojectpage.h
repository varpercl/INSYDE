#ifndef SELECTPROJECTPAGE_H
#define SELECTPROJECTPAGE_H

#include <InSyDeGui.h>

namespace Ui {
    class SelectProjectPage;
}

class SelectProjectPage : public QWizardPage
{
        Q_OBJECT

        /**
          Inicializa este formulario
          */
        void initWidget();

        /**
          Conecta los eventos necesarios de todos los controles
          */
        void connectEvents();

    public:
        explicit SelectProjectPage(QWidget *parent = 0);
        ~SelectProjectPage();

        int nextId() const;

    protected slots:

        /**
          Este slot es llamado una vez que se ha cambiado el iten seleccionado
          actualmente, entrega dos parametros correspondientes al item actual
          seleccionado y al item pasado, respectivamente.

          @param QTreeWidgetItem *current Puntero al item actualmente seleccionado
          @param QTreeWidgetItem *last Puntero al ultimo item seleccionado
          */
        void currentItemProjectChanged(QTreeWidgetItem *current, QTreeWidgetItem *last);

    private:
        Ui::SelectProjectPage *ui;
};

#endif // SELECTPROJECTPAGE_H
