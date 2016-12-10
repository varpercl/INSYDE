#include "imath.h"

namespace math{


vector<vector<double> > toDouble(const vector<vector<int> > &vec)
{
	size_t sVec= vec.size();
	vector<vector<double> > result(sVec);

	for(size_t i = 0; i < sVec; i++){
		result[i] = vector<double>(vec[i].begin(), vec[i].end());
	}
	return result;
}

double angle(const QPointF &p1, const QPointF &p2)
{
	return atan2(p2.y() - p1.y(), p2.x() - p1.x());
}

double distance(const QPointF &point, const QPointF &p1, const QPointF &p2)
{
	double
			deltaY = p2.y() - p1.y(),
			deltaX = p2.x() - p1.x(),
			m;

	if(deltaY == 0 && deltaX == 0){
		return distance(point, p1);
	}else if(deltaX == 0){
		return fabs(p1.x() - point.x());
	}else{
		 m = deltaY/deltaX;
		 return fabs((m * point.x() - point.y() + (p2.y() - (m * p2.x()))) / sqrt(1 + pow(m, 2)));
	}
}

double distance(const QPointF &point, const QLineF &line)
{
	double
			deltaY = line.y2() - line.y1(),
			deltaX = line.x2() - line.x1(),
			m;

	if(line.length() == 0){
		return distance(point, line.p1());
	}else if(deltaX == 0){
		return fabs(line.x1() - point.x());
	}else{
		 m = deltaY/deltaX;
		 return fabs((m * point.x() - point.y() + (line.y2() - (m * line.x2()))) / sqrt(1 + pow(m, 2)));
	}

}

double distance(const QPointF &pt1, const QPointF &pt2)
{
	return hypot(pt1.x() - pt2.x(), pt1.y() - pt2.y());
}

double trunkedMultiplo(double val, int multiplo){
	double integer;
	modf(val/multiplo, &integer);
	return integer*multiplo;
}

double roundedMultiplo(double val, int multiplo){
#if _MSC_VER == 1600
	return floor( (val/multiplo) + 0.5 )*multiplo;
#else
	return round(val/multiplo)*multiplo;
#endif
}

size_t mayor(const vector<double> &vec)
{
	double ref = -99999999;
	size_t
			sVector = vec.size(),
			index = 0;
	for(size_t i = 0; i < sVector; i++){
		if(vec[i] > ref){
			ref = vec[i];
			index = i;
		}
	}
	return index;
}

size_t mayor(const vector<int> &vec)
{
	int ref = -99999999;
	size_t
			index = 0,
			sVector = vec.size();
	for(size_t i = 0; i < sVector; i++){
		if(vec[i] > ref){
			ref = vec[i];
			index = i;
		}
	}
	return index;
}

vector<vector<int> > toInt(const vector<vector<double> > &vec)
{
	size_t sVec= vec.size();
	vector<vector<int> > result(sVec);

	for(size_t i = 0; i < sVec; i++){
		result[i] = vector<int>(vec[i].begin(), vec[i].end());
	}
	return result;
}

int getMin(const QVector<int> &vec)
{
	return *min_element(vec.begin(), vec.end());
}

double getMin(const vector<double> &vec)
{
	return *min_element(vec.begin(), vec.end());
}

double getMin(const vector<vector<double> > &matrix)
{
	size_t sMatrix = matrix.size();
	vector<double> minvec(sMatrix);
	for(size_t i = 0; i < sMatrix; i++){
		minvec[i] = *min_element(matrix[i].begin(), matrix[i].end());
	}
	return *min_element(minvec.begin(), minvec.end());
}

int getMax(const QVector<int> &vec)
{
	return *max_element(vec.begin(), vec.end());
}

double getMax(const vector<double> &vec)
{
	return *max_element(vec.begin(), vec.end());
}

double getMax(const vector<vector<double> > &matrix)
{
	size_t sMatrix = matrix.size();
	vector<double> maxvec(sMatrix);
	for(size_t i = 0; i < sMatrix; i++){
		maxvec[i] = *max_element(matrix[i].begin(), matrix[i].end());
	}
	return *max_element(maxvec.begin(), maxvec.end());
}

double getMean(const vector<double> &vec){
	size_t sVec = vec.size();
	double sum = 0;
	for(size_t i = 0; i < sVec; i++){
		sum += vec[i];
	}
	return sum/sVec;
}

double getStandardDeviation(const vector<double> &a)
{
	return sqrt(getVariance(a));
}

double getVariance(const vector<double> &vec)
{
	size_t sVec = vec.size();
	double
			sum = 0,
			sum2 = 0,
			mean = getMean(vec);
	for(size_t i = 0; i < sVec; i++){
		sum = (vec[i] - mean);
		sum2 += sum*sum;
	}
	return sum2/(sVec-1);
}

double randomNumber(double min, double max){
	double rnd = (double(rand())/double(RAND_MAX));
//	double fmin = min, fmax = max;
	double d = (min + (max - min)*rnd);
	return d;
}

double probNumbers(vector<pair<double, double> > pairs){
	double rnd = (double(rand())/double(RAND_MAX));
	size_t sPairs = pairs.size();
	double sum = 0;
	for(size_t i = 0; i < sPairs - 1; i++){
		if(rnd > sum && rnd <= pairs[i].second + sum){
			return pairs[i].first;
		}
		sum += pairs[i].second;
	}
	return pairs[sPairs-1].first;
}

vector<double> getRandomValues(int nvalues)
{
	vector<double> values;

	values.resize(nvalues);
	for(int i = 0; i < nvalues; i++){
		values[i] = 1 - (double(rand() * 2)/double(RAND_MAX));
	}
	return values;
}

vector<double> getRandomValues(int nvalues, double min, double max)
{
	vector<double> values(nvalues);
	for(int i = 0; i < nvalues; i++){
		values[i] = randomNumber(min, max);
	}
	return values;
}

vector<double> addNoise(const vector<double> &vec, double min, double max)
{
	vector<double> cVec = vec;
	size_t sVec = cVec.size();
	//	srand(clock());
	for(size_t i = 0; i < sVec; i++){
		cVec[i] += randomNumber(min, max);
	}
	return cVec;
}

concurrent_vector<double> concAddNoise(const concurrent_vector<double> &vec, double min, double max)
{
	concurrent_vector<double> cVec = vec;
	size_t sVec = cVec.size();
	//	srand(clock());
	for(size_t i = 0; i < sVec; i++){
		cVec[i] += randomNumber(min, max);
	}
	return cVec;
}

vector<int> toUnipolar(const vector<double> &vec, double threshold)
{
	size_t sVec = vec.size();
	vector<int> cVec(sVec);

	for(size_t i = 0; i < sVec; i++){
		cVec[i] = vec[i] > threshold ? 1 : 0;
	}
	return cVec;
}

vector<int> toBipolar(const vector<double> &vec, double threshold)
{
	size_t sVec = vec.size();
	vector<int> cVec(sVec);

	for(size_t i = 0; i < sVec; i++){
		cVec[i] = vec[i] > threshold ? 1 : -1;
	}
	return cVec;
}

vector<double> normalizeBipolarFixedThreshold(const vector<double> &vec, double threshold)
{
	size_t sVec = vec.size();

	vector<double> output(sVec, 0);

	for(size_t i = 0; i < sVec; i++){
		output[i] = vec[i] < threshold ? -1 : 1;
	}
	return output;
}

vector<vector<double> > normalizeBipolarFixedThreshold(const vector<vector<double> > &vec, double threshold)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);

	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeBipolarFixedThreshold(vec[i], threshold);
	}
	return output;
}

