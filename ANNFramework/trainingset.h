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
//struct TrainingPair{
//        //Vector de entradas
//        vector<double> inputs;
//        //Vector de objetivos
//        vector<double> targets;
//};

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

class TrainingSet
{
	public:

		/**
		  Crea una instancia TrainingSet vacia y establece el numero de entradas que tendra
		  y el numero de salidas que tendra el vector objetivo
		  */
		explicit TrainingSet(int n = 1);
		explicit TrainingSet(const vector<vector<double> > &inputs, const vector<vector<double> > &targets);

		/**
				  Redimensiona el numero de entradas del conjunto de entrenamiento. Cuando se cambia el numero
				  de entradas del conjunto de entrenamiento, los valores que estos pares entradas/objetivos
				  contienen se vuelven inciertos, por lo cual es necesario que se le asignen los valores deseados
				  nuevamente
				  */
		void setInputSize(int is);

		/**
				  Devuelve el numero de entradas del conjunto de entrenamiento
				  */
		int getInputSize();

		/**
				  Analogo a setNumberInputs
				  */
		void setTargetSize(int ts);

		/**
				  Analogo a getNumberInputs
				  */
		int getTargetSize();

		void insertTrainingPattern(int i);
		void deleteTrainingPattern(int i);

		void setInputs(const vector<vector<double> > &inputs);
		void setInputs(const vector<vector<int> > &inputs);

		void setTargets(const vector<vector<double> > &targets);
		void setTargets(const vector<vector<int> > &targets);

		vector<vector<double> > getInputs();
		vector<vector<double> > getTargets();

		void normalizeTrainingSet();
		void normalizeTrainingSet(double min, double max);

		void addNoiseToInputs(double min = 0, double max = 1);
		void addNoiseToInputs(double a);

		void addNoiseToTargets(double min = 0, double max = 1);
		void addNoiseToTargets(double a);

		void addNoiseToAll(double min = 0, double max = 1);
		void addNoiseToAll(double a);

		void appendPattern(const vector<double> &inputs, const vector<double> &targets);
		void appendPattern(const vector<int> &inputs, const vector<double> &targets);

	private:
		//conjunto de entradas
		vector<vector<double> > inputs;
		//conjunto de objetivos
		vector<vector<double> > targets;

};

#endif // TRAININGSET_H
