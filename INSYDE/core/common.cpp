#include "common.h"

double math::distanceBetweenPoints(const QPointF &pt1, const QPointF &pt2)
{
	return hypot(pt1.x() - pt2.x(), pt1.y() - pt2.y());
}

double math::trunkedMultiplo(double val, int multiplo){
	double integer;
	modf(val/multiplo, &integer);
	return integer*multiplo;
}

double math::roundedMultiplo(double val, int multiplo){
#if _MSC_VER == 1600
	return floor( (val/multiplo) + 0.5 )*multiplo;
#else
	return round(val/multiplo)*multiplo;
#endif
}

size_t math::mayor(const vector<double> &vec)
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

size_t math::mayor(const vector<int> &vec)
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

vector<unsigned int> common::imageToUIntVector(const QImage &img)
{
	vector<unsigned int> out;

	int
			h = img.height(),
			w = img.width();

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			out.push_back(img.pixel(j, i));
		}
	}

	return out;
}

vector<long> common::imageToIntVector(
		const QImage &img,
		IntegerTypes it,
		double threshold)
{
	vector<long> out;

	int
			gray,
			h = img.height(),
			w = img.width();

	unsigned long pix;
	QColor rgb;

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			pix = img.pixel(j, i);
			switch(img.format()){
				case QImage::Format_Mono:
				case QImage::Format_MonoLSB:
				default:{
					rgb = QColor(pix);
					gray = qGray(rgb.rgb());
					switch(it){
						case Unipolar:
							out.push_back(gray < threshold*255 ? 0 : 1);
							break;
						case Bipolar:
							out.push_back(gray < threshold*255 ? -1 : 1);
							break;
						case NormalSigned:
							out.push_back(pix);
							break;
						case NormalUnsigned:
							pix = pix & 0x00000000ffffffff;
							out.push_back(pix);
							break;
					}
					break;
				}
			}
		}
	}

	return out;
}

pair<int, int> common::getWidthHeight(int value)
{
	int width, height;
	if(value >= 1){
		width = height = (int)sqrt(value);
		return pair<int, int>(width+1, height);
	}else{
		return pair<int, int>(1, 1);
	}
}

QVector<QVector<int> > common::toQVector(const vector<vector<int> > &vec)
{
	QVector<QVector<int> > output;
	for(size_t i = 0; i < vec.size(); i++){
		output.push_back(QVector<int>::fromStdVector(vec[i]));
	}
	return output;
}

vector<vector<int> > common::toMatrix(const vector<int> &data, int rows, int cols)
{
	vector<vector<int> > output(rows, vector<int>(cols, 0));
	vector<int>::const_iterator it = data.begin();

	for(int r = 0; r < rows; r++){
		output[r] = vector<int>(it, it + cols);
		it = it + cols;
	}

	return output;
}

vector<vector<double> > math::toDouble(const vector<vector<int> > &vec)
{
	size_t sVec= vec.size();
	vector<vector<double> > result(sVec);

	for(size_t i = 0; i < sVec; i++){
		result[i] = vector<double>(vec[i].begin(), vec[i].end());
	}
	return result;
}

vector<vector<int> > math::toInt(const vector<vector<double> > &vec)
{
	size_t sVec= vec.size();
	vector<vector<int> > result(sVec);

	for(size_t i = 0; i < sVec; i++){
		result[i] = vector<int>(vec[i].begin(), vec[i].end());
	}
	return result;
}

double math::getMin(const vector<double> &vec)
{
	return *min_element(vec.begin(), vec.end());
}

double math::getMin(const vector<vector<double> > &matrix)
{
	size_t sMatrix = matrix.size();
	vector<double> minvec(sMatrix);
	for(size_t i = 0; i < sMatrix; i++){
		minvec[i] = *min_element(matrix[i].begin(), matrix[i].end());
	}
	return *min_element(minvec.begin(), minvec.end());
}

double math::getMax(const vector<double> &vec)
{
	return *max_element(vec.begin(), vec.end());
}

double math::getMax(const vector<vector<double> > &matrix)
{
	size_t sMatrix = matrix.size();
	vector<double> maxvec(sMatrix);
	for(size_t i = 0; i < sMatrix; i++){
		maxvec[i] = *max_element(matrix[i].begin(), matrix[i].end());
	}
	return *max_element(maxvec.begin(), maxvec.end());
}

double math::getMean(const vector<double> &vec){
	size_t sVec = vec.size();
	double sum = 0;
	for(size_t i = 0; i < sVec; i++){
		sum += vec[i];
	}
	return sum/sVec;
}

double math::getStandardDeviation(const vector<double> &a)
{
	return sqrt(getVariance(a));
}

double math::getVariance(const vector<double> &vec)
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

double math::randomNumber(double min, double max){
	double rnd = (double(rand())/double(RAND_MAX));
//	double fmin = min, fmax = max;
	double d = (min + (max - min)*rnd);
	return d;
}