vector<double> normalizeBipolarAutoThreshold(const vector<double> &vec, double *threshold)
{
	size_t sVec = vec.size();

	vector<double> output(sVec, 0);

	if(threshold == NULL){
		threshold = new double;
	}
	*threshold = (getMin(vec) + getMax(vec)) / 2;
	for(size_t i = 0; i < sVec; i++){
		output[i] = vec[i] < *threshold ? -1 : 1;
	}
	return output;
}

vector<vector<double> > normalizeBipolarAutoThreshold(const vector<vector<double> > &vec, double *threshold)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);

	if(threshold == NULL){
		threshold = new double;
	}
	*threshold = (getMin(vec) + getMax(vec)) / 2;
	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeBipolarFixedThreshold(vec[i], *threshold);
	}
	return output;
}

vector<double> normalizeUnipolarFixedThreshold(const vector<double> &vec, double threshold)
{
	size_t sVec = vec.size();

	vector<double> output(sVec, 0);

	for(size_t i = 0; i < sVec; i++){
		output[i] = vec[i] < threshold ? 0 : 1;
	}
	return output;
}

vector<vector<double> > normalizeUnipolarFixedThreshold(const vector<vector<double> > &vec, double threshold)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);

	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeUnipolarFixedThreshold(vec[i], threshold);
	}
	return output;
}

