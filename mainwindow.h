#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

#ifndef QT_NO_OPENGL
#include <QGLWidget>
#endif

#include <InSyDeGui.h>
#include <math.h>

namespace Ui {
    class MainWindow;
}

enum Render{
    OpenGL,
    Nativo
};

/**
  @class MainWindow
  @author Edixon Vargas
  @date 08-06-2012

  La clase @code{MainWindow} corresponde a la ventana principal del programa, alli se pueden realizar las simulaciones
  de los agentes y demas operaciones.
  */

class MainWindow : public QMainWindow
{
        Q_OBJECT

        //Dialogo para algoritmos ACO
        ACO *acoDialog;

        //Ventana para crear un nuevo proyecto
//        AssistantDialog *npd;

        //Asistente para la creacion de un nuevo proyecto
        NewProjectWizard *newProjectDialog;

        //Timer que permite la actualizacion de la barra de estado
        QTimer updateStatusTimer;

        //Cuadro de dialogo para agregar mas agentes
        AddAgentsDialog *dlgAddAgents;

        //Control del estado de la animacion
        StatusAnimationControl *sta;

        //Visor actual de la simulacion
        Visor *visor;

        //Estado actual de renderizacion
        Render actualRender;

        //Sub-Arbol de exploracion de agentes
        QTreeWidgetItem *trAgentes;

        //Arbol de exploracion de proyecto
        QTreeWidgetItem *trProyecto;

        //Widget para el puerto del visor
        QWidget *viewPortWidget;

        //Widget opengl para el puerto del visor
        QGLWidget *glWidget;

        /**
          Inicializa los componentes de la interfaz grafica de usuario
          */
        void initGUI();

        /**
          Conecta todos los eventos correspondientes a los controles de la interfaz
          */
        void conectarEventos();

        /**
          Actualiza los items hijos de un arbol padre

          @param *parent Arbol padre al cual se le actualizaran los sub-items

          */
        void updateChildItems(QTreeWidgetItem *parent);

    public:
        Ui::MainWindow *ui;

        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();


    protected:
//        void closeEvent (QCloseEvent *event);

    protected slots:

        /**
          Esta funcion es llamada cuando se agregan agentes al entorno, se encarga de generar los nuevos agentes
          y asignarle las propiedades que el usuario especifique.
          */
        void addAgents();

        /**
          Comienza la simulacion de un proyecto si esta detenida o pausada.
          */
        void runAnimation();

        /**
          Pausa una animacion en caso de que se encuentre actualmente corriendo.
          */
        void pauseAnimation();

        /**
          Detiene una animacion que esta corriendo actualmente.
          */
        void stopAnimation();

        /**
          Este metodo se llama cuando se ha hecho click en el elemento "Salir" del menu Archivo
          */
        void menuSalirClick();

        /**
          Este metodo se llama cuando se cambia del modo grafico OpenGL al modo grafico Nativo del
          Sistema Operativo
          */
        void menuNativoClick();

        /**
          Este metodo activa el modo OpenGL para una mejor renderizacion y procesamiento de los graficos
          */
        void menuOpenGLClick();

        /**
          Se ejecuta cuando se hace click con el secundario sobre el visor de la animacion

          @param p Punto donde se hizo click
          */
        void menuContextualListaObjetos(QPoint p);

        /**
          Este metodo es llamado cuando se hace click en el boton Agregar agentes
          */
        void btnAgregarAgenteClick();

        /**
          Se llama cuando se hace click en el boton Borrar agentes
          */
        void btnBorrarAgenteClick();

        /**
          Cada vez que se llama imprime sobre la barra de estado la cantidad de agentes que se encuentran seleccionados
          */
        void mostrarAgentesSeleccionados();

        /**
          Se llama cada vez que se quiere refrescar la barra de estado de la ventana.
          */
        void updateWindowStatus();

//        void edicionItemAgente(QTreeWidgetItem *current, QTreeWidgetItem *past);
    private slots:

        /**
          Evento llamado cuando se hace click sobre el visor

          QMouseEvent *event Informacion sobre el evento del mouse
          */
        void onVisorClicked(QMouseEvent *event);

        /**
          Se ejecuta cada vez que se hace click sobre el boton
          */
        void on_btnSearchMode_clicked();

        /**
          Este evento se dispara cada vez que se quiere crear un nuevo proyecto.
          */
        void onNewProyectTriggered(bool val);
        void on_pushButton_2_clicked();
        void on_mainToolBox_currentChanged(int index);
};

#endif // MAINWINDOW_H
