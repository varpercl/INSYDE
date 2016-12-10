#ifndef PHEROMONEITEM_H
#define PHEROMONEITEM_H

#include <QtCore>
#include <QtWidgets>

//#if QT_VERSION > 0x050000
//#include <QtWidgets/QStyleOptionGraphicsItem>
//#include <QtWidgets/QGraphicsObject>
//#include <QtWidgets/QGraphicsScene>
//#else
//#include <QtGui>
//#endif


#include "share_ec_gui.h"

/**
  @class PheromoneItem
  @author Edixon Vargas
  @date 08-06-2012

  La clase @code{PheromoneItem} corresponde a los items de feromona que deja el actuador @code{PheromoneDepositor}.
  Los items de feromonas tienen propiedades que se le pueden modificar como el tiempo de evaporacion, la cantidad,
  el punto de saturacion entre otros.

  */
class EC_GUI_LIB_IMPORT_EXPORT PheromoneItem : public QGraphicsObject
{
		Q_OBJECT

		//Lista de las ultimas feromonas depositadas
		QList<PheromoneItem*> lastPheromones;

		//Indica la taza de evaporacion del item de feromona
		int evaporationRate;

		//Timer que controla la evaporacion de las feromonas
		QTimer tmrEvaporation;

		//Rectangulo que contiene el texto que describe los valores de las feromonas
		QRectF textRect;

		//Este es un rectangulo que contien las dimensiones de la circunferencia del item de feromona
		QRectF circunferencia;

		//Contiene la intensidad actual de este item de feromona
		int pheromoneValue;

		//Contiene el valor de saturacion de este item de feromona
		int saturationValue;

		//Contien el angulo al que apunta esta feromona actualmente (Esta variable esta a prueba)
		double angle;

		/**
		  Inicializa las variables miembro de la clase a sus valores predeterminados

		  @param cantidad Indica el valor inicial de la intensidad del item de feromona
		  @param angle Indica el angulo al cual apunta la feromona actual

		  */
		void iniciarItemPheromona(int cantidad, double angle);

		/**
		  Calcula las dimensiones del rectangulo que contiene el texto de descripcion. Esta funcion es
		  empleada a la hora de dibujar el item y sus propiedades

		  @param &str String al cual se le calculara las dimensiones del rectangulo
		  @param &font Fuente que tiene el string @code{str}
		  @param &referencia Es un rectangulo de referencia que se usa para calcular la posicion del rectangulo generado.
		  El rectangulo generado siempre sera colocado por encima y al centro del rectangulo de referencia
		  */
		QRectF calculateTextRect(const QString &str, const QFont &font, const QRectF &referencia);

	public:

		/**
		  Crea un nuevo item de feromona
		  */
		explicit PheromoneItem();

		/**
		  Crea un nuevo item de feromona con una intensidad especifica

		  @param cantidad Indica el valor de la intensidad actual de este item de feromona
		  */
		explicit PheromoneItem(int cantidad);

		/**
		  Construye un nuevo item de feromona con las propiedades especificas

		  @param cantidad Intensidad inicial de este item
		  @param angulo Angulo al cual apuntara la feromona

		  */
		explicit PheromoneItem(int cantidad, double angle);

		/**
		  Asigna la intensidad del item de feromona.

		  @param val Intensidad a ser asignada

		  @see getPheromoneValue
		  */
		void setPheromoneValue(int val);

		/**
		  Devuelve el valor actual de este item de feromona

		  @return int Valor actual de la feromona
		  */
		int getPheromoneValue();

		/**
		  Establece el valor actual de saturacion de este item de feromona

		  @param val Valor de saturacion actual

		  @see getSaturationValue
		  */
		void setSaturationValue(int val);

		/**
		  Obtiene el valor actual de saturacion de este item

		  @return int Valor actual de saturacion de este item de feromona
		  */
		int getSaturationValue();

		/**
		  Incrementa la intensidad de la feromona @code{val} veces

		  @param val Valor a incrementar
		  */
		void incrementPheromoneValue(int val);

		/**
		  Decrementa la intensidad del item de feromona @code{val} veces

		  @param val Valor a decrementar
		  */
		void decrementPheromoneValue(int val);

		/**
		  Establece el angulo al cual apunta este item de feromona

		  @param ang Angulo actual que se le asignara

		  @see getAngle
		  */
		void setAngle(double ang);

		/**
		  Obtiene el angulo actual de este item de feromona

		  @return double Angulo actual al que apunta el item
		  */
		double getAngle();

		/**
		  Establece la taza de evaporacion de este item de feromona

		  @param val Unidades evaporadas por segundo

		  @see getEvaporationRate
		  */
		void setEvaporationRate(int val);

		/**
		  Devuelve el valor de la taza de evaporacion actual

		  @return int Taza actual de evaporacion
		  */
		int getEvaporationRate();

		/**
		  Inserta una referencia al ultimo item de feromona depositado a la lista de los ultimos items de feromona

		  @param *pi Puntero al item que se quiere agregar

		  @see deleteLasPheromone
		  */
		void addLastPheromone(PheromoneItem *pi);

		/**
		  Elimina un item de feromona de la lista de ultimos items

		  @param *pi Puntero al item que se quiere eliminar de la lista

		  @see getLastPheromones, addLastPheromone
		  */
		void deleteLastPheromone(PheromoneItem *pi);

		/**
		  Devuelve una lista de los ultimos items de feromona que se han dejado, esto ira conformando una cadena
		  hasta el primer item que se deposito (si este existe).

		  @return QList<PheromoneItem*> Lista con todos los ultimos items depositados por el agente
		  */
		QList<PheromoneItem *> getLastPheromones();

		/**
		  Esta funcion es redundante y esta mal ubicada y se puede considerar su eliminacion o moverla.
		  */
		PheromoneItem *getMostIntenseNeighbour();


//        bool operator==(const PheromoneItem &pi1);

	protected:
		//Heredados de la clase padre
		void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
		QPainterPath shape() const;
		QRectF boundingRect() const;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	signals:

		/**
		  Esta señal se dispara una vez que se ha evaporado completamente un item de feromona

		  @param *pi Puntero al item de feromona que se ha evaporado totalmente
		  */
		void pheromoneDeleted(PheromoneItem *pi);

	protected slots:

		/**
		  Este evento es llamado cada vez que el el tiempo de actualizacion ha expirado, en ese entonces
		  se decrementa el item de feromona segun la taza de evaporacion que tenga.
		  */
		void evaporatePheromone();

		/**
		  Este evento es disparado una vez que se ha eliminado totalmente un item de feromona del entorno
		  de este modo se pueden actualizar los demas items que estan vinculados de manera directa o indirecta
		  a este.

		  @param *pi Puntero al item que se ha eliminado
		  */
		void pheromoneHasDeleted(PheromoneItem *pi);
};

#endif // PHEROMONEITEM_H
