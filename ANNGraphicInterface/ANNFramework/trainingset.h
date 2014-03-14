#ifndef TRAININGSET_H
#define TRAININGSET_H

#include <QObject>

#include <vector>
#include <list>

#include "trainingsetinterface.h"
#include "ANNFramework_global.h"

class ITrainingSet;
//using namespace std;

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

/*!
 * \brief La clase TrainingSet es basica para entrenar cualquier red neuronal
 * consiste basicamente en un arreglo (vector) de pares de entrenamiento
 * (TrainingPair) estos pares de entrenamiento a su vez son un vector V = <I, T> donde I
 * son las entradas y T son los valores deseados. En un objeto TrainingSet
 * pueden existir tantos pares de entrenamiento como se desee o como asi lo
 * permita el computador o la red neuronal.
 *
 * \author Ing. Edixon Vargas <ingedixonvargas@gmail.com>
 */
class ANNFRAMEWORK_EXPORT TrainingSet : public QObject, public ITrainingSet
{
	public:

		explicit TrainingSet(QObject *parent = 0);

		/**
		  Crea una instancia TrainingSet vacia y establece el numero de entradas que tendra
		  y el numero de salidas que tendra el vector objetivo
		  */
		explicit TrainingSet(int inputsize, double targetsize, int n = 1, QObject *parent = 0);
		explicit TrainingSet(const vector<vector<double> > &inputs, const vector<vector<double> > &targets, QObject *parent = 0);
		explicit TrainingSet(double **inputs,
							 unsigned int sinputs,
							 double **targets,
							 unsigned int stargets,
							 unsigned int spatterns, QObject *parent = 0);

		/*!
		 * \brief TrainingSet
		 *
		 * \note Este constructor no se declara \code{explicit} porque puede ocasionar
		 * problemas al retornar un valor de este tipo en alguna funcion.
		 *
		 * \see Elide Constructors
		 *
		 * \param ts
		 * \param parent
		 */
		TrainingSet(const TrainingSet &ts, QObject *parent = 0);

		//		explicit TrainingSet(TrainingSet ts);

		~TrainingSet();

		/**
		 * @brief setInputSize Funcion reimplementada.
		 * @see @code{ITrainingSet::setInputSize()}
		 */
		void setInputSize(int is, double fill = 0);

		/*!
		 * \brief getInputSize
		 * \return
		 */
		int getInputSize() const;

		/**
		 * @brief setTargetSize Funcion reimplementada.
		 * @reimp @code{ITrainingSet::setTargetSize()}
		 * @param ts
		 * @param fill
		 */
		void setTargetSize(int ts, double fill = 0);

		/**
				  Analogo a getNumberInputs
				  */
		int getTargetSize() const;

		/*!
		 * \brief insertTrainingPattern
		 * \param inputs
		 * \param targets
		 * \param i
		 */
		void insertPattern(const vector<double> &inputs, const vector<double> &targets, int i);

		/*!
		 * \brief insertTrainingPattern
		 * \param inputs
		 * \param targets
		 * \param i
		 */
		void insertPattern(const vector<int> &inputs, const vector<int> &targets, int i);

		/*!
		 * \brief deleteTrainingPattern
		 * \param i
		 */
		void deletePattern(int i);

		/*!
		 * \brief setInputs Función reimplementada.
		 * \param inputs
		 */
		void setInputs(const vector<vector<double> > &inputs);

		/*!
		 * \brief setInputs Funcion reimplementada.
		 * \param inputs
		 */
		void setInputs(const vector<vector<int> > &inputs);

		/*!
		 * \brief setTargets Funcion reimplementada.
		 * \param targets
		 */
		void setTargets(const vector<vector<double> > &targets);

		/*!
		 * \brief setTargets Funcion reimplementada.
		 * \param targets
		 */
		void setTargets(const vector<vector<int> > &targets);

		vector<vector<double> > getInputs() const;
		vector<vector<double> > getTargets() const;

