#ifndef PHEROMONEDEPOSITOR_H
#define PHEROMONEDEPOSITOR_H


#define _ISOC99_SOURCE
#ifdef WIN32
	#ifndef NAN
		static const unsigned long __nan[2] = {0xffffffff, 0x7fffffff};
		#define NAN (*(const float *) __nan)
	#endif
#endif

#include <QtCore>
#include <math.h>

#include <pheromoneitem.h>
#include <actuador.h>
#include <movilagent.h>
#include <ECFunctions.h>
#include <../INSYDECommon/insydefunctions.h>

#include <ECGraphicInterface_global.h>

using namespace ECFunctions;

/**
  @class PheromoneDepositor
  @author Edixon Vargas
  @date 08-06-2012

  La clase @code{PheromoneDepositor} es un tipo de actuador que le da la propiedad a un agente movil de depositar feromonas
  segun las especificaciones que se le den a este actuador.

  */
class ECGRAPHICINTERFACESHARED_EXPORT PheromoneDepositor : public Actuator
{
		Q_OBJECT

		//Almacena el valor del espaciado de la grilla donde se colocaran los items de feromonas
		double gridSpace;

		//Valor de la distancia minima que tiene que haber entre un item de feromona y otro
		double pheromoneDistance;

		//Puntero al ultimo item de feromona depositado por el agente
		QPointer<PheromoneItem> lastPheromoneItem;

		//Posicion inicial donde se comenzo la deposicion de feromonas
		QPointF initialPosition;

		//Timer que se encarga verificar la distancia entre la ultima feromona depositada y la nueva que se depositara
		QTimer timerCheckDistance;

		//Intensidad de la feromona a depositar
		int pheromoneIntensity;

		//Maxima intensidad que puede tener un item de feromona
		int saturationValue;

		/**
		  Inicializa el actuador para un funcionamiento estandar adecuado para el agente

		  @param intensity Intensidad con la cual depositara una feromona
		  */
		void initPDep(int intensity);

		/**
		  Devuelve la distancia hasta la ultima feromona depositada

		  @return double Distancia a la ultima feromona
		  */
		double distanceToLastPheromone();

	public:

		/**
		  Construye un actuador para depositar feromonas y lo asigna a un agente si es especificado.

		  @param *agent Agente al cual pertenecera este depositor
		  */
		explicit PheromoneDepositor(MovilAgent *agent = NULL);

		/**
		  Construye un actuador para depositar feromonas y lo asigna a un agente si es especificado.

		  @param *agent Agente al cual pertenecera este depositor
		  @param intensity Intensidad con la cual depositara las feromonas
		  */
		explicit PheromoneDepositor(MovilAgent *agent, int intensity);

		/**
		  Deposita un item de feromona con una intensidad indicada por el parametro

		  @param intensity Indica la intensidad con la cual se depositara la feromona
		  */
		void placePheromoneItem(int intensity);
		void placePheromoneItem(double angle);

		/**
		  Deposita un item de feromona existente en el entorno

		  @param *pi Item de feromona previamente creado

		  */
		void placePheromoneItem(PheromoneItem *pi);

//        /**
//          Establece la posicion inicial.

//          @note Nota: esta funcion no esta correctamente definida y su uso es incierto
//          */
//        void setInitialPosition(const QPointF &pos);

//        /**
//          Devuelve la posicion inicial.

//          @note Nota: esta funcion no esta correctamente definida y su uso es incierto
//          */
//        QPointF getInitialPos();

		/**
		  Establece la intensidad con la cual se depositaran los items de feromona

		  @param intensity Valor de la intensidad

		  @see getIntensity
		  */
		void setIntensity(int intensity);

		/**
		  Devuelve la intensidad con la cual se estan depositando las feromonas

		  @return int Intensidad con la que se depositan las feromonas
		  */
		int getIntensity();

		/**
		  Asigna un valor de saturacion de las feromonas para evitar que la deposicion se prolonge
		  hasta valores muy altos en caso de que se superpongan muchos items

		  @param val Valor del nivel de saturacion

		  @see getSaturationValue
		  */
		void setSaturationValue(int val);

		/**
		  Devuelve el valor de saturacion del depositor

		  @return int Maximo valor de saturacion de los items de feromona

		  @see setSaturationValue
		  */
		int getSaturationValue();

		/**
		  Inicia la deposicion de feromonas, esto lo hara dependiendo de la distancia que exista entre cda item de feromona

		  @see stopPlacePheromone
		  */
		void startPlacePheromone();

		/**
		  Detiene la deposicion de feromonas.

		  @see startPlacePheromone
		  */
		void stopPlacePheromone();

	protected slots:

		/**
		  Se activa cada vez que se requiere hacer una evaluacion de la distancia hasta el ultimo item de feromona
		  */
		void timerCheckDistanceEvent();
};

#endif // PHEROMONEDEPOSITOR_H
