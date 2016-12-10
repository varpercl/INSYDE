#include "common.h"

namespace common{

QString getFileExtension(const QString &path)
{
	QFileInfo fi(path);

	return fi.suffix();
}

QImage base64ToImage(const QByteArray &base64)
{
	//TODO: 06/17/2016 base64ToImage This routine has never been tested
	QImage result;

	result.loadFromData(QByteArray::fromBase64(base64));

	return result;
}

QImage base64ToImage(char *base64)
{
	//TODO: 06/17/2016 base64ToImage This routine has never been tested
	QImage result;

	result.loadFromData(QByteArray::fromBase64(QByteArray(base64)));

	return result;
}

QImage base64ToImage(const QString &base64)
{
	//TODO: 06/17/2016 base64ToImage This routine has never been tested
	QImage result;
	result.loadFromData(QByteArray::fromBase64(base64.toUtf8()));

	return result;
}

QString imageToBase64(const QImage &img)
{
	QByteArray bytes;
	QBuffer buffer(&bytes);
	buffer.open(QIODevice::WriteOnly);
	img.save(&buffer, "PNG");
	QString output(bytes.toBase64().data());

	return output;
}

QString imageToBase64(const QPixmap &img)
{
	//TODO: 06/17/2016 imageToBase64 Must be implemented
	(void)img;
	return "";
}

QString imageToBase64(const QBitmap &img)
{
//TODO: 06/17/2016 imageToBase64 Must be implemented
	(void)img;
	return "";
}

bool nearTo(const QPoint &p1, const QPoint &p2, int clearance)
{
	return math::distance(p1, p2) <= clearance;
}

bool nearTo(const QPointF &p1, const QPointF &p2, int clearance)
{
	return math::distance(p1, p2) <= clearance;
}

bool nearTo(const QPoint &pos, const QRect &rect, int clearance)
{
	QRect
			outerRect = rect.adjusted(-clearance/2, -clearance/2, clearance/2, clearance/2),
			innerRect = rect.adjusted(clearance/2, clearance/2, -clearance/2, -clearance/2);

	return outerRect.contains(pos) && !innerRect.contains(pos);
}

bool nearTo(const QPointF &pos, const QRectF &rect, double clearance)
{
	QRectF
			outerRect = rect.adjusted(-clearance/2, -clearance/2, clearance/2, clearance/2),
			innerRect = rect.adjusted(clearance/2, clearance/2, -clearance/2, -clearance/2);

	return outerRect.contains(pos) && !innerRect.contains(pos);
}

bool nearTo(const QPointF &pos, const QLineF &line, int clearance)
{
	return math::distance(pos, line) <= clearance;
}

bool nearTo(const QPointF &pos, const QPointF &p1, const QPointF &p2, int clearance)
{
	return math::distance(pos, p1, p2) <= clearance;
}

QCursor getCursor(const QPoint &pos, const QRect &rect, int clearance, const QCursor &defCursor, bool ignoreCorners)
{
	double
			distTopLeft = math::distance(pos, rect.topLeft()),
			distTopRight = math::distance(pos, rect.topRight()),
			distBottomRight = math::distance(pos, rect.bottomRight()),
			distBottomLeft = math::distance(pos, rect.bottomLeft()),
			distTop = std::abs(pos.y() - rect.top()),
			distRight = std::abs(pos.x() - rect.right()),
			distBottom = std::abs(pos.y() - rect.bottom()),
			distLeft = std::abs(pos.x() - rect.left()),
			clearanceRadius = clearance/2;

	if((distTop <= clearanceRadius && !(distTopLeft <= clearanceRadius) && !(distTopRight <= clearanceRadius)) || (distBottom <= clearanceRadius && !(distBottomLeft <= clearanceRadius) && !(distBottomRight <= clearanceRadius))){
		return QCursor(Qt::SizeVerCursor);
	}else if((distRight <= clearanceRadius && !(distTopRight <= clearanceRadius) && !(distBottomRight <= clearanceRadius)) || (distLeft <= clearanceRadius && !(distTopLeft <= clearanceRadius) && !(distBottomLeft <= clearanceRadius))){
		return QCursor(Qt::SizeHorCursor);
	}else if((distTopLeft <= clearanceRadius || distBottomRight <= clearanceRadius) && !ignoreCorners){
		return QCursor(Qt::SizeFDiagCursor);
	}else if((distTopRight <= clearanceRadius || distBottomLeft <= clearanceRadius) && !ignoreCorners){
		return QCursor(Qt::SizeBDiagCursor);
	}

	return defCursor;
}


vector<long> imageToIntVector(
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
vector<unsigned int> imageToUIntVector(const QImage &img)
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

pair<int, int> getWidthHeight(int value)
{
	int width, height;
	if(value >= 1){
		width = height = (int)sqrt(value);
		return pair<int, int>(width+1, height);
	}else{
		return pair<int, int>(1, 1);
	}
}

QVector<QVector<int> > toQVector(const vector<vector<int> > &vec)
{
	QVector<QVector<int> > output;
	for(size_t i = 0; i < vec.size(); i++){
		output.push_back(QVector<int>::fromStdVector(vec[i]));
	}
	return output;
}

vector<vector<int> > toMatrix(const vector<int> &data, int rows, int cols)
{
	vector<vector<int> > output(rows, vector<int>(cols, 0));
	vector<int>::const_iterator it = data.begin();

	for(int r = 0; r < rows; r++){
		output[r] = vector<int>(it, it + cols);
		it = it + cols;
	}

	return output;
}

QColor getHeatColor(double value, const vector<double> &vec)
{
	double
			maxW = *max_element(vec.begin(), vec.end()),
			minW = *min_element(vec.begin(), vec.end()),
			nValue = fabs((value - minW)/(maxW - minW));

	int
			rComponent = nValue <= 0.5 ? 255 : 512 * (1 - nValue),
			gComponent = nValue <= 0.5 ? 512 * nValue : 255;

	return QColor(rComponent, gComponent, 0);
}

Sides nearToSide(const QPoint &pos, const QRect &rect, int clearance, bool ignoreCorners)
{
	double
			distTopLeft = math::distance(pos, rect.topLeft()),
			distTopRight = math::distance(pos, rect.topRight()),
			distBottomRight = math::distance(pos, rect.bottomRight()),
			distBottomLeft = math::distance(pos, rect.bottomLeft()),
			distTop = std::abs(pos.y() - rect.top()),
			distRight = std::abs(pos.x() - rect.right()),
			distBottom = std::abs(pos.y() - rect.bottom()),
			distLeft = std::abs(pos.x() - rect.left()),
			clearanceRadius = clearance/2;

	if(distTop <= clearanceRadius && !(distTopLeft <= clearanceRadius) && !(distTopRight <= clearanceRadius)){
		return Top;
	}else if(distBottom <= clearanceRadius && !(distBottomLeft <= clearanceRadius) && !(distBottomRight <= clearanceRadius)){
		return Bottom;
	}else if(distRight <= clearanceRadius && !(distTopRight <= clearanceRadius) && !(distBottomRight <= clearanceRadius)){
		return Right;
	}else if(distLeft <= clearanceRadius && !(distTopLeft <= clearanceRadius) && !(distBottomLeft <= clearanceRadius)){
		return Left;
	}else if(distTopLeft <= clearanceRadius && !ignoreCorners){
		return TopLeft;
	}else if(distBottomRight <= clearanceRadius && !ignoreCorners){
		return BottomRight;
	}else if(distTopRight <= clearanceRadius && !ignoreCorners){
		return TopRight;
	}else if(distBottomLeft <= clearanceRadius && !ignoreCorners){
		return BottomLeft;
	}else{
		return None;
	}

}

}


