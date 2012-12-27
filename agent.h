#ifndef AGENT_H
#define AGENT_H

#include <QtCore>
#include <QtGui>

#include <vector2d.h>
#include <math.h>
#include <sensordistancia.h>
#include <actuador.h>
#include <regla.h>

class Sensor;
class Actuator;

/**
  @class Agent
  @author Edixon Vargas
  @date 05-05-2012

  La clase @code{Agent} es la base de todos los objetos que se pueden considerar un agente, contiene todos
  los atributos y metodos necesarios para el funcionamiento basico en un entorno virtual.

  */

class Agent : public QGraphicsObject
{
    private:
        Q_OBJECT

        //Lista de reglas que rigen el comportamiento del agente
        QMap<QString, Rule*> reglas;

        //Lista de los sensores que posee el agente actualmente
        QMap<QString, Sensor*> sensores;

        //Lista de los actuadores que posee el agente actualmente
        QMap<QString, Actuator*> actuadores;

        //Color del agente actualmente (para propositos graficos y de identificacion visual)
        QColor color;

        //Forma actual del agente (para propositos graficos)
        QPainterPath forma;

        //Ancho del borde del agente (para propositos graficos unicamente)
        int borderWidth;

        //Indica si se quiere que la forma de los actuadores sea visible
        bool actuatorsShapeVisible;

        /*
         Indica si quiere que se visualice una figura para representar graficamente el agente.
         inicialmente esta figura es representada por un circulo con una linea que indica
         la direccion a la cual apunta el agente
        */
        bool figuraAbstractaVisible;

        //Cadena que permite contiene un identificador unico que distingue al agente de los demas
        QString identificador;

        //Describe el radio de la unidad abstracta en caso de no tener una figura personalizada
        double radioAgente;

        /**
          Inicializa una instancia de objeto de esta clase, asigna los valores iniciales a todas las variables miembro
          mediante el pase de parametros a esta funcion, hace que sea simple el trabajo ya que cuando se llama un constructor
          solo llamamos a esta funcion pasandole los parametros que queremos asignarle inicialmente
          */
        void iniciarTodo(double radio);

    public:

        /**
          Crea una instancia de clase con radio, angulo y velocidad iniciales preestablecidas
          */
        explicit Agent();

        /**
          Crea una instancia de clase con un radio pasado como parametro

          @param int radio - Describe el radio de esta unidad.
          */
        explicit Agent(double radio);

        /**
          Crea una instancia de clase con un radio y angulo pasado como parametro

          @param int radio - Describe el radio de esta unidad.
          @param qreal angulo - Describe el angulo expresado en grados al que apunta esta unidad.
          */
        explicit Agent(double radio, double angulo);

        /**
          Crea una instancia de clase con un radio, angulo y velocidad pasado como parametro

          @param int radio - Describe el radio de esta unidad.
          @param qreal angulo - Describe el angulo expresado en grados al que apunta esta unidad.
          @param qreal angulo - Describe la velocidad expresada en pix/sec a la que se desplaza esta unidad.
          */
        explicit Agent(double radio, double angulo, double vel);

        /**
          Establece el radio para este agente basico, este metodo se utiliza para efectos graficos a la hora
          de ser necesario que este se dibuje en un entorno grafico.

          @note Este metodo esta en evaluacion y es posible que desaparezca para efectos de mejoras en la
          implementacion.

          @arg rad Indica que radio se le asignara a este agente

          @see getRadius
          */
        void setRadius(double rad);

        /**
          Devuelve el radio actual del agente

          @return double Devuelve el valor del radio actual
          */

        inline double getRadius(){return radioAgente;}

        /**
          Establece si se quiere que se visualice una figura abstracta, en este caso un circulo que
          representara visualmente el agente en el entorno
          */
        void setAbstractFigureVisible(bool vis);

        /**
          Devuelve el estado de la visibilidad de la figura abstracta

          @return bool Devuelve true si es visible
          */
        bool getAbstractFigureVisible();

        /**
          Establese si las formas de los actuadores seran visibles. A pesar de que cada actuador tiene
          su propia configuracion, con esta funcion se puede des/habilitar la visibilidad de los actuadores

          @param vis Establece la visibilidad
          */
        void setActuatorsShapeVisible(bool vis);

        /**
          Retorna la visibilidad de las figuras de los actuadores

          @return bool Visibilidad actual de los actuadores
          */
        bool getActuatorsShapeVisible();

        /**
          Agrega un sensor a la lista de sensores que actualmente posee el agente

          @param nombre Nombre clave que se le asignara al sensor, no debe estar repetido
          @param *sensor Puntero al sensor que se va a agregar
          */
        void addSensor(QString nombre, Sensor *sensor);

        /**
          Elimina un sensor basandose en su nombre clave

          @param nombre Nombre clave del sensor que se va a eliminar

          @see agregarSensor
          */
        void deleteSensor(QString nombre);

        /**
          Devuelve un puntero al sensor que tenga por nombre clave @code{nombre}

          @return Sensor* Puntero al sensor que se va a obtener

          @see addSensor
          */
        Sensor *getSensor(QString nombre);

