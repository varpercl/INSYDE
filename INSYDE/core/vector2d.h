#ifndef VECTORR2_H
#define VECTORR2_H

#include "share_core_lib.h"
#include "common.h"

#include <QtCore>


namespace core CORE_LIB_IMPORT_EXPORT{

/*!
 * \brief The Direction enum indicates the spin direction.
 */
enum Direction {
	ClockWise,
    CounterClockWise
};

/*!
 * \brief The Vector2D class is just a mathematical representation of a 2 component vector.
 * It has a lot of constructors and functions that extends functionalities of a simple vector.
 *
 * \author Edixon Vargas <ingedixonvargas@gmail.com>
 * \date 02/02/2015
 */
class CORE_LIB_IMPORT_EXPORT Vector2D
{

	public:

		/*!
		 * \brief Builds a null vector.
		 */
		explicit Vector2D();

		/*!
		 * \brief Builds a vector with \p x and \p y components.
		 * \param x The X component.
		 * \param y The Y component.
		 */
		explicit Vector2D(double x, double y);

		/*!
		 * \brief Builds a vector given two points in space.
		 * \param x0 The first point's x component.
		 * \param y0 The first point's y component.
		 * \param x1 The second point's x component.
		 * \param y1 The second point's y component.
		 */
		explicit Vector2D(double x0, double y0, double x1, double y1);

		/*!
		 * \brief Builds a vector given two points \p p0 and \p p1.
		 * \param p0 The first point.
		 * \param p1 The second point.
		 */
		explicit Vector2D(QPointF p0, QPointF p1);

		/*!
		 * \brief Builds a vector who starts from origin and ends at \p pt.
		 * \param pt The point the vector ends at.
		 */
		explicit Vector2D(QPointF pt);

		/*!
		 * \brief Builds a vector based on its modulus \p module and angle \p angle.
		 * \param modulus The modulus of the vector.
		 * \param angle The angle of the vector.
		 */
		explicit Vector2D(float modulus, float angle);

		/*!
		 * \brief Sets the \p x coordinate of this vector.
		 * \param x The coordinate.
		 */
		void setX(double x);

		/*!
		 * \brief Gets the current \c x coordinate of this vector.
		 *
		 * \return A double value that holds the \c x coordinate.
		 */
		inline double getX(){return x;}

		/*!
		 * \brief Sets the \p y coordinate of this vector.
		 * \param y The coordinate.
		 */
		void setY(double y);

		/*!
		 * \brief Gets the current \c y coordinate of this vector.
		 * \return A double value that holds the \c y coordinate.
		 */
		inline double getY(){return y;}

		/*!
		 * \brief Gets the modulus of this vector.
		 * \return The modulus of this vector.
		 */
		double getModulus();

		/*!
		 * \brief Sets this vector with a modulus \p mod.
		 *
		 * \note Using this method will change the \c x and \c y coordinates.
		 *
		 * \param mod The new modulus of this vector.
		 */
		void setModulus(double mod);

		/*!
		 * \brief Returns the angle of this vector.
		 * \return A double value which is the angle.
		 */
		double getAngle();

		/*!
		 * \brief Sets the angle of this vector to \p angle.
		 *
		 * \note Using this method will change the \c x and \c y coordinates.
		 *
		 * \param angle The new angle.
		 */
		void setAngle(double angle);

		/*!
		 * \brief Gets the angle in degrees.
		 * \return A double value holding the angle in degrees.
		 */
		double getAngleDeg();

		/*!
		 * \brief Similar to setAngle but in this case you have to
		 * specify the angle in degrees.
		 *
		 * \note Using this method will update the values of \c x and \c y coordinates.
		 *
		 * \param angle The new angle in degrees.
		 */
		void setAngleDeg(double angle);

		/*!
		 * \brief Determines if this vector is parallel with \p vector parameter.
		 * \param vector The vector to be compared.
		 * \return True in case of both parallel.
		 */
		bool isParallel(const Vector2D &vector);

		/*!
		 * \brief Determines if this vector is perpendicular to \p vector parameter.
		 * \param vector The vector to be compared.
		 * \return True in case of both parallel.
		 */
		bool isPerpendicular(const Vector2D &vector);

		/*!
		 * \brief Gets a perpendicular vector to this, indicating the
		 * spin direction.
		 *
		 * \param dir The direction of the vector.
		 *
		 * \return A vector who is perpendicular to this.
		 *
		 * \see Direction
		 */
		Vector2D getPerpendicular(Direction dir);

		/*!
		 * \brief Converts this vector to a QPointF.
		 *
		 * \return A QPointF object with the x and y coordinates.
		 */
		QPointF toPointF();

		bool operator==(const Vector2D &vector);
		bool operator!=(const Vector2D &vector);
		Vector2D &operator=(const Vector2D &vector);
		double operator*(const Vector2D &vector1);
		Vector2D &operator*(const double k);
		Vector2D &operator+(const Vector2D &vector1);
		Vector2D &operator-(const Vector2D &vector1);

	private:
		double x, y;
};
}
#endif // VECTORR2_H
