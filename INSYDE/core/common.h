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

/*!
 * \brief The IntegerTypes enum represent the type of a binary integer.
 *
 * FIXME: There is a big confusion of the types this enum represents.
 *
 */
enum IntegerTypes{
	Unipolar, /**< Only values of 0 or 1 >*/
	Bipolar, /**< Only values of -1 or 1 >*/
	NormalSigned, /**< Only negative or positive integers >*/
	NormalUnsigned /**< Only positive integers >*/
};

/*!
 * \brief The Sides enum represent a list of sides of a rectangle.
 * This sides even includes the corners of the rectangle.
 */
enum Sides{
	None, /**< No side represented >*/
	Top, /**< The top side >*/
	Right, /**< The right side >*/
	Bottom, /**< The bottom side >*/
	Left, /**< The left side >*/
	TopLeft, /**< The top-left corner >*/
	TopRight, /**< The top-right corner >*/
	BottomRight, /**< The bottom-right corner >*/
	BottomLeft /**< The bottom-left corner >*/
};

/*!
	 * \brief Returns which side from \p rect is \p pos near to depending of \p clearance.
	 * \param[in] pos The current post to be processed.
	 * \param[in] rect The bounding rectangle where \p pos will move.
	 * \param clearance The clearance or sensitivity of this function.
	 * \param ignoreCorners True will tell to the functions that if \p pos is close to any corner will return none.
	 * \return A Sides type which represent the closes side where \p pos is placed.
	 */
CORE_LIB_IMPORT_EXPORT Sides nearToSide(const QPoint &pos, const QRect &rect, int clearance, bool ignoreCorners = false);

/*!
	 * \brief Returns the file extension from a well formed path.
	 * This is done by taking the string after the last point (".") of the string path.
	 * \note This is a complement function that basicly replace the original QFileInfo::suffix.
	 *
	 * \param[in] path The current path to be scanned.
	 */
CORE_LIB_IMPORT_EXPORT QString getFileExtension(const QString &path);

/*!
	 * \brief Performs a conversion between a byte array to a QImage object that can be drawn and manipulated
	 * by the user.
	 *
	 * \note data must be in base 64 format.
	 *
	 * \param[in] base64 The byte array to be processed.
	 */
CORE_LIB_IMPORT_EXPORT QImage base64ToImage(const QByteArray &base64);


/*!
	 * \brief Performs a conversion between a char pointer of data to a QImage object that can
	 * be drawn and manipulated by the user.
	 *
	 * \note data must be in base 64 format.
	 *
	 * \param[in] base64 A pointer to a char data, this pointer should be null terminated.
	 */
CORE_LIB_IMPORT_EXPORT QImage base64ToImage(char *base64);

/*!
	 * \brief Performs a conversion between a QString to a QImage object that can be drawn and manipulated
	 * by the user.
	 *
	 * \note data must be in base 64 format
	 *
	 * \param[in] The string containing the base-64 information to be processed.
	 */
CORE_LIB_IMPORT_EXPORT QImage base64ToImage(const QString &base64);

/*!
	 * \brief base64ToImage Performs a conversion between an image to a QString in base 64 format. Useful to
	 * embed images into documents like html, xml, etc.
	 *
	 * \param[in] img The image to be converted.
	 */
CORE_LIB_IMPORT_EXPORT QString imageToBase64(const QImage &img);

/*!
 * \overload
 */
CORE_LIB_IMPORT_EXPORT QString imageToBase64(const QPixmap &img);

/*!
 * \overload
 */
CORE_LIB_IMPORT_EXPORT QString imageToBase64(const QBitmap &img);

/*!
 * \brief Determines wether \p p1 and \p p2 are close enough. This is determined
 * comparing euclidean distance between both points with \p clearance.
 *
 * \param[in] p1 The first point to be analysed.
 * \param[in] p2 The second point to be analysed.
 * \param clearance The clearance or sensitivity.
 *
 * \return True if \p p1 is close enough to \p p2.
 */
CORE_LIB_IMPORT_EXPORT bool nearTo(const QPoint &p1, const QPoint &p2, int clearance);

/*!
 * \overload
 */
CORE_LIB_IMPORT_EXPORT bool nearTo(const QPointF &p1, const QPointF &p2, int clearance);

/*!
 * \overload
 */
CORE_LIB_IMPORT_EXPORT bool nearTo(const QPoint &pos, const QRect &rect, int clearance);

/*!
 * \overload
 */
CORE_LIB_IMPORT_EXPORT bool nearTo(const QPointF &pos, const QRectF &rect, double clearance);

