#include "ANNFramework_global.h"

vector<vector<double> > ANNFrameworkFunctions::toDouble(const vector<vector<int> > &vec)
{
	size_t sVec= vec.size();
	vector<vector<double> > result(sVec);

	for(size_t i = 0; i < sVec; i++){
		result[i] = vector<double>(vec[i].begin(), vec[i].end());
	}
	return result;
}

vector<vector<int> > ANNFrameworkFunctions::toInt(const vector<vector<double> > &vec)
{
	size_t sVec= vec.size();
	vector<vector<int> > result(sVec);

	for(size_t i = 0; i < sVec; i++){
		result[i] = vector<int>(vec[i].begin(), vec[i].end());
	}
	return result;
}

double ANNFrameworkFunctions::getMin(const vector<double> &vec)
{
	return *min_element(vec.begin(), vec.end());
}

double ANNFrameworkFunctions::getMin(const vector<vector<double> > &matrix)
{
	size_t sMatrix = matrix.size();
	vector<double> minvec(sMatrix);
	for(size_t i = 0; i < sMatrix; i++){
		minvec[i] = *min_element(matrix[i].begin(), matrix[i].end());
	}
	return *min_element(minvec.begin(), minvec.end());
}

double ANNFrameworkFunctions::getMax(const vector<double> &vec)
{
	return *max_element(vec.begin(), vec.end());
}

double ANNFrameworkFunctions::getMax(const vector<vector<double> > &matrix)
{
	size_t sMatrix = matrix.size();
	vector<double> maxvec(sMatrix);
	for(size_t i = 0; i < sMatrix; i++){
		maxvec[i] = *max_element(matrix[i].begin(), matrix[i].end());
	}
	return *max_element(maxvec.begin(), maxvec.end());
}

double ANNFrameworkFunctions::getMean(const vector<double> &vec){
	size_t sVec = vec.size();
	double sum = 0;
	for(size_t i = 0; i < sVec; i++){
		sum += vec[i];
	}
	return sum/sVec;
}

double ANNFrameworkFunctions::getStandardDeviation(const vector<double> &a)
{
	return sqrt(getVariance(a));
}

double ANNFrameworkFunctions::getVariance(const vector<double> &vec)
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

double ANNFrameworkFunctions::randomNumber(double min, double max){
	double rnd = (double(rand())/double(RAND_MAX));
//	double fmin = min, fmax = max;
	double d = (min + (max - min)*rnd);
	return d;
}

double ANNFrameworkFunctions::probNumbers(vector<pair<double, double> > pairs){
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

vector<double> ANNFrameworkFunctions::getRandomValues(int nvalues)
{
	vector<double> values(nvalues);
	for(int i = 0; i < nvalues; i++){
		values[i] = 1 - (double(rand() * 2)/double(RAND_MAX));
	}
	return values;
}

vector<double> ANNFrameworkFunctions::getRandomValues(int nvalues, double min, double max)
{
	vector<double> values(nvalues);
	for(int i = 0; i < nvalues; i++){
		values[i] = randomNumber(min, max);
	}
	return values;
}

vector<double> ANNFrameworkFunctions::addNoise(const vector<double> &vec, double min, double max)
{
	vector<double> cVec = vec;
	size_t sVec = cVec.size();
	//	srand(clock());
	for(size_t i = 0; i < sVec; i++){
		cVec[i] += randomNumber(min, max);
	}
	return cVec;
}

vector<int> ANNFrameworkFunctions::toUnipolar(const vector<double> &vec, double threshold)
{
	size_t sVec = vec.size();
	vector<int> cVec(sVec);

	for(size_t i = 0; i < sVec; i++){
		cVec[i] = vec[i] > threshold ? 1 : 0;
	}
	return cVec;
}

vector<int> ANNFrameworkFunctions::toBipolar(const vector<double> &vec, double threshold)
{
	size_t sVec = vec.size();
	vector<int> cVec(sVec);

	for(size_t i = 0; i < sVec; i++){
		cVec[i] = vec[i] > threshold ? 1 : -1;
	}
	return cVec;
}

vector<double> ANNFrameworkFunctions::normalizeBipolarFixedThreshold(const vector<double> &vec, double threshold)
{
	size_t sVec = vec.size();
	
	vector<double> output(sVec, 0);
	
	for(size_t i = 0; i < sVec; i++){
		output[i] = vec[i] < threshold ? -1 : 1;
	}
	return output;
}

vector<vector<double> > ANNFrameworkFunctions::normalizeBipolarFixedThreshold(const vector<vector<double> > &vec, double threshold)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);

	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeBipolarFixedThreshold(vec[i], threshold);
	}
	return output;
}

