#ifndef TRAININGSET_H
#define TRAININGSET_H

#include "RNALibrary_global.h"
#include <vector>
#include <list>
//#include <string>

using namespace std;

/**
  TrainingPair es un vector expandido que contiene la informacion sobre el par de entrenamiento.
  Este vector contiene a su ves dos vectores, uno de entradas y uno de salidas deseadas. Durante
  la etapa de entrenamiento de la red neuronal se le presentara cada par de entrenamiento y la
  red calculara los pesos adecuados.
  */
struct TrainingPair{
        //Vector de entradas
        vector<double> inputs;
        //Vector de objetivos
        vector<double> targets;
};

/**
  @class TrainingSet
  @author Ing. Edixon Vargas <ingedixonvargas@gmail.com>

  La clase TrainingSet es basica para entrenar cualquier red neuronal
  consiste basicamente en un arreglo (vector) de pares de entrenamiento
  (TrainingPair) estos pares de entrenamiento a su vez son un vector V = <I, T> donde I
  son las entradas y T son los valores deseados. En un objeto TrainingSet
  pueden existir tantos pares de entrenamiento como se desee o como asi lo
  permita el computador o la red neuronal
  */
template<class TrainingPattern>
class TrainingSet : public list<TrainingPattern>
{
    public:

        /**
          Crea una instancia TrainingSet vacia y establece el numero de entradas que tendra
          y el numero de salidas que tendra el vector objetivo
          */
        explicit TrainingSet<TrainingPattern>();
        explicit TrainingSet<TrainingPattern>(int n);

//        /**
//          Redimensiona el numero de entradas del conjunto de entrenamiento. Cuando se cambia el numero
//          de entradas del conjunto de entrenamiento, los valores que estos pares entradas/objetivos
//          contienen se vuelven inciertos, por lo cual es necesario que se le asignen los valores deseados
//          nuevamente
//          */
//        void setNumberInputs(int ni);

//        /**
//          Devuelve el numero de entradas del conjunto de entrenamiento
//          */
//        int getNumberInputs();

//        /**
//          Analogo a setNumberInputs
//          */
//        void setNumberOutputs(int no);

//        /**
//          Analogo a getNumberInputs
//          */
//        int getNumberOutputs();

//        void insertTrainingPattern(const TrainingPattern &tp);

//        TrainingPattern getTrainingPattern();

    private:
//        //vector con un conjunto de pares de entrenamiento
////        list<TrainingPair> tableList;
//        vector<TrainingPattern> table;
//        //numero de entradas que tiene el TrainingSet
//        int ninputs;
//        //numero de salidas que tiene el TrainingSet
//        int noutputs;
};

#endif // TRAININGSET_H
