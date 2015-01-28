#ifndef TRAININGSET_H
#define TRAININGSET_H

#include <QObject>
#include <QStandardItemModel>

#include <vector>
#include <list>

#include <tbb/concurrent_vector.h>
#include <tbb/tbb.h>

#include "mlp.h"
#include "itrainingset.h"
#include "ANNglobal.h"
#include "trainingsetfile.h"

using namespace std;
using namespace tbb;

class TrainingSetFile;
class MultilayerPerceptron;
class ITrainingSet;


//NOTE: evaluar la posibilidad de usar una sola matriz MxN en lugar de dos matrices (uno para las entradas y uno para las salidas)

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
class ANNFRAMEWORK_EXPORT TrainingSet : public QAbstractTableModel, public ITrainingSet
{
	public:

		explicit TrainingSet();

		/**
		  Crea una instancia TrainingSet vacia y establece el numero de entradas que tendra
		  y el numero de salidas que tendra el vector objetivo
		  */
		explicit TrainingSet(int inputsize,
							 int targetsize,
							 int n = 1);

		explicit TrainingSet(const vector<vector<double> > &inputs,
							 int is,
							 const vector<vector<double> > &targets,
							 int ts);

		explicit TrainingSet(double **inputs,
							 unsigned int sinputs,
							 double **targets,
							 unsigned int stargets,
							 unsigned int spatterns);

		explicit TrainingSet(MultilayerPerceptron *mlp);

		explicit TrainingSet(TrainingSetFile &file);

		explicit TrainingSet(const QString &path);

		explicit TrainingSet(const TrainingSetFile &file);

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
		TrainingSet(const TrainingSet &ts);

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
		int getInputsSize() const;

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
		int getTargetsSize() const;

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
		void removePattern(int i);

		/*!
		 * \brief setInputs Función reimplementada.
		 * \param inputs
		 */
		void setInputs(const vector<vector<double> > &inputs, int size);

		/*!
		 * \brief setInputs Funcion reimplementada.
		 * \param inputs
		 */
		void setInputs(const vector<vector<int> > &inputs, int size);

		/*!
		 * \brief setTargets Funcion reimplementada.
		 * \param targets
		 */
		void setTargets(const vector<vector<double> > &targets, int size);

		/*!
		 * \brief setTargets Funcion reimplementada.
		 * \param targets
		 */
		void setTargets(const vector<vector<int> > &targets, int size);

		/*!
		 * \brief getInputs Devuelve el conjunto de entradas
		 * \return Devuelve una matriz MxN con M patrones y N siendo el tamaño de las entradas
		 */
		vector<vector<double> > getInputs() const;

		/*!
		 * \brief getTargets Devuelve el conjunto de salidas
		 * \return Devuelve una matriz MxN con M patrones y N siendo el tamaño de las salidas
		 */
		vector<vector<double> > getTargets() const;

		void normalizeNothing();
		void normalizeInputsNothing();
		void normalizeTargetsNothing();

		void normalizeLinearFixedRange(Normalization in, Normalization tn);
		void normalizeLinearFixedRange(double minInputs, double maxInputs, double minTargets, double maxTargets);
		void normalizeInputsLinearFixedRange(Normalization in);
		void normalizeInputsLinearFixedRange(double min, double max);
		void normalizeTargetsLinearFixedRange(Normalization tn);
		void normalizeTargetsLinearFixedRange(double min, double max);

		void normalizeLinearAutoRange(Normalization *in, Normalization *tn);
		void normalizeLinearAutoRange(double *minInputs, double *maxInputs, double *minTargets, double *maxTargets);
		void normalizeInputsLinearAutoRange(Normalization *in);
		void normalizeInputsLinearAutoRange(double *min, double *max);
		void normalizeTargetsLinearAutoRange(Normalization *tn);
		void normalizeTargetsLinearAutoRange(double *min, double *max);