vector<double> ANNFrameworkFunctions::normalizeBipolarAutoThreshold(const vector<double> &vec, double *threshold)
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

vector<vector<double> > ANNFrameworkFunctions::normalizeBipolarAutoThreshold(const vector<vector<double> > &vec, double *threshold)
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

vector<double> ANNFrameworkFunctions::normalizeUnipolarFixedThreshold(const vector<double> &vec, double threshold)
{
	size_t sVec = vec.size();

	vector<double> output(sVec, 0);

	for(size_t i = 0; i < sVec; i++){
		output[i] = vec[i] < threshold ? 0 : 1;
	}
	return output;
}

vector<vector<double> > ANNFrameworkFunctions::normalizeUnipolarFixedThreshold(const vector<vector<double> > &vec, double threshold)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);

	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeUnipolarFixedThreshold(vec[i], threshold);
	}
	return output;
}

vector<double> ANNFrameworkFunctions::normalizeUnipolarAutoThreshold(const vector<double> &vec, double *threshold)
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

vector<vector<double> > ANNFrameworkFunctions::normalizeUnipolarAutoThreshold(const vector<vector<double> > &vec, double *threshold)
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

vector<double> ANNFrameworkFunctions::normalizeLinearFixedRange(const vector<double> &vec, double min, double max)
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

vector<vector<double> > ANNFrameworkFunctions::normalizeLinearFixedRange(const vector<vector<double> > &vec, double min, double max)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);

	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeLinearFixedRange(vec[i], min, max);
	}
	return output;
}

vector<double> ANNFrameworkFunctions::normalizeLinearAutoRange(const vector<double> &vec, double *min, double *max)
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

vector<vector<double> > ANNFrameworkFunctions::normalizeLinearAutoRange(const vector<vector<double> > &vec, double *min, double *max)
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

vector<double> ANNFrameworkFunctions::normalizeTanh(const vector<double> &vec, double amplitude, double elongation)
{
	size_t sVec = vec.size();
	vector<double> output(sVec, 0);
	for(size_t i = 0; i < sVec; i++){
		output[i] = amplitude * tanh(elongation * vec[i]);
	}
	return output;
}

vector<vector<double> > ANNFrameworkFunctions::normalizeTanh(const vector<vector<double> > &vec, double amplitude, double elongation)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);
	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeTanh(vec[i], amplitude, elongation);
	}
	return output;
}

vector<double> ANNFrameworkFunctions::normalizeSigmoid(const vector<double> &vec, double amp, double elong)
{
	size_t sVec = vec.size();
	vector<double> output(sVec);
	for(size_t i = 0; i < sVec; i++){
		output[i] = amp / (1 + exp(-elong*vec[i]));
	}
	return output;
}

vector<vector<double> > ANNFrameworkFunctions::normalizeSigmoid(const vector<vector<double> > &vec, double amp, double elong)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);

	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeSigmoid(vec[i], amp, elong);
	}
	return output;
}

vector<double> ANNFrameworkFunctions::normalizeMeanDistance(const vector<double> &vec)
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

vector<vector<double> > ANNFrameworkFunctions::normalizeMeanDistance(const vector<vector<double> > &vec)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);

	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeMeanDistance(vec[i]);
	}
	return output;
}
