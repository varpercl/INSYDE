#ifndef VECTORR2_H
#define VECTORR2_H

#include <QVector2D>
#include <QtCore>
#include <qmath.h>

enum Direction{
    ClockWise,
    CounterClockWise
};

/**
  @class Vector2D
  @author Edixon Vargas
  @date 08-06-2012

  Un objeto @code{Vector2D} permite utilizar todas las operaciones de vectores, ideal para el uso en un entorno grafico
  porque brinda acceso al modulo, al angulo y permite no solo devolverlos como valor sino tambien asignarlos.

  */
class Vector2D
{
    private:
        double x, y;

    public:
        explicit Vector2D();
        explicit Vector2D(double x, double y);
        explicit Vector2D(double x0, double y0, double x1, double y1);
        explicit Vector2D(QPointF ptIni, QPointF ptFin);
        explicit Vector2D(QPointF pt);
        explicit Vector2D(float modulo, float angle);

        void setX(double x);
        inline double getX(){return x;}

        void setY(double y);
        inline double getY(){return y;}

        double getModulo();
        void setModulo(double mod);

        double getAngle();
        void setAngle(double angle);

        double getAngleDeg();
        void setAngleDeg(double angle);

        bool isParallel(Vector2D vector);
        bool isPerpendicular(Vector2D vector);

        Vector2D getPerpendicular(Direction angle);

        QPointF toPointF();

        bool operator==(const Vector2D &vector);
        bool operator!=(const Vector2D &vector);
        Vector2D &operator=(const Vector2D &vector);
        double operator*(const Vector2D &vector1);
        Vector2D &operator*(const double k);
        Vector2D &operator+(const Vector2D &vector1);
        Vector2D &operator-(const Vector2D &vector1);
};

#endif // VECTORR2_H
