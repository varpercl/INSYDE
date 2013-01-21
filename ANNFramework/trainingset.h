#ifndef TRAININGSET_H
#define TRAININGSET_H

#include <ANNFramework_global.h>
#include <vector>
#include <list>
//#include <string>

using namespace std;
using namespace ANNFrameworkFunctions;

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

class ANNFRAMEWORK_EXPORT TrainingSet
{
	public:

		enum NormalizeOption{
			Standart,
			Sigmoid,
			Tanh
		};

		explicit TrainingSet();
		/**
		  Crea una instancia TrainingSet vacia y establece el numero de entradas que tendra
		  y el numero de salidas que tendra el vector objetivo
		  */
		explicit TrainingSet(int inputsize, double targetsize, int n = 1);
		explicit TrainingSet(const vector<vector<double> > &inputs, const vector<vector<double> > &targets);
		explicit TrainingSet(double **inputs,
							 unsigned int sinputs,
							 double **targets,
							 unsigned int stargets,
							 unsigned int spatterns);

		~TrainingSet();

		/**
				  Redimensiona el numero de entradas del conjunto de entrenamiento. Cuando se cambia el numero
				  de entradas del conjunto de entrenamiento, los valores que estos pares entradas/objetivos
				  contienen se vuelven inciertos, por lo cual es necesario que se le asignen los valores deseados
				  nuevamente
				  */
		void setInputSize(int is);
		void setInputSize(int is, double fill);

		/**
				  Devuelve el numero de entradas del conjunto de entrenamiento
				  */
		int getInputSize();

		/**
				  Analogo a setNumberInputs
				  */
		void setTargetSize(int ts);
		void setTargetSize(int ts, double fill);

		/**
				  Analogo a getNumberInputs
				  */
		int getTargetSize() const;

		void insertTrainingPattern(const vector<double> &inputs, const vector<double> &targets, int i);
		void insertTrainingPattern(const vector<int> &inputs, const vector<int> &targets, int i);
		void deleteTrainingPattern(int i);

		void setInputs(const vector<vector<double> > &inputs);
		void setInputs(const vector<vector<int> > &inputs);

		void setTargets(const vector<vector<double> > &targets);
		void setTargets(const vector<vector<int> > &targets);

		vector<vector<double> > getInputs() const;
		vector<vector<double> > getTargets() const;

		void normalize(double min, double max);
		void normalize(NormalizeOption no);

		void addNoiseToInputs(double min = 0, double max = 1);
		void addNoiseToInputs(double a);

		void addNoiseToTargets(double min = 0, double max = 1);
		void addNoiseToTargets(double a);

		void addNoiseToAll(double min = 0, double max = 1);
		void addNoiseToAll(double a);

		void appendPattern(const vector<double> &inputs, const vector<double> &targets);
		void appendPattern(const vector<int> &inputs, const vector<double> &targets);

		void setPatternCount(int s);
		int getPatternCount();

		TrainingSet operator=(const TrainingSet &trset);

	private:
		//conjunto de entradas
		vector<vector<double> > inputs;
		//conjunto de objetivos
		vector<vector<double> > targets;

		void initTS(const vector<vector<double> > &inputs, const vector<vector<double> > &targets);
		void resizeVectorSet(vector<vector<double> > &vec, int s, double fill);
};

#endif // TRAININGSET_H