		void normalizeLinearFixedRange(double minInputs, double maxInputs, double minTargets, double maxTargets);
		void normalizeInputsLinearFixedRange(double min, double max);
		void normalizeTargetsLinearFixedRange(double min, double max);

		TrainingSet getNormalizedLinearFixedRange(double minInputs, double maxInputs, double minTargets, double maxTargets) const;
		vector<vector<double> > getNormalizedInputsLinearFixedRange(double min, double max);
		vector<vector<double> > getNormalizedTargetsLinearFixedRange(double min, double max);

		void normalizeLinearAutoRange(double *minInputs, double *maxInputs, double *minTargets, double *maxTargets);
		void normalizeInputsLinearAutoRange(double *min, double *max);
		void normalizeTargetsLinearAutoRange(double *min, double *max);

		TrainingSet getNormalizedLinearAutoRange(double *minInputs, double *maxInputs, double *minTargets, double *maxTargets) const;
		vector<vector<double> > getNormalizedInputsLinearAutoRange(double *min, double *max);
		vector<vector<double> > getNormalizedTargetsLinearAutoRange(double *min, double *max);

		void normalizeUnipolarFixedThreshold(double inThreshold, double tarThreshold);
		void normalizeInputsUnipolarFixedThreshold(double threshold);
		void normalizeTargetsUnipolarFixedThreshold(double threshold);

		TrainingSet getNormalizedUnipolarFixedThreshold(double inThreshold, double tarThreshold) const;
		vector<vector<double> > getNormalizedInputsUnipolarFixedThreshold(double threshold) const;
		vector<vector<double> > getNormalizedTargetsUnipolarFixedThreshold(double threshold) const;

		void normalizeUnipolarAutoThreshold(double *inThreshold, double *tarThreshold);
		void normalizeInputsUnipolarAutoThreshold(double *threshold);
		void normalizeTargetsUnipolarAutoThreshold(double *threshold);

		TrainingSet getNormalizedUnipolarAutoThreshold(double *inThreshold, double *tarThreshold) const;
		vector<vector<double> > getNormalizedInputsUnipolarAutoThreshold(double *threshold) const;
		vector<vector<double> > getNormalizedTargetsUnipolarAutoThreshold(double *threshold) const;

		void normalizeBipolarFixedThreshold(double inThreshold, double tarThreshold);
		void normalizeInputsBipolarFixedThreshold(double threshold);
		void normalizeTargetsBipolarFixedThreshold(double threshold);

		TrainingSet getNormalizedBipolarFixedThreshold(double inThreshold, double tarThreshold) const;
		vector<vector<double> > getNormalizedInputsBipolarFixedThreshold(double threshold) const;
		vector<vector<double> > getNormalizedTargetsBipolarFixedThreshold(double threshold) const;

		void normalizeBipolarAutoThreshold(double *inThreshold, double *tarThreshold);
		void normalizeInputsBipolarAutoThreshold(double *threshold);
		void normalizeTargetsBipolarAutoThreshold(double *threshold);

		TrainingSet getNormalizedBipolarAutoThreshold(double *inThreshold, double *tarThreshold) const;
		vector<vector<double> > getNormalizedInputsBipolarAutoThreshold(double *threshold) const;
		vector<vector<double> > getNormalizedTargetsBipolarAutoThreshold(double *threshold) const;

		void normalizeTanh(double inAmp = 1, double inElong = 1, double tarAmp = 1, double tarElong = 1);
		void normalizeInputsTanh(double amp = 1, double elong = 1);
		void normalizeTargetsTanh(double amp = 1, double elong = 1);

		TrainingSet getNormalizedTanh(double inAmp = 1, double inElong = 1, double tarAmp = 1, double tarElong = 1);
		vector<vector<double> > getNormalizedInputsTanh(double amp = 1, double elong = 1);
		vector<vector<double> > getNormalizedTargetsTanh(double amp = 1, double elong = 1);

		void normalizeSigmoid(double inAmp = 1, double inElong = 1, double tarAmp = 1, double tarElong = 1);
		void normalizeInputsSigmoid(double amp = 1, double elong = 1);
		void normalizeTargetsSigmoid(double amp = 1, double elong = 1);

