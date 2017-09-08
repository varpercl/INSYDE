#ifndef HOPFIELDNETWORK_H
#define HOPFIELDNETWORK_H

#include <QtCore>

#include "share_ann_base_lib.h"
#include "../core/imath.h"
#include "../core/common.h"
#include "artificialneuralnetwork.h"

#include <vector>


namespace ann_base{

using namespace std;

/*!
 * \brief The Hopfield class
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 03/02/2015
 */
class ANN_BASE_LIB_IMPORT_EXPORT Hopfield : public ArtificialNeuralNetwork
{
	public:

		/**
	  Tipo de propagacion de las unidades (neuronas) de la red
	  @param Random Propaga un elemento por vez de modo aleatorio
	  @param Secuential Propaga un elemento por vez pero de modo secuencial
	  */
		enum PropagationType{
			Random,
			Sequential
		};

		/**
	  Contiene informacion sobre el resultado de un entrenamiento, como el numero
	  de epocas que le tomo el entrenamiento, un historial de cambios de los pesos
	  sinapticos, que lo hace ideal si queremos realizar graficas o analisis del
	  avance de los mismos.
	  */
		struct OutputResult{
				int iterations;
				vector<double> output;
				vector<vector<double> > outputHistory;
				//                vector<vector<double> > weightHistory;
				//                vector<double> thresholdHistory;
		};

		/**
	  @enum TransferFunctionType

	  Indica los tipos de funciones de transferencias para un perceptron simple

	  Parametros:

	  alpha = Indica la pendiente de la funcion de transferencia, solamente es considerado en algunos casos
	  suminput = Sumatoria de todas las entradas multiplicadas por los pesos correspondientes

	  @name Step Funcion tipo escalon unitario si la sumatoria es mayor que cero la salida sera 1
	  @name Signus Parecida a la funcion threshold salvo que tiene los valores -1 y 1
	  */
		enum OutputType{
			Signus,
			Step
		};

		/**
	  Construye una red Hopfield con @code{neuronCount} neuronas y con una funcion de transferencia por defecto
	  Binaria, aunque puede ser bipolar (-1,1).

	  @param unsigned int neuronCount Numero de neuronas que tendra esta red. El numero minimo sera de 7 ya que las redes neuronales de Hopfiel necesitan tener al menos N = P / 0.15 neuronas para lograr la convergencia sin errores (minimos locales).
	  @param TransferFunctionType tf Tipo de funcion de transferencia, por defecto es Threshold (binaria), aunque puede ser tambien bipolar (-1,1)
	  */
		explicit Hopfield(unsigned int neuronNumber, OutputType tf = Signus);

		~Hopfield();

		/**
	  Redimensiona la red (si es necesario) al nuevo numero de neuronas @code{nc}, si la cantidad de neuronas
	  a asignar es distinta a la anterior, se redimensionara la red y se asignaran pesos aleatorios.

	  @param unsigned int nc Numero de neuronas que se asignaran a la red.
	  */
		void setNumberNeurons(unsigned int nc);

		/**
	  Devuelve el numero actual de neuronas que tiene la red.

	  @return int Numero de neuronas actualmente asignadas a esta red
	  */
		unsigned int getNumberNeurons() const;

		/**
	  Establece la funcion de transferencia que tendra esta red.

	  @param TransferFunctionType tf Funcion de transferencia que se le asignara

	  @see getTransferFunction
	  */
		void setOutputFunction(OutputType tf);

		/**
	  Devuelve la funcion de transferencia actual de esta red.

	  @return TransferFunctionType Funcion de transferencia actual.
	  */
		OutputType getOutputFunction();

		/**
	  Obtiene un vector con las salidas generadas a partir de un patron presentado a la red

	  @param
	  */
		OutputResult getOutput(const vector<double> &inputs, const PropagationType &pt = Random);

		Type getType() const;

		QString getName() const;

		void randomizeWeights(double min = -1, double max = 1);

	private:

		vector<double> miu;

		//Numero de elementos (neuronas) que tendra la red
		int neuronNumber;

		//Matriz de pesos sinapticos
		vector<vector<int> > weights;

		//Funcion de trasnferencia con la cual esta funcionando esta red
		OutputType tf;

		/**
	  Inicializa la red neuronal con un tamaño de @code{neuronCount} y asigna la
	  funcion de transferencia @code{tf}

	  @param unsigned int neuronCount Asigna el tamaño de la red, es decir, la cantidad de neuronas que tendra.
	  @param TransferFunctionType tf Asigna el tipo de funcion de transferencia

	  @see TransferFunctionType
	  */
		void init(unsigned int neuronCount, OutputType tf);

		bool propagateUnit(int i);

		/*!
	 * \brief calculateWeights
	 * Calcula los pesos para esta red de hopfield. Esta funcion difiere
	 * a una funcion de entrenamiento convencional en que el numero de
	 * iteraciones es fijo y depende del numero de elementos en la red
	 * asimismo no se necesita presentar un conjunto de entradas/objetivos
	 * sino mas bien un conjunto de patrones que utilizara la red para
	 * relacionar.
	 *
	 * \param patterns
	 * \return
	 */
		vector<vector<int> > calculateWeights(const vector<vector<double> > &patterns);

		// ArtificialNeuralNetwork interface
	public:
		int getOutputSize() const override;
		int getInputSize() const override;

	public slots:
		void setInputSize(int i) override;
		void setOutputSize(int o) override;

	private:
		Q_OBJECT
};
}

#endif // HOPFIELDNETWORK_H
