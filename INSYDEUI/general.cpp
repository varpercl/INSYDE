#include "INSYDEUI_global.h"

using namespace CommonFunctions;


double CommonFunctions::distanceBetweenPoints(const QPointF &pt1, const QPointF &pt2)
{
	return hypot(pt1.x() - pt2.x(), pt1.y() - pt2.y());
}

double CommonFunctions::trunkedValue(double val, double divisor){
	double integer;
	modf(val/divisor, &integer);
	return integer*divisor;
}

double CommonFunctions::roundedValue(double val, double divisor){
#if _MSC_VER == 1600
	return floor( (val/divisor) + 0.5 )*divisor;
#else
	return round(val/divisor)*divisor;
#endif
}

size_t CommonFunctions::mayor(const vector<double> &vec)
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

size_t CommonFunctions::mayor(const vector<int> &vec)
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

vector<unsigned int> CommonFunctions::imageToUIntVector(const QImage &img)
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

vector<int> CommonFunctions::imageToIntVector(
		const QImage &img,
		IntegerTypes it,
		double threshold)
{
	vector<int> out;

	int
			gray,
			h = img.height(),
			w = img.width();

	unsigned int pix;
	QColor rgb;

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			pix = img.pixel(j, i);
			switch(img.format()){
				case QImage::Format_Mono:
				case QImage::Format_MonoLSB:{
					rgb = QColor(pix);
					gray = qGray(rgb.rgb());
					switch(it){
						case Unipolar:
							out.push_back(gray < threshold*255 ? 0 : 1);
							break;
						case Bipolar:
							out.push_back(gray < threshold*255 ? -1 : 1);
							break;
						case Normal:
						default:
							out.push_back(pix);
							break;
					}
					//					out.push_back(pix);
					break;
				}
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
						case Normal:
						default:
							out.push_back(pix);
							break;
					}
				}
			}
		}
	}

	return out;
}