		TrainingSet getNormalizedSigmoid(double inAmp = 1, double inElong = 1, double tarAmp = 1, double tarElong = 1);
		vector<vector<double> > getNormalizedInputsSigmoid(double amp = 1, double elong = 1);
		vector<vector<double> > getNormalizedTargetsSigmoid(double amp = 1, double elong = 1);

		void normalizeMeanDistance();
		void normalizeInputsMeanDistance();
		void normalizeTargetsMeanDistance();

		TrainingSet getNormalizedMeanDistance();
		vector<vector<double> > getNormalizedInputsMeanDistance();
		vector<vector<double> > getNormalizedTargetsMeanDistance();

		void normalize(NormalizationType no);
		TrainingSet getNormalized(NormalizationType nt) const;

		void addNoiseToInputs(double min, double max);
		void addNoiseToInputs(double a);

		void addNoiseToTargets(double min, double max);
		void addNoiseToTargets(double a);

		void addNoiseToAll(double min, double max);
		void addNoiseToAll(double a);


		void setPatternCount(int s);
		int getPatternCount() const;

		void setInput(int pat, int index, double value);
		void setTarget(int pattern, int index, double value);
		double getInput(int pat, int index) const;
		double getTarget(int pat, int index) const;
		void setPattern(int index, const vector<double> &inputs, const vector<double> &targets);
		pair<vector<double>, vector<double> > getPattern(int index) const;
		void appendPattern(const vector<double> &inputs, const vector<double> &targets);

		TrainingSet &operator=(const TrainingSet &trset);
		bool operator==(const TrainingSet &trset);
		bool operator!=(const TrainingSet &trset);


		void save(const QString &file);

	signals:

		void inputsChanged(const vector<vector<double> > &li, const vector<vector<double> > &ni);
		void inputsChanged(const vector<vector<double> > &ni);
		void inputsChanged(const vector<vector<int> > &li, const vector<vector<int> > &ni);
		void inputsChanged(const vector<vector<int> > &ni);

		void inputChanged(int pat, int index, double value);
		void inputChanged(int pat, int index, double prevValue, double newValue);

		void targetsChanged(const vector<vector<double> > &lt, const vector<vector<double> > &nt);
		void targetsChanged(const vector<vector<double> > &nt);
		void targetsChanged(const vector<vector<int> > &lt, const vector<vector<int> > &nt);
		void targetsChanged(const vector<vector<int> > &nt);

		void targetChanged(int pat, int index, double value);
		void targetChanged(int pat, int index, double prevValue, double newValue);

		void inputSizeChanged(int ls, int ns);
		void inputSizeChanged(int ns);
		void targetSizeChanged(int ls, int ns);
		void targetSizeChanged(int ns);

		void patternInserted(const vector<double> &inputs, const vector<double> &targets, int index);
		void patternInserted(const vector<int> &inputs, const vector<int> &targets, int i);

		void patternAdded(const vector<double> &inputs, const vector<double> &targets);

		void patternDeleted(const vector<double> &inputs, const vector<double> &targets, int i);

		void patternChanged(int index, const vector<double> &inputs, const vector<double> &targets);
		void patternChanged(int index, const vector<double> &prevInputs, const vector<double> &newInputs, const vector<double> &prevTargets, const vector<double> &newTargets);

	private:
		Q_OBJECT

		NormalizationType
		inputsNorType,
		targetsNorType;

		vector<vector<double> >
		inputs,						/**< conjunto de entradas*/
		targets,					/**< conjunto de objetivos*/

		normalizedInputs,			/**< conjunto de entradas normalizadas*/
		normalizedTargets;			/**< conjunto de objetivos normalizados*/

		void initTS(const vector<vector<double> > &inputs, const vector<vector<double> > &targets);
		void resizeVectorSet(vector<vector<double> > &vec, int s, double fill);
};
#endif // TRAININGSET_H
