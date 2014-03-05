#ifndef ITRAINABLE_H
#define ITRAINABLE_H

#include "normalization.h"

#include <vector>
#include <utility>

class TrainingSet;

using namespace std;

class ITrainingSet{

	public:
		/*!
		 * \brief The NormalizationType enum
		 */
		enum NormalizationType{
			Nothing,
			BipolarFixedThreshold,
			BipolarAutoThreshold,
			UnipolarFixedThreshold,
			UnipolarAutoThreshold,
			LinearFixedRange,
			LinearAutoRange,
			Tanh,
			Sigmoid
		};

		/**
		 * @brief setInputSize Establece el tamaño del patron de entrada.
		 *
		 * Redimensiona el numero de entradas del conjunto de entrenamiento. Cuando se cambia el numero
		 * de entradas del conjunto de entrenamiento, los valores que estos pares entradas/objetivos
		 * contienen se vuelven inciertos, por lo cual es necesario que se le asignen los valores deseados
		 * nuevamente.
		 *
		 * @param is
		 */
		virtual void setInputSize(int is, double fill = 0) = 0;

		/**
		 * @brief getInputSize Devuelve el tamaño del patron de entradas.
		 * @return
		 */
		virtual int getInputSize() const = 0;

		/**
		 * @brief setTargetSize Establece el tamaño del patron de salida.
		 * @param ts
		 * @param fill
		 */
		virtual void setTargetSize(int ts, double fill = 0) = 0;

		/**
		 * @brief getTargetSize Devuelve tamaño del patron de salida.
		 * @return
		 */
		virtual int getTargetSize() const = 0;

		/*!
		 * \brief insertPattern Inserta un patron de entrenamiento en el indice \code{index} indicado.
		 * \param inputs
		 * \param targets
		 * \param index
		 */
		virtual void insertPattern(const vector<double> &inputs, const vector<double> &targets, int index) = 0;

		/*!
		 * \brief insertPattern Inserta un patron de entrenamiento en el indice \code{index} indicado.
		 * \param inputs
		 * \param targets
		 * \param index
		 */
		virtual void insertPattern(const vector<int> &inputs, const vector<int> &targets, int index) = 0;

		/*!
		 * \brief deletePattern Elimina un patron de entrenamiento en el indice \code{index} dado.
		 * \param index
		 */
		virtual void deletePattern(int index) = 0;

		/*!
		 * \brief setInputs Asigna el subconjunto de entradas \code{inputs} al conjunto de entrenamiento.
		 *
		 * Este metodo contiene la implementacion original donde los valores de entrada son del tipo \code{double}.
		 *
		 * \param inputs
		 */
		virtual void setInputs(const vector<vector<double> > &inputs) = 0;

		/*!
		 * \brief setInputs Asigna el subconjunto de entradas \code{inputs} al conjunto de entrenamiento.
		 *
		 * \overload Este metodo es una sobrecarga para soportar valores de tipo \code{int}.
		 *
		 * \param inputs
		 */
		virtual void setInputs(const vector<vector<int> > &inputs) = 0;

		/*!
		 * \brief setInput
		 * \param pat
		 * \param index
		 * \param value
		 */
		virtual void setInput(int pat, int index, double value) = 0;

		/*!
		 * \brief setTargets  Asigna el subconjunto de salidas \code{targets} al conjunto de entrenamiento.
		 *
		 * Este metodo contiene la implementacion original donde los valores de salida son del tipo \code{double}.
		 *
		 * \param targets
		 */
		virtual void setTargets(const vector<vector<double> > &targets) = 0;

		/*!
		 * \brief setTargets Asigna el subconjunto de salidas \code{targets} al conjunto de entrenamiento.
		 *
		 * \overload Este metodo es una sobrecarga para soportar valores de tipo \code{int}.
		 *
		 * \param targets
		 */
		virtual void setTargets(const vector<vector<int> > &targets) = 0;

		/*!
		 * \brief setTarget
		 * \param pattern
		 * \param index
		 * \param value
		 */
		virtual void setTarget(int pattern, int index, double value) = 0;