vector<double> normalizeUnipolarAutoThreshold(const vector<double> &vec, double *threshold)
{
	size_t sVec = vec.size();

	vector<double> output(sVec, 0);

	if(threshold == NULL){
		threshold = new double;
	}
	*threshold = (getMin(vec) + getMax(vec)) / 2;
	for(size_t i = 0; i < sVec; i++){
		output[i] = vec[i] < *threshold ? 0 : 1;
	}
	return output;
}

vector<vector<double> > normalizeUnipolarAutoThreshold(const vector<vector<double> > &vec, double *threshold)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);

	if(threshold == NULL){
		threshold = new double;
	}
	*threshold = (getMin(vec) + getMax(vec)) / 2;
	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeUnipolarFixedThreshold(vec[i], *threshold);
	}
	return output;
}

vector<double> normalizeLinearFixedRange(const vector<double> &vec, double min, double max)
{
	size_t sVec = vec.size();

	vector<double> output(sVec, 0);
	double val, den;
	for(size_t i = 0; i < sVec; i++){
		den = max - min;
		if(den == 0){
			output[i] = -1;
		}else{
			val = (((vec[i] - min)/den)*2)-1;
			if(val < -1){
				val = -1;
			}else if(val > 1){
				val = 1;
			}
			output[i] = val;
		}
	}
	return output;
}

vector<vector<double> > normalizeLinearFixedRange(const vector<vector<double> > &vec, double min, double max)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);

	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeLinearFixedRange(vec[i], min, max);
	}
	return output;
}

vector<double> normalizeLinearAutoRange(const vector<double> &vec, double *min, double *max)
{
	size_t sVec = vec.size();

	vector<double> output(sVec, 0);

	if(!(min && max)){
		min = new double;
		max = new double;
	}
	*min = getMin(vec);
	*max = getMax(vec);
	for(size_t i = 0; i < sVec; i++){
		output[i] = (vec[i] - *min)/(*max - *min);
	}
	return output;
}

vector<vector<double> > normalizeLinearAutoRange(const vector<vector<double> > &vec, double *min, double *max)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);

	if(!(min && max)){
		min = new double;
		max = new double;
	}
	*min = getMin(vec);
	*max = getMax(vec);
	for(size_t i = 0; i < sVec; i++){
		//NOTE: se hace un llamado a la funcion normalizeLinearFixedRange ya que se busco inicialmente el valor maximo y minimo global,
		//por lo cual no necesita ser determinado en cada iteracion como se haria si se llama a normalizeLinearAutoRange
		output[i] = normalizeLinearFixedRange(vec[i], *min, *max);
	}
	return output;
}

vector<double> normalizeTanh(const vector<double> &vec, double amplitude, double elongation)
{
	size_t sVec = vec.size();
	vector<double> output(sVec, 0);
	for(size_t i = 0; i < sVec; i++){
		output[i] = amplitude * tanh(elongation * vec[i]);
	}
	return output;
}

vector<vector<double> > normalizeTanh(const vector<vector<double> > &vec, double amplitude, double elongation)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);
	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeTanh(vec[i], amplitude, elongation);
	}
	return output;
}

vector<double> normalizeSigmoid(const vector<double> &vec, double amp, double elong)
{
	size_t sVec = vec.size();
	vector<double> output(sVec);
	for(size_t i = 0; i < sVec; i++){
		output[i] = amp / (1 + exp(-elong*vec[i]));
	}
	return output;
}

vector<vector<double> > normalizeSigmoid(const vector<vector<double> > &vec, double amp, double elong)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);

	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeSigmoid(vec[i], amp, elong);
	}
	return output;
}

vector<double> normalizeMeanDistance(const vector<double> &vec)
{
	size_t sVec = vec.size();
	vector<double> output(sVec);
	double
			mean = getMean(vec),
			var = getVariance(vec);

	for(size_t i = 0; i < sVec; i++){
		if(var != 0){
			output[i] = (vec[i] - mean)/var;
		}else{
			output[i] = vec[i] - mean;
		}
	}
	return output;
}

vector<vector<double> > normalizeMeanDistance(const vector<vector<double> > &vec)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);

	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeMeanDistance(vec[i]);
	}
	return output;
}
}