/*!
 * \brief Determines if referenced point \p pos is near to \p line. This is done
 * by comparing the distance between both with clearance.
 *
 * \param pos The current point to be compared.
 * \param line The line to be compared.
 * \param clearance The tolerance or minimun distance between \p pos and \p line.
 *
 * \return True if is close enough indicated by \p clearance.
 */
CORE_LIB_IMPORT_EXPORT bool nearTo(const QPointF &pos, const QLineF &line, int clearance);

/*!
 * \brief Determines if referenced point \p pos is near to line formed by both \p p1 and \p p2.
 *
 * \param pos The point to be compared with both \p p1 and \p p2.
 * \param p1 The first point of the line to be compared with \p pos.
 * \paran p2 The second point of the line to be compared with \p pos.
 * \param clearance The tolerance or minimun distance.
 *
 * \return True if close enough.
 */
CORE_LIB_IMPORT_EXPORT bool nearTo(const QPointF &pos, const QPointF &p1, const QPointF &p2, int clearance);

/*!
 * \brief This utility function return a cursor depending on \p pos position, for example, when
 * mouse is near to the borders of \p rect. Clearance determines the sensibility (minimum distance).
 *
 * The cursors are resize arrows which depends on the side the \p pos parameter is.
 *
 * This function is very useful when user wants to resize some rectangle or any resizable object.
 *
 * \param pos The position of the cursor.
 * \param rect The rectangle to be processed.
 * \param clearance The minimum distance to update the cursor.
 * \param defCursor The default cursor to be shown in case of pos is far away.
 * \param ignoreCorners If true, the corners won't be taken in account.
 *
 * \return Returns a QCursor object that depends on the \p pos parameter.
 */
CORE_LIB_IMPORT_EXPORT QCursor getCursor(const QPoint &pos, const QRect &rect, int clearance, const QCursor &defCursor = QCursor(Qt::ArrowCursor), bool ignoreCorners = false);

/*!
 * \brief Performs a conversion from std::vector to QVector. This is utility function to perform a practic
 * conversion, but not the best in performance.
 * It performs a one-by-one conversion.
 *
 * \param vec The vector to be converted.
 *
 * \return A QVector object who stores the same information of \p vec.
 */
CORE_LIB_IMPORT_EXPORT QVector<QVector<int> > toQVector(const vector<vector<int> > &vec);

/*!
 * \brief Performs a conversion from a QImage to a vector of unsigned integers.
 * This function delivers a copy of the pixels of the image \p img.
 *
 * \param img The image to be converted.
 * \return A vector that contains all the pixels in \p img.
 *
 */
CORE_LIB_IMPORT_EXPORT vector<unsigned int> imageToUIntVector(const QImage &img);

/*!
 * \brief Performs a convertion from an image \p img to a vector of binary values depending on
 * threshold, the values will be stored on a vector depending on parameter \p it.
 *
 * \param img The image to be processed.
 * \param it The type of integers delivered in the result.
 * \param threshold This value represents the comparing point of each pixel after being converted to gray scale.
 *
 * \return A vector with the image converted.
 */
CORE_LIB_IMPORT_EXPORT vector<long> imageToIntVector(const QImage &img, IntegerTypes it = NormalSigned, double threshold = 0.5);

/*!
 * \brief This function returns a pair of int values which correspont to a width and height, both are the same.
 * Basicly this function is equivalent to a sqrt(value)
 *
 * \param value The value to be converted.
 * \return A pair of values which correspond to the height and width.
 */
CORE_LIB_IMPORT_EXPORT pair<int, int> getWidthHeight(int value);

/*!
 * \brief Converts a linear vector to a MxN vector depending on \p rows and \p cols specified by the user.
 *
 * WARNING: its not clear which parameter has priority (rows or cols).
 *
 * \param data The data to be converted.
 * \param rows The desired row in the returned data.
 * \param cols The desired cols in the returned data.
 * \return A \p rows x \p cols matrix.
 */
CORE_LIB_IMPORT_EXPORT vector<vector<int> > toMatrix(const vector<int> &data, int rows, int cols);

/*!
 * \brief This utility function returns a heat color in a range from green to red depending on the values
 * contained in \p vec.
 *
 * \note This function evaluates which is the minimum and maximum value of \p vec. Then \p value is compared
 * and the color is calculated based on the position the \p value parameter is.
 *
 * In case value is out of range then the taken value will be the closest.
 *
 * \param value
 * \param vec
 * \return
 */
CORE_LIB_IMPORT_EXPORT QColor getHeatColor(double value, const vector<double> &vec);

}
}
#endif // INSYDECOMMON_GLOBAL_H
