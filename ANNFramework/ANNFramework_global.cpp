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
		maxvec[i] = *min_element(matrix[i].begin(), matrix[i].end());
	}
	return *max_element(maxvec.begin(), maxvec.end());
}

double ANNFrameworkFunctions::getAverage(const vector<double> &vec){
	size_t sVec = vec.size();
	double sum = 0;
	for(size_t i = 0; i < sVec; i++){
		sum += vec[i];
	}
	return sum/sVec;
}

double ANNFrameworkFunctions::getStandardDeviation(const vector<double> &a)
{
	int n = a.size();
	if(n == 0)
		return 0.0;
	double sum = 0;
	double sq_sum = 0;
	for(int i = 0; i < n; ++i) {
		sum += a[i];
		sq_sum += a[i] * a[i];
	}
	double mean = sum / n;
	double variance = sq_sum / n - mean * mean;
	return sqrt(variance);
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