        /**
          Establece la lista actual de sensores que va a tener el agente

          @param sensore Lista del tipo @code{QMap} que contiene un set de sensores con sus respectivos nombres clave

          @see addSensor
          */
        void setSensors(QMap<QString, Sensor*> sensores);

        /**
          Devuelve la lista de sensores que posee el agente actualmente

          @return QMap<QString, Sensor*> Mapa con los nombres clave y los apuntadores de los sensores

          @see setSensors
          */
        QMap<QString, Sensor *> &getSensors();

        /**
          Agrega un actuador a la lista de actuadores de este agente. Cada actuador debe tener un nombre clave

          @param nombre Nombre clave del actuador
          @param *actuador Puntero al actuador que se va a agregar

          @see setActuators
          */
        void addActuator(QString nombre, Actuator *actuador);

        /**
          Elimina un actuador basado en el nombre clave del mismo.

          @param nombre Nombre clave del actuador

          @see addActuator
          */
        void deleteActuator(QString nombre);

        /**
          Devuelve un puntero a un actuador dado su nombre clave

          @param nombre Nombre clave del actuador

          @see addActuator
          */
        Actuator *getActuator(QString nombre);

        /**
          Asigna una lista de actuadores a este agente, cada actuador debe tener un nombre clave que lo identifique
          y dicho nombre no debe estar repetido.

          @param actuadores Mapa de actuadores con un par nombre-puntero

          @see getActuator
          */
        void setActuators(QMap<QString, Actuator*> actuadores);

        /**
          Devuelve una lista de actuadores actualmente asignado al agente

          @return QMap<QString, Actuador*> Mapa con todos los actuadores

          @see setActuators
          */
        QMap<QString, Actuator*> &getActuators();

        /**
          Establece la forma actual de este agente, algunos agentes pueden tener una forma establecida
          que permite que se visualicen en un entorno grafico.

          @param &fig Forma que se le asignara a este actuador

          @see getShape
          */
        void setShape(const QPainterPath &fig);

        /**
          Establece el nombre de este agente, si este agente se asigna a un entorno, el entorno validara
          si el nombre no se encuentra repetido

          @param nombre Nombre que se le asignara a este agente

          @see getName
          */
        void setName(QString nombre);

        /**
          Devuelve el nombre actual de este agente

          @return QString Cadena con el nombre de este agente
          */
        QString getName();

        /**
          Devuelve la forma grafica de este agente.

          @return QPainterPath Objeto que contiene la forma grafica de este agente
          */
        QPainterPath shape() const;

        /**
          Devuelve una forma radial de este agente. Una forma es una circunferencia
          que abarca toda el area de la forma real del agente, este metodo es util especialmente
          si se quiere hacer deteccion de colisiones.

          @return QPainterPath Objeto con la forma radial del objeto

          @see shape
          */
        virtual QPainterPath radialShape() const;

        /**
          Establece el tiempo de actualizacion de este agente, este tiempo determina el intervalo
          de chequeo de las reglas y otros elementos activos en el agente.

          @note Nota: esta funcion esta a prueba.

          @param udi Intervalo de actualizacion

          @see getUpdateInterval
          */
        void setUpdateInterval(int udi);

        /**
          Devuelve el tiempo de actualizacion de este agente

          @return int Tiempo de actualizacion
          */
        inline int getUpdateInterval();

        /**
          Establece el ancho de los bordes de este agente, este metodo es para propositos
          graficos

          @param w Ancho del borde
          */
        void setBorderWidth(int w);

        /**
          Devuelve el ancho del borde de este agente.

          @return int Ancho actual de los bordes de este agente
          */
        int getBorderWidth() const;

        /**
          Establece el color actual de este agente. El color actual se establece
          para tener una representacion visual en el entorno

          @param col Color que se le asignara al agente

          @see getColor
          */
        inline void setColor(QColor col){color = col;}

        /**
          Devuelve el color actual de este agente

          @return QColor Color actual del agente

          @see setColor
          */
        QColor getColor() const{return color;}

    protected:
        //Metodos propios

        /**
          Inicia de forma segura un timer a un intervalo @code{interval} y le asigna un ID @code{id}

          @param &id ID que se le asignara a este timer
          @param intervalo Intervalo de actualizacion de este timer

          @see secureKillTimer
          */
        virtual void secureStartTimer(int &id, int interval);

        /**
          Desactiva permanentemente un timer con un id @code{id}

          @param &id ID que se le asignara actualmente a este timer
          */
        virtual void secureKillTimer(int &id);

        //Metodos de la clase padre
//        void mousePressEvent(QGraphicsSceneMouseEvent *event);
//        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

        /**
          El metodo paint es heredado de la clase @code{QGraphicsItem}, vease la documentacion de dicha clase para
          mayor informacion
          */
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        /**
          El metodo @code{boundingRect()} es heredado de @code{QGraphicsItem}, vease la documentacion de dicha clase
          para mayor informacion
          */
        QRectF boundingRect() const;
//        void timerEvent(QTimerEvent *event);



    signals:

    public slots:
        void checkRules();
//        void timeout();
};

#endif // UNIDAD_H
