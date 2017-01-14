#ifndef COMMON_H
#define COMMON_H

#include <QtCore>
#include <QtGui>

#include <math.h>
#include <vector>
#include <utility>

#include <tbb/concurrent_vector.h>

//#include <windows.h>

#include "share_core_lib.h"
#include "imath.h"

using namespace tbb;
using namespace std;

namespace core{

/*!
 * \brief The common namespace involves a generic collection of
 * classes and helper functions that are used along almost every part of the project
 *
 * \author Edixon V <ingedixonvargas@gmail.com>
 * \date 08-06-2012
 */
namespace common /*CORE_LIB_IMPORT_EXPORT*/ {

	enum IntegerTypes{
		Unipolar,
		Bipolar,
		NormalSigned,
		NormalUnsigned
	};

	enum Sides{
		Top,
		Right,
		Bottom,
		Left,
		TopLeft,
		TopRight,
		BottomRight,
		BottomLeft,
		None
	};

	/*!
	 * \brief nearToSide Returns which side from \code{rect} is \code{pos} near to depending of \code{clearance}.
	 *
	 *
	 */
	CORE_LIB_IMPORT_EXPORT Sides nearToSide(const QPoint &pos, const QRect &rect, int clearance, bool ignoreCorners = false);

	/*!
	 * \brief getFileExtension Returns the file extension from a well formed path.
	 * This is done by taking the string after the last point (".") of the string path
	 */
	CORE_LIB_IMPORT_EXPORT QString getFileExtension(const QString &path);

	/*!
	 * \brief base64ToImage Performs a conversion between a byte array to a QImage object that can be drawn and manipulated
	 * by the user.
	 *
	 * Note: data must be in base 64 format
	 */
	CORE_LIB_IMPORT_EXPORT QImage base64ToImage(const QByteArray &base64);


	/*!
	 * \brief base64ToImage Performs a conversion between a char pointer to a QImage object that can be drawn and manipulated
	 * by the user.
	 *
	 * Note: data must be in base 64 format
	 */
	CORE_LIB_IMPORT_EXPORT QImage base64ToImage(char *base64);

	/*!
	 * \brief base64ToImage Performs a conversion between a QString to a QImage object that can be drawn and manipulated
	 * by the user.
	 *
	 * Note: data must be in base 64 format
	 */
	CORE_LIB_IMPORT_EXPORT QImage base64ToImage(const QString &base64);

	/*!
	 * \brief base64ToImage Performs a conversion between an image to a QString in base 64 format. Useful to
	 * embed images into documents like html, xml, etc.
	 *
	 */
	CORE_LIB_IMPORT_EXPORT QString imageToBase64(const QImage &img);
	CORE_LIB_IMPORT_EXPORT QString imageToBase64(const QPixmap &img);
	CORE_LIB_IMPORT_EXPORT QString imageToBase64(const QBitmap &img);

	/*!
	 * \brief near Determines wether \code{p1} and \code{p2} are close enough. This is determined
	 * comparing distance between both points with \code{clearance}
	 *
	 */
	CORE_LIB_IMPORT_EXPORT bool nearTo(const QPoint &p1, const QPoint &p2, int clearance);
	CORE_LIB_IMPORT_EXPORT bool nearTo(const QPointF &p1, const QPointF &p2, int clearance);

	/*!
	 * \brief near Perform calcs
	 *
	 *
	 */
	CORE_LIB_IMPORT_EXPORT bool nearTo(const QPoint &pos, const QRect &rect, int clearance);

    CORE_LIB_IMPORT_EXPORT bool nearTo(const QPointF &pos, const QRectF &rect, double clearance);

	/*!
	 * \brief near Determines if referenced point \code{pos} is near to \code{line}. This is done
	 * by comparing the distance between both with clearance
	 *
	 * \param pos
	 * \param line
	 * \param clearance
	 */
	CORE_LIB_IMPORT_EXPORT bool nearTo(const QPointF &pos, const QLineF &line, int clearance);

	/*!
	 * \brief near Determines if referenced point \code{pos} is near to line formed by both \code{p1} and \code{p2}.
	 * This is done by comparing the distance between both with clearance
	 *
	 * \param pos
	 * \param p1
	 * \paran p2
	 * \param clearance
	 */
	CORE_LIB_IMPORT_EXPORT bool nearTo(const QPointF &pos, const QPointF &p1, const QPointF &p2, int clearance);

	/*!
	 * \brief getCursor This utility function return a cursor depending on \code{pos} position, for example. When
	 * mouse is near to \code{rect} border. Clearance determines the sensibility (minimum distance)
	 *
	 */
	CORE_LIB_IMPORT_EXPORT QCursor getCursor(const QPoint &pos, const QRect &rect, int clearance, const QCursor &defCursor = QCursor(Qt::ArrowCursor), bool ignoreCorners = false);

	/*!
	 * \brief toQVector
	 * \param vec
	 * \return
	 */
	CORE_LIB_IMPORT_EXPORT QVector<QVector<int> > toQVector(const vector<vector<int> > &vec);

	/*!
	 * \brief imageToUIntVector
	 * \param img
	 * \return
	 */
	CORE_LIB_IMPORT_EXPORT vector<unsigned int> imageToUIntVector(const QImage &img);

	/*!
	 * \brief imageToIntVector
	 * \param img
	 * \param it
	 * \param threshold
	 * \return
	 */
	CORE_LIB_IMPORT_EXPORT vector<long> imageToIntVector(const QImage &img, IntegerTypes it = NormalSigned, double threshold = 0.5);

	/*!
	 * \brief getWidthHeight
	 * \param value
	 * \return
	 */
	CORE_LIB_IMPORT_EXPORT pair<int, int> getWidthHeight(int value);

	/*!
	 * \brief toMatrix
	 * \param data
	 * \param rows
	 * \param cols
	 * \return
	 */
	CORE_LIB_IMPORT_EXPORT vector<vector<int> > toMatrix(const vector<int> &data, int rows, int cols);

	CORE_LIB_IMPORT_EXPORT QColor getHeatColor(double value, const vector<double> &vec);

}

}
#endif // INSYDECOMMON_GLOBAL_H
