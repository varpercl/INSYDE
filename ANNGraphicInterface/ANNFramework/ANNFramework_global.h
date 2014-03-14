#ifndef ANNFRAMEWORK_GLOBAL_H
#define ANNFRAMEWORK_GLOBAL_H

#include <vector>
#include <algorithm>
#include <math.h>
#include <QtCore/qglobal.h>

using namespace std;

#if defined(ANNFRAMEWORK_LIBRARY)
#  define ANNFRAMEWORK_EXPORT Q_DECL_EXPORT
#else
#  define ANNFRAMEWORK_EXPORT Q_DECL_IMPORT
#endif

namespace ANNFrameworkFunctions {
	vector<vector<double> > toDouble(const vector<vector<int> > &vec);
	vector<vector<int> > toInt(const vector<vector<double> > &vec);

	double getMin(const vector<double> &vec);
	double getMin(const vector<vector<double> > &matrix);

	double getMax(const vector<double> &vec);
	double getMax(const vector<vector<double> >&matrix);

	double getMean(const vector<double> &vec);
	double getStandardDeviation(const vector<double> &a);
	double getVariance(const vector<double> &vec);

	double randomNumber(double min, double max);

	template<typename T>
	double average(const vector<T> &arr){
		double sum = 0;
		int C = 0;
		size_t sArr = arr.size();
		for(int i = 0; i < sArr; i++){
			sum += arr[i];
			C++;
		}
		return sum/C;
	}

	/**
	  Esta funcion devuelve un elemento de acuerdo a probabilidades.
	  toma como parametro un vector de pares elemento/probabilidad
	  donde se arroja un numero aleatorio y de acuerdo a la probabilidad de cada
	  elemento pasado en el vector de pares la funcion devolvera uno de ellos.

	  La suma de las probabilidades de todos los elementos debe ser igual a 1.
	  La probabilidad del ultimo elemento (n - 1) no se toma en cuenta ya que
	  se asume que es el restante para completar una probabilidad total igual a 1.

	  En caso de que la probabilidad total exceda 1 siempre se devolvera el elemento
	  (n - 1)

	  @param vector<pair<double, double> > pairs Pares elemento/probabilidad
	  */
	double probNumbers(vector<pair<double, double> > pairs);

	/**
	Este metodo devuelve un vector con una lista de valores aleatorios de tipo @code{double}
	La idea de usar este metodo es para generar una cantidad de pesos sinapticos aleatorios o tambien
	entradas aleatorias inicialmente.

	@param ninputs Numero de valores aleatorios que se quieren generar

	*/
	vector<double> getRandomValues(int nvalues);

	vector<double> getRandomValues(int nvalues, double min, double max);

	vector<double> addNoise(const vector<double> &vec, double min, double max);

	vector<int> toUnipolar(const vector<double> &vec, double threshold);

	vector<int> toBipolar(const vector<double> &vec, double threshold);

	vector<double> normalizeBipolarFixedThreshold(const vector<double> &vec, double threshold);

	vector<vector<double> > normalizeBipolarFixedThreshold(const vector<vector<double> > &vec, double threshold);

	vector<double> normalizeBipolarAutoThreshold(const vector<double> &vec, double *threshold = 0);

	vector<vector<double> > normalizeBipolarAutoThreshold(const vector<vector<double> > &vec, double *threshold = 0);

	vector<double> normalizeUnipolarFixedThreshold(const vector<double> &vec, double threshold);

	vector<vector<double> > normalizeUnipolarFixedThreshold(const vector<vector<double> > &vec, double threshold);

	vector<double> normalizeUnipolarAutoThreshold(const vector<double> &vec, double *threshold = 0);

	vector<vector<double> > normalizeUnipolarAutoThreshold(const vector<vector<double> > &vec, double *threshold = 0);

	vector<double> normalizeLinearFixedRange(const vector<double> &vec, double min, double max);

	vector<vector<double> > normalizeLinearFixedRange(const vector<vector<double> > &vec, double min, double max);

	vector<double> normalizeLinearAutoRange(const vector<double> &vec, double *min, double *max);

	vector<vector<double> > normalizeLinearAutoRange(const vector<vector<double> > &vec, double *min, double *max);

	vector<double> normalizeTanh(const vector<double> &vec, double amplitude = 1.7159, double elongation = 2/3);

	vector<vector<double> > normalizeTanh(const vector<vector<double> > &vec, double amplitude = 1.7159, double elongation = 2/3);

	vector<double> normalizeSigmoid(const vector<double> &vec, double amp = 1, double elong = 1);

	vector<vector<double> > normalizeSigmoid(const vector<vector<double> > &vec, double amp = 1, double elong = 1);

	vector<double> normalizeMeanDistance(const vector<double> &vec);

	vector<vector<double> > normalizeMeanDistance(const vector<vector<double> > &vec);

}

#endif // RNALIBRARY_GLOBAL_H