		void normalizeUnipolarFixedThreshold(Normalization in, Normalization tn);
		void normalizeUnipolarFixedThreshold(double inThreshold, double tarThreshold);
		void normalizeInputsUnipolarFixedThreshold(Normalization in);
		void normalizeInputsUnipolarFixedThreshold(double threshold);
		void normalizeTargetsUnipolarFixedThreshold(Normalization tn);
		void normalizeTargetsUnipolarFixedThreshold(double threshold);

		void normalizeUnipolarAutoThreshold(Normalization *in, Normalization *tn);
		void normalizeUnipolarAutoThreshold(double *inThreshold, double *tarThreshold);
		void normalizeInputsUnipolarAutoThreshold(Normalization *in);
		void normalizeInputsUnipolarAutoThreshold(double *threshold);
		void normalizeTargetsUnipolarAutoThreshold(Normalization *tn);
		void normalizeTargetsUnipolarAutoThreshold(double *threshold);

		void normalizeBipolarFixedThreshold(Normalization in, Normalization tn);
		void normalizeBipolarFixedThreshold(double inThreshold, double tarThreshold);
		void normalizeInputsBipolarFixedThreshold(Normalization in);
		void normalizeInputsBipolarFixedThreshold(double threshold);
		void normalizeTargetsBipolarFixedThreshold(Normalization tn);
		void normalizeTargetsBipolarFixedThreshold(double threshold);

		void normalizeBipolarAutoThreshold(Normalization *in, Normalization *tn);
		void normalizeBipolarAutoThreshold(double *inThreshold, double *tarThreshold);
		void normalizeInputsBipolarAutoThreshold(Normalization *in);
		void normalizeInputsBipolarAutoThreshold(double *threshold);
		void normalizeTargetsBipolarAutoThreshold(Normalization *tn);
		void normalizeTargetsBipolarAutoThreshold(double *threshold);

		void normalizeTanh(Normalization in, Normalization tn);
		void normalizeTanh(double inAmp = 1, double inElong = 1, double tarAmp = 1, double tarElong = 1);
		void normalizeInputsTanh(Normalization in);
		void normalizeInputsTanh(double amp = 1, double elong = 1);
		void normalizeTargetsTanh(Normalization tn);
		void normalizeTargetsTanh(double amp = 1, double elong = 1);

		void normalizeSigmoid(Normalization in, Normalization tn);
		void normalizeSigmoid(double inAmp = 1, double inElong = 1, double tarAmp = 1, double tarElong = 1);
		void normalizeInputsSigmoid(Normalization in);
		void normalizeInputsSigmoid(double amp = 1, double elong = 1);
		void normalizeTargetsSigmoid(Normalization tn);
		void normalizeTargetsSigmoid(double amp = 1, double elong = 1);

		void normalizeMeanDistance();
		void normalizeInputsMeanDistance();
		void normalizeTargetsMeanDistance();

		TrainingSet getNormalizedLinearFixedRange(double minInputs, double maxInputs, double minTargets, double maxTargets) const;
		vector<vector<double> > getNormalizedInputsLinearFixedRange(double min, double max);
		vector<vector<double> > getNormalizedTargetsLinearFixedRange(double min, double max);

		TrainingSet getNormalizedLinearAutoRange(double *minInputs, double *maxInputs, double *minTargets, double *maxTargets) const;
		vector<vector<double> > getNormalizedInputsLinearAutoRange(double *min, double *max);
		vector<vector<double> > getNormalizedTargetsLinearAutoRange(double *min, double *max);

		TrainingSet getNormalizedUnipolarFixedThreshold(double inThreshold, double tarThreshold) const;
		vector<vector<double> > getNormalizedInputsUnipolarFixedThreshold(double threshold) const;
		vector<vector<double> > getNormalizedTargetsUnipolarFixedThreshold(double threshold) const;

		TrainingSet getNormalizedUnipolarAutoThreshold(double *inThreshold, double *tarThreshold) const;
		vector<vector<double> > getNormalizedInputsUnipolarAutoThreshold(double *threshold) const;
		vector<vector<double> > getNormalizedTargetsUnipolarAutoThreshold(double *threshold) const;