		/*!
		 * \brief getInputs Devuelve el subconjunto de entradas de este conjunto de entrenamiento.
		 * \return
		 */
		virtual vector<vector<double> > getInputs() const = 0;

		/*!
		 * \brief getInput
		 * \param pat
		 * \param index
		 * \return 
		 */
		virtual double getInput(int pat, int index) const = 0;

		/*!
		 * \brief getTargets Devuelve el subconjunto de salidas de este conjunto de entrenamiento.
		 * \return
		 */
		virtual vector<vector<double> > getTargets() const = 0;

		/*!
		 * \brief getTarget
		 * \param pat
		 * \param index
		 * \return 
		 */
		virtual double getTarget(int pat, int index) const = 0;

		/*!
		 * \brief normalize Normaliza el conjunto de entrenamiento.
		 *
		 * La normalizacion de los datos contribuye en una convergencia mucho mas rapida al realizar el entrenamiento
		 * de cualquier red neuronal.
		 *
		 * En este caso se procede a normalizar los datos en base a valores maximos y minimos ya conocidos. Es muy util si
		 * tenemos valores que se mueven entre un rango de datos fijo que sabemos no cambiara con el tiempo.
		 *
		 * \note
		 * \parblock
		 * Al conocer el rango de valores entre el cual se mueven los datos, se puede realizar una \"desnormalizacion\", lo cual
		 * permite deshacer los cambios hechos a los datos.
		 *
		 * Si los valores se encuentran fuera de \code min y \code max, estos seran ajustados automaticamente
		 * a \code min y \code max respectivamente.
		 * \endparblock
		 *
		 * \note Esta funcion cambia el estado del tipo de normalizacion, lo que implica que cualquier dato que sea insertado sera
		 * normalizado automaticamente.
		 *
		 * \param min
		 * \param max
		 */
		virtual void normalizeLinearFixedRange(double minInputs, double maxInputs, double minTargets, double maxTargets) = 0;

		virtual void normalizeInputsLinearFixedRange(double min, double max) = 0;
		virtual void normalizeTargetsLinearFixedRange(double min, double max) = 0;

		/*!
		 * \brief getNormalized Devuelve un conjunto de enternamiento (\code{TrainingSet}) normalizado con limites conocidos.
		 *
		 * En este tipo de normalizacion se deben conocer exactamente cuales son los limites maximos y minimos
		 * de los datos que tendra el conjunto de entrenamiento. Todos aquellos datos que esten fuera de ese rango
		 * se ajustaran al limite mas proximo. Se debe tener cuidado al usar este tipo de normalizacion ya que existe
		 * la posibilidad de perdida de datos.
		 *
		 * \param min
		 * \param max
		 * \return
		 */
		virtual TrainingSet getNormalizedLinearFixedRange(double minInputs, double maxInputs, double minTargets, double maxTargets) const = 0;

		virtual vector<vector<double> > getNormalizedInputsLinearFixedRange(double min, double max) = 0;
		virtual vector<vector<double> > getNormalizedTargetsLinearFixedRange(double min, double max) = 0;

		/**
		 * @brief normalize Normaliza el conjunto de entrenamiento.
		 *
		 * Similar a la normalizacion con rango fijo de valores, sin embargo, en este caso se determina automaticamente el valor
		 * maximo y minimo.
		 *
		 * La funcion devuelve en sus parametros los valores \code min y \code max, en caso de que los mismos sean necesarios.
		 *
		 * \note Esta funcion es mal lenta ya que requiere primero recorrer el conjunto de entrenamiento para buscar los maximos y minimos.
		 * \note Esta funcion cambia el estado del tipo de normalizacion, lo que implica que cualquier dato que sea insertado sera
		 * normalizado automaticamente.
		 *
		 * @param min
		 * @param max
		 */
		virtual void normalizeLinearAutoRange(double *minInputs, double *maxInputs, double *minTargets, double *maxTargets) = 0;

		virtual void normalizeInputsLinearAutoRange(double *min, double *max) = 0;
		virtual void normalizeTargetsLinearAutoRange(double *min, double *max) = 0;