double math::probNumbers(vector<pair<double, double> > pairs){
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

vector<double> math::getRandomValues(int nvalues)
{
	vector<double> values;

	values.resize(nvalues);
	for(int i = 0; i < nvalues; i++){
		values[i] = 1 - (double(rand() * 2)/double(RAND_MAX));
	}
	return values;
}

vector<double> math::getRandomValues(int nvalues, double min, double max)
{
	vector<double> values(nvalues);
	for(int i = 0; i < nvalues; i++){
		values[i] = randomNumber(min, max);
	}
	return values;
}

vector<double> math::addNoise(const vector<double> &vec, double min, double max)
{
	vector<double> cVec = vec;
	size_t sVec = cVec.size();
	//	srand(clock());
	for(size_t i = 0; i < sVec; i++){
		cVec[i] += randomNumber(min, max);
	}
	return cVec;
}

concurrent_vector<double> math::concAddNoise(const concurrent_vector<double> &vec, double min, double max)
{
	concurrent_vector<double> cVec = vec;
	size_t sVec = cVec.size();
	//	srand(clock());
	for(size_t i = 0; i < sVec; i++){
		cVec[i] += randomNumber(min, max);
	}
	return cVec;
}

vector<int> math::toUnipolar(const vector<double> &vec, double threshold)
{
	size_t sVec = vec.size();
	vector<int> cVec(sVec);

	for(size_t i = 0; i < sVec; i++){
		cVec[i] = vec[i] > threshold ? 1 : 0;
	}
	return cVec;
}

vector<int> math::toBipolar(const vector<double> &vec, double threshold)
{
	size_t sVec = vec.size();
	vector<int> cVec(sVec);

	for(size_t i = 0; i < sVec; i++){
		cVec[i] = vec[i] > threshold ? 1 : -1;
	}
	return cVec;
}

vector<double> math::normalizeBipolarFixedThreshold(const vector<double> &vec, double threshold)
{
	size_t sVec = vec.size();

	vector<double> output(sVec, 0);

	for(size_t i = 0; i < sVec; i++){
		output[i] = vec[i] < threshold ? -1 : 1;
	}
	return output;
}

vector<vector<double> > math::normalizeBipolarFixedThreshold(const vector<vector<double> > &vec, double threshold)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);

	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeBipolarFixedThreshold(vec[i], threshold);
	}
	return output;
}

vector<double> math::normalizeBipolarAutoThreshold(const vector<double> &vec, double *threshold)
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

vector<vector<double> > math::normalizeBipolarAutoThreshold(const vector<vector<double> > &vec, double *threshold)
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

vector<double> math::normalizeUnipolarFixedThreshold(const vector<double> &vec, double threshold)
{
	size_t sVec = vec.size();

	vector<double> output(sVec, 0);

	for(size_t i = 0; i < sVec; i++){
		output[i] = vec[i] < threshold ? 0 : 1;
	}
	return output;
}

vector<vector<double> > math::normalizeUnipolarFixedThreshold(const vector<vector<double> > &vec, double threshold)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);

	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeUnipolarFixedThreshold(vec[i], threshold);
	}
	return output;
}

vector<double> math::normalizeUnipolarAutoThreshold(const vector<double> &vec, double *threshold)
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

vector<vector<double> > math::normalizeUnipolarAutoThreshold(const vector<vector<double> > &vec, double *threshold)
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

vector<double> math::normalizeLinearFixedRange(const vector<double> &vec, double min, double max)
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

vector<vector<double> > math::normalizeLinearFixedRange(const vector<vector<double> > &vec, double min, double max)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);

	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeLinearFixedRange(vec[i], min, max);
	}
	return output;
}

vector<double> math::normalizeLinearAutoRange(const vector<double> &vec, double *min, double *max)
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

vector<vector<double> > math::normalizeLinearAutoRange(const vector<vector<double> > &vec, double *min, double *max)
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

vector<double> math::normalizeTanh(const vector<double> &vec, double amplitude, double elongation)
{
	size_t sVec = vec.size();
	vector<double> output(sVec, 0);
	for(size_t i = 0; i < sVec; i++){
		output[i] = amplitude * tanh(elongation * vec[i]);
	}
	return output;
}

vector<vector<double> > math::normalizeTanh(const vector<vector<double> > &vec, double amplitude, double elongation)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);
	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeTanh(vec[i], amplitude, elongation);
	}
	return output;
}

vector<double> math::normalizeSigmoid(const vector<double> &vec, double amp, double elong)
{
	size_t sVec = vec.size();
	vector<double> output(sVec);
	for(size_t i = 0; i < sVec; i++){
		output[i] = amp / (1 + exp(-elong*vec[i]));
	}
	return output;
}

vector<vector<double> > math::normalizeSigmoid(const vector<vector<double> > &vec, double amp, double elong)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);

	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeSigmoid(vec[i], amp, elong);
	}
	return output;
}

vector<double> math::normalizeMeanDistance(const vector<double> &vec)
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

vector<vector<double> > math::normalizeMeanDistance(const vector<vector<double> > &vec)
{
	size_t sVec = vec.size();
	vector<vector<double> > output(sVec);

	for(size_t i = 0; i < sVec; i++){
		output[i] = normalizeMeanDistance(vec[i]);
	}
	return output;
}