		TrainingSet getNormalizedBipolarFixedThreshold(double inThreshold, double tarThreshold) const;
		vector<vector<double> > getNormalizedInputsBipolarFixedThreshold(double threshold) const;
		vector<vector<double> > getNormalizedTargetsBipolarFixedThreshold(double threshold) const;

		TrainingSet getNormalizedBipolarAutoThreshold(double *inThreshold, double *tarThreshold) const;
		vector<vector<double> > getNormalizedInputsBipolarAutoThreshold(double *threshold) const;
		vector<vector<double> > getNormalizedTargetsBipolarAutoThreshold(double *threshold) const;

		TrainingSet getNormalizedTanh(double inAmp = 1, double inElong = 1, double tarAmp = 1, double tarElong = 1);
		vector<vector<double> > getNormalizedInputsTanh(double amp = 1, double elong = 1);
		vector<vector<double> > getNormalizedTargetsTanh(double amp = 1, double elong = 1);

		TrainingSet getNormalizedSigmoid(double inAmp = 1, double inElong = 1, double tarAmp = 1, double tarElong = 1);
		vector<vector<double> > getNormalizedInputsSigmoid(double amp = 1, double elong = 1);
		vector<vector<double> > getNormalizedTargetsSigmoid(double amp = 1, double elong = 1);

		TrainingSet getNormalizedMeanDistance();
		vector<vector<double> > getNormalizedInputsMeanDistance();
		vector<vector<double> > getNormalizedTargetsMeanDistance();

		void normalizeInputs(Normalization in);
		void normalizeTargets(Normalization tn);
		void normalize(Normalization in, Normalization tn);

		/*!
		 * \brief getNormalized Devuelve una copia normalizada del conjunto de entrenamiento.
		 * Se debe indicar la normalizacion tanto para las entradas como para las salidas ya que pueden tener diferentes normalizaciones
		 * e incluso las entradas podrian soportar normalizaciones que las salidas no o viceversa.
		 * \param nt
		 * \return
		 */
		TrainingSet getNormalized(Normalization in, Normalization tn) const;

		/*!
		 * \brief getNormalizedInputs Devuelve las entradas normalizadas segun el tipo de normalizacion que este asignada actualmente a las entradas.
		 * La funcion \code{getInputsNormalization()} devolvera la normalizacion actual.
		 *
		 * \return Devuelve el conjunto de entradas normalizadas.
		 *
		 * \see getInputsNormalization()
		 */
		vector<vector<double> > getNormalizedInputs() const;

		/*!
		 * \brief getNormalizedTargets Devuelve las salidas normalizadas segun el tipo de normalizacion que este asignada actualmente a las salidas.
		 * La funcion \code{getTargetsNormalization()} devolvera la normalizacion actual.
		 *
		 * \return Devuelve el conjunto de salidas normalizadas.
		 *
		 * \see getTargetsNormalization()
		 */
		vector<vector<double> > getNormalizedTargets() const;

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

		/*!
		 * \brief appendPattern Agrega un nuevo patron con valores iniciales iguales a cero adoptando el mismo tamaño
		 * de entradas y salidas
		 */
		virtual void appendPattern();

		/*!
		 * \brief appendPattern
		 *
		 * \reimp
		 * \param inputs
		 * \param targets
		 */
		void appendPattern(const vector<double> &inputs, const vector<double> &targets);

		//Operators
		TrainingSet &operator=(const TrainingSet &trset);
		bool operator==(const TrainingSet &trset);
		bool operator!=(const TrainingSet &trset);

		//ITrainingSet inheritance

		/*!
		 * \brief setInputsNormalization Se realiza una reimplementacion que implica una validacion de si hay o no
		 * algun cambio en la nueva normalizacion \code{in}. En caso de haberla se emite una señal \code{inputsNormalizationChanged()}.
		 * La señal sera emitida no solo si el tipo de normalizacion cambia, tambien se emitira si algun parametro de
		 * la nueva normalizacion asignada varia con respecto a la normalizacion anterior
		 *
		 * \reimp
		 * \param in Nueva normalizacion que se asignara a las entradas
		 *
		 * \see setTargetsNormalization
		 */
		void setInputsNormalization(const Normalization &in);

