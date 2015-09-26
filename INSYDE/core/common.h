#ifndef COMMON_H
#define COMMON_H

#include <QtCore>
#include <QtGui>

#include <math.h>
#include <vector>
#include <utility>

#include <tbb/concurrent_vector.h>

using namespace tbb;
using namespace std;

/*!
 * \namespace math
 *
 * \date 01/02/2015
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 */
namespace math Q_DECL_EXPORT{

	/*!
	 * \brief distanceBetweenPoints
	 * \param pt1 Primer punto
	 * \param pt2 Segundo punto
	 * \return Distancia euclidea entre ambos puntos
	 */
	double distanceBetweenPoints(const QPointF &pt1, const QPointF &pt2);

	/*!
	 * trunkedDivision Devuelve el minimo valor entero mas proximo a @code{val} que sea multiplo de @code{divisor}.
	 *
	 * \example
	 * trunkedInterval(105, 10) devuelve 10
	 * trunkedInterval(115, 10) devuelve 11
	 * trunkedInterval(444, 5) devuelve 445
	 *
	 * \param val Valor que se quiere aproximar
	 * \param divisor Valor del divisor al cual se quiere hacer la aproximacion
	 *
	 * \return double Valor truncado
	 */
	double trunkedMultiplo(double val, int multiplo);

	/*!
	 * \brief roundedValue Devuelve un valor redondeado al proximo multiplo de @code{divisor} mas cercano a \code{val}
	 *
	 * \example
	 *     roundedInterval(105, 10) devuelve 11
	 *     roundedInterval(115, 10) devuelve 12
	 *     roundedInterval(444, 5) devuelve 440
	 *
	 * \param val Valor que se quiere redondear
	 * \param divisor Valor que servira de divisor de val
	 * \return
	 */
	double roundedMultiplo(double val, int multiplo);

	/*!
	 * \brief mayor
	 * \param vec
	 * \return
	 */
	size_t mayor(const vector<double> &vec);

	/*!
	 * \brief mayor
	 * \param vec
	 * \return
	 */
	size_t mayor(const vector<int> &vec);

	vector<vector<double> > toDouble(const vector<vector<int> > &vec);
	vector<vector<int> > toInt(const vector<vector<double> > &vec);

	double getMin(const vector<double> &vec);
	double getMin(const vector<vector<double> > &matrix);

	double getMax(const vector<double> &vec);
	double getMax(const vector<vector<double> > &matrix);

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

	/*!
	 * \brief probNumbers Esta funcion devuelve un elemento de acuerdo a probabilidades. Toma como parametro un vector
	 * de pares elemento/probabilidad donde se arroja un numero aleatorio y de acuerdo a la probabilidad de cada
	 * elemento pasado en el vector de pares la funcion devolvera uno de ellos.
	 *
	 * La suma de las probabilidades de todos los elementos debe ser igual a 1.
	 * La probabilidad del ultimo elemento (n - 1) no se toma en cuenta ya que se asume que es el restante para
	 * completar una probabilidad total igual a 1.
	 *
	 * \param pairs
	 * \return
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

	/*!
	 * \brief addNoise Agrega ruido a una serie de valores proporcionados por \code{vec}
	 * \param vec Vector con valores a los cuales se les agregara el ruido
	 * \param min Valor minimo de amplitud del ruido
	 * \param max Valor maximo de amplitud del ruido
	 * \return Devuelve un vector que sera igual al vector de entrada mas el ruido sumado a cada uno de los elementos (a cada elemento se le suma un
	 * valor de ruido diferente)
	 *
	 * Para obtener el mismo resultado pero con vectores concurrentes
	 * \see concAddNoise
	 */
	vector<double> addNoise(const vector<double> &vec, double min, double max);

	/*!
	 * \brief concAddNoise Es una copia de la funcion \code{addNoise()} con la diferencia en el uso de los vectores de datos
	 * en la cual se usa el vector concurrente \code{concurrent_vector()} que sirve para operar con algoritmos paralelos.
	 * En muchos casos se utiliza para evitar la conversion desde la clase \code{vector}.
	 *
	 * \param vec Vector concurrente con los datos a los cuales se le agregara el ruido
	 * \param min Valor pico inferior de ruido sumado
	 * \param max Valor pico superior de ruido sumado
	 * \return Devuelve un vector tambien concurrente igual al vector de entrada mas el ruido sumado
	 *
	 * \see addNoise()
	 */
	concurrent_vector<double> concAddNoise(const concurrent_vector<double> &vec, double min, double max);

	vector<int> toUnipolar(const vector<double> &vec, double threshold);
//	vector<int> toUnipolar(const vector<double> &vec, double threshold);

	vector<int> toBipolar(const vector<double> &vec, double threshold);
//	vector<int> toBipolar(const vector<double> &vec, double threshold);

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

/*!
 * Este espacio de nombres define una serie de funciones de uso general
 *
 * \namespace common
 * \author Edixon Vargas
 * \date 08-06-2012
 */
namespace common Q_DECL_EXPORT{

	enum IntegerTypes{
		Unipolar,
		Bipolar,
		NormalSigned,
		NormalUnsigned
	};

	/*!
	 * \brief toQVector
	 * \param vec
	 * \return
	 */
	QVector<QVector<int> > toQVector(const vector<vector<int> > &vec);

	/*!
	 * \brief imageToUIntVector
	 * \param img
	 * \return
	 */
	vector<unsigned int> imageToUIntVector(const QImage &img);

	/*!
	 * \brief imageToIntVector
	 * \param img
	 * \param it
	 * \param threshold
	 * \return
	 */
	vector<long> imageToIntVector(const QImage &img, IntegerTypes it = NormalSigned, double threshold = 0.5);

	/*!
	 * \brief getWidthHeight
	 * \param value
	 * \return
	 */
	pair<int, int> getWidthHeight(int value);

	/*!
	 * \brief toMatrix
	 * \param data
	 * \param rows
	 * \param cols
	 * \return
	 */
	vector<vector<int> > toMatrix(const vector<int> &data, int rows, int cols);
}

#endif // INSYDECOMMON_GLOBAL_H
