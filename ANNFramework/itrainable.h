#ifndef ITRAINABLE_H
#define ITRAINABLE_H

#include "general.h"

#ifdef QT_CORE_LIB
#include <QtCore>
#endif

#include "RNALibrary_global.h"
//#include <stdlib.h>

using namespace std;

class ITrainable{

    public:

#ifdef QT_CORE_LIB

        /**
          Entrena el perceptron con una matriz de entradas presentadas, la matriz tendra en cada fila un
          vector de entradas y su correspondiente valor deseado, es ideal si tenemos un conjunto de entrenamiento
          y no un valor de entradas puntual.

          @param QVector<QVector<double> > &inputs Tabla de entradas, cada fila tiene un vector de entradas
          @param QVector<QVector<double> > &targets Valores deseados para cada fila de entradas proporcionadas por inputs
          @param double error Error minimo deseado para que se detenga el algoritmo de entrenamiento
          @param unsigned int nIteraciones Numero de iteraciones maximas deseadas para que se detenga el entrenamiento
          @param double learningFactor Factor de entrenamiento que tendra el perceptron, ayuda en la convergencia del entrenamiento.
          */
//        virtual void train(const QVector<QVector<double> > &inputs, const QVector<double> &targets, double error, unsigned int nIterations, double learningFactor) = 0;

#endif
        /**
          Entrena este perceptron con una matriz de datos, donde cada fila corresponde a un par entrada/objetivo

          @param vector<vector<double> > &inputs Tabla con los valores de entrada, cada fila contiene una serie de datos de entrada.
          @param vector<double> &targets Valores objetivo, cada fila o elemento corresponde a una serie de datos de entrada
          @param double error Error minimo que se quiere alcanzar para que se detenga el entrenamiento.
          @param unsigned int nIteraciones Numero de iteraciones maximas que tendra la funcion de entrenamiento.
          @param double learningFactor Factor de aprendizaje, ayuda en la convergencia del entrenamiento y la velocidad de aprendizaje del perceptron.
        */
//        virtual void train(const vector<vector<double> > &inputs, const vector<double> &target, double error, unsigned int nIterations, double learningFactor) = 0;

        /**
          Entrena una red neuronal con una matriz de salidas y una matriz de entradas

          @param vector<vector<double> > &inputs Matriz de entradas para esta red neuronal
          @param vector<vector<double> > &target Matriz de salidas para esta red neuronal
          @param double error Error maximo que se quiere alcanzar hasta que converja esta red
          @param unsigned int nIterations Numero de iteraciones maximas que se quiere alcanzar con esta red
          @param double learningFactor Factor de aprendizaje que se quiere asignar a esta red
          */
        virtual void train(const vector<vector<double> > &inputs, const vector<vector<double> > &target, double error, unsigned int nIterations, double learningFactor) = 0;

        /**
          Entrena una red neuronal para una sola muestra de datos, es decir un conjunto de entradas y un conjunto de salidas.

          @param vector<double> &inputs Conjunto de entradas
          @param vector<double> &target Conjunto de valores objetivo
          @param double error Error maximo que puede tener durante el entrenamiento
          @param unsigned int nIterations Numero maximo de iteraciones
          @param double learningFactor Factor de aprendizaje durante el entrenamiento
          */

        virtual void train(const vector<double> &inputs, const vector<double> &target, double error, unsigned int nIterations, double learningFactor) = 0;

//        virtual void train(double *inputSet, double target) = 0;
//        virtual void setTransferFunction(TransferFunctionType tf) = 0;
//        virtual TransferFunctionType getTransferFunction() = 0;
};

#endif // ITRAINING_H