		/*!
		 * \brief setTargetsNormalization Se realiza una reimplementacion que implica una validacion de si hay o no
		 * algun cambio en la nueva normalizacion \code{in}. En caso de haberla se emite una señal \code{targetsNormalizationChanged()}.
		 * La señal sera emitida no solo si el tipo de normalizacion cambia, tambien se emitira si algun parametro de
		 * la nueva normalizacion asignada varia con respecto a la normalizacion anterior
		 *
		 * \reimp
		 * \param tn Nueva normalizacion que se asignara a las salidas
		 *
		 * \see setInputsNormalization
		 */
		void setTargetsNormalization(const Normalization &tn);

		// QAbstractItemModel inheritance

		/*!
		 * \brief rowCount
		 *
		 * \reimp
		 * \param parent
		 * \return
		 */
		int rowCount(const QModelIndex &parent = QModelIndex()) const;

		/*!
		 * \brief columnCount
		 *
		 * \reimp
		 * \param parent
		 * \return
		 */
		int columnCount(const QModelIndex &parent = QModelIndex()) const;

		/*!
		 * \brief setData
		 *
		 * \reimp
		 * \param index
		 * \param value
		 * \param role
		 * \return
		 */
		bool setData(const QModelIndex &index, const QVariant &value, int role);

		/*!
		 * \brief data
		 *
		 * \reimp
		 * \param index
		 * \param role
		 * \return
		 */
		QVariant data(const QModelIndex &index, int role) const;

		/*!
		 * \brief headerData
		 *
		 * \reimp
		 * \param section
		 * \param orientation
		 * \param role
		 * \return
		 */
		QVariant headerData(int section, Qt::Orientation orientation, int role) const;

		/*!
		 * \brief setHeaderData
		 * \param section
		 * \param orientation
		 * \param value
		 * \param role
		 *
		 * \reimp setHeaderData()
		 *
		 * \sa TrainingSet::setHeaderData()
		 */
//		bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role);

		/*!
		 * \brief flags
		 *
		 * \param index
		 * \return
		 *
		 * \reimp flags()
		 *
		 * \sa TrainingSet::flags()
		 */
		Qt::ItemFlags flags(const QModelIndex &index) const;

	protected:

		// QAbstractItemModel inheritance
//		void insertRow(int row, const QModelIndex &parent);

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

		void inputsSizeChanged(int ls, int ns);
		void inputsSizeChanged(int ns);
		void targetsSizeChanged(int ls, int ns);
		void targetsSizeChanged(int ns);

		void patternInserted(const vector<double> &inputs, const vector<double> &targets, int index);
		void patternInserted(const vector<int> &inputs, const vector<int> &targets, int i);

		void patternAdded(const vector<double> &inputs, const vector<double> &targets);

		void patternDeleted(const vector<double> &inputs, const vector<double> &targets, int i);

		void patternChanged(int index, const vector<double> &inputs, const vector<double> &targets);
		void patternChanged(int index, const vector<double> &prevInputs, const vector<double> &newInputs, const vector<double> &prevTargets, const vector<double> &newTargets);

		void inputsNormalizationChanged(const Normalization &ln, const Normalization &nn);
		void inputsNormalizationChanged(const Normalization &nn);

		void targetsNormalizationChanged(const Normalization &ln, const Normalization &nn);
		void targetsNormalizationChanged(const Normalization &nn);

	private:
		Q_OBJECT

		int
		inputsSize,
		targetsSize,
		patternCount;

		QStringList header;

		vector<vector<double> >
		inputs,						/**< conjunto de entradas*/
		targets,					/**< conjunto de objetivos*/
		normalizedInputs,			/**< conjunto de entradas normalizadas*/
		normalizedTargets;			/**< conjunto de objetivos normalizados*/

		void init(const vector<vector<double> > &inputs, int is, const vector<vector<double> > &targets, int ts);
		void resizeVectorSet(vector<vector<double> > &vec, int s, double fill);

		vector<double> normalizedVector(const vector<double> &vec, const Normalization &nor);
};
#endif // TRAININGSET_H