		/*!
		 * \brief getNormalized Devuelve un conjunto de entrenamiento (\code{TrainingSet}) normalizado con limites desconocidos.
		 *
		 * Este es un tipo de normalizacion lineal donde no se conoce el limite inferior ni el limite superior.
		 * Lo cual significa que hay que determinarlos. Los limites son devueltos a travez de \code{min} y \code{max}
		 * si lo requieren.
		 *
		 * \param min
		 * \param max
		 * \return
		 */
		virtual TrainingSet getNormalizedLinearAutoRange(double *minInputs, double *maxInputs, double *minTargets, double *maxTargets) const = 0;

		virtual vector<vector<double> > getNormalizedInputsLinearAutoRange(double *min, double *max) = 0;
		virtual vector<vector<double> > getNormalizedTargetsLinearAutoRange(double *min, double *max) = 0;
		
		/*!
		 * \brief normalize
		 * \param inThreshold
		 * \param tarThreshold
		 */
		virtual void normalizeUnipolarFixedThreshold(double inThreshold, double tarThreshold) = 0;

		virtual void normalizeInputsUnipolarFixedThreshold(double threshold) = 0;
		virtual void normalizeTargetsUnipolarFixedThreshold(double threshold) = 0;

		virtual TrainingSet getNormalizedUnipolarFixedThreshold(double inThreshold, double tarThreshold) const = 0;

		virtual vector<vector<double> > getNormalizedInputsUnipolarFixedThreshold(double threshold) const = 0;
		virtual vector<vector<double> > getNormalizedTargetsUnipolarFixedThreshold(double threshold) const = 0;
		
		/*!
		 * \brief normalize
		 * \param inThreshold
		 * \param tarThreshold
		 */
		virtual void normalizeUnipolarAutoThreshold(double *inThreshold, double *tarThreshold) = 0;

		virtual void normalizeInputsUnipolarAutoThreshold(double *threshold) = 0;
		virtual void normalizeTargetsUnipolarAutoThreshold(double *threshold) = 0;

		virtual TrainingSet getNormalizedUnipolarAutoThreshold(double *inThreshold, double *tarThreshold) const = 0;

		virtual vector<vector<double> > getNormalizedInputsUnipolarAutoThreshold(double *threshold) const = 0;
		virtual vector<vector<double> > getNormalizedTargetsUnipolarAutoThreshold(double *threshold) const = 0;

		virtual void normalizeBipolarFixedThreshold(double inThreshold, double tarThreshold) = 0;

		virtual void normalizeInputsBipolarFixedThreshold(double threshold) = 0;
		virtual void normalizeTargetsBipolarFixedThreshold(double threshold) = 0;

		virtual TrainingSet getNormalizedBipolarFixedThreshold(double inThreshold, double tarThreshold) const = 0;

		virtual vector<vector<double> > getNormalizedInputsBipolarFixedThreshold(double threshold) const = 0;
		virtual vector<vector<double> > getNormalizedTargetsBipolarFixedThreshold(double threshold) const = 0;

		virtual void normalizeBipolarAutoThreshold(double *inThreshold, double *tarThreshold) = 0;

		virtual void normalizeInputsBipolarAutoThreshold(double *threshold) = 0;
		virtual void normalizeTargetsBipolarAutoThreshold(double *threshold) = 0;

		virtual TrainingSet getNormalizedBipolarAutoThreshold(double *inThreshold, double *tarThreshold) const = 0;

		virtual vector<vector<double> > getNormalizedInputsBipolarAutoThreshold(double *threshold) const = 0;
		virtual vector<vector<double> > getNormalizedTargetsBipolarAutoThreshold(double *threshold) const = 0;

//		virtual void normalizeTanh(double *inThreshold, double *tarThreshold) = 0;
//		virtual void normalizeSigmoid(double *inThreshold, double *tarThreshold) = 0;

		/*!
		 * NOTE: se debe investigar bien sobre este tipo de normalizacion. Ya que esta es un poco mas compleja.
		 *
		 * \note Esta funcion cambia el estado del tipo de normalizacion, lo que implica que cualquier dato que sea insertado sera
		 * normalizado automaticamente.
		 *
		 * \brief normalize
		 * \param no
		 */
		virtual void normalize(NormalizationType no) = 0;

