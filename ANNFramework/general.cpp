#include "general.h"

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
    vector<double> values(nvalues);
    for(int i = 0; i < nvalues; i++){
        values[i] = 1 - (double(rand() * 2)/double(RAND_MAX));
    }
    return values;
}