		/*!
		 * \brief getNormalized Devuelve un conjunto de entrenamiento normalizado (\code{TrainingSet}).
		 *
		 * Se devuelve un conjunto normalizado de acuerdo a \code{no}.
		 * \param no
		 * \return
		 */
		virtual TrainingSet getNormalized(NormalizationType no) const = 0;

		/*!
		 * \brief setNormalizationType Establece el tipo de normalizacion que se usara en este conjunto de entrenamiento.
		 *
		 * A diferencia de \code{normalize()}, que normaliza todo el conjunto de entrenamiento, \code{setNormalizationType()}
		 * solo indica el tipo de normalizacion que se utilizara a la hora de agregar/insertar nuevos patrones de entrenamiento.
		 * Asi como tambien cuando se asigne un conjunto de entradas/targets nuevo. Esto significa que los datos que sean
		 * asignados seran normalizados automaticamente.
		 *
		 * Esto tiene especial importancia para evitar que una vez normalizado el conjunto de entrenamiento, si se decidiese
		 * insertar nuevos patrones con valores totalmente fuera del rango de normalizacion se generaran problemas con el
		 * entrenamiento y la incongruencia que existiria entre los mismos.
		 *
		 * \param nt
		 */
//		virtual void setNormalizationType(NormalizationType nt) = 0;

		/*!
		 * \brief addNoiseToInputs Suma ruido al subconjunto de entradas.
		 *
		 * Permite crear conjuntos de entrenamiento a partir de un padre, donde tales conjuntos representan variaciones
		 * con inclusion de ruido, lo cual permitiria que la red tenga un entrenamiento mas completo y tolerante a fallos.
		 *
		 * \note Esta utilidad debe ser usada con cautela ya que no hay manera de volver a los valores anteriores.
		 *
		 * \param min, max
		 */
		virtual void addNoiseToInputs(double min, double max) = 0;

		/*!
		 * \brief addNoiseToInputs Suma ruido al subconjunto de entradas.
		 *
		 * \overload Esta es una funcion sobrecargada.
		 *
		 * \param a
		 */
		virtual void addNoiseToInputs(double a) = 0;

		/*!
		 * \brief addNoiseToTargets Suma ruido al subconjunto de salidas.
		 *
		 * Permite crear conjuntos de entrenamiento a partir de un padre, donde tales conjuntos representan variaciones
		 * con inclusion de ruido, lo cual permitiria que la red tenga un entrenamiento mas completo y tolerante a fallos.
		 *
		 * \note Esta utilidad debe ser usada con cautela ya que no hay manera de volver a los valores anteriores.
		 * \param min
		 * \param max
		 */
		virtual void addNoiseToTargets(double min, double max) = 0;

		/*!
		 * \brief addNoiseToTargets Suma ruido al subconjunto de salidas.
		 *
		 * \overload Esta es una funcion sobrecargada.
		 *
		 * \param a
		 */
		virtual void addNoiseToTargets(double a) = 0;

		/*!
		 * \brief addNoiseToAll
		 * \param min
		 * \param max
		 */
		virtual void addNoiseToAll(double min, double max) = 0;

		/*!
		 * \brief addNoiseToAll
		 * \param a
		 */
		virtual void addNoiseToAll(double a) = 0;

		/*!
		 * \brief appendPattern
		 * \param inputs
		 * \param targets
		 */
		virtual void appendPattern(const vector<double> &inputs, const vector<double> &targets) = 0;

		/*!
		 * \brief setPatternCount
		 * \param s
		 */
		virtual void setPatternCount(int s) = 0;

		/*!
		 * \brief getPatternCount
		 * \return
		 */
		virtual int getPatternCount() const = 0;

		virtual void setPattern(int index, const vector<double> &inputs, const vector<double> &targets) = 0;

		virtual pair<vector<double>, vector<double> > getPattern(int index) const = 0;

		void setNormalization(const Normalization &nor);
		Normalization getNormalization() const;

	protected:
		Normalization inputsNorm, targetsNorm;
};

#endif // ITRAINING_H
